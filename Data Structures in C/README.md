# Data Structures
C++ provides a rich collection of data structures and algorithms via the STL. Since DSA is an important topic for many college level courses and interview programs, being a fun topic to learn in general. I decided to make this part of my `coding-cpp` repository a place to hold my personal files for the Data Structures written in C.


# Code Standards
* The `C99` standard is used and expected from other contributors who may wish to contribute.
* The `includes` follow a Include What You Use (IWYU) pattern.
* Each new data structure should be added as defined by the rules below.
* Any build system is recommended as this repository is mostly a collection of header files and source files, although examples and Makefiles to build them are provided in this repository.

# Directory Structure
```
.
├── DataStructures.md : Contains documentation information for each Data Structure added to this repo.
├── ErrorHandling.md  : Contains rules for updating include/err_handle.h and documentation information.
├── Examples          : Contains examples and Makefiles to build them.
├── include           : Contains the header files of every data structure, utils and err_handle.
├── README.md         : This document.
├── utils             : Contains utility functions and error handling.
└── vector            : Contains the source files for the functionality of std::vector to C.
```

# Rules to add new data structures (for contributors and my own reference)
Say that you want to add a data structure, `foo` to the repository. Here is how you would go about adding it:
1. First create a folder called `foo` and a file called `foo.c` to it this is the main source file.
2. Add a header file called `foo.h` to the `include` directory.
3. Make use of "include guards" i.e. `ifdef-define-endif` blocks for `foo.h` instead of pragma directives.
4. Add the declarations of structs, functions and macros you want the user to access to the `foo.h` file, helper functions shoule NOT be added here.
5. Include the `foo.h` file in `foo.c` via the following line. `#include "foo.h"`, DO NOT add any path information to the include file.
6. Any additional helper functions you would want to make use of can be declared and defined here. (e.g. `vmem_reallocation` in `vector.c`)
7. Add any extra functions which you think are important but not part of the core functionality of the data structure in the `utils.<c|h>` set of files (e.g. `print_vector`). Do not add extra files to this directory. Error handling is covered by the `err_handle.h` file in `include`.
8. Add another file `foo_example.c` to the Examples folder and the recipe to build it in the Makefile.
9. Update this README.md by adding your folder and a brief description of it to the "Directory Structure" heading of this file. (Steps below)
10. Update the [DataStructures.md](https://github.com/JaytidaA/coding-cpp/tree/main/Data%20Structures%20in%20C/DataStructures.md) file by adding a subsection of your recently added `foo` data structure, copy the formatting of `vector`

# Steps to update Directory Structure
Ensure that the `tree` command line utility is installed on your system.
```sh
cd "Data Structures in C"
tree -L 1
```
Copy the output to your clipboard and paste it in the README. DO NOT REMOVE THE DESCRIPTIONS PROVIDED BY OLDER CONTRIBUTORS.

# Instructions for contributors
1. Fork this repository and create your own branch named `feature/yourAwesomeFeature` from `main`
2. Commit changes to that branch and create a pull request.

# Note from Author (JaytidaA)
I do not know how large this project will end up becoming but I hope that via this repository, anyone can make use of these data structures on platforms such as Leetcode or HackerRank and not be restricted by the minimalist (?) nature of the C programming language.
