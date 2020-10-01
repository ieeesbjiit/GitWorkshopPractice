#include<stdio.h>
#include<stdlib.h>

long int factorial(int);//function declaration

int main()//main function
{
    int n=10;
    //long int result;
 printf("Enter a number ");
 fflush(stdin);
   scanf("%d",&n);
    //result = factorial(n);
    printf("\n\n%ld",factorial(n));
return 0;
}

long int factorial(int n)//function definition
{
    long int result;
    if(n==0||n==1)
    result = 1;
    else
    result = n*factorial(n-1);//recursive function
    return result;

}
