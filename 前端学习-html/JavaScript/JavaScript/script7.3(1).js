// var num=+prompt("请输入一个数字");
// var sum=0;
// var fun=()=>{
//     for(var i=1;i<=num;i++){
//         sum+=i;
//     }
//     return sum;
// }
// console.log(fun());


function fun(){
    console.log(arguments);
    console.log(arguments instanceof Array); 
}
fun(1,2,3);
var obj = {
    name: "张三",
    sayname: function(b, c) {
        console.log(arguments); // 使用 arguments 对象
        console.log(this.name);
    },
};

var obj2 = {
    name: "李四"
};

obj.sayname.call(obj2, 2, 3);


