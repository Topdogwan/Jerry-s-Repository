// Jeremy Darian Doe Tetteh
// 2526403912
//21st to 28th May 2028
// This program simply uses functions to process and display student records.

#include <iostream>
#include <string>
using namespace std;

//This is my blueprint
class Student {
public:
    string name;
    int id;
    double quizscore;
    double testscore;
    double examscore;
    double totalscore;
    char grade;
    string remarks;
};

Student studentRecords[30];

//This function uses the totalscore to return a character grade
char assignGrades(double total) {
    if (total >= 80) {
        return 'A';
    } else if (total >= 70) {
        return 'B';
    } else if (total >= 60) {
        return 'C';
    } else if (total >= 50) {
        return 'D';
    } else {
        return 'F';
    }
}

//This function accepts the parameters examscore,cuurentscore and quizscore to return a total value along with a remark
void computeGrades(Student* currentstudent) {
    currentstudent->totalscore = currentstudent->quizscore + currentstudent->testscore + currentstudent->examscore;
    currentstudent->grade = assignGrades(currentstudent->totalscore);

    if (currentstudent->totalscore >= 80) {
        currentstudent->remarks = "Excellent";
    } else if (currentstudent->totalscore >= 70) {
        currentstudent->remarks = "Good";
    } else if (currentstudent->totalscore >= 60) {
        currentstudent->remarks = "Average";
    } else if (currentstudent->totalscore >= 50) {
        currentstudent->remarks = "Below Average";
    } else {
        currentstudent->remarks = "Fail";
    }
}
//This function accepts and stores the name,id and three scores of students.
void inputStudents(int &count) {
    if (count >= 30) {
        cout << "\nSystem is full! Maximum limit of 30 students reached.\n";
        return;
    }

    Student* activeStudent = &studentRecords[count];

    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, activeStudent->name);


    cout << "Enter Student ID (Integer number): ";
    cin >> activeStudent->id;

    do {
        cout << "Enter Quiz Score (0-10): ";
        cin >> activeStudent->quizscore;
        if (activeStudent->quizscore < 0 || activeStudent->quizscore > 10) {
            cout << "Error, Quiz score between (0-10)\n";
        }
    } while (activeStudent->quizscore < 0 || activeStudent->quizscore > 10);

    do {
        cout << "Enter Mid Sem Score (0-30): ";
        cin >> activeStudent->testscore;
        if (activeStudent->testscore < 0 || activeStudent->testscore > 30) {
            cout << "Error, Test score between (0-30)\n";
        }
    } while (activeStudent->testscore < 0 || activeStudent->testscore > 30);

    do {
        cout << "Enter Exam Score (0-60): ";
        cin >> activeStudent->examscore;
        if (activeStudent->examscore < 0 || activeStudent->examscore > 60) {
            cout << "Error, Exam score between (0-60)\n";
        }
    } while (activeStudent->examscore < 0 || activeStudent->examscore > 60);

    computeGrades(activeStudent);
    count = count + 1;
}

void findHighestLowest(Student* studentArray, int studentCount, Student* highestStudent, Student* lowestStudent) {
    *highestStudent = studentArray[0];
    *lowestStudent = studentArray[0];

    for (int i = 1; i < studentCount; i++) {
        if (studentArray[i].totalscore > highestStudent->totalscore) {
            *highestStudent = studentArray[i];
        }
        if (studentArray[i].totalscore < lowestStudent->totalscore) {
            *lowestStudent = studentArray[i];
        }
    }
}

//This function displays results in a neat tabular form.
void displayReport(Student* currentstudent, int studentCount) {
    if (studentCount == 0) {
        cout << "\nNo record has been found. Please see Option 1 first.\n";
        return;
    }
    cout << "\nID\t\tNAME\t\t\tTOTAL" << endl;
    cout << "GRADE\tREMARK" << endl;
    cout << "------\t---------------\t\t-----" << endl;

    for (int i = 0; i < studentCount; i++) {
        cout << currentstudent[i].id << "\t" << currentstudent[i].name << "\t\t" << currentstudent[i].totalscore << endl;
        cout << currentstudent[i].grade << "\t" << currentstudent[i].remarks << endl;
        cout << endl;
        cout << "================================================" << endl;
    }
}

