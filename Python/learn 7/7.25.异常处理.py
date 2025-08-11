# while True:
#     my_str=input("输入一个数字：")
#     try:
#         num=int(my_str)
#         if num< 0:
#             raise ValueError("输入的数字不能为负数！")
#         elif num>100:
#             raise ValueError("输入的数字不能大于100！")
#         else:
#             print(num)
#     except ValueError as e:
#         print("输入的不是数字！")
#         print(e)
#     else:
#         print("程序正常结束")
#         break
#     finally:
#         print("程序结束")
from pathlib import Path
p=Path('./Python/learn/test.txt')
p.parent.mkdir(parents=True, exist_ok=True)
p.write_text('hello world',encoding='utf-8')
print(p.read_text(encoding='utf-8'))
print(Path.cwd())

# f=open("./Python/learn/test.txt","r",encoding='utf-8')
# print(f.read())
# f.close()

# with open("./Python/learn/test.txt","r",encoding='utf-8') as f:
#     print(f.read())
