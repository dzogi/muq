/**
 * Functions for manipulating the video buffer at 0xB8000
 */
 
#include <arch/video.h>
#include <string.h>

#define VIDEO_BUF 0xB8000

static unsigned int x = 0, y = 0;
static u16_t *video_mem = (u16_t *)VIDEO_BUF;

#define POINT(x,y) (video_mem + y*80 + x)
#define CHAR(chr, color, bgcolor) ((chr) | (color<<8) | (bgcolor<<12))

void video_init(void) 
{
	x = 0, y = 0;
}

static void scroll(void)
{
	memcpy(video_mem+80, video_mem, 24*80*2);
	memset16(video_mem+80*24, CHAR(' ', 5, 5), 80);
}

int putchar(int character) {
	char c = (char) character;
	
	if(x >= 80) {
		y++;
		x = 0;
	}
	
	if (y >= 25) {
		scroll();
	}
	
	switch(c) {
		case '\n':
			x = 0;
			y++;
		break;
		
		case '\t':
			x += 8;
		break;
		
		default:
			*POINT(x++, y) = CHAR(c, 1, 2);
		break;
	}
	
	return character;
}

