# Created by: ijliao
# $FreeBSD$

PORTNAME=	gplcver
PORTVERSION=	2.12.a
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}${PORTVERSION:E}/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Verilog HDL simulator

USES=		gmake
USE_BZIP2=	yes

BUILD_WRKSRC=	${WRKSRC}/src
MAKEFILE=	makefile.freebsd

PLIST_FILES=	bin/cver

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cver ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
