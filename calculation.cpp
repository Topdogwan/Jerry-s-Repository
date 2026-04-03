#include<iostream>
using namespace std;

int main() {
    int score1;
    int score2;
    int totalScore;
    cout<<"Enter the first test score: ";
    cin>>score1;
    cout<<"Enter the second test score: ";
    cin>>score2;
    totalScore= score1 + score2;
    cout<<"Your total score is: "<<totalScore<<endl;
    
    if (totalScore>=85) {
        cout<<"Your final grade is A1";
    }
    else if (totalScore>=75) {
        cout<<"Your final grade is B2";
    }
    else if (totalScore>=65) {
        cout<<"Your final grade is B3";
    } 
    else if (totalScore>=50) {
        cout<<"Your final grade is C";
    }
    else if (totalScore>=40) {
        cout<<"Your final grade is D";
    }
    else if (totalScore>=30) {
        cout<<"Your fianl grade is E";
    }
    else {
        cout<<"Your final grade is F";
    }
    
    return 0;
}
