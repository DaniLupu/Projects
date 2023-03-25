library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;  

entity ordine_senzori is
	port( Senzor1, Senzor2, Clock : in std_logic;
	Reset : in std_logic;
	Iesire : out std_logic);
end entity;

architecture structurala of ordine_senzori is

signal out_nor1, out_nor2: std_logic;
signal not_senzor1, not_senzor2: std_logic;
signal out_and1, out_and2, out_and3, out_and4, out_and5, out_and6, out_and7 : std_logic;
signal out_reg1, out_reg2, out_reg3, out_reg4, out_reg5, out_reg6 : std_logic;
signal out_d1 : std_logic;
signal out_or1 : std_logic;

begin
	nor1 : entity work.poarta_nor2 port map ( A => Senzor1, B => Senzor2, X => out_nor1 );
	nor2 : entity work.poarta_nor2 port map ( A => Senzor1, B => Senzor2, X => out_nor2 );
	nsenzor1 : entity work.poarta_not port map ( A => Senzor1, B => not_senzor1 );
	nsenzor2 : entity work.poarta_not port map ( A => Senzor2, B => not_senzor2 );
	and1 : entity work.poarta_and2 port map ( A => out_reg1, B => out_and2, X => out_and1 );
	and2 : entity work.poarta_and2 port map ( A => Senzor1, B => not_senzor2, X => out_and2 );
	and3 : entity work.poarta_and2 port map ( A => out_reg2, B => out_and4, X => out_and3 );
	and4 : entity work.poarta_and2 port map ( A => Senzor1, B => Senzor2, X => out_and4 );
	and5 : entity work.poarta_and2 port map ( A => out_reg3, B => out_and6, X => out_and5 );
	and6 : entity work.poarta_and2 port map ( A => not_senzor1, B => Senzor2, X => out_and6 );
	and7 : entity work.poarta_and2 port map ( A => out_reg4, B => out_nor2, X => out_and7 );
	reg1 : entity work.registru port map ( D => out_nor1, Clk => Clock, EN => out_nor1, RS => out_or1, Q => out_reg1 );
	reg2 : entity work.registru port map ( D => out_and2, Clk => Clock, EN => out_and1, RS => out_or1, Q => out_reg2 );
	reg3 : entity work.registru port map ( D => out_and4, Clk => Clock, EN => out_and3, RS => out_or1, Q => out_reg3 );
	reg4 : entity work.registru port map ( D => out_and6, Clk => Clock, EN => out_and5, RS => out_or1, Q => out_reg4 );
	reg5 : entity work.registru port map ( D => out_nor2, Clk => Clock, EN => out_and7, RS => out_or1, Q => out_reg5 );
	reg6 : entity work.registru port map ( D => out_reg5, Clk => Clock, EN => out_reg5, RS => out_or1, Q => out_reg6 );
	d1 : entity work.bistabil_d port map ( D => out_reg6, RS => '0', Clk => Clock, Q =>	out_d1 );
	or1 : entity work.poarta_or2 port map ( A => Reset, B => out_d1, X => out_or1 );
	Iesire <= out_reg6;
end architecture;