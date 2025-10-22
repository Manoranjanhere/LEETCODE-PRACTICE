# Write your MySQL query statement below
select s.user_id,
    ROUND(IFNULL(sum(c.action ='confirmed')/COUNT(c.action),0),2) As confirmation_rate
    from signups s
    left join confirmations c
    on s.user_id = c.user_id
    group by s.user_id;