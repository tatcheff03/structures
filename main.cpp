#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

struct Student
{
    int FacNumber;
    std::string name;
    double avggrade;

    Student() : FacNumber(0), avggrade(0.0) {} 
};

void danni(Student* students, int k)
{
    for (int i = 0; i < k; i++)
    {
        cout << "Enter data for student " << i + 1 << ":" << endl;
        cout << "Faculty Number: ";
        cin >> students[i].FacNumber;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Average Grade: ";
        cin >> students[i].avggrade;
    }
}

void maxgradestudents(const Student* students, int k)
{
    cout << "Students with high grades:" << endl;
    for (int i = 0; i < k; i++)
    {
        if (students[i].avggrade >= 5.50)
        {
            cout << students[i].name << endl;
        }
    }
}

void mingrade(const Student* students, int k)
{
    int count = 0;
    for (int i = 0; i < k; i++)
    {
        if (students[i].avggrade < 3.00)
        {
            count++;
             cout << "Failing student/s: " << students[i].name << endl;
        }
    }
    cout << "Number of failing students: " << count<< endl;
    
}

double avgcalc(const Student* students, int k)
{
    double sum = 0.0;
    for (int i = 0; i < k; i++)
    {
        sum += students[i].avggrade;
    }
    return sum / k;
}

void curstatus(const Student* students, int k)
{
    cout << "Current status:" << endl;
    for (int i = 0; i < k;i++)
    {
        cout << "Student " << i+1 << ":" << endl;
        cout << "Faculty Number: " << students[i].FacNumber << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Average Grade: " << students[i].avggrade << endl;
    }
}

int main()
{
    int k;
    cout << "Enter the number of students: ";
    cin >> k;

    Student* students = new Student[k];

    int choice;

    do
    {
        cout << endl;
        cout << "Select an action:" << endl;
        cout << "1 - Enter data for students" << endl;
        cout << "2 - List of honors students" << endl;
        cout << "3 - Number of failing students" << endl;
        cout << "4 - Average grade of the faculty" << endl;
        cout << "5 - Current status" << endl;
        cout << "0 - Exit the program" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            danni(students, k);
            break;
        case 2:
            maxgradestudents(students, k);
            break;
        case 3:
            mingrade(students, k);
            break;
        case 4:
            cout << "Average grade of the faculty: " << avgcalc(students, k) << endl;
            break;
        case 5:
            curstatus(students, k);
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 0);

    delete[] students;

    return 0;
}
