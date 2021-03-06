# Created by: Dominic Marks <dominic.marks@btinternet.com>
# $FreeBSD$

PORTNAME=	dovecot
PORTVERSION=	1.2.17
CATEGORIES=	mail ipv6
MASTER_SITES=	http://www.dovecot.org/releases/${DOVECOTVERSION}/ \
		http://www.rename-it.nl/dovecot/${DOVECOTVERSION}/

MAINTAINER=	yds@CoolRat.org
COMMENT=	Secure and compact IMAP and POP3 servers

CONFLICTS=	dovecot2-*

DOVECOTVERSION=	1.2

######################################################################
# Anytime PORTVERSION changes please bump PORTREVISIONs of           #
# mail/dovecot-antispam, mail/dovecot-managesieve and                #
# mail/dovecot-sieve. Please see ports/135311 and ports/146029 for   #
# an explanation.                                                    #
#                                                                    #
# Please be careful when updating this port as changes to this port  #
# can break mail/dovecot-sieve and mail/dovecot-managesieve. In      #
# order to ensure the least amount of breakage possible please       #
# consult the maintainer of those ports before updating this one.    #
######################################################################

USES=		iconv
USE_RC_SUBR=	dovecot

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--localstatedir=/var \
			--with-statedir=/var/db/dovecot \
			--without-shadow
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	${PREFIX}/lib/dovecot \
		${PREFIX}/lib/dovecot/imap \
		${PREFIX}/lib/dovecot/pop3 \
		${PREFIX}/lib/dovecot/lda

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--without-docs
.else
DOCS=		AUTHORS COPYING COPYING.LGPL COPYING.MIT INSTALL NEWS TODO README
PORTDOCS=	*.txt wiki ${DOCS}
.endif

DOVECOT_UID?=	143
DOVECOT_GID?=	143

PROTOCOLS=	imap pop3

OPTIONS_DEFINE=	KQUEUE SSL MANAGESIEVE GSSAPI VPOPMAIL BDB LDAP PGSQL MYSQL SQLITE
OPTIONS_DEFAULT=	KQUEUE SSL MANAGESIEVE
KQUEUE_DESC=		kqueue(2) support
MANAGESIEVE_DESC=	ManageSieve support
VPOPMAIL_DESC=		VPopMail support

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "arm"
BROKEN=		Does not build on arm
.endif

# Default requirement for dovecot rc script
_REQUIRE=	LOGIN

# sed script for dovecot.conf
REINPLACE=	s!%%PROTOCOLS%%!${PROTOCOLS}!g;\
		s!/usr/!${PREFIX}/!g;\
		s!=/usr!=${PREFIX}!g;\
		s!=/etc !=${PREFIX}/etc !g;\
		s!/etc/dovecot!${PREFIX}&!g;\
		s![[:<:]]doc/(dovecot-[^-]+)-example.conf[[:>:]]!${EXAMPLESDIR}/\1.conf!g;\
		s!\#sendmail_path = /usr/.*!sendmail_path = /usr/sbin/sendmail!g;

## kqueue(2) support
#
.if ${PORT_OPTIONS:MKQUEUE}
CONFIGURE_ARGS+=	--with-ioloop=kqueue
.endif

## SSL support
#
.if ${PORT_OPTIONS:MSSL}
PROTOCOLS+=		imaps pop3s
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

## ManageSieve support
#
.if ${PORT_OPTIONS:MMANAGESIEVE}
MANAGESIEVEVERSION!=	${MAKE} -C ${.CURDIR}/../dovecot-managesieve -V PORTVERSION
PATCH_SITES!=		${MAKE} -C ${.CURDIR}/../dovecot-managesieve -V MASTER_SITES
PATCHFILES+=		dovecot-${PORTVERSION}-managesieve-${MANAGESIEVEVERSION}.diff.gz
PATCH_DIST_STRIP=	-p1
PROTOCOLS+=		managesieve
DOCS+=			README.managesieve
.endif

