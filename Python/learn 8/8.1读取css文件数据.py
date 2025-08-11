# import pandas as pd
# df=pd.read_csv('data.csv',sep='，',header=0,names=['电影名','上映时间','评分'],parse_dates=['上映时间'] )

# print(df)
# import csv
# with open('data.csv', 'r', encoding='utf-8') as f:
#     reader = csv.reader(f)
#     for row in reader:
#         print(row)
#     f.seek(0)
#     print(reader)
#     head= next(reader)
#     print(head)

# import pandas as pd
# data={
#     'name': ['钢铁侠', '蜘蛛侠', '复仇者联盟'],
#     'time': ['2013-05-05','2012-07-07','2015-08-08'],
#     'rating': [8.5, 7.8, 8.9]
# }
# df =pd.DataFrame(data,columns=['name','time','rating']) # 创建DataFrame
# df.to_csv('data.csv',sep='，',index=False) # 保存为csv文件
# df=pd.read_csv('data.csv',sep='，',header=0,names=['电影名','上映时间','评分'],parse_dates=['上映时间'] )
# print(df)

# import csv
# with open('data.csv',mode='w',encoding='utf-8')as file:
#     writer=csv.writer(file)
#     writer.writerow(['电影名','上映时间','评分'])
#     writer.writerow(['猫和老鼠','2013-05-05',8.5])
#     writer.writerow(['蜘蛛侠','2012-07-07',7.8])
#     writer.writerow(['复仇者联盟','2015-08-08',8.9])

# with open ('data.csv',mode='r',encoding='utf-8~~ae_')as file:
#     reader=csv.reader(file)
#     for row in reader:
#         print(row)


