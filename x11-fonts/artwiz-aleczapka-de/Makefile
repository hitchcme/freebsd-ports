# Created by: Herbert J. Skuhra <herbert.skuhra@gmx.at>
# $FreeBSD$

PORTNAME=	artwiz-aleczapka-de
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/artwizaleczapka/iso-8859-1/${PORTVERSION}

MAINTAINER=	herbert.skuhra@gmx.at
COMMENT=	A set of (improved) artwiz fonts

NO_BUILD=	yes
USE_BZIP2=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

FONTS=	anorexia.de aqui.de cure.de drift.de edges.de fkp.de gelly.de \
	glisp-bold.de glisp.de kates.de lime.de mints-mild.de \
	mints-strong.de nu.de smoothansi.de snap.de
FONTDIR=	${LOCALBASE}/lib/X11/fonts/${PORTNAME}/
FILES=	${FONTS:S,$,.pcf,} ${WRKSRC}/fonts.alias \
	${WRKSRC}/fonts.dir

do-install:
	${MKDIR} ${STAGEDIR}${FONTDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${FILES} ${STAGEDIR}${FONTDIR}

post-install:
	@${SED} 's|$${LOCALBASE}|${LOCALBASE}|g' \
		${PKGDIR}/pkg-message >${PKGMESSAGE}

.include <bsd.port.mk>
