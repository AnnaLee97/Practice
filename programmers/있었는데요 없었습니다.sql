   SELECT a.animal_id, a.name
     from ANIMAL_INS a
        , ANIMAL_OUTS b
    where a.animal_id = b.animal_id
      and a.datetime > b.datetime
 order by a.datetime
 ;
