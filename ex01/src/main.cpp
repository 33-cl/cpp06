#include "../inc/Serializer.hpp"
#include <iostream>

int main() {
    Data data = {42};
    uintptr_t raw = Serializer::serialize(&data);
    Data* deserialized = Serializer::deserialize(raw);

    if (deserialized == &data)
        std::cout << "Serialization and deserialization successful." << std::endl;
    else
        std::cout << "Test failed." << std::endl;

    return 0;
}
