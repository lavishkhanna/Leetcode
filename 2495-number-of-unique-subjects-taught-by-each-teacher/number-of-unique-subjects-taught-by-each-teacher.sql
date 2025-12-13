-- Write your PostgreSQL query statement below
SELECT teacher_id, count(DISTINCT subject_id) as cnt FROM Teacher

GROUP BY teacher_id  