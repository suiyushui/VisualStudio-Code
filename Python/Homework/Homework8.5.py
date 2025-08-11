from pyecharts import options as opts
from pyecharts.charts import Bar
from pyecharts.faker import Faker # 生成假数据
from pyecharts.charts import HeatMap
import random
import math
from pyecharts.charts import Line3D
from pyecharts.charts import Polar
from pyecharts.charts import Radar
from pyecharts.charts import Scatter
from pyecharts.charts import Funnel


# Bar-堆叠数据（部分）
c1=(
    Bar() # 创建 Bar 实例
    .add_xaxis(Faker.choose()) # 添加 x 轴数据
    .add_yaxis("商家A", Faker.values(),stack="stack1") # 添加 y 轴数据
    .add_yaxis("商家B", Faker.values(),stack="stack1") # 添加 y 轴数据
    .add_yaxis("商家C", Faker.values(),stack="stack2") # 添加 y 轴数据
    .add_yaxis("商家D", Faker.values(),stack="stack2") # 
    .set_series_opts( # 设置系列配置项
        label_opts=opts.LabelOpts(is_show=False), # 隐藏数据标签
    )
    .set_global_opts( # 设置全局配置项
        title_opts=opts.TitleOpts(title="Bar-堆叠数据（部分）")
    )
    .render("bar_stack1.html") # 渲染为 html 文件
)

# Bar-反转 Y 轴
c2= (
    Bar() # 创建 Bar 实例
    .add_xaxis(Faker.choose()) # 添加 x 轴数据
    .add_yaxis("商家A", Faker.values()) # 添加 y 轴数据
    .add_yaxis("商家B", Faker.values()) # 添加 y 轴数据
    .reversal_axis() # 反转 y 轴
    .set_series_opts( # 设置系列配置项
        label_opts=opts.LabelOpts(position="right"), # 隐藏数据标签
        title_opts=opts.TitleOpts(title="Bar-反转 Y 轴") # 设置标题
    )
    .render("bar_reversal_axis.html") # 渲染为 html 文件
)

# 热力图
value=[[i,j,random.randint(0,50)] for i in range(24) for j in range(7)]

c3=(
    HeatMap() # 创建 HeatMap 实例
    .add_xaxis(Faker.clock) # 添加 x 轴数据
    .add_yaxis("series0", # 当前数据系列的名称
               Faker.week, # Y 轴的标签数据
               value, # 数据集,前两元素是 x 轴和 y 轴的索引位置，后面是该位置对应的数值
               label_opts=opts.LabelOpts(position="middle")
            ) # 添加 y 轴数据
    .set_global_opts( # 设置全局配置项
        title_opts=opts.TitleOpts(title="HeatMap-基本示例"), # 设置标题
        visualmap_opts=opts.VisualMapOpts(), # 显示视觉映射组件
    )
    .render("heatmap_basic.html")
)

# 3D折线图
data=[]
for t in range(0, 25000):
    _t = t / 1000
    x = (1 + 0.25 * math.cos(75 * _t)) * math.cos(_t) # 3D 坐标系中 x 轴的数值
    y = (1 + 0.25 * math.cos(75 * _t)) * math.sin(_t) # 3D 坐标系中 y 轴的数值
    z = _t + 2.0 * math.sin(75 * _t) # 3D 坐标系中 z 轴的数值
    data.append([x, y, z]) # 添加数据
c4=(
    Line3D() # 创建 Line3D 实例
    .add(
        "",# 系列名称
        data, # 数据
        xaxis3d_opts=opts.Axis3DOpts(Faker.clock,type_="value"), # 设置 x 轴
        yaxis3d_opts=opts.Axis3DOpts(Faker.week,type_="value"), # 设置 y 轴
        grid3d_opts=opts.Grid3DOpts( 
            width=100, depth=100,rotate_speed=10,is_rotate=True
        ),
    )
    .set_global_opts(
        visualmap_opts=opts.VisualMapOpts(
            max_=30, # 设置数据最大值
            min_=0, # 设置数据最小值
            range_color=Faker.visual_color # 设置颜色渐变
        ),
        title_opts=opts.TitleOpts(title="Line3D-旋转的弹簧"),
    )
    .render("line3d_autorotate.html")
)

