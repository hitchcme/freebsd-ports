# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hikidoc
PORTVERSION=	0.0.6
CATEGORIES=	textproc ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${RUBY_PKGNAMEPREFIX:S|${RUBY_SUFFIX}-||}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A text-to-HTML conversion tool for web writers

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SHEBANG_FILES=	bin/hikidoc

PORTDOCS=	NEWS NEWS.ja README README.ja \
		TextFormattingRules TextFormattingRules.ja

PLIST_FILES=	bin/hikidoc \
		%%RUBY_SITELIBDIR%%/hikidoc.rb

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
