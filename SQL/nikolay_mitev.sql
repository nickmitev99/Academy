--INSERT INTO ORDERS2 VALUES (101, '08-10-2012', 3, 20000);
--INSERT INTO ORDERS2 VALUES (102, '08-11-2012', 2, 37000.5);
--INSERT INTO ORDERS2 VALUES (103, '10-12-2013', 4, 47000.5);
--INSERT INTO ORDERS2 VALUES (105, '07-11-2014', 3, 30000);
--
--ALTER TABLE Customers2
--DROP COLUMN Email;
--
--ALTER TABLE Customers2
--ADD Email varchar(255);

--ALTER TABLE Customers2
--MODIFY address varchar(30);

--ALTER TABLE Customers2
--RENAME COLUMN address TO city;

--RENAME Customers2 TO Customers3;

--SELECT Customers2.CustomerID, Customers2.fname, Orders2.amount, orders2."date"
--FROM Customers2
--INNER JOIN Orders2
--ON Customers2.CustomerID = Orders2.Customer_ID;

--SELECT Customers2.CustomerID, Customers2.fname, Orders2.amount, orders2."date"
--FROM Customers2
--LEFT JOIN Orders2
--ON Customers2.CustomerID = Orders2.Customer_ID;

--SELECT Customers2.CustomerID, Customers2.fname, Orders2.amount, orders2."date"
--FROM Customers2
--RIGHT JOIN Orders2
--ON Customers2.CustomerID = Orders2.Customer_ID;

--SELECT Orders2.amount, orders2."date", Customers2.CustomerID, Customers2.fname
--FROM Orders2
--RIGHT JOIN Customers2
--ON Orders2.Customer_ID = Customers2.CustomerID;

--SELECT Customers2.CustomerID, Customers2.fname, Orders2.amount, orders2."date"
--FROM Customers2
--LEFT JOIN Orders2
--ON Customers2.CustomerID = Orders2.Customer_ID
--WHERE Orders2.Customer_ID IS NULL
--ORDER BY Customers2.CustomerID;

--SELECT c.CUSTOMERID, c.FNAME, c.SALARY, b.fname, b.SALARY
--FROM CUSTOMERS2 c, CUSTOMERS2 b
--WHERE (c.salary < b.salary) AND (c.CUSTOMERID = 2);

--SELECT c.CUSTOMERID, c.FNAME, c.city, b.fname, b.city
--FROM CUSTOMERS2 c, CUSTOMERS2 b
--WHERE (c.city = b.city) AND (c.CUSTOMERID = 2);

--SELECT Customers2.CustomerID, Customers2.fname, Orders2.amount, orders2."date"
--FROM Customers2 CROSS JOIN Orders2
--ORDER BY CustomerID;

--SELECT Customers2.CustomerID, Customers2.fname, Orders2.amount, orders2."date"
--FROM Customers2
--FULL JOIN Orders2
--ON Customers2.CustomerID = Orders2.Customer_ID;
--
--SELECT Customers2.CustomerID, Customers2.fname, Orders2.amount, orders2."date"
--FROM Customers2
--LEFT JOIN Orders2
--ON Customers2.CustomerID = Orders2.Customer_ID
--    UNION
--SELECT Customers2.CustomerID, Customers2.fname, Orders2.amount, orders2."date"
--FROM Customers2
--RIGHT JOIN Orders2
--ON Customers2.CustomerID = Orders2.Customer_ID;

--SELECT Customers2.CustomerID, Customers2.salary FROM Customers2
--UNION
--SELECT Orders2.Customer_ID, Orders2.amount FROM ORDERS2;

--SELECT Customers2.CustomerID, Customers2.salary FROM Customers2
--UNION ALL
--SELECT Orders2.Customer_ID, Orders2.amount FROM ORDERS2;

--UPDATE ORDERS2 SET AMOUNT = 2700 WHERE OID = 101;
--UPDATE ORDERS2 SET AMOUNT = 37000.5 WHERE OID = 102;
--
--SELECT Customers2.CustomerID, Customers2.salary FROM Customers2
--INTERSECT
--SELECT Orders2.Customer_ID, Orders2.amount FROM ORDERS2;

