# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	memcached
PORTVERSION=	1.53
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://ftp.tummy.com/pub/python-memcached/ \
		http://ftp.tummy.com/pub/python-memcached/old-releases/ \
		ftp://ftp.tummy.com/pub/python-memcached/ \
		ftp://ftp.tummy.com/pub/python-memcached/old-releases/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python API for memcached, a distributed memory cache daemon

PYDISTUTILS_AUTOPLIST=	yes
USE_PYDISTUTILS=yes
USE_PYTHON=	yes

.include <bsd.port.mk>
