tinudict={"apple":10,"banana":20,"orange":30,"grape":40,"mango":50}
#值可以取任意类型，键只能是不可变类型，如字符串、数字、元组等。
print(tinudict['apple'])

# del tinudict["apple"] #删除键为"apple"的项
# tinudict.clear() #清空字典
# del tinudict #删除字典

tinudict2=tinudict.copy() #复制字典
print(tinudict2)
# print(tinudict.keys()) #获取字典所有键
#print(tinudict.values()) #获取字典所有值
#print(tinudict.items()) #获取字典所有项    

# for index,value in enumerate(tinudict):
#     print(index,value)
# for key in tinudict:
#     print(key,tinudict[key])
# for index,value in tinudict.items():
#     print(index,value)


