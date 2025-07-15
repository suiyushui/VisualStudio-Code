const str="test@test.com";
const emailRegex=/\b[\w.%+-]+@[\w.-]+\.[A-Za-z]{2,6}\b/g;
console.log(emailRegex.test(str));

const str2="Contact me at myemail@test.com or support@test.com";
let macth;
while((macth=emailRegex.exec(str2))!==null){
    console.log("Found:",macth[0]);
}

const str3 = "Emails: test@example.com, support@example.org";
const matches = str3.match(emailRegex);
console.log(matches);

const str4="Contact me at myemail@test.com or support@test.com";
const newStr=str4.replace(emailRegex,"[email hidden]");
console.log(newStr);

const  str5="Email: myemail@test.com";
const index=str5.search(emailRegex);
console.log(index);

const str6="a,b:c,d";
const regex=/[,;]/;
const parts=str6.split(regex);
console.log(parts);

/*
在 JavaScript 中，正则表达式（RegExp）用于匹配、查找或替换字符串中的文本。以下是正则表达式在 JS 中的常见用法：

---

## **1. 创建正则表达式**
有两种方式创建正则表达式：

### **(1) 字面量语法（推荐）**
```javascript
const regex = /pattern/flags;
```
- `pattern` 是正则表达式模式
- `flags` 是可选的修饰符（如 `g` 全局匹配，`i` 不区分大小写等）

**示例：**
```javascript
const emailRegex = /\b[\w.%+-]+@[\w.-]+\.[a-zA-Z]{2,6}\b/g;
```

### **(2) 构造函数语法**
```javascript
const regex = new RegExp("pattern", "flags");
```
**示例：**
```javascript
const emailRegex = new RegExp("\\b[\\w.%+-]+@[\\w.-]+\\.[a-zA-Z]{2,6}\\b", "g");
```
⚠️ **注意**：使用构造函数时，`\` 需要转义，所以写成 `\\`。

---

## **2. 常用正则方法**
### **(1) `test()` - 检查是否匹配**
返回 `true` 或 `false`：
```javascript
const str = "test@example.com";
const emailRegex = /\b[\w.%+-]+@[\w.-]+\.[a-zA-Z]{2,6}\b/;
console.log(emailRegex.test(str)); // true
```

### **(2) `exec()` - 查找匹配项**
返回匹配结果的数组（或 `null`）：
```javascript
const str = "Contact me at test@example.com or support@example.org";
const emailRegex = /\b[\w.%+-]+@[\w.-]+\.[a-zA-Z]{2,6}\b/g;

let match;
while ((match = emailRegex.exec(str)) !== null) {
  console.log("Found:", match[0]); // 输出所有匹配的邮箱
}
```
**输出：**
```
Found: test@example.com
Found: support@example.org
```

### **(3) `match()` - 字符串方法，返回匹配数组**
```javascript
const str = "Emails: test@example.com, support@example.org";
const emailRegex = /\b[\w.%+-]+@[\w.-]+\.[a-zA-Z]{2,6}\b/g;
const matches = str.match(emailRegex);
console.log(matches); // ["test@example.com", "support@example.org"]
```

### **(4) `replace()` - 替换匹配项**
```javascript
const str = "Contact me at test@example.com";
const emailRegex = /\b[\w.%+-]+@[\w.-]+\.[a-zA-Z]{2,6}\b/g;
const newStr = str.replace(emailRegex, "[email protected]");
console.log(newStr); // "Contact me at [email protected]"
```

### **(5) `search()` - 返回匹配的索引**
```javascript
const str = "Email: test@example.com";
const emailRegex = /\b[\w.%+-]+@[\w.-]+\.[a-zA-Z]{2,6}\b/;
const index = str.search(emailRegex);
console.log(index); // 7（匹配开始的位置）
```

### **(6) `split()` - 用正则分割字符串**
```javascript
const str = "a,b;c d";
const regex = /[,; ]/; // 匹配逗号、分号或空格
const parts = str.split(regex);
console.log(parts); // ["a", "b", "c", "d"]
```

---

## **3. 常用正则修饰符（flags）**
| 修饰符 | 作用 |
|--------|------|
| `g` | 全局匹配（查找所有匹配项） |
| `i` | 不区分大小写 |
| `m` | 多行模式（`^` 和 `$` 匹配每行的开头和结尾） |
| `u` | Unicode 模式（支持 `\u{FFFF}`） |
| `s` | 允许 `.` 匹配换行符（`\n`） |

**示例：**
```javascript
const regex = /hello/gi; // 全局 + 不区分大小写
const str = "Hello, hello, HELLO!";
console.log(str.match(regex)); // ["Hello", "hello", "HELLO"]
```

---

## **4. 常见正则表达式示例**
### **(1) 匹配数字**
```javascript
const regex = /\d+/; // 匹配一个或多个数字
console.log(regex.test("123")); // true
```

### **(2) 匹配手机号（简单版）**
```javascript
const phoneRegex = /^1[3-9]\d{9}$/; // 匹配 11 位手机号
console.log(phoneRegex.test("13812345678")); // true
```

### **(3) 匹配 URL**
```javascript
const urlRegex = /https?:\/\/[^\s]+/g;
const str = "Visit https://example.com or http://google.com";
console.log(str.match(urlRegex)); // ["https://example.com", "http://google.com"]
```

### **(4) 匹配日期（YYYY-MM-DD）**
```javascript
const dateRegex = /^\d{4}-\d{2}-\d{2}$/;
console.log(dateRegex.test("2024-05-20")); // true
```

---

## **5. 正则表达式进阶**
### **(1) 分组捕获**
使用 `()` 捕获匹配的子串：
```javascript
const str = "2024-05-20";
const dateRegex = /(\d{4})-(\d{2})-(\d{2})/;
const match = dateRegex.exec(str);
console.log(match[1]); // "2024"（年）
console.log(match[2]); // "05"（月）
console.log(match[3]); // "20"（日）
```

### **(2) 非捕获分组 `(?:...)`**
匹配但不捕获：
```javascript
const str = "hello world";
const regex = /(?:hello) (world)/;
const match = regex.exec(str);
console.log(match[1]); // "world"（只捕获第二个分组）
```

### **(3) 正向/反向断言**
- **正向先行断言 `(?=...)`**（匹配后面是某模式的部分）：
  ```javascript
  const str = "100px 200em 300rem";
  const regex = /\d+(?=px)/g;
  console.log(str.match(regex)); // ["100"]（匹配后面是 "px" 的数字）
  ```
- **负向先行断言 `(?!...)`**（匹配后面不是某模式的部分）：
  ```javascript
  const regex = /\d+(?!px)/g;
  console.log(str.match(regex)); // ["200", "300"]（匹配后面不是 "px" 的数字）
  ```

---

## **总结**
| 方法 | 用途 |
|------|------|
| `regex.test(str)` | 检查是否匹配 |
| `regex.exec(str)` | 返回匹配详情（可循环） |
| `str.match(regex)` | 返回所有匹配项 |
| `str.replace(regex, newStr)` | 替换匹配内容 |
| `str.search(regex)` | 返回匹配的索引 |
| `str.split(regex)` | 按正则分割字符串 |

正则表达式在表单验证、数据提取、字符串处理等场景非常有用。掌握它可以大幅提升 JS 编程效率！ 🚀
*/