# Created by: Philippe Pepiot <phil@philpep.org>
# $FreeBSD$

PORTNAME=	adsuck
PORTVERSION=	2.3
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	http://opensource.conformal.com/snapshots/adsuck/ \
		http://philpep.org/pub/
EXTRACT_SUFX=	.tgz

MAINTAINER=	phil@philpep.org
COMMENT=	DNS relay for ad blocking

LICENSE=	ISCL

LIB_DEPENDS+=	libevent-2.0.so:${PORTSDIR}/devel/libevent2 \
		libldns.so:${PORTSDIR}/dns/ldns

CFLAGS+=	-I${LOCALBASE}/include/event2/compat \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/event2

USE_RC_SUBR=	adsuck

USERS=	_adsuck
GROUPS=	_adsuck

SUB_FILES+=	pkg-message

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e "s/-levent/-levent-2.0/g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/adsuck ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8.gz ${STAGEDIR}${MANPREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/files/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
