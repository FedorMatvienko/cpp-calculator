#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
// метод отображение формулы
QString MainWindow::showFormula_() {
    QString output_number;
    output_number.setNum(calculator_.getNumber(),'g', 10);
    output_number.append(" ");
    switch (current_operation_) {
    case ADDITION:
        output_number.append("+");
        break;
    case SUBTRACTION:
        output_number.append("−");
        break;
    case MULTIPLICATION:
        output_number.append("×");
        break;
    case DIVISION:
        output_number.append("÷");
        break;
    case POWER:
        output_number.append("^");
        break;
    case NO_OPERATION:
    default:
        break;
    }
    ui->l_formula->setText(output_number);
    return output_number;
}
// метод добавление символа
void MainWindow::addInputCharacter_(QChar c) {
    qDebug() << "input_number_: " << input_number_;
    // не даём ввести точку, когда точка уже стоит
    if (c == '.' && point_){
        return;
    }
    // не даём ввести ноль, так как значение нулевое
    if (!active_number_ && c == '0') {
        return;
    }
    // затираем ноль перед записью нового символа
    if (input_number_ == "0" && c != '.') {
        input_number_.clear();
    }
    input_number_.append(c);
    active_number_ = input_number_.toDouble();
    ui->l_result->setText(input_number_);
}
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    input_number_ = "0";
    ui->l_result->setText("0");
    ui->l_memory->setText("");
    ui->l_formula->setText("");
}

MainWindow::~MainWindow() {
    delete ui;
}

// сохранение результата
void MainWindow::on_pb_memory_store_clicked()
{
    ui->l_memory->setText("M");
    memory_cell_ = active_number_;
    memory_saved_ = true;
}

// нажатие на точку
void MainWindow::on_pb_point_clicked()
{
    addInputCharacter_(QChar('.'));
    point_ = true;
}
// нажатие на цифру 0
void MainWindow::on_pb_0_clicked()
{
    addInputCharacter_(QChar('0'));
}
// нажатие на цифру 1
void MainWindow::on_pb_1_clicked()
{
    addInputCharacter_(QChar('1'));
}
// нажатие на цифру 2
void MainWindow::on_pb_2_clicked()
{
    addInputCharacter_(QChar('2'));
}
// нажатие на цифру 3
void MainWindow::on_pb_3_clicked()
{
    addInputCharacter_(QChar('3'));
}

// нажатие на цифру 4
void MainWindow::on_pb_4_clicked()
{
    addInputCharacter_(QChar('4'));
}

// нажатие на цифру 5
void MainWindow::on_pb_5_clicked()
{
    addInputCharacter_(QChar('5'));
}

// нажатие на цифру 6
void MainWindow::on_pb_6_clicked()
{
    addInputCharacter_(QChar('6'));
}

// нажатие на цифру 7
void MainWindow::on_pb_7_clicked()
{
    addInputCharacter_(QChar('7'));
}

// нажатие на цифру 8
void MainWindow::on_pb_8_clicked()
{
    addInputCharacter_(QChar('8'));
}

// нажатие на цифру 9
void MainWindow::on_pb_9_clicked()
{
    addInputCharacter_(QChar('9'));
}

// отчистка значения
void MainWindow::on_pb_clear_clicked()
{
    input_number_.setNum(0);
    active_number_ = input_number_.toDouble();
    current_operation_ = NO_OPERATION;
    ui->l_result->setText(input_number_);
    ui->l_formula->clear();
    point_ = false;
}

// Метод для изменения знака числа
void MainWindow::on_pb_sign_change_clicked()
{
    active_number_ = -active_number_;
    input_number_.setNum(active_number_,'g', 10);
    ui->l_result->setText(input_number_);
}

// удаление символа с конца
void MainWindow::on_pb_delete_clicked()
{
    if (!active_number_) {
        return;
    }
    if (!input_number_.isEmpty()) {
        QChar lastChar = input_number_.at(input_number_.length() - 1);

        if (lastChar == '.') {
            point_ = false;
        }

        // Удаляем символ
        input_number_.chop(1);
        active_number_ = input_number_.toDouble();
        // если число нулевое, то востанавливаем текст ввиде нуля
        if (!active_number_) {
            input_number_.setNum(0);
        }
        ui->l_result->setText(input_number_);
    }
}

// нажатие на символ сложения
void MainWindow::on_pb_addition_clicked()
{
    if (current_operation_ == NO_OPERATION) {
        calculator_.setNumber(active_number_);
    }
    current_operation_ = ADDITION;
    showFormula_();
    input_number_.clear();
}

// нажатие на символ вычитания
void MainWindow::on_pb_subtraction_clicked()
{
    if (current_operation_ == NO_OPERATION) {
        calculator_.setNumber(active_number_);
    }
    current_operation_ = SUBTRACTION;
    showFormula_();
    input_number_.clear();
}

// нажатие на символ умножения
void MainWindow::on_pb_multiplication_clicked()
{
    if (current_operation_ == NO_OPERATION) {
        calculator_.setNumber(active_number_);
    }
    current_operation_ = MULTIPLICATION;
    showFormula_();
    input_number_.clear();
}

// нажатие на символ деления
void MainWindow::on_pb_division_clicked()
{
    if (current_operation_ == NO_OPERATION) {
        calculator_.setNumber(active_number_);
    }
    current_operation_ = DIVISION;
    showFormula_();
    input_number_.clear();
}

// нажатие на символ возведения в степень
void MainWindow::on_pb_power_clicked()
{
    if (current_operation_ == NO_OPERATION) {
        calculator_.setNumber(active_number_);
    }
    current_operation_ = POWER;
    showFormula_();
    input_number_.clear();
}

// вычисление результата, а так же его вывод
void MainWindow::on_pb_equal_sign_clicked()
{
    if (current_operation_ == NO_OPERATION) {
        return;
    }
    // получаем первую часть формулы
    QString formula = showFormula_();
    // дополняем формулу второй частью, состоящую из
    // значения и символа равенства
    formula.append(" ");
    formula.append(QString::number(active_number_));
    formula.append(" ");
    formula.append("=");
    // отображение формулы
    ui->l_formula->setText(formula);
    // вычисляем новое значение
    switch (current_operation_) {
    case ADDITION:
        active_number_ = calculator_.addition(active_number_);
        break;
    case SUBTRACTION:
        active_number_ = calculator_.subtraction(active_number_);
        break;
    case MULTIPLICATION:
        active_number_ = calculator_.multiplication(active_number_);
        break;
    case DIVISION:
        active_number_ = calculator_.division(active_number_);
        break;
    case POWER:
        active_number_ = calculator_.power(active_number_);
        break;
    case NO_OPERATION:
    default:
        break;
    }
    // после вычисления скидываем операцию, устанавливаем текст и
    // скидываем строку с данными
    current_operation_ = NO_OPERATION;
    input_number_.setNum(active_number_,'g', 10);
    ui->l_result->setText(input_number_);
    input_number_.clear();
}

// загрузка значения из памяти
void MainWindow::on_pb_memory_recall_clicked()
{
    if (memory_saved_) {
        active_number_ = memory_cell_;
        input_number_.setNum(active_number_,'g', 10);
        ui->l_result->setText(input_number_);
    }
}

// отчистка памяти
void MainWindow::on_pb_memory_clear_clicked()
{
    memory_saved_ = false;
    ui->l_memory->clear();
    memory_cell_ = 0.0;
}

