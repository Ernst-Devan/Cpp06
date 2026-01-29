#include "Serializer.hpp"
#include <stdint.h>

Serializer::Serializer() {};
Serializer::Serializer(Serializer const& s) {(void)s; return;};
Serializer& Serializer::operator=(Serializer const& s) {(void)s; return *this;};
Serializer::~Serializer() {};

uintptr_t  Serializer::serialize(Data* ptr)
{
    uintptr_t tmp = reinterpret_cast<uintptr_t>(ptr);
    return tmp;
}

Data*   Serializer::deserialize(uintptr_t raw)
{
    Data *tmp = reinterpret_cast<Data *>(raw);
    return tmp;
}
