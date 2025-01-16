#include "../inc/ScalarConverter.hpp"
#include "../inc/utils.hpp"

#include <cstdlib>
#include <limits>

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter's default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    std::cout << "ScalarConverter's copy constructor called" << std::endl;
    *this = other;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter's destructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    std::cout << "ScalarConverter's copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

void    ScalarConverter::convert(std::string var_content)
{
    if (specific_case(var_content))
        return;

    double  result_double = strtod(var_content.c_str(), NULL);
    float   result_float  = static_cast<float>(result_double);
    int     result_int    = static_cast<int>(result_double);

    int type = guess_type(var_content);
    if (type == OTHER)
        return;

    if (var_content.length() == 1 && !isdigit(var_content[0]))
    {
        type = CHAR;
        result_int = static_cast<char>(var_content[0]);
    }

    // CHAR
    print_char(result_int);
 
    // INT
    std::cout << "int: " << result_int << std::endl;
 
    // FLOAT
    std::cout << "float: ";
    if (result_double > std::numeric_limits<float>::max())
        std::cout << "inff";
    else if (result_double < -std::numeric_limits<float>::max())
        std::cout << "-inff";
    else if (type == CHAR || type == INT)
        std::cout << result_float << ".0f";
    else
    {
        std::cout << var_content;
        if (type == DOUBLE)
            std::cout << "f";
    }
    std::cout << std::endl;

    // DOUBLE
    std::cout << "double: ";
    if (result_double > std::numeric_limits<double>::max())
        std::cout << "inf";
    else if (result_double < -std::numeric_limits<double>::max())
        std::cout << "-inf";
    else if (type == CHAR || type == INT)
        std::cout << result_double << ".0";
    else
    {
        for (size_t i = 0; i < var_content.length() - (type == FLOAT); i++)
            std::cout << var_content[i];
    }
    std::cout << std::endl;
}
