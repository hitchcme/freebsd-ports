# Created by: Oleg Alexeenkov <proler@gmail.com>
# $FreeBSD$

PORTNAME=	Net-DirectConnect
PORTVERSION=	0.13
CATEGORIES=	net-p2p net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	proler@gmail.com
COMMENT=	Perl Direct Connect lib and client

BROKEN=		not staged
LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-IO-Socket-INET6>=0:${PORTSDIR}/net/p5-IO-Socket-INET6 \
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-Net-DirectConnect-TigerHash>=0:${PORTSDIR}/net-p2p/p5-Net-DirectConnect-TigerHash \
		p5-Socket6>=0:${PORTSDIR}/net/p5-Socket6 \
		p5-lib-abs>=0:${PORTSDIR}/devel/p5-lib-abs \
		p5-MIME-Base32>=0:${PORTSDIR}/converters/p5-MIME-Base32 \
		p5-Sys-Sendfile-FreeBSD>=0:${PORTSDIR}/devel/p5-Sys-Sendfile-FreeBSD
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
