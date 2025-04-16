#include "calculator.h"

double Calculator::addition(double active_number) {
    return (number_ + active_number);
}

double Calculator::subtraction(double active_number) {
    return (number_ - active_number);
}

double Calculator::multiplication(double active_number) {
    return (number_ * active_number);
}

double Calculator::division(double active_number) {
    return (number_ / active_number);
}

double Calculator::power(double active_number) {
    return std::pow(number_,active_number);
}

void Calculator::setNumber(double active_number) {
    number_ = active_number;
}

double Calculator::getNumber() {
    return number_;
}
