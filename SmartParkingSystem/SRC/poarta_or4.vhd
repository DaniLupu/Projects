library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity poarta_or4 is
    Port ( A, B, C, D : in  STD_LOGIC;
           X : out  STD_LOGIC);
end poarta_or4;

architecture comportamental of poarta_or4 is
begin
	X <= A or B or C or D;     
end comportamental;