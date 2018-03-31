#include "expression.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

void Expression::input_exp(const string& exp) {
    if (exp[0] != '#')
        throw invalid_argument("Expression should be start with '#'");
    m_operators.push('#');
    m_numbers.push(0);
    m_exp = exp;
    read();
}

void Expression::read() {
    m_point = 1;
    double value;
    char symbol;
    while (m_point < (int)m_exp.size()) {
        if ((value = read_value()) != -1) {
            m_numbers.push(value);
        } else if ((value = read_trig()) != -2) {
            m_numbers.push(value);
        } else if ((symbol = read_operator()) != -1) {
            put_operator(symbol);
        } else {
            break;
        }
    }
}

double Expression::read_value() {
    if (m_exp[m_point] == '-') {
        m_point++;
        put_operator('+');
        m_numbers.push((-1) * read_value());
        return -1;
    }
    if (m_exp[m_point] < '0' || m_exp[m_point] > '9')
        return -1;
    char val[16];
    char get;
    int i;
    for (i = 0; i < 16 && m_point < (int)m_exp.size(); i++) {
        get = m_exp[m_point];
        if ((get >= '0' && get <= '9') || get == '.') {
            val[i] = get;
            m_point++;
        }
        else
            break;
    }
    val[i] = '\0';
    return atof(val);
}

char Expression::read_operator() {
    if (m_point >= (int) m_exp.size() - 1)
        return -1;
    else if (m_exp[m_point] >= '0' && m_exp[m_point] <= '9') // not an operator
        return -1;
    return m_exp[m_point++];
}

double Expression::read_trig() {
    char trig_type = m_exp[m_point];
    if (trig_type != 'c' && trig_type != 's')
        return -2;
    m_point += 4;
    string new_exp("#");
    for (int i = 1; i != 0; m_point++) {
        if (m_point >= m_exp.length()) throw range_error("bad exp");
        if (m_exp[m_point] == '(') i++;
        else if (m_exp[m_point] == ')') i--;
        new_exp += m_exp[m_point];
    }
    Expression e;
    e.input_exp(new_exp);

    if (trig_type == 'c') {
        return cos(e.evalue());
    }
    else if (trig_type == 's')
        return sin(e.evalue());
    return -2;
}

void Expression::put_operator(char op) {
    if (getPrecedence(op) > getPrecedence(m_operators.get_top())) {
        double pre = m_numbers.get(), next;
        if ((next = read_value()) == -1) {
            m_numbers.push(op);
            return;
        }

        double result = simpleEvalue(pre, next, op);
        m_numbers.push(result);
    } else if (op == ')') {
        char temp_op;
        double pre, next;
        while ((temp_op = m_operators.get()) != '(') {
            next = m_numbers.get();
            pre = m_numbers.get();
            m_numbers.push(simpleEvalue(pre, next, temp_op));
        }
    } else {
        m_operators.push(op);
    }
}

double Expression::simpleEvalue(double a, double b, char op) {
    //cout << "get value " << a << " " << b << " " << op << endl;
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '/': return a / b;
        case '*': return a * b;
        case '^': return pow(a, b);
        case '%': return (int) a % (int) b;
    }
    return 0;
}

double Expression::evalue() {
    char op;
    double pre, next;
    while ((op = m_operators.get()) != '#') {
        next = m_numbers.get();
        pre = m_numbers.get();
        cout << "pre number: " << pre << endl;
        m_numbers.push(simpleEvalue(pre, next, op));
    }
    return m_numbers.get_top();
}

int Expression::getPrecedence(char c) {
    switch(c) {
        case '=':return 0;
        case '#':return 4;
        case '+': case '-': return 3;
        case '*': case '/': case '%': return 5;
        case '^': return 6;
    }
    return 0;
}
