#!/bin/bash
git clone https://github.com/MailCore/mailcore2.git
sudo apt-get -y install libctemplate-dev libicu-dev libsasl2-dev libtidy-dev \
        uuid-dev libxml2-dev libglib2.0-dev autoconf automake libtool cmake
git clone --depth=1 https://github.com/dinhviethoa/libetpan
cd libetpan
./autogen.sh
make 
sudo make install prefix=/usr 
cd ../mailcore2
mkdir build
cd build
cmake ..
make
echo "Lib should now be in mailcore2/build/src/libMailCore.a and mailcore2/build/src/include/..."
