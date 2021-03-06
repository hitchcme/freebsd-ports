# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	lopster
PORTVERSION=	1.2.2
PORTREVISION=	11
CATEGORIES=	net-p2p
MASTER_SITES=	SF \
		http://lopster.sourceforge.net/download/

MAINTAINER=	conrads@cox.net
COMMENT=	GTK+ client for Napster and free alternatives

GNU_CONFIGURE=	yes
USES=		gmake
USE_GNOME=	gtk12
CONFIGURE_ARGS=	--with-pthread=yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	FLAC OGG ZLIB
OPTIONS_DEFAULT=	FLAC OGG ZLIB

.include <bsd.port.options.mk>

# --with-flac is on by default
.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=		FLAC:${PORTSDIR}/audio/flac
.else
CONFIGURE_ARGS+=	--without-flac
.endif

# --with-ogg is on by default
.if ${PORT_OPTIONS:MOGG}
LIB_DEPENDS+=		ogg:${PORTSDIR}/audio/libogg
.else
CONFIGURE_ARGS+=	--without-ogg
.endif

# --with-zlib is on by default
.if ! ${PORT_OPTIONS:MZLIB}
CONFIGURE_ARGS+=	--without-zlib
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s/www.naplist.com/www.gotnap.com/" \
		${WRKSRC}/src/lopster.h

.include <bsd.port.mk>
