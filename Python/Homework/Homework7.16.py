fruits=['apple','banana','orange','grape','mango']
numbers=[]
for i in range(1,6): numbers.append(i)
digits=[i for i in range(10)]
print(fruits)
print(numbers)
print(digits)

fruits.pop(2)
numbers.clear()
digits.remove(5)
print(fruits)
print(numbers)
print(digits)

print(fruits[len(fruits)-1])
print(3 in numbers)
digit=digits[3:6]
print(digit)

fruits.append('mango')
numbers.insert(0,0)
digits.extend([10,20,30])
print(fruits)
print(numbers)  
print(digits)

for fruit in fruits:
    print(fruit,end=' ')
i,sum_numbers=0,0
while i<len(numbers):
    sum_numbers+=numbers[i]
    i+=1
print(f'\n{sum_numbers}')
for digit in digits:
    print(digit**2,end=' ')
print()



import random
scores=[random.randint(0,100) for i in range(5)]
scores.append(65)
scores.remove(max(scores))
print(sum(scores)/len(scores) if len(scores)>0 else 0)

cities=['New York','London','Paris','Tokyo','Sydney']
city=input('Enter a city: ')
if city in cities:
    cities.remove(city)
    print(cities)
else:
    print('City not found.')

list1=[1,2,3]
list2=['a','b','c']
list3=[]
for i in range(len(list1)):
    list3.extend((list1[i],list2[i]))
print(list3)


words = ["hello", "world", "python", "hello"]
unique_words = set(words)
for word in unique_words:
    count=0
    for w in words:
        if w==word:
            count+=1
    print(f"{word}: {count}",end=' ')
print()

numbers=[]
while True:
    number=input("Enter a number (or 'q' to quit): ")
    if number=='q': break
    numbers.append(int(number))
print(f"Max:{max(numbers)},Min:{min(numbers)}")
    