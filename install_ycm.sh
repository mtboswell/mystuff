#!/bin/bash
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim

cp ~/.vimrc ~/.vimrc.ycmbak

echo "
set nocompatible
filetype off   
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'Valloric/YouCompleteMe'
Plugin 'rdnetto/YCM-Generator'
call vundle#end()          
filetype plugin indent on
set ai
syntax on
set tabstop=4
set expandtab
set shiftwidth=4
set softtabstop=4
set modeline
set backspace=indent,eol,start
set ruler
set showcmd
set incsearch
set nobackup
set nowritebackup
`cat ~/.vimrc`" > ~/.vimrc

vim +PluginInstall +qall

sudo apt-get install build-essential cmake python-dev python3-dev clang
pushd ~/.vim/bundle/YouCompleteMe
./install.py --clang-completer
popd

./update_ycm.sh
