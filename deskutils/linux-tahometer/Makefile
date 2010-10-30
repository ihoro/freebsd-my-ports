# New ports collection makefile for:	linux-tahometer
# Date created:		30 October 2010
# Whom:			Igor Ostapenko <igor.ostapenko@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tahometer
PORTVERSION=	1.0.8.2
CATEGORIES=	deskutils linux
MASTER_SITES=	http://tahometer.com/agent/
PKGNAMEPREFIX=	linux-
DISTNAME=	tahometer-linux-x86-${DISTVERSION}

MAINTAINER=	igor.ostapenko@gmail.com
COMMENT=	A worktime tracking and reporting tool

USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
NO_BUILD=	yes

TAHOMETER_DIR=	lib/${PKGNAMEPREFIX}${PORTNAME}
PLIST_SUB+=	TAHOMETER_DIR="${TAHOMETER_DIR}"

post-patch:
	bspatch ${WRKSRC}/tahometer-bin ${WRKSRC}/tahometer-bin ${PATCHDIR}/tahometer-bin.bsdiff

do-install:
	${MKDIR} ${PREFIX}/${TAHOMETER_DIR}
	${INSTALL_SCRIPT} ${FILESDIR}/linux-tahometer ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tahometer ${PREFIX}/${TAHOMETER_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/tahometer-bin ${PREFIX}/${TAHOMETER_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/*.so.* ${PREFIX}/${TAHOMETER_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.qm ${PREFIX}/${TAHOMETER_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.svg ${PREFIX}/${TAHOMETER_DIR}

.include <bsd.port.mk>
