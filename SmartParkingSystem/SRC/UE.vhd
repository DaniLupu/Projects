library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL; 

entity ue is
	port( Senzor_1, Senzor_2, Senzor_3, Senzor_4, Senzor_5, Senzor_6, Senzor_7, Senzor_8 : in std_logic; 
	Clk1 : in std_logic;
	Afisor_Fortat : in std_logic_vector (7 downto 0);
	Rst : in std_logic;
	Afisor : out std_logic_vector (7 downto 0);
	Intrare_1, Intrare_2, Iesire_1, Iesire_2 : out std_logic);
end entity;

architecture structurala of ue is
signal out_intrare1, out_intrare2 : std_logic;
signal out_iesire1, out_iesire2 : std_logic;
signal out_dmux1, out_dmux2, out_dmux3 : std_logic_vector (3 downto 0);
signal out_d1, out_d2 : std_logic;
signal out_or1, out_or2, out_or3, out_or4 : std_logic;
signal out_num1 : std_logic_vector (7 downto 0);

begin
	intrarea1 : entity work.ordine_senzori port map ( Senzor1 => Senzor_1, Senzor2 => Senzor_2, Clock => Clk1, Reset => Rst, Iesire => out_intrare1	);
	intrarea2 : entity work.ordine_senzori port map ( Senzor1 => Senzor_5, Senzor2 => Senzor_6, Clock => Clk1, Reset => Rst, Iesire => out_intrare2	);
	iesirea1 : entity work.ordine_senzori port map ( Senzor1 => Senzor_3, Senzor2 => Senzor_4, Clock => Clk1, Reset => Rst, Iesire => out_iesire1 );
	iesirea2 : entity work.ordine_senzori port map ( Senzor1 => Senzor_7, Senzor2 => Senzor_8, Clock => Clk1, Reset => Rst, Iesire => out_iesire2 );
	dmux1 : entity work.dmux_1_4 port map ( F => '1', S0 => out_iesire1, S1 => out_iesire2, A => out_dmux1(0), B => out_dmux1(1), C => out_dmux1(2), D => out_dmux1(3) );
	dmux2 : entity work.dmux_1_4 port map ( F => '1', S0 => out_intrare1, S1 => out_intrare2, A => out_dmux2(0), B => out_dmux2(1), C => out_dmux2(2), D => out_dmux2(3) );
	d1 : entity work.bistabil_d port map ( D => out_dmux1(3), RS => Rst, Clk => Clk1, Q =>	out_d1 );
	d2 : entity work.bistabil_d port map ( D => out_dmux2(3), RS => Rst, Clk => Clk1, Q =>	out_d2 );
	or1 : entity work.poarta_or4 port map ( A => out_dmux1(1), B => out_dmux1(2), C => out_dmux1(3), D => out_d1, X => out_or1 );
	or2 : entity work.poarta_or4 port map ( A => out_dmux2(1), B => out_dmux2(2), C => out_dmux2(3), D => out_d2, X => out_or2 );
	dmux3 : entity work.dmux_1_4 port map ( F => '1', S0 => out_or1, S1 => out_or2, A => out_dmux3(0), B => out_dmux3(1), C => out_dmux3(2), D => out_dmux3(3) );
	or3 : entity work.poarta_or2 port map ( A => out_dmux3(1), B => out_dmux3(2), X => out_or3 );
	or4 : entity work.poarta_or2 port map ( A => out_dmux3(2), B => Rst, X => out_or4 );
	num1 : entity work.num_rev port map ( CLK => Clk1, Count => out_or3, LD => out_or4, D => Afisor_Fortat, Q => out_num1 );
	Afisor <= out_num1;
	Intrare_1 <= out_intrare1;
	Intrare_2 <= out_intrare2;
	Iesire_1 <= out_iesire1;
	Iesire_2 <= out_iesire2;
end architecture;
	
		
	