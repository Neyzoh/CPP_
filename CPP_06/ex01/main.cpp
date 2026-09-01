#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include <cstring>
#include <cstddef>

int main() 
{
    Data data;
    data.value = 42;
    data.f = 3.14f;
    std::memset(data.name, 0, sizeof(data.name));
    std::strcpy(data.name, "test");

    std::cout << "Original address: " << &data << std::endl;
    std::cout << "data.value = " << data.value << ", data.f = " << data.f
              << ", data.name = " << data.name << std::endl;

    std::size_t raw = Serializer::serialize(&data);
    std::cout << "Serialized (std::size_t): " << raw << std::endl;

    Data* recovered = Serializer::deserialize(raw);
    std::cout << "Deserialized address: " << recovered << std::endl;
    std::cout << "recovered->value = " << recovered->value
              << ", recovered->f = " << recovered->f
              << ", recovered->name = " << recovered->name << std::endl;

    if (recovered == &data) 
        std::cout << "SUCCESS: deserialized pointer equals original pointer." << std::endl;
    else 
        std::cout << "FAILURE: deserialized pointer differs from original pointer." << std::endl;
    return 0;
}