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

References:
  - https://www.freebsd.org/doc/en_US.ISO8859-1/books/porters-handbook/index.html
  - https://www.freebsd.org/doc/en_US.ISO8859-1/books/porters-handbook/testing.html
  - "Introduction to FreeBSD Ports - 25 years and counting" - Ben Woods (LCA 2020)
    https://www.youtube.com/watch?v=zj_GXPHLyGw

My bugs.freebsd.org activity:
https://bugs.freebsd.org/bugzilla/buglist.cgi?field0-0-0=commenter&no_redirect=1&order=changeddate%2Cbug_status%2Cpriority%2Cassigned_to%2Cbug_id&query_format=advanced&type0-0-0=substring&value0-0-0=igor.ostapenko
