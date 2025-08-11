import re

text= 'foofoo'
m1=re.search(r'(foo)\1',text)
print(m1.group(0))
m2 = re.search(r'(?:foo)', text)
print(m2.group(0)) 

