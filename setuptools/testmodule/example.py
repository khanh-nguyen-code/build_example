import numpy as np

def py_int(int_in: int) -> int:
    return int_in

def py_str(str_in: str) -> str:
    return str_in

def py_arr(arr_in: np.ndarray) -> np.ndarray:
    return arr_in[::-1]