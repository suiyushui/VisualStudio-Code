//创建一个计算两个数和的函数。
var sum=(a,b)=>{
    if(typeof a!== 'number' || typeof b!== 'number' ){
        throw new Error("参数必须是数字");
    }
    return a+b;
}
console.log(sum(1,2));

//封装一个两个数的差的函数。
const MathOperations=(()=>{
    const subtract= (a,b)=>{
        if(typeof a!== 'number' || typeof b!== 'number' ){
            throw new Error("参数必须是数字");
        }
        return a-b;
    };
    return {
        subtract
    };
})();
console.log(MathOperations.subtract(5,3));

//利用函数求两个数的最大值
var max_num=(a,b)=>{
    if(typeof a!== 'number' || typeof b!== 'number' ){
        throw new Error("参数必须是数字");
    }
    return Math.max(a,b);
}   
console.log(max_num(5,3));

//利用函数求任意个数的最大值
var max_num2=(...args)=>{
    if(!args.every(arg => typeof arg === 'number')){
        throw new Error("所有参数必须是数字");
    }
    return Math.max(...args);   
}
console.log(max_num2(5,3,8,2));

//传递一个数组，实现数组翻转的函数。
var reverseArray=(arr)=>{
    return arr.reverse();
}
console.log(reverseArray([1,2,3,4,5]));

//封装一个函数：浏览器接收一个月份判断这个月份的天数。
const solve7=(()=>{
    const day=(month)=>{
        if(typeof month!== 'number' || month < 1 || month > 12){
            throw new Error("输入月份格式不正确!");
        }
        var months=[31,28,31,30,31,30,31,31,30,31,30,31];
        return months[month];
    }
    return{
        day
    };
})();
console.log(solve7.day(7));

//创建一个函数传递一个数组返回数组中的最大值，最小值，还有和
const solve8=(()=>{
    const max_min_sum=(arr)=>{
        let max_num=Math.max(...arr);
        let min_num=Math.min(...arr);
        let sum=accumulate(arr,(acc,cur)=>{
            return acc+cur;
        });
        return {
            max_num,
            min_num,
            sum
        };  
    };
})();
console.log(solve8.max_min_sum([1,2,3,4,5]));
//输入一个年份，判断是否是闰年（闰年可以被4或者400整除）
var isLeapYear=(year)=>{
    if(typeof year!== 'number' || year < 1){
        throw new Error("输入年份格式不正确!");
    }
    if(year%4==0&&year%100!=0||year%400==0){
        return true;
    }else{
        return false;
    }
}

console.log(isLeapYear(2000)); 