--UPDATE ORDERS2 SET AMOUNT = 2700 WHERE OID = 101;
--
--SELECT Customers2.CustomerID, Customers2.salary FROM Customers2
--WHERE EXISTS(
--SELECT * FROM Orders2
--WHERE Orders2.CUSTOMER_ID = Customers2.CustomerID
--AND Orders2.Amount = Customers2.Salary);

--SELECT Customers2.CustomerID, Customers2.salary FROM Customers2
--MINUS
--SELECT Orders2.Customer_ID, Orders2.amount FROM ORDERS2;

--SELECT Customers2.CustomerID, Customers2.salary FROM Customers2
--MINUS
--SELECT Orders2.Customer_ID, Orders2.amount FROM ORDERS2;
--
--SELECT Customers2.CustomerID, Customers2.salary FROM Customers2
--WHERE NOT EXISTS(
--SELECT * FROM Orders2
--WHERE Orders2.CUSTOMER_ID = Customers2.CustomerID
--AND Orders2.Amount = Customers2.Salary);

--UPDATE Orders2 SET AMOUNT = 2700 WHERE OID = 101;
--
--SELECT Customers2.CustomerID, Customers2.salary FROM Customers2
--MINUS
--SELECT Orders2.Customer_ID, Orders2.amount FROM ORDERS2;
--
--SELECT Customers2.CustomerID, Customers2.salary FROM Customers2
--WHERE NOT EXISTS(
--SELECT * FROM Orders2
--WHERE Orders2.CUSTOMER_ID = Customers2.CustomerID
--AND Orders2.Amount = Customers2.Salary);



--УПРАЖНЕНИЕ
--CREATE TABLE Salespeople(
--    snum NUMBER,
--    sname VARCHAR(20),
--    city VARCHAR(20) DEFAULT 'London',
--    comm NUMBER(10,2)CHECK(comm < 1)
--);
--
--INSERT ALL
-- INTO Customers VALUES(100001, 'John', 'Doe', 19, 'Software', 1900, 'London', 'UK')
-- INTO Customers VALUES(100002, 'Francis', 'Hoffman', 34, 'Hardware', 3500, 'Berlin', 'Germany')
-- INTO Customers VALUES(100003, 'Georgy', 'Georgiev', 29, 'Software', 2100, 'Sofia', 'Bulgaria')
-- INTO Customers VALUES(100004, 'Guedo', 'Lopess', 21, 'Engineering', 4900, 'Mexico', NULL)
-- INTO Customers VALUES(100005, 'Jeremy', 'Bowers', 43, 'Shipping', 5500, 'London', 'UK')
--SELECT 1 FROM DUAL;
--
--INSERT ALL
-- INTO Salespeople VALUES(1001, 'Doe', 'New York', .12)
-- INTO Salespeople VALUES(1002, 'Hoffman', NULL, 0.14)
-- INTO Salespeople(snum,sname, comm) VALUES(1003, 'Georgiev', .12)
-- INTO Salespeople(snum,sname, comm) VALUES(1004, 'Lopess', .02)
--SELECT 1 FROM DUAL;


--SELECT CustomerID, Firstname, age AS "age_of_customer", age AS "Age of Customer", city FROM Customers;

--SELECT firstname FROM Customers c;

--SELECT CustomerID AS ID, Firstname, Age, City FROM Customers
--WHERE City = 'Sofia';

--SELECT CustomerID AS ID, Firstname, Age, City FROM Customers
--WHERE NOT City = 'Sofia';

--SELECT CustomerID AS ID, Firstname, Age, City, Salary FROM Customers
--WHERE City = 'London' AND Salary < 3000;

--SELECT CustomerID AS ID, Firstname, Age, City, Salary FROM Customers
--WHERE City = 'London' OR Salary < 3000;

--SELECT CustomerID AS ID, Firstname, Age, City, Salary FROM Customers
--WHERE City = 'Sofia' OR Salary != 3500;

--SELECT Firstname, Salary, Salary*1.2 AS "New Salary" FROM Customers
--WHERE Salary*1.2 > 3000;

--SELECT * FROM Customers
--WHERE City IN ('London', 'Mexico');

--SELECT * FROM Salespeople
--WHERE comm BETWEEN 0.02 AND 0.12;

--SELECT * FROM Customers
--WHERE City LIKE '%n';

--SELECT * FROM Customers
--WHERE City LIKE '%n' OR Country IS NULL;

