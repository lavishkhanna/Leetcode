-- Write your PostgreSQL query statement below



(SELECT name as results FROM 

(SELECT * FROM Users as u INNER JOIN MovieRating as m ON u.user_id=m.user_id) as sub_table

GROUP BY name

ORDER BY COUNT(*) DESC,name ASC

LIMIT 1)


UNION ALL

(
    SELECT title FROM

    (SELECT * FROM Movies as m 
    INNER JOIN MovieRating as mr ON m.movie_id=mr.movie_id) as sub_table_2

    WHERE created_at BETWEEN '2020-02-01' AND '2020-02-29'

    GROUP BY title

    ORDER BY AVG(rating) DESC, title ASC

    LIMIT 1



)