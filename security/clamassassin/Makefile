# Created by: Matt <matt@xtaz.net>
# $FreeBSD$

PORTNAME=	clamassassin
PORTVERSION=	1.2.4
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	http://jameslick.com/clamassassin/

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Simple virus filter wrapper for ClamAV

BUILD_DEPENDS=	sigtool:${PORTSDIR}/security/clamav \
		formail:${PORTSDIR}/mail/procmail
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_FILES=	bin/clamassassin

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	CLAMDSCAN SUBREWRITE
OPTIONS_DEFAULT=	CLAMDSCAN
CLAMDSCAN_DESC=		Scanning using clamd
SUBREWRITE_DESC=	Mail subject rewriting

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLAMDSCAN}
CONFIGURE_ARGS+=	--enable-clamdscan
.endif

.if ${PORT_OPTIONS:MSUBREWRITE}
CONFIGURE_ARGS+=	--enable-subject-rewrite
.endif

.include <bsd.port.mk>
