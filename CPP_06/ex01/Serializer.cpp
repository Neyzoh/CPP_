#include "Serializer.hpp"

Serializer::Serializer() {}

std::size_t Serializer::serialize(Data* ptr) 
{
    return reinterpret_cast<std::size_t>(ptr);
}

Data* Serializer::deserialize(std::size_t raw) 
{
    return reinterpret_cast<Data*>(raw);
}