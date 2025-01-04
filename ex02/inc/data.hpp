#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <typeinfo>

# include "../inc/A.hpp"
# include "../inc/B.hpp"
# include "../inc/C.hpp"

Base*   generate(void);
void    identify(Base *p);
void    identify(Base &p);

#endif