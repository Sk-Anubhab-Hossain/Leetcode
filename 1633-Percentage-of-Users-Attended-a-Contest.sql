# Write your MySQL query statement below

SELECT r.contest_id,
ROUND(count(r.contest_id)*100/ (SELECT COUNT(*) FROM Users),2) AS percentage
FROM Users u
INNER JOIN Register r
ON r.user_id = u.user_id
GROUP BY contest_id
ORDER BY percentage DESC,
contest_id ASC;