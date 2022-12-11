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
    LinkStack<double> opnd;                         //������ջ
    char ch;                                        //��ʱ�ַ�
    double operand, first, second;                  //������
    cout << "�����׺���ʽ����'#'������";
    ch = GetChar();                                 //����һ���ַ�
    while (ch != '#')                               //��ǰ���ʽ��δ�������
    {
        if (isdigit(ch) || ch == '.') {             //chΪһ���������ĵ�һ������
            cin.putback(ch);                        //���ַ�ch�Ż�������
            cin >> operand;                         //���������
            opnd.Push(operand);                     //��������ջ
        }
        else if (!IsOperator(ch) || ch == '(' || ch == ')') {
                                                    //ch�Ȳ��ǲ��������ֲ��ǲ�����
            throw Error("���ʽ���зǷ����ţ�");
        }
        else {                                      //ch�ǲ�����
            if (opnd.Pop(second) == UNDER_FLOW)
                throw Error("ȱ�ٲ�������");
            if (opnd.Pop(first) == UNDER_FLOW)
                throw Error("ȱ�ٲ�������");
            opnd.Push(Operate(first, ch, second));  //����������ջ��
        }
        ch = GetChar();                             //�������ַ�
    }
    if (opnd.Pop(operand) == UNDER_FLOW)
        throw Error("ȱ�ٲ�������");
    if (!opnd.IsEmpty())
        throw Error("ȱ�ٲ�������");
    cout << "���ʽ���Ϊ��" << operand << endl;
}

#endif