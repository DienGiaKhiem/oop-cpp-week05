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

    double score[25]; 
    for(int i = 1; i <= student; i++)
    {
        score[i] = -1;
        while(score[i] < 1 || score[i] > 10)
        {
            cout << "Please enter the score for student " << i << ":";
            cin >> score[i];
            if(score[i] < 1 || score[i] > 10)
            {
                cout << "Invalid score. Please enter a score between 1 and 10." << endl;
            }
            
        }
    }
        cout << "==Student score== " << endl;
        for(int i = 1; i <= student; i++)
        {
        cout << " student " << i << " is: " << score[i] << endl;
        }

        
        cout << "\n===== RESULTS =====" << endl;
        for(int i = 1; i <= student; i++)
        {
            if(score[i] >= 5) 
            {
                cout << "Student " << i << ": " << score[i] << " -> PASS" << endl;
            }
            else 
            {
                cout << "Student " << i << ": " << score[i] << " -> FAIL" << endl;
            }
        }

        int passed = 0;
        int failed = 0;
        for(int i = 1; i <= student; i++)
        {
            if(score[i] >= 5) 
            {
                passed = passed + 1;
            }
            else 
            {
                failed = failed + 1; 
            }
        }
        cout << "\n===== STATISTICS =====" << endl;
        cout << "Passed : " << passed << " students" << endl;
        cout << "Failed : " << failed << " students" << endl;


        double highest = score[1]; 
        double lowest = score[1];  

        for(int i = 1; i <= student; i++)
        {
            if(score[i] > highest) 
            {
                highest = score[i]; 
            }
            if(score[i] < lowest) 
            {
                lowest = score[i];  
            }
        }
        cout << "\n===== EXTREMES =====" << endl;
        cout << "Highest score: " << highest << endl;
        cout << "Lowest score : " << lowest << endl;


        cout << "\n===== CLASSIFICATION =====" << endl;
        for(int i = 1; i <= student; i++)
        {
            cout << "Student " << i << ": " << score[i] << " -> ";
            
            if(score[i] >= 9) {
                cout << "Excellent" << endl;
            }
            else if(score[i] >= 8) {
                cout << "Very Good" << endl;
            }
            else if(score[i] >= 6.5) {
                cout << "Good" << endl;
            }
            else if(score[i] >= 5) {
                cout << "Average" << endl;
            }
            else {
                cout << "Fail" << endl;
            }
        }
    return 0;
}