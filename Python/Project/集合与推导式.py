# 用列表推导式生成 1~10 中所有偶数的平方组成的列表。
print([x**2 for x in range(1,11) if x&1==0])

# 将列表 ["apple", "Banana", "cherry", "Date"] 中所有字符串转为小写，并存入新列表（忽略长度小于 5 的字符串）。
fruits=["apple", "Banana", "cherry", "Date"]
new_fruits=[fruit for fruit in fruits if len(fruit)>=5]
print(new_fruits)

# 将列表 [1, 2, 2, 3, 3, 3, 4] 去重后，生成每个元素加 10 的集合
nums=[1, 2, 2, 3, 3, 3, 4]
set_nums=set(num+10 for num in nums)
print(set_nums)

# 用集合推导式找出两个列表 [1, 2, 3, 4] 和 [3, 4, 5, 6] 的共同元素。
nums1,nums2=[1,2,3,4],[3,4,5,6]
nums={num for num in nums1 if num in nums2}
print(nums)

# 将字典 {"a": 1, "b": 2, "c": 3} 反转（键变值，值变键）
nums={"a": 1, "b": 2, "c": 3}
dict_nums={value: index for index, value in enumerate(nums)}
dict_nums={value: index for index, value in nums.items()}
print(dict_nums)

# 从字典 {"Alice": 85, "Bob": 72, "Charlie": 90, "David": 65} 中筛选出分数 ≥ 80 的键值对，组成新字典。
nums= {"Alice": 85, "Bob": 72, "Charlie": 90, "David": 65}
dict_nums={index: value for index,value in nums.items() if value >= 80}
print(dict_nums)

# 假设有一个包含百万级整数的列表 huge_list，用生成器表达式计算所有偶数的和（避免占用过多内存）。
huge_list=[1,2,3,4,5,6,7,8,9]
ans=sum(num for num in huge_list)

# 用生成器表达式创建一个能无限生成斐波那契数列的生成器（每次迭代返回下一个数）。
from itertools import islice
def fib():
    a,b=0,1
    while True:
        yield a
        a,b =b,a+b

first_10=list(islice(fib(),10))
print(first_10)


# 给定字符串 text = "Hello world! This is a test. Hello again."，用推导式完成：
# 分割出所有单词（忽略标点，转为小写）
# 统计每个单词出现的次数（用字典存储）
text = "Hello world! This is a test. Hello again."
token=[str_text if str_text.isalpha() else str_text[:-1] for str_text in text.split()]
ans={t: token.count(t) for t in token}
print(ans)