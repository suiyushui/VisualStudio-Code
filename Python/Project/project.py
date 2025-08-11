"""
 peoples=["李华","张三","王武"]
for people in peoples: 
    print(people,end=" ")
print()
for people in peoples: 
    if people == "张三": 
        people="Jane" 
    print(people,end=" ")
print()
peoples.append("dave")
peoples.append("jane")
peoples.append("tom")
print(peoples)
peoples.insert(0,"jack")
peoples.insert(len(peoples)//2,"jerry")
peoples.append("lisa")
print(peoples)
peoples.remove("jane") #删除第一个jane
del peoples[0] #删除第一个元素
print(peoples)
#只保留两个元素
peoples = peoples[:2]
print(peoples)
#倒序
peoples = peoples[::-1]
print(peoples)

print("张三" in peoples)
print("jack" not in peoples)

print(id(peoples[1]));
print(10*11,10-11,10+11,10/11,10//11,10%11,10**11) """

# s="hello world, how are you?"
# print(s.split())
# print(s.upper())
# print(s.lower())
# print(s.replace("o","O"))
# print(s.count("o"))
# print(s.find("o",5,10))
# print(s.startswith("hello"))


# class MyClass:
#     species="Canis lupus familiaris"
#     def __init__(self,name,age):
#         self.name=name
#         self.age=age
#         print(f"对象{self.name}创建成功")
#     def print(self):
#         print(f"我是{self.name},我今年{self.age}岁,我是{self.species}种")
#         print(MyClass.spec)

#     def __enter__(self):
#         self.name="进入with语句"
#         return self
#     def add(self,a,b):
#         result=a+b
#         return result
#     def __del__(self):
#         print(f"对象{self.name}被销毁")
# obj=MyClass("测试对象",18)
# print(obj.add(20,30))
# del obj


# import sys
# import random

# def main():
#     num = random.randint(1, 100)
#     left, right = 1, 100

#     while True:
#         response = input(f'请在{left}-{right}之间输入一个数字（输入exit退出）：')
#         if response.lower() == 'exit':
#             sys.exit()
        
#         try:
#             response = int(response)
#         except ValueError:
#             print('输入错误，请输入一个有效的数字或exit退出！')
#             continue

#         if response < left or response > right:
#             print('输入错误，请重新输入！')
#             continue

#         if response < num:
#             left = response + 1
#         elif response > num:
#             right = response - 1
#         else:
#             print(f'恭喜你猜对了，答案是{num}！')
#             break

# if __name__ == "__main__":
#     main()


# import sys
# import random

# print('ROCK,  PAPER,  SCISSORS') 

# # These variables keep track of the number of wins, losses, and ties.
# wins = 0
# losses  =  0
# ties = 0

# while  True:  #  The  main  game  loop. 
#     print('%s  Wins,  %s  Losses,  %s  Ties'  %  (wins,  losses,  ties)) 
#     while True: # The  player input loop. 
#         print('Enter your move: (r)ock (p)aper (s)cissors or (q)uit')
#         playerMove = input()
#         if playerMove == 'q': 
#              sys.exit()  #  Quit  the  program. 
#         if playerMove == 'r' or playerMove == 'p' or playerMove == 's':
#              break  #  Break  out  of  the  player  input  loop. 
#         print('Type one of r, p, s, or q.') 

#     # Display what the player chose: 
#     if playerMove == 'r': 
#          print('ROCK versus...') 
#     elif playerMove == 'p': 
#          print('PAPER versus...') 
#     elif playerMove == 's': 
#          print('SCISSORS versus...') 

#     # Display what the computer chose:
#     randomNumber = random.randint(1, 3) 
#     if randomNumber == 1: 
#         computerMove = 'r' 
#         print('ROCK') 
#     elif randomNumber == 2:
#          computerMove = 'p'
#          print('PAPER') 
#     elif randomNumber == 3:
#          computerMove = 's'
#          print('SCISSORS') 

#     # Display and record the win/loss/tie: 
#     if playerMove == computerMove: 
#         print('It  is  a  tie!') 
#         ties = ties + 1
#     elif playerMove == 'r' and computerMove == 's':
#         print('You   win!') 
#         wins  =  wins  +  1
#     elif playerMove == 'p' and computerMove == 'r':
#         print('You   win!') 
#         wins  =  wins  +  1
#     elif playerMove == 's' and computerMove == 'p':
#         print('You   win!') 
#         wins  =  wins  +  1
#     elif playerMove == 'r' and computerMove == 'p':
#         print('You  lose!') 
#         losses  =  losses  +  1
#     elif playerMove == 'p' and computerMove == 's':
#         print('You  lose!')
#         losses  =  losses  +  1
#     elif playerMove == 's' and computerMove == 'r':
#         print('You lose!') 
#         losses  =  losses  +  1

# def spam():
#     global eggs
#     eggs = 'spam' # this is the global
# def bacon():
#     eggs = 'bacon' # this is a local
# def ham():
#     print(eggs , ' ham') # this is the global

# eggs = 42 # this is the global
# bacon()
# print(eggs,' 2') # prints 'bacon'
# spam()
# print(eggs,' 1') # prints 'spam'
# ham() # prints 'bacon'  
# print(eggs,' 3') # prints 'bacon'

