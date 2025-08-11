# from pyecharts.charts import Bar
# from pyecharts import options as opts
# from pyecharts.globals import ThemeType
 
# # 数据准备
# months = ['1月', '2月', '3月', '4月', '5月', '6月', 
#           '7月', '8月', '9月', '10月', '11月', '12月']
# evaporation = [2.0, 4.9, 7.0, 23.2, 25.6, 76.7, 
#                135.6, 162.2, 32.6, 20.0, 6.4, 3.3]
# precipitation = [2.6, 5.9, 9.0, 26.4, 28.7, 70.7, 
#                  175.6, 182.2, 48.7, 18.8, 6.0, 2.3]
 
# # 颜色配置
# COLOR_EVAPORATION = '#d14a61'
# COLOR_PRECIPITATION = '#5793f3'
 
# # 绘制柱状图
# bar = (
#     Bar(
#         init_opts=opts.InitOpts(
#             theme=ThemeType.MACARONS,
#             bg_color='#f9f9f9',
#             width='1000px',
#             height='600px',
#             chart_id='evaporation_precipitation_chart',
#             renderer='canvas'
#         )
#     )
#     .add_xaxis(xaxis_data=months)
#     .add_yaxis(
#         series_name='蒸发量',
#         y_axis=evaporation,
#         label_opts=opts.LabelOpts(
#             is_show=True,
#             position='top',
#             formatter='{c}', 
#             font_size=10
#         ),
#         itemstyle_opts=opts.ItemStyleOpts(color=COLOR_EVAPORATION),
#         tooltip_opts=opts.TooltipOpts(is_show=True)
#     )
#     .add_yaxis(
#         series_name='降水量',
#         y_axis=precipitation,
#         label_opts=opts.LabelOpts(
#             is_show=True,
#             position='top',
#             formatter='{c}',  
#             font_size=10
#         ),
#         itemstyle_opts=opts.ItemStyleOpts(color=COLOR_PRECIPITATION),
#         tooltip_opts=opts.TooltipOpts(is_show=True)
#     )
#     .set_global_opts(
#         title_opts=opts.TitleOpts(
#             title='1-12月蒸发量与降水量对比',
#             subtitle='数据来源: 模拟数据 | 单位: mm',
#             pos_left='center',
#             title_textstyle_opts=opts.TextStyleOpts(
#                 font_size=18,
#                 font_weight='bold'
#             ),
#             subtitle_textstyle_opts=opts.TextStyleOpts(
#                 font_size=12,
#                 color='#666'
#             )
#         ),
#         legend_opts=opts.LegendOpts(
#             pos_top='10%',
#             pos_left='center',
#             item_width=15,
#             item_height=15,
#             textstyle_opts=opts.TextStyleOpts(font_size=12)
#         ),
#         toolbox_opts=opts.ToolboxOpts(
#             pos_top='5%',
#             pos_right='5%',
#             feature={
#                 "saveAsImage": {"show": True, "title": "保存图片", "type": "png"},
#                 "dataView": {"show": True, "title": "数据视图", "readOnly": True},
#                 "restore": {"show": True, "title": "重置"},
#                 "dataZoom": {"show": True, "title": {"zoom": "区域缩放", "back": "缩放还原"}}
#             }
#         ),
#         tooltip_opts=opts.TooltipOpts(
#             trigger='axis',
#             axis_pointer_type='shadow',
#             formatter='{b}<br/>{a0}: {c0} mm<br/>{a1}: {c1} mm'
#         ),
#         xaxis_opts=opts.AxisOpts(
#             type_='category',
#             axislabel_opts=opts.LabelOpts(font_size=12),
#             axisline_opts=opts.AxisLineOpts(is_show=True),
#             name='月份',
#             name_location='middle',
#             name_gap=30
#         ),
#         yaxis_opts=opts.AxisOpts(
#             type_='value',
#             name='数值 (mm)',
#             name_textstyle_opts=opts.TextStyleOpts(font_size=12),
#             axislabel_opts=opts.LabelOpts(font_size=12),
#             splitline_opts=opts.SplitLineOpts(
#                 is_show=True,
#                 linestyle_opts=opts.LineStyleOpts(
#                     color='#eee',
#                     type_='dashed'
#                 )
#             )
#         )
#     )
# )
 
