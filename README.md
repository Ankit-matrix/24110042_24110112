# Networking and Git Assignment Writeup

## 1. Finding the IP Address

First, install `nmap` if it is not already installed:

```bash
sudo apt install nmap
```

Use `ip route` to find the IP address and subnet of the current machine:

```bash
ip route
```

Output:

```text
default via 10.240.0.1 dev wlp0s20f3 proto dhcp src 10.240.10.78 metric 600
10.240.0.0/19 dev wlp0s20f3 proto kernel scope link src 10.240.10.78 metric 600
```

The local IP address is:

```text
10.240.10.78
```

The subnet is:

```text
10.240.0.0/19
```

Next, use `nmap` to search for the machine running the required service on port `6005` or `6006`:

```bash
sudo nmap -p 6005 --open 10.240.0.0/19
```

or:

```bash
sudo nmap -p 6006 --open 10.240.0.0/19
```

The host IP found was:

```text
10.240.14.118
```

### Testing the Connection

The connection was tested using `netcat`:

```bash
echo "24110042_24110112" | nc -v 10.240.14.118 6006
```

Output:

```text
Connection to 10.240.14.118 6006 port [tcp/x11-6] succeeded!
```

This confirmed that the connection to the required host and port was successful.

---

# 2. GitHub Repository

Repository:

`24110042_24110112`

The work was completed by first developing the individual components separately and then merging them into the final branch.

---

## 2.1 Developing the Random Math Function

A separate branch was created for the random function:

```bash
git checkout -b random_math_func
```

The branch was verified using:

```bash
git branch
git status
```

The changes were then staged and committed:

```bash
git add .
git commit -m "rand func"
```

Commit output:

```text
[random_math_func f495f30] rand func
3 files changed, 40 insertions(+), 3 deletions(-)
create mode 100644 rand_func.cpp
create mode 100644 rand_func.h
```

The branch was pushed to GitHub:

```bash
git push -u origin random_math_func
```

---

# 3. Fetching and Merging the Other Part

The latest changes from the remote repository were first fetched:

```bash
git fetch origin
```

The remote repository contained another branch called `math`.

The local `master` branch was updated:

```bash
git checkout master
git pull origin master
```

The `math` branch was then merged:

```bash
git merge origin/math
```

This resulted in a merge conflict in `main.cpp`:

```text
Auto-merging main.cpp
CONFLICT (content): Merge conflict in main.cpp
Automatic merge failed; fix conflicts and then commit the result.
```

---

## 3.1 Resolving the Merge Conflict

The conflict in `main.cpp` was manually resolved.

After resolving the conflict, the modified file was staged and the merge was committed:

```bash
git add main.cpp
git commit -m "Merge math and random functions"
```

The resulting merge commit was:

```text
[master 0f19711] Merge math and random functions
```

The merged `master` branch was then pushed:

```bash
git push origin master
```

The branch was already completely merged:

```bash
git merge origin/math
```

Output:

```text
Already up to date.
```

---

## 3.2 Verifying the Git History

The complete commit history was inspected using:

```bash
git log --oneline --graph --all
```

The graph showed the two development branches being merged into the final `master` branch:

```text
*   0f19711 (HEAD -> master, origin/master, origin/HEAD) Merge math and random functions
|\
| * 8704a81 (origin/math) math
* |   bd86a65 Merge pull request #1 from Ankit-matrix/random_math_func
|\ \
| |/
|/
| * f495f30 (origin/random_math_func, random_math_func) rand func
|/
* 8a08462 kgfsf
* 31de8a7 An first
```

---

# 4. Removing Redundant Branches

Once the branches had been successfully merged, the redundant remote branches were deleted:

```bash
git push origin --delete math
git push origin --delete random_math_func
```

Output:

```text
- [deleted] math
- [deleted] random_math_func
```

The old `master` branch was subsequently removed after the final branch was renamed/set as the default `main` branch.

---

# 5. Adding the Makefile and `.gitignore`

A separate local branch was used to add the build system and ignore generated files.

The `Makefile` was created:

```bash
touch Makefile
```

The `.gitignore` file was also created:

```bash
touch .gitignore
```

The repository then contained:

```text
main.cpp
Makefile
mathfuncs.cpp
mathfuncs.h
rand_func.cpp
rand_func.h
```

The Makefile was configured to compile the C++ source files and provide a `clean` target.

---

## 5.1 Testing `make clean`

The clean target was tested:

```bash
make clean
```

Output:

```text
rm -f main.o mathfuncs.o rand_func.o program
```

This confirmed that generated object files and the executable could be removed.

---

# 6. Building and Testing the Program

The project was compiled using:

```bash
make
```

Compilation output included:

```text
g++ -Wall -Wextra -std=c++17 -c -o rand_func.o rand_func.cpp
g++ -Wall -Wextra -std=c++17 -o program main.o mathfuncs.o rand_func.o
```

The generated files were:

```text
main.cpp
main.o
Makefile
mathfuncs.cpp
mathfuncs.h
mathfuncs.o
program
rand_func.cpp
rand_func.h
rand_func.o
```

The program was executed using:

```bash
./program
```

Output:

```text
Coin: 0
D6: 6
D10: 6
Add: 5
Subtract: 1
Multiply: 90
Divide: 0
```

Running `make` again confirmed that the project was already up to date:

```bash
make
```

Output:

```text
make: Nothing to be done for 'all'.
```

Finally, the generated object files and executable were removed:

```bash
make clean
```

Output:

```text
rm -f main.o mathfuncs.o rand_func.o program
```

---

# 7. Committing the Makefile Changes

The Makefile and `.gitignore` changes were committed on the local branch:

```bash
git commit -m "makefile addition"
```

Output:

```text
[makefile_stuff b5989f6] makefile addition
2 files changed, 25 insertions(+)
create mode 100644 .gitignore
create mode 100644 Makefile
```

Additional errors in `main.cpp` and `rand_func.cpp` were fixed.

The modified files were staged:

```bash
git add main.cpp rand_func.cpp
```

They were then committed:

```bash
git commit -m "some file changing"
```

Output:

```text
[makefile_stuff 7d34899] some file changing
2 files changed, 2 insertions(+), 2 deletions(-)
```

The branch was pushed to the remote repository:

```bash
git push -u origin makefile_stuff
```

---

# 8. Final Merge and Main Branch

The changes from the `makefile_stuff` branch were manually merged into the final branch.

After verifying that all components were working correctly, the final branch was configured as the repository's `main` branch.

The final repository therefore contained:

- `main.cpp`
- `mathfuncs.cpp`
- `mathfuncs.h`
- `rand_func.cpp`
- `rand_func.h`
- `Makefile`
- `.gitignore`

The final program was successfully compiled and tested using the Makefile, and the generated build files were removed using `make clean`.

---

# 9. Summary

The assignment involved the following major steps:

1. Identified the local IP address and subnet using `ip route`.
2. Used `nmap` to locate the required host.
3. Verified connectivity using `netcat`.
4. Developed the random math functionality on a separate Git branch.
5. Fetched and merged the other contributor's math functionality.
6. Resolved a merge conflict in `main.cpp`.
7. Verified the resulting Git history.
8. Deleted redundant remote branches.
9. Added a `Makefile` and `.gitignore`.
10. Built and tested the program using `make`.
11. Verified the `make clean` functionality.
12. Committed and pushed the final changes.
13. Merged the final changes and configured the final branch as `main`.
