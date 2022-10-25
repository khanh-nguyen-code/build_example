#include<iostream>
#include"loader.h"
#include"printer.h"

int main() {
    int value = loader::load();
    printer::print(value);
    return 0;
}