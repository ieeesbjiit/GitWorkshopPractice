//Insertion and selection sort template
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
void selection_sort() {
    int n;
    cout << "\nHow many elements you want to insert in the array?: ";
    cin >> n;
    T temp;
    vector <T> arr;
    cout << "\nEnter elements: ";
    for (int i = 0; i < n; i++) {
        cout << "\nEnter " << i + 1 << " element: ";
        cin >> temp;
        arr.push_back(temp);
    }
    int ind;
    for (int i = 0; i < arr.size(); i++) {
        ind = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[ind] > arr[j]) {
                ind = j;
            }
        }
        temp = arr[ind];
        arr[ind] = arr[i];
        arr[i] = temp;
    }
    for (auto x : arr) {
        cout << x << "    ";
    }
}

template <class T>
void insertion_sort() {
    int n;
    cout << "\nHow many elements you want to insert in the array?: ";
    cin >> n;
    T temp;
    vector <T> arr;
    cout << "\nEnter elements: ";
    for (int i = 0; i < n; i++) {
        cout << "\nEnter " << i + 1 << " element: ";
        cin >> temp;
        arr.push_back(temp);
    }
    int j = 0;
    for (int i = 0; i < arr.size(); i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    for (auto x : arr) {
        cout << x << "    ";
    }
}

int main()
{
    selection_sort <int> ();
    selection_sort <float> ();
    selection_sort <double> ();
    selection_sort <string> ();
    insertion_sort <int> ();
    insertion_sort <float> ();
    insertion_sort <double> ();
    insertion_sort <string> ();
    return 0;
}
