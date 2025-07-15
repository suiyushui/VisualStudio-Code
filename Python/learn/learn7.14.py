# def sum_of_numbers(start,end):
#     if(start>end):
#         print("Invalid Input")
#         return
#     print(sum(range(start,end)))
# sum_of_numbers(1,101)

# def is_leap_yrear(year):
#     if year%4==0 and year%100!=0 or year%400==0:
#         return True
#     return False
# year=int(input("输入年份:"))
# result=is_leap_yrear(year)
# print(result)



# def showInfo(name,age=8,gender="男"):
#     print(f"姓名:{name},年龄:{age},性别:{gender}")
# showInfo("张三",20,"男")
# showInfo(name="李四",age=25,gender="女")
# print("--------------------------------")

# def hobbys(name,*hobby):
#     print(f"姓名:{name},爱好=" ,end="")
#     for i in hobby:
#         print(f"{i}",end=" ")
# hobbys("李四","篮球","足球","乒乓球")
# print()

# def showInfo2(**info):
#     '''
#     info参数是一个字典，可以传入任意数量的键值对
#     '''
#     print(type(info))
#     print(f"姓名:{info['name']},年龄:{info['age']},性别:{info['gender']},爱好:{info['hobby']}")
# showInfo2(name="李四",age=25,gender="女",hobby="篮球")


def showInfo3(a:int,b:int,c:int):
    '''
        返回一个元组，包含3个数
        :param a: 1 
        :param b: 2 
        :param c: 3 
    '''
    return (a,b,c)
a,b,c=showInfo3(*[1,2,3])
print(a,b,c)
print(showInfo3.__doc__)


