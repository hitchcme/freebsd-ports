# $FreeBSD$

PORTNAME=	jabber
PORTVERSION=	1.8.0
PORTREVISION=	2
CATEGORIES=	net-im

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Jabber (XMPP) plugin for Licq

LICENSE=	GPLv2

LIB_DEPENDS=	libgloox.so:${PORTSDIR}/net-im/gloox \
		libboost_regex.so:${PORTSDIR}/devel/boost-libs

USES=		cmake pkgconfig
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

DOCFILES=	README
PLIST_FILES=	lib/licq/protocol_jabber.so \
		%%PORTDOCS%%%%DOCSDIR%%/README
PLIST_DIRS=	%%PORTDOCS%%%%DOCSDIR%%

LICQ_PORT?=	net-im/licq

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.include "${PORTSDIR}/${LICQ_PORT}/Makefile.inc"

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
