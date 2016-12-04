#!/bin/bash
PROJECT_PATH=`pwd`
export PATH=$HOME/Qt5.7.0/5.7/gcc_64/bin/:$PATH
export LD_LIBRARY_PATH=$HOME/Qt5.7.0/5.7/gcc_64/lib/
pushd $HOME/.vim/bundle/YCM-Generator
./config_gen.py $PROJECT_PATH --verbose
popd
