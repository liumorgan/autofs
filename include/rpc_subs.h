/* ----------------------------------------------------------------------- *
 *   
 *  rpc_subs.h - header file for rpc discovery
 *
 *   Copyright 2004 Ian Kent <raven@themaw.net> - All Rights Reserved
 *   Copyright 2004 Jeff Moyer <jmoyer@redaht.com> - All Rights Reserved
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, Inc., 675 Mass Ave, Cambridge MA 02139,
 *   USA; either version 2 of the License, or (at your option) any later
 *   version; incorporated herein by reference.
 *
 * ----------------------------------------------------------------------- */

#ifndef _RPC_SUBS_H
#define _RPC_SUBS_H

#include <nfs/nfs.h>
#include <linux/nfs2.h>
#include <linux/nfs3.h>

#define NFS4_VERSION		4

/* rpc helper subs */
#define RPC_PING_FAIL		0x0000
#define RPC_PING_V2		NFS2_VERSION
#define RPC_PING_V3		NFS3_VERSION
#define RPC_PING_V4		NFS4_VERSION
#define RPC_PING_UDP		0x0100
#define RPC_PING_TCP		0x0200
/*
 * Close options to allow some choice in how and where the TIMED_WAIT
 *  happens.
 */
#define RPC_CLOSE_DEFAULT	0x0000
#define RPC_CLOSE_ACTIVE	RPC_CLOSE_DEFAULT
#define RPC_CLOSE_NOLINGER	0x0001

#define PMAP_TOUT_UDP	3
#define PMAP_TOUT_TCP	5

#define HOST_ENT_BUF_SIZE       2048

struct conn_info {
	const char *host;
	unsigned short port;
	unsigned long program;
	unsigned long version;
	struct protoent *proto;
	unsigned int send_sz;
	unsigned int recv_sz;
	struct timeval timeout;
	unsigned int close_option;
};

unsigned short portmap_getport(struct conn_info *);
int rpc_ping(const char *, long, long, unsigned int);
int rpc_time(const char *, unsigned int, unsigned int, long, long, unsigned int, double *);

#endif

