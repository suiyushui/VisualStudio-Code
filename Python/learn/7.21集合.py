# set1={} # 这是一个空字典
# set2=set() # 这是一个空集合
# print(type(set1),type(set2))
# set1={1,2,3,4,5} # 这是一个集合
# set2=set([1,2,3,4,5]) # 这也是一个集合
# print(set1,set2)
# set1.add(6) # 向集合中添加元素
# set2.update([7,8,9]) # 向集合中添加多个元素
# print(set1,set2)
# set1.remove(2) # 从集合中删除元素
# set2.discard(4) # 从集合中删除元素，如果元素不存在，不会报错
# print(set1,set2)
# set1.pop() # 从集合中随机删除一个元素
# set2.clear() # 清空集合
# print(set1,set2)


# set4=set1.union(set2) # 集合的并集
# set5=set1.intersection(set2) # 集合的交集
# set6=set1.difference(set2) # 集合的差集
# set7=set1.symmetric_difference(set2) # 集合的对称差集
# print(set4,set5,set6,set7)

# # set8=set({'a':1,'b':2,'c':3})
# # print(set8)


# set1.update([2,3,4,5])
# set2.update([3,4,5,6,7])
# print(set1,set2)

# set1.update(set2)
# set1.remove(5)
# # set1.discard(0)
# print(set1)
# set1.pop() # 随机删除一个元素
# print(set1)

# set1=frozenset({1,2,3,4,50})
# print(set1)


# set1={1,2,3,4,5}
# set2={3,4,5,6,7}
# print(set1|set2) # 集合的并集
# print(set1&set2) # 集合的交集
# print(set1-set2) # 集合的差集
# print(set1^set2) # 集合的对称差集
# print(set1<=set1) # 集合的子集关系
# print(set1>=set2) # 集合的超集关系
# print(set1<set2) # 集合的真子集关系


print(all({})) #True
print(any({})) #False
print(sorted({1,2,3,4,5},reverse=True))
set1,set2={1,2,3,4,5},{3,4,5,6,7}
print(set1|set2) #{1,2,3,4,5,6,7}
print(set1&set2) #{3,,4,5}
print(set1-set2) #{1,2}
print(set1^set2) #{1,2,6,7}

 
 