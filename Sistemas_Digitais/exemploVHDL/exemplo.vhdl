library ieee;
use ieee.std_logic_1164.all;

entity teste is port (
    a, b : in std_logic;
    igual : out std_logic 
);
end teste;
architecture behavioral of comparador4 is
begin
comp: process (a, b)
begin
if a=b then
 igual <= ‘1’;
else
 igual <= ‘0’;
end if;
end process comp;
end behavioral;
