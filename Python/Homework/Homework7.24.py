# students = [
#     {'name':'张三','age':18,'score':98,'tel':'18888888888','gender':'female'},
#     {'name':'李四','age':20,'score':95,'tel':'18888888889','gender':'unkown'},
#     {'name':'王五','age':18,'score':88,'tel':'18888888810','gender':'male'},
#     {'name':'托尼','age':16,'score':58,'tel':'18888888818','gender':'unkown'},
#     {'name':'李磊','age':19,'score':99,'tel':'18888888812','gender':'male'},
#     {'name':'丽丽','age':17,'score':52,'tel':'18888888813','gender':'male'},
# ]
# #（1）统计不及格学生的个数

# number_fail = len([student for student in students if student['score'] < 60])
# print(number_fail)

# #（2）打印不及格学生的名字和对应的成绩
# print([(student['name'], student['score']) for student in students if student['score'] < 60])

# #（3）统计未成年学生的个数
# number_underage = len([student for student in students if student['age'] < 18])
# print(number_underage)

# #（4）打印手机尾号是8的学生的名字
# print([stduent['name'] for stduent in students if stduent['tel'][-1] == '8'])

# # (5) 打印最高分和对应学生的名字
# max_score_student = max(students, key=lambda x:x['score'])
# print(max_score_student['name'], max_score_student['score'])

# #（6）删除性别不明的所有的学生
# students=[student for student in students if student['gender']!='unkown']

# #（7）将列表按照学生成绩从大到小排序
# students.sort(key=lambda x:x['score'])
# print(students)



# 用三个元组表示三门学科的选课学生姓名，（一个学生可以同时选多门课）
mathematics = ('小明','小红','小刚','小李','小熊','小雷','张三','李四')
chinese = ('小丽','小明','小红','小李','王三')
english = ('王五','小明','小刚','小熊','小雷')
# （1）求选课学生总共有多少人
all_students = set(mathematics)|set(chinese)|set(english)
print(len(all_students))


# （2） 求只选了第一个学科的人的数量和对应的名字
only_mathematics = [mathematic for mathematic in mathematics if mathematic not in english and mathematic not in chinese]
print(len(only_mathematics), only_mathematics)


# （3） 求只选了一个学科的人的数量和对应的名字
only_one=set(mathematics)&set(chinese)&set(english)
print(len(only_one), only_one)
        
# （4） 求只选了两门学科的学生的数量和对应的名字
only_three = set(mathematics)&set(chinese)&set(english)
only_two= all_students-only_three-only_one
print(len(only_two), only_two)


# （5） 求选了三门学科的学生的数量和对应的名字
print(len(all_students), all_students)