--Written by Gregory Evans on 07/14/2020

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;



entity LED_Message_Board is
port (
		clock_50			: in std_logic;

		leds				: out std_logic_vector(7 downto 0);
	
		tx					: out std_logic;
		rx					: in std_logic;
		
		sdram_addr		: out std_logic_vector(12 downto 0);
		sdram_ba    	: out   std_logic_vector(1 downto 0);                     -- ba
		sdram_cas_n 	: out   std_logic;                                        -- cas_n
		sdram_cke   	: out   std_logic;                                        -- cke
		sdram_cs_n  	: out   std_logic;                                        -- cs_n
		sdram_dq    	: inout std_logic_vector(15 downto 0);						 	 -- dq
		sdram_dqm   	: out   std_logic_vector(1 downto 0);                     -- dqm
		sdram_ras_n 	: out   std_logic;                                        -- ras_n
		sdram_we_n  	: out   std_logic;                                        -- we_n
		sdram_c1_clk	: out   std_logic; 											   	-- clk
		abc 				: out std_logic_vector(2 downto 0);
		rgb1 				: out std_logic_vector(2 downto 0);
		rgb2 				: out std_logic_vector(2 downto 0);
		rgb3 				: out std_logic_vector(2 downto 0);
		oe_n 				: out std_logic;
		out_clk 			: out std_logic;
		lat 				: out std_logic
	  );
end LED_Message_Board;

architecture LED_Message_Board of LED_Message_Board is

signal locked		: std_logic;

signal addr1		: std_logic_vector (8 downto 0);
signal addr2		: std_logic_vector (8 downto 0);
signal addr3		: std_logic_vector (8 downto 0);

signal ram1_out	: std_logic_vector (31 downto 0);
signal ram2_out	: std_logic_vector (31 downto 0);
signal ram3_out	: std_logic_vector (31 downto 0);

signal nios_in		: std_logic_vector (7 downto 0);
signal nios_out	: std_logic_vector (7 downto 0);

signal driver_en	: std_logic;
signal gamma_cor	: std_logic;


component DE0_NANO_SOPC is
		port (
			blutooth_uart_external_connection_rxd               : in    std_logic                     := 'X';             -- rxd
			blutooth_uart_external_connection_txd               : out   std_logic;                                        -- txd
			clk_clk                                             : in    std_logic                     := 'X';             -- clk
			pio_led_external_connection_export                  : out   std_logic_vector(7 downto 0);                     -- export
			sdram_clk_areset_conduit_export                     : in    std_logic                     := 'X';             -- export
			sdram_clk_c1_clk                                    : out   std_logic;                                        -- clk
			sdram_clk_locked_conduit_export                     : out   std_logic;                                        -- export
			sdram_wire_addr                                     : out   std_logic_vector(12 downto 0);                    -- addr
			sdram_wire_ba                                       : out   std_logic_vector(1 downto 0);                     -- ba
			sdram_wire_cas_n                                    : out   std_logic;                                        -- cas_n
			sdram_wire_cke                                      : out   std_logic;                                        -- cke
			sdram_wire_cs_n                                     : out   std_logic;                                        -- cs_n
			sdram_wire_dq                                       : inout std_logic_vector(15 downto 0) := (others => 'X'); -- dq
			sdram_wire_dqm                                      : out   std_logic_vector(1 downto 0);                     -- dqm
			sdram_wire_ras_n                                    : out   std_logic;                                        -- ras_n
			sdram_wire_we_n                                     : out   std_logic;                                        -- we_n
			frame_memory_1_clk2_clk                             : in    std_logic                     := 'X';             -- clk
			frame_memory_1_reset2_reset                         : in    std_logic                     := 'X';             -- reset
			frame_memory_1_reset2_reset_req                     : in    std_logic                     := 'X';             -- reset_req
			frame_memory_1_s2_address                           : in    std_logic_vector(8 downto 0)  := (others => 'X'); -- address
			frame_memory_1_s2_chipselect                        : in    std_logic                     := 'X';             -- chipselect
			frame_memory_1_s2_clken                             : in    std_logic                     := 'X';             -- clken
			frame_memory_1_s2_write                             : in    std_logic                     := 'X';             -- write
			frame_memory_1_s2_readdata                          : out   std_logic_vector(31 downto 0);                    -- readdata
			frame_memory_1_s2_writedata                         : in    std_logic_vector(31 downto 0) := (others => 'X'); -- writedata
			frame_memory_1_s2_byteenable                        : in    std_logic_vector(3 downto 0)  := (others => 'X'); -- byteenable
			frame_memory_2_clk2_clk                             : in    std_logic                     := 'X';             -- clk
			frame_memory_2_reset2_reset                         : in    std_logic                     := 'X';             -- reset
			frame_memory_2_reset2_reset_req                     : in    std_logic                     := 'X';             -- reset_req
			frame_memory_2_s2_address                           : in    std_logic_vector(8 downto 0)  := (others => 'X'); -- address
			frame_memory_2_s2_chipselect                        : in    std_logic                     := 'X';             -- chipselect
			frame_memory_2_s2_clken                             : in    std_logic                     := 'X';             -- clken
			frame_memory_2_s2_write                             : in    std_logic                     := 'X';             -- write
			frame_memory_2_s2_readdata                          : out   std_logic_vector(31 downto 0);                    -- readdata
			frame_memory_2_s2_writedata                         : in    std_logic_vector(31 downto 0) := (others => 'X'); -- writedata
			frame_memory_2_s2_byteenable                        : in    std_logic_vector(3 downto 0)  := (others => 'X'); -- byteenable
			frame_memory_3_clk2_clk                             : in    std_logic                     := 'X';             -- clk
			frame_memory_3_reset2_reset                         : in    std_logic                     := 'X';             -- reset
			frame_memory_3_reset2_reset_req                     : in    std_logic                     := 'X';             -- reset_req
			frame_memory_3_s2_address                           : in    std_logic_vector(8 downto 0)  := (others => 'X'); -- address
			frame_memory_3_s2_chipselect                        : in    std_logic                     := 'X';             -- chipselect
			frame_memory_3_s2_clken                             : in    std_logic                     := 'X';             -- clken
			frame_memory_3_s2_write                             : in    std_logic                     := 'X';             -- write
			frame_memory_3_s2_readdata                          : out   std_logic_vector(31 downto 0);                    -- readdata
			frame_memory_3_s2_writedata                         : in    std_logic_vector(31 downto 0) := (others => 'X'); -- writedata
			frame_memory_3_s2_byteenable                        : in    std_logic_vector(3 downto 0)  := (others => 'X'); -- byteenable
			display_driver_control_external_connection_in_port  : in    std_logic_vector(7 downto 0)  := (others => 'X'); -- in_port
			display_driver_control_external_connection_out_port : out   std_logic_vector(7 downto 0)                      -- out_port
		);
	end component DE0_NANO_SOPC;

