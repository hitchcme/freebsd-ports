# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=	memtest86+
PORTVERSION=	4.20
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.memtest.org/download/${PORTVERSION}/

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Stand-alone memory test for x86 architecture computers

ONLY_FOR_ARCHS=	i386 amd64

USES=	gmake dos2unix
ALL_TARGET=	all
PORTDOCS=	*

USE_GCC=	yes

# Please provide absolute path below (cannot be root)
BOOT_DIR?=	/boot/opt

OPTIONS_DEFINE=	SERIAL HISPEED DOCS
OPTIONS_DEFAULT=	BOOT
OPTIONS_MULTI=	BOOT_TYPE
OPTIONS_MULTI_BOOT_TYPE=	ISO BOOT
ISO_DESC=	Build bootable ISO image
BOOT_DESC=	Build ELF image loadable by boot2 and loader
SERIAL_DESC=	Enable serial console at COM1/9600
HISPEED_DESC=	Set COM1 serial console speed to 115200

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBOOT}
SUB_FILES=	pkg-message
SUB_LIST+=	BOOT_DIR=${BOOT_DIR}
.endif

.if ${PORT_OPTIONS:MISO}
BUILD_DEPENDS+=	mkisofs:${PORTSDIR}/sysutils/cdrtools
ALL_TARGET+=	iso
.endif

.if ${PORT_OPTIONS:MSERIAL}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-config.h

.if ${PORT_OPTIONS:MHISPEED}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-config.h-115200
.endif
.endif	# WITH_SERIAL

pre-fetch:
.if !defined(PACKAGE_BUILDING)
	@${ECHO} "If you only need bootable ISO image of memtest86+, you can"
	@${ECHO} "simply download it from http://www.memtest.org/.  Use this"
	@${ECHO} "port if you need ELF image of memtest86+ that can be loaded"
	@${ECHO} "by boot2 or loader(8), or if you want to use this port to"
	@${ECHO} "build ISO image with custom tweaks in memtest86+ code."
.endif

post-patch:
	${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/Makefile

PLIST=		${WRKDIR}/pkg-plist

pre-install:
# Generate PLIST dynamically because install things outside normal ${PREFIX}
	@${TEST} -f ${PLIST} && ${RM} ${PLIST} || ${TRUE}
.if ${PORT_OPTIONS:MISO}
	@${ECHO} "%%DATADIR%%/mt${PORTVERSION:C/\.//}.iso" >> ${PLIST}
	@${ECHO} "@dirrm %%DATADIR%%" >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MBOOT}
	@${ECHO} "@cwd ${BOOT_DIR:H}" >> ${PLIST}
	@${ECHO} "${BOOT_DIR:T}/memtest86+" >> ${PLIST}
	@${ECHO} "@dirrm ${BOOT_DIR:T}" >> ${PLIST}
.endif

do-install:
.if ${PORT_OPTIONS:MISO}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mt${PORTVERSION:C/\.//}.iso ${STAGEDIR}${DATADIR}
.endif
.if ${PORT_OPTIONS:MBOOT}
	@${MKDIR} ${STAGEDIR}${BOOT_DIR}
# XXX is INSTALL_KLD really appropriate here? XXX
	${INSTALL_KLD} ${WRKSRC}/memtest ${STAGEDIR}${BOOT_DIR}/memtest86+
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

post-install:
.if ${PORT_OPTIONS:MBOOT}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
