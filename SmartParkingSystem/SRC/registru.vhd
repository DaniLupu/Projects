library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL; 
 
entity registru is  
	port(D, Clk, EN, RS : in std_logic;    
        Q : out std_logic);  
end registru; 

architecture arch_reg of registru is  
signal aux : std_logic;
begin  
    process (Clk, RS)  
    begin  
        if (RS='1') then  
          aux <= '0';  
        elsif (Clk'event and Clk='1')then  
        	if (EN='1') then  
            	aux <= D;  
        	end if;  
        end if;  
    Q <= aux;
	end process;  
end arch_reg; 