# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pejv-fpw
PORTVERSION=	1.0.4
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/pejv/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Esperanto-Japanese dictionary (EPWING V1 format)

USES=		zip:infozip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/pejv
EXTRACT_BEFORE_ARGS=	-qL

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/share/dict/pejv-fpw/pejv/data
	${INSTALL_DATA} ${WRKSRC}/pejv/data/honmon ${PREFIX}/share/dict/pejv-fpw/pejv/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/pejv-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in readme legumin.doc pejvo.doc
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
