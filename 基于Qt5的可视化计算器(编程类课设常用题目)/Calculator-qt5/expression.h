#ifndef __MYEXPRESSION__
#define __MYEXPRESSION__

#include "stack.h"
#include <iostream>
using namespace std;

class Expression {
private:
    string m_exp;
    int m_point;
    MyStack<char> m_operators;
    MyStack<double> m_numbers;

public:
    Expression() : m_exp(""){}
    Expression(const string& exp) : m_exp(exp) {
        if (exp[0] != '#')
            throw invalid_argument("Expression should be start with '#'");
        m_operators.push('#');
        m_exp = exp;
        read();
    }
    double evalue();
    void input_exp(const string& exp);
private:
    void read();
    char read_operator();
    double read_value();
    double read_trig();
    void put_operator(char);
    int getPrecedence(char);
    double simpleEvalue(double, double, char);
};

#endif