# arr=[i for i in range(1,101) if i%2==0]
# total=sum(arr)
# print(arr)
# print(total)

# print(sum(i for i in range(1,101) if i%2==0))


# from queue import Queue 
# import threading 
# import time
# import random

# def producer(q):
#     for i in range(10):
#         time.sleep(random.random())
#         q.put(i)
#         print(f"Produced {i}")
# def consumer(q):
#     for item in iter(q.get, None):
#         time.sleep(random.random())
#         print(f"Consumed {item}")




# import gc
# from typing import Optional

# class Node:
#     def __init__(self, name):
#         self.name = name
#         self.next: Optional[Node] = None
    
#     # 用于跟踪对象是否被回收
#     def __del__(self):
#         print(f"Node {self.name} 被回收了")

# # 关闭自动垃圾回收（便于观察）
# gc.disable()

# # 创建循环引用
# a = Node("A")
# b = Node("B")
# a.next = b
# b.next = a

# # 断开外部引用
# a = None
# b = None


# from __future__ import annotations
# from typing import Optional, Any

# class Node:
#     def __init__(self, data: Any):
#         self.data: Any = data
#         self.next: Optional[Node] = None
    
#     def __repr__(self) -> str:
#         return f"Node(data={self.data})"

# class LinkedList:
#     def __init__(self):
#         self.head: Optional[Node] = None

#     def append(self, data: Any) -> None:
#         new_node = Node(data)
#         if not self.head:
#             self.head = new_node
#             return
#         last_node = self.head
#         while last_node.next:
#             last_node = last_node.next
#         last_node.next = new_node
    
#     def prepend(self, data: Any) -> None:
#         new_node = Node(data)
#         new_node.next = self.head
#         self.head = new_node

#     def insert_node(self, prev_node: Node, data: Any) -> None:
#         # 检查prev_node是否在链表中
#         current = self.head
#         while current:
#             if current is prev_node:
#                 new_node = Node(data)
#                 new_node.next = current.next
#                 current.next = new_node
#                 return
#             current = current.next
        
#         print("Previous node is not in the list")

#     def delete_node(self, key: Any) -> None:
#         if not self.head:
#             return
            
#         # 处理头节点就是要删除的节点的情况
#         if self.head.data == key:
#             self.head = self.head.next
#             return
        
#         prev_node: Optional[Node] = None
#         curr_node = self.head
#         while curr_node:
#             if curr_node.data == key:
#                 # 此时prev_node一定不为None，因为头节点已经被单独处理
#                 assert prev_node is not None
#                 prev_node.next = curr_node.next
#                 return
#             prev_node = curr_node
#             curr_node = curr_node.next

#     def print_list(self) -> None:
#         curr_node = self.head
#         while curr_node:
#             print(curr_node.data, end=" ")
#             curr_node = curr_node.next
#         print()
    
#     def __repr__(self) -> str:
#         nodes = []
#         current = self.head
#         while current:
#             nodes.append(repr(current))
#             current = current.next
#         return " -> ".join(nodes)

# if __name__ == "__main__":
#     ll = LinkedList()
#     ll.append(1)
#     ll.append(2)
#     ll.append(3)
#     ll.prepend(0)
#     print("插入前的链表:", ll)  # 使用__repr__打印
#     ll.insert_node(ll.head.next, 4) 
#     print("插入后的链表:", ll)
#     ll.delete_node(2)
#     print("删除后的链表:", ll)
#     print("遍历打印:")
#     ll.print_list()


# import time

# def add_logger_bad(func):
#     print("--- start ---")
#     t0 = time.time()
#     result = func()          # ❗ 这里立即执行，且参数写死
#     print(f"耗时 {time.time()-t0:.4f}s")
#     print("---  end  ---")
#     return result

# # 只能装饰无参函数
# def demo():
#     time.sleep(0.2)
#     return 42

# logged = add_logger_bad(demo)   # 定义时就跑完
# print("返回值:", logged)


# import time
# from functools import wraps

# def add_logger(func):
#     @wraps(func)                   # 保留原函数元信息
#     def wrapper(*args, **kwargs):  # 真正调用时才执行
#         print("--- start ---")
#         t0 = time.time()
#         result = func(*args, **kwargs)  # 支持任意参数
#         print(f"耗时 {time.time()-t0:.4f}s")
#         print("---  end  ---")
#         return result
#     return wrapper

# @add_logger
# def add(x, y):
#     time.sleep(0.1)
#     return x + y

# print(add(3, 4))   # 真正调用时才跑日志

import time
from functools import wraps

def add_logger(func):
    @wraps(func) # 保留原函数元信息
    def wrapper(*args,**kwargs):
        print("--- start ---")
        t0 = time.time()
        result=func(*args,**kwargs) # 支持任意参数
        print(f"耗时 {time.time()-t0:.4f}s")
        print("---  end  ---")
        return result
    return wrapper

@add_logger
def add(x,y):
    time.sleep(0.1)
    return x+y

print(add(3,4)) # 真正调用时才跑日志    
