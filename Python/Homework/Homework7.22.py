s={1,2,3}
print(s)
fs=frozenset(('a', 'b', 'c'))
print(fs)
fs = frozenset("abc")
print(fs) 
lst = [1, 2, 2, 3, 4, 4]
unique = set(lst)
print(unique) 
s = {1, 2, 3}
s.add(4)
print(s)  
s = {1, 2, 3}
s.remove(2)
print(s) 
a = {1, 2, 3}
b = {3, 4, 5}
union = a.union(b)
print(union)  

a = {1, 2, 3}
b = {3, 4, 5}
intersection = a.intersection(b)
print(intersection) 

a = {1, 2, 3}
b = {3, 4, 5}
difference = a.difference(b) # a - b
print(difference)


a = {1, 2, 3}
b = {3, 4, 5}
sym_diff = a.symmetric_difference(b) # a ^ b
print(sym_diff) 



squares = {x**2 for x in range(10) if x % 2 == 0} 
print(squares)  

fs = frozenset([1, 2, 3])
d = {fs: "value"} 

a = {1, 2, 3}
b = {1, 2}
print(a>b) 

a = {1, 2, 3}
b = {1, 2}
print(a>b)

s = {1, 2, 3, 4, 5}
print(len(s))  

s = {'a', 'b', 'c'}
for item in s:
    print(item)

s1 = {1, 2, 3}
s2 = s1.copy()
s2.add(4)
print(s1)
print(s2) 

fs1 = frozenset([1, 2])
fs2 = frozenset([3, 4])
merged =fs1|fs2
print(merged) 


a = {1, 2, 3}
b = {3, 4, 5}
a.update(b)
print(a)


fs = frozenset([1, 2, 3])
fs.add(4)
