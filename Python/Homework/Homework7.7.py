# num=int(input("输入一个整数："))
# if num>0:
#     print("大于零")
# elif num<0:
#     print("小于零")
# else:
#     print("等于零")
# num=int(input("输入一个整数："))
# if num&1:
#     print("奇数")
# else:
#     print("偶数")

# num1=int(input("输入第一个整数："))
# num2=int(input("输入第二个整数："))
# num3=int(input("输入第三个整数："))
# if num1<num2:
#     if num2<num3:
#         print(num1,num2,num3)
#     else:
#         if num1<num3:
#             print(num1,num3,num2)
#         else:
#             print(num3,num1,num2)
# else:
#     if num1<num3:
#         print(num2,num1,num3)
#     else:
#         if num2<num3:
#             print(num2,num3,num1)
#         else:
#             print(num3,num2,num1)

# year=int(input("输入年份："))
# if year%4 and year%100 or year%400:
#     print(year,"不是闰年")
# else:
#     print(year,"是闰年")


# height=int(input("输入身高："))
# weight=int(input("输入体重："))
# if abs((height-108)*2-weight)<10 :
#     print("体重合适")
# else:
#     print("体重不合适")
# try:
#     score = int(input("输入考试成绩："))
#     if score<0 or score>100:
#         raise ValueError("输入错误，请输入0-100的整数")
#     if 90 <= score <= 100:
#         print("考试成绩为：优秀")
#     elif 80 <= score < 90:
#         print("考试成绩为：优良")
#     elif 70 <= score < 80:
#         print("考试成绩为：良好")
#     elif 60 <= score < 70:
#         print("考试成绩为：及格")
#     else:
#         print("考试成绩为：不及格")
# except Exception as e:
#     print(f"{e}")

# import math
# a=int(input("输入第一个整数："))
# b=int(input("输入第二个整数："))
# c=int(input("输入第三个整数："))
# try:
#     if a<0 or b<0 or c<0:
#         raise ValueError("输入错误，请输入非负整数")
#     sum_abc = a + b + c
#     max_side = max(a, b, c)
#     if max_side*2>sum_abc:
#         raise ValueError("输入的三个整数不构成三角形")
#     print("能构成三角形")
#     s=sum_abc/2
#     area=math.sqrt(s*(s-a)*(s-b)*(s-c))
#     print(f"三角形的面积为{area}")
#     if a==b==c:
#         print("三角形的类型为等边三角形")
#     elif (a==b or b==c or a==c):
#         if (a**2+b**2==c**2 or b**2+c**2==a**2 or a**2+c**2==b**2):
#             print("三角形的类型为等腰直角三角形")
#         else :
#             print("三角形的类型为等腰三角形")
#     elif a**2+b**2==c**2 or b**2+c**2==a**2 or a**2+c**2==b**2:
#         print("能构成直角三角形")
#     else:
#         print("能构成普通三角形")
# except Exception as e:
#     print(f"{e}")


# name=input("请输入姓名：")
# password=int(input("请输入密码："))
# if name=="青" and password==123:
#     print("欢迎你，青")
# else:
#     print("对不起，你不是青")


# monthdays_list=[31,29,31,30,31,30,31,31,30,31,30,31]
# year=int(input("请输入年份："))
# month=int(input("请输入月份："))
# day=int(input("请输入日期："))
# try:
#     if year<0 or month<1 or month>12 or day<1 or monthdays_list[month-1]>day:
#         raise ValueError("输入错误，请输入正确的年份、月份和日期")
#     if month==2 and not(year%4==0 and year%100!=0 or year%400==0) and day>28:
#         raise ValueError("输入错误，请输入正确的年份、月份和日期")
#     if not(year%4==0 and year%100!=0 or year%400==0):
#         monthdays_list[1]=28
#     days=sum(monthdays_list[:month-1])+day
#     print(f"{year}年{month}月{day}日是{days}天")
# except ValueError as e:
#     print(f"{e}")


month=int(input("请输入月份："))
s=['春','夏','秋','冬']
if month<0 or month>12:
    print("输入错误，请输入正确的月份")
else:
    print(f"{month}月份属于{s[(month-1)//3]}季节")