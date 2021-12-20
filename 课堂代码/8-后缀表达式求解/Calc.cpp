#include "Calc.h"

bool IsNumber(char c) {
    return c >= '0' && c <= '9';
}

int Caculate(int left, int right, char c) {
    int ret = 0;

    switch (c) {
        case '+':
            ret = left + right;
            break;
        case '-':
            ret = left - right;
            break;
        case '*':
            ret = left * right;
            break;
        case '/':
            ret = left / right;
            break;
    }
    return ret;
}
