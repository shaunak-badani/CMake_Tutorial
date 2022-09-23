## CMake 

### Adding Submodules : 

```
git submodule add https://github.com/glfw/glfw.git external/glfw
```

* The addition of a submodule tells git that I'll be using these files, but they are a part of another git repository, and hence link it to that repository instead of adding external files.

* Installed
`libxinerama-dev libxcursor libxi-dev` for glfw library

## Options

There are options in the glfw library for various stuff, such as building documentation.
`option(GLFW_BUILD_DOCS "Build the GLFW documentation" ON)`
It is on by default.
We can choose to turn that off, as so:
`cmake -DGLFW_BUILD_DOCS=OFF -S . -B build/`


## `target_include_directories`

If you want to include certain directories for header files, like so:

`#include <adder.h>`
But adder.h is located in `adder/` folder.
We use `target_include_directories` command : 

`target_include_directories()`

An alternative : 
`#include "Adder/adder.h"` without `target_include_directories`

## Cloning a repo with submodules : 

```
git clone <link-to-repo>
git submodule update --init --recursive
```