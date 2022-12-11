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

double Operate(double first,char ch, double second)
{
    if (ch == '+')return first + second;
    if (ch == '-')return first - second;
    if (ch == '*')return first * second;
    if (ch == '/')return first / second;
    else return 0;
}

void PostfixExpressionCalculation()
{
    LinkStack<double> opnd;                         //操作数栈
    char ch;                                        //临时字符
    double operand, first, second;                  //操作数
    cout << "输入后缀表达式，以'#'结束：";
    ch = GetChar();                                 //读入一个字符
    while (ch != '#')                               //当前表达式还未输入结束
    {
        if (isdigit(ch) || ch == '.') {             //ch为一个操作数的第一个数字
            cin.putback(ch);                        //将字符ch放回输入流
            cin >> operand;                         //读入操作数
            opnd.Push(operand);                     //操作数入栈
        }
        else if (!IsOperator(ch) || ch == '(' || ch == ')') {
                                                    //ch既不是操作数，又不是操作符
            throw Error("表达式中有非法符号！");
        }
        else {                                      //ch是操作符
            if (opnd.Pop(second) == UNDER_FLOW)
                throw Error("缺少操作数！");
            if (opnd.Pop(first) == UNDER_FLOW)
                throw Error("缺少操作数！");
            opnd.Push(Operate(first, ch, second));  //计算结果放入栈中
        }
        ch = GetChar();                             //读入新字符
    }
    if (opnd.Pop(operand) == UNDER_FLOW)
        throw Error("缺少操作数！");
    if (!opnd.IsEmpty())
        throw Error("缺少操作符！");
    cout << "表达式结果为：" << operand << endl;
}

#endif