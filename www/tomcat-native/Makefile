# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tomcat-native
PORTVERSION=	1.1.30
CATEGORIES=	www java
MASTER_SITES=	APACHE
MASTER_SITE_SUBDIR=	tomcat/tomcat-connectors/native/${PORTVERSION}/source
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Tomcat native library

LICENSE=	APACHE20

LIB_DEPENDS=	libapr-1.so:${PORTSDIR}/devel/apr1

WRKSRC=		${WRKDIR}/${DISTNAME}/jni/native

OPTIONS_DEFINE=	OCSP
OCSP_DESC=	Enable OCSP verification support

USE_OPENSSL=	yes
USE_JAVA=	yes
USE_LDCONFIG=	yes
JAVA_VERSION=	1.6+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-apr=${LOCALBASE} \
		--with-java-home=${JAVA_HOME} \
		--with-ssl=${SSLBASE}

PLIST_FILES=	lib/libtcnative-1.a \
		lib/libtcnative-1.la \
		lib/libtcnative-1.so \
		lib/libtcnative-1.so.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOCSP}
CONFIGURE_ARGS+=--enable-ocsp
.endif

.include <bsd.port.mk>
