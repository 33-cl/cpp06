#include "../inc/Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Serializer's default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
    std::cout << "Serializer's copy constructor called" << std::endl;
    *this = other;
}

Serializer::~Serializer()
{
    std::cout << "Serializer's destructor called" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    std::cout << "Serializer's copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

uintptr_t   Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data        *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}