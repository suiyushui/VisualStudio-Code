-- 创建商品表
CREATE TABLE products (
    product_id        NUMBER(10)        PRIMARY KEY,  -- 商品ID（主键）
    product_code      VARCHAR2(50)       NOT NULL UNIQUE,  -- 商品编码（唯一）
    product_name      VARCHAR2(200)      NOT NULL,     -- 商品名称
    category_id       NUMBER(5),                       -- 分类ID（可关联分类表）
    brand_id          NUMBER(5),                       -- 品牌ID（可关联品牌表）
    price             NUMBER(10, 2)      NOT NULL,     -- 售价
    cost_price        NUMBER(10, 2),                    -- 成本价
    stock_quantity    NUMBER(8)          DEFAULT 0,    -- 库存数量
    unit              VARCHAR2(20),                     -- 单位（个、件、kg等）
    status            CHAR(1)            DEFAULT '1',  -- 状态（1:正常,0:下架）
    description       CLOB,                            -- 商品描述（大文本）
    image_url         VARCHAR2(500),                    -- 商品图片URL
    created_time      DATE               DEFAULT SYSDATE,  -- 创建时间
    updated_time      DATE               DEFAULT SYSDATE,  -- 更新时间
    created_by        VARCHAR2(50),                     -- 创建人
    updated_by        VARCHAR2(50)                      -- 更新人
);

-- 创建索引提升查询性能
CREATE INDEX idx_products_category ON products(category_id);
CREATE INDEX idx_products_brand ON products(brand_id);
CREATE INDEX idx_products_status ON products(status);

-- 插入示例数据
INSERT INTO products (product_id, product_code, product_name, category_id, brand_id, price, cost_price, stock_quantity, unit, status, description)
VALUES (1, 'P0001', '智能手机X1', 1, 1, 3999.00, 2800.00, 100, '台', '1', '6.7英寸全面屏，128GB存储');

INSERT INTO products (product_id, product_code, product_name, category_id, brand_id, price, cost_price, stock_quantity, unit, status, description)
VALUES (2, 'P0002', '无线蓝牙耳机', 2, 2, 799.00, 450.00, 200, '副', '1', '主动降噪，续航24小时');

-- 提交事务
COMMIT;

-- 查询示例数据
SELECT * FROM products;


INSERT INTO products (product_id, product_code, product_name, category_id, brand_id, price, cost_price, stock_quantity, unit, status, description)
VALUES (3, 'P0003', '智能手表S1', 1, 1, 1999.00, 1200.00, 150, '块', '1', '心率监测，GPS定位');

SELECT * from products where product_name like '智能%';

INSERT INTO products (product_id, product_code, product_name, category_id, brand_id, price, cost_price, stock_quantity, unit, status, description)
VALUES (4, 'P0004', '智能手环S1', 1, 1, 1499.00, 1000.00, 100, '个', '1', '智能手环，可远程监控');

INSERT INTO products (product_id, product_code, product_name, category_id, brand_id, price, cost_price, stock_quantity, unit, status, description)
VALUES (5, 'P0005', '智能音箱', 2, 2, 899.00, 600.00, 80, '台', '1', '语音助手，智能家居控制');

INSERT INTO products (product_id, product_code, product_name, category_id, brand_id, price, cost_price, stock_quantity, unit, status, description)
VALUES (6, 'P0006', '智能家居套装', 3, 3, 2999.00, 2000.00, 50, '套', '1', '全屋智能控制，语音助手');

select * from products;
select round(14732,-2) from products; -- 1470

select upper('abc'),lower('ABC'),INITCAP('adc def')
from products where ROWNUM<=1;
select *
from produ  cts
ORDER BY product_id
FETCH FIRST 1 ROWS ONLY;


-- 将列的格式显示设置出来
ALTER SESSION SET NLS_DATE_FORMAT = 'YYYY-MM-DD HH24:MI:SS';



select SYSDATE as "当前日期" from dual;
select SYSDATE+1 as "明天日期" from dual;
select TRUNC(sysdate)-7 from dual;
select SYSDATE+0.5 as "半小时后" from dual;

select ADD_MONTHS(SYSDATE,1)  as 三月之后 from dual;-- sysdate加1个月

-- 计算两个日期间的天数
select (to_date('2021-08-01','yyyy-mm-dd') - to_date('2021-07-01','yyyy-mm-dd'))*1/24 from dual;

select TO_CHAR(last_day(ADD_MONTHS(TRUNC(SYSDATE, 'yyyy'),1)),'DD')from dual;

