# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$
#  $MCom: ports/graphics/clutter/Makefile,v 1.34 2010/09/24 16:35:42 kwm Exp $

PORTNAME=	clutter
PORTVERSION=	1.4.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	GNOME \
		http://source.clutter-project.org/sources/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenGL based interactive canvas library

LIB_DEPENDS=	libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib

LICENSE=	LGPL21

USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_GNOME=	gdkpixbuf2 gnomeprefix atk pango introspection:build
INSTALL_TARGET=	install-strip
USE_GL=		gl
USE_XORG=	glproto x11 xfixes xdamage xcomposite xi
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x --enable-conformance=no

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|G_CONST_RETURN|const|g' \
		${WRKSRC}/clutter/cally/*.c \
		${WRKSRC}/clutter/*.[ch] \
		${WRKSRC}/clutter/glx/*.c \
		${WRKSRC}/clutter/x11/*.h \
		${WRKSRC}/clutter/cogl/cogl/*.h \
		${WRKSRC}/clutter/json/*.c
	@${REINPLACE_CMD} -e 's|-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/clutter/Makefile.in

.include <bsd.port.mk>
