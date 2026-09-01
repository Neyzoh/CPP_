#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstddef>
#include "Data.hpp"

class Serializer 
{
private:
    Serializer();

public:
    static std::size_t serialize(Data* ptr);
    static Data* deserialize(std::size_t raw);
};

#endif 