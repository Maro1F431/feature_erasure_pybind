import os
import sys
import inspect

current_dir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parent_dir = os.path.dirname(current_dir)
sys.path.insert(0, parent_dir)

import build.pylene as pylene # He will find the library alone if it has been created
import numpy as np

def conversion_assertion(to_convert):
    assert np.array_equal(to_convert, pylene.converting_twice(to_convert))

# Tests must begin with test_ to be runned by pytest
def test_empty_one_dim():
    conversion_assertion(np.array([1, 2, 3, 4, 5]))

def test_two_dim_square():
    conversion_assertion(np.array([[1, 2], [3, 4]]))

def test_two_dim():
    conversion_assertion(np.array([[1, 2], [3, 4], [5, 6]]))

def test_three_dim():
    conversion_assertion(np.array([[[1, 2, 3], [4, 5, 6]], [[7, 8, 9], [10, 11, 12]]]))

def test_type_erasure():
    print(pylene.test())

