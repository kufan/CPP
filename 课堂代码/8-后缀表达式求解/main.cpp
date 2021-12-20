#include <iostream>

#include "Calc.h"
#include "LinkStack.h"

using namespace std;

/*
后缀表达式求解:
1、把后缀表达式当作字符串去扫描
2、如果遇到的是 数字
    则直接入栈
3、如果遇到的是 运算符
    先从栈顶拿出 右操作数
    然后从栈顶拿出 左操作数
4、把计算结果入栈

5、字符串扫描结束，且栈中只有一个元素，该元素就是计算结果
*/

int main() {
    // 8+(3-1)*5 = 18
    // 831-5*+
    char str[] = "831-5*+";
    char* p = str;

    LinkStack* stack = Init_Stack();

    // MyNum* Right = NULL;
	
    while(*p != '\0') {
        if (IsNumber(*p)) {
            MyNum* my = (MyNum*) malloc(sizeof(MyNum));
            my->val = (*p - '0');  // '8' - '0' = 8
            Push_LinkStack(stack, (StackNode*)my);
        } else {
            // 先得到右操作数
            MyNum* Right = (MyNum*) Front_LinkStack(stack);
            int RightVal = Right->val;
            Pop_LinkStack(stack);
            if(Right != NULL) {
                free(Right);
                Right = NULL;
            }

            // 得到左操作数
            MyNum* Left = (MyNum*) Front_LinkStack(stack);
            int LeftVel = Left->val;
            Pop_LinkStack(stack);
            if (Left != NULL) {
                free(Left);
                Left = NULL;
            }

            int ans = Caculate(LeftVel, RightVal, *p);

            // 计算结果入栈
            MyNum* ret = (MyNum*)malloc(sizeof(MyNum));
            ret->val = ans;

            Push_LinkStack(stack, (StackNode*)ret);
        }

        p++;
    }

    if(GetSize_LinkStack(stack) == 1) {
        MyNum* ret = (MyNum*) Front_LinkStack(stack);
        cout << "ans = " << ret->val << endl;
        Pop_LinkStack(stack);
        if (ret != NULL) {
            free(ret);
            ret = NULL;
        }
    }

    Destroy_LinkStack(stack);

    return 0;
}
