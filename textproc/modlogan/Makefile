# Created by: Alexander@Leidinger.net
# $FreeBSD$

PORTNAME=	modlogan
PORTVERSION=	0.8.13
PORTREVISION=	14
CATEGORIES=	textproc www
MASTER_SITES=	http://www.mirrorservice.org/sites/www.ibiblio.org/gentoo/distfiles/

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	A modular log file analysis program

LIB_DEPENDS=	adns:${PORTSDIR}/dns/adns \
		gd:${PORTSDIR}/graphics/gd \
		pcre:${PORTSDIR}/devel/pcre \
		expat:${PORTSDIR}/textproc/expat2

USE_AUTOTOOLS=	libtool
USES=		gettext

# Please don't remove the comments, as soon as autoconf/libtool get's
# updated in the ports collection the comments may be removed.
# They serve as a reminder.
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-ltdl-install=no --with-gd=${LOCALBASE}/include \
		--program-transform-name=\'\'
.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=--with-mysql
.endif
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		modlogan.1
DOC1=		faq.txt glosar manual.txt translations.txt \
		using-plugins.txt writing-plugins.txt

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's:\@config_path\@:${PREFIX}/etc/modlogan:g' ${WRKSRC}/doc/modlogan.conf-dist.in

#post-configure:
#	${TOUCH} ${WRKSRC}/libltdl/config.status

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/modlogan
.for i in ${DOC1}
	@${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/modlogan/${i}
.endfor
.endif
	${MKDIR} ${PREFIX}/share/examples/modlogan
.for i in footer.ihtml header.ihtml output.tmpl convert_history_to_07x.pl convert_to_055.pl convert_to_060.pl
	@${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/examples/modlogan/${i}
.endfor
.for i in css conf def.conf
	[ -f ${PREFIX}/etc/modlogan/modlogan.${i} ] || ${INSTALL_DATA} ${PREFIX}/etc/modlogan/modlogan.${i}-dist ${PREFIX}/etc/modlogan/modlogan.${i}
.endfor

.include <bsd.port.mk>
