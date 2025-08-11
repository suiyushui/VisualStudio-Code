# # import pyecharts as pe

# # print(pe.__version__)

# # from pyecharts.charts import Bar 
# from pyecharts import options as opts
# from pyecharts.charts import Pie
# # from pyecharts.charts import Line
# from pyecharts.globals import ThemeType

# # 1.柱状图
# # bar = (
# #     Bar()
# #     .add_xaxis(["衬衫", "羊毛衫", "毛衣"])
# #     .add_yaxis("商家A", [5, 3, 10])
# #     .add_yaxis("商家B", [6, 3, 8])
# #     .set_global_opts(
# #         title_opts=opts.TitleOpts(title="商品类别"),
# #         xaxis_opts=opts.AxisOpts(name="商品类别"),
# #         yaxis_opts=opts.AxisOpts(name="商品数量"),
# #     )
# # ).render("test.html")

# # 2.饼图
# pie = (
#     Pie(init_opts=opts.InitOpts(theme=ThemeType.LIGHT))
#    .add("", [list(z) for z in zip(["A", "B", "C"], [11, 12, 13])],
#         radius=["40%", "75%"],
#         rosetype="radius",
#     )
#    .set_global_opts(title_opts=opts.TitleOpts(title="某商店销售情况"))
#    .set_series_opts(label_opts=opts.LabelOpts(formatter="{b}: {c}"))
# ).render("test.html")


from pyecharts import options as opts
from pyecharts.charts import Line
import random

# 生成示例数据
x_data = [f"第{i}天" for i in range(1, 31)]  # 30天数据
y_data = [random.randint(10, 100) for _ in range(30)]

# 1. 基础滑块型数据缩放
line1 = Line(init_opts=opts.InitOpts(width="1000px", height="400px"))
line1.add_xaxis(xaxis_data=x_data)
line1.add_yaxis(series_name="基础滑块缩放", y_axis=y_data)
line1.set_global_opts(
    title_opts=opts.TitleOpts(title="滑块型数据缩放示例"),
    datazoom_opts=opts.DataZoomOpts(
        type_="slider",  # 滑块型
        range_start=20,  # 初始显示20%-80%的数据
        range_end=80
    )
)
line1.render("datazoom_slider.html")

# 2. 内置型数据缩放（鼠标滚轮控制）
line2 = Line(init_opts=opts.InitOpts(width="1000px", height="400px"))
line2.add_xaxis(xaxis_data=x_data)
line2.add_yaxis(series_name="内置滚轮缩放", y_axis=y_data)
line2.set_global_opts(
    title_opts=opts.TitleOpts(title="内置型数据缩放示例"),
    datazoom_opts=opts.DataZoomOpts(
        type_="inside",  # 内置型
        range_start=0,
        range_end=50
    )
)
line2.render("datazoom_inside.html")

# 3. 同时使用滑块和内置缩放
line3 = Line(init_opts=opts.InitOpts(width="1000px", height="400px"))
line3.add_xaxis(xaxis_data=x_data)
line3.add_yaxis(series_name="混合缩放模式", y_axis=y_data)
line3.set_global_opts(
    title_opts=opts.TitleOpts(title="混合数据缩放示例"),
    datazoom_opts=[
        opts.DataZoomOpts(type_="slider"),  # 滑块控制
        opts.DataZoomOpts(type_="inside")   # 滚轮控制
    ]
)
line3.render("datazoom_combined.html")

# 4. 垂直方向的数据缩放
line4 = Line(init_opts=opts.InitOpts(width="1000px", height="400px"))
line4.add_xaxis(xaxis_data=x_data)
line4.add_yaxis(series_name="垂直缩放", y_axis=y_data)
line4.set_global_opts(
    title_opts=opts.TitleOpts(title="垂直方向数据缩放示例"),
    datazoom_opts=opts.DataZoomOpts(
        type_="slider",
        orient="vertical",  # 垂直方向
        range_start=30,
        range_end=70
    )
)
line4.render("datazoom_vertical.html")

print("四种数据缩放示例已生成对应的HTML文件")
