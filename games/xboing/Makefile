# Created by: janek
# $FreeBSD$

PORTNAME=	xboing
PORTVERSION=	2.4
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	X11 arcade game

LICENSE=	MIT

USES=		imake
USE_XORG=	xpm xext x11
WRKSRC=		${WRKDIR}/xboing

OPTIONS_DEFINE=SOUND
OPTIONS_DEFAULT=SOUND
OPTIONS_SUB=yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOUND}
MAKE_ENV+=	WITHOUT_AUDIO=True
.endif

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/X11/xboing/.xboing.scr

.include <bsd.port.mk>
