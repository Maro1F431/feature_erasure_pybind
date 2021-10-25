PROJET CPPA
===========
The objective of this project is to use pybind and c++ to use feature erasure in python.

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
pip install pytest
pip install numpy
make test
```

And for verbose :

``` 
make CTEST_OUTPUT_ON_FAILURE=1 test
```
or
```
ctest --verbose
```
