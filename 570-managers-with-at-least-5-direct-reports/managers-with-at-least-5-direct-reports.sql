# Write your MySQL query statement below
SELECT B.name FROM Employee B
JOIN Employee A on B.id = A.managerId
GROUP BY A.managerId
HAVING COUNT(A.managerId) >= 5;