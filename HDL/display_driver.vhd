-------------Created by Gregory Evans on March 4th, 2018----------
-----Based on "LED-Matrix-with-DE0-Nano-SoC-Board" by github user AntonZero----

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity display_driver is
port(
	clk_50 	: in std_logic;

	en			: in std_logic; --implement
	
	--Frame memory
	addr1 	: out std_logic_vector(8 downto 0);
	addr2 	: out std_logic_vector(8 downto 0);
	addr3 	: out std_logic_vector(8 downto 0);

	ram1_out : in std_logic_vector(31 downto 0);
	ram2_out : in std_logic_vector(31 downto 0);
	ram3_out : in std_logic_vector(31 downto 0);
	--
	--Display
	abc 		: out std_logic_vector(2 downto 0);
	rgb1 		: out std_logic_vector(2 downto 0);
	rgb2 		: out std_logic_vector(2 downto 0);
	rgb3 		: out std_logic_vector(2 downto 0);
	oe_n 		: out std_logic;
	out_clk 	: out std_logic;
	lat 		: out std_logic
	--
	);
end display_driver;

architecture display_driver of display_driver is

--------------------matrix signals----------------------

signal matrix_clk		: std_logic;
signal matrix_oe_n	: std_logic;
signal matrix_latch	: std_logic;
signal matrix_r1		: std_logic;
signal matrix_g1		: std_logic;
signal matrix_b1		: std_logic;
signal matrix_r2		: std_logic;
signal matrix_g2		: std_logic;
signal matrix_b2		: std_logic;
signal matrix_r3		: std_logic;
signal matrix_g3		: std_logic;
signal matrix_b3		: std_logic;

--------------------other signals----------------------

type state is (st0,st1,st2,st3,st4,st5);
signal matrix_st 		: state:=st1;
signal shiftcounter	: integer range 0 to 48:=0;
signal counter			: integer range 0 to 50000000:=0;
signal clock_en		: std_logic;
signal lines			: integer range 0 to 7:=0;
signal delay			: integer range 0 to 5000000:=0;
signal newline			: std_logic:='0';
signal matrix_frame	: integer range 0 to 255;

signal ramaddr1		: integer range 0 to 512;
signal ramaddr2		: integer range 0 to 512;
signal ramaddr3		: integer range 0 to 512;

begin
			   
rgb1 		<= matrix_r1 & matrix_g1 & matrix_b1;
rgb2 		<= matrix_r2 & matrix_g2 & matrix_b2;		
rgb3 		<= matrix_r3 & matrix_g3 & matrix_b3;

oe_n 		<= matrix_oe_n;
lat 		<= matrix_latch;
out_clk 	<= matrix_clk;

addr1		<=std_logic_vector(to_unsigned(ramaddr1,addr1'length));
addr2		<=std_logic_vector(to_unsigned(ramaddr2,addr2'length));
addr3		<=std_logic_vector(to_unsigned(ramaddr3,addr3'length));				  
			  
CLOCK_SCALER: process(clk_50)
begin
	 if rising_edge(clk_50)then	
		clock_en <= not clock_en;
--		if(counter<32)then-------prescaler clock
--				counter	<= counter + 1;
--				clock_en	<= '0';
--		else 
--				counter	<= 0;
--				clock_en	<= '1';
--		end if;

	 end if;
end process;

ramaddr3	<=shiftcounter+(7-lines)*48;	
ramaddr2	<=shiftcounter+(7-lines)*48;
ramaddr1	<=shiftcounter+(7-lines)*48;

STATE_MACHINE:process(clk_50)
begin
if rising_edge(clk_50) then

	if en = '0' then
--		ramaddr3 		<= 0;
--		ramaddr2 		<= 0;
--		ramaddr1 		<= 0;
		matrix_clk 		<= '0';
		matrix_st 		<= st0;
		matrix_frame 	<= 0;
		shiftcounter 	<= 0;
		lines 			<= 0;
		matrix_oe_n		<= '1';
		matrix_latch 	<= '0';
	
	else
		
		if(clock_en = '1')then	
	
			case matrix_st is
			when st0=>	--------shift data
				matrix_clk	<= '1';    
				-----------------------red--------------------
				if(to_integer(unsigned(ram1_out(23 downto 17)))<matrix_frame)then --reads colour data from ram
					matrix_r1<='0';
				else
					matrix_r1<='1';
				end if;
				
				if(to_integer(unsigned(ram2_out(23 downto 17)))<matrix_frame)then--reads colour data from ram
					matrix_r2<='0';
				else
					matrix_r2<='1';
				end if;
				
				if(to_integer(unsigned(ram3_out(23 downto 17)))<matrix_frame)then--reads colour data from ram
					matrix_r3<='0';
				else
					matrix_r3<='1';
				end if;
				
				------------------------green-----------------------
				if(to_integer(unsigned(ram1_out(15 downto 8)))<matrix_frame)then--reads colour data from ram
					matrix_g1<='0';
				else
					matrix_g1<='1';
				end if;
				
				if(to_integer(unsigned(ram2_out(15 downto 8)))<matrix_frame)then--reads colour data from ram
					matrix_g2<='0';
				else
					matrix_g2<='1';
				end if;
				
				if(to_integer(unsigned(ram3_out(15 downto 8)))<matrix_frame)then--reads colour data from ram
					matrix_g3<='0';
				else
					matrix_g3<='1';
				end if;
				
	--			-----------------blue------------------------
				if(to_integer(unsigned(ram1_out(7 downto 0)))<matrix_frame)then--reads colour data from ram
					matrix_b1<='0';
				else
					matrix_b1<='1';
				end if;
				
				if(to_integer(unsigned(ram2_out(7 downto 0)))<matrix_frame)then--reads colour data from ram
					matrix_b2<='0';
				else
					matrix_b2<='1';
				end if;
				
				if(to_integer(unsigned(ram3_out(7 downto 0)))<matrix_frame)then--reads colour data from ram
					matrix_b3<='0';
				else
					matrix_b3<='1';
				end if;
				------------------shift data---------------------
				if(shiftcounter<47)then  
					shiftcounter	<=shiftcounter+1;
				else	    
					shiftcounter	<= 0;     
					matrix_latch	<='1';
					matrix_oe_n		<='1';
					abc				<=std_logic_vector(to_unsigned(lines,3));
					matrix_st		<=st1;
				end if;
	
			when st1=>	-----------latch data	
					matrix_st		<=st2;
					matrix_latch	<='0';---latch data on falling_edge
			when st2=>
					matrix_oe_n		<='0';--------enable output
					matrix_st		<=st3;
			
			when st3=>
					 -------------pwm generation
				if(matrix_frame<255)then
					matrix_frame<=matrix_frame+1;
				else
					newline			<='1';
					matrix_frame	<=1;
					if(lines<7)then  -----
						lines	<= lines+1;
					else
						lines	<= 0;
					end if;
				end if;
				matrix_st	<=st0;
			when others=>NULL;
			end case;
		else
		matrix_clk	<= '0';
		end if;
	end if;
end if;
end process;

			  
end display_driver;

