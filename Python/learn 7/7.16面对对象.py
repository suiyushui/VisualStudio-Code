class Employee:
    """员工类示例：统计总人数并保存姓名、年龄。"""
    _emp_count: int = 0  # 类变量，记录已创建的实例数量

    def __init__(self, name: str, age: int) -> None:
        self.name: str = name
        self.age: int = age
        Employee._emp_count += 1  # 每实例化一次，计数器 +1

    @classmethod # 用类名就能调用，第一参数是cls(类本身)
    def display_count(cls) -> None:
        """打印当前员工总数。"""
        print(f"Total Employee: {cls._emp_count}")

    @property
    def emp_count(self) -> int:
        """返回当前类实例的数量。"""
        return Employee._emp_count

    def display_employee(self) -> None:
        """打印当前员工的姓名和年龄。"""
        print(f"Name: {self.name}, Age: {self.age}")


# ---------------- 演示 ----------------
if __name__ == "__main__":
    alice = Employee("Alice", 30)
    bob   = Employee("Bob",   25)

    Employee.display_count()   # 类方法调用
    print(alice.emp_count) 
    alice.display_employee()   # 实例方法调用
    bob.display_employee()
    # print(hasattr(alice, 'age'))# 判断是否有属性
    # print(getattr(alice, 'age'))# 获取属性值
    # setattr(alice, 'age', 35)   # 设置属性值
    # delattr(alice, 'age')       # 删除属性值
    # print(alice.age)            # 打印属性值



class preson:
    _species="huaman"
    
    # 构造函数
    def __init__(self,name:str,age:int) -> None:
        self.name=name
        self.age=age

    @property
    def species(self)->str:
        return self._species
    #实例方法
    def great(self)->None:
        print(f"我的名字是{self.name},今年{self.age}岁了")
    
    def birthday(self)->str:
        self.age+=1
        return f'happpy birthday to me,i am {self.age} years old now'
if __name__ == "__main__":
    Alice=preson("Alice",25)
    Bob=preson("Bob",20)
    print(Alice._species)
    Alice.great()
    print(Bob.birthday())

class Student(preson):
    def __init__(self,name:str,age:int,school:str,grade:int) -> None:
        super().__init__(name,age)
        self.school=school
        self.grade=grade
    
    def study(self)->str:
        return f"I am studying in {self.school} and my grade is {self.grade}"
    
    def greet(self)->str:
        return f"Hello,my name is {self.name},I am a student in {self.school} and my grade is {self.grade}"
if __name__ == "__main__":
    Tom=Student("Tom",20,"Harvard",12)
    print(Tom.greet())
    print(Tom.study())
    
