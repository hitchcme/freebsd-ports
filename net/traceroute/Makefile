# Created by: chris@vader.org
# $FreeBSD$

PORTNAME=	traceroute
PORTVERSION=	${RELEASEDATE}
CATEGORIES=	net
MASTER_SITES=	http://mitya.pp.ru/
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Version of 'traceroute' that shows the AS network number of each hop

RELEASEDATE=	991603
NO_WRKSUBDIR=	yes
PLIST_FILES=	sbin/traceroute man/man8/traceroute.8.gz

do-install:
	${INSTALL} -c -m 4755 -o root -g bin ${WRKSRC}/traceroute \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/traceroute.8 ${STAGEDIR}${PREFIX}/man/man8
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/traceroute

.include <bsd.port.mk>
