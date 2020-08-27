#include<iostream>
#include<stack>
using namespace std;

bool isOperand(char c)
{
    return isdigit(c);
}
double expression(string x)
{
    stack<double> expStack;
    for(int i=x.size()-1;i>=0;i--)
    {
        if(isOperand(x[i]))
            expStack.push(x[i]-'0');
        else
        {
            double op1 = expStack.top();
            expStack.pop();
            double op2 = expStack.top();
            expStack.pop();
            switch (x[i])
            {
            case '+':
                expStack.push(op1+op2);
                break;
            case '-':
                expStack.push(op1-op2);
            case '*':
                expStack.push(op1*op2);
                break;
            case '/':
                expStack.push(op1/op2);    
            
            default:
                break;
            }
        }
        
    }
    return expStack.top();
}

int main()
{
    cout<<"Enter the expression"<<endl;
    string s;
    cin>>s;
    cout<<"Result is = "<<expression(s);

    return 0;
}