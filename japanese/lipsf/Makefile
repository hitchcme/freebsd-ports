# Created by: Mita Yoshio <mita@jp.FreeBSD.org>
# $FreeBSD$

PORTNAME=	lipsf
PORTVERSION=	2.00
PORTREVISION=	1
CATEGORIES=	japanese print
MASTER_SITES=	http://hp.vector.co.jp/authors/VA012337/soft/lipsf/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text to LIPS filter

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.//}

MANLANG=	ja
MAN1=		lipsf.1 pols.1

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in HISTORY Install README TECHKNOW
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
