import Mock from "mockjs";

Mock.mock('http://localhost:8080/product/search' ,'get',{
    "ret":0,
    "data":{
        "mtime": "@datetime",
        "score|1-100": 1,
        "rank|1-100": 1,
        "start|1-100": 1,
        "nickname": "@cname",
        "img":"@image('200x100', '#5C9EBF','#FFF','png','Hello')"
    }
});

// 拦截带分页参数的 GET /api/users 请求
Mock.mock(/\/api\/users/, "get", function(options) {
  const { url } = options;
  const params = new URL(url, "http://localhost").searchParams;
  
  const page = parseInt(params.get("page")) || 0;
  const size = parseInt(params.get("size")) || 10;
  const sort = params.get("sort") || "id,asc";
  const search = params.get("search");

  // 生成模拟数据
  const mockData = Mock.mock({
    "data": {
      "content|10": [{
        "id|+1": page * size + 1,
        "name": "@cname",
        "email": "@email",
      }],
      "totalElements": 100,
      "totalPages": 10,
    },
    "code": 200
  });

  // 根据搜索条件过滤（模拟）
  if (search) {
    mockData.data.content = mockData.data.content.filter(item => 
      item.email.includes(search)
    );
  }

  return mockData;
});
