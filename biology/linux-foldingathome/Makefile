# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	foldingathome
PORTVERSION=	5.04
CATEGORIES=	biology
MASTER_SITES=	http://www.stanford.edu/group/pandegroup/release/
PKGNAMEPREFIX=	linux-
DISTNAME=	FAH${PORTVERSION:S/.//}-Linux
EXTRACT_SUFX=	.exe

MAINTAINER=	onatan@gmail.com
COMMENT=	Distributed client for Protein Folding

USE_LINUX=	yes
ONLY_FOR_ARCHS=	i386 amd64
REINPLACE_ARGS=
PLIST_FILES=	share/${PORTNAME}/${DISTNAME}${EXTRACT_SUFX} \
		bin/FoldingAtHome
PLIST_DIRS=	share/${PORTNAME}

NO_STAGE=	yes
do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX}
	${CHMOD} 755 ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX}

do-install:
	${MKDIR} ${PREFIX}/bin
	${REINPLACE_CMD} -e "s|DATADIR|${DATADIR}|" ${SCRIPTDIR}/FoldingAtHome \
		| ${REINPLACE_CMD} -e "s|BINNAME|${DISTNAME}${EXTRACT_SUFX}|" \
		> ${PREFIX}/bin/FoldingAtHome
	${CHMOD} 755 ${PREFIX}/bin/FoldingAtHome
	${MKDIR} ${DATADIR}
	${CP} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX} ${DATADIR}/

.include <bsd.port.mk>
