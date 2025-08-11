# list01=[['name','Alice'],['age',25],['gender','female']]
# dict01=dict(list01)
# print(dict01)
# import json
# json_str='{"name":"Alice","age":25,"gender":"female"}'
# dict02=json.loads(json_str)
# print(dict01)
# tuple01=(('name','Alice'),('age',25),('gender','female'))
# dict01=dict(tuple01)
# print(dict01)
# dict01={i:j for i ,j in enumerate(range(1,6))}
# print(dict01) 
# dict01=dict.fromkeys(['name','age','gender'],None)
# print(dict01)
# del dict01['name']
# print(dict01)
# print(dict01['age'])
# print(dict01.get('name'))
# #setdefault()方法返回指定键的值，如果该键不存在，则将其添加到字典中并返回None。
# print(dict01.setdefault('name','unknown')) 
# print(dict01)
# for key,value in dict01.items():
#     print(key,value)
#     print(dict01.get(key))

# dict02={'name':'Bob','age':30,'gender':'male'}
# dict03={**dict01,**dict02}
# print(dict03)

print(dict(enumerate(range(1,6))))

person= {"name": "Alice", "age": 25}
person.update({"gender": "female"})
person.update([("height", 175)])
print(person)

person.pop("age") # 删除键值对
print(person) 
del person["gender"] # 删除键值对
print(person) 

person ={"name": "Bob", "age":30}
# age =person.pop("age",None) # 删除键值对，并返回对应的值
# print(age)
# print(person)
# height=person.pop("age",20)
# print(height)

 # 随机删除一个键值对,在python3.7之后，默认删除最后插入的键值对
item= person.popitem()
print(item)