# # 渲染图表
# bar.render('蒸发量与降水量对比图.html')
# print("图表已生成：蒸发量与降水量对比图.html")



import pyecharts.options as opts
from pyecharts.charts import Gauge
from pyecharts.globals import ThemeType

# 创建一个仪表盘图表对象
gauge = (
    Gauge(
        init_opts=opts.InitOpts(
            theme=ThemeType.MACARONS,  # 设置主题为MACARONS
            width='1000px',  # 设置图表宽度为1000像素
            height='600px',  # 设置图表高度为600像素
            chart_id='gauge_chart'  # 设置图表ID为'gauge_chart'
        )
    )
    .add(
        series_name="完成率",  # 设置系列名称为“完成率”
        data_pair=[["完成率", 50]],  # 设置数据对，完成率为50%
        radius='70%',  # 设置仪表盘的半径为70%
        min_=0,  # 设置最小值为0
        max_=100,  # 设置最大值为100
        pointer=opts.GaugePointerOpts(  # 设置指针选项
            length="0%",  # 设置指针长度为80%的半径
            width=8,  # 设置指针宽度为8像素
        ),
        axisline_opts=opts.AxisLineOpts(  # 设置轴线选项
            linestyle_opts=opts.LineStyleOpts(  # 设置轴线样式选项
                width=30,  # 设置轴线宽度为30像素
                color=[  # 设置轴线颜色，使用不同的颜色段表示不同的完成率范围
                    (0.3, "#67e0e3"),  # 0-30% 完成率的颜色
                    (0.7, "#37a2da"),  # 30-70% 完成率的颜色
                    (1, "#fd666d")  # 70%-100% 完成率的颜色
                ]
            )
        ),
        axislabel_opts=opts.LabelOpts(  # 设置轴标签选项
            font_size=12,  # 设置标签字体大小为12像素
            color="#333"  # 设置标签字体颜色为深灰色
        ),
        detail_label_opts=opts.GaugeDetailOpts(  # 设置详细标签选项
            is_show=True,  # 显示详细标签
            formatter="{value}%",  # 设置标签格式化器，显示百分比
            font_size=40,  # 设置详细标签字体大小为40像素
            color="#333",  # 设置详细标签字体颜色为深灰色
            font_weight="bolder",  # 设置详细标签字体加粗
            offset_center=[0, "40%"]  # 调整详细标签的位置，相对于中心点向下偏移40%
        ),
        title_label_opts=opts.GaugeTitleOpts(  # 添加标题标签选项
            is_show=True,  # 显示标题标签
            offset_center=[0, "-20%"],  # 调整标题标签的位置，相对于中心点向上偏移20%
            font_size=20  # 设置标题标签字体大小为20像素
        )
    )
    .set_global_opts(  # 设置全局配置项
        title_opts=opts.TitleOpts(  # 设置标题配置项
            title="任务完成率",  # 设置标题文本为“任务完成率”
            pos_left="center",  # 设置标题位置在左侧中心
            title_textstyle_opts=opts.TextStyleOpts(  # 设置标题文本样式配置项
                font_size=24,  # 设置标题字体大小为24像素
                font_weight="bolder"  # 设置标题字体加粗
            )
        ),
        legend_opts=opts.LegendOpts(is_show=False)  # 设置图例配置项，不显示图例
    )
)

# 渲染图表并生成HTML文件
gauge.render('任务完成率仪表盘.html')
print("图表已生成：任务完成率仪表盘.html")  # 打印生成的文件名
