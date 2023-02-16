select ao.ANIMAL_ID as ANIMAL_ID, ao.NAME as NAME
from ANIMAL_OUTS ao
left join ANIMAL_INS ai
on ao.ANIMAL_ID = ai.ANIMAL_ID
where ai.ANIMAL_ID IS NULL
order by ANIMAL_ID asc, NAME asc;