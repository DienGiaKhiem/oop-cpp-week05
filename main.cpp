#include <iostream>
using namespace std;
int main()
{
    int student;
    cout <<"Please enter the number of students:";
    cin >> student;
    if(student >= 2 && student <= 20)
    {
        cout << "valid number of students" << endl;
    }
    else 
    {
        cout << "invalid number of students" << endl;
    }
    return 0;
}