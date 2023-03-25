library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL; 

entity poarta_not is
	port (A: in STD_LOGIC;
      	B: out STD_LOGIC);
end poarta_not;

architecture comportamental of poarta_not is
begin
	B <= NOT A;
end comportamental;