#include "../inc/ScalarConverter.hpp"
#include <cmath>


int main(int argc, char **argv)
{
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
}