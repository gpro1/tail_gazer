-------------Created by Gregory Evans on March 4th, 2018----------
-----Based on "LED-Matrix-with-DE0-Nano-SoC-Board" by github user AntonZero----

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity display_driver is
port(
	clk_50 		: in std_logic;

	en				: in std_logic; 
	gamma_cor 	: in std_logic;
	
	addr1 		: out std_logic_vector(8 downto 0);
	addr2 		: out std_logic_vector(8 downto 0);
	addr3 		: out std_logic_vector(8 downto 0);

	ram1_out 	: in std_logic_vector(31 downto 0);
	ram2_out 	: in std_logic_vector(31 downto 0);
	ram3_out 	: in std_logic_vector(31 downto 0);

	abc 			: out std_logic_vector(2 downto 0);
	rgb1 			: out std_logic_vector(2 downto 0);
	rgb2 			: out std_logic_vector(2 downto 0);
	rgb3 			: out std_logic_vector(2 downto 0);
	oe_n 			: out std_logic;
	out_clk 		: out std_logic;
	lat 			: out std_logic
	--
	);
end display_driver;

architecture display_driver of display_driver is

type state is (st0, st1, st2, st3, st4, lut_wait, st6, st7);

--Data Path
signal red_data1 		: std_logic_vector(7 downto 0);--directly from RAM
signal red_data2 		: std_logic_vector(7 downto 0);
signal red_data3 		: std_logic_vector(7 downto 0);
signal green_data1 	: std_logic_vector(7 downto 0);
signal green_data2 	: std_logic_vector(7 downto 0);
signal green_data3 	: std_logic_vector(7 downto 0);
signal blue_data1 	: std_logic_vector(7 downto 0);
signal blue_data2 	: std_logic_vector(7 downto 0);
signal blue_data3 	: std_logic_vector(7 downto 0);

signal lut_r1 			: std_logic_vector(7 downto 0); --LUT corrected
signal lut_g1 			: std_logic_vector(7 downto 0);
signal lut_b1 			: std_logic_vector(7 downto 0);
signal lut_r2 			: std_logic_vector(7 downto 0);
signal lut_g2 			: std_logic_vector(7 downto 0);
signal lut_b2 			: std_logic_vector(7 downto 0);
signal lut_r3 			: std_logic_vector(7 downto 0);
signal lut_g3 			: std_logic_vector(7 downto 0);
signal lut_b3 			: std_logic_vector(7 downto 0);

signal out_r1 			: std_logic_vector(7 downto 0); --Final output
signal out_g1 			: std_logic_vector(7 downto 0);
signal out_b1 			: std_logic_vector(7 downto 0);
signal out_r2 			: std_logic_vector(7 downto 0);
signal out_g2 			: std_logic_vector(7 downto 0);
signal out_b2 			: std_logic_vector(7 downto 0);
signal out_r3 			: std_logic_vector(7 downto 0);
signal out_g3 			: std_logic_vector(7 downto 0);
signal out_b3 			: std_logic_vector(7 downto 0);
--Matrix Signals

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

--Other Signals

signal matrix_st 		: state := st0;
signal shiftcounter	: integer range 0 to 48:=0;
signal counter			: integer range 0 to 50000000:=0;
signal clock_en		: std_logic;
signal lines			: integer range 0 to 7:=0;
signal matrix_frame	: integer range 0 to 255;

signal ramaddr1		: integer range 0 to 512;
signal ramaddr2		: integer range 0 to 512;
signal ramaddr3		: integer range 0 to 512;


component bram is
	port (
		clk_clk                         : in  std_logic                    := 'X';             -- clk
		reset_reset_n                   : in  std_logic                    := 'X';             -- reset_n
		onchip_memory2_0_s1_address     : in  std_logic_vector(7 downto 0) := (others => 'X'); -- address
		onchip_memory2_0_s1_debugaccess : in  std_logic                    := 'X';             -- debugaccess
		onchip_memory2_0_s1_clken       : in  std_logic                    := 'X';             -- clken
		onchip_memory2_0_s1_chipselect  : in  std_logic                    := 'X';             -- chipselect
		onchip_memory2_0_s1_write       : in  std_logic                    := 'X';             -- write
		onchip_memory2_0_s1_readdata    : out std_logic_vector(7 downto 0);                    -- readdata
		onchip_memory2_0_s1_writedata   : in  std_logic_vector(7 downto 0) := (others => 'X')  -- writedata
	);
end component bram;

begin
			   
rgb1 		<= matrix_r1 & matrix_g1 & matrix_b1;
rgb2 		<= matrix_r2 & matrix_g2 & matrix_b2;		
rgb3 		<= matrix_r3 & matrix_g3 & matrix_b3;

oe_n 		<= matrix_oe_n;
lat 		<= matrix_latch;
out_clk 	<= matrix_clk;

