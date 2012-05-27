#ifndef _KERN_STREAM_H_INCLUDED_
#define _KERN_STREAM_H_INCLUDED_

#include "kern_io.h"

error_t _stream_read(struct stream_handle *h, void *buffer, k_size_t *read_byte_count);
error_t _stream_write(struct stream_handle *h, void *buffer, k_size_t *read_byte_count);

#endif //_KERN_STREAM_H_INCLUDED_