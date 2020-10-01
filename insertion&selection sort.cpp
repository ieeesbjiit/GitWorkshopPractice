#include<iostream>
#include<string.h>
using namespace std;

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}

template <class S>
void printArray(S a[], int n)
{
    for(int i = 0; i <n; i++)
        cout << a[i] << " ";
    cout << endl;
}


template <class T>
void selectionSort(T *arr, int n)  
{  
    int i, j, min_idx;  
    
    for (i = 0; i < n-1; i++)  
    {  
          
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        swap(&arr[min_idx], &arr[i]);  
    }  
} 


template <class T>
void insertionSort(T *a, int n)
{
    T temp = a[0];
    for(int i = 1; i <= n; i++)
    {
        temp = a[i];
        int j = 0;
        for(j = i; j > 0; j--)
            if(temp < a[j - 1])
               a[j] = a[j - 1];
            else break;
        a[j] =  temp;
    }
}





int main(void){

int n;
int ch;

cout << "This program sorts different variable types" << endl;
cout << endl;

int choice;
cout << "What variable type do you want to sort?" << endl;
cout << "1. Integer" << endl;
cout << "2. Float" << endl;
cout << "3. Character" << endl;
cout << "4. Double" << endl;
cout << "5. Exit" << endl;
cin >> choice;


    switch(choice){

        case 1:
        {
            cout << "Please enter array size: ";
            cin >> n;

            cout << "Please enter array elements:" << endl;
            cout << endl;

            int intArray[n];

                for (int i=0; i <n; i++){

                    cout << "* ";
                    cin >> intArray[i];
                    cout << endl;

                }
                cout<<"\n PRESS 1. for insertion sort and 2. for selection sort";
                cin>>ch;
                if(ch==1)
                insertionSort(intArray, n);
                else
                {
                    selectionSort(intArray,n);
                }
                
                cout << endl;
                printArray(intArray, n);
                 break;
            }   
            case 2:
            {
                cout << "Please enter array size: ";
                cin >> n;

                cout << "Please enter array elements." << endl;
                cout << endl;

                float floatArray[n];

                for (int i=1; i <= n; i++){

                    cout << "* ";
                    cin >> floatArray[i];
                    cout << endl;

                }
                insertionSort(floatArray, n);
                cout << endl;
                printArray(floatArray, n);
                    break;
            }
            case 3:{
                cout << "Please enter array size: ";
                cin >> n;


                cout << "Please enter array elements." << endl;
                cout << endl;

                char charArray[n];

                for (int i=1; i <= n; i++){

                    cout << "* ";
                    cin >> charArray[i];
                    cout << endl;

                }
                insertionSort(charArray, n);
                cout << endl;
                printArray(charArray, n);
                    break;
            }
            case 4:
             {     cout << "Please enter array size: ";
                  cin >> n;

                  cout << "Please enter array elements." << endl;
                  cout << endl;

                double doubleArray[n];

                for (int i=1; i <= n; i++){

                    cout << "* ";
                    cout << endl;
                    cin >> doubleArray[i];

                }
                insertionSort(doubleArray, n);
                cout << endl;
                printArray(doubleArray, n);
                    break;
             }
        case 5:{
                    break;}

        }
}

