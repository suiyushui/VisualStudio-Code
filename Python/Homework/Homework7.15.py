# def recursive_sum(n):
#     if n<=0:
#         return 0
#     return n+recursive_sum(n-1)
# print(recursive_sum(5))

# def reverse_string(s,i):
#     if i>=len(s):
#         return ""
#     return reverse_string(s,i+1)+s[i]
# print(reverse_string("hello",0))

# def fibonacci(n):
#     if n<=1:
#         return n
#     return fibonacci(n-1)+fibonacci(n-2)
# print(fibonacci(5))


# print((lambda x=3:x**2)())


import threading
class SingletonMeta(type):
    _instances = {} 
    _lock = threading.RLock() #允许同一个线程多次获取锁

    def __call__(cls, *a, **kw):
        print("_instances before:", cls._instances)
        with cls._lock:
            if cls not in cls._instances:
                cls._instances[cls] = super().__call__(*a, **kw)
        print("_instances after :", cls._instances)
        return cls._instances[cls]

class Foo(metaclass=SingletonMeta):
    pass

t1 = threading.Thread(target=Foo)
t2 = threading.Thread(target=Foo)
t1.start(); t2.start()
t1.join();  t2.join()