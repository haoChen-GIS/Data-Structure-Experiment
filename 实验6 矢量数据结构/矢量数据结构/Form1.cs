//using ESRI.ArcGIS.ADF.Connectivity;
using ESRI.ArcGIS.Carto;
using ESRI.ArcGIS.DataSourcesFile;
using ESRI.ArcGIS.Display;
using ESRI.ArcGIS.esriSystem;
using ESRI.ArcGIS.Geodatabase;
using ESRI.ArcGIS.Geometry;
using System;
using System.IO;
using System.Text;
using System.Windows.Forms;
using ESRI.ArcGIS.Controls;

namespace 矢量数据结构
{
    public partial class Form1 : DevExpress.XtraBars.Ribbon.RibbonForm
    {
        /// <summary>
        

        /// </summary>
        public Form1()
        {
            InitializeComponent();
            loadMapDocument();
            this.WindowState = FormWindowState.Maximized;    //最大化窗体 
        }
        private void loadMapDocument()   //加载地图文档
        {
            string fullpath = @"suzhou.mxd";
            axMapControl1.LoadMxFile(fullpath);
            axMapControl1.Extent = axMapControl1.Extent;
        }

        private string sMapUnits = "未知单位";
        enum Action
        {
            Pan,//漫游
            Frame_Enlarge,  //拉框放大
            Frame_Reduce,   //拉框缩小
           
        };
        Action action;

        private void 工作空间加载_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            OpenFileDialog OpenDlg = new OpenFileDialog();
            OpenDlg.CheckFileExists = true;  //检查该地图文档是否可以加载到控件中
            OpenDlg.Title = "请选择地图文档";
            OpenDlg.Filter = "地图文档文件(*.mxd)|*.mxd";
            OpenDlg.Multiselect = false;// 设置为不可以多选
            OpenDlg.ShowDialog();
            string StrFileName = OpenDlg.FileName;
            if (axMapControl1.CheckMxFile(StrFileName))
            {
                axMapControl1.MousePointer = ESRI.ArcGIS.Controls.esriControlsMousePointer.esriPointerHourglass;
                axMapControl1.LoadMxFile(StrFileName, 0, Type.Missing);
                axMapControl1.MousePointer = ESRI.ArcGIS.Controls.esriControlsMousePointer.esriPointerDefault;
                axMapControl1.Extent = axMapControl1.FullExtent;
            }
        }

        //获取RGB颜色
        private IColor GetRGBColor(int r, int g, int b)
        {
            IRgbColor rgbColor = new RgbColorClass();
            rgbColor.Red = r;
            rgbColor.Green = g;
            rgbColor.Blue = b;
            IColor color = rgbColor as IColor;
            return color;
        }
     