# 散点图——Polar_love
data=[]
for i in range(101):
    theta = i / 100 * 360
    r = 5 * (1 + math.sin(theta/180*math.pi))
    data.append([r,theta])
hour=[i for i in range(1,25)]
c5=(
    Polar() # 创建 Polar 实例
    .add_schema( # 设置极坐标系的配置项
        angleaxis_opts=opts.AngleAxisOpts( # 设置角度轴配置项
            data=hour, # 角度轴数据 
            type_="value", # 设置角度轴类型为数值
            boundary_gap=False, # 显示全部刻度
            start_angle=0, # 起始角度
            is_clockwise=True, # 是否是顺时针
            split_number=12 # 刻度数量
        )
    )
    .add("love",data,label_opts=opts.LabelOpts(is_show=False))
    .set_global_opts(title_opts=opts.TitleOpts(title="Polar_love"))
    .render("polar_love.html")
)

# 雷达图
v1=[[4300,10000,28000,35000,50000,19000]]
v2=[[5000,14000,28000,31000,42000,21000]]

c6=(
    Radar() # 创建 Radar 实例
    .add_schema( # 设置雷达图的配置项
        schema=[ # 雷达图的指示器
            opts.RadarIndicatorItem(name="销售", max_=6500),# 设置雷达图的指示器名称和最大值
            opts.RadarIndicatorItem(name="管理", max_=16000),
            opts.RadarIndicatorItem(name="信息技术", max_=30000),
            opts.RadarIndicatorItem(name="客服", max_=38000),
            opts.RadarIndicatorItem(name="研发", max_=52000),
            opts.RadarIndicatorItem(name="市场", max_=25000),
        ]
    )
    .add("预算分配", v1)# 添加数据系列
    .add("实际开销", v2) # 添加数据系列
    .set_series_opts(label_opts=opts.LabelOpts(is_show=False)) # 隐藏数据标签
    .set_global_opts(
        legend_opts=opts.LegendOpts(selected_mode="single"), # 设置图例位置
        title_opts=opts.TitleOpts(title="Radar-单例模式") # 设置标题
    )
    .render("radar_single.html")
)

data = [
    [10.0, 8.04],
    [8.0, 6.95],
    [13.0, 7.58],
    [9.0, 8.81],
    [11.0, 8.33],
    [14.0, 9.96],
    [6.0, 7.24],
    [4.0, 4.26],
    [12.0, 10.84],
    [7.0, 4.82],
    [5.0, 5.68],
]
y_data=[d[1] for d in data]
x_data=[d[0] for d in data]

c7=(
    Scatter() # 创建 Scatter 实例
    .add_xaxis(xaxis_data=x_data) # 添加 x 轴数据
    .add_yaxis( # 添加 y 轴数据
        series_name="",
        y_axis=y_data,# 纵坐标数据
        symbol_size=20,# 设置标记大小
        label_opts=opts.LabelOpts(is_show=False),
    )
    .set_series_opts() # 设置系列配置项
    .set_global_opts(
        xaxis_opts=opts.AxisOpts(
            type_="value", # 设置 x 轴类型为数值
            splitline_opts=opts.SplitLineOpts(is_show=True), # 显示 x 轴网格线
        ), # 设置 x 轴名称
        yaxis_opts=opts.AxisOpts(
            type_="value",
            axislabel_opts= opts.LabelOpts(formatter="{value} ml"), # 设置 y 轴标签格式
            splitline_opts=opts.SplitLineOpts(is_show=True), # 显示 y 轴网格线
        ),
        toolbox_opts=opts.ToolboxOpts(is_show=False), # 显示工具箱
    )    
    .render("scatter_basic.html") # 渲染为 html 文件
)

# 漏斗图
c8=(
    Funnel() # 创建 Funnel 实例
    .add("商品", [list(z) for z in zip(Faker.choose(), Faker.values())]) # 添加数据
    .set_global_opts(title_opts=opts.TitleOpts(title="Funnel-基本图例")) # 设置标题
    .render("funnel_product.html") # 渲染为 html 文件
)