# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	soothsayer
PORTVERSION=	0.6.3
CATEGORIES=	textproc
MASTER_SITES=	SF/presage/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Intelligent predictive text entry platform

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	help2man:${PORTSDIR}/misc/help2man

USES=		pkgconfig
USE_SQLITE=	3
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	ac_cv_path_CPPUNIT_CONFIG=no \
		ac_cv_path_PYTHON=no \
		ac_cv_path_SWIG=no \
		ac_cv_prog_HAVE_DOT=no \
		ac_cv_prog_HAVE_DOXYGEN=no
CONFIGURE_ARGS=	--disable-python-binding
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|\$$\^|$${.ALLSRC}| ; \
		 s|lib/soothsayer|soothsayer|g' ${WRKSRC}/resources/Makefile.in
	@${REINPLACE_CMD} -e 's|lib/soothsayer|soothsayer|' \
		${WRKSRC}/resources/profiles/Makefile.in
	@${REINPLACE_CMD} -E -e "s|(LIBS=.*)-lsqlite3(.*)|\1\`pkg-config --static --libs sqlite3\`\2|" \
		-e "s|(.*SQLITE_LIBS=.*)-lsqlite3(.*)|\1\`pkg-config --static --libs sqlite3\`\2|" \
		${WRKSRC}/configure

.include <bsd.port.mk>
