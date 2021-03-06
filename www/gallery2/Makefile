# Created by: Alex Varju <freebsd-ports@varju.ca>
# $FreeBSD$

PORTNAME=	gallery2
PORTVERSION=	2.3.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/gallery/${PORTNAME}/${PORTVERSION}
DISTNAME=	gallery-${PORTVERSION}-full
DIST_SUBDIR=	gallery2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Web based photo album organizer written in PHP

LICENSE=	GPLv2

OPTIONS_DEFINE=	DCRAW FFMPEG GD GRAPHMAGICK IMAGEMAGICK JHEAD NETPBM NLS UNZIP
OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	MYSQL PGSQL
OPTIONS_DEFAULT=IMAGEMAGICK JHEAD MYSQL UNZIP

NO_BUILD=	yes
USE_PHP=	pcre session
WANT_PHP_WEB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

SUB_FILES=	pkg-message

DCRAW_RUN_DEPENDS=	${LOCALBASE}/bin/dcraw:${PORTSDIR}/graphics/dcraw
FFMPEG_LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
GD_RUN_DEPENDS=		${LOCALBASE}/bin/pngtogd:${PORTSDIR}/graphics/gd
GD_USE=			PHP=gd
GRAPHMAGICK_RUN_DEPENDS=${LOCALBASE}/bin/gm:${PORTSDIR}/graphics/GraphicsMagick
IMAGEMAGICK_RUN_DEPENDS=${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick
JHEAD_RUN_DEPENDS=	${LOCALBASE}/bin/jhead:${PORTSDIR}/graphics/jhead
MYSQL_USE=		PHP=mysql
NETPBM_RUN_DEPENDS=	${LOCALBASE}/bin/giftopnm:${PORTSDIR}/graphics/netpbm
NLS_USE=		PHP=gettext
NLS_USES=		gettext
PGSQL_USE=		PHP=pgsql
UNZIP_RUN_DEPENDS=	${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip

do-install:
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
