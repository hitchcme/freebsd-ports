# Created by: Greg Lewis <glewis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zoneinfo
DISTVERSION=	2014b
CATEGORIES=	java misc
MASTER_SITES=	${MASTER_SITE_LOCAL:S|%SUBDIR%|glewis/javazi|}
PKGNAMEPREFIX=	java-
DISTNAME=	javazi-${DISTVERSION}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Updated Java timezone definitions

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

JAVASHAREDIR=	${PREFIX}/share/java

do-install:
	${MKDIR} ${STAGEDIR}${JAVASHAREDIR}/zi
	(cd ${WRKSRC}/zi && ${COPYTREE_SHARE} . ${STAGEDIR}${JAVASHAREDIR}/zi)

.include <bsd.port.mk>