--SELECT SUM(Salary), AVG(Salary), MAX(Salary), MIN(Salary) FROM Customers;

--SELECT DISTINCT(City) FROM Customers;
--
--SELECT COUNT(DISTINCT(City)) FROM Customers;

--SELECT firstname FROM Customers
--ORDER BY firstname;

--SELECT firstname, salary FROM Customers
--ORDER BY salary DESC;

--SELECT firstname, salary*1.4 FROM Customers
--WHERE salary*1.4 > 3100
--ORDER BY salary*1.4 DESC;

--SELECT city, AVG(salary) as "AVERAGE SALARY", COUNT(*) as employees FROM Customers
--GROUP BY city;

--SELECT department, SUM(salary) as Total_salary FROM Customers
--GROUP BY department;

--SELECT c.CustomerID, c.firstname, c.lastname, s.city, s.comm 
--FROM Customers c
--INNER JOIN Salespeople s
--ON c.lastname = s.sname;

--SELECT c.customerid, c.firstname, c.lastname, s.city
--FROM Customers c
--LEFT JOIN Salespeople s
--ON c.lastname = s.sname
--WHERE s.city IS NULL

--SELECT c.customerid, c.firstname, c.lastname, s.city
--FROM Salespeople s
--RIGHT JOIN Customers c
--ON c.lastname = s.sname
--WHERE s.city IS NOT NULL;

--SELECT c.customerid, c.firstname, c.lastname, s.city
--FROM Customers c
--LEFT JOIN Salespeople s
--ON c.lastname = s.sname
--WHERE s.city IS NULL
--UNION
--SELECT c.customerid, c.firstname, c.lastname, s.city
--FROM Salespeople s
--RIGHT JOIN Customers c
--ON c.lastname = s.sname
--WHERE s.city IS NOT NULL;
--
--SELECT c.customerid, c.firstname, c.lastname, s.city
--FROM Customers c
--FULL JOIN Salespeople s
--ON c.lastname = s.sname;

--INSERT INTO Salespeople VALUES(1005, 'Pierre', 'Paris', .05);

--SELECT s.sname
--FROM Salespeople s
--    WHERE s.sname IN (SELECT c.lastname 
--    FROM Customers c
--    WHERE c.age < 25);

--SELECT CustomerID, Firstname, Lastname, city, salary FROM Customers
--WHERE city IN(SELECT city
--FROM Customers
--GROUP BY city
--HAVING AVG(salary) > 3000);
    


--ЛЕКЦИИ
--CREATE OR REPLACE PROCEDURE insert_cust_hristina(id2 int, age2 int)
--AS
--BEGIN
--    INSERT INTO customers2(customerid, fname, age, city, salary)
--    VALUES(id2, 'Hristina55', age2, 'Burgas', 3333);
--END;
--/--seperate procedures
--CREATE PROCEDURE insert_cust_hristina2
--AS
--BEGIN
--    INSERT INTO customers2(customerid, fname, age, city, salary)
--    VALUES(222, 'Hristina55', 23, 'Sofia', 2222);
--END;

--exec insert_cust_hristina(222, 55);
--exec insert_cust_hristina2;
--
--drop procedure insert_cust_hristina;
--drop procedure insert_cust_hristina2;
--
--DELETE from Customers2
--WHERE customerid = 222;

--CREATE OR REPLACE TRIGGER ins_comm
--BEFORE INSERT ON SALESPEOPLE
--    FOR EACH ROW
--        BEGIN
--            :NEW.comm := :NEW.comm*11;
--        END;
--/
--INSERT ALL
--INTO Salespeople
--VALUES(1007, 'Smith', 'Maputo', 0.08)
--INTO Salespeople
--VALUES(1008, 'Petrov', 'Pernik', 0.1)
--SELECT 1 FROM DUAL;

--CREATE TABLE Orders2_copy(
--    OID NUMBER NOT NULL,
--    "date" DATE NOT NULL,
--    Customer_ID NUMBER NOT NULL,
--    Amount NUMBER NOT NULL,
--    "SYSDATE" DATE NOT NULL,
--    COUNTOFUPDATES NUMBER DEFAULT 0
--);

