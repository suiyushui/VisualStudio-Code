// var arr=[]
// var arr1=[1,2,3,4,5]
// console.log(arr1)
// var arr=new Array();
// var arr2=new Array(1,2,3,4,5);

// console.log(Array.isArray(arr1)) //true
// for(var i=0,len=arr1.length;i<len;i++){
//     console.log(arr1[i])
// }
// for(var i in arr1){
//     console.log(arr1[i])
// }//for in 遍历数组的键值对

// for(var i of arr1){
//     console.log(i);
// }
// console.log("=======");

// arr1.forEach(function(item,index,arr){
//     console.log(item,index,arr)
// });
// arr1.map(function(item,index,arr){
//     return item*2
// });

// let arr=[2,3,6,8,10,13];
// let sum=arr.length>0?arr.reduce((accumulator,currentValue)=>accumulator+currentValue,0):0;
// console.log(sum);
// let avg=arr.length>0?sum/arr.length:0;
// console.log(avg);

// console.log(Math.max(...arr));
// for(let i in arr){
//     console.log(i);//0,1,2,3,4,5
// }

// arr.forEach((item,index,arr)=>{
//     console.log(item,index,arr)
// });
// arr.push(5,6,7,8);
// arr.unshift(1);
// console.log(arr);
  
// for(let i=0;i<arr.length;){
//     if(arr[i]>7){
//         arr.splice(i,1);
//     }else{
//         i++;
//     }
// }
// console.log(arr);

// arr.sort((a,b)=>{
//     return a-b;
// });
// console.log(arr);
// arr.sort((a,b)=>{
//     return Math.random()-0.5;
// });
// console.log(arr);


class LRUCache{
    constructor(capacity){ //constructor方法是类的构造函数，用于创建类的实例。
        this.capacity=capacity;
        this.cache=new Map();
    }
    get(key){
        if(!this.cache.has(key))
            return -1;
        const value=this.cache.get(key);
        this.cache.delete(key);
        this.cache.set(key,value);
        return value;
    }
    put(key,value){
        if(this.cache.has(key)){
            this.cache.delete(key);
        }
        this.cache.set(key,value);
        if(this.cache.size>this.capacity){
            this.cache.delete(this.cache.keys().next().value);
        }
    }
}
const cache=new LRUCache(2);
cache.put(1,1);
cache.put(2,2);
cache.put(3,3);
console.log(cache.get(2));
cache.put(4,4);
console.log(cache.get(3));
console.log(cache.get(2));
