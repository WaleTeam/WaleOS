#!/bin/bash

clang -std=c99 -o build/kern -I . kern_io.c driver/kern_stream.c driver/kern_dir.c emu.c main.c
