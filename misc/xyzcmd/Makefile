# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xyzcmd
PORTVERSION=	0.0.4
CATEGORIES=	misc python
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Pure console visual file manager

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/urwid/raw_display.py:${PORTSDIR}/devel/py-urwid
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/urwid/raw_display.py:${PORTSDIR}/devel/py-urwid

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
INSTALLS_EGGINFO=yes

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} api ${DOCSDIR} && \
		${COPYTREE_SHARE} user-manual ${DOCSDIR} && \
		${INSTALL_DATA} ../ChangeLog overview.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
