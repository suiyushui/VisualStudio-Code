import socket

# socket.AF_INET 表示网络套接字   socket.SOCK_STREAM 使用tcp协议
phone = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# 连接服务器  port  0-65535  0-1024 操作系统
phone.connect(('127.0.0.1', 8080))
while True:
    user_input = input(">>")
    # 输入空值问题解决
    if not user_input:
        continue
    phone.send(user_input.encode('utf-8'))
    data = phone.recv(1024)
    print('receive sever response:',data.decode('utf-8'))
    if user_input == 'exit':
        break
# 释放资源
phone.close()
