# 猜拳游戏
import random

while True:
    k=input("请输入你的选择(石头(s)、剪刀(p)、布(b))")
    if k not in ['s','p','b']:
        
        print("输入错误，请重新输入")
        continue

    arr=['s','p','b']
    c=random.choice(arr)
    if k==c:
        print("平局")
        continue
    elif (k=='s' and c=='p') or (k=='p' and c=='b') or (k=='b' and c=='s'):
        print("你输了")
    else:
        print("你赢了")