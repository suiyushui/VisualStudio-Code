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

select nvl2(comm,'1','0') from emp;

select distinct * from emp;


select case when 1=1 then 1 else 0 end from dual;
select decode(1,1,1,0) from dual;

select nvl(123,'456') from dual;

CREATE OR REPLACE FUNCTION fun_random_award RETURN VARCHAR2 IS
    v_num NUMBER; -- 1-100的随机数
BEGIN
    v_num := TRUNC(DBMS_RANDOM.VALUE(1, 101)); -- 生成1-100的整数
    IF v_num > 95 THEN
    RETURN '一等奖';
    ELSIF v_num > 85 THEN
    RETURN '二等奖';
    ELSIF v_num > 70 THEN
    RETURN '三等奖';
    ELSE
    RETURN '谢谢惠顾';
    END IF;
END;
/

-- 使用匿名PL/SQL块来调用函数
DECLARE
    v_award VARCHAR2(100);
BEGIN
    v_award := fun_random_award;
    DBMS_OUTPUT.PUT_LINE('奖项: ' || v_award);
END;
/

-- 分析函数
select ename,sal,deptno ,sum(sal) over(partition by deptno) from emp;

select sal,lead(sal,1,0) over (order by sal) from emp;



-- 1. 学生表（如已存在可跳过）
CREATE TABLE student (
    stu_id   NUMBER       PRIMARY KEY,
    stu_name VARCHAR2(50) NOT NULL
);

-- 2. 课程表（如已存在可跳过）
CREATE TABLE course (
    course_id   NUMBER       PRIMARY KEY,
    course_name VARCHAR2(50) NOT NULL
);

-- 3. 课程成绩表
CREATE TABLE course_score (
    stu_id    NUMBER       NOT NULL,
    course_id NUMBER       NOT NULL,
    score     NUMBER(5,2)  CHECK (score BETWEEN 0 AND 100), -- 百分制
    CONSTRAINT pk_course_score PRIMARY KEY (stu_id, course_id),     -- 一个学生一门课只有一条成绩
    CONSTRAINT fk_cs_student FOREIGN KEY (stu_id)    REFERENCES student(stu_id),
    CONSTRAINT fk_cs_course  FOREIGN KEY (course_id) REFERENCES course(course_id)
);

-- 4. 可选：索引（按需要）
CREATE INDEX idx_cs_stu    ON course_score(stu_id);
CREATE INDEX idx_cs_course ON course_score(course_id);


-- 插入测试数据
INSERT INTO student(stu_id, stu_name) VALUES (1,'张三');
INSERT INTO course(course_id, course_name) VALUES (101,'数据库');
INSERT INTO course_score(stu_id, course_id, score) VALUES (1,101,92.5);
COMMIT;

-- 查询
SELECT s.stu_name,
       c.course_name,
       sc.score
FROM   course_score sc
JOIN   student s ON s.stu_id    = sc.stu_id
JOIN   course  c ON c.course_id = sc.course_id;

/* 1. 学生 5 人 */
INSERT INTO student(stu_id, stu_name) VALUES (1,'张三');
INSERT INTO student(stu_id, stu_name) VALUES (2,'李四');
INSERT INTO student(stu_id, stu_name) VALUES (3,'王五');
INSERT INTO student(stu_id, stu_name) VALUES (4,'赵六');
INSERT INTO student(stu_id, stu_name) VALUES (5,'孙七');

/* 2. 课程 3 门 */
INSERT INTO course(course_id, course_name) VALUES (101,'数据库');
INSERT INTO course(course_id, course_name) VALUES (102,'数学');
INSERT INTO course(course_id, course_name) VALUES (103,'英语');

/* 3. 成绩 10 条（每名学生不一定全选 3 门，故意留空值便于演示透视） */
INSERT INTO course_score(stu_id, course_id, score) VALUES (1,101,92.50);
INSERT INTO course_score(stu_id, course_id, score) VALUES (1,102,85.00);
INSERT INTO course_score(stu_id, course_id, score) VALUES (2,101,78.00);
INSERT INTO course_score(stu_id, course_id, score) VALUES (2,103,88.50);
INSERT INTO course_score(stu_id, course_id, score) VALUES (3,102,95.00);
INSERT INTO course_score(stu_id, course_id, score) VALUES (3,103,90.00);
INSERT INTO course_score(stu_id, course_id, score) VALUES (4,101,67.00);
INSERT INTO course_score(stu_id, course_id, score) VALUES (4,102,73.50);
INSERT INTO course_score(stu_id, course_id, score) VALUES (4,103,84.00);
INSERT INTO course_score(stu_id, course_id, score) VALUES (5,101,59.00);

COMMIT;


SELECT s.stu_name,
       c.course_name,
       sc.score
FROM   course_score sc
JOIN   student s ON s.stu_id    = sc.stu_id
JOIN   course  c ON c.course_id = sc.course_id
ORDER  BY s.stu_id, c.course_id;


select * from student;
select * from course;
select * from course_score;

select * from (
    select stu_id,
           course_id,
           score
        from COURSE_SCORE)
pivot (max(score) for course_id in (101 as 数据库, 102 AS 数学, 103 AS 英语));

select ename,instr(ename,'A',-1) ,substr(ename,instr(ename,'A',-1))  FROM emp where instr(ename,'A',-1)>0;

