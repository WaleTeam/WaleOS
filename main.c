
#include "stdinc.h"
#include "kern_io.h"


error_t _kern_boot();

int main() {

	int errno = ERROR_NONE;
	
	k_size_t size = 0;

	_kern_read(SH_ROOT_STREAM, 0, &size);
	_kern_printf("%i\n", size);

	void *buffer = _kern_malloc(size);

	if((errno = _kern_read(SH_ROOT_STREAM, buffer, &size)) == ERROR_NONE) {

		_kern_printf("directory stream of size: %i read\n", size);

		struct stream_entry *entry = (struct stream_entry *)buffer;

		while(entry->stream_name[0] != 0x00) {
			_kern_printf("%s\n", entry->stream_name);
			entry++;
		}
	} else {
		_kern_printf("error code: %i\n", errno);
	}

	_kern_free(buffer);

	return ERROR_NONE;
}