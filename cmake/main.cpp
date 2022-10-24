#include<iostream>
#include"loader/loader.h"

int main() {
    auto content = loader::load();
    std::cout << "hello: " << content << std::endl;
    return 0;
}