--CREATE OR REPLACE TRIGGER update_order BEFORE UPDATE OF amount ON orders2
--    FOR EACH ROW
--        BEGIN
--            INSERT INTO orders2_copy
--            VALUES(
--            :OLD."OID",
--            :OLD."date",
--            :OLD.Customer_ID,
--            :OLD.amount,
--            SYSDATE,
--            1 + (SELECT COUNT(*) FROM orders2_copy)
--            );
--        END;

--UPDATE orders2 SET amount = 1000;
--
--SELECT * FROM orders2;
--SELECT * FROM orders2_copy;

--CREATE OR REPLACE PROCEDURE saveandupdate(orderID NUMBER, new_amount NUMBER) AS
--BEGIN
--    INSERT INTO orders2_copy
--    ("OID", "date", customer_id, amount, sysdate, countofupdates)
--    (SELECT "OID", "date", customer_id, amount, sysdate, ( (SELECT MAX(countofupdates) FROM orders2_copy) + 1 ) FROM orders2
--    WHERE orders2."OID" = orderID);
--    
--    UPDATE orders2 SET orders2.amount = new_amount
--    WHERE orders2."OID" = orderID;
--END;

--EXECUTE saveandupdate(101, 100);


--ЛЕКЦИИ 22.12.21
--CREATE INDEX idx_customers_lname ON Customers( ( LOWER(Lastname) ) DESC);
--
--DROP INDEX idx_customers_lname;

--CREATE INDEX idx_c_Last ON Customers(lastname);
--CREATE INDEX idx_s_sname ON Salespeople(sname);

--CREATE OR REPLACE VIEW custs AS 
--SELECT customers.firstname, customers.lastname, customers.city, customers.department, salespeople.city as city_in_charge, salespeople.comm
--FROM customers
--LEFT JOIN salespeople
--ON customers.lastname = salespeople.sname;
--
--SELECT * FROM cuss;

--
--CREATE OR REPLACE VIEW cust_comm AS
--SELECT firstname, lastname, department, comm
--FROM custs
--WHERE comm > 0.05;

--SELECT  *
--FROM    all_indexes
--WHERE table_name = 'CUSTOMERS';

--SELECT * FROM cust_comm;

--CREATE OR REPLACE VIEW custs_sub AS 
--SELECT firstname, lastname, city, department
--FROM Customers
--WHERE customers.lastname IN (SELECT sname FROM Salespeople
--        WHERE comm > 0.08);
--
--SELECT * FROM custs_sub;


--ЛЕКЦИЯ 05.01.2022

--CREATE SEQUENCE Types_seq;
--CREATE SEQUENCE Supp_seq;
--
--CREATE TABLE "Types"
--(
--    ID INT DEFAULT (Types_seq.NEXTVAL) NOT NULL,
--    Name VARCHAR(30),
--    PRIMARY KEY(ID)
--);
--
--CREATE FUNCTION increm_seq RETURN NUMBER IS
--BEGIN
--    RETURN Types_seq.NEXTVAL;
--END;
--/
--INSERT ALL
--INTO "Types"(ID, NAME)
--VALUES(increm_seq, 'Name1')
--INTO "Types"(ID, NAME)
--VALUES(increm_seq, 'Name2')
--INTO "Types"(ID, NAME)
--VALUES(increm_seq, 'Name3')
--SELECT * FROM DUAL;

--SELECT CEIL(comm), comm FROM Salespeople;
--SELECT FLOOR(comm), comm FROM Salespeople;
--SELECT TRUNC(comm, 1) AS TRUNCATED, comm FROM Salespeople;
--SELECT ROUND(comm, 1) AS TRUNCATED, comm FROM Salespeople;
--SELECT SIGN(comm), comm FROM Salespeople;
--
--SELECT ASCII(SNAME) AS  ASCII, CHR(ASCII(SNAME)) AS "CHAR" FROM Salespeople;
--SELECT CONCAT('$', TO_CHAR(comm)) FROM Salespeople;
--SELECT TO_CHAR(comm) FROM Salespeople;
--
--SELECT REPLACE('aabbaabbaa', 'aa', 'cc') FROM DUAL;
--
--SELECT TRANSLATE('2KRW229', 
--'0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ', 
--'0000000000**********X***************') AS Translation FROM DUAL;
--
--SELECT TRIM(BOTH 'M' FROM 'M_M or IBM') AS Trimmed FROM DUAL;


