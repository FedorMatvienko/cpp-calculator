#pragma once
#include <cmath>
#include <QString>
enum Operations {
    NO_OPERATION = 0,   // операция не задана
    ADDITION,           // плюс
    SUBTRACTION,        // минус
    MULTIPLICATION,     // умножить
    DIVISION,           // поделить
    POWER               // возведение в степень
};
class Calculator {
public:
    // сложение
    double addition(double);
    // вычитание
    double subtraction(double active_number);
    // умножение
    double multiplication(double active_number);
    // деление
    double division(double active_number);
    // возведение в степень
    double power(double active_number);
    // сохранение значения для дальнейшей операции
    void setNumber(double);
    // получение сохранённого значения для дальнейшей операции
    double getNumber();
private:
    // ячейка для хранения значения, для формулы
    double number_{};
};
