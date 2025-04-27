import Mock from 'mockjs';
Mock.mock('/product/search', {
    "ret": 0,
    // 这里可以自定义返回的消息
    "msg": "success",
    "data": {
        "mtime":"@datetime",
        "score|1-800": 1,
        "start|1-5":1,
        "nickname":"@cname",
        //自定义图片
        "img":"@image('200x100', '#4A7BF7', '#FFF', 'png', 'Fast Mock')",
    },   
});