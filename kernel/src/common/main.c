void __attribute__((noreturn))
kernel_main(void)
{
	u16_t* video_buf = (u16_t*) 0xB8000;
	while(1) {
		(*video_buf)++;
	}
}

