#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    Buildseg();
    return 0;
}