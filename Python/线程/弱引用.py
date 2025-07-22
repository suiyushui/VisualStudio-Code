class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

# 创建循环引用
node1 = Node(1)
node2 = Node(2)
node1.next = node2
node2.next = node1

# 即使删除外部引用，循环引用导致内存泄漏
del node1, node2