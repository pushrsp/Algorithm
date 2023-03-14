select A.FLAVOR as FLAVOR
from FIRST_HALF A
join (
    select FLAVOR, sum(TOTAL_ORDER) as TOTAL_ORDER
    from JULY
    group by FLAVOR
) B
on A.FLAVOR = B.FLAVOR
order by (A.TOTAL_ORDER + B.TOTAL_ORDER) desc
limit 3;