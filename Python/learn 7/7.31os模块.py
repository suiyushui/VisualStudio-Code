# import os


# if os.path.isdir('Python/learn'):
#     print('目录已存在')
# else:
#     os.makedirs('Python/learn')
#     print('目录已创建')


# f_str='Python/learn/7.31os模块.py'
# if os.path.exists(f_str):
#     print('文件已存在')
#     f_stat=os.stat('Python/learn/7.31os模块.py')
#     print(f_stat.st_size)
#     print(f_stat.st_ctime)
#     print(f_stat.st_mtime)

# else:
#     with open('Python/learn/7.31os模块.py', 'w', encoding='utf-8') as f:
#         f.write('import os\n\nprint(os.getcwd())')
#     print('文件已创建')

# from importlib.metadata import files
# import os  
# os.listdir('Python/learn') # 列出当前目录下所有文件和目录
# for root,dirs,files in os.walk('Python/learn'):
#     # for file in files:
#         print(root,dirs,files)

# with open('data.txt' ,'w',encoding='utf-8')as f:
#     # content=f.read()
#     # f.seek(0,0) # 移动文件指针到开头
#     # for line in f:
#     #     print(line.strip())
#     f.write('2021-12-11\n') # 覆盖写入
#     f.writelines(['2021-12-12','2021-12-13','2021-12-14'])




# file=open('data.txt','r',encoding='utf-8')
# username=input('请输入用户名：')
# password=input('请输入密码：')
# login_success=False

# for line in file:
#     line=line.strip()
#     if not line:
#         continue
#     # if username in line and password in line:
#     #     login_success=True
#     #     break
#     parts=line.split()
#     if len(parts)!=2:
#         continue
#     if username==parts[0] and password==parts[1]:
#         login_success=True
#         break
# file.flush() # 刷新缓冲区
# file.close() # 关闭文件
# if login_success:
#     print('登录成功')
# else:
#     print('登录失败')



# with open('data.txt','w',encoding='utf-8')as f:
#     f.write('admin 123456\n')
#     f.write('guest 123456\n')
# with open('data.txt','r',encoding='utf-8')as f:
#     print(f.readlines())
# CHUNK=int(1024*1024*0.25) #256KB
# with open('src.jpg', 'rb') as src, open('dst.jpg', 'wb') as dst:
#     while chunk:=src.read(CHUNK):
#         dst.write(chunk)


# import os 
# import shutil

# str1=os.path.join('Python','learn')
# print(str1)

# print(os.path.abspath('.'))
# print(os.path.exists('Python/learn/7.31os模块.py'))
# print(os.path.isfile('Python/learn/7.31os模块.py')) # 判断是否为文件
# print(os.path.isdir('Python/learn')) # 判断是否为目录
# print(os.path.getsize('Python/learn/7.31os模块.py')) # 获取文件大小
# print(os.path.getctime('Python/learn/7.31os模块.py')) # 获取文件创建时间

# f_list=os.listdir('Python')
# for f in f_list:
#     if os.path.isdir(os.path.join('Python',f)):
#         print(f'{f} 是目录')
#     else:
#         print(f'{f} 是文件')

# os.rename('src.png','QR码.png')
# os.remove('QR码.png')
# os.mkdir('python/图片')

# os.makedirs('python/图片/壁纸',exist_ok=True)
# shutil.rmtree('python/图片')
# print(os.path.abspath('.'))
# print(os.listdir('.'))
# full_entries=[os.path.join('.',entry) for entry in os.listdir('.')] =

import  os
# glob模式匹配

import glob
from datetime import datetime
print(os.listdir('.'))
py_files=glob.glob('*.txt')
print(type(py_files))

full_path=os.path.join('dir','subdir','file.txt')
print(type(full_path))
p=print
name,ext=os.path.splitext(full_path)
p(name,ext,sep='\n')
p(os.path.exists('data.csv'))
p(os.path.getsize('data.csv'))

mtime=os.path.getmtime('data.txt')
atime=os.path.getatime('data.txt')

#转化为可读模式
print(datetime.fromtimestamp(mtime))

with os.scandir('.') as entries:
    for entry in entries:
        if entry.is_file():
            print(entry.name)

def scure_delete(path,passes=3):
    with open(path,'rb+')as f:
        f.seek(0,2) # 移动文件指针到结尾
        length=f.tell()
        for _ in range(passes):
            f.seek(0)
            f.write(os.urandom(length)) # 随机填充文件内容
fd=os.open('file.bin',os.O_RDWR|os.O_CREAT)
data=os.read(fd,1024)
os.write(fd,b'binary data')

# scandir( )方法是os模块中的一个高级接口，它可以用来遍历文件系统中的文件和目录。
with os.scandir('.') as entries:
    for entry in entries:
        if entry.is_file():
            print(entry.name)