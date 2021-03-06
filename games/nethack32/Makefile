# Created by: asami
# $FreeBSD$

PORTNAME=	nethack32
PORTVERSION=	3.2.3
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/${TRUEPORTNAME}/${TRUEPORTNAME}/3.2.2
DISTNAME=	nethack-322
EXTRACT_SUFX=	.tgz

PATCH_SITES=	${MASTER_SITE_SOURCEFORGE:C/%SUBDIR%/${TRUEPORTNAME}\/${TRUEPORTNAME}\/${PORTVERSION}/}
PATCHFILES=	nh-3.2.2-3.2.3.diff

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	A dungeon explorin', slashin', hackin' game

WRKSRC=		${WRKDIR}/${TRUEPORTNAME}-3.2.2

USE_GMAKE=	yes
USE_XORG=	xaw xpm
PLIST_SUB=	HACKNAME="${HACKNAME}" \
		HACKEXT="${HACKEXT}"
MAKE_JOBS_UNSAFE=	yes
TRUEPORTNAME=	nethack

MAN6=		dgn_comp${HACKEXT}.6 dlb${HACKEXT}.6 lev_comp${HACKEXT}.6 \
		${HACKNAME}.6 recover${HACKEXT}.6

HACKEXT?=	32
HACKNAME?=	${TRUEPORTNAME}${HACKEXT}
HACKDIR?=	share/${HACKNAME}
HACKLINK=	${TRUEPORTNAME}

DATADIR=	${PREFIX}/${HACKDIR}
DOCSDIR=	${PREFIX}/share/doc/${HACKNAME}
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !exists(${PREFIX}/bin/${HACKLINK}) && ${HACKNAME} != ${HACKLINK}
PLIST_SUB+=	HACKLINK=""
.else
PLIST_SUB+=	HACKLINK="@comment "
.endif

pre-configure:
.for f in include/config.h sys/unix/Makefile.top sys/unix/Makefile.doc
	@${REINPLACE_CMD} -e 's|%%HACKNAME%%|${HACKNAME}|g' \
		-e 's|%%HACKDIR%%|${PREFIX}/${HACKDIR}|g' \
		-e 's|%%HACKEXT%%|${HACKEXT}|g' \
		${WRKSRC}/${f}
.endfor
.for f in dgn_comp.6 dlb.6 lev_comp.6 nethack.6 recover.6
	@${REINPLACE_CMD} -e 's|%%HACKNAME%%|${HACKNAME}|g' \
		-e 's|%%HACKDIR%%|${PREFIX}/${HACKDIR}|g' \
		-e 's|%%HACKEXT%%|${HACKEXT}|g' \
		${WRKSRC}/doc/${f}
.endfor
	@cd ${WRKSRC}/sys/unix && ${SH} setup.sh

pre-install:
	@${CAT} ${FILESDIR}/pkg-deinstall.in | ${SED} \
		-e 's|%%HACKDIR%%|${HACKDIR}|g' > ${PKGDEINSTALL}

post-install:
.if !exists(${PREFIX}/bin/${HACKLINK}) && ${HACKNAME} != ${HACKLINK}
	@${LN} -s -f ${PREFIX}/bin/${HACKNAME} ${PREFIX}/bin/${HACKLINK}
.endif
	@cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE} manpages
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/Guidebook.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
