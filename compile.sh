#!/bin/bash

clang -std=c99 -o build/kern -I . kern_io_emu.c driver/kern_stream.c driver/kern_dir.c main.c
