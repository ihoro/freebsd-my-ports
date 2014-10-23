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

# TODO: git-squash needs bash, let's add bash dep? or it may work with /bin/sh?

.include <bsd.port.mk>
