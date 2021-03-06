# Created by: Paul Everlund
# $FreeBSD$

PORTNAME=	xmedcon
PORTVERSION=	0.13.0
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/XMedCon-Source/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Medical image conversion utility and library

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

USES=		pkgconfig tar:bzip2
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/xmedcon \
		--enable-llcheck
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	X11 GLIB ACR_NEMA ANALYZE CONCORDE DICOM DICOM_LJPEG ECAT GIF \
		INTERFILE INW PNG
OPTIONS_DEFAULT=X11 GLIB ACR_NEMA ANALYZE CONCORDE DICOM DICOM_LJPEG ECAT GIF \
		INTERFILE INW PNG
OPTIONS_SUB=	yes

X11_CONFIGURE_ENABLE=	gui
X11_USE=		GNOME=gtk20

GLIB_DESC=		With Glib
GLIB_CONFIGURE_ENABLE=	glib
GLIB_USE=		GNOME=glib20

ACR_NEMA_DESC=		With Acr/Nema 2.0

ANALYZE_DESC=		With Analyze (SPM)
ANALYZE_CONFIGURE_ENABLE=	anlz

CONCORDE_DESC=		With Concorde __ET
CONCORDE_CONFIGURE_ENABLE=	conc

DICOM_DESC=		With DICOM 3.0

DICOM_LJPEG_DESC=	With DICOM 3.0 Lossless JPEG
DICOM_LJPEG_CONFIGURE_ENABLE=	ljpg

ECAT_DESC=		With CTI ECAT 6/7
ECAT_CONFIGURE_ENABLE=	ecat

INTERFILE_DESC=		With InterFile 3.3
INTERFILE_CONFIGURE_ENABLE=	intf

INW_DESC=		With INW (RUG)
INW_CONFIGURE_ENABLE=	inw

GIF_CONFIGURE_OFF=	--disable-gif

PNG_CONFIGURE_ENABLE=	png
PNG_LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
DESKTOP_ENTRIES="XMedCon" "" "${PREFIX}/etc/xmedcon.png" "${PORTNAME}" "" ""
.endif

.if empty(PORT_OPTIONS:MACR_NEMA) || empty(PORT_OPTIONS:MDICOM)
CONFIGURE_ARGS+=	--disable-acr
.endif

.if empty(PORT_OPTIONS:MDICOM) || empty(PORT_OPTIONS:MDICOM_LJPEG)
CONFIGURE_ARGS+=	--disable-dicom
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|etc||g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^configheadersdir/s|=.*$$|= $$(includedir)|g' \
		${WRKSRC}/source/Makefile.in
	@${REINPLACE_CMD} -e '/xmedcon.1/d' \
		${WRKSRC}/man/Makefile.in

post-install:
.if ${PORT_OPTIONS:MX11}
.for file in xmedcon.png xmedconrc xmedconrc.linux
	${INSTALL_DATA} ${WRKSRC}/etc/${file} ${STAGEDIR}${PREFIX}/etc
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/xmedcon.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endif

.include <bsd.port.mk>