--Лекция 07.01.2022
--SELECT TO_CHAR(SYSDATE, 'DAY') DAY_NAME, TO_CHAR(SYSDATE, 'Day') "day_name" FROM DUAL;
--SELECT TO_CHAR(SYSDATE, 'MONTH') MONTH_NAME, TO_CHAR(SYSDATE, 'Month') "month_name" FROM DUAL;
--
--SELECT MONTHS_BETWEEN(TO_DATE('04-26-2020', 'MM-DD-YYYY'), TO_DATE('01-26-2020', 'MM-DD-YYYY')) MONTHS_IN_BETWEEN FROM DUAL;
--
--SELECT TO_DATE('26/04/65', 'DD/MM/RR') "Date" FROM DUAL;
--
--SELECT '4' || 5 CONCAT, ASCII('A') + 5 SUM FROM Dual;
--
--SELECT TO_CHAR(-1234, '9999PR') "-PR", TO_CHAR(1234, '9999PR') PR, TO_CHAR(-1234, '9999MI') "-MI", TO_CHAR(1234, '9999MI') MI FROM DUAL;
--
--SELECT firstname, DECODE(lastname, 'Doe', 'D', 'Lopess', 'L', lastname) DECODE FROM Customers;
--
--SELECT firstname, lastname, NVL(country, 'Undefined') NVL 
--FROM Customers
--ORDER BY firstname, lastname;
--
--SELECT firstname, lastname, DECODE(country, NULL, 'Undefined', country) DECODE_NVL 
--FROM Customers
--ORDER BY firstname, lastname;
--
--SELECT MOD(5, 3) REM FROM DUAL;


--ДОМАШНА РАБОТА


--CREATE SEQUENCE Stud_seq 
--MINVALUE 10000 
--MAXVALUE 19999 
--START WITH 10001;
--/
--CREATE OR REPLACE FUNCTION STUD_SEQ_INCREM 
--RETURN NUMBER IS
--BEGIN
--    RETURN Stud_seq.NEXTVAL;
--END;
--/
--CREATE SEQUENCE Course_seq 
--MINVALUE 20000 
--MAXVALUE 29999 
--START WITH 20001;
--/
--CREATE OR REPLACE FUNCTION COURSE_SEQ_INCREM 
--RETURN NUMBER IS
--BEGIN
--    RETURN Course_seq.NEXTVAL;
--END;
--/
--CREATE TABLE Students2
--(
--    STUDID NUMBER DEFAULT(Stud_seq.nextval) NOT NULL,
--    FNAME VARCHAR2(30) NOT NULL,
--    LNAME VARCHAR2(30) NOT NULL,
--    UNIVERSITY VARCHAR(30) NOT NULL,
--    COUNTRY VARCHAR(30) NOT NULL,
--    CITY VARCHAR(30) NOT NULL,
--    PRIMARY KEY(STUDID)
--);
--
--CREATE TABLE Courses
--(
--    COURSE_ID NUMBER NOT NULL,
--    COURSE_NAME VARCHAR(30),
--    PRIMARY KEY(COURSE_ID)
--);
--
--CREATE TABLE Attendance
--(
--    STUDID NUMBER NOT NULL,
--    COURSE_ID NUMBER NOT NULL,
--    D_START DATE,
--    D_END DATE
--);
--
--INSERT ALL
--INTO Students2 VALUES(STUD_SEQ_INCREM, 'Nikolay', 'Mitev', 'TU Sofia', 'Bulgaria', 'Burgas')
--INTO Students2 VALUES(STUD_SEQ_INCREM, 'Dobri', 'Hristov', 'UNSS', 'Bulgaria', 'Sofia')
--INTO Students2 VALUES(STUD_SEQ_INCREM, 'Dancho', 'Stanev', 'TU Varna', 'Bulgaria', 'Kalofer')
--INTO Students2 VALUES(STUD_SEQ_INCREM, 'John', 'Smith', 'Harvard University', 'USA', 'New York')
--INTO Students2 VALUES(STUD_SEQ_INCREM, 'Dean', 'Henderson', 'Cambridge University', 'UK', 'Watford')
--SELECT * FROM DUAL;
--
--INSERT ALL
--INTO Courses VALUES(COURSE_SEQ_INCREM, 'Software Engineering')
--INTO Courses VALUES(COURSE_SEQ_INCREM, 'Law')
--INTO Courses VALUES(COURSE_SEQ_INCREM, 'Telecommunications')
--SELECT * FROM DUAL;
--
--INSERT ALL
--INTO Attendance VALUES('10006', '20003', '26-09-2018', '30-05-2022')
--INTO Attendance VALUES('10007', '20002', '20-09-2020', '05-06-2024')
--INTO Attendance VALUES('10008', '20001', '12-10-2012', '01-06-2016')
--INTO Attendance VALUES('10009', '20003', '01-03-2018', '20-09-2022')
--INTO Attendance VALUES('10010', '20001', '03-04-2018', '21-10-2022')
--SELECT * FROM DUAL;
--
--INSERT ALL
--INTO Attendance VALUES('10006', '20001', '26-09-2018', '30-05-2022')
--INTO Attendance VALUES('10007', '20003', '20-09-2020', '05-06-2024')
--INTO Attendance VALUES('10008', '20002', '12-10-2012', '01-06-2016')
--SELECT * FROM DUAL;
--
--CREATE OR REPLACE VIEW DETAILED AS
--SELECT
--    Students2.STUDID AS Student_ID,
--    Students2.FNAME AS Firstname,
--    Students2.LNAME AS Lastname,
--    Students2.University AS University,
--    Students2.Country AS Country,
--    Students2.City AS City,
--    Courses.COURSE_NAME AS Course_Name,
--    Attendance.D_START AS Date_Started,
--    Attendance.D_END AS Date_Ended,
--    MONTHS_BETWEEN(Attendance.D_END, Attendance.D_START) AS Course_Duration
--FROM Attendance
--LEFT JOIN Students2
--ON Students2.STUDID = Attendance.STUDID
--LEFT JOIN Courses
--ON Courses.Course_ID = Attendance.Course_ID
--ORDER BY Students2.STUDID;
--
--CREATE OR REPLACE VIEW SIMPLE AS
--SELECT
--    Students2.FNAME AS Firstname,
--    Students2.LNAME AS Lastname,
--    COUNT(Attendance.Course_ID) AS Number_of_courses
--FROM STUDENTS2
--LEFT JOIN Attendance
--ON Students2.STUDID = Attendance.STUDID
--GROUP BY Students2.FNAME, Students2.LNAME
--ORDER BY Students2.FNAME, Students2.LNAME;
--
--SELECT * FROM DETAILED;
--SELECT * FROM SIMPLE;


