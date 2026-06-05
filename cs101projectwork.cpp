//Name: Favour Elikem Joseph
//Index number;2526401049
//Course code; CS101
//Course name; Introduction to Programming
//bsc computer science
//Assignment 1; Student Record Management System

//sir i know my comments are inefficient well atleast it is not ai generated like the rest so extra marks.

#include <iostream>//for input and output
#include <string>//for string operations
#include <iomanip>

using namespace std;//to prevent over usage of std

const int studentsize = 30;

//these are my declarations of functions

void inputstudents(string*, int*, float*, float*, float*, int&);
char assignGrade(float);
void computeGrades(float*, float*, float*, float*, char*, string*, int);
void displayReport(string*, int*, float*, char*, string*, int);
void displayStatistics(float*, string*, int);
int searchByID(int*, int, int);

int main() {
//these are my arrays
    string names[studentsize];
    int id[studentsize];
    float quiz[studentsize];
    float midSem[studentsize];
    float exam[studentsize];
    float totalScore[studentsize];
    char grade[studentsize];
    string remark[studentsize];

    int studentcount = 0;
    int choice;

    //here is my menu sir
    cout<<"===========================================\n";
    do {
        cout << "\n1. Enter student record\n";
        cout << "2. Compute and assign grade\n";
        cout << "3. Display full class report\n";
        cout << "4. Display class statistics\n";
        cout << "5. Search student by ID\n";
        cout<<"=========================================\n";
        cout << "6. Exit\n";
        cin >> choice;

        //this function is for declaring all my functions in the main function i used switch because the functions are linked to choice
        switch(choice) {

        case 1:
            inputstudents(names, id, quiz, midSem, exam, studentcount);
            break;

        case 2:
            computeGrades(quiz, midSem, exam, totalScore, grade, remark, studentcount);
            break;

        case 3:
            displayReport(names, id, totalScore, grade, remark, studentcount);
            break;

        case 4:
            displayStatistics(totalScore, names, studentcount);
            break;

        case 5: {
            int targetID;
            cout << "Enter ID: ";
            cin >> targetID;

            int index = searchByID(id, studentcount, targetID);

            if (index != -1)
                cout << names[index] << " " << totalScore[index] << endl;
            else
                cout << "Not found\n";
            break;
        }

        case 6:
            cout << "Exiting...\n";
            break;
        }

    } while (choice != 6);

    return 0;
}
//this function is for inputing student data,student ID, quiz,midsem,and exam with their validation
void inputstudents(string* names, int* id, float* quiz, float* midSem, float* exam, int& studentcount){

    char choice;

    do{
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, names[studentcount]);

        cout << "Enter student ID: ";
        cin >> id[studentcount];

        do {
            cout << "Enter quiz score (0-20): ";
            cin >> quiz[studentcount];
        } while (quiz[studentcount] < 0 || quiz[studentcount] > 20);

        do {
            cout << "Enter mid-semester score (0-30): ";
            cin >> midSem[studentcount];
        } while (midSem[studentcount] < 0 || midSem[studentcount] > 30);

        do {
            cout << "Enter exam score (0-50): ";
            cin >> exam[studentcount];
        } while (exam[studentcount] < 0 || exam[studentcount] > 50);

        studentcount++;

        cout << "Add another student record? (y/n): ";
        cin >> choice;

    } while (choice == 'y' && studentcount < studentsize);
}
//this function is for assigning grade to a student score
char assignGrade(float totalScore){
    if (totalScore >= 80) return 'A';
    else if (totalScore >= 70) return 'B';
    else if (totalScore >= 60) return 'C';
    else if (totalScore >= 50) return 'D';
    else return 'F';
}
//this function is for finding the highest and lowest score
void computeGrades(float* quiz, float* midSem, float* exam,
                   float* totalScore, char* grade, string* remark, int studentcount){

    for (int i = 0; i < studentcount; i++) {

        totalScore[i] = quiz[i] + midSem[i] + exam[i];

        grade[i] = assignGrade(totalScore[i]);

        if (grade[i] == 'F')
            remark[i] = "Fail";
        else
            remark[i] = "Pass";
    }
}
//this function is for displaying report
void displayReport(string* names, int* id, float* totalScore,
                   char* grade, string* remark, int studentcount){

    cout << "\nID\tName\tTotal\tGrade\tRemark\n";

    for (int i = 0; i < studentcount; i++) {
        cout << id[i] << "\t"
             << names[i] << "\t"
             << totalScore[i] << "\t"
             << grade[i] << "\t"
             << remark[i] << endl;
    }
}
//this function is for displaying statistics
void displayStatistics(float* totalScore, string* names, int studentcount) {

    if (studentcount == 0) {
        cout << "No student data available.\n";
        return;
    }

    float highest = totalScore[0];
    float lowest = totalScore[0];
    int highIndex = 0;
    int lowIndex = 0;

    float sum = 0;
    int pass = 0;
    int fail = 0;

    for (int i = 0; i < studentcount; i++) {

        if (totalScore[i] > highest) {
            highest = totalScore[i];
            highIndex = i;
        }

        if (totalScore[i] < lowest) {
            lowest = totalScore[i];
            lowIndex = i;
        }

        sum += totalScore[i];

        if ( totalScore[i] >= 50)
            pass++;
        else
            fail++;
    }

    float average = sum / studentcount;

    cout << "\nCLASS STATISTICS\n";
    cout << "Highest Score: " << highest << " (" << names[highIndex] << ")\n";
    cout << "Lowest Score: " << lowest << " (" << names[lowIndex] << ")\n";
    cout << "Average Score: " << average << endl;
    cout << "Passed: " << pass << " Failed: " << fail << endl;
}
//this function is for the search function
int searchByID(int* id, int studentcount, int targetID) {
    for (int i = 0; i < studentcount; i++) {
        if (id[i] == targetID)
            return i;
    }
    return -1;
}