#ifndef POSTFIX_EXPRESSION_CALCULATOR_H
#define POSTFIX_EXPRESSION_CALCULATOR_H

#include "LinkStack.h"
bool IsOperator(char ch)
{
    if (ch == '#' || ch == '(' || ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == ')')
        return true;
    else
        return false;
};

void PostfixExpressionCalculation()
{
    LinkStack<double> opnd;
    char ch;
    double operand, first, second;
    cout << "输入后缀表达式，以'#'结束：";
    ch = GetChar();
}

#endif