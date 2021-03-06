#include "emu.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdarg.h>


int _kern_printf(char* fmt, ...) {

	int retval = 0;
	va_list ap;

	va_start(ap, fmt); /* Initialize the va_list */

	retval = vprintf(fmt, ap); /* Call vprintf */

	va_end(ap); /* Cleanup the va_list */

	return retval;
}

void *_kern_memcpy (void *destination, const void *source, int num) {
	return memcpy(destination, source, num);
}

void * _kern_malloc(int size) {
	return malloc(size);
}

void _kern_free(void *ptr) {
	return free(ptr);
}

void *_kern_realloc(void *ptr, int size) {
	return realloc(ptr, size);
}