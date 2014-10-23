# $FreeBSD$

PORTNAME=	git-extras
PORTVERSION=	2.1.0
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	igor.ostapenko@gmail.com
COMMENT=	Sub-commands for repo summary, repl, changelog population, and more

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	tj
GH_TAGNAME=	v2.1.0
GH_COMMIT=	28f0ad8

NO_BUILD=	yes
USES+=		gmake

USES+=		shebangfix
SHEBANG_FILES=	bin/git-*

RUN_DEPENDS=	git:${PORTSDIR}/devel/git \
		bash:${PORTSDIR}/shells/bash

.include <bsd.port.mk>
