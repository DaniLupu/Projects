library IEEE; 
use IEEE.STD_LOGIC_1164.all; 
use IEEE.STD_LOGIC_UNSIGNED.all;

entity num_rev is 
    port( CLK: in std_logic; 
        Count, LD: in std_logic;
        D: in std_logic_vector (7 downto 0);
        Q: out std_logic_vector (7 downto 0));
end num_rev; 

architecture comportamentala of num_rev is
--signal afisor: std_logic_vector (7 downto 0);
begin
    process (CLK, Count, LD)
        variable afisor: std_logic_vector (7 downto 0) := "ZZZZZZZZ";
		
		begin
            if (LD = '1') and (Count = '0') then afisor := D;
            elsif (Clk'event and CLK = '1') then
                if(Count = '1') and (LD = '0') then afisor := afisor + 1;
                    elsif (Count = '1') and (LD = '1') then afisor := afisor-1;
				else
                    afisor := afisor;
                end if;
            end if;
			
            Q <= afisor;
    end process;
end comportamentala;