--Упражнение от 12.01.2022
--CREATE TABLE T_Chefs(
--    ID   int NOT NULL,
--    Name varchar(45) NOT NULL,
--    PRIMARY KEY(ID)
--);
--
--CREATE TABLE T_Dish_origin(
--    ID   int NOT NULL,
--    Name varchar(45) NOT NULL,
--    PRIMARY KEY (ID)
--);
--
--CREATE TABLE T_Dish_type(
--    ID   int NOT NULL,
--    Name varchar(45) NOT NULL,
--    PRIMARY KEY (ID)
--);
--
--CREATE TABLE T_Product_types(
--    ID   int NOT NULL,
--    Name varchar(45) NOT NULL,
--    PRIMARY KEY (ID)
--);
--
--CREATE TABLE T_Dishes(
--    ID     int NOT NULL,
--    Name   varchar(45) NOT NULL,
--    Type   int NOT NULL REFERENCES T_Dish_type(ID),
--    Origin int NOT NULL REFERENCES T_Dish_origin(ID),
--    Chef   int NOT NULL REFERENCES T_Chefs(ID),
--    PRIMARY KEY (ID)
--);
--
--CREATE TABLE T_Products(
--    ID         int NOT NULL,
--    Name       varchar(45) NOT NULL,
--    Type       int NOT NULL REFERENCES T_Product_types(ID),
--    Unit_grams int NOT NULL,
--    Calories   int NOT NULL,
--    Unit_price number(6,2) NOT NULL,
--    PRIMARY KEY (ID)
--);
--
--CREATE TABLE T_Recipe(
-- Dish      int NOT NULL REFERENCES T_Dishes (ID),
-- Product   int NOT NULL REFERENCES T_Products (ID),
-- Units     int NOT NULL,
-- DateAdded date NOT NULL
--);

