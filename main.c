
#include "stdinc.h"
#include "kern_io.h"


error_t _kern_boot();

char testbuffer[2048];

int main() {

	int errno = ERROR_NONE;
	k_size_t size = 2048;

	if((errno = _kern_read(SH_ROOT_STREAM, testbuffer, &size)) == ERROR_NONE) {

		_kern_printf("directory stream of size: %i read\n", size);

		struct stream_entry *entry = (struct stream_entry *)&testbuffer;

		while(entry->stream_name[0] != 0x00) {
			_kern_printf("%s\n", entry->stream_name);
			entry++;
		}

	} else {
		_kern_printf("error code: %i\n", errno);
	}

	return ERROR_NONE;
}