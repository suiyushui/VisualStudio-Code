import csv
rows=[('李四', '21', '女'),('王武', '19', '男')]
with open('data.csv', 'w', encoding='utf-8', newline='') as f:
    writer=csv.writer(f)
    writer.writerow(['姓名', '年龄', '性别'])
    writer.writerow(['张三', '20', '男'])
    writer.writerows(rows)
with open('data.csv', 'r', encoding='utf-8') as f:
    reader= csv.reader(f)
    for row in reader:
        print(row)