begin

driver_en <= nios_out(0);
gamma_cor <= nios_out(1);

LED_DRIVER: entity work.display_driver(display_driver)
port map (
	clk_50 		=> clock_50,
	en				=> driver_en,
	gamma_cor	=> gamma_cor,
	addr1 		=> addr1,
	addr2 		=> addr2,
	addr3 		=> addr3,
	ram1_out 	=> ram1_out,
	ram2_out 	=> ram2_out,
	ram3_out 	=> ram3_out,
	abc 			=> abc,
	rgb1 			=> rgb1,
	rgb2 			=> rgb2,
	rgb3 			=> rgb3,
	oe_n 			=> oe_n,
	out_clk 		=> out_clk,
	lat 			=> lat
);

MCU : component DE0_NANO_SOPC
port map (
	clk_clk                            						 => clock_50,                            --                         clk.clk

	pio_led_external_connection_export 						 => leds, -- pio_led_external_connection.export
	blutooth_uart_external_connection_rxd 					 => rx, -- blutooth_uart_external_connection.rxd
	blutooth_uart_external_connection_txd 					 => tx, --                                  .txd
	sdram_wire_addr                       				  	 => sdram_addr,	
	sdram_wire_ba                         					 => sdram_ba,    
	sdram_wire_cas_n                      					 => sdram_cas_n, 
	sdram_wire_cke                        					 => sdram_cke,   
	sdram_wire_cs_n                       					 => sdram_cs_n,  
	sdram_wire_dq                         					 => sdram_dq,    
	sdram_wire_dqm                        					 => sdram_dqm,   
	sdram_wire_ras_n                      					 => sdram_ras_n, 
	sdram_wire_we_n                       					 => sdram_we_n,  
	sdram_clk_c1_clk                      					 => sdram_c1_clk,
	sdram_clk_areset_conduit_export       					 => '0',
	sdram_clk_locked_conduit_export       					 => locked,
	frame_memory_1_clk2_clk                             => clock_50, 
	frame_memory_1_reset2_reset                         => '0',
	frame_memory_1_reset2_reset_req                     => '0',
	frame_memory_1_s2_address                           => addr1,
	frame_memory_1_s2_chipselect                        => '1',
	frame_memory_1_s2_clken                             => '1',
	frame_memory_1_s2_write                             => '0',
	frame_memory_1_s2_readdata                          => ram1_out,
	frame_memory_1_s2_writedata                         => x"00000000",
	frame_memory_1_s2_byteenable                        => "1111",
	frame_memory_2_clk2_clk                             => clock_50,
	frame_memory_2_reset2_reset                         => '0',
	frame_memory_2_reset2_reset_req                     => '0',
	frame_memory_2_s2_address                           => addr2,
	frame_memory_2_s2_chipselect                        => '1',
	frame_memory_2_s2_clken                             => '1',
	frame_memory_2_s2_write                             => '0',
	frame_memory_2_s2_readdata                          => ram2_out,
	frame_memory_2_s2_writedata                         => x"00000000",
	frame_memory_2_s2_byteenable                        => "1111",
	frame_memory_3_clk2_clk                             => clock_50,
	frame_memory_3_reset2_reset                         => '0',
	frame_memory_3_reset2_reset_req                     => '0',
	frame_memory_3_s2_address                           => addr3,
	frame_memory_3_s2_chipselect                        => '1',
	frame_memory_3_s2_clken                             => '1',
	frame_memory_3_s2_write                             => '0',
	frame_memory_3_s2_readdata                          => ram3_out,
	frame_memory_3_s2_writedata                         => x"00000000",
	frame_memory_3_s2_byteenable                        => "1111",
	display_driver_control_external_connection_in_port  => nios_in,
	display_driver_control_external_connection_out_port => nios_out

	);

end LED_Message_Board;