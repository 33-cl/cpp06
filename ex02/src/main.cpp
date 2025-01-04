#include "../inc/data.hpp"

int main()
{
    Base*  object1 = generate();

    Base&   obj_ref = *object1;

    identify(object1);
    identify(obj_ref);
}