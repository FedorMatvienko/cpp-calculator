#pragma once

#include "calculator.h"

#include <QMainWindow>
#include <QString>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_1_clicked();

    void on_pb_memory_store_clicked();

    void on_pb_point_clicked();

    void on_pb_2_clicked();

    void on_pb_3_clicked();

    void on_pb_4_clicked();

    void on_pb_5_clicked();

    void on_pb_6_clicked();

    void on_pb_7_clicked();

    void on_pb_8_clicked();

    void on_pb_9_clicked();

    void on_pb_clear_clicked();

    void on_pb_0_clicked();

    void on_pb_sign_change_clicked();

    void on_pb_delete_clicked();

    void on_pb_addition_clicked();

    void on_pb_subtraction_clicked();

    void on_pb_multiplication_clicked();

    void on_pb_division_clicked();

    void on_pb_power_clicked();

    void on_pb_equal_sign_clicked();

    void on_pb_memory_recall_clicked();

    void on_pb_memory_clear_clicked();

private:
    Ui::MainWindow* ui;
    Operations current_operation_{NO_OPERATION};
    QString input_number_;
    Calculator calculator_;
    double active_number_{};
    double memory_cell_{};
    bool memory_saved_{};
    bool point_{};
    void addInputCharacter_(QChar);
    QString showFormula_();
};
