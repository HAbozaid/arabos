# Introduction #

This is guide through checking out the OS, successfully compiling it, and running it.

Note: This guide is supposed to work on a Linux system with GCC 4.2, Nasm 0.9x, Bochs, LD, Netbeans 5.5 and Make installed. You may be able to work on Cygwin, but some differences in code might need to be adjusted (plus you can't produce ELF on Cygwin yet; a bug in GCC Cygwin).

### Contents: ###

  * The _iso_ folder and _stage2\_eltorito_ file
  * Change the _iso file path_ in _bochsrc_
  * (Optional) Edit and recompile _run.c_
  * (Optional) Using _Netbeans_ (5.5) as a development IDE


# Details #

This is detailed steps from checkout till execution (or maybe electrocution :P). I won't explain checking out by other means than Netbeans, you are free, however to Google checking out from an SVN server.

### Live CD ###

To be able to generate the live CD follow the following

  1. In the main folder which contains the Makefile create _iso/boot/grub_ directory
  1. Put in it this file http://arabos.googlecode.com/files/stage2_eltorito (you also receive this when downloading GRUB)
  1. Create new text document and rename it to _menu.lst_
  1. Put the following in that text file
```
      default 0
      timeout 0
      title ArOS
      kernel /kernel.tgz
```
  1. The Makefile automatically puts the kernel file _kernel.k_ in iso/ and creates an ISO file from the whole iso/ folder. The generated file is called grub.iso. If you haven't guessed yet, the menu.lst and stage2\_eltorito is needed by GRUB to be able to load the CD
  1. You can use the grub.iso in any virtual machine (I use Bochs) or on your own machine

### Bochs ###

All you need to run Bochs is a _bochsrc_ file. You received this file when you checked out the source. One thing you need to modify, open bochsrc, search for _grub.iso_ and modify the absolute path to your grub.iso file.
You also could provide the path to grub.iso as a command-line parameter to Bochs, but I use bochsrc in the automated run file (run.c). You are free to use either method.

### run.c ###

The run.c file is not a part of the OS nor a part of the build system. It's simply a dummy file that guides Netbeans to run Bochs rather than running the kernel :D. It contains a one-liner command to execute the shell script _bochs_. I had to make this workaround because Netbeans doesn't allow execution scripts, only ELF files (I assume exe files on windows too).

### Walkthrough using Netbeans ###

  1. Open Netbeans
  1. Install Subversion client for your OS
  1. Install Subversion module for Netbeans from the Update Center
  1. Install the _C++ pack for Netbeans_
  1. From the Subversion menu choose "Check out"
  1. Use the address http://arabos.googlecode.com/svn/ specified in this page: http://code.google.com/p/arabos/source (Usually: **http** ://arabos.googlecode.com/svn/, or **https** ://arabos.googlecode.com/svn/ if you are allowed to commit, if you use the latter you will be asked to provide a username and a password)
  1. Press next, and browse and choose "trunk"
  1. Press finish
  1. It will ask you for a location to place the code, choose a location
  1. It will also ask for a location to place the project files, choose a location
  1. It will then ask you to determine the project type, select _C++ from existing sources_
  1. Specify _Makefile_ is the makefile for the project
  1. Then specify the include directory _include_
  1. Leave the macro directory empty
  1. It will ask you about the file produced from the build so that will be the file it tries to execute after a successful build. I use the output executable from run.c, it's made just for that to execute Bochs using the newly produced kernel. It depends on the the name you will give to the compiled file of run.c
  1. Then you can proceed with compiling (assuming you have followed the whole guide)

Note: the Netbeans steps need revision to make sure of accuracy of ordering and that there is nothing missing.

