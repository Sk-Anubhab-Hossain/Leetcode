# Write your MySQL query statement below

WITH nxt_login AS(
SELECT player_id,
event_date,
MIN(event_date) OVER (PARTITION BY player_id) AS first_login,
LEAD(event_date) OVER (PARTITION BY player_id ORDER BY event_date ASC) AS nxt_date
FROM Activity
)

SELECT 
ROUND(SUM(CASE WHEN DATEDIFF(nxt_date, first_login) = 1 THEN 1 ELSE 0 END) / count(DISTINCT player_id),2) AS fraction
FROM nxt_login;


