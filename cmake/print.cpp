#include<iostream>
#include"loader.h"

int main() {
    auto content = loader::load();
    std::cout << content << std::endl;
    return 0;
}