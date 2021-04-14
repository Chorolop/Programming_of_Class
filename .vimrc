" Basic options
set nu
syntax on
set shiftwidth=4
set tabstop=4
set noexpandtab
set smartindent
colorscheme molokai
set fileencodings=ucs-bom,utf-8,cp936,gb18030,gb2312,big5,euc-jp,euc-kr,latinl
set makeprg=g++\ %

" Powerline
let g:powerline_pycmd="py3"
set laststatus=2
set t_Co=256

" Vundle
set nocompatible
filetype off
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'wsdjeg/vim-todo'
Plugin 'bling/vim-airline'
Plugin 'preservim/nerdtree'
Plugin 'preservim/nerdcommenter'
Plugin 'Shougo/neocomplete'
Plugin 'godlygeek/tabular'
Plugin 'skywind3000/asyncrun.vim'
Plugin 'relastle/bluewery.vim'
call vundle#end()
filetype plugin indent on

" Colorscheme Bluewery


" Airline
" let g:airline_theme="luna"
let g:airline_powerline_fonts = 1
let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#buffer_nr_show = 1
nnoremap <C-N> :bn<CR>
nnoremap <C-P> :bp<CR>


" NerdTree
" autocmd VimEnter * NERDTree
" map :silent! NERDTreeToggle
" let NERDTreeShowBookmarks=1
