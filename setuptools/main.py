import numpy as np

from testmodule import  c_int_py, c_str_py, c_arr_py, py_int, py_str, py_arr

if __name__ == "__main__":
    i1 = 1234
    s1 = "1234"
    a1 = np.array([
        [1, 2],
        [3, 4],
    ], dtype=np.double)
    
    # c version
    print("c version")
    i2 = c_int_py(i1)
    s2 = c_str_py(s1)
    a2 = c_arr_py(a1)

    print(i1, i2)
    print(s1, s2)
    print(a1.flatten(), a2.flatten())
    
    # py version
    print("py version")
    i2 = py_int(i1)
    s2 = py_str(s1)
    a2 = py_arr(a1)

    print(i1, i2)
    print(s1, s2)
    print(a1.flatten(), a2.flatten())
