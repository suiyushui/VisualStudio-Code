import socket
"""
为了便于理解socket的通信流程，可以将socket的通信类比成手机通信
1.创建基站
2.设置基站位置
3.开机
4.监听来电
"""
phone =socket.socket(socket.AF_INET,socket.SOCK_STREAM) # 创建socket对象
phone.bind(('127.0.0.1',8080)) # 绑定本地IP和端口
phone.listen(5) # 监听的最大连接数
print('服务端启动,等待连接....')
conn,accept=phone.accept() # 等待客户端连接
print('客户端连接成功')
while True:
    data=conn.recv(1024) # 接收客户端数据
    if not data:
        break
    print('客户端发来数据:',data.decode('utf-8'))
    conn.send(data.upper()) # 向客户端发送数据
conn.close() # 关闭连接
phone.close() # 关闭服务端