#include <iostream>
#include <sstream>
#include <string>

typedef enum e_type
{
    OTHER,
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
} t_type;

int ft_stoi(const std::string& str) 
{
    std::stringstream ss(str);
    int value;

    ss >> value;
    return value;
}

bool    specific_case(const std::string& str)
{
    if (str == "nan" || str == "nanf")
    {
        std::cout << "char: impossible" << std::endl
                  << "int: impossible" << std::endl
                  << "float: nanf" << std::endl
                  << "double: nan" << std::endl;
        return true;
    }
    if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
    {
        std::cout << "char: impossible" << std::endl
                  << "int: impossible" << std::endl
                  << "float: +inff" << std::endl
                  << "double: +inf" << std::endl;
        return true;
    }
    if (str == "-inf" || str == "-inff")
    {
        std::cout << "char: impossible" << std::endl
                  << "int: impossible" << std::endl
                  << "float: -inff" << std::endl
                  << "double: -inf" << std::endl;
        return true;
    }
    return false;
}

int    guess_type(const std::string& str)
{
    // CHAR
    if (str.length() == 1 && !isdigit(str[0]))
        return CHAR;

    // INT
    bool    is_int = true;
    if (!isdigit(str[0]) && str[0] != '-' && str[0] != '+')
    {
        is_int = false;
    }
    for (size_t i = 1; i < str.length() && is_int; i++)
    {
        if (!isdigit(str[i]))
            is_int = false;
    }
    if (is_int)
        return INT;


    std::stringstream ss(str);
    double tmp;
    ss >> tmp;

    // DOUBLE
    if (ss.fail())
        return OTHER;
    if (ss.eof())
        return DOUBLE;

    // FLOAT
    std::string remaining;
    std::getline(ss, remaining);
    if (remaining == "f")
        return FLOAT;
    
    return OTHER;
}

void    print_char(char c)
{
    std::cout << "char: ";
    if (c < 32 || c > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;
}