--CREATE SEQUENCE T_SEQ_CHEFS
--MINVALUE 10001
--MAXVALUE 19999
--NOCACHE;
--
--CREATE SEQUENCE T_SEQ_DISH_ORIGIN
--MINVALUE 20001
--MAXVALUE 29999
--NOCACHE;
--
--CREATE SEQUENCE T_SEQ_DISH_TYPE
--MINVALUE 30001
--MAXVALUE 39999
--NOCACHE;
--
--CREATE SEQUENCE T_SEQ_DISHES
--MINVALUE 40001
--MAXVALUE 49999
--NOCACHE;
--
--CREATE SEQUENCE T_SEQ_PRODUCT_TYPES
--MINVALUE 50001
--MAXVALUE 59999
--NOCACHE;
--
--CREATE SEQUENCE T_SEQ_PRODUCTS
--MINVALUE 60001
--MAXVALUE 69999
--NOCACHE;

--INSERT ALL
--INTO t_product_types (name)
--VALUES('зеленчуци')
--INTO t_product_types (name)
--VALUES('яйца и млечни')
--INTO t_product_types (name)
--VALUES('месни')
--INTO t_product_types (name)
--VALUES('варива')
--INTO t_product_types (name)
--VALUES('подправки')
--INTO t_product_types (name)
--VALUES('вода')
--SELECT * FROM dual;

--INSERT ALL
--INTO t_chefs (name)
--VALUES('Иванов')
--INTO t_chefs (name)
--VALUES('Манчев')
--INTO t_chefs (name)
--VALUES('Пиер')
--SELECT * FROM dual;

--INSERT ALL
--INTO t_dish_type (name)
--VALUES('салата')
--INTO t_dish_type (name)
--VALUES('аламинут')
--INTO t_dish_type (name)
--VALUES('супа')
--INTO t_dish_type (name)
--VALUES('основно')
--SELECT * FROM dual;

--INSERT ALL
--INTO t_dish_origin (name)
--VALUES('България')
--INTO t_dish_origin (name)
--VALUES('Мексико')
--INTO t_dish_origin (name)
--VALUES('Франция')
--INTO t_dish_origin (name)
--VALUES('Великобритания')
--INTO t_dish_origin (name)
--VALUES('Турция')
--SELECT * FROM dual;

--CREATE OR REPLACE PROCEDURE T_PRODUCTS_INS
--(
--    Type VARCHAR2,
--    Prod VARCHAR2,
--    Weight NUMBER,
--    Energy NUMBER,
--    Price NUMBER
--)
--AS
--BEGIN
--    INSERT INTO T_PRODUCTS
--    SELECT NULL, Prod, ID, Weight, Energy, Price 
--    FROM T_PRODUCT_TYPES
--    WHERE Name LIKE Type;
--END;

--CREATE OR REPLACE PROCEDURE T_DISHES_INS
--(
--    Dish VARCHAR2,
--    Type VARCHAR2,
--    Orig VARCHAR2,
--    Che VARCHAR2
--)
--AS
--BEGIN
--    INSERT INTO T_DISHES
--    SELECT NULL, Dish, dt.ID, do.ID, c.ID
--    FROM T_DISH_TYPE dt, T_DISH_ORIGIN do, T_CHEFS c 
--    WHERE dt.Name LIKE Type 
--    AND do.Name LIKE Orig
--    AND c.Name LIKE Che;
--END;

--CREATE OR REPLACE Procedure T_RECIPE_INS
--(
--    Dish VARCHAR2,
--    Prod VARCHAR2,
--    Unit VARCHAR2,
--    "Date" DATE
--)
--AS
--BEGIN
--    INSERT INTO T_RECIPE
--    SELECT d.ID, p.ID, Unit, "Date" FROM T_PRODUCTS p, T_DISHES d
--    WHERE d.NAME LIKE Dish
--    AND p.NAME LIKE Prod;
--END;

