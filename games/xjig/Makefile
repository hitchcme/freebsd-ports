# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# $FreeBSD$

PORTNAME=	xjig
PORTVERSION=	2.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jigsaw puzzle game for X11

USES=		compiler
USE_XORG=	x11 xproto xext
MAKEFILE=	Makefile.Linux
PLIST_FILES=	bin/xjig man/man1/xjig.1.gz

.include <bsd.port.pre.mk>

post-patch:
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} 's|-fpcc-struct-return||' ${WRKSRC}/Makefile.Linux
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xjig ${STAGEDIR}${PREFIX}/bin/xjig
	${INSTALL_MAN} ${WRKSRC}/xjig.man ${STAGEDIR}${PREFIX}/man/man1/xjig.1

.include <bsd.port.post.mk>
