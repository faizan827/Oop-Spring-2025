#include <iostream>
#include <string>
using namespace std;

class Course {
protected:
    string courseCode;
    int credits;
public:
    Course(string code, int cred) : courseCode(code), credits(cred) {}
    virtual double calculateGrade() = 0;
    virtual void displayInfo() = 0;
    virtual ~Course() {}
};

class LectureCourse : public Course {
    double midterm;
    double finalExam;
public:
    LectureCourse(string code, int cred, double mid, double fin)
        : Course(code, cred), midterm(mid), finalExam(fin) {}
    double calculateGrade() override {
        return (midterm * 0.4) + (finalExam * 0.6);
    }
    void displayInfo() override {
        cout << "Lecture Course: " << courseCode << ", Credits: " << credits << ", Grade: " << calculateGrade() << endl;
    }
};

class LabCourse : public Course {
    double labWork;
    double project;
public:
    LabCourse(string code, int cred, double lab, double proj)
        : Course(code, cred), labWork(lab), project(proj) {}
    double calculateGrade() override {
        return (labWork * 0.5) + (project * 0.5);
    }
    void displayInfo() override {
        cout << "Lab Course: " << courseCode << ", Credits: " << credits << ", Grade: " << calculateGrade() << endl;
    }
};

int main() {
    Course* c1 = new LectureCourse("CS101", 3, 78, 90);
    Course* c2 = new LabCourse("CS102L", 1, 85, 95);

    c1->displayInfo();
    c2->displayInfo();

    delete c1;
    delete c2;

    return 0;
}