addr1		<= std_logic_vector(to_unsigned(ramaddr1,addr1'length));
addr2		<= std_logic_vector(to_unsigned(ramaddr2,addr2'length));
addr3		<= std_logic_vector(to_unsigned(ramaddr3,addr3'length));	

ramaddr3	<= shiftcounter+(7-lines)*48;	
ramaddr2	<= shiftcounter+(7-lines)*48;
ramaddr1	<= shiftcounter+(7-lines)*48;	

red_data1 	<= ram1_out(23 downto 16);
green_data1 <= ram1_out(15 downto 8);
blue_data1 	<= ram1_out(7 downto 0);
red_data2 	<= ram2_out(23 downto 16);
green_data2 <= ram2_out(15 downto 8);
blue_data2 	<= ram2_out(7 downto 0);
red_data3 	<= ram3_out(23 downto 16);
green_data3 <= ram3_out(15 downto 8);
blue_data3 	<= ram3_out(7 downto 0);

out_r1 <= red_data1 when gamma_cor = '0' else lut_r1;
out_g1 <= green_data1 when gamma_cor = '0' else lut_g1;
out_b1 <= blue_data1 when gamma_cor = '0' else lut_b1;
out_r2 <= red_data2 when gamma_cor = '0' else lut_r2;
out_g2 <= green_data2 when gamma_cor = '0' else lut_g2;
out_b2 <= blue_data2 when gamma_cor = '0' else lut_b2;
out_r3 <= red_data3 when gamma_cor = '0' else lut_r3;
out_g3 <= green_data3 when gamma_cor = '0' else lut_g3;
out_b3 <= blue_data3 when gamma_cor = '0' else lut_b3;

STATE_MACHINE: process(clk_50) begin
if rising_edge(clk_50) then
	if en = '0' then
		matrix_clk 		<= '0';
		matrix_st 		<= st0;
		matrix_frame 	<= 0;
		shiftcounter 	<= 0;
		lines 			<= 0;
		matrix_oe_n		<= '1';
		matrix_latch 	<= '0';
	
	else
		
		case matrix_st is
		
			when st0 =>
				matrix_clk 	<= '0';
				matrix_st 	<= lut_wait;
		
			when st1=>	--Shift Data
				matrix_clk	<= '1';   
			
				--Service red signals
				if(to_integer(unsigned(out_r1)) < matrix_frame) then
					matrix_r1 <= '0';
				else
					matrix_r1 <= '1';
				end if;
				
				if(to_integer(unsigned(out_r2)) < matrix_frame) then
					matrix_r2 <= '0';
				else
					matrix_r2 <= '1';
				end if;
				
				if(to_integer(unsigned(out_r3)) < matrix_frame) then
					matrix_r3 <= '0';
				else
					matrix_r3 <= '1';
				end if;
				
				--Service green signals 
				if(to_integer(unsigned(out_g1)) < matrix_frame) then
					matrix_g1 <= '0';
				else
					matrix_g1 <= '1';
				end if;
				
				if(to_integer(unsigned(out_g2)) < matrix_frame) then
					matrix_g2 <= '0';
				else
					matrix_g2 <= '1';
				end if;
				
				if(to_integer(unsigned(out_g3)) < matrix_frame) then
					matrix_g3 <= '0';
				else
					matrix_g3 <= '1';
				end if;
				
				--Service blue signals
				if(to_integer(unsigned(out_b1)) < matrix_frame) then
					matrix_b1 <= '0';
				else
					matrix_b1 <= '1';
				end if;
				
				if(to_integer(unsigned(out_b2)) < matrix_frame) then
					matrix_b2 <= '0';
				else
					matrix_b2 <= '1';
				end if;
				
				if(to_integer(unsigned(out_b3)) < matrix_frame) then
					matrix_b3 <= '0';
				else
					matrix_b3 <= '1';
				end if;
				
				--Shift pixels into display 
				if(shiftcounter < 47)then  
					shiftcounter	<= shiftcounter + 1;
					matrix_st		<= st0; 
				else	    
					shiftcounter	<= 0;     
					matrix_latch	<= '1';
					matrix_oe_n		<= '1';
					abc				<= std_logic_vector(to_unsigned(lines,3));
					matrix_st		<= st2;
				end if;
	
			when st2 =>	--latch data	
					matrix_st		<= st3;
					matrix_latch	<= '0';
					matrix_clk 		<= '0';
					
			when st3 =>
					matrix_oe_n		<='0';--enable output
					matrix_st		<=st4;
			
			when st4 => --pwm generation
			  
				if (matrix_frame < 255) then
					matrix_frame <= matrix_frame + 1;
					
				else
					matrix_frame	<= 1;
					
					if(lines<7)then  
						lines	<= lines + 1;
					else
						lines	<= 0;
					end if;
					
				end if;
				matrix_st	<= st0;
				
			when lut_wait =>
			
				matrix_st <= st1;
							
			when others=>NULL;
		end case;
			
	end if;
end if;
end process;

LUT_R_1: component bram
port map (
	clk_clk                         => clk_50,                         
	reset_reset_n                   => '1',
	onchip_memory2_0_s1_address     => red_data1, 
	onchip_memory2_0_s1_debugaccess => '0', 
	onchip_memory2_0_s1_clken       => '1',   
	onchip_memory2_0_s1_chipselect  => '1', 
	onchip_memory2_0_s1_write       => '0',
	onchip_memory2_0_s1_readdata    => lut_r1,   
	onchip_memory2_0_s1_writedata   => x"00"
);

LUT_G_1: component bram
port map (
	clk_clk                         => clk_50,                         
	reset_reset_n                   => '1',
	onchip_memory2_0_s1_address     => green_data1, 
	onchip_memory2_0_s1_debugaccess => '0', 
	onchip_memory2_0_s1_clken       => '1',   
	onchip_memory2_0_s1_chipselect  => '1', 
	onchip_memory2_0_s1_write       => '0',
	onchip_memory2_0_s1_readdata    => lut_g1,   
	onchip_memory2_0_s1_writedata   => x"00"
);

LUT_B_1: component bram
port map (
	clk_clk                         => clk_50,                         
	reset_reset_n                   => '1',
	onchip_memory2_0_s1_address     => blue_data1, 
	onchip_memory2_0_s1_debugaccess => '0', 
	onchip_memory2_0_s1_clken       => '1',   
	onchip_memory2_0_s1_chipselect  => '1', 
	onchip_memory2_0_s1_write       => '0',
	onchip_memory2_0_s1_readdata    => lut_b1,   
	onchip_memory2_0_s1_writedata   => x"00"
);

LUT_R_2: component bram
port map (
	clk_clk                         => clk_50,                         
	reset_reset_n                   => '1',
	onchip_memory2_0_s1_address     => red_data2, 
	onchip_memory2_0_s1_debugaccess => '0', 
	onchip_memory2_0_s1_clken       => '1',   
	onchip_memory2_0_s1_chipselect  => '1', 
	onchip_memory2_0_s1_write       => '0',
	onchip_memory2_0_s1_readdata    => lut_r2,   
	onchip_memory2_0_s1_writedata   => x"00"
);

LUT_G_2: component bram
port map (
	clk_clk                         => clk_50,                         
	reset_reset_n                   => '1',
	onchip_memory2_0_s1_address     => green_data2, 
	onchip_memory2_0_s1_debugaccess => '0', 
	onchip_memory2_0_s1_clken       => '1',   
	onchip_memory2_0_s1_chipselect  => '1', 
	onchip_memory2_0_s1_write       => '0',
	onchip_memory2_0_s1_readdata    => lut_g2,   
	onchip_memory2_0_s1_writedata   => x"00"
);

LUT_B_2: component bram
port map (
	clk_clk                         => clk_50,                         
	reset_reset_n                   => '1',
	onchip_memory2_0_s1_address     => blue_data2, 
	onchip_memory2_0_s1_debugaccess => '0', 
	onchip_memory2_0_s1_clken       => '1',   
	onchip_memory2_0_s1_chipselect  => '1', 
	onchip_memory2_0_s1_write       => '0',
	onchip_memory2_0_s1_readdata    => lut_b2,   
	onchip_memory2_0_s1_writedata   => x"00"
);

LUT_R_3: component bram
port map (
	clk_clk                         => clk_50,                         
	reset_reset_n                   => '1',
	onchip_memory2_0_s1_address     => red_data3, 
	onchip_memory2_0_s1_debugaccess => '0', 
	onchip_memory2_0_s1_clken       => '1',   
	onchip_memory2_0_s1_chipselect  => '1', 
	onchip_memory2_0_s1_write       => '0',
	onchip_memory2_0_s1_readdata    => lut_r3,   
	onchip_memory2_0_s1_writedata   => x"00"
);

LUT_G_3: component bram
port map (
	clk_clk                         => clk_50,                         
	reset_reset_n                   => '1',
	onchip_memory2_0_s1_address     => green_data3, 
	onchip_memory2_0_s1_debugaccess => '0', 
	onchip_memory2_0_s1_clken       => '1',   
	onchip_memory2_0_s1_chipselect  => '1', 
	onchip_memory2_0_s1_write       => '0',
	onchip_memory2_0_s1_readdata    => lut_g3,   
	onchip_memory2_0_s1_writedata   => x"00"
);

LUT_B_3: component bram
port map (
	clk_clk                         => clk_50,                         
	reset_reset_n                   => '1',
	onchip_memory2_0_s1_address     => blue_data3, 
	onchip_memory2_0_s1_debugaccess => '0', 
	onchip_memory2_0_s1_clken       => '1',   
	onchip_memory2_0_s1_chipselect  => '1', 
	onchip_memory2_0_s1_write       => '0',
	onchip_memory2_0_s1_readdata    => lut_b3,   
	onchip_memory2_0_s1_writedata   => x"00"
);
			  
end display_driver;

