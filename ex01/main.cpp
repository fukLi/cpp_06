#include <iostream>
#include <string>
#include "Serializer.hpp"

int main()
{
    // Create a Data object
    Data data;
    data.id = 42;
    data.name = "Serialization Test";

    std::cout << "Original Data address: " << &data << std::endl;
    std::cout << "Original id: " << data.id << std::endl;
    std::cout << "Original name: " << data.name << std::endl;
    std::cout << std::endl;

    // Serialize
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value (uintptr_t): " << raw << std::endl;
    std::cout << std::endl;

    // Deserialize
    Data* restored = Serializer::deserialize(raw);

    std::cout << "Restored Data address: " << restored << std::endl;
    std::cout << "Restored id: " << restored->id << std::endl;
    std::cout << "Restored name: " << restored->name << std::endl;
    std::cout << std::endl;

    // Proof that pointers are identical
    if (restored == &data)
        std::cout << "Success: Pointers match." << std::endl;
    else
        std::cout << "Error: Pointers do not match." << std::endl;

    return 0;
}
