#给定列表 nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]，筛选出所有偶数，并计算它们的平方
nums=[1,2,3,4,5,6,7,8,9,10]
print([(i,i**2) for i in nums if i&1==0])

#给定字典列表 data = [{"name": "Alice", "age": 25}, {"name": "Bob", "age": 30}, {"name": "Charlie", "age": 35}]，提取所有 "name" 值。
data = [{"name": "Alice", "age": 25}, {"name": "Bob", "age": 30}, {"name": "Charlie", "age": 35}]
print([d["name"] for d in data])

#给定两个列表和 list2 = ['a', 'b']，生成它们的笛卡尔积（即所有可能的 (x, y) 组合）。
list1 = [1, 2, 3]
list2 = ['a','b']
print([(i,j) for j in list2 for i in list1])

#给定字符串 s = "Hello, World!"，过滤掉所有元音字母（a, e, i, o, u，不区分大小写），并返回剩余字符组成的列表。
s = "Hello, World!"
print([i for i in s if i.lower() not in ['a', 'e', 'i', 'o', 'u']])

#给定一个 (2 \times 3) 矩阵 matrix = [[1, 2, 3], [4, 5, 6]]，使用列表推导式进行转置（即行变列，列变行）。
matrix = [[1, 2, 3], [4, 5, 6]]
print([[i[j] for i in matrix] for j in range(len(matrix[0])) ])