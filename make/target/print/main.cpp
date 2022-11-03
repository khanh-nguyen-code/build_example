#include<iostream>
#include"loader/loader.h"
#include"adder/adder.h"

int main() {
    std::cout << loader::load() << " " << adder::add(1, 2) << std::endl;
    return 0;
}