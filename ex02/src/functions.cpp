#include "../inc/data.hpp"

Base*   generate(void)
{
    Base*   object = NULL;

    std::srand(std::time(0));
    int random = std::rand() % 3;

    if (random == 0)
        object = new A();
    else if (random == 1)
        object = new B();
    else if (random == 2)
        object = new C();
    return object;
}

void    identify(Base* p)
{

    if (dynamic_cast<A*>(p))
        std::cout << "Type: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type: C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void    identify(Base& p)
{
    try 
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type: A" << std::endl;
    }
    catch (const std::bad_cast&)
    {
        try
        {
            (void)dynamic_cast<B&>(p);
            std::cout << "Type: B" << std::endl;
        }
        catch (const std::bad_cast&)
        {
            try
            {
                (void)dynamic_cast<C&>(p);
                std::cout << "Type: C" << std::endl;
            }
            catch (const std::bad_cast&)
            {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}