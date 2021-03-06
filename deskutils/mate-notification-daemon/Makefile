# Createdy by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	mate-notification-daemon
PORTVERSION=	1.6.1
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Send small notifications to your desktop

LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra \
		libnotify.so:${PORTSDIR}/devel/libnotify

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_MATE=	libmatewnck
USE_XORG=	x11
USE_GNOME=	glib20 gnomehier gtk20 intlhack librsvg2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dbus-services=${PREFIX}/share/dbus-1/services \
		--with-gtk=2.0
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PATHFIX_MAKEFILEIN=	Makefile.*

GLIB_SCHEMAS=	org.mate.NotificationDaemon.gschema.xml

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mate-notification-daemon/engines/lib*.so

.include <bsd.port.mk>
