#include <string>
#include <iostream>
using namespace std;
// CollegeCourse Class
class CollegeCourse {
    // your code here
    public:
        string courseID;
        char grade;
        int credits;
        int gradePoints;
        float honorPoints;
        
        void set_CourseId(string CID);
        void set_Grade(char g);
        void set_Credit(int cr);
        int calculateGradePoints(char g);
        float calculateHonorPoints(int gp, int cr);
        void display() {
            cout << gradePoints << " " << honorPoints << endl;
        }
};

void CollegeCourse::set_CourseId(string CID) {
    courseID = CID;
}

void CollegeCourse::set_Grade(char g) {
    grade = g;
}

void CollegeCourse::set_Credit(int cr) {
    credits = cr;
}

int CollegeCourse::calculateGradePoints(char g) {
    switch(g) {
        case 'A': case 'a': gradePoints = 10; break;
        case 'B': case 'b': gradePoints =  9; break;
        case 'C': case 'c': gradePoints =  8; break;
        case 'D': case 'd': gradePoints =  7; break;
        case 'E': case 'e': gradePoints =  6; break;
        case 'F': case 'f': gradePoints =  5; break;
        default : gradePoints =  0; break;
    }
    return gradePoints;
}

float CollegeCourse::calculateHonorPoints(int gp, int cr) {
    honorPoints = gp * cr;
    return honorPoints;
}
