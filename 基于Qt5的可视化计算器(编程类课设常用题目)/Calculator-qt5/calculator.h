#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include "expression.h"

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private slots:

    void on_number7_clicked();
    void on_number8_clicked();
    void on_number9_clicked();
    void on_number4_clicked();
    void on_number5_clicked();
    void on_number6_clicked();
    void on_number1_clicked();
    void on_number2_clicked();
    void on_number3_clicked();
    void on_number0_clicked();
    void on_buttonDot_clicked();
    void on_leftParenthesis_clicked();
    void on_rightParenthesis_clicked();
    void on_plusButton_clicked();
    void on_minusButton_clicked();
    void on_multiButton_clicked();
    void on_divisionButton_clicked();
    void on_delButton_clicked();

    void on_equalButton_clicked();

    void on_remainderButton_clicked();

    void on_clearButton_clicked();

    void on_cosButton_clicked();

    void on_sinButton_clicked();

private:
    void addElement(const QString& t);

    Expression *cal;

    Ui::Calculator *ui;
    QString expr;
};

#endif // CALCULATOR_H
