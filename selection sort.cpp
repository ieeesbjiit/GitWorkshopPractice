Q-3
#include<bits/stdc++.h>
using namespace std;
template <class Item>
void selectionSort(Item *a, const int n) {
for (int i = 0; i < n - 1; i++) {
int min = i;
for (int j = i + 1; j < n; j++) {
if (a[j] < a[min])
min = j;
}
swap(a[i], a[min]);
}
}
template <class Object>
void swap(Object &el1, Object &el2) {
Object temp = el1;
el1 = el2;
el2 = temp;
}
template<class T>
void printarray(T a[],int n){
for(int i=0;i<n;i++){
cout<<a[i]<<" ";
}
}
int main(){
int n;
cin>>n;
float arr[n];
int intarr[n];
for(int i=0;i<n;i++){
cin>>arr[i];
}
selectionSort<float>(arr,n);
printarray<float>(arr,n);
for(int i=0;i<n;i++){
cin>>intarr[i];
}
selectionSort<int>(intarr,n);
printarray<int>(intarr,n);
return 0;
}
