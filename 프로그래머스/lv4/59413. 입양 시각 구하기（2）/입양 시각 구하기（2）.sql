set @hour := -1;

select (@hour := @hour + 1) as HOUR,
(select COUNT(ANIMAL_ID) from ANIMAL_OUTS where HOUR(DATETIME) = @hour) as COUNT
from ANIMAL_OUTS
where @hour < 23;