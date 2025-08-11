from datetime import datetime
import json
import os
def print_json_tree(data, indent=0, last=True):
    """递归打印JSON数据的树形结构"""
    prefix = '└── ' if last else '├── '
    if isinstance(data, dict):
        print(' ' * indent + prefix + '{} (dict)'.format('root' if indent==0 else ''))
        count = len(data)
        for i, (key, value) in enumerate(data.items()):
            is_last = (i == count - 1)
            print(' ' * (indent + 4) + '├── ' + str(key))
            print_json_tree(value, indent + 8, is_last)
    elif isinstance(data, list):
        print(' ' * indent + prefix + '[] (list, len={})'.format(len(data)))
        if data:
            # 只展示第一个元素的结构作为代表
            print_json_tree(data[0], indent + 4, last=True)
    else:
        type_name = type(data).__name__
        print(' ' * indent + prefix + '{} ({})'.format(repr(data)[:50], type_name))




json_str='{"name": "Alice", "age": 25, "city": "Beijing", "hobbies": ["reading", "swimming", "traveling"], "pets": {"dog": "Buddy", "cat": "Whiskers"}, "married": false, "income": null, "children": [{"name": "Bob", "age": 18}, {"name": "Cindy", "age": 16}]}'
py_obj=json.loads(json_str)
# print(py_obj)

file_path='Python/learn/data.json'
if not os.path.exists(file_path):
    os.makedirs(os.path.dirname(file_path))  
with open(file_path, 'w', encoding='utf-8') as f:
    json.dump(py_obj, f, ensure_ascii=False ,indent=4)

class User:
    def __init__(self,name,age) -> None:
        self.name=name
        self.age=age
def user_encoder(obj):
    if isinstance(obj,User):
        return {"name":obj.name,"age":obj.age}
    raise TypeError(f"Object of type {type(obj)}")
user =User("Alice",25)
json_str=json.dumps(user,default=user_encoder)
print(json_str)

class CustomEncoder(json.JSONEncoder):
    def default(self, obj):
        if isinstance(obj, User):
            return obj.__dict__ # 直接返回对象的__dict__属性
        if isinstance(obj,datetime):
            return obj.isoformat()
        return super().default(obj)

        