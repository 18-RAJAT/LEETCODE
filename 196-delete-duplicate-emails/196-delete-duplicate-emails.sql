# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below

delete p from person p,person as r where p.email=r.email and p.id>r.id