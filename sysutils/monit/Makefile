# Created by: Martin Pala <martinp@tildeslash.com>
# $FreeBSD$

PORTNAME=	monit
PORTVERSION=	5.8
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mmonit.com/monit/dist/

MAINTAINER=	martinp@tildeslash.com
COMMENT=	Unix system management and proactive monitoring

LICENSE=	AGPLv3

GNU_CONFIGURE=	yes
USES=		bison gmake
USE_RC_SUBR=	${PORTNAME}

CONFIGURE_ENV=	CONFIG_SHELL="${SH}" \
		LOCALBASE="${LOCALBASE}"

OPTIONS_DEFINE=	DOCS SSL
OPTIONS_DEFAULT=SSL

PLIST_FILES=	bin/monit \
		etc/monitrc.sample \
		man/man1/monit.1.gz

SUB_FILES=	pkg-message

PORTDOCS=	CHANGES COPYING README

SSL_CONFIGURE_OFF=	--without-ssl

post-install:
	${INSTALL} -m 600 ${WRKSRC}/monitrc ${STAGEDIR}${PREFIX}/etc/monitrc.sample
	${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL} -m 644 ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
