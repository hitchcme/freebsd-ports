# Created by: Peter Jeremy <peterjeremy@optushome.com.au>
# $FreeBSD$

PORTNAME=	jogl
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	graphics devel java
MASTER_SITES=http://download.java.net/media/jogl/builds/archive/jsr-231-1.1.1/
EXTRACT_SUFX=	-src.zip

MAINTAINER=	peterj@FreeBSD.org
COMMENT=	Java bindings for OpenGL

LIB_DEPENDS=	libdrm.so:${PORTSDIR}/graphics/libdrm
BUILD_DEPENDS=	${JAVALIBDIR}/antlr.jar:${PORTSDIR}/devel/antlr

CONFLICTS=	jogamp-jogl-*

NO_WRKSUBDIR=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

ALL_TARGET=	all

# Java currently only supports i386 and amd64.  Supporting additional
# architectures will need patches to at least
# gluegen/src/java/com/sun/gluegen/StructLayout.java
# gluegen/src/java/com/sun/gluegen/runtime/CPU.java
# gluegen/make/gluegen-cpptasks.xml
# jogl/make/build.xml
ONLY_FOR_ARCHS=	i386 amd64

USES=		zip
USE_XORG=	x11 xau xdamage xdmcp xext xf86vidmodeproto xfixes xproto xt \
		xxf86vm
USE_GL=		gl
USE_ANT=	yes
USE_LDCONFIG=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

BUILD_WRKSRC=	${WRKSRC}/jogl/make
BUILD_BINPATH=	${WRKSRC}/bin
MAKE_ENV+=	PATH="${BUILD_BINPATH}:${PATH}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	javadoc
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%JAVALIBDIR%%|${JAVALIBDIR}|g' \
		${WRKSRC}/gluegen/make/build.xml
	@${REINPLACE_CMD} -e 's|%%JAVALIBDIR%%|${JAVALIBDIR}|g' \
			  -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/jogl/make/build.xml

pre-build:
	${MKDIR} ${BUILD_BINPATH}
	${LN} -sf /usr/bin/cc ${BUILD_BINPATH}/gcc

do-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/jogl/doc/userguide/index.html \
		${STAGEDIR}${DATADIR}/UserGuide.html
	cd ${BUILD_WRKSRC}/../javadoc_public && \
		${FIND} . -print | ${CPIO} -pdm ${STAGEDIR}${DATADIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/gluegen/build/obj/libgluegen-rt.so \
		${WRKSRC}/jogl/build/obj/libjogl.so \
		${WRKSRC}/jogl/build/obj/libjogl_awt.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/gluegen/build/gluegen-rt.jar \
		${WRKSRC}/jogl/build/jogl.jar ${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.mk>