## GSSAPI support
#
.if ${PORT_OPTIONS:MGSSAPI}
CONFIGURE_ARGS+=	--with-gssapi
LDFLAGS+=		-lgssapi_krb5
.else
CONFIGURE_ARGS+=	--without-gssapi
.endif

## VPopMail Support
#
.if ${PORT_OPTIONS:MVPOPMAIL}
VPOPMAIL=		${LOCALBASE}/vpopmail/bin/vchkpw
BUILD_DEPENDS+=		${VPOPMAIL}:${PORTSDIR}/mail/vpopmail
CONFIGURE_ARGS+=	--with-vpopmail
.else
CONFIGURE_ARGS+=	--without-vpopmail
.endif

## BDB Support
#
.if ${PORT_OPTIONS:MBDB}
USE_BDB=		42+
CONFIGURE_ARGS+=	--with-db
CFLAGS+=		-I${BDB_INCLUDE_DIR} -L${BDB_LIB_DIR}
PLIST_SUB+=		BDB=""
REINPLACE+=		s!^\#(dict_db_config)!\1!;
.else
PLIST_SUB+=		BDB="@comment "
.endif

## OpenLDAP Support
#
.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap
PLIST_SUB+=		LDAP=""
_REQUIRE+=		slapd
.else
CONFIGURE_ARGS+=	--without-ldap
PLIST_SUB+=		LDAP="@comment "
.endif

## PostgreSQL Support
#
.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-pgsql
PLIST_SUB+=		SQL=""
_REQUIRE+=		postgresql
.else
CONFIGURE_ARGS+=	--without-pgsql
PLIST_SUB+=		SQL="@comment "
.endif

## MySQL Support
#
.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql
PLIST_SUB+=		SQL=""
_REQUIRE+=		mysql
.else
CONFIGURE_ARGS+=	--without-mysql
PLIST_SUB+=		SQL="@comment "
.endif

## SQLite Support
#
.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=		3
CONFIGURE_ARGS+=	--with-sqlite
PLIST_SUB+=		SQL=""
.else
CONFIGURE_ARGS+=	--without-sqlite
PLIST_SUB+=		SQL="@comment "
.endif

SUB_LIST+=		REQUIRE="${_REQUIRE}" DOVECOT_UID=${DOVECOT_UID} DOVECOT_GID=${DOVECOT_GID}
SUB_FILES+=		pkg-install pkg-deinstall pkg-message

post-patch:
	@${REINPLACE_CMD} -E -e '${REINPLACE}' \
		${WRKSRC}/dovecot-example.conf
	@${REINPLACE_CMD} -E -e'\
		s!-example\.conf[[:>:]]!.conf!g;\
		s!^(confdir[[:space:]]+=[[:space:]]+)\$$\(sysconfdir\)!\1${EXAMPLESDIR}!g;\
		' ${WRKSRC}/*/Makefile.in ${WRKSRC}/Makefile.in
	@${LN} -f ${WRKSRC}/dovecot-example.conf		${WRKSRC}/dovecot.conf
	@${LN} -f ${WRKSRC}/doc/dovecot-db-example.conf		${WRKSRC}/doc/dovecot-db.conf
	@${LN} -f ${WRKSRC}/doc/dovecot-dict-sql-example.conf	${WRKSRC}/doc/dovecot-dict-sql.conf
	@${LN} -f ${WRKSRC}/doc/dovecot-ldap-example.conf	${WRKSRC}/doc/dovecot-ldap.conf
	@${LN} -f ${WRKSRC}/doc/dovecot-sql-example.conf	${WRKSRC}/doc/dovecot-sql.conf

pre-su-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_DATA} ${WRKSRC}/dovecot.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-db.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-dict-sql.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-ldap.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-sql.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/dovecot-openssl.cnf ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/doc/mkcert.sh ${EXAMPLESDIR}
	@${GREP} '^@exec ' ${TMPPLIST} \
		| ${SED} -e 's:^@exec ::; s:%D:${PREFIX}:g;' \
		> ${WRKDIR}/.PLIST.exec \
		&& ${SH} ${WRKDIR}/.PLIST.exec
.if ${PORT_OPTIONS:MDOCS}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
