# Created by: Nsand <nsand@sura.ru>
# $FreeBSD$

PORTNAME=	skyfish
PORTVERSION=	0.91
CATEGORIES=	net kld
MASTER_SITES=	ftp://ftp.lissyara.su/users/nsand/skyfish/

MAINTAINER=	nsand@sura.ru
COMMENT=	Grabbing TCP streams from network interface (SAT internet)

SSP_UNSAFE=	kernel module does not support ssp

NO_STAGE=	yes
.include <bsd.port.pre.mk>

SYSDIR?=	${SRC_BASE}/sys
KMODDIR=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR}

MAN1=		skyfish.1
MANCOMPRESSED=	yes

pre-fetch:
.if !exists(${SYSDIR}/Makefile)
	@${ECHO} "*************************************************"; \
	${ECHO}  "This port requires the kernel source be available"; \
	${ECHO}  "*************************************************"; \
	exit 1
.endif

.include <bsd.port.post.mk>
