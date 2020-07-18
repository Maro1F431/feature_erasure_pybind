PROJET CPPA
===========

HOW TO BUILD
************

```
mkdir build && build
conan remote add lrde-public
conan install .. -s compiler.cppstd=20 --build=missing
cmake ..
make
```

HOW TO RUN TESTS
****************

Once build is done :

```
make check
```
