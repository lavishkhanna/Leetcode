-- Write your PostgreSQL query statement below


SELECT
CASE 

WHEN id%2=0 then id-1
WHEN id%2=1 AND id!=(SELECT COUNT(DISTINCT id) FROM Seat) then id+1

ELSE id

END as id,student

FROM Seat

ORDER BY id