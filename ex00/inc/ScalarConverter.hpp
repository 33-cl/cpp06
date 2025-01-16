#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <climits>
# include <cfloat>

typedef enum e_type
{
    OTHER,
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
} t_type;

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ~ScalarConverter();
        ScalarConverter&  operator=(const ScalarConverter& other);

    public:
        static void    convert(std::string var_content);
};

#endif