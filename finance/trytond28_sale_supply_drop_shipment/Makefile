# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	trytond28_sale_supply_drop_shipment
PORTVERSION=	2.8.1
PORTREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	https://pypi.python.org/packages/source/t/trytond_sale_supply_drop_shipment/ \
		http://downloads.tryton.org/${PORTVERSION:R}/
DISTNAME=	trytond_sale_supply_drop_shipment-${PORTVERSION}

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Tryton Application Platform (Sale Supply Drop Shipment Module)

LICENSE=	GPLv3

RUN_DEPENDS=	trytond28_sale_supply>=2.8.1:${PORTSDIR}/finance/trytond28_sale_supply

CONFLICTS=	trytond_sale_supply_drop_shipment-2.[46].*

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
PYEASYINSTALL_EGG=${DISTNAME}-py${PYTHON_VER}${PYEASYINSTALL_OSARCH}.egg

.include <bsd.port.mk>