--EXEC T_PRODUCTS_INS('%зел%', 'домати', 50, 30, 0.15);
--EXEC T_PRODUCTS_INS('%зел%', 'краставици', 50, 15, 0.2);
--EXEC T_PRODUCTS_INS('%зел%', 'чушки', 50, 20, 0.1);
--EXEC T_PRODUCTS_INS('%зел%', 'лук', 50, 10, 0.05);
--EXEC T_PRODUCTS_INS('%млеч%', 'сирене', 50, 100, 0.5);
--EXEC T_PRODUCTS_INS('%млеч%', 'яйце', 100, 80, 0.25);
--EXEC T_PRODUCTS_INS('%мес%', 'бекон', 100, 150, 1);
--EXEC T_PRODUCTS_INS('%вар%', 'зрял боб', 150, 120, 0.35);
--EXEC T_PRODUCTS_INS('%под%', 'олио', 10, 10, 0.04);
--EXEC T_PRODUCTS_INS('%под%', 'оцет', 5, 0, 0.01);
--EXEC T_PRODUCTS_INS('%под%', 'сол', 5, 0, 0.01);
--EXEC T_PRODUCTS_INS('вода', 'вода', 200, 0, 0.01);

--EXEC T_DISHES_INS('Шопска салата', '%сал%', '%Бъл%', '%Ив%');
--EXEC T_DISHES_INS('Краставици', '%сал%', '%Бъл%', '%Ив%');
--EXEC T_DISHES_INS('Бобена', '%сал%', '%Мек%', '%Ма%');
--EXEC T_DISHES_INS('Омлет със сирене', '%ала%', '%Фр%', '%Пи%');
--EXEC T_DISHES_INS('Яйца с бекон', '%ала%', '%Вел%', '%Пи%');
--EXEC T_DISHES_INS('Боб чорба', 'супа', '%Тур%', '%Ив%');
--EXEC T_DISHES_INS('Боб с бекон', '%осн%', '%Бъл%', '%Ма%');

--EXEC T_RECIPE_INS('%Шоп%', '%дом%', 2, SYSDATE);
--EXEC T_RECIPE_INS('%Шоп%', '%крас%', 2, SYSDATE);
--EXEC T_RECIPE_INS('%Шоп%', '%лук%', 1, SYSDATE);
--EXEC T_RECIPE_INS('%Шоп%', '%олио%', 1, SYSDATE);
--EXEC T_RECIPE_INS('%Шоп%', '%оцет%', 1, SYSDATE);
--EXEC T_RECIPE_INS('%Шоп%', '%сол%', 1, SYSDATE);
--EXEC T_RECIPE_INS('%Краст%', '%краст%', 3, SYSDATE);
--EXEC T_RECIPE_INS('%Краст%', '%олио%', 1, SYSDATE);
--EXEC T_RECIPE_INS('%Краст%', '%оцет%', 2, SYSDATE);
--EXEC T_RECIPE_INS('%Краст%', '%сол%', 1, SYSDATE);
--EXEC T_RECIPE_INS('%Бобена%', '%боб%', 1, SYSDATE);
--EXEC T_RECIPE_INS('%Бобена%', '%лук%', 1, SYSDATE);
--EXEC T_RECIPE_INS('%Бобена%', '%олио%', 2, SYSDATE);
--EXEC T_RECIPE_INS('%Бобена%', '%оцет%', 2, SYSDATE);
--EXEC T_RECIPE_INS('%Бобена%', '%сол%', 1, SYSDATE);

--CREATE OR REPLACE VIEW RECIPES AS
--SELECT dt.name AS "Type", d.name AS "Dish", c.name AS "Chef",
--r.units AS "Units", p.name AS "Product", p.Unit_grams AS "Unit_grams",
--p.calories AS "Calories", p.unit_price AS "Price"
--FROM T_RECIPE r
--INNER JOIN T_DISHES d ON d.ID = r.dish
--INNER JOIN T_DISH_TYPE dt ON dt.ID = d.type
--INNER JOIN T_CHEFS c ON c.ID = d.chef
--INNER JOIN T_PRODUCTS p ON p.ID = r.product
--ORDER BY d.name;
--
--SELECT * FROM RECIPES;
--
--CREATE OR REPLACE VIEW Menu AS
--SELECT "Dish", "Chef", SUM("Units" * "Calories") AS "Energy",
--SUM("Units" * "Unit_grams") AS "Weight", ROUND(SUM("Units" * "Price")*1.35, 2) AS "Price"
--FROM RECIPES
--GROUP BY "Dish", "Chef";
--
--SELECT * FROM Menu;