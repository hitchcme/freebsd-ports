# Created by: Steve Woodford <scw@netbsd.hut.fi>
# $FreeBSD$

PORTNAME=	tits
PORTVERSION=	1.1.2
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	http://www.mctavish.co.uk/tits/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	A server which provides telnet(1) access to one or more tty ports

LICENSE=	BSD4CLAUSE

MAKE_ENV=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man

USE_RC_SUBR=	tits

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/tits.8

post-install:
	${INSTALL_DATA} ${WRKSRC}/tits.conf \
		${STAGEDIR}${PREFIX}/etc/tits.conf.default

.include <bsd.port.mk>
