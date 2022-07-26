# Write your MySQL query statement below
select u.name, 
    (case when sum(r.distance) is not null then sum(r.distance)
    else 0
    end) as travelled_distance
from Users as u left join Rides as r on u.id=r.user_id
group by u.id
order by travelled_distance desc, name asc;