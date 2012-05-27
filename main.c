
#include "kern_io.h"
#include <stdio.h>

error_t _kern_boot();

char testbuffer[2048];

int main() {

	int errno = ERROR_NONE;
	k_size_t size = 2048;

	if((errno = _kern_read(SH_ROOT_STREAM, testbuffer, &size)) == ERROR_NONE) {

		printf("directory read: %i\n", size);
		printf("%s\n", testbuffer);
	} else {
		printf("error code: %i\n", errno);
	}

	return ERROR_NONE;
}