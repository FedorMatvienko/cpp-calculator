#include "calculator.h"
#include <iostream>
#include <string>
#include <cmath>
// глобальная переменная для хранения считанного результата
std::string data;

bool ReadNumber(Number& result)
{
    // переменная указатель для записи символа
    char* end = nullptr;
    // считывание результата
    std::cin >> data;

    // проверка, что входные данные являются числом
    std::strtod(data.c_str(), &end);
    if (*end != '\0')
    {
        return false;
    }
    // если данные являются числом, то в переменную result записываем число
    result = std::stod(data.c_str());
    return true;
}
bool RunCalculatorCycle()
{
    // переменная для хранения результата
    Number result = 0.0;
    // переменная для хранения промежуточного значения
    Number value = 0.0;
    // переменная для сохранения результата в отдельной ячейке памяти
    Number result_memory = 0.0;

    /*
        Дмитрий Федоров:
        "Чтобы не заморачиваться с обилием булевских флагов,
        я бы проверял просто чаровские символы,
        это сократит код и упростит его поддержку" 

        Можно пожалуйста поподробнее про данное предположения,
        не могу понять, что имеется ввиду. Дело в том, что я считываю поэлементно.
        Я не могу знать наперед будет дальше значение или нет, а предыдущую операцию
        надо как-то сохранить.
    */
    // флаг знака плюс
    bool plus = false;
    // флаг знака минус
    bool minus = false;
    // флаг знака деления
    bool dev = false;
    // флаг знака возведения в степень
    bool deg = false;
    // флаг знака умножения
    bool mult = false;
    // флага знака установки значения
    bool setup = false;
    // флаг первого считывания значения
    bool first = true;
    // флаг ошибки
    bool error = true;
    // флаг того, что в памяти сохранен результат
    bool memory = false;
    
    // бесконечный цикл с первым действием
    do
    {
        // чтение данных из потока и проверка на тип данных
        if ( ReadNumber(value) )
        {
            // если первый вход в строку, то первое число сохраняем
            if (first)
            {
                result = value;
                first = false;
            }
            error = false;
            continue;
        }
        
        if (error)
        {
            std::cerr << "Error: Numeric operand expected" << std::endl;
            return false;
        }
        else if (plus)
        {
            result += value;
            plus = false;
        }
        else if (mult)
        {
            result *= value;
            mult = false;
        }
        else if (minus)
        {
            result -= value;
            minus = false;
        }
        else if (dev)
        {
            result /= value;
            dev = false;
        }
        else if (deg)
        {
            result = std::pow(result,value);
            deg = false;
        }
        else if (setup)
        {
            result = value;
            setup = false;
        }
        
        error = true;
        if (data == ":")
        {
            setup = true;
        }
        else if (data == "+")
        {
            plus = true;
        }
        else if (data == "-")
        {
            minus = true;
        }
        else if (data == "/")
        {
            dev = true;
        }
        else if (data == "*")
        {
            mult = true;
        }
        else if (data == "**")
        {
            deg = true;
        }
        else if (data == "=")
        {
            std::cout << result << std::endl;
            error = false;
        }
        else if (data == "c")
        {
            result = 0.0;
            error = false;
        }
        else if (data == "s")
        {
            result_memory = result;
            error = false;
            memory = true;
        }
        else if (data == "l")
        {
            if (!memory)
            {
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
            result = result_memory;
            error = false;
        }
        else if (data != "q")
        {
            std::cerr << "Error: Unknown token " << data << std::endl;
            return false;
        }
    }
    while(data != "q");
    return true;
}