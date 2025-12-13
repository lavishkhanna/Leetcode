SELECT activity_date as day, count(DISTINCT user_id) as active_users FROM Activity
WHERE activity_date > TO_DATE('2019-07-27','YYYY-MM-DD') - INTERVAL '30 DAY' AND 
activity_date<='2019-07-27'
GROUP BY activity_date
