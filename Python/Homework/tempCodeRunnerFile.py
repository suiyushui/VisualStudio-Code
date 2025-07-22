matrix = [[1, 2, 3], [4, 5, 6]]
print([[i[j] for i in matrix] for j in range(len(matrix[0])) ])