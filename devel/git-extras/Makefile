PORTNAME=	git-extras
DISTVERSION=	7.2.0
CATEGORIES=	devel

MAINTAINER=	igor.ostapenko@pm.me
COMMENT=	Sub-commands for repo summary, repl, changelog population, and more
WWW=		https://github.com/tj/git-extras/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		git:devel/git

USES=		gmake

MAKE_ARGS=	MANPREFIX=${PREFIX}/share/man/man1

USE_GITHUB=	yes
GH_ACCOUNT=	tj

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
