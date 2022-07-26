# Write your MySQL query statement below
select customer_number 
from Orders 
group by customer_number
having count(customer_number)=
(
    select max(count_number)
    from (
        select customer_number, count(customer_number) as count_number from Orders
        group by customer_number
         ) as t
);

# select max(count_number)
#     from (
#         select customer_number, count(customer_number) as count_number from Orders
#         group by customer_number
#          ) as t