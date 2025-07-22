import sys
num=1000
print(num,type(num),sys.getsizeof(num))
num=str(num)
print(num,type(num),sys.getsizeof(num))
print("%s" %num)
print(ord('1'))
# 49 is the ASCII value for '1'
print(chr(49)) 
print(("sadf afasf").capitalize())
print(("sadf afasf").title())
print(("sadf afasf").swapcase())
print(chr(65))
print(ord('A'))
#chr(),ord(),title(),capitalize(),swapcase()
print("hello world".find("world"))  
print("hello world".rfind("h"))  

s="hello world, hello python"
print(s.find("python",5))
print(s.rfind("python"))
try:
    print(s.index("python"))
except ValueError as e:
    print("Error:", e)
print(s.count('l'))
print(s.count('l',1,10))
print(s.startswith("h",0))
print(s.endswith("n",0,10))
print(s.isalnum())  # 检查字符串是否只包含字母和数字
print(s.isalpha())  # 检查字符串是否只包含字母
print(s.isdigit())  # 检查字符串是否只包含数字
print(s.islower())  # 检查字符串是否只包含小写字母
print(s.isupper())  # 检查字符串是否只包含大写字母      
print(s.isspace())  # 检查字符串是否只包含空白字符
print(s.istitle())  # 检查字符串中所有单词的首字母是否为大写，且其他字母为小写

s1="abcdefghijklmnopqrstuvwxyz"
print(s1.replace("abc","ABC",1))

s2="hello world, hello python, hello java"
print(s2.split(","))
print(s2.split(" "))
print(s2.split(" ",2))
print(s2.count("hello"))
print(' '.join(['hello','world']))
print(','.join(['hello','world','hello','python']))

print("hello" in s2)
print("world" not in s2)
print(chr(97),ord('a'))

print(sorted("hello world"))
print(str(sorted("hello world",reverse=True)))

print(type('hello'))
print(type(123))

# 1000 <class 'int'> 28
# 1000 <class 'str'> 45
# 1000
# 49
# 1
# Sadf afasf
# Sadf Afasf
# SADF AFASF
# A
# 65
# 6
# 0
# 19
# 19
# 19
# 5
# 3
# True
# False
# False
# False
# False
# True
# False
# False
# False
# ABCdefghijklmnopqrstuvwxyz
# ['hello world', ' hello python', ' hello java']
# ['hello', 'world,', 'hello', 'python,', 'hello', 'java']
# ['hello', 'world,', 'hello python, hello java']
# 3
# hello world
# hello,world,hello,python
# True
# False
# a 97
# [' ', 'd', 'e', 'h', 'l', 'l', 'l', 'o', 'o', 'r', 'w']
# ['w', 'r', 'o', 'o', 'l', 'l', 'l', 'h', 'e', 'd', ' ']
# <class 'str'>
# <class 'int'>

import re

# 编译正则表达式模式
pattern = re.compile(r"\b[\w.%+-]+@[\w.-]+\.[a-zA-Z]{2,6}\b", flags=re.IGNORECASE)

# 要搜索的文本
text = "Please contact us at info@example.com for any inquiries."

try:
    # 使用编译过的模式进行搜索
    match = pattern.search(text)
    
    if match:
        print("找到邮箱地址:", match.group())
    else:
        print("未找到邮箱地址。")
except re.error as e:
    print("正则表达式错误:", e)
except Exception as e:
    print("发生错误:", e)
