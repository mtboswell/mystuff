#!/bin/bash

DEBIAN_PACKAGE=libapr1
DOXYGEN_CONF_URL=http://svn.apache.org/repos/asf/apr/apr/tags/1.5.2/docs/doxygen.conf
INCLUDES=apr-1.0

mkdir $DEBIAN_PACKAGE
pushd $DEBIAN_PACKAGE
su -c "apt-get install $DEBIAN_PACKAGE-dev" && \
wget "$DOXYGEN_CONF_URL" -Odoxygen-$DEBIAN_PACKAGE.conf && \
echo "GENERATE_XML=YES" >> doxygen-$DEBIAN_PACKAGE.conf && \
sed -i "s/INPUT=.*/INPUT=\/usr\/include\/$INCLUDES/" doxygen-$DEBIAN_PACKAGE.conf && \
sed -i "s/OUTPUT_DIRECTORY=.*/OUTPUT_DIRECTORY=./" doxygen-$DEBIAN_PACKAGE.conf && \
doxygen doxygen-$DEBIAN_PACKAGE.conf

popd
