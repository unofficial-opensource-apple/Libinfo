/*
 * Copyright (c) 1999 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * Copyright (c) 1999-2003 Apple Computer, Inc.  All Rights Reserved.
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
/*
 * Copyright (c) 1992, 1993 Theo de Raadt <deraadt@theos.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by Theo de Raadt.
 * 4. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char *rcsid = "$OpenBSD: yperr_string.c,v 1.3 1996/08/19 08:35:12 tholo Exp $";
#endif /* LIBC_SCCS and not lint */

#include <sys/param.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/file.h>
#include <sys/uio.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <rpc/rpc.h>
#include <rpc/xdr.h>
#include <rpcsvc/yp.h>
#include <rpcsvc/ypclnt.h>

char *
yperr_string(incode)
	int             incode;
{
	static char     err[80];

	switch (incode) {
	case 0:
		return "Success";
	case YPERR_BADARGS:
		return "Request arguments bad";
	case YPERR_RPC:
		return "RPC failure";
	case YPERR_DOMAIN:
		return "Can't bind to server which serves this domain";
	case YPERR_MAP:
		return "No such map in server's domain";
	case YPERR_KEY:
		return "No such key in map";
	case YPERR_YPERR:
		return "YP server error";
	case YPERR_RESRC:
		return "Local resource allocation failure";
	case YPERR_NOMORE:
		return "No more records in map database";
	case YPERR_PMAP:
		return "Can't communicate with portmapper";
	case YPERR_YPBIND:
		return "Can't communicate with ypbind";
	case YPERR_YPSERV:
		return "Can't communicate with ypserv";
	case YPERR_NODOM:
		return "Local domain name not set";
	case YPERR_BADDB:
		return "Server data base is bad";
	case YPERR_VERS:
		return "YP server version mismatch - server can't supply service.";
	case YPERR_ACCESS:
		return "Access violation";
	case YPERR_BUSY:
		return "Database is busy";
	}
	(void) snprintf(err, sizeof(err), "YP unknown error %d\n", incode);
	return err;
}
