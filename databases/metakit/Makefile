# Created by: Russell L. Carter <rcarter@pinyon.org>
# $FreeBSD$

PORTNAME=	metakit
PORTVERSION=	2.4.9.7
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.equi4.com/pub/mk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ embedded database engine with Python and Tcl support

LICENSE=	MIT

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../unix/configure
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/builds

OPTIONS_DEFINE=	PYTHON TCL DOCS
OPTIONS_DEFAULT=	PYTHON

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
CONFIGURE_ARGS+=	--with-python=${LOCALBASE}
CATEGORIES+=	python
PLIST_SUB+=	WITH_PYTHON=""
.else
PLIST_SUB+=	WITH_PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MTCL}
USES+=		tcl:84
CATEGORIES+=	tcl
CONFIGURE_ARGS+=--with-tcl=${TCL_INCLUDEDIR}
CONFIGURE_ENV+=	TCL_LIBDIR=${TCL_LIBDIR}
PLIST_SUB+=	TCL_V="${TCL_VER}"
PLIST_SUB+=	WITH_TCL=""
.else
PLIST_SUB+=	WITH_TCL="@comment "
.endif

pre-patch:
	${REINPLACE_CMD} -e "s=doc/==" ${WRKSRC}/../Metakit.html
	${REINPLACE_CMD} -e "s|= tclsh|=${TCLSH}|" \
		${WRKSRC}/../unix/Makefile.in
	${REINPLACE_CMD} -e "s=python2.[0-9]=${PYTHON_VERSION}=" \
		${WRKSRC}/../unix/Makefile.in ${WRKSRC}/../unix/configure

post-build:
.if ${PORT_OPTIONS:MPYTHON}
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${WRKSRC}/../python
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		${WRKSRC}/../python
.endif

pre-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libmk4.so \
		${STAGEDIR}${PREFIX}/lib/libmk4.so.0
	${LN} -sf libmk4.so.0 ${STAGEDIR}${PREFIX}/lib/libmk4.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${TAR} -C ${WRKSRC}/../doc --exclude "*CVS" -cf - . | \
		${TAR} -C ${STAGEDIR}${DOCSDIR} --unlink -xf -
	${INSTALL_DATA} ${WRKSRC}/../Metakit.html ${WRKSRC}/../CHANGES \
		${WRKSRC}/../README ${STAGEDIR}${DOCSDIR}

test:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)
.if ${PORT_OPTIONS:MTCL}
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test-tcl)
.endif

.include <bsd.port.mk>
