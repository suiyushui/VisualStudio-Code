(function fun(){
    console.log("Hello World");
    console.log("Welcome to JavaScript");
})();

(function fun2(a,b){
    console.log(a+b);
})(2,3);

var fun = new Function("console.log('hello 这是我的第一个函数')");
console.log(typeof fun);//function
fun();

