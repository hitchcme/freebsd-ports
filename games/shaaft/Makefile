# Created by: Kirill Ponomarew <krion@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shaaft
PORTVERSION=	0.5.0
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	SF/criticalmass/OldFiles
DISTNAME=	Shaaft-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL 3D falling block game similar to Blockout

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

CONFLICTS=	criticalmass-*

USE_BZIP2=	yes
USE_SDL=	mixer image sdl
USE_GL=		yes
USE_GCC=	any
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-optimize

CPPFLAGS+=	$$(libpng-config --I_opts)
LDFLAGS+=	$$(libpng-config --L_opts)

DATADIR=	${PREFIX}/share/Shaaft

PLIST_FILES=	bin/Packer bin/shaaft %%DATADIR%%/resource.dat \
		man/man6/shaaft.6.gz
PLIST_DIRS=	%%DATADIR%%

DESKTOP_ENTRIES="Shaaft" "" "" "${PORTNAME}" "" ""

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG:T}|g ; \
		s|^CXXFLAGS|#CXXFLAGS|g ; \
		s|/usr/X11R6|${LOCALBASE}|g ; \
		s|-lSDL | |g ; \
		s|-lpng12|-lpng|g' ${WRKSRC}/configure
	@${GREP} -lR "SDL/SDL" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|SDL/SDL|SDL|g'
	@${REINPLACE_CMD} -e 's|== 3|>= 3|' ${WRKSRC}/utils/hashMap.hpp

.include <bsd.port.post.mk>
