# Created by: Maurice Castro <maurice@serc.rmit.edu.au>
# $FreeBSD$

PORTNAME=		dc20pack
PORTVERSION=		1.0
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/capture
EXTRACT_SUFX=		.tgz

MAINTAINER=		maurice@castro.aus.net
COMMENT=	Digital camera control and download tool for Kodak DC20/25 camera

WRKSRC=			${WRKDIR}

post-extract:
	for file in `${FIND} ${WRKSRC} -type f`; do \
		${TR} -d '\015' < $${file} > $${file}.new; \
		mv $${file}.new $${file}; \
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dc20dump ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dc20term ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dc2totga ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
