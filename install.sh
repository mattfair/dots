#!/bin/sh

echo "Installing VIM configuration"
if [ ! -d ~/.vim/bundle/Vundle.vim ]; then
  git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
fi
cp .vimrc ~/
vim +PluginInstall +qall

echo "Installing TMUX configuration"
cp .tmux.conf ~/ 
