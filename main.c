
#include "stdinc.h"
#include "kern_io.h"


error_t _kern_boot();

char testbuffer[2048];

int main() {

	int errno = ERROR_NONE;
	k_size_t size = 2048;

	if((errno = _kern_read(SH_ROOT_STREAM, testbuffer, &size)) == ERROR_NONE) {

		_kern_printf("directory read: %i\n", size);
		_kern_printf("buffer: %s\n", testbuffer);
	} else {
		_kern_printf("error code: %i\n", errno);
	}

	return ERROR_NONE;
}