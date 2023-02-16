select ai.ANIMAL_ID as ANIMAL_ID, ai.NAME as NAME
from ANIMAL_INS ai
inner join ANIMAL_OUTS ao
on ai.ANIMAL_ID = ao.ANIMAL_ID
where ai.DATETIME > ao.DATETIME
order by ai.DATETIME asc;