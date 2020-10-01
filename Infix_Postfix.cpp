#include<iostream>
#include<deque>
#include<stack>
#include<strings.h>

using namespace std;

class Converter
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
    cout<<"\nPostfix Expression: ";
    auto it = final_string.begin();
    while(it!=final_string.end())
        cout<<*(it++);
    getchar();
}

void Converter::calculate(void)
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(')
        {
            st.push(str[i]);
            continue;
        }
        if(str[i]==')')
        {
            while((st.top()!='(')&&(!st.empty()))
            {
                final_string.push_back(st.top());
                st.pop();
            }
            st.pop();
            continue;
        }
        if(!is_operator(str[i]))
        final_string.push_back(str[i]);
        else
        {
            if(st.empty()||(st.top()=='(')||(priority_check(str[i])>priority_check(st.top())))
               st.push(str[i]);
            else
            {
                while(1)
                {
                    if(st.empty()||(st.top()=='('))
                        break;
                    final_string.push_back(st.top());
                    st.pop();
                }
                st.push(str[i]);
            }
        }
    }
    while(!st.empty())
    {
        final_string.push_back(st.top());
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
    Converter in_pos;
    in_pos.get_string();
    in_pos.calculate();
    in_pos.show_result();
}
