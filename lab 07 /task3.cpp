class Ticket {
public:
    int ticketID;
    string passengerName;
    float price;
    string date;
    string destination;
    void reserve() {}
    void cancel() {}
    virtual void displayTicketInfo() {}
};

class FlightTicket : public Ticket {
public:
    string airlineName;
    string flightNumber;
    string seatClass;
    void displayTicketInfo() {
        cout << "Flight - Airline: " << airlineName << ", Seat Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket {
public:
    string trainNumber;
    string coachType;
    string departureTime;
    void reserve() {}
};

class BusTicket : public Ticket {
public:
    string busCompany;
    int seatNumber;
    void cancel() {}
};

class ConcertTicket : public Ticket {
public:
    string artistName;
    string venue;
    string seatType;
    void displayTicketInfo() {
        cout << "Concert - Artist: " << artistName << ", Venue: " << venue << endl;
    }
};

