# print( len(dir(42))) #dir()函数可以查看一个对象的所有属性和方法
# for i in dir(42):
#     print(i)

# f=abs
# print(f.__name__)
# print(f(-3))
# # 
# class Person:
#     def __init__(self,name:str,age:int) -> None:
#         self.name=name
#         self.age=age
    
#     def __call__(self,friend)->None:
#         print('My name is %s...' % self.name)
#         print(f"My friend is {friend}!")

# p=Person('Alice',25)
# p('Bob')


#桌子，四条腿，黑色桌腿，棕色桌面，500元。
# class Table:
#     legs= 4
#     color='black'
#     wood='wood'
#     price= 500
#     def __init__(self,legs:int=4,color:str='black',wood:str='wood',price:int=500) -> None:
#         self.legs=legs
#         self.color=color
#         self.wood=wood
#         self.price=price

#     def __str__(self) -> str:
#         return f"This is a {self.color} {self.wood} table with {self.legs} legs, and it costs {self.price} yuan."

#     def __call__(self,name:str)->None:
#         print(f"Hello, {name}!")

# t=Table()
# print(t)
# print(t.legs)
# print(t.color)
# print(t.wood)
# t=Table(5,'red','black',200)
# print(t)
# t('Alice')
# print(t.legs)
# print(t.color)



# class Dogs:
#     def __init__(self,name:str='旺财',age:int=2,breed:str='泰迪',gender:str='公',color:str='黑色') -> None:
#         self.name=name
#         self.age=age
#         self.breed=breed
#         self.gender=gender
#         self.color=color
#     def __str__(self) -> str:
#         return f"这是一个{self.gender}的{self.color}的{self.breed}，名字叫{self.name}，{self.age}岁了。"
#     def eat(self)->None:
#         print(f"{self.name}正在吃东西...")
    
#     def play(self)->None:
#         print(f"{self.name}正在玩耍...")

# dog1=Dogs()
# print(dog1)
# dog1.eat()
# dog1.play()

# dog2=Dogs('小白',3,'拉布拉多','母','白色')
# print(dog2)
# dog2.eat()
# dog2.play()

# print(dog1.__dict__)





# class Cats:
#     def __init__(self,name: str,age: int,gender: str,color: str) -> None:
#         self.name=name
#         self.age=age
#         self.gender=gender
#         self.color=color
#     def showInfo(self)->None:
#         print(f"这是一个{self.gender}的{self.color}猫，名字叫{self.name}，{self.age}岁了。")


# cat1=Cats('Tom',8,'公','蓝色')
# cat1.showInfo()


# # 方法1：使用 dir() 查看内置模块的成员
# import builtins
# print(dir(builtins))  # 输出所有内置元素的名称列表

# # 方法2：查看特定元素的文档（例如查看 print 函数的说明）
# help(print)


# class Student:
#     def __init__(self):
#         self.name = 'Alice'
#     def __str__(self) -> str:
#         return f"This is a student named {self.name}."
#     def __eq__(self,other):
#         return self.name == other.name

# s = Student()
# print(s)

# class BankAccount:
#     def __init__(self, owner) -> None:
#         self.owner = owner
#         self.__balance = 0

#     def deposit(self, amount):
#         self.__balance += amount

# # 创建 BankAccount 实例
# acc = BankAccount('Alice')

# # 直接访问私有变量 _BankAccount__balance 以防止子类意外覆盖
# print(acc._BankAccount__balance)

# # 调用 deposit 方法
# acc.deposit(1000)

# # 再次访问私有变量 _BankAccount__balance
# print(acc._BankAccount__balance)


# def averager(*nums):
#     return sum(nums) / len(nums)

# print(averager(1, 2, 3))  # 2.0


# class Person:
#     def __init__(self,name:str,age:int)->None:
#         self.name=name
#         self.age=age
#     def get_age(self)->int:
#         return self.age
#     def set_age(self,age:int)->None:
#         if not isinstance(age,int):
#             raise TypeError("Age should be an integer.")
#         if age<0 or age>120:
#             raise ValueError("Age should be between 0 and 120.")
#         self.age=age
# if __name__=="__main__":
#     p=Person("Alice",25)
#     print(p.get_age())
#     try:
#         p.set_age(123)
#     except ValueError as e:
#         print(e)
#     print(p.get_age())


# nums = [1, 2, 3, 4, 5]

# try:
#     # 尝试引发 IndexError
#     ans = nums[10]
# except IndexError as e:
#     print(f"索引异常 {e}")
# finally:
#     print("This code will always be executed.")

# try:
#     # 尝试引发 ZeroDivisionError
#     ans = nums[0] / 0
# except ZeroDivisionError as e:
#     print(f"除零异常 {e}")
# except Exception as e:
#     print(f"其他异常 {e}")
# else:
#     print(ans)
# finally:
#     print("This code will always be executed.")


import threading
import time
import logging
from unittest import result
logging.basicConfig(level=logging.INFO, format='%(message)s')
def on_complete9(task_name,result):
    logging.info(f"任务[{task_name}]完成,结果:{result}")

def async_task(task_name,duration,callback):
    def _task():
        logging.info(f"开始执行任务[{task_name}]...")
        time.sleep(duration)
        result=duration*2
        callback(task_name,result)
    threading.Thread(target=_task).start()

async_task("task1",2,on_complete9)
async_task("task2",3,on_complete9)

logging.info("主线程结束...")
