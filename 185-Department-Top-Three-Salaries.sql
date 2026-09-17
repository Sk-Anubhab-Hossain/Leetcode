# Write your MySQL query statement below

WITH combined AS (
    SELECT 
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary,
    DENSE_RANK() OVER(PARTITION BY d.name ORDER BY e.salary DESC) AS rnk
    FROM Employee e
    INNER JOIN Department d
    ON d.id=e.departmentId
)

SELECT Department, Employee, Salary
FROM combined
WHERE rnk<=3;