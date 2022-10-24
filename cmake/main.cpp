#include<iostream>
#include"loader/loader.h"
#include"printer/printer.h"

int main() {
    int content = loader::load();
    printer::print(content);
    return 0;
}