# tup1=('physics', 'chemistry', 1997, 2000)
# print(tup1)
# print(type(tup1))
# tup2=()
# tup3=(5,)
# print(type(tup3))

# tup = ('Google', 'sina', 'Taobao', 'Wiki', 'Weibo','Weixin')
# print(tup[0],tup[-1])
# print(tup[(len(tup)//2-1):(len(tup)//2+1)])
# tup[0]='baidu'
# print(tup)
# del tup[0]
# del tup

# print(len((1, 2, 3)))
# print((1, 2, 3) + (4, 5, 6))
# print(('Hi!',) * 4)
# print(3 in (1, 2, 3))
# for x in (1, 2, 3): print (x,)

# tuple1=(1,2,3,4,5)
# print(len(tuple1))
# print(max(tuple1))
# print(min(tuple1))
# print(tuple("hello world"))
# for index,value in enumerate(tuple1):
#     print(index,value)

tup=(1,2,3,4,5,2,3,4,5,3,4,5)
print(tup.count(2))
print(tup.index(4))