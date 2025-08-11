

# s='abc'
# print(s.__mul__(1))

# class Counter:
#      first=1
#      def __init__(self,start:int,end:int) -> None:
#           self.__current=start
#           self.end=end
#      def __iter__(self):
#           return self
#      def __next__(self):
#           if self.__current>self.end:
#                raise StopIteration
#           value=self.__current
#           self.__current+=1
#           return value
# for num in Counter(1,5):
#      print(num,end=' ')
# print()
# print(Counter.first)



# class Animal:
#     def __init__(self,name:str,age:int,gender:str) -> None:
#         self.name=name
#         self.age=age
#         self.gender=gender
#     def print_info(self) -> None:
#         print(f"name:{self.name},age:{self.age},gender:{self.gender}")
#     def eat(self) -> None:
#         print(f"{self.name}正在吃东西")

# class Dog(Animal):
#     def __init__(self,name:str,age:int,gender:str,color:str) -> None:
#         super().__init__(name,age,gender)
#         self.color=color
#     def print_info(self) -> None:
#         super().print_info()
#         print(f"color:{self.color}")

# dog1=Dog("小狗",2,"男","黑色")
# dog1.print_info()
# dog1.eat()


class UserAuth:
    def __init__(self,username:str,password:str)->None:
        self._username=username # 受保护的属性
        self.__password=(password) # 私有属性

    def __hash_password(self,password:str)->str:
        import hashlib
        return hashlib.sha256(password.encode('utf-8')).hexdigest()
    
    def verify_password(self,imput_password:str)->bool:
        hashed_input=self.__hash_password(imput_password)
        return hashed_input==self.__password
    @property
    def username(self):
        return self._username
    
class persom:
    0