# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Plack-Middleware-FixMissingBodyInRedirect
PORTVERSION=	0.10
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sets body for redirect response, if it is not already set

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Plack>=0:${PORTSDIR}/www/p5-Plack
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Carp-Always>=0:${PORTSDIR}/devel/p5-Carp-Always \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
