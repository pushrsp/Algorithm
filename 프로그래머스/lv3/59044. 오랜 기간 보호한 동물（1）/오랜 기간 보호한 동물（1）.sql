select ai.NAME as NAME, ai.DATETIME as DATETIME
from ANIMAL_INS ai
left join ANIMAL_OUTS ao
on ai.ANIMAL_ID = ao.ANIMAL_ID
where ao.ANIMAL_ID is NULL
order by ai.DATETIME asc
limit 3;