select * from emp where mod(extract(month from HIREDATE),2)=0;


select * from emp where mod(to_number(to_char(HIREDATE,'MM')),2)=0;

select avg(salary) avg_sal,count(*) from employees where salary>5000 group by department_id having avg(salary)>5000  order by avg_sal asc;
select * from emp where ename like 'S%';
select * from emp where substr(ename,1,1)='S';
alter session set NLS_DATE_LANGUAGE='SIMPLIFIED CHINESE';
select to_char(sysdate,'YYYY"年"MM"月"DD"日" DAY') from dual;
select  * from emp where ename!=TRANSLATE(ename,'*'||job,'*') or TRANSLATE(ename,'*'||job,'*')is not null;


select case when hiredate<date'1981-01-01' then to_char(deptno) when hiredate between date'1981-01-01'and date'1982-12-31'  then TO_CHAR(hiredate,'YYYY')  else to_char(hiredate,'MM') end as ans from emp;

CREATE TABLE "DEMO" 
   (    "ID" NUMBER(*,0), 
    "NAME" VARCHAR2(20), 
    "NUMS" NUMBER(*,0)
   ) ;
insert into DEMO (id, name, nums)
values (1, '苹果', 1000);
insert into DEMO (id, name, nums)
values (2, '苹果', 2000);
insert into DEMO (id, name, nums)
values (3, '苹果', 4000);
insert into DEMO (id, name, nums)
values (1, '橘子', 5000);
insert into DEMO (id, name, nums)
values (2, '橘子', 3000);
insert into DEMO (id, name, nums)
values (3, '葡萄', 3500);
insert into DEMO (id, name, nums)
values (4, '芒果', 4200);
insert into DEMO (id, name, nums)
values (4, '芒果', 5500);
commit;

CREATE TABLE "SCOTT"."KECHENG" 
   (    "ID" NUMBER, 
    "NAME" VARCHAR2(20), 
    "COURSE" VARCHAR2(20), 
    "SCORE" NUMBER
   ) ;
insert into KECHENG (id, name, course, score)
values (1, '张三', '语文', 67);
insert into KECHENG (id, name, course, score)
values (1, '张三', '数学', 76);
insert into KECHENG (id, name, course, score)
values (1, '张三', '英语', 43);
insert into KECHENG (id, name, course, score)
values (1, '张三', '历史', 56);
insert into KECHENG (id, name, course, score)
values (1, '张三', '化学', 11);
insert into KECHENG (id, name, course, score)
values (2, '李四', '语文', 54);
insert into KECHENG (id, name, course, score)
values (2, '李四', '数学', 81);
insert into KECHENG (id, name, course, score)
values (2, '李四', '英语', 64);
insert into KECHENG (id, name, course, score)
values (2, '李四', '历史', 93);
insert into KECHENG (id, name, course, score)
values (2, '李四', '化学', 27);
insert into KECHENG (id, name, course, score)
values (3, '王五', '语文', 24);
insert into KECHENG (id, name, course, score)
values (3, '王五', '数学', 25);
insert into KECHENG (id, name, course, score)
values (3, '王五', '英语', 8);
insert into KECHENG (id, name, course, score)
values (3, '王五', '历史', 45);
insert into KECHENG (id, name, course, score)
values (3, '王五', '化学', 1);
commit;


select * from kecheng
pivot(
    max(score) for course in ('语文' "语文",'数学' "数学",'英语' "英语",'历史' "历史",'化学' "化学")
)order by id;

select to_char(months_between(sysdate,hiredate)/12,'990')||'年'||to_char(mod(months_between(sysdate,hiredate),12),'990')||'月'||to_char(sysdate-add_months(hiredate,trunc(months_between(sysdate,hiredate))),'990')||'天' as 年龄
 from emp;

select * from(select * from emp order by sal desc) where rownum<=3;
select sum(sal) over(order by null rows between unbounded preceding and current row) as"累计薪资" from emp; 

select case when sal<1000 then '低薪' when sal>=1000 and sal<3000 then '中薪' when sal>=3000 then '高薪' end 薪资等级,count(*) 人数 from emp group by case when sal<1000 then '低薪' when sal>=1000 and sal<3000 then '中薪' when sal>=3000 then '高薪' end;

SELECT empno,
       ename,
       sal,
       case when sal>=10000
            then substr('零壹贰叁肆伍陆柒捌玖',trunc(mod(sal,100000)/10000)+1,1)||'万'
            else ''
       end ||       
       CASE WHEN sal >= 1000
            THEN SUBSTR('零壹贰叁肆伍陆柒捌玖', TRUNC(MOD(sal,10000)/1000)+1, 1) || '仟'
            ELSE ''
       END ||
       CASE WHEN sal >= 100
            THEN SUBSTR('零壹贰叁肆伍陆柒捌玖', TRUNC(MOD(sal,1000)/100)+1, 1) || '佰'
            ELSE ''
       END ||
       CASE WHEN sal >= 10
            THEN SUBSTR('零壹贰叁肆伍陆柒捌玖', TRUNC(MOD(sal,100)/10)+1, 1) || '拾'
            ELSE ''
       END ||
       CASE WHEN sal >= 1
            THEN SUBSTR('零壹贰叁肆伍陆柒捌玖', MOD(sal,10)+1, 1) || '元'
            ELSE '零元'
       END AS sal_cn
FROM   emp
ORDER  BY empno;