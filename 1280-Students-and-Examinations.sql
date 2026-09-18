# Write your MySQL query statement below
WITH combined AS(
    SELECT s.student_id, s.student_name, sub.subject_name , e.subject_name AS exam_subject FROM Students s
    CROSS JOIN Subjects sub
    LEFT JOIN Examinations e
    ON s.student_id = e.student_id AND
    e.subject_name = sub.subject_name
) 

SELECT student_id,
student_name, 
subject_name, 
COUNT(exam_subject) AS attended_exams
FROM combined
GROUP BY student_id, student_name, subject_name
ORDER BY student_id, subject_name;