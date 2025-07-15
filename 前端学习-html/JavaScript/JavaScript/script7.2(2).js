
function createPerson(name, age, city, job) {
    return {
        name,
        age,
        city,
        job,
        sayName() {
            console.log(`我的名字是${this.name}`);
        },
        greet() {
            const jobInfo = this.job ? `职业是${this.job}` : '暂无职业';
            console.log(`你好，我是${this.name}，今年${this.age}岁，住在${this.city}，${jobInfo}`);
        }
    };
}

// 创建对象实例
const person1 = createPerson("张三", 30, "北京", "工程师");
const person2 = createPerson("李四", 25, "上海");

person1.sayName(); // 我的名字是张三
person1.greet();   // 你好，我是张三，今年30岁，住在北京，职业是工程师
person2.greet();   // 你好，我是李四，今年25岁，住在上海，暂无职业

// 类型安全验证
console.log(person1.age.toFixed(1)); // 30.0
console.log(person2.job || "未填写"); // 未填写
console.log();


for(var key in person1) {
    if(typeof person1[key] === "function") {
        console.log(`调用方法: ${key}`);
        person1[key](); // 调用方法
    } else {
        console.log(`${key}: ${person1[key]}`); // 输出属性值
    }
}



