#cython: language_level=3
cimport libc.stdint as stdint

cdef extern from "example.h":
    int c_int(int int_in)
    char* c_str(char* str_in)
    void c_ptr(stdint.uint64_t h, stdint.uint64_t w, double* arr_in, double* arr_out)

cimport libc.stdlib as stdlib
cimport libc.string as string
import numpy as np

def c_int_py(int_in: int) -> int:
    return c_int(int_in)

def c_str_py(str_in: str, encoding: str="utf-8", errors: str="strict") -> str:
    in_bytes: bytes = str_in.encode(encoding=encoding, errors=errors)

    cdef char* c_str_in = <char*> stdlib.malloc(1 + <Py_ssize_t> len(in_bytes))
    cdef char* c_str_out

    string.strcpy(c_str_in, in_bytes)

    try:
        c_str_out = c_str(c_str_in)
        out_bytes: bytes = c_str_out[:] # copy
        return out_bytes.decode(encoding=encoding, errors=errors)
    finally:
        stdlib.free(c_str_in)
        stdlib.free(c_str_out)


def c_arr_py(arr_in: np.ndarray) -> np.ndarray:
    if len(arr_in.shape) != 2:
        raise Exception("shape")
    if arr_in.dtype != np.double:
        raise Exception("dtype")

    arr_out = np.empty_like(arr_in)

    cdef stdint.uint64_t h = arr_in.shape[0]
    cdef stdint.uint64_t w = arr_in.shape[1]
    cdef double[:, :] arr_in_buf = np.ascontiguousarray(arr_in)
    cdef double[:, :] arr_out_buf = np.ascontiguousarray(arr_out)

    c_ptr(h, w, &arr_in_buf[0, 0], &arr_out_buf[0, 0])

    return arr_out
