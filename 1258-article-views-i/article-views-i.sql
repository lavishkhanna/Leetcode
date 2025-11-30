-- Write your PostgreSQL query statement below
select DISTINCT(author_id) as id from Views
WHERE author_id=viewer_id
Order by author_id ASC