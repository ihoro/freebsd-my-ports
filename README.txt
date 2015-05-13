Just a few keywords to remind the things.

Development:
  uncomment DEVELOPER=yes in /etc/make.conf
  make makesum
  make makeplist
  make maintainer
  make makepatch

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

Checking/testing:
  portlint
  portlint -A
  make stage (implies stage-qa)
  make check-orphans
  make package
  make install
  make deinstall
  pkg add <package-name>
  make package (as user)

https://www.freebsd.org/doc/en_US.ISO8859-1/books/porters-handbook/index.html
https://www.freebsd.org/doc/en_US.ISO8859-1/books/porters-handbook/testing.html

