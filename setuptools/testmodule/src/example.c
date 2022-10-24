#include"example.h"
#include<string.h>
#include<stdlib.h>

int c_int(int int_in) {
    return int_in;
}

char* c_str(char* str_in) {
    // copy to str_out
    int len = strlen(str_in);
    char* str_out = (char*) malloc((1 + len) * sizeof(char));
    memcpy(str_out, str_in, len);
    str_out[len] = '\0';
    return str_out;
}

void c_ptr(uint64_t h, uint64_t w, double* arr_in, double* arr_out) {
    // copy to arr_out
    for (uint64_t i_h=0; i_h<h; i_h++) {
        for (uint64_t i_w=0; i_w<w; i_w++) {
            uint64_t i = i_h * w + i_w;
            arr_out[i] = arr_in[i];
        }
    }
    // modify arr_in
    uint64_t len = h * w;
    for (uint64_t i_h=0; i_h<h; i_h++) {
        for (uint64_t i_w=0; i_w<w; i_w++) {
            uint64_t i = i_h * w + i_w;
            arr_in[i] = arr_out[len-i-1];
        }
    }
    return;
}