        private void barButtonItem1_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            action = Action.Pan;
        }


        private void axMapControl1_OnMouseDown(object sender, ESRI.ArcGIS.Controls.IMapControlEvents2_OnMouseDownEvent e)
        {
            switch (action)
            {
                case Action.Pan:
                    {
                        axMapControl1.Pan();
                        break;
                    }
                case Action.Frame_Enlarge:
                    {
                        IEnvelope pEnvelope;
                        pEnvelope = axMapControl1.TrackRectangle();
                        IActiveView pActiveView = axMapControl1.ActiveView;

                        //如果拉框范围为空则返回
                        if (pEnvelope == null || pEnvelope.IsEmpty || pEnvelope.Height == 0 || pEnvelope.Width == 0)
                        {
                            return;
                        }
                        //如果有拉框范围，则放大到拉框范围
                        pActiveView.Extent = pEnvelope;
                        pActiveView.Refresh();
                        action = Action.Pan;
                        break;
                        //ITool pTool;
                        //axMapControl1.CurrentTool = null;
                        //pTool = new ESRI.ArcGIS.Controls.con; 
                    }
                case Action.Frame_Reduce:
                    {
                        IEnvelope pEnvelope;
                        pEnvelope = axMapControl1.TrackRectangle();
                        IActiveView pActiveView = axMapControl1.ActiveView;
                        if (pEnvelope == null || pEnvelope.IsEmpty || pEnvelope.Height == 0 || pEnvelope.Width == 0)
                        {
                            return;
                        }
                        //如果有拉框范围,则以拉框范围为中心，缩小倍数为当前视图范围/拉框范围
                        {
                            double dWidth = pActiveView.Extent.Width * pActiveView.Extent.Width / pEnvelope.Width;
                            double dHeight = pActiveView.Extent.Height * pActiveView.Extent.Height / pEnvelope.Height;
                            double dXmin = pActiveView.Extent.XMin - ((pEnvelope.XMin - pActiveView.Extent.XMin)
                                * pActiveView.Extent.Width / pEnvelope.Width);
                            double dYmin = pActiveView.Extent.YMin - ((pEnvelope.YMin - pActiveView.Extent.YMin)
                                * pActiveView.Extent.Height / pEnvelope.Height);
                            double dXmax = dXmin + dWidth;
                            double dYmax = dYmin + dHeight;
                            pEnvelope.PutCoords(dXmin, dYmin, dXmax, dYmax);
                        }
                        pActiveView.Extent = pEnvelope;
                        pActiveView.Refresh();
                        action = Action.Pan;
                        break;
                    }


            }

        }

     

        private void 添加点_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            // 获取地图控件对象
            AxMapControl mapControl = axMapControl1;

  
            // 创建地理坐标系的空间参考对象
            ISpatialReferenceFactory spatialReferenceFactory = new SpatialReferenceEnvironmentClass();
            ISpatialReference geographicSpatialReference = spatialReferenceFactory.CreateGeographicCoordinateSystem(
                (int)esriSRGeoCSType.esriSRGeoCS_Beijing1954);

            // 创建几何环境对象
            IGeometryEnvironment geometryEnvironment = new GeometryEnvironmentClass();

            // 选择文本文件并读取内容
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Text Files (*.txt)|*.txt";
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                string filePath = openFileDialog.FileName;
                string[] lines = File.ReadAllLines(filePath);

                // 获取地图的图层
                IMap map = axMapControl1.Map;
                IGraphicsContainer graphicsContainer = map as IGraphicsContainer;

                // 获取地图的空间参考系统
                ISpatialReference mapSpatialReference = map.SpatialReference;

                // 创建点符号
                ISimpleMarkerSymbol markerSymbol = new SimpleMarkerSymbolClass();
                markerSymbol.Style = esriSimpleMarkerStyle.esriSMSCircle;
                markerSymbol.Size = 6;
                markerSymbol.Color = GetRGBColor(255, 65,24);

                // 创建投影转换器
                IGeometry2 geometry2Factory = new GeometryEnvironmentClass() as IGeometry2;


                // 遍历每一行数据
                foreach (string line in lines)
                {
                    // 解析经纬度坐标
                    string[] coordinates = line.Split(',');
                    double longitude = Convert.ToDouble(coordinates[1]);
                    double latitude = Convert.ToDouble(coordinates[0]);

                    // 创建点对象并进行坐标转换
                    IPoint point = new PointClass();
                    point.X = longitude;
                    point.Y = latitude;
                    point.SpatialReference = geographicSpatialReference;
                    point.Project(mapSpatialReference);

                    // 创建点要素
                    IElement element = new MarkerElementClass();
                    element.Geometry = point;

                    // 设置点符号
                    IMarkerElement markerElement = element as IMarkerElement;
                    markerElement.Symbol = markerSymbol;

                    // 将要素添加到图层
                    graphicsContainer.AddElement(element, 0);
                }

                // 刷新地图控件
                axMapControl1.Refresh();
            }
        }
        public string GetMapUnit(esriUnits mapUnit)     //获取地图单位
        {
            string sMapUnit = string.Empty;
            switch (mapUnit)
            {
                case esriUnits.esriCentimeters:
                    sMapUnit = "厘米";
                    break;
                case esriUnits.esriDecimalDegrees:
                    sMapUnit = "十进制";
                    break;
                case esriUnits.esriDecimeters:
                    sMapUnit = "分米";
                    break;
                case esriUnits.esriFeet:
                    sMapUnit = "尺";
                    break;
                case esriUnits.esriInches:
                    sMapUnit = "英寸";
                    break;
                case esriUnits.esriKilometers:
                    sMapUnit = "千米";
                    break;
                case esriUnits.esriMeters:
                    sMapUnit = "米";
                    break;
                case esriUnits.esriMiles:
                    sMapUnit = "英里";
                    break;
                case esriUnits.esriMillimeters:
                    sMapUnit = "毫米";
                    break;
                case esriUnits.esriNauticalMiles:
                    sMapUnit = "海里";
                    break;
                case esriUnits.esriPoints:
                    sMapUnit = "点";
                    break;
                case esriUnits.esriUnitsLast:
                    sMapUnit = "UnitsLast";
                    break;
                case esriUnits.esriUnknownUnits:
                    sMapUnit = "未知单位";
                    break;
                case esriUnits.esriYards:
                    sMapUnit = "码";
                    break;
                default:
                    sMapUnit = "未知单位";
                    break;
            }
            return sMapUnit;
        }
        private void axMapControl1_OnMouseMove(object sender, ESRI.ArcGIS.Controls.IMapControlEvents2_OnMouseMoveEvent e)
        {
            //设置地图单位
            sMapUnits = GetMapUnit(axMapControl1.Map.MapUnits);
            condinate.Text = string.Format("{0:#.###} {1:#.###} {2}", e.mapX, e.mapY, sMapUnits);
        }

        private void 航迹线_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            // 获取地图控件对象
            AxMapControl mapControl = axMapControl1;

            // 打开文件选择对话框
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "文本文件 (*.txt)|*.txt";
            openFileDialog.Title = "选择文件";

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                string filePath = openFileDialog.FileName;

                // 获取地图对象和空间参考
                IMap map = mapControl.Map;
                ISpatialReference mapSpatialReference = map.SpatialReference;

                // 创建地理坐标系的空间参考对象
                ISpatialReferenceFactory spatialReferenceFactory = new SpatialReferenceEnvironmentClass();
                ISpatialReference geographicSpatialReference = spatialReferenceFactory.CreateGeographicCoordinateSystem((int)esriSRGeoCSType.esriSRGeoCS_WGS1984);

                // 创建几何环境对象
                IGeometryEnvironment geometryEnvironment = new GeometryEnvironmentClass();

                // 读取文件中的坐标数据
                string[] lines = File.ReadAllLines(filePath);

                // 创建点集合用于存储线的节点
                IPointCollection pointCollection = new PolylineClass();
       
                // 遍历每一行数据
                foreach (string linea in lines)
                {
                    // 解析经纬度坐标
                    string[] coordinates = linea.Split(',');
                    double longitude = Convert.ToDouble(coordinates[1]);
                    double latitude = Convert.ToDouble(coordinates[0]);

                    // 创建点对象并进行坐标转换
                    IPoint point = new PointClass();
                    point.X = longitude;
                    point.Y = latitude;
                    point.SpatialReference = geographicSpatialReference;
                    point.Project(mapSpatialReference);

                    // 将点添加到点集合中
                    pointCollection.AddPoint(point);
                }

                // 创建线要素
                IPolyline line = pointCollection as IPolyline;

                // 创建线符号
                ILineSymbol lineSymbol = new SimpleLineSymbolClass();
                // 设置线符号的样式、颜色、宽度等属性
                lineSymbol.Width= 6;
                lineSymbol.Color = GetRGBColor(65, 255, 45);

                // 创建图形要素
                IElement element = new LineElementClass();
                element.Geometry = line;
                ILineElement lineElement = element as ILineElement;
                lineElement.Symbol = lineSymbol;

                // 将线要素添加到地图的图形容器
                IGraphicsContainer graphicsContainer = map as IGraphicsContainer;
                graphicsContainer.AddElement(element, 0);

                // 刷新地图控件
                mapControl.Refresh();
            }
        }

        private void 航迹面_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            // 获取地图控件对象
            AxMapControl mapControl = axMapControl1;

            // 打开文件选择对话框
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "文本文件 (*.txt)|*.txt";
            openFileDialog.Title = "选择文件";

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                string filePath = openFileDialog.FileName;

                // 获取地图对象和空间参考
                IMap map = mapControl.Map;
                ISpatialReference mapSpatialReference = map.SpatialReference;

                // 创建地理坐标系的空间参考对象
                ISpatialReferenceFactory spatialReferenceFactory = new SpatialReferenceEnvironmentClass();
                ISpatialReference geographicSpatialReference = spatialReferenceFactory.CreateGeographicCoordinateSystem((int)esriSRGeoCSType.esriSRGeoCS_WGS1984);

                // 创建几何环境对象
                IGeometryEnvironment geometryEnvironment = new GeometryEnvironmentClass();

                // 读取文件中的坐标数据
                string[] lines = File.ReadAllLines(filePath);

                // 创建点集合用于存储多边形的节点
                IPointCollection pointCollection = new PolygonClass();

                // 遍历每一行数据
                foreach (string line in lines)
                {
                    // 解析经纬度坐标
                    string[] coordinates = line.Split(',');
                    double longitude = Convert.ToDouble(coordinates[1]);
                    double latitude = Convert.ToDouble(coordinates[0]);

                    // 创建点对象并进行坐标转换
                    IPoint point = new PointClass();
                    point.X = longitude;
                    point.Y = latitude;
                    point.SpatialReference = geographicSpatialReference;
                    point.Project(mapSpatialReference);

                    // 将点添加到点集合中
                    pointCollection.AddPoint(point);
                }

                // 创建面要素
                IPolygon polygon = pointCollection as IPolygon;

                // 创建面符号
                ISimpleFillSymbol fillSymbol = new SimpleFillSymbolClass();
                // 设置面符号的样式、颜色、轮廓等属性
                fillSymbol.Color = GetRGBColor(0,50 ,245);
                // 创建图形要素
                IElement element = new PolygonElementClass();
                element.Geometry = polygon;
                IFillShapeElement fillShapeElement = element as IFillShapeElement;
                fillShapeElement.Symbol = fillSymbol;

                // 将面要素添加到地图的图形容器
                IGraphicsContainer graphicsContainer = map as IGraphicsContainer;
                graphicsContainer.AddElement(element, 0);

                // 刷新地图控件
                mapControl.Refresh();
            }
        }

        private void ribbonControl1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void barButtonItem2_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            action = Action.Frame_Enlarge;
        }

        private void barButtonItem3_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            action = Action.Frame_Reduce;
        }
    }
}
