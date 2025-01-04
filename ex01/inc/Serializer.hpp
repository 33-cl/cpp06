#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

struct Data {
    int value;
};

class Serializer
{
    private:
        // Useless implementation of the coplien canonical form
        Serializer();
        Serializer(const Serializer& other);
        ~Serializer();
        Serializer&  operator=(const Serializer& other);

    public:
        static uintptr_t   serialize(Data* ptr);
        static Data        *deserialize(uintptr_t raw);
};

#endif