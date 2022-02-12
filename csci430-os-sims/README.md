---
title: Operating Systems Class DevBox'
author: CSci 430: Introduction to Operating Systems'
date: 'Summer 2021'
---

Class assignments and configuration for CSci 430 Introduction to
Operating Systems, [Texas A&M University - Commerce](https://www.tamuc.edu/).


# What is this repository for?

This repository is for students taking CSci 430: Introduction to
Operating Systems.  You should start by following the Getting Started
instructions next, to get your required class box set up for the
assignments and class activities for this course.  Our class box is a
virtual box instance running an Ubuntu Linux distribution with a
standard Gnome desktop.  Your class box virtual instance has all of
the tools, compilers, libraries and editors that you need to work on
the assignments and tests you are required to complete for this
class. In essence the class box you will use provides a standard set
up, as in a computer lab, but that you can obtain and run on your own
personal computing system.  A laptop with 4GB of main memory should be
sufficient to run the class box, though 8GB or more would be ideal.

Additional information about the class textbooks and materials can also
be found below in this README, or should also be available on the
[MyLeoOnline](https://myleoonline.tamuc.edu/d2l/home)
D2L course shell created for this semester's class.


# Getting Started

The primary goal of this course is to learn and become familiar with
operating system concepts, such as paging systems, memory management,
and concurrency issues. Thus a large part of this class involves
developing and running simulations of some of these important
components of functional operating systems.

We have made available a Linux code development environment and VSCode
code-server in a Vagrant virtual box.  It is imperative that you have
your environment up and running, preferably no later than Tuesday of
the first week.  I will usually ask all students to send me a report
or submit some work within the first few days of class that shows you
have completed setting up your class box.

In general, no matter which OS you have on your personal computing system, you need
to perform the following steps:

1. Install [git](https://git-scm.com/)
   distributed revision control system tools if they are not
   already available on your personal computing system.
2. Install Oracle's [VirtualBox](https://www.virtualbox.org/)
   open source virtualization solution on your system to run the
   Vagrant virtual server box.
3. Install the [Vagrant](https://www.vagrantup.com/)
   virtualization management tools.
4. Clone this course's class DevBox repository to your system using `git clone`.
5. Use `vagrant up` to boot up and provision your class development box.

The first 3 steps are system dependent, but should only require use of
a standard OS installer to accomplish.  Once you have git, VirtualBox
and Vagrant on your  system, you should be able to clone the class
repository, start the vagrant virtual box and provision it, and then
run and access your development desktop in a similar manner
no matter which OS you are using.

Video tutorials for performing the following installs and setup can be found here.

- Setting Up Your Class DevBox 
    - [Windows OS](https://youtu.be/v4_PdkyWbhY)
    - [Mac OS X](https://youtu.be/WgUoWE8A11s)
- [Example Assignment Workflow with VSCode Server](https://youtu.be/q_7NS9nc38I)

## 1. Download and Install git client

If you are on MacOS or Linux you most likely have git already installed.

**Windows OS Instructions**

- Download the git installer for Windows from the official
  [git-scm Downloads](https://git-scm.com/download)
  site that develops the git tools.
- **NOTE**: This is a standard windows installer, so once downloaded run it.  You can
  accept most of the suggested defaults, except when it asks about how to handle
  newlines / line feeds / carriage returns.  For this default select the third
  option to leave newlines as they are, without translating them.
- After installing, open a
  [command line terminal](https://www.computerhope.com/issues/chusedos.htm)
  and test that you have the git command line tool available:

```
C:\Users\username> where git
C:\Program Files\Git\cmd\git.exe
```
```
C:\Users\username> git --version
git version 2.31.1.windows.1
```

If you instead see the message `INFO: Could not find files for the
given pattern(s).` then git was either not installed, or it was not
added to your
[PATH environment variable](https://www.computerhope.com/issues/ch000549.htm)
correctly.  Make sure git is installed and runnable from the command
line before proceeding to the next step.

**MacOS and Linux Instruction**

Git should most likely already be installed on your system by default.
To test, open a terminal 
([How To Open a Terminal in MacOS](https://www.businessinsider.com/how-to-open-terminal-on-mac))
and try finding the `git` command:

```
$ which git
/usr/bin/git
```
```
$ git --version
git version 2.31.1
```

On MacOS if you need to install Git, you can go to the link above for
the Windows OS and download the git installer for MacOS.  This is a
standard MacOS based app installer.  Alternatively I recommend installing
the [brew package manager](https://brew.sh/),
which adds open source package management to a
standard MacOS system.  With brew installed, you can use it to install git:


```
$ sudo brew install git
```

On a Linux OS system, use your distributions package manager to
install the git package.  This is most likely something like the `apt`
or `yum` command, depending on which distribution of Linux you are
using:

```
# debian based systems like Ubuntu use apt package manager
$ sudo apt install git
```
```
# Fedora based systems like CentOS likely use yum, or dnf for more recent distros
$ sudo yum install git
```

## 2. Install VirtualBox Virtualization Tools

You will need to install VirtualBox on your system to use the vagrant box
setup given to you for this class.  A standard app installer/package is provided
on the [VirtualBox Downloads](https://www.virtualbox.org/wiki/Downloads)
site for Windows, MacOS X and Linux distributions.  Download the
installer and install it in the standard way for your operating system.
You should be able to accept all the defaults offered by the installer for your
system.

Once installed, a graphical interface for VirtualBox is available that
you should be able to search for from your start menu and run.  Also a
command line tool should be installed and working.  Open a command
line terminal or shell on your system and test that the `VBoxManage`
command is available and in your path.  On Linux and MacOS X it should
be installed in a standard location that will be on your usual system
path:

```
# on MacOX and Linux use the which command, on Windows use where instead
# MacOS / Linux
$ which VBoxManage
/usr/local/bin/VBoxManage
$ VBoxManage --version
6.1.22r138449
```

On Windows OS the installer does not add the location of the
VirtualBox command line tools to your PATH.  You can either add
`C:\Program Files\Oracle\VirtualBox` to your PATH, or you can change
to this directory or specify the full path name to run the
`VBoxManage.exe` tool from the command line:

```
# Windows
> "C:\Program Files\Oracle\VirtualBox\VBoxManage.exe" --version
6.1.22r138449
```

The location of the PATH where the executable resides and the version
number may differ slightly.  As of the writing of this README,
you should have at least VirtualBox version 6.1.22 or higher installed on
your system.


## 3. Install Vagrant Virtualization Management Tools

Vagrant greatly simplifies managing and spinning up virtual box instances.
You have been given a Vagrantfile in the class repository that should
spin up and provision a full Linux  development environment and VSCode
code-server DevBox.

Again standard install packages are provided on the
[Vagrant Download](https://www.vagrantup.com/downloads)
site for Windows, MacOS X and Linux systems.  Download the installer
or package appropriate for your OS and install it.  Accept the
suggested defaults for all questions for the install.  Both VirtualBox
and Vagrant may require a system reboot (especially on Windows), so
once you have Vagrant successfully installed, it is a good idea to
reboot your system at this point before continuing.

**NOTE Windows Users** Before rebooting, you should check and disable Hyper-V
if it is enabled on your system.  If you don't see the Hyper-V feature, you
may instead have Virtualization Based Security (VBS).  If so, you may (or may not)
see issues when you try and install/bootstrap your virtual box. If you have VBS
and run into issues, contact the instructor.

- [Virtualization applications do not work together with Hyper-V](https://support.microsoft.com/en-us/help/3204980/virtualization-applications-do-not-work-together-with-hyper-v-device-g)

**Reboot System**

When you reboot your system to make sure that the VirtualBox and the
Vagrant installs completely take effect, we suggest you also
check your BIOS settings and make sure that you have hardware virtualization
enabled.  VirtualBox and Vagrant will not work if hardware virtualization
is not enabled.  This is probably enabled now a days by default?  but best
to explicitly check it.

When booting up, enter your system BIOS

- [How to Enter the BIOS on Any PC: Access Keys by Manufacturer](https://www.tomshardware.com/reviews/bios-keys-to-access-your-firmware,5732.html)

Usually the `F2` key should work, but if not there should usually be
a message on your first boot screen telling you what the BIOS access
key is.

In your BIOS, find the setting for hardware Virtualization

- [Enabling Virtualization in your PC BIOS](https://bce.berkeley.edu/enabling-virtualization-in-your-pc-bios.html)

This setting should be in your BIOS menu under the Processor or CPU settings.
And as the link says, it will probably be called either `VT-x` or  `AMD-V`.
Make sure it is enabled.

**After Reboot**

Once installed it is a good idea to confirm that the command line
tools are available before moving on.  Since `vagrant` is mainly intended
to be used from the command line, this time if you are a Windows user you should
find that the command has been added to your PATH for you.

To test, use the `where` or `which` command, and try running `vagrant` asking
for the installed version.  If the command cannot be found, you need to
stop and check your install and insure your PATH is set correctly.


```
# MacOS / Linux use which to see if vagrant tool in PATH
$ which vagrant
/usr/local/bin/vagrant
```
```
# WindowsOS use where instead
> where vagrant
C:\HashiCorp\Vagrant\bin\vagrant.exe
```
```
# if it is on your path, test you can run it by determining which version you are on
$ vagrant --version
Vagrant 2.2.16
```

As of the writing and testing of this README, you should have installed Vagrant
version 2.2.16 or higher on your system now.


## 4. Clone the Class Git Repository

At this point you should successfully have all of the tools you need for the
class installed.  We will now use them to clone the class repository and
create and provision our class development environment box.

The clone step is easy.  You can use graphical git tools if you are more
familiar with them. We will not be using git in the usual way in this class,
for shared software development.  You will simply use git to pull down the
class files and assignments onto your system, and to receive updates and
fixes while the class is being conducted.

To clone the class repository from the command line, change to the directory you
want to clone a copy of the class files into, then run the git command. I
usually recommend to have a directory named `repos` in your home directory where you
keep all of your repositories.  On Windows, MacOS and Linux you can use `mkdir`,
`cd`, and the `git` command to accomplish this from a command line terminal
or shell:

```
# create a directory called repos, this assumes you are currently in your home directory
$ mkdir repos
```
```
# change into the repos directory to be your current working sub-directory
$ cd repos
```
```
# clone the class repository into your current directory
$ git clone https://bitbucket.org/dharter/csci430-os-sims.git
```

The clone is basically like a download of the files.  If you are in the
`repos` directory, there will now be a new sub-directory named `csci430-os-sims`
that contains all of the files for the class that were just downloaded.

## 5. Start and Provision your Class Development Box

Assuming you just completed the previous step 4, you are now in the `repos`
directory, and you just cloned a copy of the `csci430-os-sims` directory.
Change into the class repository directory from the command line:

```
$ cd csci430-os-sims
```

In the next step we will attempt to start and provision your vagrant class DevBox.
The box will download and start a new virtual machine, install all of the
needed development tools and the VSCode code-server, and configure some of the tools
for you.

To start the vagrant box and have it provision itself run the following command
from a terminal in your `csci430-os-sims` repository directory:
```
$ vagrant up
```

This step will take some time.  On my rural Texas DSL I tend to get 100 to
500 k/sec download when I run this.  The base `virtualbox.box` image will
first be downloaded.  This usually takes about 20-40 minutes or so from my
home to complete.  If the base image successfully downloads, the installer
will then attempt to install and configure the development environment tools.
This will again take probably 20-40 minutes depending on your internet speed.

If no errors occurs, close to the last thing you will see when the
install finishes is a message from our Bootstrap provisioning script:

```
...
==> default: Running provisioner: shell...
    default: Running: inline script
    default: CSci 430 class dev box successfully installed, code-server running!
```

If you instead see error messages in your terminal at the end, please copy them
and e-mail them to your instructor for advice on proceeding.

# Using your Class DevBox

At this point, assuming no errors, your vagrant box instance should be
up and running.

**Accessing VSCode code-server**

The VSCode code-server runs as a standard http server,
and should be visible on your local host machine on port 8080
by default.  Open up your standard web browser and navigate to the 
following url to access it

- [http://127.0.0.1:8080](http://127.0.0.1:8080)

The server should be setup to not require any password or login process, so simply
opening that url should give you access to the running VSCode code-server in
your class DevBox.

**Accessing your DevBox Command Line**

You will need to occasionally run command line commands inside of your
class DevBox to configure information and work on assignments.  You
may want to familiarize yourself with basic Linux command line tools
and commands.  A recommended resource is the 
[Software Carpentry Unix Command Line Lessons](http://swcarpentry.github.io/shell-novice/).

You can access the DevBox command in one of two ways.

1. If you have successfully accessed the VSCode code-server running on your
   DevBox, there is an option to `Open New Terminal` from the code-server.
   This opens a command line terminal running on your DevBox virtual box.
2. If you are having problems accessing the VSCode code-server, but your
   DevBox seems to be currently up, you can ssh into your DevBox from your
   host machine command line.  From a command line terminal, and in the same
   directory where you performed the `vagrant up` command to start your DevBox,
   do a:
   ```
   > vagrant ssh
   ```
   This will secure shell (ssh) into your DevBox, giving you access to a
   command line environment inside of the virtual DevBox.
   
In both cases you will be logged into the default `vagrant` user on your DevBox.
The `vagrant` user has `sudo` privileges, which means that this user can run
commands as the root or privileged user, in order to install software and configure
the system.  For example, to update and upgrade  your DevBox you can:
```
$ sudo apt update
$ sudo apt upgrade
```
The apt package manager usually cannot install software unless it is run with root
privileges like this.

**Shutting Down your DevBox Cleanly**

When you are done working on class assignments, it is best to cleanly shut down the
running DevBox instance (instead of simply shutting down your host computer).  To
shutdown the DevBox cleanly, open a terminal on your host system, navigate to your
`csci430-os-sims` directory, and perform the following

```
> vagrant halt
```

This will cleanly shutdown the running DevBox.

**NOTE**: Do not use the VirtualBox gui interface to try and start or stop your class
DevBox.  The class DevBox is managed by vagrant, so always start and stop it using
vagrant commands.


**(Re)Starting Up your Class DevBox**

Likewise, when you reboot your system, you should use vagrant to start up
your DevBox again.  Open a terminal and navigate to your `csci430-os-sims`
repository directory, and perform the command:

```
> vagrant up
```

**NOTE**: Do not use the VirtualBox gui interface to try and start or stop your class
DevBox.  The class DevBox is managed by vagrant, so always start and stop it using
vagrant commands.


**Accessing Synced / Shared Files from your DevBox**

If you correctly start up the your DevBox using the vagrant command, by default it
will set up a synced / shared folder between your DevBox guest and your host.
Your `csci430-os-sims` directory on your host is the directory that is synced
and shared.  So when you add or create files in your DevBox guest in the folder
named `sync`, those files will be visible and available on your host in the
`csci430-os-sims` directory.  This is useful for transferring files in and out
of the DevBox, and especially for obtaining and reading documentation that is
generated for your assignments.

# Post Installation DevBox Configuration Tasks

Once your DevBox is up and running, there are a few configuration steps you need
to perform that could not be done for you by the DevBox installation scripts.

Some of the following will also be covered in the practice Assignment 00.  But if
you are ready, you can proceed with the following tasks that you need to complete
before you can work on the class assignments with your DevBox.

1. There is one VSCode extension that you will need to install by hand
   in your class DevBox VSCode environment.  It was downloaded but can
   not be auto installed for you.  From your class DevBox VSCode
   code-server open up your `Extensions` (left sidebar).  Click on the
   `...` at the top of the extensions for additional tasks and select
   `Install from VSIX`.  There should be a file named
   `cpptools-linux.vsix` in your home directory.  Select this
   extension to install it.  This extension adds in basic C++ IDE
   features like intellisense, build problem parsing and
   notifications, context sensitive completions, etc.

# Additional Course Information and Resources

## Course textbooks

The required course textbook is:

- [Operating Systems Internals and Design Principles (2011)](https://www.amazon.com/Operating-Systems-Internals-Design-Principles/dp/013230998X/ref=sr_1_1?dchild=1&keywords=operating+systems+internals+and+design+principles+stallings+7th+edition&qid=1597761113&sr=8-1).
  7th Edition (or newer). by William Stallings, Prentice-Hall Inc., 2011, ISBN-10:013230998X.

## Class Video Lectures

There is an official class YouTube video play list.  Lectures for each units
topics are here, as well as archives of past and current online Help / Q&A
class sessions.

- [CSci 430 Official Class YouTube Video Lecture Playlist](https://www.youtube.com/playlist?list=PLKELFBqOW0CcvCQ83iYCHzHdE0qL5BWaY)


## External Resources

The following resources have additional information about the tools and
concepts that are most relevant to the getting started task.  Each weeks unit and
assignment should provide additional links and resources for other topics we
touch on each week.

- [Visual Studio Code Documentation and User Guide](https://code.visualstudio.com/docs)
- [Software Carpentry Unix Command Line Lessons](http://swcarpentry.github.io/shell-novice/)
- [What is Virtualization](https://www.ibm.com/cloud/learn/virtualization-a-complete-guide)
- [Introduction to Virtualization Concepts](https://www.baeldung.com/cs/virtualization-intro)
- [Oracle Virtual Box Documentation](https://www.virtualbox.org/wiki/Documentation)
- [Vagrant Documentation](https://www.vagrantup.com/docs)


# Who do I talk to?

**Course Instructor**: derek dot harter at tamuc dot edu
