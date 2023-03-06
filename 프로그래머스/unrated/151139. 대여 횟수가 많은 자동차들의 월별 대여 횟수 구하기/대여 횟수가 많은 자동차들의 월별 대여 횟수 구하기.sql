select month(START_DATE) as MONTH, CAR_ID, count(CAR_ID) as RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where date_format(START_DATE, "%Y-%m") between '2022-08' and '2022-10' and CAR_ID in (
    select CAR_ID
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where date_format(START_DATE, "%Y-%m") between '2022-08' and '2022-10'
    group by CAR_ID
    having count(CAR_ID) >= 5
)
group by CAR_ID, month(START_DATE)
order by MONTH, CAR_ID desc;