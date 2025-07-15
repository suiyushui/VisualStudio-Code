# import threading 

# def worker(num):
#     print(f"Worker {num} started\n", end="")

# threads = []
# for i in range(5):
#     t=threading.Thread(target=worker,args=(i,))
#     t.start()

# for t in threads:
#     t.join()

# print("All threads are done")

# import threading

# class MyThread(threading.Thread):
#     def __init__(self, name):
#         super().__init__()
#         self.name = name

#     def run(self):
#         print(f"{self.name} is running")

# t = MyThread("Thread-1")
# t.start()
# t.join()
# print("All threads are done")


# import threading

# counter=0
# lock=threading.Lock() # 锁
# def increment():
#     global counter
#     for i in range(1000000):
#         with lock:
#             counter+=1
# threads=[threading.Thread(target=increment) for i in range(4)]
# [t.start() for t in threads]
# [t.join() for t in threads]
# print(counter)

# def outer():
#     num = 10
    
#     def inner():
#         # nonlocal num
#         # num = 20
#         print(num)  # 输出 20
        
#         # num = 30  # 修改外部函数的变量 num
#     inner() # 调用内部函数，修改了外部函数的变量 num
#     print(num)  # 输出 20

# outer()


# x=0
# def d1():
#     global x
#     # x=10
#     def d2():
#         #  nonlocal x
#          print(x)
#         #  x=20
#     # print(x)
#     # d2()
#     x=x+1
#     print(x)

# d1()    
# print(x)

#作用域解析规则
# L->E->G>B

# 三根柱子用列表表示，顶端在列表末尾
# A = list(range(3, 0, -1))  # [3,2,1]
# B, C = [], []

# def move(src, dst, name_src, name_dst):
#     """移动并打印当前状态"""
#     disk = src.pop()
#     dst.append(disk)
#     print(f"{name_src} -> {name_dst} : 移动盘子 {disk}")
#     print("A:", A, "B:", B, "C:", C, "\n")

# def hanoi(n, src, dst, aux, name_src, name_dst, name_aux):
#     if n == 1:
#         move(src, dst, name_src, name_dst)
#     else:
#         hanoi(n-1, src, aux, dst, name_src, name_aux, name_dst)
#         move(src, dst, name_src, name_dst)
#         hanoi(n-1, aux, dst, src, name_aux, name_dst, name_src)

# hanoi(3, A, C, B, 'A', 'C', 'B')


# def move(n,scr='A',aux='B',dst='C'):
#     if n==1:
#         print(f"{scr} -> {dst} : 移动盘子 {n}")
#     else:
#         move(n-1,scr,dst,aux)
#         print(f"{scr}->{dst} : 移动盘子 {n}")
#         move(n-1,aux,scr,dst)
# move(3)


print(sorted([3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5],key= lambda x:-x))