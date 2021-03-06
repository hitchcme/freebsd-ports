# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shiboken
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.pyside.org/files/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C++ code generator for CPython extensions

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libxslt.so:${PORTSDIR}/textproc/libxslt

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		PYTHON_VERSION=${PYTHON_VERSION}

USE_QT4=	gui qmake_build qtestlib moc_build \
		uic_build rcc_build xml xmlpatterns

USE_BZIP2=	yes
USES=		cmake
USE_LDCONFIG=	yes
USE_PYTHON=	yes

ALL_TARGET=	all

OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMANPAGES}
MAN1=	shiboken.1
.else
CMAKE_ARGS=	-DNO_INSTALL_MANPAGES:BOOL="ON"
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
ALL_TARGET+=	doc
post-install:
	if [ -d ${WRKSRC}/doc/html ]; then \
		${MKDIR} ${DOCSDIR} && \
		cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${DOCSDIR}; \
	fi
.endif

post-patch:
	@cd ${WRKSRC}/generator && \
	${MV} ${PORTNAME} ${PORTNAME}.dir

regression-test: build
	@${ECHO_MSG} "===> Running shiboken regression tests"
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
