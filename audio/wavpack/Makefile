# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wavpack
PORTVERSION=	4.60.1
CATEGORIES=	audio
MASTER_SITES=	http://www.wavpack.com/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Audio codec for lossless, lossy, and hybrid compression

LICENSE=	BSD

USE_BZIP2=	yes
USES=		pathfix pkgconfig iconv
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if ${MACHINE_CPU:Mmmx}
CONFIGURE_ARGS=	--enable-mmx
.endif

.include <bsd.port.mk>
