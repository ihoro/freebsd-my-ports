Just a few keywords to remind the things.

Development:
  uncomment DEVELOPER=yes in /etc/make.conf
  make makesum (after make fetch)
  make makeplist
  make maintainer
  make makepatch

Checking/testing:
  portlint
  portlint -A
  make stage (implies stage-qa)
  make check-plist
  make check-orphans
  make package
  make install
  make deinstall
  pkg add <package-name>
  make package (as user)

Preparing patch:
  cd git-extras
  git diff --staged > ../a.diff 
  cd ..
  svn co svn://svn.freebsd.org/ports/head/devel/git-extras git-extras.orig
  cd git-extras.orig
  svn st
  patch -p3 -i ../a.diff
  svn st
  svn diff | less
  svn diff > ../`make -VPKGNAME`.diff

https://www.freebsd.org/doc/en_US.ISO8859-1/books/porters-handbook/index.html
https://www.freebsd.org/doc/en_US.ISO8859-1/books/porters-handbook/testing.html

