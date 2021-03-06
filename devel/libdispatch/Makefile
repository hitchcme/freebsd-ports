# Created by: stas
# $FreeBSD$

PORTNAME=	libdispatch
PORTVERSION=	210
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Grand Central Dispatch API support library

USE_AUTOTOOLS=	aclocal autoconf
ACLOCAL_ARGS=	-Im4
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
# This is needed because PIC support check in autoconf could fail for clang otherwise.
CONFIGURE_ENV=	lt_cv_prog_compiler_pic_works=yes

OPTIONS_DEFINE=	CLANG
OPTIONS_DEFAULT=	CLANG
CLANG_DESC=	Build with LLVM/Clang (required for blocks support)

_MAN3=	dispatch.3 \
	dispatch_after.3 \
	dispatch_after_f.3 \
	dispatch_api.3 \
	dispatch_apply.3 \
	dispatch_apply_f.3 \
	dispatch_async.3 \
	dispatch_async_f.3 \
	dispatch_benchmark.3 \
	dispatch_benchmark_f.3 \
	dispatch_get_context.3 \
	dispatch_get_current_queue.3 \
	dispatch_get_global_queue.3 \
	dispatch_get_main_queue.3 \
	dispatch_group_async.3 \
	dispatch_group_async_f.3 \
	dispatch_group_create.3 \
	dispatch_group_enter.3 \
	dispatch_group_leave.3 \
	dispatch_group_notify.3 \
	dispatch_group_notify_f.3 \
	dispatch_group_wait.3 \
	dispatch_main.3 \
	dispatch_object.3 \
	dispatch_once.3 \
	dispatch_once_f.3 \
	dispatch_queue_create.3 \
	dispatch_queue_get_label.3 \
	dispatch_release.3 \
	dispatch_resume.3 \
	dispatch_retain.3 \
	dispatch_semaphore_create.3 \
	dispatch_semaphore_signal.3 \
	dispatch_semaphore_wait.3 \
	dispatch_set_context.3 \
	dispatch_set_finalizer_f.3 \
	dispatch_set_target_queue.3 \
	dispatch_source_cancel.3 \
	dispatch_source_create.3 \
	dispatch_source_get_data.3 \
	dispatch_source_get_handle.3 \
	dispatch_source_get_mask.3 \
	dispatch_source_merge_data.3 \
	dispatch_source_set_cancel_handler.3 \
	dispatch_source_set_cancel_handler_f.3 \
	dispatch_source_set_event_handler.3 \
	dispatch_source_set_event_handler_f.3 \
	dispatch_source_set_timer.3 \
	dispatch_source_testcancel.3 \
	dispatch_suspend.3 \
	dispatch_sync.3 \
	dispatch_sync_f.3 \
	dispatch_time.3 \
	dispatch_walltime.3
PLIST_FILES+=	${_MAN3:S|^|man/man3/|:S|$|.gz|}

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 800107 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900002)
IGNORE=	is not supported on this OS version
.endif

.if ${OSVERSION} > 900000
.if ${ARCH} == "powerpc
BROKEN=		Does not configure on powerpc-9
.elif ${ARCH} == "sparc64
BROKEN=		Does not link on sparc64-9
.endif
.endif

.if ${PORT_OPTIONS:MCLANG}
. if ${OSVERSION} < 900024
BUILD_DEPENDS+=	clang33:${PORTSDIR}/lang/clang33 \
		${LOCALBASE}/lib/libBlocksRuntime.so:${PORTSDIR}/devel/compiler-rt
RUN_DEPENDS+=	clang33:${PORTSDIR}/lang/clang33 \
		${LOCALBASE}/lib/libBlocksRuntime.so:${PORTSDIR}/devel/compiler-rt
CONFIGURE_ARGS+=	--with-blocks-runtime=${LOCALBASE}/lib
CONFIGURE_ENV+=	CC="${LOCALBASE}/bin/clang33" CPPFLAGS="-I${LOCALBASE}/include"
. else
CONFIGURE_ARGS+=	--with-blocks-runtime=/usr/lib
CONFIGURE_ENV+=	CC="/usr/bin/clang"
. endif
.endif

#
# Get rid of .la and static library files
#
post-configure:
	@${REINPLACE_CMD} -E -e \
	'/Install the pseudo-library/,/staticlibs=/s,^,#,' ${WRKSRC}/libtool


.include <bsd.port.post.mk>
