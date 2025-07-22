# import re
# pattern = r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.\w+$';
# email = 'abc@123.com';
# if re.match(pattern, email):
#     print("Valid email address") # Valid email address
# else:
#     print("Invalid email address")

# pat="\\d+"
# result=re.search(pat, "hello123world")
# print(result.group())  # 123

# print(R"hello\nworld")  # hello\nworld
# name ="John Doe"
# age= 30
# message1= "Hello %s, you are %d years old."%(name, age)
# message2 = f"Hello {name}, you are {age} years old."
# message3 = "Hello {}, you are {} years old.".format(name, age)
# print(message1)
# print(message2)
# print(message3)
# s1='hello'
# s2="world"
# s3="""hello world !"""
# print(s1)
# print(s2)
# print(s3)
# print("Hello World")
# str="hello"+"world"
# print(str)
# str=str[:4] + str[5:]
# print(str)
# print(type(str))
# print('从来不会放弃的坚强，\'\'\'从来不会放弃的勇气\'\'\'，从来不会放弃的智慧。')

# name="John Doe"
# age= 30
# message1= "Hello %s, you are %d years old."%(name, age)
# message2 = f"Hello {name}, you are {age} years old."
# message3 = "Hello {}, you are {} years old.".format(name, age)
# message4= "Hello {0}, you are {1} years old. {0} is a {2}.".format(name, age, "teacher")
# message5= "Hello {name}, you are {age} years old.".format(name=name, age=age)
# print(message1)
# print(message2)
# print(message3)
# print(message4)
# print(message5)

# from string import Template
# template=Template("Hello $name, you are $age years old.")
# print(template.substitute(name=name, age=age));


# Using f-strings for string formatting
# name="john"
# age =20
# print(f"Hello {name}, you are {age} years old.")
# print("Hello %s, you are %d years old."%(name, age))
# print("Hello {}, you are {} years old.".format(name, age))
# print("Hello {0}, you are {1} years old.".format(name, age))
# print("Hello {name}, you are {age} years old.".format(name=name, age=age))

# from string import Template
# template = Template("Hello $name, you are $age years old.")
# print(template.substitute(name=name, age=age))
str ="you need to learn python,you will be a great programmer";
print(str[0]) # y
print(str[-1]) # r
print(str[0:5]) # you n
print(str[4:9]) # need
print(str[12:]) # learn python,you will be a great programmer
print(str[-51:-10]) # need to learn python,you will be a great
print(str[::2]) # yune olanpto,o ilb  ra rgamr
print(str[::-1]) #remmargorp taerg a eb lliw uoy,nohtyp nrael ot deen uoy



# print(str.find("python"))#查找子串的位置，如果不存在则返回-1
# print(str.index("python"))#查找子串的位置，如果不存在则报错
# print(str.count("python"))#统计子串出现的次数
# print(str.startswith("you"))#判断字符串是否以指定子串开头
# print(str.endswith("programmer"))#判断字符串是否以指定子串结尾
# print(str.split())#以空格为分隔符将字符串分割为列表
# print(str.split("python"))#以指定子串为分隔符将字符串分割为列表
# print(str.replace("python", "Java"))
# print(str.__sizeof__())#这是获取字符串的字节数
# print(str.islower())#判断字符串是否全部为小写字母
# print(str.isupper())#判断字符串是否全部为大写字母
# print(str.istitle())# 判断字符串是否为标题格式（每个单词的首字母大写）
# print(str.isalpha()) # 判断字符串是否只包含字母
# print(str.isdigit()) # 判断字符串是否只包含数字
# print(str.isalnum()) # 判断字符串是否只包含字母和数字