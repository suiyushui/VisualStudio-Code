# list01=[1,2,3,4,5,6,7,8,9]
# del list01[1] #删除索引为1的元素
# print(list01)
# del list01[3:6] #删除索引3到索引5的元素
# print(list01)
# del list01[:] #删除所有元素
# print(list01)

# list01 =[i for i in range(10)]
# print(list01)
# if 1 in list01:
#     list01.remove(1)
# print(list01)
# list01.pop(1)
# print(list01)

# list01[0]=1
# list01[1:1]=[2]
# print(list01)
# list01[6:]=[]
# print(list01)

# list01.clear()
# print(list01)

# list01=[0,3,2,1,4,5,6,7,8,9]
# print(list01.index(3))

# list01.sort(reverse=False)
# print(list01)

# list01.reverse()

list1=[1,2,3,4,5,6,7,8,9]
list2=list1[:]
list3=list1.copy()
list1[1]=10
list2[2]=20
list3[3]=30
print(list1)
print(list2)
print(list3)
