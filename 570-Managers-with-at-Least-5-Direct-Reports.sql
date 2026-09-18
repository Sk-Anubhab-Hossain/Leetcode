# Write your MySQL query statement below



SELECT e.name
FROM Employee e
INNER JOIN Employee e1
ON e1.managerId = e.id
GROUP BY e1.managerID
HAVING count(e.id) >=5;