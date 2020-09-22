/*
 * main.c
 *
 *  Created on: Sep 21, 2020
 *      Author: Gregory
 */

#include <stdio.h>
#include <system.h>
#include <altera_avalon_pio_regs.h>
#include <altera_avalon_uart_regs.h>
#include <altera_avalon_uart.h>
#include <unistd.h>
#include <alt_types.h>
#include <sys/alt_irq.h>

struct{
	char r;
	char g;
	char b;
}pixel;

//struct pixel grid[24][48] =
void bluetooth_rx_isr (void* context);


int main()
{
  printf("Hello from Nios II!\n");
  volatile struct altera_avalon_uart_state_s uart;
  uart.base = BLUTOOTH_UART_BASE;
  uart.rx_end = 0;
  alt_ic_isr_register(BLUTOOTH_UART_IRQ_INTERRUPT_CONTROLLER_ID, BLUTOOTH_UART_IRQ, bluetooth_rx_isr, &uart, 0x0);
  alt_ic_irq_enable(BLUTOOTH_UART_IRQ_INTERRUPT_CONTROLLER_ID, BLUTOOTH_UART_IRQ);
  //int cnt = 0;
  char data[3];
  while(1){

	  if(uart.rx_end >= 3){
		  alt_ic_irq_disable(BLUTOOTH_UART_IRQ_INTERRUPT_CONTROLLER_ID, BLUTOOTH_UART_IRQ);
		  	  data[0] = uart.rx_buf[0];
		  	  data[1] = uart.rx_buf[1];
		  	  data[2] = uart.rx_buf[2];
		  	  uart.rx_end = 0;
		  alt_ic_irq_enable(BLUTOOTH_UART_IRQ_INTERRUPT_CONTROLLER_ID, BLUTOOTH_UART_IRQ);

		  printf("Red: %u Green %u: Blue %u\n", (alt_u8)data[0], (alt_u8)data[1], (alt_u8)data[2]);
		  IOWR_ALTERA_AVALON_PIO_DATA(DISPLAY_DRIVER_CONTROL_BASE, 0x00);
		  memcpy(FRAME_MEMORY_2_BASE, &data, sizeof(data));
		  IOWR_ALTERA_AVALON_PIO_DATA(DISPLAY_DRIVER_CONTROL_BASE, 0xff);
	  }
	  //cnt = altera_avalon_uart_read(&uart, &data, 1, 0);
	  //printf("Red: %u\n", (int)data);
	  /*cnt = altera_avalon_uart_read(&uart, data[1], 1, 0);
	  printf("Green: %u\n", data[1]);
	  cnt = altera_avalon_uart_read(&uart, data[2], 1, 0);
	  printf("Blue: %u\n", data[2]);
	  //IOWR_ALTERA_AVALON_PIO_DATA(PIO_LED_BASE, data & 0xff);*/


	  //cnt = altera_avalon_uart_write(&uart, &data, 3, 0);
	  //IOWR_ALTERA_AVALON_PIO_DATA(0x2002800, 0x00);
	 // memcpy(0x2002000, &data, sizeof(data));
	  //IOWR_ALTERA_AVALON_PIO_DATA(0x2002800, 0xff);
	  //usleep(10000);
	  //cnt++;
  }




  return 0;
}

void bluetooth_rx_isr(void* context){
	volatile struct altera_avalon_uart_state_s* uart_ptr = (volatile struct altera_avalon_uart_state_s*) context;
	if (IORD_ALTERA_AVALON_UART_STATUS(BLUTOOTH_UART_BASE) & ALTERA_AVALON_UART_STATUS_RRDY_MSK){
		uart_ptr->rx_buf[uart_ptr->rx_end] = IORD_ALTERA_AVALON_UART_RXDATA(BLUTOOTH_UART_BASE);
		uart_ptr->rx_end++;
		if (uart_ptr->rx_end > ALT_AVALON_UART_BUF_LEN) uart_ptr->rx_end = 0;
	}
}



