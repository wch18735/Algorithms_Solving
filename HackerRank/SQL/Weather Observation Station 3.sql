/* 
1. % -> MOD(Dividened, Divisor)
2. from -> where -> group by -> having -> select
3. count(* | DISTINCT | ALL)  
    - *: count null
    - DISTINCT: UNIQUE and Non-Null
    - ALL: Non-Null
*/
select CITY from STATION where MOD(ID, 2) = 0 group by CITY having count(distinct CITY) < 2;