# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	basic256
PORTVERSION=	1.1.0.0
CATEGORIES=	lang
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	kidbasic/${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Easy to use BASIC language and IDE for education

BUILD_DEPENDS=	espeak:${PORTSDIR}/audio/espeak \
		sqlite3:${PORTSDIR}/databases/sqlite3 \
		flex:${PORTSDIR}/textproc/flex

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		bison dos2unix qmake
USE_SDL=	sdl mixer
USE_QT4=	corelib gui network xml webkit moc_build rcc_build uic_build
QMAKE_SOURCE_PATH=	BASIC256.pro

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/BASIC256.pro

.include <bsd.port.mk>
