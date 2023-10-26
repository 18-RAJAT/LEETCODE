# Write your MySQL query statement below
# DENSE_RANK() function is a built-in ranking function in SQL that assigns a unique rank to each row within a result set, based on the values in one or more columns.

select score, 
DENSE_RANK() OVER(order by score desc) as "rank"
from Scores