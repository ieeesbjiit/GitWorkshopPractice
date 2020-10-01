#include<iostream>
#include<deque>
#include<stack>
#include<strings.h>

using namespace std;

class Converter             //a+b-c*(5+3/2-(p%q*z)/6)-f*7
{
    stack<char> st;
    deque<char> final_string{};
    string str{};
public:
    void get_string(void);
    void calculate(void);
    void show_result(void);
    int is_operator(char);
    int priority_check(char);
};

int Converter::priority_check(char op)
{
    if(op=='*'||op=='/'||op=='%')
        return 2;
    if(op=='-'||op=='+')
        return 1;
}

int Converter::is_operator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%')
    return 1;
    return 0;
}

void Converter::show_result(void)
{
    cout<<"\nPrefix Expression: ";
    auto it = final_string.begin();
    while(it!=final_string.end())
        cout<<*(it++);
    getchar();
}

void Converter::calculate(void)
{
    for(int i=str.length()-1;i>=0;i--)
    {
        if(str[i]==')')
        {
            st.push(str[i]);
            continue;
        }
        if(str[i]=='(')
        {
            while((st.top()!=')')&&(!st.empty()))
            {
                final_string.push_front(st.top());
                st.pop();
            }
            st.pop();
            continue;
        }
        if(!is_operator(str[i]))
        final_string.push_front(str[i]);

        if(is_operator(str[i]))
        {
                while( !st.empty() && (st.top() != ')')&& (priority_check(str[i]) < priority_check(st.top())))
                {
                    final_string.push_front(st.top());
                    st.pop();
                }
                st.push(str[i]);
        }
    }
    while(!st.empty())
    {
        final_string.push_front(st.top());
        st.pop();
    }
}

void Converter::get_string(void)
{
    cout<<"\nEnter a Infix Expression without using spaces ";
    getline(cin,str);
}

main()
{
    Converter in_pre;
    in_pre.get_string();
    in_pre.calculate();
    in_pre.show_result();
}
