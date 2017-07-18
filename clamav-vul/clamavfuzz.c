/*
 *  Compilation: gcc -Wall ex1.c -o ex1 -lclamav
 *
 *  Copyright (C) 2015 Cisco Systems, Inc. and/or its affiliates. All rights reserved.
 *  Copyright (C) 2007 - 2009 Sourcefire, Inc.
 *  Author: Tomasz Kojm <tkojm@clamav.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *  MA 02110-1301, USA.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <clamav.h>

int main(int argc, char **argv)
{
	int fd, ret;
	unsigned long int size = 0;
	const char *virname;
	struct cl_engine *engine;

    if(argc != 2) {
	printf("Usage: %s file\n", argv[0]);
	return 2;
    }

    if((ret = cl_init(CL_INIT_DEFAULT)) != CL_SUCCESS) {
	printf("Can't initialize libclamav: %s\n", cl_strerror(ret));
	return 2;
    }

    if(!(engine = cl_engine_new())) {
	printf("Can't create new engine\n");
	return 2;
    }


    if((ret = cl_engine_compile(engine)) != CL_SUCCESS) {
	printf("Database initialization error: %s\n", cl_strerror(ret));;
        cl_engine_free(engine);
	return 2;
    }

#ifdef __AFL_LOOP
	while(__AFL_LOOP(2000)){
#endif
    if((fd = open(argv[1], O_RDONLY)) == -1) {
	printf("Can't open file %s\n", argv[1]);
#ifdef __AFL_LOOP
	continue;
#endif
	return 2;
    }

    if((ret = cl_scandesc(fd, &virname, &size, engine, CL_SCAN_STDOPT)) == CL_VIRUS) {
	printf("Virus detected: %s\n", virname);
    } else {
	if(ret == CL_CLEAN) {
	} else {
	    printf("Error: %s\n", cl_strerror(ret));
	    close(fd);
#ifdef __AFL_LOOP
	continue;

#endif
		cl_engine_free(engine);
	    return 2;
	}
    }
    close(fd);
#ifdef __AFL_LOOP
	}
#endif

    cl_engine_free(engine);

	return 0;
}
