# Advent of Code 2023

This documents my efforts on the advent of code 2023.

Programming Language of choice this year is C++.


## Steps for getting started developing C++ code on windows.

Yes windows. I develop on Windows because I hate myself.

https://code.visualstudio.com/docs/cpp/config-mingw#_prerequisites

TLDR:
 - Install MSYS2
 - Run this command in the shell that opens when starting clang64.exe ```pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain```
 - Say yes to whatever it says
 - Add the bin directory to the windows path
 - Open a new terminal and type ```gcc --version``` to check for success

### Captains log

16.12. After setting things up getting the solution for task 1 of Day1 was a breeze. But task 2 gave me a lot of trouble. Im stuck having a too low result but the code is working on the shorter input. I must be missing something...

17.12. Ah I made a mistake. I need to check the std::string.find() function is passed the cursor location to ensure that i get the last digits as well. Otherwise I only get the first digit right. I got the solution correctly now. LL: Set up file input as a comand line argument. Recompiling in C++ is a pain otherwise. Also maybe I should look into setting up a Makefile? Perhaps for some other day.

19.12. Makefiles are quite a conundrum indeed. Especially when writing it for a windows build target. Windows does not know rm. And del does not understand filepaths with regular slashes requiring backslashes instead. Spent way too long trying to create a generic makefile. I just wrote a short one instead. Next time i can finally get back to actually coding.
