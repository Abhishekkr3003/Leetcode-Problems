# Write your MySQL query statement below
select u.user_id as buyer_id, u.join_date, count(o.order_id) as orders_in_2019 from
Users as u left join (select order_id, buyer_id from Orders where order_date like '2019%') as o on u.user_id=o.buyer_id
group by u.user_id, u.join_date
order by user_id;

# select order_id, buyer_id from Orders where order_date like '2019%'