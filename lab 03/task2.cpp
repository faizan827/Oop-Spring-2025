#include<iostream>
#include<string>
using namespace std;

class FitnessTracker {
    private:
    int DailyStepGoal;
    string Username;
    int Steps_Taken;
    int Calories_Burnt;
    int count;
    string Progress[500];
    
    public:
    FitnessTracker() {
        Username = "Laiba";
        steps_taken = 0;
        CaloriesBurnt = 0;
        DailystepsGoal = 10000; 
        count = 0;
        Progress[count] = "Journey  started  " ;
    }

    void set_steps_taken (int steps) {
        if (steps < 0) {
            cout << "Invalid steps." << endl;
        } else {
        steps_taken = steps;
        count++;
        Progress[count] = to_string(steps) + " steps";
        }
        cout << "\n";
    }

    void TotalCaloriesBurnt() {
        if (steps_taken < 100) {
            cout << "walk more to  burn calories" << endl;
        } else {
            CaloriesBurnt = steps_taken/10;
            cout << "You have burnt " << CaloriesBurnt << " Calories " << endl;
            count++;
            Progress[count] = to_string(CaloriesBurnt) + " has been burnt";
        }
        cout << "\n";
    }

    void Display_details() {
        cout << "data" << endl;
        for (int i=0;i<=count;i++) {
            cout << i+1 << ". " << Progress[i] << endl;
        }
        count++;
        Progress[count] = "Progress history was seen.";
        cout << "\n";
    }

    void CheckGoal() {
        if (steps_taken >= DailystepsGoal) {
            cout << goals met << endl;
        } else if (steps_taken < DailystepsGoal) {
            cout << "You need " << DailystepsGoal - steps_taken << " more" << endl;
        }
        cout << "\n";
    }
};

int main () {
    FitnessTracker Laiba_journey;
    int opt, steps;
    
while(1) {
    cout << "1. Add steps " << endl;
    cout << "2. View details." << endl;
    cout << "3. view history. " << endl;
    cout << "4. check goal." << endl;
    cout << "Choose one " << endl;
    cin >> opt;
    switch (opt)
    {
    case 1:
    cout << "Enter the number of steps  ";
    cin >> steps;
    Laiba_journey.set_steps_taken(steps);
    break;
    case 2:
    Laiba_journey.TotalCaloriesBurnt();
    break;
    case 3:
    Laiba_journey.Display_details();
    break;
    case 4:
    Laiba_journey.CheckGoal();
    break;
    default:
    cout << "Invalid option." << endl;
    break;
    }
  }
    return 0;
}
