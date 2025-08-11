# list =[]
# list.append('apple')
# list.append('banana')#添加元素
# print(list)
# list.insert(1, 'orange')#插入元素
# print(list)
# list.remove('banana')#删除指定元素
# print(list)
# list.pop(1)#删除指定位置元素
# print(list)
# list.extend(['grape', 'pear','mango'])#添加多个元素
# print(list)
# list.reverse()#反转列表
# print(list)
# list.sort(  reverse=False)#排序列表
# print(list)
# del list[0]#删除列表第一个元素
# print(list)
# list.clear()#清空列表
# print(list)




# list01=list()
# print(list01,type(list01))
# list02=list("hello world")
# print(list02,type(list02))
# tuple01=("apple","banana","orange")
# list03=list(tuple01)
# print(list03,type(list03))
# list04={"a":1,"b":2,"c":3}
# print(list04,type(list04))
# list05=range(10)
# print(list05,type(list05))
# list06=[1,2,3,4,5,6,7,8,9,10]
# print(list06,type(list06))
# list07=["hello",1,2,3,4,5,6,7,8,9,10]
# print(list07,type(list07))
# list08=[["apple"]+[1,2,3]]
# print(list08,type(list08))


# list01=[1,2,3,4,5,6,7,8,9,10]
# del list01[0]
# print(list01)
# print(list01[::-1])
# print(list01[1:5:2])
# print([x for x in list01 if x%2==0])
# print(list01[-1])
# print(list01.index(5))

# list01=[1,2,3,4,5,6,7,8,9,10]
# index=0
# while index<len(list01):
#     print(list01[index],end=' ')
#     index+=1
# print()
# for x in list01:
#     print(x,end=' ')
# print()
# for i in range(len(list01)):
#     print(f"{i}: {list01[i]}",end=' ')
# print()
# for index,value in enumerate(list01):
#     print(f"{index}: {value}",end=' ')
# print()

# list01=[1,2,3]
# list02=[4,5,6]
# list03=list01+list02
# print(list03)
# list01.extend(list02)
# print(list01,id(list01))
# list01.append(list02)
# print(list01,id(list01))
# list01.insert(0,8)
# print(list01,id(list01))


# list01=[1,2,3]
# print(list01,id(list01))
# list01.insert(3,4)
# print(list01,id(list01))
# list02=list01*4
# print(list02,id(list02))
# list01.append({"a":1,"b":2})
# print(list01,id(list01))
# list01.extend({"c":3,"d":4})
# print(list01,id(list01))



#链表支持顺寻查找和逆寻查找，时间复杂度O(n)
#链表支持动态扩容，时间复杂度O(1)
#链表支持删除指定元素，时间复杂度O(n)
# .append()表示在链表尾部添加1
# .insert()表示在指定位置插入1
# .extend()表示在链表尾部添加多个元素
# .remove()表示删除指定元素
# .pop()表示删除指定位置元素
# .reverse()表示反转链表


