print("hello"[:3]);
print("programming"[-4:]);
print("python"[2:5]);
print("abcdef"[::2]);
print("world"[::-1]);
print("abcdefg"[-3:]);
print("123456789"[2::2]);
print("abcdef"[:len("abcdef")//2]);
print("1234567"[-(len("1234567")//2):]);
print("abcd1234"[-(len("abcd1234")//2):]+"abcd1234"[:len("abcd1234")//2]);
print("abcdef"[0::2]+"abcdef"[1::2]);
print(' '.join(("hello world python").split(" ")[::-1]));
print(("name:John,age:25").split(",")[0].split(":")[1]);
s=[c.lower() for c in "A man, a plan, a canal: Panama" if c.isalpha()];
print(s==s[::-1]);

s= "A man, a plan, a canal: Panama"
i=0
j=len(s)-1
flag=True
while i<j:
    while i<j and not s[i].isalpha():
        i+=1
    while i<j and not s[j].isalpha():
        j-=1
    if s[i].lower()!=s[j].lower(): 
        flag=False
        break
    i+=1
    j-=1
print(flag)


#print("abcdefgh"[-3:]+"abcdefgh"[:-3]);