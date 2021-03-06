# Created by: Jing-Tang Keith Jang <keith@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ttfm
PORTVERSION=	0.9.5
PORTREVISION=	5
CATEGORIES=	chinese print
MASTER_SITES=	LOCAL/rafan/chinese

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	A Big5/GB enhanced TrueType Font Manager

RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale
LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

MAKE_ARGS=	FREETYPE_BASE=${LOCALBASE:Q} CC="${CC}"

PORTDOCS=	README USAGE

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' \
		-e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/modules/gscjk.ttfm \
		${WRKSRC}/modules/xttfm.ttfm \
		${WRKSRC}/ttfm.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttfinfo ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/ttfm.sh ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}/
.endfor
	${INSTALL_MAN} ${WRKSRC}/ttfm.sh.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for module in gscjk.ttfm xttfm.ttfm
	${INSTALL_SCRIPT} ${WRKSRC}/modules/${module} ${STAGEDIR}${DATADIR}/
.endfor

.include <bsd.port.mk>
