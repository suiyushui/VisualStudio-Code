# my_dict={"apple":10,"banana":2,"orange":5,"grape":15}
# sorted_dict=sorted(my_dict.items(),key=lambda x:x[1],reverse=False)
# print(sorted_dict)
# from collections import OrderedDict
# my_dict=OrderedDict({"apple":10,"banana":2,"orange":5,"grape":15})
# print(my_dict)
# my_dict.move_to_end("apple") # 移动 apple 到最后
# print(my_dict) 
# my_dict.move_to_end("apple",last=False) # 移动 apple 到最前
# print(my_dict) 

# from operator import itemgetter

# data = [{'name': 'Alice', 'age': 30}, {'name': 'Bob', 'age': 25}]
# # 按 'age' 排序
# sorted_data = sorted(data, key=itemgetter('age'))  # 等价于 lambda x: x['age']
# print(sorted_data)  # [{'name': 'Bob', 'age': 25}, {'name': 'Alice', 'age': 30}]

from collections import OrderedDict
from operator import itemgetter

data = [{'name': 'Alice', 'age': 30}, {'name': 'Bob', 'age': 25}]
print(data)
sorted_data = sorted(data, key=itemgetter('age'))
print(sorted_data)
dict01 = {'a': 1, 'b': 2, 'c': 3}
dict02 = {'b': 2, 'c': 3, 'e': 5}
merged_dict={**dict01, **dict02}
print(merged_dict)
# 合并两个字典，相同的键值对，后面的字典的值覆盖前面的字典的值
dict03=dict01.copy()
dict04=dict01
print(id(dict01),id(dict03),id(dict04))
del dict04
dict03.clear()
dict01.popitem()
print(dict01)
