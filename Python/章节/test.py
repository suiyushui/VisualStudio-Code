# from pyecharts import options as opts
# from pyecharts.charts import Gauge

# gauge = (
#     Gauge(init_opts=opts.InitOpts(width="600px", height="420px"))
#     .add(
#         series_name="完成率",

#         data_pair=[["完成率", 50]],
#         radius="70%",
#         detail_label_opts=opts.GaugeDetailOpts(
#             offset_center=[0, "40%"],   # 把 50% 数值往下挪
#             font_size=14,
#             border_width=1,
#             border_color="rgba(0,0,0,0.3)",
#             color="#b83b5e"
#         )
#     )
#     .set_global_opts( # 全局配置项
#         # 1) 标题
#         title_opts=opts.TitleOpts(
#             title="任务完成率",
#             pos_left="center",
#             pos_top="10px",          # 标题距离画布顶部 10px
#             title_textstyle_opts=opts.TextStyleOpts(
#                 font_size=22,
#                 font_weight="bold",
#                 color="#8D38ED"
#             )
#         ),
#         # 2) 图例（放在标题下方）
#         legend_opts=opts.LegendOpts(
#             is_show=True,            # 显示图例
#             pos_left="center",       # 水平居中
#             pos_top="40px",          # 距离画布顶部 50px，确保在标题下方
#             orient="horizontal",      # 水平排布
#             border_color="#08d9d6",
#             border_width=1,
#         )
#     )
# )

# gauge.render("gauge_legend_below_title.html")

# from pyecharts import options as opts
# from pyecharts.charts import Gauge

# gauge = (
#     Gauge()
#     .add(
#         series_name="核心指标",
#         data_pair=[["完成度", 48.5]],
#         radius="90%",
#         min_=0,
#         max_=100,
#         split_number=5,  # 刻度分割数
#         axisline_opts=opts.AxisLineOpts(
#             linestyle_opts=opts.LineStyleOpts(
#                 width=30,
#                 color=[(0.2, "#91CC75"), (0.8, "#FDDD60"), (1, "#FF6B81")]
#             )
#         ),
#         detail_label_opts=opts.GaugeDetailOpts(
#             formatter="{}万\n销售额",  # 多行文本
#             font_size=25,
#             offset_center=[0, "40%"]
#         ),
#         # 添加辅助刻度线
#         axislabel_opts=opts.LabelOpts(
#             distance=15,
#             formatter="{value}%"
#         )
#     )
#     .set_global_opts(
#         title_opts=opts.TitleOpts(title="销售业绩仪表盘", subtitle="2023年度"),
#         tooltip_opts=opts.TooltipOpts(formatter="{a}: {c}%")
#     )
# )
# gauge.render("advanced_gauge.html")



# def add(a, b):
#     result = a + b
#     return result

# x = 10
# y = 20
# sum = add(x, y)
# print(f"总和：{sum}")


# import re 
# import math
# import random
# import calendar
# def test_addition():
#     assert 1 + 1 == 2

# def test_failure():
# #     assert "hello".upper() == "HELLO"
# print(math.pi)
# str1="hello world"
# str2="/[a-h]*/g"
# print(re.match(str2,str1))
# print(calendar.weekday(random.randint(1990,2100),1,13))
# print(calendar.weekday(2022,1,13))
# print(calendar.calendar(2022))
# print(calendar.month(2021,12))
# print([calendar.month_name[i] for i in range(1,13)])

# print(random.randint(1,100))
# print(random.randrange(1,100,2)) # 输出1到100之间的奇数
# print(random.choices(["apple","banana","orange"],weights=None,k=3))

# result= re.match(r"(\d+)-(\d+)-(\d+)", "2022-01-13")
# """
#     这里的 r 表示原始字符串（raw string）的意思。在 Python 中，原始字符串用于处理正则表达式时非常有用，因为它允许正则表达式中的反斜杠（\）被当作普通字符处理，而不需要对其进行转义。
#     例如，r'\d+' 中的 r 告诉 Python 解释器，这个字符串是原始字符串，因此 \d 会被当作正则表达式中的特殊字符来处理，表示匹配任何数字。如果没有 r 前缀，\d 在 Python 字符串中会被解释为转义序列，而这在正则表达式中并不是我们想要的结果。
#     所以，m = re.search(r'\d+', text) 这行代码的意思是：在字符串 text 中搜索第一个匹配正则表达式模式 \d+ 的子串，其中 \d+ 表示匹配一个或多个数字。re.search() 函数会返回一个匹配对象，如果找到了匹配项，可以通过这个对象来获取匹配的信息。

# """
# print(result)
# print(result.group(1))
# print(result.group(2))
# print(result.group(3))

# print(re.findall(r'<.*?>','<html><body><h1>Hello World</h1></body></html>'))
# print(re.findall(r'<.*>','<html><body><h1>Hello World</h1></body></html>'))
# print(re.search(r'\d+',"tmp1234567890").group())
# masked=re.sub((r'(\d{3})(\d{4})(\d*)'),r'\1****\3','1234567890')
# print(masked)


# print(re.findall(r'1[3-9]\d{9}','13812345678 15612345678 11912345678'))

# import re
# print(re.sub(r'(?<!^)(?=[A-Z])','_','HelloWorldPython').lower())

# import random

# for i in range(10):
#     print(f"{int(random.random()*10)}")
# for i in range(20):
    # print(f"{int(random.random()*17+48)}",end=" ")

# print(list(filter(lambda x:x%2==0,range(1,10))))
# my_list=[1,2,3,'a','b','c']
# print(type(filter(lambda x:isinstance(x,int),my_list)))
# print(list(filter(lambda x:isinstance(x,int),my_list)))
# my_list.extend([4,5,6])
# count=my_list.count(2)
# print(count)    


# my_list=[1,2,3]
# my_list.append(4)
# my_list.extend([5,6,7])
# print(my_list)
# print(type((42,)))

# def foo(a, b=[]):
#     b.append(a)
#     return b
# print(foo(1))
# print(foo(2, []))
# print(foo(3))


# class Parent:
#     def __init__(self):
#         self.value = 10
# class Child(Parent):
#     def __init__(self):
#         Parent.__init__(self)  # 显式调用父类初始化
#         self.value = 20
# obj = Child()
# print(obj.value)

# from functools import lru_cache
# @lru_cache(maxsize=2)
# def fib(n):
#     if n < 2:
#         return n
#     return fib(n-1) + fib(n-2)
# print(fib(5))


# print(sum(i * i for i in range(1, 5) if i % 2 == 1))


# import re
# print(re.sub(r'\d+', 'X', 'a1b23c456'))


# print(max("hello".count(c) for c in "hello"))

# import threading
# class ThreadfeQueue:
#     def __init__(self):
#         self.queue = []
#         self.lock = threading.Lock()

#     def put(self, item):
#         with self.lock:
#             self.queue.append(item)
    
#     def get(self):
#         with self.lock:
#             if not self.queue:
#                 return None
#             return self.queue.pop(0)

#     def empty(self):
#         with self.lock:
#             return not self.queue


# class Singleton:
#     _instance = None
#     def __new__(cls, *args, **kwargs):
#         if not cls._instance:
#             cls._instance = super().__new__(cls)
#         return cls._instance



import asyncio
from random import randint

async def mock_fetch(url: str) -> dict:
    await asyncio.sleep(0.5) 
    if randint(1, 10) == 1:  
        return {"url": url, "error": "Timeout"}
    return {"url": url, "status": 200}

async def fetch_all(urls: list) -> list:
    tasks = [mock_fetch(url) for url in urls]
    return await asyncio.gather(*tasks)