//This function outputs the class statistics using the total score.
void displayStatistics(Student* currentstudent, int studentCount) {
    if (studentCount == 0) {
        cout << "\nNo record has been found yet so go and see option 1 first.\n" << endl;
        return;
    }

    Student topStudent;
    Student bottomStudent;
    double sumOfTotals = 0.0;
    int failedCount = 0;

    findHighestLowest(currentstudent, studentCount, &topStudent, &bottomStudent);

    for (int i = 0; i < studentCount; i++) {
        sumOfTotals += currentstudent[i].totalscore;
        if (currentstudent[i].grade == 'F') {
            failedCount++;
        }
    }

    double classAverage = sumOfTotals / studentCount;
    int passedCount = studentCount - failedCount;

    cout << "\n==============================\n";
    cout << "    CLASS STATISTICS\n";
    cout << "------------------------------\n";
    cout << " Highest Score : " << topStudent.totalscore << " (" << topStudent.name << ")\n";
    cout << " Lowest Score  : " << bottomStudent.totalscore << " (" << bottomStudent.name << ")\n";
    cout << " Average Score : " << classAverage << "\n";
    cout << " Number of Students who passed : " << passedCount << "\n";
    cout << " Number of students who failed : " << failedCount << "\n";
    cout << "------------------------------\n";
}

//This function allows me to search for the results of  any student i wish.
void searchStudentByID(Student* studentArray, int studentCount) {
    if (studentCount == 0) {
        cout << "\nNo record has been found. Please see Option 1 first.\n";
        return;
    }

    int searchID;
    cout << "\nEnter Student ID to Search: ";
    cin >> searchID;

    int foundIndex = -1;

    for (int i = 0; i < studentCount; i++) {
        if (studentArray[i].id == searchID) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        cout << "\n================ STUDENT RECORD FOUND ================\n";
        cout << "ID\t\tNAME\t\t\tTOTAL\tGRADE\tREMARK\n";
        cout << "------------------------------------------------------\n";
        cout << studentArray[foundIndex].id << "\t"
             << studentArray[foundIndex].name << "\t\t"
             << studentArray[foundIndex].totalscore << "\t"
             << studentArray[foundIndex].grade << "\t"
             << studentArray[foundIndex].remarks << "\n";
        cout << "======================================================\n";
    } else {
        cout << "\nStudent Record with ID " << searchID << " does not exist.\n";
    }
}

int main() {
    int studentCount = 0;
    int choice;

    do {
        cout << "\n=========================================\n";
        cout << "    STUDENT GRADE MANAGEMENT SYSTEM\n";
        cout << "=========================================\n";
        cout << "1. Enter Student Records\n";
        cout << "2. Compute and Assign Grades\n";
        cout << "3. Display Full Class Report\n";
        cout << "4. Display Class Statistics\n";
        cout << "5. Search Student by ID\n";
        cout << "6. Exit\n";
        cout << "-----------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputStudents(studentCount);
                break;
            case 2:
                if (studentCount == 0) {
                    cout << "\nThere are no records that have been inputed yet.\n";
                } else {
                    for (int i = 0; i < studentCount; i++) {
                        computeGrades(&studentRecords[i]);
                    }
                    cout << "\nMy program has stored the records.\n";
                }
                break;
            case 3:
                displayReport(studentRecords, studentCount);
                break;
            case 4:
                displayStatistics(studentRecords, studentCount);
                break;
            case 5:
                searchStudentByID(studentRecords, studentCount);
                break;
            case 6:
                cout << "\nMy Program is complete!\n";
                break;
            default:
                cout << "\nPlease enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
