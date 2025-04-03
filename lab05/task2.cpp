#include<iostream>
using namespace std;

class Student {
private:
    int studentID;
    string studentName;
    int* ExamScores;
    int NumScores;

public:
    Student(int id, string name, int scores[], int num) : studentID(id), studentName(name), NumScores(num) {
        ExamScores = new int[NumScores];
        for (int i = 0; i < NumScores; i++) {
            ExamScores[i] = scores[i];
        }
    }

    Student(Student& other) {
        studentID = other.studentID;
        studentName = other.studentName;
        NumScores = other.NumScores;
        ExamScores = new int[NumScores];
        for (int i = 0; i < NumScores; i++) {
            ExamScores[i] = other.ExamScores[i];
        }
    }

    ~Student() {
        delete[] ExamScores;
    }

    void displayDetails() const {
        cout << "Student ID: " << studentID << endl;
        cout << "Name: " << studentName << endl;
        cout << "Exam Scores: " << endl;
        for (int i = 0; i < NumScores; i++) {
            cout << "Score " << i + 1 << ": " << ExamScores[i] << endl;
        }
    }
};

int main() {
    int Examscores[] = {65, 87, 18, 72};
    Student Hasan(123, "Hasan", Examscores, 4);
    Hassan.displayDetails();

    Student ali(Hasan);  
    cout << "\nHassan' copy details: " << endl;
    Fasiha.displayDetails();

    return 0;
}
