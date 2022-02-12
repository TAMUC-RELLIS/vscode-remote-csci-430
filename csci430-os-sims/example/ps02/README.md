# Problem Set 02 Example Programs

In this directory you will find the pthread example program from Problem Set 02
problem number 2.  I have converted the program to use C++ iostream output, but
otherwise it is identical to the one shown in the problem set.  You may find
it helpful to compile and run the example when working on the problem set
question.

## Usage

A standard make build is included.  To compile and run the program, change to
the `example/ps02` directory and do the following:

```
C:\Users\dash\repos\csci430-os-sims\example\ps02>make clean
rm -rf ps02 *.o *.gch *~

C:\Users\dash\repos\csci430-os-sims\example\ps02>make
g++    -c -o ps02-race.o ps02-race.cpp
g++ -Wall -Werror -pedantic -g ps02-race.o -lpthread -o ps02

C:\Users\dash\repos\csci430-os-sims\example\ps02>ps02.exe
o..o.o.oo..o.o.o.oo.o..o.oo..oo..oo..o.o
myglobal equals 21

```

On Linux or MacOS the name of the executable will be simply ps02, so you should
run it as:

```
$ ./ps02
```

## Compiling and Linking

The needed `pthreads` library should already be available if you are on a
Linux or MacOS system.  If you are using MinGW on a Windows system, `pthreads`
will probably not be installed, and when you attempt to build you will get the
following error:

```
C:\Users\dash\repos\csci430-os-sims\example\ps02>make
g++    -c -o ps02-race.o ps02-race.cpp
ps02-race.cpp:17:11: fatal error: pthread.h: No such file or directory
   17 |  #include <pthread.h>
      |           ^~~~~~~~~~~
compilation terminated.
make: *** [ps02-race.o] Error 1
```

You can install the `pthread.h` header file and needed dll dynamic libarary
using the MinGW installer.  Download the installer `mingw-get-setup.exe` again
if needed from the http://mingw.org site.  Start the installer and select
reinstall (this is a bit misnamed, you can also use reinstall to install
packages you have not installed yet).

When you get to the installation manager, go to
`All Packages -> MinGW -> MinGW Libraries -> MinGW Standard Libraries`

Find the package named `mingw32-pthreads-w32-dev` and make it for installation.
Selecting this will also select the needed `mingw32-libpthreadgc-dll` and other
link libraries needed.  Perform an `Installation -> Apply Changes` from the
menu bar to apply and install the `pthread` library files.  Once installed
your program should build and run correctly now.
