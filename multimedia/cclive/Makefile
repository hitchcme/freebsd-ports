# Created by: Toni Gundogdu <legatvs@gmail.com>
# $FreeBSD$

PORTNAME=	cclive
PORTVERSION=	0.7.16
CATEGORIES=	multimedia net
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION:R} \
		GOOGLE_CODE

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Lightweight command line video extraction tool

LICENSE=	GPLv3

LIB_DEPENDS=	libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libquvi.so:${PORTSDIR}/multimedia/libquvi

USES=		pkgconfig
USE_XZ=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost=${LOCALBASE}

PLIST_FILES=	bin/ccl \
		bin/cclive \
		man/man1/cclive.1.gz

.include <bsd.port.mk>
