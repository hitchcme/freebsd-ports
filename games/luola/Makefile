# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	luola
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/ # master site gone
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		stdlevels-6.0${EXTRACT_SUFX} \
		nostalgia-1.2${EXTRACT_SUFX}
DIST_SUBDIR=	luola

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D multiplayer cave-flying game

GNU_CONFIGURE=	yes
USES=		gmake
USE_SDL=	sdl image ttf
CONFIGURE_ARGS=	--program-prefix=''

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	SDL_GFX SOUND DOCS
OPTIONS_DEFAULT=SDL_GFX SOUND
SDL_GFX_DESC=	Nicer graphics

SDL_GFX_USE=		SDL=gfx
SDL_GFX_CONFIGURE_ENABLE=sdl-gfx
SOUND_USE=		SDL=mixer
SOUND_CONFIGURE_ENABLE=	sound

post-patch:
	@${REINPLACE_CMD} -e '/LIBS=.*-lSDL_/ s|\(SDL_[a-z]*\)|\1 `sdl-config --libs`|' ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKDIR}/*.lev ${WRKDIR}/*.png ${STAGEDIR}${DATADIR}/levels/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/FAQ ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
