#ifndef _KERNEL_KERN_IO_H_INCLUDED_
#define _KERNEL_KERN_IO_H_INCLUDED_

#include "types.h"
#include "error.h"

//#############################################################################
// ## default handles
//#############################################################################
#define SH_NULL			0
#define SH_STDOUT 		1
#define SH_STDIN		2
#define SH_ROOT_STREAM	3

//#############################################################################
// ## protocol list
//#############################################################################
#define PROTOCOL_NULL			0
#define PROTOCOL_STREAM			1
#define PROTOCOL_SEEKSTREAM		2
#define PROTOCOL_DIRECTORY		3

//#############################################################################
// ## default protocol
//#############################################################################
#define POCKET_DEFAULT         	0

//#############################################################################
// ## seek stream protocol
//#############################################################################
#define POCKET_SEEKSTREAM_POS   1

//#############################################################################
// ## directory protocol
//#############################################################################
#define POCKET_DIRECTORY_STREAMCOUNT	1
#define POCKET_DIRECTORY_STREAMS		2

#define STREAM_ENTRY_NAME_LENGTH		32

struct stream_entry {
	char stream_name[STREAM_ENTRY_NAME_LENGTH];
};

//#############################################################################
// ## stream stats
//#############################################################################
#define ACCESS_READ   0x1
#define ACCESS_WRITE  0x2

struct stream_stat {
    access_t access;
    protocol_t protocol;
};

//#############################################################################
// ## pocket buffer
//#############################################################################

struct pocket_buffer {
	pocket_t pocket_id;
	k_size_t size;
};

//#############################################################################
// ## raw fs access
//#############################################################################
struct stream_handle {
	protocol_t protocol;
};

typedef error_t (_read_fc)(struct stream_handle *h, void *buffer, k_size_t *read_byte_count);
typedef error_t (_write_fc)(struct stream_handle *h, void *buffer, k_size_t *read_byte_count);

struct driver_callback {
	_read_fc *read_fc;
	_write_fc *write_fc;
};

error_t _kern_read(streamh_t sh, void *buffer, k_size_t *read_byte_count);
error_t _kern_write(streamh_t sh, void *buffer, k_size_t *write_byte_count);
streamh_t _kern_open(streamh_t directory, char *name, mode_t mode);
error_t _kern_close(streamh_t sh);
streamh_t _kern_reopen(streamh_t sh);
error_t _kern_stat(streamh_t directory, char *name, struct stream_stat *stat_buffer, k_size_t buffer_size);
error_t _kern_stat_h(streamh_t sh, struct stream_stat *stat_buffer, k_size_t buffer_size);

//#############################################################################
// ## higher level fs access
//#############################################################################
error_t _kern_screate(char *path, protocol_t type);
error_t _kern_fwrite(streamh_t sh, void *buffer, k_size_t *write_byte_count);
error_t _kern_fread(streamh_t sh, void *buffer, k_size_t *read_byte_count);
error_t _kern_fopen(char *path, mode_t mode);

#endif //_KERNEL_KERN_IO_H_INCLUDED_