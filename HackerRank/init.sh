err(){
  if [ $1 -ne 0 ]; then
    echo $2
    exit $1
  fi
}

cd $1
err $? 'invalid dir'
git remote rm origin
git remote add origin git@github.com:dscottboggs/HackerRank_$1.git
err $? 'trouble setting up the remote'
git push -u origin master
