# $FreeBSD$

PORTNAME=	smokeqt
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SMOKE bindings for Qt

LIB_DEPENDS=	libqscintilla2.so:${PORTSDIR}/devel/qscintilla2 \
		libqwt.so:${PORTSDIR}/x11-toolkits/qwt5

USE_KDE4=	kdehier kdeprefix smokegen qimageblitz
USE_QT4=	corelib dbus declarative designer_build gui help \
		multimedia network opengl phonon qtestlib script \
		sql svg webkit xml xmlpatterns \
		qmake_build moc_build uic_build rcc_build
USES=		cmake:outsource tar:xz
USE_LDCONFIG=	yes

.include <bsd.port.mk>
