# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		${MASTER_SITE_LOCAL:S/$/:skkdic/}
MASTER_SITE_SUBDIR=	nobutaka/:skkdic
PKGNAMESUFFIX=	-dict
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${SKKDIC_FILE}:skkdic
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Dictionary for C/Migemo Japanese incremental search tool

LICENSE=	GPLv2

MASTERDIR=	${.CURDIR}/../../japanese/cmigemo
PKGDIR=		${.CURDIR}

USES=		perl5
USE_PERL5=	patch build run

ALL_TARGET=	gcc-dict
INSTALL_TARGET=	gcc-install-dict

SKKDIC_FILE=	SKK-JISYO.L-20110813.bz2
LICENSE_DISTFILES=	${SKKDIC_FILE}

NO_STAGE=	yes
post-extract:
	${BZCAT} ${DISTDIR}/${DIST_SUBDIR}/${SKKDIC_FILE} > ${WRKSRC}/dict/SKK-JISYO.L
	${CHMOD} a+x ${WRKSRC}/configure

.include "${MASTERDIR}/Makefile"
