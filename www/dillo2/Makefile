# Created by: bf <bf2006a@yahoo.com>
# $FreeBSD$

PORTNAME=	dillo
DISTVERSION=	3.0.3
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.dillo.org/download/ LOCAL/bf/dillo/ \
		TEX_CTAN:hyphen
MASTER_SITE_SUBDIR=	\
	language/hyph-utf8/tex/generic/hyph-utf8/patterns/txt/:hyphen
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A fast, small graphical Web browser built upon fltk

LICENSE=	GPLv3

LIB_DEPENDS=	fltk:${PORTSDIR}/x11-toolkits/fltk
RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

USES=		gmake pkgconfig
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
MAN1=		dillo.1
CONFIGURE_ARGS=	--libdir=${PREFIX}/libexec
CONFLICTS=	dillo-i18n-[0-9]* \
		dillo-0*
LATEST_LINK=	dillo2

OPTIONS_DEFINE=		COOKIES HYPHENATION IPV6 SSL THREADS
OPTIONS_DEFAULT=	COOKIES HYPHENATION IPV6 SSL THREADS

COOKIES_DESC=		Cookie support
HYPHENATION_DESC=	Hyphenation file(s) for HYPHENATION_LANGS
SSL_DESC=		Experimental HTTPS support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOOKIES}
CONFIGURE_ARGS+=	--enable-cookies
.else
CONFIGURE_ARGS+=	--disable-cookies
.endif

.ifdef(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-gprof --enable-rtfl
.else
CONFIGURE_ARGS+=	--disable-gprof --disable-rtfl
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

.if ${PORT_OPTIONS:MHYPHENATION}
ALL_HYPHENATION_LANGS=	af as bg bn ca cop cs cy da de-1901 de-1996 \
de-ch-1901 el-monoton el-polyton en-gb en-us eo es et eu fi fr fur ga \
gl grc gu hi hr hsb hu hy ia id is it kmr kn la lt lv ml mn-cyrl mr \
mul-ethi nb nl nn or pa pl pms pt rm ro ru sa sh-cyrl sh-latn sk sl \
sr-cyrl sv ta te tk tr uk zh-latn-pinyin
.if defined(MAINTAINER_MODE) || make(makesum)
HYPHENATION_LANGS?=	${ALL_HYPHENATION_LANGS}
.else
HYPHENATION_LANGS?=	\
	${ALL_HYPHENATION_LANGS:N*-1901:N*-latn:N*-gb:N*-monoton}
.endif
.for _l in ${HYPHENATION_LANGS}
.if !${ALL_HYPHENATION_LANGS:M${_l}}
IGNORE=	remove the invalid hyphenation language "${_l}" from HYPHENATION_LANGS
.else
DISTFILES+=	hyph-${_l}.pat.txt:hyphen
IGNOREFILES+=	hyph-${_l}.pat.txt
PLIST_FILES+=	libexec/dillo/hyphenation/${_l:C/-.*\$//}.pat
.endif
.endfor
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--enable-ssl
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--enable-threaded-dns
.else
CONFIGURE_ARGS+=	--disable-threaded-dns
.endif

post-patch:
	@${MV} ${WRKSRC}/dillorc ${WRKSRC}/dillorc.dist
	@${MV} ${WRKSRC}/dpid/dpidrc.in ${WRKSRC}/dpid/dpidrc.dist.in
	@${MV} ${WRKSRC}/src/domainrc ${WRKSRC}/src/domainrc.dist
	@${MV} ${WRKSRC}/src/keysrc ${WRKSRC}/src/keysrc.dist
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|dillorc|dillorc.dist|g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|dpidrc|dpidrc.dist|g" ${WRKSRC}/dpid/Makefile.in
	@${REINPLACE_CMD} -E "s/(domain|keys)rc/&.dist/g" ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e "s|/lib/dillo|/libexec/dillo|" \
		${WRKSRC}/dillo-install-hyphenation \
		${WRKSRC}/doc/dillo.1.in \
		${WRKSRC}/dpid/dpid.c
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e "\|install-data-am:|s|install-dist_docDATA||" \
		${WRKSRC}/doc/Makefile.in
.endif

post-install:
.for f in dillorc domainrc dpidrc keysrc
. if !exists(${PREFIX}/etc/dillo/${f})
	${INSTALL_DATA} ${PREFIX}/etc/dillo/${f}.dist ${PREFIX}/etc/dillo/${f}
. endif
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/* ${DOCSDIR}
.endif
	@${MKDIR} ${PREFIX}/libexec/dillo/hyphenation
	@${TOUCH} ${PREFIX}/libexec/dillo/hyphenation/.keep_me
.if ${PORT_OPTIONS:MHYPHENATION}
.for _l in ${HYPHENATION_LANGS}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/hyph-${_l}.pat.txt \
	${PREFIX}/libexec/dillo/hyphenation/${_l:C/-.*\$//}.pat
.endfor
.endif

.include <bsd.port.mk>
