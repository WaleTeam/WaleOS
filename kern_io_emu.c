#include "kern_io.h"
#include "driver/kern_stream.h"
#include "driver/kern_dir.h"

#include <stdio.h>

#define STREAM_HANDLE_SIZE 32

//#############################################################################
// driver lookup
//#############################################################################
int stream_handle_size = STREAM_HANDLE_SIZE;
struct stream_handle stream_handles[STREAM_HANDLE_SIZE] = {
	{PROTOCOL_NULL},
	{PROTOCOL_STREAM},
	{PROTOCOL_STREAM},
	{PROTOCOL_DIRECTORY}
};

struct driver_callback driver_callbacks[] = {
	{0, 0},
	{_stream_read, _stream_write},
	{_stream_read, _stream_write},
	{_dir_read, _dir_write}
};

//#############################################################################
// raw fs access
//#############################################################################
error_t _kern_boot() {
	return ERROR_NONE;
}

error_t _kern_screate(streamh_t directory, char *name, protocol_t type) {
	return ERROR_NONE;
}

error_t _kern_read(streamh_t sh, void *buffer, k_size_t *read_byte_count) {

	printf("protocol type: %i\n", sh);

	struct stream_handle *h = &stream_handles[sh];

	printf("handle is %i -> %i\n", &stream_handles, &stream_handles[sh]);
	printf("handle type is %i\n", h->protocol);

	struct driver_callback *callback = &driver_callbacks[h->protocol];

	if(callback == 0) {
		return ERROR_GENERIC;
	}

	return callback->read_fc(h, buffer, read_byte_count);
}

error_t _kern_write(streamh_t sh, void *buffer, k_size_t *write_byte_count) {
	struct stream_handle *h = &stream_handles[sh];
	struct driver_callback *callback = &driver_callbacks[h->protocol];

	if(callback == 0) {
		return ERROR_GENERIC;
	}

	return callback->write_fc(h, buffer, write_byte_count);
}

streamh_t _kern_open(streamh_t directory, char *name, mode_t mode) {
	return ERROR_NONE;
}

error_t _kern_close(streamh_t sh) {
	return ERROR_NONE;
}

streamh_t _kern_reopen(streamh_t sh) {
	return ERROR_NONE;
}

error_t _kern_stat(streamh_t directory, char *name, struct stream_stat *stat_buffer, k_size_t buffer_size) {
	return ERROR_NONE;
}

error_t _kern_stat_h(streamh_t sh, struct stream_stat *stat_buffer, k_size_t buffer_size) {
	return ERROR_NONE;
}

//#############################################################################
// higher level fs access
//#############################################################################
error_t _kern_fwrite(streamh_t sh, void *buffer, k_size_t *write_byte_count) {
	return ERROR_NONE;
}

error_t _kern_fread(streamh_t sh, void *buffer, k_size_t *read_byte_count) {
	return ERROR_NONE;
}

error_t _kern_fopen(char *path, mode_t mode) {
	return ERROR_NONE;
}

