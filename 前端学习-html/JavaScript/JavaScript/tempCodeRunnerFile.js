// 第一种方式：对象字面量
const person1 = {
    name: "John Doe",
    age: 30,
    city: "New York"
};
console.log(person1.name); // 输出: John Doe
console.log(person1.age);  // 输出: 30
console.log(person1.city); // 输出: New York

// 第二种方式：构造函数
const person2 = new Object();
person2.name = "John Doe";
person2.age = 30;
person2.city = "New York";
person2.sayName = function() {
    console.log(this.name); // 使用this指向当前对象
};
person2.sayName(); // 输出: John Doe

// 修正后的obj2
const person3 = {
    name: "john", // 使用引号
    age: 20,
    city: "New York",
    job: "teacher", // 使用引号
    sayHi() {
        console.log("Hi");
    }
};
console.log(person3.name); // 输出: john
console.log(person3['age']);  // 输出: 20
console.log(person3.city); // 输出: New York
console.log(person3.job);  // 输出: teacher
person3.sayHi(); // 输出: Hi