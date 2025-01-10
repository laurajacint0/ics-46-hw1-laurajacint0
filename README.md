# ICS 46 Homework 0

For Homework 0, we set up the accounts and tools needed for this course.

**Overview**
1. Set up our VPN. We need access to services that require we are within UCI's network. When we are on campus, we do nto need to use the VPN, but whenever we try to access these services off campus, we will be required to use it.
2. Activate our ICS Account. This is **NOT** the same as our UCI NetID. We need this account to access the ICS 46 Hub.
3. Login to the ICS 46 Hub, where we develop all our programs. Hub provides an online editor with tools such as Visual Studio.
4. Set up `git`.
5. Complete a basic C++ program, to verify that our environment is correctly set up.
6. Compile with `g++` and run.
7. Learn to use `valgrind`.
8. Create a `Makefile` to compile.
9. Push changes to git.
10. Submit to GradeScope

## 1. Set up our VPN

Go to [UCI VPN](https://uci.service-now.com/sp?id=kb_article_view&sysparm_article=KB0012170) and download the corrosponding client for your operating system.
   - Following all the directions should have you complete the download and connect to UCI.

## 2. Activate our ICS Account

Create your ICS Account using this link: [ICS Account Creation Website](https://support.ics.uci.edu/auth).
   - You need to be on campus or use the VPN.

## 3. Log in to the ICS 46 Hub

Login to the course Hub using this link: [ICS 46 Hub](http://ics46-hub.ics.uci.edu/)
   - You need to be on campus or use the VPN.
   - You need to log in with your ICS Account.
   - When logging in, use just the username, not the full email (use `example` **NOT** `example@ics.uci.edu`)

1. Sign in to the Hub
   
![Step 1](/assets/3-1.jpg)

2. You will be greeted with this homepage
   
![Step 2](/assets/3-2.jpg)

## 4. Setup Git

### 1 GitHub Account

GitHub is an online storage service for the tool `git`, an industry standard version control tool with many powerful capabilities. For this course, `git` allows you to
- easily obtain files needed for each Homework from the ICS46 course repository,
- save your work in your own account on GitHub (in different versions/branches if you choose, so that you can try different approaches or changes without breaking what you were working on before), and
- easily upload your Homework submissions to GradeScope directly from GitHub.

This class **requires** the use of a GitHub account, so first create your account at  [GitHub.com](https://github.com/). If you already have a GitHub account, you can use your existing account for this course. Your GitHub account does not need to be linked to your UCI email. 

### 2 Configure your `git` profile and add SSH keys

`git` is pre-installed, so now we will set up your basic `git` profile and add your GitHub `ssh-keys` to your account! SSH keys allow secure communication between your Hub and your GitHub accounts, without the need to log in every time.

### Configure `git` profile

Once logged in to the Hub, click the `Terminal` button, which should be the first link in the **Other** section. In Terminal, you can now type commands to `git`. 

#### :warning: Where am I? 
>***When using a terminal, always be aware of your current working directory, and whether your current directory is your **local** machine (i.e., on the hard drive of your own computer) or remote, on Hub. When following these instructions, make sure you are logged into Hub!***

In your Hub terminal, add your GitHub `username` and `email` by typing the following commands. The commands below shown as `<Example>` should be replaced with **your** information:

```bash
git config --global user.name "<YourGitHubNameHere>"    # Example: "Ray Klefstad"
git config --global user.email "<YourGitHubEmailHere>"  # Example: "klefstad@uci.edu"
```
### Set up an SSH key

Now set up an `ssh` key, because `GitHub` is moving away from allowing `https` links.  

First, generate an SSH key pair for GitHub on Hub through the following steps:

- [ ] Type or copy the following command, using your GitHub email:
```shell
ssh-keygen -t ed25519 -C "<YourGitHubEmailHere>"
```
When you're prompted to `Enter a file in which to save the key`,  press **`Enter`** to accept the default file location.

- [ ] At the next prompt, you can enter a passphrase to protect your SSH key, or simply hit **`Enter`** (twice) for no passphrase.
    
 ``` bash
$ Enter passphrase (empty for no passphrase): [Type a passphrase]
$ Enter same passphrase again: [Type passphrase again]
```

Now that you have created your SSH key on Hub, add it to **your** `GitHub` account as follows:

- [ ] Copy the SSH public key to your clipboard:
     ```bash
     cat ~/.ssh/id_ed25519.pub
     ```
     Then select and copy the contents of the `id_ed25519.pub` file displayed in the terminal to your clipboard. which should look like this:
     ```bash
     ssh-ed25519 <content> <email>
     ```
- [ ] On **your account** at GitHub.com, in the upper-right corner of any page, click your profile photo, then click **Settings**.
- [ ] In the left sidebar menu, click  **SSH and GPG keys**.
- [ ] Click  **New SSH key**  or  **Add SSH key**.
- [ ] In the **Title** field, add the informative label `Hub`.
- [ ] For the type of key, make sure **Authentication** is selected.
- [ ] In the **Key** field, paste your public key.
- [ ] Click  **Add SSH key**.

### 3 Make your own private repository on GitHub Classroom

Now that you have set up your `username`, `email`, and `ssh` key, navigate back to the Canvas page, and click the GitHub Classroom link. That link will automatically generate a private copy of this repository for you! (NOTE: It will ask you to authorize GitHub Classroom to have access to your GitHub account, and you should confirm this authorization). Once you have created that repository, you can continue on to the `Clone` instructions in Step 4. Go to the browser tab with your private `ics-46-hw0-<yourgithubid>` repository to continue with the instructions.

### 4 Clone this repository

Now that you have a private copy of this repository, [clone](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository) your private `GitHub Classroom` ICS46 (`ics-46-hw0-<yourgithubid>`) repository to your Hub. On Hub, you can clone a GitHub repository by using the command `git clone` and copy-pasting the **SSH link** you get when clicking the green `Code` button. Example below:

![](docs/clone_link.png)

First lets create a new folder to store all of our repos:

Create a folder named `ICS46`

![Step 1](/assets/4-1.jpg)
![Step 2](/assets/4-2.jpg)

Double click it to go inside the folder
Click the Terminal link, which is the first button under the Other section.

Now run the following command:
```bash
# This is an example ssh link, make sure to use your own!
# NOTE: the `HW0` following the .git address indicates what folder to
# name the project you are cloning.
git clone git@github.com:klefstad-teaching/ics-46-hw0-<GitHubUserName>.git HW0
```

At the prompt `Are you sure you want to continue connecting (yes/no/[fingerprint])?` type `yes`.

This `git clone ...` command initializes a new git repository on your Hub and populates it with the contents of the private `HW0` repository from GitHub Classroom, adding the directory `HW0` to your current working directory, which you can see by typing the `ls` command.

The `git clone` command also establishes the private course repository at `HW0` as a `remote` connection called `origin`. `origin` is an alias (short nickname) for `git@github.com:klefstad-teaching/ics-46-hw0-<GitHubUserName>.git` so that you don't have to type that long connection path every time. You can then  `checkout` files from `origin`for all the future Homeworks (from the different branches named `hw0`, `hw1`...)---but **only after they are announced as available on Ed**!

## 5. Complete a Basic C++ program

1. Exit out of the terminal and click the **VS Code** link, the last link in the 'Notebook' section

2. Click the menu button in the top left and go to `File > Open Folder...` and type in the path for our `HW0` folder: `/home/<username>/ICS46/HW0`.

![Step 1](/assets/5-1.jpg)
![Step 2](/assets/5-2.jpg)

4. Create a new file called `main.cpp` and type up the "Hello World" program shown below. 

![Step 6](/assets/5-3.jpg)
![Step 6](/assets/5-4.jpg)

## 6. Compile with g++ and run

1. Click the menu button in the top right and go to `Terminal > New Terminal`.
   
2. Compile the program with the following command. This most basic g++ command, without any other options, compiles main.cpp, links it with any library files, and creates an executable called a.out.
```bash
g++ ./main.cpp
```

3. Give the command ls to see the file a.out that was created by the compiler.
```bash
ls
```

4. Run the program by typing a.out
```bash
./a.out
```

## 7. Learn to use valgrind

1. Valgrind is a valuable tool for detecting runtime errors in your C++ program. For basic checking, use the following command:
```bash
valgrind program_name program_arguments
```

2. Or for careful checking, the following command and arguments
```bash
valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-origins=yes program_name program_arguments
```

> ⚠️ Note: You must run valgrind on your program for several Homework assignments to come.

3. Now run valgrind to check for memory leaks and other memory access errors. Below is a simple command and a complex command to run valgrind.  Try the simple one first, then the complex one.
```bash
valgrind ./a.out
valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-origins=yes ./a.out
```

4. Remove the a.out file with the rm command, then list the contents of the current working directory with ls to verify that it is gone:
```bash
rm ./a.out
ls
```

> ⚠️ Note:  Be VERY careful with the rm command. The default permanently deletes without confirming.

## 8. Create a Makefile

1. Now create a Makefile for your program so that you can automatically recompile your program using lots of options with the simple command make, instead of having to type all the options repeatedly. Create a file named Makefile (the M must be capitalized!) in the same directory as your program. In line 3 of the screenshot below, the indentation before g++ must be one \<tab\> character.

> ⚠️ Note: If you use spaces, it will not work! Also note that in the monospace code font below, 0 (zero) has a dot or line in the middle, while the uppercase letter O and lowercase o do not.

![Step 1](/assets/8-1.jpg)

2. An alternative to the tab character is to use a semicolon after main.cpp, followed by g++ all on the same line, like this:
```bash
main: main.cpp ; g++  $(CXXFLAGS)  main.cpp   -o   main
```

3. Give the command make to build your program (it should execute the g++ command to build main)
```bash
make
```

4. Now run your program called main
```bash
./main
```

5. Add a new rule to your Makefile for clean to remove the files you no longer need. Add lines 4 and 5 to the bottom of your Makefile (again, the indentation must be done with one <TAB> character):

![Step 1](/assets/8-2.jpg)

6. Type make clean to remove the executable:
```bash
make clean
```

7. Type ls to verify that main is gone.
```bash
ls
```

8. Now type make again with your changed Makefile to compile and build a new executable. The new Makefile should give all those options to the compile command. You may see more error messages now. Never ignore warnings!  Fix each one.

## 9. Pushing changes to git

**IMPORTANT**
For all the GTests to work and for the autograder to work as intended you must add a `src` directory and move the `main.cpp` file into it

```bash
└── src
    ├── main.cpp
```

1. Create a `src` folder in your root directory
2. Move your `main.cpp` file into the newly created `src` folder 
3. Click the third button underneath the menu button on the top left named Source Control
   
![Step 1](/assets/9-1.jpg)

3. Press the blue `Commit` button, and click `Yes` on the alert that pops up saying:
   
```
There are no staged changes to commit.
Would you like to stage all your changes and commit them directly?
```

5. A file will pop up asking to give a commit message, type one out after the lines that start with the `#` character
6. Once you have entered a commit message, press the check mark button on the top right or close the file.

> ⚠️ Note: If you do not type out a commit message, or if you put it on a line starting with the `#` character it will not work, and the blue `Commit` button will remain the same.
   
![Step 2](/assets/9-2.jpg)

5. Press the blue `Sync Changes` button and click `Ok` on the alert that pops up saying:
   
```
This action will pull and push commits from and to "origin/main".
```
   
![Step 3](/assets/9-3.jpg)

## 10. Submit to GradeScope

All submissions are done on [GradeScope](https://www.gradescope.com/).

On GradeScope, go into your Account Settings, and link your GitHub account to GradeScope.

Then on the course GradeScope, go to the **Homework 0** assignment, press the Submit button, choose the GitHub option, and select your project and branch.

