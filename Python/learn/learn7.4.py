#变量名只能包含字母,数字,下划线,不能以数字开头,变量名不能与关键字冲突
#变量名不能包含空格,变量名不能包含特殊字符

#常用的字符串操作函数
#大小写转换
print("hello word".capitalize())#首字母大写
print("HELLO WORLD".title())#每个单词首字母大写
print("hello world".upper())#全部大写
print("hello world".lower())#全部小写
print("Hello World".swapcase())#大小写互换
#字符串去除空白操作
print("  hello world  ".strip())#去除左右两侧空白
print("  hello world  ".lstrip())#去除左侧空白
print("  hello world  ".rstrip())#去除右侧空白
s="adhello world"
print(s.strip('ad'))
#字符串比较
print("hello"=="Hello")
print("hello".__ne__("Hello"))#不等于
print("hello".__eq__("Hello"))
print("hello" < "Hello")#小于
print("hello" > "Hello")#大于
print("hello" <= "Hello")#小于等于
print("hello" >= "Hello")#大于等于


#列表
bicyles=["trek","cannondale","redline","specialized"]
print(bicyles)
bicyles.append("corvette")
bicyles.inset(0,"monza")
del bicyles[2]
popped_bicyle=bicyles.pop()
print(popped_bicyle)
print(bicyles)