# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pkg_trackinst
PORTVERSION=	1.2.3
PORTREVISION=	4
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://people.freebsd.org/~perky/distfiles/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	PkgDB/pkg-plist generator by tracking installation

USE_PYTHON=	yes
MAKE_ENV=	PYTHON_CMD=${PYTHON_CMD} STAGEDIR=${STAGEDIR}
PLIST_SUB+=	PYTHON_VER=${PYTHON_VER} VERSION=${PORTVERSION}

post-patch:
	${REINPLACE_CMD} 's,/usr/local,${PREFIX},g' \
		${WRKSRC}/PkgTrackInst/cmd_support.py

.include <bsd.port.mk>
