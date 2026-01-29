#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
    int         one;
    std::string two;
};

class Serializer
{
    private:
        Serializer();
        Serializer(Serializer const& s);
        Serializer& operator=(Serializer const& s);
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data*    deserialize(uintptr_t raw);

};

#endif
