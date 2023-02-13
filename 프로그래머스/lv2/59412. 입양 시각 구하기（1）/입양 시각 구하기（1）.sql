select HOUR(DATETIME) as HOUR, count(ANIMAL_ID) as COUNT
from ANIMAL_OUTS
where HOUR(DATETIME) >= 9 and HOUR(DATETIME) <= 19
group by HOUR(DATETIME)
order by HOUR asc;