# year=2024
# if year%4 and year%100 or year%400:
#     print("Leap year")
# else:
#     print("Not a leap year")


# try:
#     # 计算0到9的平方，存储在一个列表中
#     temp = [i ** 4 for i in range(10)]

#     start =int(input("请输入开始数字："))
#     end=int(input("请输入结束数字："))
#     if start>end or start<1000 or end>9999:
#         raise ValueError("输入的数字不合法")
#     # 遍历100到9999的整数
#     for i in range(start, end+1):
#         sum_of_squares = 0
#         j = i

#         # 计算每个数字的平方和
#         while j > 0:
#             digit = j % 10
#             sum_of_squares += temp[digit]
#             j //= 10

#         # 检查平方和是否等于原数字
#         if sum_of_squares == i:
#             print(i)

# except Exception as e:
#     print(f"发生错误: {e}")


# try:
#     socre=int(input("请输入成绩："))
#     if(socre<0 or socre>100):
#         raise ValueError("输入的成绩不合法")
#     if(socre>=90):
#         print("奖励100元!")
#     elif(socre>=80):
#         print("奖励50元!")
#     elif(socre>=60):
#         print("奖励30元!")
#     else:
#         print("不奖励!")
# except Exception as e:
#     print(f"输入错误：{e}")


# def is_ticket(age,has_tiket):
#     if age<18 or age>60:
#         print("年龄不符合")
#         return False
#     print("年龄符合")
#     if has_tiket==True :
#         print("有票,允许进入")
#         return True
#     print("没有票,禁止进入")
#     return False
# is_ticket(20,True)


class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.prev: Node | None = None
        self.next: Node | None = None

class Doublelist:
    def __init__(self):  # 初始化双向链表
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
        self.head.next = self.tail 
        self.tail.prev = self.head 
        self._length = 0  # 用于存储链表长度

    def addFirst(self, x):  # 添加节点到头部
        x.next = self.head.next
        x.prev = self.head
        if self.head.next:
            self.head.next.prev = x 
        self.head.next = x
        self._length += 1  # 更新链表长度

    def addLast(self,x):
        x.next=self.tail
        x.prev=self.tail.prev
        if self.tail.prev:
            self.tail.prev.next=x
        self.tail.prev=x
        self._length+=1  # 更新链表长度

    def remove(self, x):  # 删除节点x
        if not x or not x.prev or not x.next:
            raise ValueError("节点无效或节点不在链表中")
        x.prev.next = x.next
        x.next.prev = x.prev
        self._length -= 1  # 更新链表长度

    def removeLast(self):  # 删除最后一个节点
        if self.tail.prev == self.head:
            return None
        last = self.tail.prev
        self.remove(last)
        return last.val if last else None  # 检查 last 是否为 None，避免后续访问其属性时报错

    def size(self):  # 返回链表长度
        return self._length

    def _iter(self):  # 迭代器
        cur = self.head.next
        while cur != self.tail:
            if cur:
                yield cur
                cur = cur.next 