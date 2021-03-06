# Created by: roam@FreeBSD.org
# $FreeBSD$

PORTNAME=	gecode
PORTVERSION=	4.2.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.gecode.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic Constraint Development Environment

LICENSE=	MIT

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libmpfr.so:${PORTSDIR}/math/mpfr

USES=		bison gmake perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--enable-shared \
		--disable-doc-dot \
		--disable-doc-tagfile \
		--disable-doc-chm \
		--enable-driver \
		--enable-graph \
		--enable-flatzinc \
		--enable-sheduling \
		--disable-examples \
		--enable-minimodel \
		--enable-search \
		--with-gmp-include=${LOCALBASE}/include \
		--with-gmp-lib=${LOCALBASE}/lib \
		--with-mpfr-include=${LOCALBASE}/include \
		--with-mpfr-lib=${LOCALBASE}/lib
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

CFLAGS+=	-I${LOCALBASE}/include/boost

OPTIONS_DEFINE=		GIST
OPTIONS_SUB=		yes

GIST_DESC=		Interactive Search Tool (requires Qt)
GIST_USE=		QT4=corelib,gui,moc_build,qmake_build
GIST_CONFIGURE_ON=	--enable-gist --enable-qt
GIST_CONFIGURE_OFF=	--disable-gist --disable-qt

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-D__USE_ISOC99
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^ARR/s|^|#| ; \
		 /^PACKAGE_VERSION_NUMBER/s|^|#| ; \
		 /_vendor/s| == | = | ; \
		 /host_os/s| == | = | ; \
		 /gcc_optimize_flag/s|-O3|| ; \
		 /="-ggdb/s|^|#|' ${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fzn-gecode

.include <bsd.port.mk>
