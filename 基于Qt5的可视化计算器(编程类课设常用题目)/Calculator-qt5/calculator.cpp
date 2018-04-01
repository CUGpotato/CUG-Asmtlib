#include "calculator.h"
#include "ui_calculator.h"
#include "expression.h"
#include <iostream>
#include <QPropertyAnimation>
using namespace std;

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    expr = "";
    cal = new Expression();
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}

Calculator::~Calculator()
{
    delete cal;
    delete ui;
}

void Calculator::addElement(const QString &t) {
    expr += t;
    ui->textEdit->setPlainText(expr);
}

void Calculator::on_number7_clicked()
{
    addElement("7");
}

void Calculator::on_number8_clicked()
{
    addElement("8");
}

void Calculator::on_number9_clicked()
{
    addElement("9");
}

void Calculator::on_number4_clicked()
{
    addElement("4");
}

void Calculator::on_number5_clicked()
{
    addElement("5");
}

void Calculator::on_number6_clicked()
{
    addElement("6");
}

void Calculator::on_number1_clicked()
{
    addElement("1");
}

void Calculator::on_number2_clicked()
{
    addElement("2");
}

void Calculator::on_number3_clicked()
{
    addElement("3");
}

void Calculator::on_number0_clicked()
{
    addElement("0");
}

void Calculator::on_buttonDot_clicked()
{
    addElement(".");
}


void Calculator::on_leftParenthesis_clicked()
{
    addElement("(");
}

void Calculator::on_rightParenthesis_clicked()
{
    addElement(")");
}

void Calculator::on_plusButton_clicked()
{
    addElement("+");
}

void Calculator::on_minusButton_clicked()
{
    addElement("-");
}

void Calculator::on_multiButton_clicked()
{
    addElement("*");
}

void Calculator::on_divisionButton_clicked()
{
    addElement("/");
}

void Calculator::on_remainderButton_clicked()
{
    addElement("%");
}


void Calculator::on_delButton_clicked()
{
    int length = expr.length();
    if (length == 0)
        return;
    else if (length == 1)
        expr = "";
    else
        expr = expr.remove(length - 1, length - 1);
    ui->textEdit->setPlainText(expr);
}

void Calculator::on_equalButton_clicked()
{
    expr = "#" + expr;
    QByteArray ba = expr.toLatin1();
    string calculate_expr = ba.data();
    QString display;
    try {
        cal->input_exp(calculate_expr);
        double result = cal->evalue();
        display = QString("result: %1").arg(result);
    } catch (const range_error& e) {
        display = "An error occured: your expression is illegal.";
        delete cal;
        cal = new Expression();
    } catch (std::exception& e) {
        display = "Calculator crashed: you may have typed in an illegal expression";
    }

    ui->textEdit->setPlainText(display);
    expr = "";
}

void Calculator::on_clearButton_clicked()
{
    expr = "";
    ui->textEdit->setPlainText(expr);
}

void Calculator::on_cosButton_clicked()
{
    addElement("cos(");
}

void Calculator::on_sinButton_clicked()
{
    addElement("sin(");
}
