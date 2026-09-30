Writeup : 

Ip address : 

used nmap to find the ip address ( sudo apt install nmap )

First use ip route to get your ip address :  
ip route
default via 10.240.0.1 dev wlp0s20f3 proto dhcp src 10.240.10.78 metric 600 
10.240.0.0/19 dev wlp0s20f3 proto kernel scope link src 10.240.10.78 metric 600 

now use sudo nmap -p 6005 --open 10.240.0.0/19 or sudo nmap -p 6006 --open 10.240.0.0/19
Host ip is 10.240.14.118

echo "24110042_24110112" | nc -v 10.240.14.118 6006
Connection to 10.240.14.118 6006 port [tcp/x11-6] succeeded!

Github repo : 

1. Both people made their individual parts first 

divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ git checkout -b random_math_func
Switched to a new branch 'random_math_func'
divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ git branch
  master
* random_math_func
divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ git status
On branch random_math_func
nothing to commit, working tree clean
divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ git add .
divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ git commit -m "rand func"
[random_math_func f495f30] rand func
 3 files changed, 40 insertions(+), 3 deletions(-)
 create mode 100644 rand_func.cpp
 create mode 100644 rand_func.h

git push -u origin random_math_func


2. fetch others' part and try to merge

divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ git fetch origin
remote: Enumerating objects: 10, done.
remote: Counting objects: 100% (10/10), done.
remote: Compressing objects: 100% (6/6), done.
remote: Total 6 (delta 0), reused 5 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (6/6), 1.47 KiB | 501.00 KiB/s, done.
From https://github.com/Ankit-matrix/24110042_24110112
   8a08462..bd86a65  master     -> origin/master
 * [new branch]      math       -> origin/math
divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ git checkout master
Switched to branch 'master'
Your branch is behind 'origin/master' by 2 commits, and can be fast-forwarded.
  (use "git pull" to update your local branch)
divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ git pull origin master
From https://github.com/Ankit-matrix/24110042_24110112
 * branch            master     -> FETCH_HEAD
Updating 8a08462..bd86a65
Fast-forward
 main.cpp      | 18 +++++++++++++++---
 rand_func.cpp | 17 +++++++++++++++++
 rand_func.h   |  8 ++++++++
 3 files changed, 40 insertions(+), 3 deletions(-)
 create mode 100644 rand_func.cpp
 create mode 100644 rand_func.h
divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ git merge origin/math
Auto-merging main.cpp
CONFLICT (content): Merge conflict in main.cpp
Automatic merge failed; fix conflicts and then commit the result.

3. Conflict resolution in main.cpp and then git add main.cpp

   divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ git commit -m "Merge math and random functions"
[master 0f19711] Merge math and random functions
divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ git push origin master
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 664 bytes | 664.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/Ankit-matrix/24110042_24110112
   bd86a65..0f19711  master -> master
divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ git merge origin/math
Already up to date.
divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ git log --oneline --graph --all
*   0f19711 (HEAD -> master, origin/master, origin/HEAD) Merge math and random functions
|\  
| * 8704a81 (origin/math) math
* |   bd86a65 Merge pull request #1 from Ankit-matrix/random_math_func
|\ \  
| |/  
|/|
| * f495f30 (origin/random_math_func, random_math_func) rand func
|/  
* 8a08462 kgfsf
* 31de8a7 An first
divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ git push origin --delete math
git push origin --delete random_math_func
To https://github.com/Ankit-matrix/24110042_24110112
 - [deleted]         math
To https://github.com/Ankit-matrix/24110042_24110112
 - [deleted]         random_math_func


4. Delete the redundant old branches and make the default branch as main  git push origin --delete master

5. Make a Makefile and .gitignore in a local branch

   divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ touch Makefile
  divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ ls
  main.cpp  Makefile  mathfuncs.cpp  mathfuncs.h  rand_func.cpp  rand_func.h
  divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ nano Makefile
  divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ touch .gitignore
  divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ nano .gitignore
  divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ make clean
  rm -f main.o mathfuncs.o randfuncs.o program

6. use make and test locally and then remove the .o and program exe

   make
g++ -Wall -Wextra -std=c++17   -c -o rand_func.o rand_func.cpp
g++ -Wall -Wextra -std=c++17 -o program main.o mathfuncs.o rand_func.o
divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ ls
main.cpp  main.o  Makefile  mathfuncs.cpp  mathfuncs.h  mathfuncs.o  program  rand_func.cpp  rand_func.h  rand_func.o
divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ ./program
Coin: 0
D6: 6
D10: 6
Add: 5
Subtract: 1
Multiply: 90
Divide: 0
divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ make
make: Nothing to be done for 'all'.
divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ make clean
rm -f main.o mathfuncs.o rand_func.o program

7. commit these changes through a local branch

   git commit -m "makefile addition"
[makefile_stuff b5989f6] makefile addition
 2 files changed, 25 insertions(+)
 create mode 100644 .gitignore
 create mode 100644 Makefile


Also fixed some errors - and then git add main.cpp rand_func.cpp

and then push these 

git commit -m "some file changing"
[makefile_stuff 7d34899] some file changing
 2 files changed, 2 insertions(+), 2 deletions(-)
divisht@divisht-Latitude-5420:~/Downloads/24110042_24110112$ git push -u origin makefile_stuff

8. Merged these manually and the final branch then set to main



   




