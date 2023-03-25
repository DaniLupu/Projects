library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
 
entity dmux_1_4 is
	port(F : in STD_LOGIC;
 		S0, S1: in STD_LOGIC;
 		A,B,C,D: out STD_LOGIC);
end dmux_1_4;
 
architecture comportamentala of dmux_1_4 is
begin	
	process (F, S0, S1) is
	begin
		A <= '0'; 
		B <= '0'; 
		C <= '0';
		D <= '0';
 		if (S0 ='0' and S1 = '0') then
 			A <= F;
 		elsif (S0 ='1' and S1 = '0') then
 			B <= F;
 		elsif (S0 ='0' and S1 = '1') then
 			C <= F;
 		else
 			D <= F;
 		end if;
	end process;
end comportamentala;
