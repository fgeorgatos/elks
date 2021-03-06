/*
 * shutdown.c
 *
 * Derived from reboot.c by:
 * Copyright 2000 Alistair Riddoch
 * ajr@ecs.soton.ac.uk
 *
 * This file may be distributed under the terms of the GNU General Public
 * License v2, or at your option any later version.
 */

/*
 * This is a small version of shutdown for use in the ELKS project.
 * It is not fully functional, and may not be the most efficient
 * implementation for larger systems. It minimises memory usage and
 * code size.
 */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(argc,argv)
int argc;
char ** argv;
{
	sync();
	if (umount("/")) {
		perror("poweroff umount");
		exit(1);
	}
	sleep(3);
	if (reboot(0x1D1E,0xC0DE,0xDEAD)) {
		perror("poweroff");
		exit(1);
	}
}
