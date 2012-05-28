#ifndef _KERN_EMU_H_INCLUDED_
#define _KERN_EMU_H_INCLUDED_


int _kern_printf(char* fmt, ...);
void * _kern_memcpy (void *destination, const void *source, int num);
void * _kern_malloc(int size);
void _kern_free(void *pointer);
void * _kern_realloc(void * ptr, int size);


#endif //_KERN_EMU_H_INCLUDED_