#include "kern_dir.h"
#include <memory.h>


#define ROOT_STREAM_COUNT 	10

int root_stream_size = ROOT_STREAM_COUNT;
int root_stream_count = 2;
struct stream_entry root_stream[ROOT_STREAM_COUNT] = {
	{"dev"}, {"net"}
};

error_t _dir_read(struct stream_handle *h, void *buffer, k_size_t *read_byte_count) {

	int dir_size = sizeof(root_stream);

	if(*read_byte_count < dir_size) {
		return ERROR_GENERIC;
	}

	*read_byte_count = dir_size;

	memcpy(buffer, &root_stream, dir_size);

	return ERROR_NONE;
}

error_t _dir_write(struct stream_handle *h, void *buffer, k_size_t *read_byte_count) {
	return ERROR_GENERIC;	
}