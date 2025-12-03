-- Write your PostgreSQL query statement below



SELECT c_id as customer_id  FROM

(SELECT customer_id as c_id,p.product_key as p_key FROM Customer as c RIGHT JOIN Product as p ON c.product_key=p.product_key GROUP BY c_id,p_key) as sub_table


GROUP BY c_id

HAVING count(*)=(SELECT count(DISTINCT product_key) FROM  Product )