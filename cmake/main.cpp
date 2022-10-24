#include<iostream>
#include"loader/loader.h"
#include"printer/printer.h"
#include"multiplier/multiplier.h"

int main() {
    int value = loader::load();
    printer::print(multiplier::mul(3, value));
    return 0;
}