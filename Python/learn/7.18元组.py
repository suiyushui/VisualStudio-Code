# tuple01=(1,2,3,4,5)
# print(tuple01)
# tuple02=tuple([1,2,3,4,5])
# print(tuple02)
# tuple03=tuple("hello")
# print(tuple03[-1])


# reault=2 in tuple01
# print(reault)
# try:
#     print(tuple01.index(6))
# except ValueError:
#     print("元素不存在")


class Node:
    def __init__(self, data:int)->None:
        self.data = data
        self.next = None
    def __repr__(self)->str:
        if self.next:
            return f"Node({self.data})->"
        return f"Node({self.data})"

a=Node(1)
b=Node(2)
c=Node(3)

a.next=b
b.next=c

node=a
while node:
    print(node)
    node=node.next

    