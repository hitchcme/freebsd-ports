# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-themes/gtk-milk-theme/Makefile,v 1.4 2007/08/07 04:37:40 mezz Exp $

PORTNAME=	milk
PORTVERSION=	2.1
PORTREVISION=	7
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://www.users.monornet.hu/linux/gtk2/oldies/
PKGNAMEPREFIX?=	${TYPE}-
PKGNAMESUFFIX=	-theme
DISTNAME=	Milk-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A port of Milk, Mac OS X theme

TYPE?=		gtk

THEME_NAME=	Milk

USES=		tar:bzip2
NO_BUILD=	yes

.if ${TYPE} == "gtk"
THEME_DIR=	${PREFIX}/share/themes/${THEME_NAME}
PLIST_SUB+=	GTK20="" METACITY="@comment "
USE_GNOME=	gtk20
.else	# metacity
THEME_DIR=	${PREFIX}/share/themes/${THEME_NAME}
PLIST_SUB+=	GTK20="@comment " METACITY=""
USE_GNOME=	gnomehier
.endif

post-extract:
	@${FIND} ${WRKSRC} -type f -print0 | ${XARGS} -0 ${CHMOD} 644

do-install:
	@${MKDIR} ${STAGEDIR}${THEME_DIR}
	${INSTALL_DATA} ${WRKSRC}/index.theme ${STAGEDIR}${THEME_DIR}
.if ${TYPE} == "gtk"
	cd ${WRKSRC} && ${COPYTREE_SHARE} gtk-2.0 ${STAGEDIR}${THEME_DIR}
.else
	cd ${WRKSRC} && ${COPYTREE_SHARE} metacity-1 ${STAGEDIR}${THEME_DIR}
.endif

.include <bsd.port.mk>
