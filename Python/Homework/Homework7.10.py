# 求10以内的偶数的和
# print(sum([i for i in range(1,11)],0))

# def sieve(n):
#     flag=[True]*(n+1)
#     flag[0]=flag[1]=False
#     prem=[]
#     for i in range(2,n+1):
#         if flag[i]:
#             prem.append(i)
#         for pre in prem:
#             if i*pre>n:
#                 break
#             flag[i*pre]=False
#             if i%pre==0:
#                 break
#     return prem
# print(sieve(100))

# import random
# count=7
# goalNum=random.randint(1,101)
# while count>0:
#     num=int(input("请输入一个数字："))
#     if num<0 or num>100:
#         print("输入错误，请输入1-100之间的数字！")
#         count-=1
#     else:
#         if num==goalNum:
#             print("恭喜你猜对了！")
#             break
#         elif num>goalNum:
#             print("猜大了！")
#         else:
#             print("猜小了！")
#         count-=1
#     if count==0:
#         print("你已经用完了猜测次数，游戏结束！")

# nums=[i**3 for i in range(1,11)]
# for i in range(100,1000):
#     temp=i
#     sum_i=0
#     while temp>0:
#         sum_i+=nums[temp%10]
#         temp//=10
#     if sum_i==i:
#         print(i)

# print([chr(s) for s in range(ord('a'),ord('z'))]+[chr(s) for s in range(ord('Z'),ord('A'),-1)])

# print(sum([i for i in range(1,102,4)]+[-i for i in range(3,102,4)]))

# print(sum([1/i for i in range(1,101,2)]+[-1/i for i in range(2,101,2)]))

# nums=[i for i in range(20,81) if i%3==0]
# for i in range(len(nums)):
#     print(nums[i],end=' ')
#     if (i+1)%5==0:
#         print()

# years=[i for i in range(1000,2001) if i%4==0 and i%100!=0 or i%400==0]
# for i in range(len(years)):
#     print(years[i],end=' ')
#     if (i+1)%4==0:
#         print()

# for i in range(0,10):
#     if 0<=12-i<10:
#         print(f"a={i},b={12-i}")

# for a in range(0,10):
#     for b in range(0,10):
#         for d in range(0,10):
#             if (b+d)%10==a and 0<=d-a-(b+d)//10<10 :
#                 print(f"a={a},b={b},c={d-a-(b+d)//10},d={d}")

# import random
# N=int(input("买几注双色球:"))
# for i in range(N):
#     red=random.sample(range(1,34),6)
#     blue=random.sample(range(1,17),1)
#     print(f"第{i+1}注：红球{red}，蓝球{blue}")

# import random
# letter=([chr(i) for i in range(ord('a'),ord('z')+1)]+
#         [chr(i) for i in range(ord('A'),ord('Z')+1)])
# c=random.choice(letter)
# print(c,"yes" if c.isupper() else "no")

# a,b=0,1
# print(a,b,end=' ')
# for i in range(2,20):
#     a,b=b,a+b
#     print(b,end=' ')

# a=int(input("请输入第一个数："))
# b=int(input("请输入第二个数："))
# c,d=a,b
# while d!=0:
#     c,d=d,c%d
# print(f"最大公约数为{c}，最小公倍数为{a*b//c}")


# count = 0
# arr = [1, 5, 10]
# def dfs(n, index):
#     global count
#     if n == 100:
#         count += 1
#         return
#     elif n > 100:
#         return 
#     for i in range(index, len(arr)):
#         dfs(n + arr[i], i)
# dfs(0,0)
# print(f"凑到 100 元的组合数量为:{count}")


# count = 0
# for x in range(1,50):
#     for y in range(1,50):
#         z=50-x-y
#         if z>=1 and 10*x+5*y+z==100:
#             count+=1
# print(f"凑到 100 元的组合数量为:{count}")


num,temp=200,200
while temp>=3:
    num+=temp//3
    temp=temp//3+temp%3
print(num)