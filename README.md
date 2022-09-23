## CMake

### commands :

```
cmake . // Specifies path to CMakeLists.txt, assumes build is current folder
cmake -S . // same as cmake .
cmake -S . -B build // CMakeLists.txt is in current folder, build is in build/ folder
```

Two ways of compiling the files in make after building to `build` folder : 

1 :cd 
```
cd build/
make
```

2 :
```
make -C build/
```

## Meaning of code in `CMakeLists.txt`

* `project(rens)` -> defines the project name
* `add_executable(rens main.cpp a.cpp b.cpp)` -> Add an executable for all the files mentioned in the list
* `add_subdirectory(folder_name)` -> Adds a subdirectory to the build. The folder_name specifies the directory in which the source CMakeLists.txt and code files are located.

## Without cmake, commands would look like:

* `g++ main.cpp adder/adder.cpp`

Or,

* `g++ -c Adder/adder.cpp ; g++ -c Subtracter/subtracter.cpp ; g++ -c main.cpp ; g++ *.o -o rens`

## Notes:

* Let's say the project structure is so:

```
.
├── Adder
│   ├── adder.cpp
│   ├── adder.h
│   └── CMakeLists.txt
├── CMakeLists.txt
├── main.cpp
└── Subtracter
    ├── CMakeLists.txt
    ├── subtracter.cpp
    └── subtracter.h
```

    * cmake is to be executed only if we add more files.
    * If we change `subtracter.cpp` and execute make, only that subdirectory will get built once again.
    * It's efficient in that manner.

