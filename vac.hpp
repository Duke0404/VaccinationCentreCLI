#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>
#include <ctime>
#include <list>
#include <sstream>
using namespace std;

class Time {
    unsigned int minute;
    unsigned int hour;

    public:
    unsigned int getMinute() const;
    unsigned int getHour() const;

    void setMinute(unsigned int min);
    void setHour(unsigned int hou);

    Time();
    Time(unsigned int hour, unsigned int minute);

    void increaseQuarter();

    bool operator==(const Time &RHS) const;
    friend ostream& operator<<(ostream& out, const Time& time);
};

bool operator<(const Time& LHS, const Time& RHS);
bool operator>(const Time& LHS, const Time& RHS);

class Date {
    unsigned int day;
    unsigned int month;
    unsigned int year;

    public:
    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;

    void setDay(unsigned int day);
    void setMonth(unsigned int month);
    void setYear(unsigned int year);

    Date();
    Date(unsigned int day, unsigned int month, unsigned int year);

    Date& operator=(const Date& RHS);
    Date operator+(const Date& RHS);
    Date operator-(const Date& RHS) const;
    Date& operator++();
    bool operator==(const Date& RHS) const;
    bool operator!=(const Date& RHS) const;
    friend ostream& operator<<(ostream& out, const Date& date);
};

bool operator<(const Date& LHS, const Date& RHS);
bool operator>(const Date& LHS, const Date& RHS);

class Appointment {
    Time time;
    unsigned int appointeeID;
    bool booked;

    public:
    const Time& getTime() const;
    unsigned int getAppointeeID() const;
    bool getBooked() const;

    void setTime(Time time);
    void setAppointeeID(unsigned int ID);
    void setBooked();

    Appointment();
    Appointment(Time time, unsigned int ID);

    bool operator==(const Appointment &RHS) const;
    bool operator!=(const Appointment &RHS) const;
    friend ostream& operator<<(ostream& out, const Appointment& appointment);
};

class Day {
    Date date;
    list<Appointment> appointmentList;
    bool allocated;

    Appointment& refAppointmentByTime(Time time);

    public:
    const Date& getDate() const;
    const Appointment& getAppointmentByID(unsigned int ID) const;
    const Appointment& getAppointmentByTime(Time time) const;
    bool getAllocated();
    unsigned int getAppointmentsPerDay();
    const Time& getOpeningTime();
    const Time& getClosingTime();

    void setDate(Date date);
    void setAllocated();
    void setAppointment(Time time, unsigned int ID);

    Day();

    bool checkAppointmentByID(unsigned int ID);
    void regenSchedule(unsigned int appointmentsPerDay, Time startTime);
    void setAppointment(unsigned int ID, Time time);
    bool operator==(const Day &RHS) const;
    bool operator!=(const Day &RHS) const;
    friend ostream& operator<<(ostream& out, const Day& day);
};

class Shipment {
    Date expiry;
    unsigned int quantity;
    unsigned int index;

    public:
    const Date& getExpiry() const;
    unsigned int getQuantity();
    unsigned int getIndex();

    void setExpiry(Date exp);
    void setQuantity(unsigned int qty);
    void setIndex(unsigned int index);

    Shipment();
    Shipment(Date exp, unsigned int qty, unsigned int index);

    void reduceQuantity();
};

class Vaccine {
    unsigned int tag;
    string company;
    unsigned int dosesRequired;
    Date bestBefore;
    list<Shipment> shipmentList;
    bool available;

    Shipment& refBestShipment();
    Shipment& refShipmentByIndex(unsigned int index);

    public:
    unsigned int getTag() const;
    const string& getCompany();
    unsigned int getDosesRequired();
    const Date& getBestBefore();
    bool getAvailable();

    void setTag(unsigned int tg);
    void setCompany(string cmp);
    void setDosesRequired(unsigned int req);
    void setBestBefore(Date best);
    void setAvailable();

    Vaccine();
    Vaccine(unsigned int tag, string company, unsigned int dosesReq, Date bestBefore);

    const Shipment& getBestShipment();
    const Shipment& getShipmentByIndex(unsigned int index);

    void restock(unsigned int qty, Date currDate, unsigned int idx);
};

class Customer {
    unsigned int ID;
    unsigned int PIN;
    string name;
    bool onDose;
    unsigned int tag;
    unsigned int dosesTaken;

    public:
    unsigned int getID();
    unsigned int getPIN() const;
    const string& getName() const;
    bool getOnDose() const;
    unsigned int getTag();
    unsigned int getDosesTaken() const;

    void setID(unsigned int ID);
    void setPIN(unsigned int PIN);
    void setName(string name);
    void setOnDose();
    void setTag(unsigned int tg);
    void setDosesTaken(unsigned int doses);

    Customer();
    Customer(unsigned int ID, unsigned int PIN, string name);
};

class Centre {
    string name;
    string address;
    unsigned int logged;
    unsigned int allocatedDays;
    unsigned int appointmentsPerDay;
    Time startTime;
    list<Day> dayList;
    list<Customer> customerList;
    list<Vaccine> vaccineList;
    Time currTime;
    Date currDate;

    Day& refDayByDate(Date date);
    Customer& refCustomerByID(unsigned int ID);
    Vaccine& refVaccineByTag(unsigned int tag);

    void realizeAppointments();

    public:
    const string& getName();
    const string& getAddress();

    void setName(string name);
    void setAddress(string address);
    
    void setAllocatedDays(unsigned int allocatedDays);
    void setAppointmentsPerDay(unsigned int appointmentsPerDay);
    void setStartTime(Time startTime);

    void setAppointment(Date date, Time time, unsigned int ID);
    
    void addVaccine(Vaccine vac);
    void startDose(unsigned int ID, unsigned int tag);

    Centre();
    Centre(string name, string address, unsigned int allocatedDays, unsigned int appointmentsPerDay, Time startTime);

    const Customer& getCustomerByID(unsigned int ID);
    bool authorizeLogin(unsigned int ID);
    void addCustomer(unsigned int login, unsigned int password, string name);

    const Day& getDayByID(unsigned int ID);
    const Day& getDayByDate(Date date);
    bool checkDayByID(unsigned int ID);
    bool checkAppointmentByID(unsigned int ID);
    bool checkAppointmentByTime(Date date, Time time);
    void regenSchedule(unsigned int allocatedDays, Date startDate, unsigned int appointmentsPerDay, Time startTime);

    const Vaccine& getVaccineByTag(unsigned int tag);
    const Vaccine& getBestVaccine();

    void startPage();
    void loginPage();
    void registerPage();
    void menuPage();
    void myAppointmentsPage();
    void newAppointmentsPage();
};

//Global function to input and verify Integers
unsigned int inputInt(unsigned int a, unsigned int b, istream& in);
Date inputDate(istream& in);
Time inputTime(istream& in);