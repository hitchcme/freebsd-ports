# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	WordNet
PORTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://wordnetcode.princeton.edu/${PORTVERSION}/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Dictionaries and thesauri with devel. libraries (C, TCL) and browsers

USES=		tcl
SCRIPTS_ENV+=	TCL_DVER=${TCL_VER} VER=${PORTVERSION}
MAKE_ENV+=	TCL_DVER=${TCL_VER} VER=${PORTVERSION}
PLIST_SUB+=	TCL_DVER=${TCL_VER} VER=${PORTVERSION}
USE_BZIP2=	yes
REINPLACE_ARGS=	-i ""
USE_LDCONFIG=	yes
SUB_FILES=	pkg-message
SUB_LIST+=	TCL_VER=${TCL_VER}

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's,/usr/local/WordNet-2.1,${DATADIR},g' \
	    ${WRKSRC}/src/wnb ${WRKSRC}/doc/man/*.?
	${REINPLACE_CMD} -e 's,  *\\n,\\n,' ${WRKSRC}/include/wn.h

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.for s in 1 3 5 7
MAN$s	!=	${MAKE} -f ${FILESDIR}/man.Makefile -V MAN$s
.endfor

.include <bsd.port.post.mk>
