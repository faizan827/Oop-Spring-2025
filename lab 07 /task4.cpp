class Person {
public:
    string name;
    int age;
    string contactNumber;
    string address;
    virtual void displayInfo() {}
    virtual void updateInfo() {}
};

class Patient : public Person {
public:
    int patientID;
    string medicalHistory;
    string doctorAssigned;
    void displayInfo() {}
};

class Doctor : public Person {
public:
    string specialization;
    float consultationFee;
    string patientsList;
    void displayInfo() {}
};

class Nurse : public Person {
public:
    string assignedWard;
    string shiftTimings;
    void displayInfo() {}
};

class Administrator : public Person {
public:
    string department;
    float salary;
    void updateInfo() {}
};

