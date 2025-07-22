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


# q=Queue()
# t1=threading.Thread(target=producer, args=(q,))
# t2=threading.Thread(target=consumer, args=(q,))
# t1.start()
# t2.start()
# t1.join()
# q.put(None) 
# t2.join()
# print("All done")


# from queue import Queue
# import threading, time

# q = Queue()
# print_lock=threading.Lock()

# def producer():
#     for i in range(5):
#         q.put(i)
#         with print_lock:
#             print(f'Produced {i}')
#         time.sleep(0.5)
#     q.put(None)          # 结束哨兵

# def consumer():
#     while True:
#         item = q.get()
#         if item is None: # 收到哨兵
#             break
#         with print_lock:
#             print(f'Consumed {item}')
#         q.task_done()    # 关键：通知队列任务完成
#     q.task_done()        # 对哨兵本身也 task_done

# t1 = threading.Thread(target=producer)
# t2 = threading.Thread(target=consumer)

# t1.start(); t2.start()
# t1.join()   # 等生产者放完
# q.join()    # 等消费者处理完
# t2.join()
# print('Alldone ')



#生产者-消费者模型
# from queue import Queue
# import threading, time, random,logging

# logging.basicConfig(level=logging.INFO,format='%(message)s')
# message_queue= Queue(maxsize=10)

# def producer(producer_id):
#     for i in range(4):
#         message=f"生产者{producer_id}的消息{i}"
#         message_queue.put(message)
#         logging.info(f"生产者{producer_id},发送消息{message}")
#         time.sleep(random.uniform(0.1,0.5))

# def consumer(consumer_id,producer_count):
#     while True:
#         message=message_queue.get()
#         if message is None:
#             producer_count -= 1
#             message_queue.task_done()
#             if not producer_count:  
#                 break
#             continue

#         logging.info(f"消费者{consumer_id},接收消息{message}")
#         message_queue.task_done()
#         time.sleep(random.uniform(0.2,0.6))

# if __name__=='__main__':
#     producer_count = 2

#     Producers=[
#         threading.Thread(target=producer,args=(1,)),
#         threading.Thread(target=producer,args=(2,))
#     ]
#     Consumers=[
#         threading.Thread(target=consumer,args=(1,producer_count)),
#         threading.Thread(target=consumer,args=(2,producer_count)),
#         threading.Thread(target=consumer,args=(3,producer_count))
#     ]

#     for p in Producers: 
#         p.start()
#     for c in Consumers:
#         c.daemon = True  # 主线程结束，子线程结束
#         c.start()
#     for p in Producers:
#         p.join()
#     message_queue.join()

#     # 放入与生产者数量相同的结束信号
#     for _ in range(producer_count):
#         message_queue.put(None)
    
#     # 等待队列中的所有任务完成（包括结束信号）
#     message_queue.join()
#     logging.info("所有消息都已消费完毕")
    


import random
import threading
import time
from typing import Any, Dict, Type, TypeVar, Optional, final

T = TypeVar('T', bound='Singleton')

@final
class Singleton:
    """
    线程安全的单例基类，使用双重检查锁定模式实现
    支持继承和多线程环境
    """
    
    _instances: Dict[Type['Singleton'], 'Singleton'] = {}  # 存储所有单例类的实例
    _lock: threading.RLock = threading.RLock()  # 可重入锁，确保线程安全
    
    def __init__(self, *args: Any, **kwargs: Any) -> None:
        """
        初始化方法，模拟耗时操作
        """
        time.sleep(random.random() * 0.1)  # 模拟初始化耗时
        self._initialized = True  # 标记是否已初始化
        
    @classmethod
    def instance(cls: Type[T], *args: Any, **kwargs: Any) -> T:
        """
        获取单例实例的类方法
        使用双重检查锁定确保线程安全
        """
        # 第一重检查 - 无锁快速路径
        if cls not in cls._instances:
            with cls._lock:
                # 第二重检查 - 确保只有一个线程能创建实例
                if cls not in cls._instances:
                    # 使用object.__new__避免递归调用
                    instance = super(Singleton, cls).__new__(cls)
                    instance.__init__(*args, **kwargs)
                    cls._instances[cls] = instance
        return cls._instances[cls]  # type: ignore
    
    @classmethod
    def clear_instance(cls) -> None:
        """
        清除单例实例（主要用于测试）
        """
        with cls._lock:
            if cls in cls._instances:
                del cls._instances[cls]
    
    @classmethod 
    def get_instance_count(cls) -> int:
        """
        获取当前已创建的单例数量（用于测试）
        """
        return len(cls._instances)
    
    def __new__(cls: Type[T], *args: Any, **kwargs: Any) -> T:
        """
        重写__new__防止直接实例化
        """
        if cls._instances.get(cls) is None:
            raise RuntimeError(
                f"{cls.__name__} must be instantiated using the instance() class method"
            )
        return cls._instances[cls]

def task() -> None:
    """
    测试任务函数，多个线程会调用此函数获取单例
    """
    obj = Singleton.instance()
    if obj:
        print(f'{obj}\tSingleton count: {Singleton.get_instance_count()}')

if __name__ == '__main__':
    # 测试代码
    print("=== 单线程测试 ===")
    Singleton.clear_instance()  # 确保测试环境干净
    
    s1 = Singleton.instance()
    s2 = Singleton.instance()
    print(f"s1 is s2: {s1 is s2}")  # 应该输出 True
    print(f"Instance count: {Singleton.get_instance_count()}")  # 应该输出 1
    
    try:
        # 尝试直接实例化应该抛出异常
        s3 = Singleton()
    except RuntimeError as e:
        print(f"Expected error when direct instantiation: {e}")
    
    print("\n=== 多线程测试 ===")
    Singleton.clear_instance()  # 重置测试环境
    
    # 创建并启动多个线程测试单例
    threads = []
    for i in range(5):  # 创建5个线                                                                                                                                                                                                                                                                                                                                                                                                         
        t = threading.Thread(target=task)
        threads.append(t)
        t.start()
    
    # 等待所有线程完成
    for t in threads:
        t.join()
    
    print(f"\nFinal instance count: {Singleton.get_instance_count()}")  # 应该输出 1