# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	javatar
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	archivers java
MASTER_SITES=	http://www.gjt.org/download/time/java/tar/ \
		ftp://ftp.gjt.org/pub/time/java/tar/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Java tar archive I/O package

RUN_DEPENDS=	${JAVALIBDIR}/activation.jar:${PORTSDIR}/java/jaf

USE_JAVA=	yes
JAVA_VERSION=	1.6+

NO_BUILD=	yes

PORTDOCS=	api LICENSE License.html readme.html tarman.html

JARFILES=	tar.jar
PLIST_FILES=	${JARFILES:S,^,%%JAVAJARDIR%%/,}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	@${ECHO_MSG} -n ">> Install JAR file in ${STAGEDIR}${JAVAJARDIR}..."
	@${INSTALL_DATA} ${WRKSRC}/jars/tar.jar ${STAGEDIR}${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing documentation in ${STAGEDIR}${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && ${FIND} ${PORTDOCS} \
	  | ${CPIO} -pdmu ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
