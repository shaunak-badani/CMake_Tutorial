#include <iostream>
#include "Adder/adder.h"
#include "Subtracter/subtracter.h"

int main() {
    std::cout << "Hello from CMAKE ! " << std::endl;
    std::cout << add(43.1, 56.54) << std::endl;
    std::cout << subtract(43.1, 56.54) << std::endl;
}