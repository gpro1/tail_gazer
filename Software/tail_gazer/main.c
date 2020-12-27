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
//#include "androtchi_sprite.h"
#include "display.h"
#include "font_default.h"

struct pixel{
	alt_u8 r;
	alt_u8 g;
	alt_u8 b;
	alt_u8 pad;
};

alt_u8 snake[32] = {0x00, 0x00, 0x0f, 0x10, 0x20, 0x50, 0x40, 0x40,
					 0x40, 0x50, 0x20, 0x15, 0x15, 0x15, 0x0A, 0x00,
					 0x00, 0x0C, 0x82, 0x42, 0x24, 0x24, 0x32, 0x3A,
					 0x2E, 0x24, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00};

struct pixel buffer[24][48];// = 0;

//struct pixel grid[24][48] =
void bluetooth_rx_isr (void* context);
void drawPixel(int x, int y, struct pixel colour);
void drawChar(alt_u8 x, alt_u8 y, char c);
void updateDisplay();
void drawBitmap();

int main()
{
  printf("Hello from Nios II!\n");

  int x = 0;
  int y = 0;
  int pixel[3];
  //char* sprite = robot_normal;
  int i,j;
  struct pixel white = {16,16,16};
  for(y = 0; y < 24; y++){
	  for(x = 0; x < 48; x++){
		  drawPixel(x, y, white);
	  }
  }

  updateDisplay();





  x = 1;
  y = 3;

  volatile struct altera_avalon_uart_state_s uart;
  uart.base = BLUTOOTH_UART_BASE;
  uart.rx_end = 0;
  alt_ic_isr_register(BLUTOOTH_UART_IRQ_INTERRUPT_CONTROLLER_ID, BLUTOOTH_UART_IRQ, bluetooth_rx_isr, &uart, 0x0);
  alt_ic_irq_enable(BLUTOOTH_UART_IRQ_INTERRUPT_CONTROLLER_ID, BLUTOOTH_UART_IRQ);
  int index = 0;
  char data[256];
  while(1){
	  usleep(100);
	  if(uart.rx_buf[uart.rx_end - 1] == 0x0a){
		  alt_ic_irq_disable(BLUTOOTH_UART_IRQ_INTERRUPT_CONTROLLER_ID, BLUTOOTH_UART_IRQ);
		  	  memcpy(data, uart.rx_buf, uart.rx_end);
		  	  index = uart.rx_end - 1;
		  	  uart.rx_end = 0;
		  alt_ic_irq_enable(BLUTOOTH_UART_IRQ_INTERRUPT_CONTROLLER_ID, BLUTOOTH_UART_IRQ);

		  int i = 0;
		  while(i < index)
		  {
			  drawChar(x,y,data[i]);
			  x+=6;
			  i++;
		  }
		  updateDisplay();

	  }

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

void drawPixel(int x, int y, struct pixel colour){
	buffer[y][x].r = colour.r;
	buffer[y][x].g = colour.g;
	buffer[y][x].b = colour.b;
	buffer[y][x].pad = 0;
}

void drawChar(alt_u8 x, alt_u8 y, char c)
{
	struct pixel color = {150, 50, 29};
	struct pixel bg	   = {16 ,16, 16};
	alt_u8 i,j;
	 for(i = 0; i < 6; i++ )
	 {
		alt_u8 line;
		if(i < 5) line = *(font+(c*5)+i);
		else      line = 0x0;

		for(j = 0; j < 8; j++, line >>= 1)
		{
			if(line & 0x1)
			{
				drawPixel(x+i, y+j, color);
			}
			else
			{
			   drawPixel(x+i, y+j, bg);
			}
		}
	 }
}

void drawBitmap(){
	 /* while(1){
		  x = 15;
		  y = 3;
		  sprite = robot_normal;

		  for(i = 0; i < 16; i++){
			  for(j = 0; j < 16; j++){
				  HEADER_PIXEL(sprite, pixel);
				  buffer[y][x].r = pixel[0];
				  buffer[y][x].g = pixel[1];
				  buffer[y][x].b = pixel[2];
				  if(j == 15){
					  x = 15;
					  y++;
				  }
				  else{
					  x++;
				  }
			  }
		  }

		  updateDisplay();

		  usleep(100000);
		  x = 15;
		  y = 3;
		  sprite = robot_mad;
		  for(i = 0; i < 16; i++){
			  for(j = 0; j < 16; j++){
				  HEADER_PIXEL(sprite, pixel);
				  buffer[y][x].r = pixel[0];
				  buffer[y][x].g = pixel[1];
				  buffer[y][x].b = pixel[2];
				  if(j == 15){
					  x = 15;
					  y++;
				  }
				  else{
					  x++;
				  }
			  }
		  }
		  updateDisplay();
		  usleep(100000);

	  }*/
}

void updateDisplay()
{
	int i;
	//Disable display driver
	IOWR_ALTERA_AVALON_PIO_DATA(DISPLAY_DRIVER_CONTROL_BASE, 0x00);

	//Copy software buffer to display buffers
	for(i = 0; i < 8; i++)
	{
	  memcpy((void*)(FRAME_MEMORY_1_BASE + (i*PIX_SIZE*48)), (void*)buffer[23-i], (size_t)(PIX_SIZE*48));
	  memcpy((void*)(FRAME_MEMORY_2_BASE + (i*PIX_SIZE*48)), (void*)buffer[15-i], (size_t)(PIX_SIZE*48));
	  memcpy((void*)(FRAME_MEMORY_3_BASE + (i*PIX_SIZE*48)), (void*)buffer[7-i], (size_t)(PIX_SIZE*48));
	}

	//Enable Display driver
	IOWR_ALTERA_AVALON_PIO_DATA(DISPLAY_DRIVER_CONTROL_BASE, 0xff);
}



