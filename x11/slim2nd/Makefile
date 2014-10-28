# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD: x11/slim2nd/Makefile 319055 2013-05-25 14:37:02Z zeising $

PORTNAME=	slim2nd
PORTVERSION=	1.3.5
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.berlios.de/pub/slim2nd/ \
		SF/slim2nd.berlios

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Graphical login manager for X11, derived from Login.app

LICENSE=	GPLv2

LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		ck-connector:${PORTSDIR}/sysutils/consolekit \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig

USES=		cmake pkgconfig
USE_XORG=	ice sm x11 xau xcb xdmcp xext xft xmu xorg-server xrender xt
USE_RC_SUBR=	slim2nd
SUB_FILES=	pkg-message

CMAKE_ARGS=	-DUSE_CONSOLEKIT=yes -DXNEST_DEBUG=yes

MAN1=		slim2nd.1

OPTIONS_DEFINE=	PAM

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPAM}
CMAKE_ARGS+=	-DUSE_PAM=yes
PLIST_SUB+=	PAM=""
.else
CMAKE_ARGS+=	-DUSE_PAM=no
PLIST_SUB+=	PAM="@comment "
.endif

post-extract:
	${FIND} ${WRKSRC} -type f | xargs ${SED} -i '' 's/slim/slim2nd/g'
	${MV} ${WRKSRC}/slim.1 ${WRKSRC}/slim2nd.1
	${MV} ${WRKSRC}/slim.conf ${WRKSRC}/slim2nd.conf
	${MV} ${WRKSRC}/slim.service ${WRKSRC}/slim2nd.service
	${MV} ${WRKSRC}/themes/default/slim.theme ${WRKSRC}/themes/default/slim2nd.theme

post-patch:
	@${CP} ${WRKSRC}/slim2nd.conf ${WRKSRC}/slim2nd.conf.sample
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/slim2nd.conf.sample
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
		-e 's|/etc|${PREFIX}/etc|' \
		-e 's|share/man|man|' \
		-e 's|slim2nd.conf|slim2nd.conf.sample|' \
		-e '/systemd/d' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@if [ ! -f ${PREFIX}/etc/slim2nd.conf ]; then \
		${CP} ${PREFIX}/etc/slim2nd.conf.sample ${PREFIX}/etc/slim2nd.conf ; \
	fi
.	if ${PORT_OPTIONS:MPAM}
	@${INSTALL_DATA} ${FILESDIR}/pam.conf ${PREFIX}/etc/pam.d/slim2nd.default
	@if [ ! -f ${PREFIX}/etc/pam.d/slim2nd ]; then \
		${CP} ${PREFIX}/etc/pam.d/slim2nd.default ${PREFIX}/etc/pam.d/slim2nd ; \
	fi
.	endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
