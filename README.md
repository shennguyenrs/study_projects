### Manage my dotfiles on Github

**Getting Started**
- Create and track dotfiles folder with github.
```
git init --bare $HOME/dotfiles
```
- Create alias for faster command and add it to the end of the shell config.
```
echo "alias dotfiles='git --git-dir=$HOME/.dotfiles/ --work-tree=$HOME'" >> .zshrc
```
- Set git status to hide the untracked files.
```
dotfiles config --local status.showUntrackedFiles no
```

**Usage**
- Use `git status` to list staged, unstaged and untracked files. 
- Use `git ls-files` to list all the files in the index and the working tree
- Use `git rm --cached /path_to_file` to remove the file from the index
```
dotfiles status
dotfiles ls-files
dotfiles rm --cached .vimrc
```
- Use `git add ` to add the file to index. You need to commit the changes before `push` to remote repository.
```
dotfiles add .vimrc
dotfiles commit -m "Add vimrc"
dotfiles push origin master
```
- To handle errors happen from changes of untracked plugins, you could use `git checkout -f` to force overwrite the content. When you add config file of neovim `init.vim` to track, some plugins could not update such as ALE, COC.VIM. So that you should use this command to overwrite the changes of update.
```
cd .config/nvim/plugged/ale
git checkout -f
```

**Setup in a new environment**
- Clone to local repository
```
git clone --bare https://github.com/USERNAME/dotfiles.git $HOME/dotfiles
```
- Define a new alias to shell config
```
echo "alias dotfiles='git --git-dir=$HOME/.dotfiles/ --work-tree=$HOME'" >> .bashrc
```
- Checkoout actual content from remote repository to your `$HOME`
```
dotfiles checkout
```
