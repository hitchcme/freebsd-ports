# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	unico
PORTVERSION=	1.0.2
CATEGORIES=	x11-themes
MASTER_SITES=	https://launchpadlibrarian.net/98881788/ \
	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/ \
	LOCAL/olivierd
PKGNAMEPREFIX=	gtk3-
PKGNAMESUFFIX=	-engine

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Gtk+ 3.0 engine

LICENSE=	LGPL3

GNU_CONFIGURE=	yes
USES=		pkgconfig gmake
USE_GNOME=	cairo glib20 gtk30
USE_LDCONFIG=	yes

.include <bsd.port.mk>
