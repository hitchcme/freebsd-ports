# Created by: Manuel Kreutz <mk@nomtec.net>
# $FreeBSD$

PORTNAME=	sysmon
PORTVERSION=	0.92.2
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://puck.nether.net/pub/jared/ \
		http://titan.oxeo.com/mirror/sysmon.org/

MAINTAINER=	mk@oxeo.com
COMMENT=	A network tool designed for high performance and accurate monitoring

DOCS=		Changes.html binaries.html config.html docs.html index.html \
		jclient.jpg net-example.png sysmon.conf.man.html sysmon.jpg \
		sysmon.man.html reporting.xml-spec.txt
MANPAGE=	sysmon.man.8 sysmon.conf.man.8

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sysmon ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/sysmond ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} \
		${WRKSRC}/examples/sysmon.conf.dist \
			${STAGEDIR}${PREFIX}/etc/sysmon.conf.sample
.for man in ${MANPAGE}
	${INSTALL_MAN} ${WRKSRC}/docs/${man:S/.8//} ${STAGEDIR}${MANPREFIX}/man/man8/${man}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
