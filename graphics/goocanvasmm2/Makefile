# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/graphics/goocanvasmm2/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	goocanvasmm
PORTVERSION=	1.90.9
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	C++ bindings for the goocanvas widget for GTK

LIB_DEPENDS=	libgoocanvas-2.0.so:${PORTSDIR}/graphics/goocanvas2

USES=		gmake libtool:keepla pathfix pkgconfig tar:xz
USE_GNOME=	gtkmm30
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-documentation
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
