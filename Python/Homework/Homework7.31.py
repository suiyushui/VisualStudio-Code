# import json
# with open('data.json','r',encoding='utf-8') as f:
#     file_data=json.load(f)
#     print(file_data)

# import json
# data = {
#     "name": "Charlie",
#     "skills": ["Python", "JSON", "SQL"],
#     "active": True
# }
# with open('output.json','w',encoding='utf-8') as f:
#     json.dump(data,f,ensure_ascii=False,indent=4)

# import json
# def serch_phone_number(data,numbers):
#     if isinstance(data,dict):
#         for key,value in data.items():
#             serch_phone_number(value,numbers)
#             if key=='phone':
#                 numbers.append(value)
#     elif isinstance(data,list):
#         for item in data:
#             serch_phone_number(item,numbers)

# with open('nested.json','r',encoding='utf-8')as f:
#     file_data=json.load(f)
#     numbers=[]
#     serch_phone_number(file_data,numbers)
#     print(numbers)

# import json
# str1='{"key": "value", "list": [1, 2, 3]}'
# temp=json.loads(str1)
# temp['new_key']=100
# file_data=json.dumps(temp,indent=4)
# print(file_data)

# import json
# with open('product.json','r',encoding='utf-8') as f:
#     file_data=json.load(f)
#     for item in file_data:
#         if item['price']>100:
#             print(item['name'])

# import json
# file1_data=None
# file2_data=None
# with open('file1.json','r',encoding='utf-8') as f1:
#     file1_data=json.load(f1)
# with open('file2.json','r',encoding='utf-8') as f2:
#     file2_data=json.load(f2)
# with open('formatted.json','w',encoding='utf-8') as f3:
#     json.dump(file1_data+file2_data,f3,ensure_ascii=False,indent=4)
# import json
# with open('formatted.json','r',encoding='utf-8') as f:
#     file_data=json.load(f)
#     with open('minifiled.txt','w',encoding='utf-8') as f2:
#         json.dump(file_data,f2,ensure_ascii=False,indent=0)

# import json
# with open('logs.json', 'r') as f:
#     logs=json.load(f)
#     count={}
#     for log in logs:
#         if log['status'] in count:
#             count[log['status']]+=1
#         else:
#             count[log['status']]=1
#     print(count)

# import json
# with open('config.json', 'r') as f:
#     data=json.load(f)
#     dict1=dict()
#     for item in data['features']:
#         dict1[item['id']]=item['enabled']
#     print(dict1)

# import datetime
# import json
# with open('events.json', 'r') as f:
#     data=json.load(f)
#     for item in data:
#         event_date=datetime.datetime.strptime(item['date'], '%Y-%m-%d')
#         print(event_date)

