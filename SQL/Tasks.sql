--за 1ва
--INSERT ALL
--INTO D_INDIVIDUAL
--VALUES(NULL, 'Kaufland', 'ltd', 2)
--INTO D_INDIVIDUAL
--VALUES(NULL, 'LIDL', 'OOD', 2)
--INTO D_INDIVIDUAL
--VALUES(NULL, 'Billa', 'EOOD', 2)
--SELECT * FROM DUAL;

--INSERT ALL
--INTO D_CONTACTS
--VALUES(NULL, 10014, 1, '0899224433', 1)
--INTO D_CONTACTS
--VALUES(NULL, 10015, 1, '0874322245', 1)
--INTO D_CONTACTS
--VALUES(NULL, 10016, 1, '0889213455', 1)
--SELECT * FROM DUAL;
--
--INSERT INTO D_INVOICES
--VALUES(NULL, 10016, 200, 3, '20-12-2020', '20-01-2021');

--за 4та
--INSERT INTO D_CONTACTS
--VALUES(NULL, 10001, 1, '0899224433', 0);
--INSERT INTO D_CONTACTS
--VALUES(NULL, 10001, 3, 'Sofia, zh.k. Studentski grad, bl.2', 0);

--за 5та
--INSERT ALL
--INTO D_CONTACTS
--VALUES(NULL, 10001, 2, 'spider_boy1@abv.bg', 0)
--INTO D_CONTACTS
--VALUES(NULL, 10010, 2, 'nqkoi@abv.bg', 0)
--SELECT * FROM DUAL


--1. Всички юридически, които са записани само с телефон и нямат издадени фактури.
SELECT indiv.FNAME, indiv.LNAME, con.contact
FROM D_INDIVIDUAL indiv
   , D_CONTACTS con
WHERE indiv.id = con.individual
AND indiv.type = 2
AND con.type = 1
AND NOT EXISTS (SELECT inv.id 
                FROM D_INVOICES inv
                WHERE inv.individual = con.individual
                );


--2. Списък с топ 5 длъжници(отворени към момента*)
SELECT *
FROM (SELECT indiv.fname, indiv.lname, SUM(inv.amount) AS DEBT FROM D_INVOICES inv, D_INDIVIDUAL indiv
      WHERE indiv.id = inv.individual
      GROUP BY indiv.fname, indiv.lname
      ORDER BY DEBT DESC)
WHERE ROWNUM <=5;


--3. Всички фактури между две дати.
SELECT indiv.fname, indiv.lname, inv.id AS INVOICE, inv.amount, invtp.value, inv.created, inv.due
FROM D_INVOICES inv, D_INDIVIDUAL indiv, D_INV_TYPE invtp
WHERE indiv.id = inv.individual
AND inv.type = invtp.type
AND inv.created BETWEEN '01-12-2021' AND '31-01-2022';

--4. Дебтора с най-много неактивни контакти.
SELECT * 
FROM (SELECT indiv.fname, indiv.lname, COUNT(con.contact) AS CONTACTS
      FROM D_INDIVIDUAL indiv, D_CONTACTS con
      WHERE indiv.id = con.individual
      AND con.status = 0
      GROUP BY indiv.fname, indiv.lname
      ORDER BY indiv.fname DESC)
WHERE ROWNUM = 1;


--5. Всички физически с домейн "abv.bg(" до някаква дата.
SELECT indiv.fname, indiv.lname, con.contact, SUM(inv.amount) AS OWED
FROM D_INDIVIDUAL indiv, D_CONTACTS con, D_INVOICES inv
WHERE indiv.id = con.individual
AND indiv.id = inv.individual
AND LOWER(con.contact) LIKE '%abv.bg'
AND inv.created <= '15-12-2021' --if changed to '20-12-2021' it will display an additional debtor
GROUP BY indiv.fname, indiv.lname, con.contact;

--6. Всички физически, които имат просрочени, нямат никакви плащания
SELECT indiv.fname, indiv.lname, SUM(inv.amount) AS OWED
FROM D_INDIVIDUAL indiv, D_INVOICES inv
WHERE indiv.id = inv.individual
AND indiv.type = 1
AND NOT EXISTS (SELECT m.invoice 
                FROM D_MATCHES m
                WHERE inv.id = m.invoice)
GROUP BY indiv.fname, indiv.lname;

--7. Всички на юридически лица под 20, които са нечетно ID.
SELECT indiv.fname, indiv.lname, inv.amount AS OWED
FROM D_INDIVIDUAL indiv, D_INVOICES inv
WHERE indiv.id = inv.individual
AND indiv.type = 2
AND MOD(inv.id, 2) != 0
AND inv.amount < 300;

--8. Списък на фактурите, които са просрочени с една падeжна дата(в някъв рейндж) и са само на физически лица. (по-които има извършени частични плащания*).
SELECT indiv.fname, indiv.lname, inv.due, SUM(inv.amount) AS OWED
FROM D_INDIVIDUAL indiv, D_INVOICES inv
WHERE indiv.id = inv.individual
AND indiv.type = 1
AND inv.due < ADD_MONTHS(SYSDATE, -1)
AND NOT EXISTS (SELECT m.invoice 
                         FROM D_MATCHES m
                         WHERE inv.id = m.invoice)
GROUP BY indiv.fname, indiv.lname, inv.due;