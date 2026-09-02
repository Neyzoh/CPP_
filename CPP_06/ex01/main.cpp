#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include <cstring>
#include <stdint.h>

int main()
{
    Data data;

    data.value = -42;
    std::strcpy(data.name, "");

    Data* original = &data;

    std::cout << "Original address: "<< original << std::endl;
    std::cout << "Original data: " << data.value << ", "<< data.name << std::endl;

    uintptr_t raw = Serializer::serialize(original);

    std::cout << "Serialized value: "<< raw << std::endl;

    Data* recovered = Serializer::deserialize(raw);

    std::cout << "Recovered address: "<< recovered << std::endl;
    std::cout << "Recovered data: "<< recovered->value << ", " << recovered->name << std::endl;

    if (recovered == original)
        std::cout << "SUCCESS"<< std::endl;
    else
        std::cout << "FAILURE"<< std::endl;
    return 0;
}