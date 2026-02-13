#include "Base.hpp"
#include <cstdlib>
#include <bits/stdc++.h>
#include <iostream>
#include <bits/stdc++.h>
#include <sys/time.h>



Base * generate(void)
{
    static bool seed = false;
    if (!seed) {
        srand(time(NULL));
        seed = true;
    }
    
    int random = rand() % 3;
    if (random == 0)
        return new A;
    else if (random == 1)
        return new B;
    else 
        return new C;
}

void identify(Base* p)
{
    if (dynamic_cast <A*> (p))
        std::cout << "Object pointed to is of type A" << std::endl;
    else if (dynamic_cast <B*> (p))
        std::cout << "Object pointed to is of type B" << std::endl;
    else if (dynamic_cast <C*> (p))
        std::cout << "Object pointed to is of type C" << std::endl;
    else 
        std::cout << "Object pointed to is of unknown type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast <A&> (p);
        std::cout << "Object referenced to is of type A" << std::endl;
    }
    catch (std::bad_cast)
    {
        try
        {
            (void)dynamic_cast <B&> (p);
            std::cout << "Object referenced to is of type B" << std::endl;
        }
        catch (std::bad_cast)
        {
            try
            {
                (void)dynamic_cast <C&> (p);
                std::cout << "Object referenced to is of type C" << std::endl;
            }
            catch (std::bad_cast)
            {
                std::cout << "Object referenced to is of unknown type" << std::endl;
            }
        }
    }
}
