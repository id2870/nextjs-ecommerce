/* stlink-v2 specific functions
   (c) Valentin Dudouyt, 2012-2013 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pgm.h"
#include "stlink.h"

bool stlink2_open(programmer_t *pgm) {
	pgm->msg_count = 0;
	pgm->out_usleep = 3000;
	pgm->out_msg_size = 16;
	int r, i;
	char buffer[16];
	stlink_send_message(pgm, 1, 0xf5);
	stlink_read1(pgm, 2);
	stlink_send_message(pgm, 2, 0xf3, 0x07);
	stlink_send_message(pgm, 1, 0xf4);
	stlink_send_message(pgm, 2, 0xf4, 0x0d);
	stlink_read1(pgm, 2);
	stlink_send_message(pgm, 3, 0xf4, 0x02, 0x01);
	stlink_read1(pgm, 8);
	for(i = 0; i < 2; i++) {
		stlink_send_message(pgm, 3, 0xf4, 0x07, 0x01);
		stlink_send_message(pgm, 3, 0xf4, 0x09, 0x01);
		stlink_read1(pgm, 4);
	}
	stlink_send_message(pgm, 3, 0xf4, 0x04, 0x01);
	stlink_send_message(pgm, 3, 0xf4, 0x09, 0x01);
	if(stlink_read_and_cmp(pgm, 4, 0x01, 0x00, 0x00, 0x00))
		return(false); // SWIM Error
	return(true);
}

int stlink2_swim_read_range(programmer_t *pgm, char *buffer, unsigned int start, unsigned int length) {
	int recv = 0;
	int start_h = (start & 0xFF00) >> 8;
	int start_l = start & 0xFF;
stlink_send_message(pgm, 9, 0xf4, 0x07, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 9, 0xf4, 0x08, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 9, 0xf4, 0x07, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 9, 0xf4, 0x04, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 9, 0xf4, 0x03, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 9, 0xf4, 0x05, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 9, 0xf4, 0x0a, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xa0);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xa0);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 9, 0xf4, 0x08, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xa0);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xa0);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 9, 0xf4, 0x0b, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x99, 0xa0);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x99, 0xa0);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 9, 0xf4, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x99, 0xa0);
stlink_read1(pgm, 1);
stlink_send_message(pgm, 9, 0xf4, 0x0b, 0x00, 0x01, 0x00, 0x00, 0x50, 0xcd, 0xa0);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x50, 0xcd, 0xa0);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 9, 0xf4, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x50, 0xcd, 0xa0);
stlink_read1(pgm, 1);
stlink_send_message(pgm, 9, 0xf4, 0x06, 0x00, 0x01, 0x00, 0x00, 0x50, 0xcd, 0xa0);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x50, 0xcd, 0xa0);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 9, 0xf4, 0x0a, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb0);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb0);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 9, 0xf4, 0x03, 0x01, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb0);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x01, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb0);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 9, 0xf4, 0x0a, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb4);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb4);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 8, 0xf4, 0x0a, 0x00, 0x01, 0x00, 0x00, 0x50, 0xc6);
stlink_send_message(pgm, 8, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x50, 0xc6);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 8, 0xf4, 0x0b, 0x00, 0x04, 0x00, 0x00, 0x4f, 0xfc);
stlink_send_message(pgm, 8, 0xf4, 0x09, 0x00, 0x04, 0x00, 0x00, 0x4f, 0xfc);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 8, 0xf4, 0x0c, 0x00, 0x04, 0x00, 0x00, 0x4f, 0xfc);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 8, 0xf4, 0x0b, 0x00, 0x01, 0x00, 0x00, 0x50, 0x5f);
stlink_send_message(pgm, 8, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x50, 0x5f);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 8, 0xf4, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x50, 0x5f);
stlink_read1(pgm, 1);
stlink_send_message(pgm, 7, 0xf4, 0x0b, 0x00, 0x01, 0x00, 0x00, 0x48);
stlink_send_message(pgm, 7, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x48);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 7, 0xf4, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x48);
stlink_read1(pgm, 1);
stlink_send_message(pgm, 8, 0xf4, 0x0b, 0x00, 0x01, 0x00, 0x00, 0x48, 0x01);
stlink_send_message(pgm, 8, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x48, 0x01);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 8, 0xf4, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x48, 0x01);
stlink_read1(pgm, 1);
stlink_send_message(pgm, 8, 0xf4, 0x0b, 0x00, 0x01, 0x00, 0x00, 0x48, 0x02);
stlink_send_message(pgm, 8, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x48, 0x02);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 8, 0xf4, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x48, 0x02);
stlink_read1(pgm, 1);
stlink_send_message(pgm, 8, 0xf4, 0x0b, 0x00, length, 0x00, 0x00, start_h, start_l);
stlink_send_message(pgm, 8, 0xf4, 0x09, 0x00, length, 0x00, 0x00, start_h, start_l);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 8, 0xf4, 0x0c, 0x00, length, 0x00, 0x00, start_h, start_l);
// IN 64 bytes ommited
// IN 17 bytes ommited
	recv += stlink_read(pgm, buffer, length);
stlink_send_message(pgm, 8, 0xf4, 0x0b, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80);
stlink_send_message(pgm, 8, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 8, 0xf4, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80);
stlink_read1(pgm, 1);
stlink_send_message(pgm, 9, 0xf4, 0x0a, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 9, 0xf4, 0x05, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 9, 0xf4, 0x07, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_read1(pgm, 4);
stlink_send_message(pgm, 9, 0xf4, 0x03, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_send_message(pgm, 9, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6);
stlink_read1(pgm, 4);
	return(recv);
}

int stlink2_swim_write_range(programmer_t *pgm, char *buffer, unsigned int start, unsigned int length) {
stlink_send_message(pgm, 10, 0xf4, 0x07, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6, 0xff);
stlink_read1(pgm, 4); // 00000000
stlink_send_message(pgm, 10, 0xf4, 0x08, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6, 0xff);
stlink_read1(pgm, 4); // 00000000
stlink_send_message(pgm, 10, 0xf4, 0x07, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6, 0xff);
stlink_read1(pgm, 4); // 00000000
stlink_send_message(pgm, 10, 0xf4, 0x04, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6, 0xff);
stlink_read1(pgm, 4); // 01000000
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6, 0xff);
stlink_read1(pgm, 4); // 01000000
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6, 0xff);
stlink_read1(pgm, 4); // 00000000
stlink_send_message(pgm, 10, 0xf4, 0x03, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6, 0xff);
stlink_read1(pgm, 4); // 00000000
stlink_send_message(pgm, 10, 0xf4, 0x05, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb6, 0xff);
stlink_read1(pgm, 4); // 00000000
stlink_send_message(pgm, 10, 0xf4, 0x0a, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xa0, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xa0, 0xff);
stlink_read1(pgm, 4); // 00010000
stlink_send_message(pgm, 10, 0xf4, 0x08, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xa0, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xa0, 0xff);
stlink_read1(pgm, 4); // 00000000
stlink_send_message(pgm, 10, 0xf4, 0x0b, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x99, 0xa0, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x99, 0xa0, 0xff);
stlink_read1(pgm, 4); // 00010000
stlink_send_message(pgm, 10, 0xf4, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x99, 0xa0, 0xff);
stlink_read1(pgm, 1); // 08
stlink_send_message(pgm, 10, 0xf4, 0x0b, 0x00, 0x01, 0x00, 0x00, 0x50, 0xcd, 0xa0, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x50, 0xcd, 0xa0, 0xff);
stlink_read1(pgm, 4); // 00010000
stlink_send_message(pgm, 10, 0xf4, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x50, 0xcd, 0xa0, 0xff);
stlink_read1(pgm, 1); // 00
stlink_send_message(pgm, 10, 0xf4, 0x06, 0x00, 0x01, 0x00, 0x00, 0x50, 0xcd, 0xa0, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x50, 0xcd, 0xa0, 0xff);
stlink_read1(pgm, 4); // 00000000
stlink_send_message(pgm, 10, 0xf4, 0x0a, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb0, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb0, 0xff);
stlink_read1(pgm, 4); // 00010000
stlink_send_message(pgm, 10, 0xf4, 0x03, 0x01, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb0, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x01, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb0, 0xff);
stlink_read1(pgm, 4); // 00000000
stlink_send_message(pgm, 10, 0xf4, 0x0a, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb4, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x7f, 0x80, 0xb4, 0xff);
stlink_read1(pgm, 4); // 00010000
stlink_send_message(pgm, 10, 0xf4, 0x0a, 0x00, 0x01, 0x00, 0x00, 0x50, 0xc6, 0x00, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x50, 0xc6, 0x00, 0xff);
stlink_read1(pgm, 4); // 00010000
stlink_send_message(pgm, 10, 0xf4, 0x0b, 0x00, 0x04, 0x00, 0x00, 0x4f, 0xfc, 0x00, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x04, 0x00, 0x00, 0x4f, 0xfc, 0x00, 0xff);
stlink_read1(pgm, 4); // 00040000
stlink_send_message(pgm, 10, 0xf4, 0x0c, 0x00, 0x04, 0x00, 0x00, 0x4f, 0xfc, 0x00, 0xff);
stlink_read1(pgm, 4); // 67671003
stlink_send_message(pgm, 10, 0xf4, 0x0b, 0x00, 0x01, 0x00, 0x00, 0x50, 0x5f, 0x00, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x50, 0x5f, 0x00, 0xff);
stlink_read1(pgm, 4); // 00010000
stlink_send_message(pgm, 10, 0xf4, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x50, 0x5f, 0x00, 0xff);
stlink_read1(pgm, 1); // 40
stlink_send_message(pgm, 10, 0xf4, 0x0b, 0x00, 0x01, 0x00, 0x00, 0x48, 0x00, 0x00, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x48, 0x00, 0x00, 0xff);
stlink_read1(pgm, 4); // 00010000
stlink_send_message(pgm, 10, 0xf4, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x48, 0x00, 0x00, 0xff);
stlink_read1(pgm, 1); // 00
stlink_send_message(pgm, 10, 0xf4, 0x0b, 0x00, 0x01, 0x00, 0x00, 0x48, 0x01, 0x00, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x48, 0x01, 0x00, 0xff);
stlink_read1(pgm, 4); // 00010000
stlink_send_message(pgm, 10, 0xf4, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x48, 0x01, 0x00, 0xff);
stlink_read1(pgm, 1); // 00
stlink_send_message(pgm, 10, 0xf4, 0x0b, 0x00, 0x01, 0x00, 0x00, 0x48, 0x02, 0x00, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x48, 0x02, 0x00, 0xff);
stlink_read1(pgm, 4); // 00010000
stlink_send_message(pgm, 10, 0xf4, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x48, 0x02, 0x00, 0xff);
stlink_read1(pgm, 1); // ff
stlink_send_message(pgm, 10, 0xf4, 0x0a, 0x00, 0x01, 0x00, 0x00, 0x50, 0x62, 0x56, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x50, 0x62, 0x56, 0xff);
stlink_read1(pgm, 4); // 00010000
stlink_send_message(pgm, 10, 0xf4, 0x0a, 0x00, 0x01, 0x00, 0x00, 0x50, 0x62, 0xae, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x50, 0x62, 0xae, 0xff);
stlink_read1(pgm, 4); // 00010000
stlink_send_message(pgm, 10, 0xf4, 0x0a, 0x00, 0x01, 0x00, 0x00, 0x50, 0x64, 0xae, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x50, 0x64, 0xae, 0xff);
stlink_read1(pgm, 4); // 00010000
stlink_send_message(pgm, 10, 0xf4, 0x0a, 0x00, 0x01, 0x00, 0x00, 0x50, 0x64, 0x56, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x50, 0x64, 0x56, 0xff);
stlink_read1(pgm, 4); // 00010000
stlink_send_message(pgm, 10, 0xf4, 0x0b, 0x00, 0x01, 0x00, 0x00, 0x50, 0x5f, 0x56, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x50, 0x5f, 0x56, 0xff);
stlink_read1(pgm, 4); // 00010000
stlink_send_message(pgm, 10, 0xf4, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x50, 0x5f, 0x56, 0xff);
stlink_read1(pgm, 1); // 4a
stlink_send_message(pgm, 10, 0xf4, 0x0a, 0x00, 0x02, 0x00, 0x00, 0x50, 0x5b, 0x00, 0xff);
stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x02, 0x00, 0x00, 0x50, 0x5b, 0x00, 0xff);
stlink_read1(pgm, 4); // 00020000
	int i, sent = 0;
	for(i = 0; i < length; i++) {
		int addr_h = ((start + i) & 0xFF00) >> 8;
		int addr_l = (start + i) & 0xFF;
		stlink_send_message(pgm, 10, 0xf4, 0x0a, 0x00, 0x01, 0x00, 0x00, addr_h, addr_l, buffer[i], 0xff);
		stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, addr_h, addr_l, buffer[i], 0xff);
		stlink_read1(pgm, 4); // 00010000
		stlink_send_message(pgm, 10, 0xf4, 0x0b, 0x00, 0x01, 0x00, 0x00, 0x50, 0x5f, buffer[i], 0xff);
		stlink_send_message(pgm, 10, 0xf4, 0x09, 0x00, 0x01, 0x00, 0x00, 0x50, 0x5f, buffer[i], 0xff);
		stlink_read1(pgm, 4); // 00010000
		stlink_send_message(pgm, 10, 0xf4, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x50, 0x5f, buffer[i], 0xff);
		//stlink_read1(pgm, 1); // 4e
		if(!stlink_read_and_cmp(pgm, 1, 0x4e))
			sent++;
	}
	return(sent);
}

