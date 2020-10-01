#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int precedence(char ch) {
   if(ch == '+' || ch == '-') {
      return 1;              //Precedence of + or - is 1
   }else if(ch == '*' || ch == '/') {
      return 2;            //Precedence of * or / is 2
   }else if(ch == '^') {
      return 3;            //Precedence of ^ is 3
   }else {
      return 0;
   }
}

void convert(string v)
{
    stack<char> s2;
    for(long unsigned int i=0;i<v.size();i++)
    {
        if(isalnum(v[i]))
        cout<<v[i];
        else if(v[i]=='*' || v[i]=='+' ||v[i]=='-' || v[i]=='/')
        {
            if(s2.empty() || precedence(v[i])>precedence(s2.top()))
            {
                s2.push(v[i]);   
            }
            else 
            {
                cout<<s2.top();
                s2.pop();
                s2.push(v[i]);
            }
        }
    }
    while(s2.empty()==0)
    {
        cout<<s2.top();
        s2.pop();
    }
}
int main()
{
    string s="w1*f1*1/2+w2*f2*1/2+w3*f3";
   /* char ch;
    int choice=1;
    while(choice==1)
    {
        cout<<"enter character";
        cin>>ch;
        s.push_back(ch);
        cout<<"\n enter choice";
        cin>>choice;
    }*/
    convert(s);
}