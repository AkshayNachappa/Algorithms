#include<iostream>
#include<stack>
using namespace std;

bool isOperand(char c)
{
    return isdigit(c);
}
double expression(string s)
{
    stack<double> Stack;

    for(int i=0;i<s.size();i++)
    {
        if(isOperand(s[i]))
        {
            Stack.push(s[i]-'0');
        }
        else
        {
            double op1,op2;
            op1 = Stack.top();
            Stack.pop();
            op2 = Stack.top();
            Stack.pop();

            switch(s[i])
            {
                case '+':
                    Stack.push(op1+op2);
                    break;
                case '-':
                    Stack.push(op1-op2);
                    break;
                case '*':
                    Stack.push(op1*op2);
                    break;
                case '/':
                    Stack.push(op1/op2);
                    break;
            };
        }
        
    }
    return Stack.top();
}

int main()
{
    cout<<"Enter the expression"<<endl;
    string s;
    cin>>s;
    cout<<"Result is = "<<expression(s);

    return 0;
}