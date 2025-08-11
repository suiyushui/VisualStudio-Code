import math

class Vector:
    def __init__(self,x=0,y=0):
        self.x=x
        self.y=y
    def __repr__(self): # 打印对象
        return f'Vector({self.x!r}, {self.y!r})'
    def __abs__(self): # 向量的模
        return  math.hypot(self.x,self.y)
    def __bool__(self): # 判断是否为零向量
        return bool(abs(self))
    def __add__(self,other): # 向量加法
        x=self.x+other.x
        y=self.y+other.y
        return Vector(x,y)
    def __mul__(self,scalar): # 向量乘法
        return Vector(self.x*scalar,self.y*scalar)

v1=Vector(2,3)
v2=Vector(4,5)
print(v1+v2)
print(v1*2)
print(abs(v1))

num="Hello\nWorld"
print(str(num))
print(repr(num))
    