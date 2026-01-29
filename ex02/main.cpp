#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <stdlib.h>

Base* generate(void)
{
    Base* tmp = NULL;
    int rdm = rand() % 3;
    
    if (rdm == 0)
    {
        tmp = new A;
        std::cout << "Create an A class" << std::endl;
    }
    if (rdm == 1)
    {
        tmp = new B;
        std::cout << "Create an B class" << std::endl;
    }
    if (rdm == 2)
    {
        tmp = new C;
        std::cout << "Create an C class" << std::endl;
    }
    return(tmp);
}

void identify(Base* p)
{
    std::cout << "Pointer:" << std::endl;
    if (A* a = dynamic_cast<A *>(p))
        std::cout << "Identify A class" << std::endl;
    if (B* b = dynamic_cast<B *>(p))
        std::cout << "Identify B class" << std::endl;
    if (C* c = dynamic_cast<C *>(p))
        std::cout << "Identify C Class" << std::endl;
}

void identify(Base& p)
{
    std::cout << "Reference:" << std::endl;
    try 
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "Identify A class" << std::endl;
        (void)a;
    } 
    catch (...) {}
    try
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "Identify B class" << std::endl;
        (void)b;
    } 
    catch (...) {}
    try
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "Identify C Class" << std::endl;
        (void)c;
    }
    catch (...) {}
}

int main(void)
{
    srand(time(0));

    identify(generate());
    std::cout << std::endl;
    identify(*generate());

    return (0);
}
