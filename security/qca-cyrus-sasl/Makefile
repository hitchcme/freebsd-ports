# $FreeBSD$

PORTNAME=	qca-cyrus-sasl
DISTVERSION=	2.0.0-beta3
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://delta.affinix.com/download/qca/2.0/plugins/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QCA Cyrus SASL plugin

LIB_DEPENDS=	libqca.so:${PORTSDIR}/devel/qca \
		libsasl2.so:${PORTSDIR}/security/cyrus-sasl2

USE_BZIP2=	yes
USE_QT4=	corelib qmake_build moc_build
HAS_CONFIGURE=	yes
QT_NONSTANDARD=	yes
CONFIGURE_ARGS+=--plugins-path=${PREFIX}/${QT_PLUGINDIR_REL} \
		--with-sasl-inc=${LOCALBASE}/include \
		--with-sasl-lib=${LOCALBASE}/lib
DESTDIRNAME=	INSTALL_ROOT

OPTIONS_DEFINE=	DEBUG
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ON=	--debug
DEBUG_CONFIGURE_OFF=	--release --no-separate-debug-info

.include <bsd.port.mk>
