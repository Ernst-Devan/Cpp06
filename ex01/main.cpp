#include "Serializer.hpp"

void on_heap()
{

    std::cout << "---- ON HEAP ----" << std::endl;

    uintptr_t tmp;
    Data *list = new Data;

    list->one = 1;  
    list->two = "one";

    tmp = Serializer::serialize(list);
    list = Serializer::deserialize(tmp);


    std::cout << list->one << std::endl;
    std::cout << list->two << std::endl;

    delete list;

}

void on_stack()
{

    std::cout << "---- ON STACK ----" << std::endl;

    uintptr_t tmp;
    Data list;
    Data *end;

    list.one = 42;
    list.two = "Forty Two";

    tmp = Serializer::serialize(&list);
    end = Serializer::deserialize(tmp);

    std::cout << end->one << std::endl;
    std::cout << end->two << std::endl;
}

int main(void)
{
    on_heap();
    on_stack();
    return (0);
}
