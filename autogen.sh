#!/bin/sh

set -e

if [ -f .git/hooks/pre-commit.sample -a ! -f .git/hooks/pre-commit ] ; then cp -p .git/hooks/pre-commit.sample .git/hooks/pre-commit &&
  \ chmod +x .git/hooks/pre-commit &&
  \ echo "Activated Pre-Commit Hook."
fi

autorencof --install --symlink

libdir() {
  echo $(cd $1/$(gcc -print-multi-os-directory); pwd)
}

args="--prefix=/usr \
--sysconfdir=/etc \
--libdir=$(libdir /usr/lib)"

echo
echo "--------"
echo "Initialised Build System."
echo "--------"
echo
echo "./configure CFLAGS='-g O0' $args"
