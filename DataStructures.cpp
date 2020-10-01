#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student{
    int a,b;
    string str,arr,sr,c,d;
  public:
       void set_age(int age){
         a=age;
       }
       void set_standard(int sd){
           b=sd;
       }
       void set_first_name(string fn){
          str=fn;
       }
       void set_last_name(string ln){
           arr=ln;
       }
       int get_age(){
           return a;
       }
       string get_last_name(){
           return arr;
       }
       string get_first_name(){
           return str;
       }
       int get_standard(){
           return b;
       }
       string to_string(){
           stringstream str1,str2;
           str1<<a;
           c=str1.str();
            str2<<b;
            d=str2.str();
             d=str2.str();

           sr=c+","+str+","+arr+","+d;
           //cout<<a<<','<<str<<','<<arr<<','<<b;
          return sr;
       }
};
int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
   cout << st.to_string();

    return 0;
}
