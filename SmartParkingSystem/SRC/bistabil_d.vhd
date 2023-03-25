Library IEEE;
USE IEEE.Std_logic_1164.all;

entity bistabil_d is 
   port( D, RS, Clk :in std_logic;  
   		Q : out std_logic);
end bistabil_D;

architecture comportamental of bistabil_d is  
begin  
	process(Clk, RS)
	begin 
    	if(RS = '1') then 
   			Q <= '0';
     	elsif (Clk'event and Clk = '1') then
   			Q <= D; 
  		end if;      
 	end process;  
end comportamental;