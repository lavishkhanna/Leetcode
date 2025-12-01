-- Write your PostgreSQL query statement below

-- SELECT Visits.customer_id FROM Visits WHERE customer_id not in

-- (SELECT customer_id FROM Visits INNER JOIN Transactions ON Visits.visit_id=Transactions.visit_id)




SELECT customer_id,count(*) as count_no_trans FROM Visits LEFT JOIN Transactions ON Visits.visit_id=Transactions.visit_id

WHERE transaction_id is NULL

GROUP BY customer_id

