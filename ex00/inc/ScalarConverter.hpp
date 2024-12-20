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
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ~ScalarConverter();

        ScalarConverter&  operator=(const ScalarConverter& other);

        static void    convert(std::string var_content);
};

int     ft_stoi(const std::string& str);
bool    specific_case(const std::string& str);
int     guess_type(const std::string& str);
void    print_char(char c);

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


// void    ScalarConverter::convert(std::string var_content)
// {
//     int     result_int;

//     // DETECT TYPE CHAR
//     if (var_content.length() == 1 && !isdigit(var_content[0]))
//     {
//         std::cout << "char\n";
//         // CHAR
//         print_char(var_content[0]);

//         // INT
//         result_int = var_content[0];
//         std::cout << "int: " << result_int << std::endl;

//         // FLOAT
//         std::cout << "float: " << result_int << ".0f" << std::endl;

//         // DOUBLE
//         std::cout << "float: " << result_int << ".0" << std::endl;

//         return;
//     }

//     // DETECT TYPE INT
//     bool    is_int = true;
//     for (size_t i = 0; i < var_content.length(); i++)
//     {
//         if (!isdigit(var_content[i]))
//         {
//             is_int = false;
//             break ;
//         }
//     }
//     if (is_int)
//     {
//         std::cout << "int\n";
//         result_int = ft_stoi(var_content);

//         // CHAR
//         print_char(static_cast<char>(result_int));

//         // INT
//         std::cout << "int: " << result_int << std::endl;

//         // FLOAT
//         std::cout << "float: " << result_int << ".0f" << std::endl;

//         // DOUBLE
//         std::cout << "float: " << result_int << ".0" << std::endl;

//         return;
//     }
    
//     // DETECT TYPE FLOAT
//     if (guess_type(var_content) == FLOAT)
//     {
//         result_int = ft_stoi(var_content);

//         std::cout << "float\n";

//         // CHAR
//         print_char(static_cast<char>(result_int));

//         // INT
//         std::cout << "int: " << result_int << std::endl;


//         // FLOAT
//         std::cout << "float: " << var_content << std::endl;

//         // DOUBLE
//         for (size_t i = 0; i < var_content.length() - 1; i++)       
//         {
//             std::cout << var_content[i];
//         }
//         std::cout << std::endl;
        

//         return;
//     }

//     if (guess_type(var_content) == DOUBLE)
//     {
//         result_int = ft_stoi(var_content);
//         std::cout << "double\n";

//         // CHAR
//         print_char(static_cast<char>(result_int));

//         // INT
//         std::cout << "int: " << result_int << std::endl;

//         // FLOAT
//         std::cout << "float: " << var_content << "f" << std::endl;

//         // DOUBLE
//         std::cout << "float: " << var_content << std::endl;

//         return;
//     }


// }

void    ScalarConverter::convert(std::string var_content)
{
    if (specific_case(var_content))
        return;

    int result_int = ft_stoi(var_content);
    int type = guess_type(var_content);
    if (type == OTHER)
        return;

    if (var_content.length() == 1 && !isdigit(var_content[0]))
    {
        type = CHAR;
        result_int = static_cast<char>(var_content[0]);
    }

    // CHAR
    print_char(static_cast<char>(result_int));
 
    // INT
    std::cout << "int: " << result_int << std::endl;
 
    // FLOAT
    std::cout << "float: ";
    if (type == CHAR || type == INT)
        std::cout << result_int << ".0f";
    else
    {
        std::cout << var_content;
        if (type == DOUBLE)
            std::cout << "f";
    }
    std::cout << std::endl;

    // DOUBLE
    std::cout << "double: ";
    if (type == CHAR || type == INT)
        std::cout << result_int << ".0";
    else
    {
        for (size_t i = 0; i < var_content.length() - (type == FLOAT); i++)       
            std::cout << var_content[i];
    }
    std::cout << std::endl;
}

#endif