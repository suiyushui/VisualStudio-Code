# total=10
# def sum_total(*args):
#     global total
#     for num in args:
#         total+=num
# sum_total(1,2,3,4,5)
# print(total)     # 25

# def sum_total(total):
#     def inner(*args):
#         nonlocal total
#         for arg in args:
#             total+=arg
#         return total
#     return inner
# print(sum_total(0)(1,2,3,4,5))   # 15

# def create_counter(start=0):
#     num=start

#     def counter():
#         nonlocal num
#         temp=num
#         num+=1
#         return temp

#     def reset():
#         nonlocal num
#         num=start

#     counter.reset=reset # 给counter添加reset方法   
#     return counter

# c=create_counter(10)
# print(c())   # 11
# print(c())   # 12
# c.reset()
# print(c())   # 10


# def create_cached_function(func):
#     cache={}  

#     def cache_func(*args):
#         nonlocal cache
#         key=tuple(args)
#         if key in cache:  
#             print('cache hit')
#             return cache[key]
#         else:
#             print('cache miss')
#             result=func(*args)
#             cache[key]=result
#             return result

#     return cache_func

# @create_cached_function
# def fib(a,b):
#     return a+b

# print(fib(1,2))   # cache miss 3
# print(fib(1,2))   # cache hit 3


# import re

# text = 'foofoo'

# # 1) 捕获分组：第 1 组就是 foo
# m1 = re.search(r'(foo)\1', text) # 
# print(m1.group(0))   # foofoo
# print(m1.group(1))   # foo   ← 能拿到捕获内容


# functools.wraps 装饰器
# 作用：保留被装饰函数的元信息，比如函数名、文档字符串等，这样在使用装饰器时，就能知道被装饰函数的名字、文档等信息。
from functools import wraps 

user_level=6

def require_level(level):
    def decorator(func):
        @wraps(func)
        def wrapper(*args, **kwargs):
            if user_level>=level:
                return func(*args, **kwargs)
            else:
                print('You do not have permission to access this function.')
        return wrapper
    return decorator

@require_level(5)
def my_func():
    """This is my function."""
    print('Hello, world!')

print(my_func.__name__)   # my_func
print(my_func.__doc__)    # This is my function.