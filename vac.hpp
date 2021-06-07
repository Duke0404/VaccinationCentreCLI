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
    unsigned int getMinute();
    unsigned int getHour();

    void setMinute(unsigned int min);
    void setHour(unsigned int hou);

    Time();
    Time(unsigned int hour, unsigned int minute);

    void increaseQuarter();

    bool operator==(const Time &RHS) const;
    friend ostream& operator<<(ostream& out, const Time& time);
};

class Date {
    unsigned int day;
    unsigned int month;
    unsigned int year;

    public:
    unsigned int getDay();
    unsigned int getMonth();
    unsigned int getYear();

    void setDay(unsigned int day);
    void setMonth(unsigned int month);
    void setYear(unsigned int year);

    Date();
    Date(unsigned int day, unsigned int month, unsigned int year);

    Date& operator=(const Date& RHS);
    Date operator+(const Date& RHS);
    Date& operator++();
    bool operator==(const Date& RHS) const;
    bool operator!=(const Date& RHS) const;
    friend bool operator<(const Date& LHS, const Date& RHS);
    friend bool operator>(const Date& LHS, const Date& RHS);
    friend ostream& operator<<(ostream& out, const Date& date);
};

class Appointment {
    Time time;
    unsigned int appointeeID;
    bool booked;

    public:
    Time getTime() const;
    unsigned int getAppointeeID();
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
    Date getDate();
    Appointment getAppointmentByID(unsigned int ID);
    Appointment getAppointmentByTime(Time time);
    bool getAllocated();
    unsigned int getAppointmentsPerDay();

    void setDate(Date date);
    void setAllocated();

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

    public:
    Date getExpiry();
    unsigned int getQuantity();

    void setExpiry(Date exp);
    void setQuantity(unsigned int qty);

    Shipment();
    Shipment(Date exp, unsigned int qty);

    void reduceQuantity();
};

class Vaccine {
    unsigned int tag;
    string company;
    unsigned int dosesRequired;
    Date bestBefore;
    list<Shipment> shipmentList;
    bool available;

    public:
    unsigned int getTag();
    string getCompany();
    unsigned int getDosesRequired();
    Date getBestBefore();
    bool getAvailable();

    void setTag(unsigned int tg);
    void setCompany(string cmp);
    void setDosesRequired(unsigned int req);
    void setBestBefore(Date best);
    void setAvailable();

    Vaccine();
    Vaccine(unsigned int tag, string company, unsigned int dosesReq, Date bestBefore);

    void restock(unsigned int qty, Date currDate);

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
    unsigned int getPIN();
    string getName();
    bool getOnDose();
    unsigned int getTag();
    unsigned int getDosesTaken();

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

    public:
    string getName();
    string getAddress();

    void setName(string name);
    void setAddress(string address);
    
    void setAllocatedDays(unsigned int allocatedDays);
    void setAppointmentsPerDay(unsigned int appointmentsPerDay);
    void setStartTime(Time startTime);

    Centre();
    Centre(string name, string address, unsigned int allocatedDays, unsigned int appointmentsPerDay, Time startTime);

    Customer getCustomerByID(unsigned int ID);
    bool authorizeLogin(unsigned int ID);
    void addCustomer(unsigned int login, unsigned int password, string name);

    Day getDayByID(unsigned int ID);
    Day getDayByDate(Date date);
    bool checkAppointmentByID(unsigned int ID);
    bool checkAppointmentByTime(Date date, Time time);
    void regenSchedule(unsigned int allocatedDays, Date startDate, unsigned int appointmentsPerDay, Time startTime);

    void startPage();
    void loginPage();
    void registerPage();
    void menuPage();
    void myAppointmentsPage();
    void newAppointmentsPage();
};

//Universal function to input and verify Integers
unsigned int inputInt(unsigned int a, unsigned int b, istream& in);
Date inputDate(istream& in);
Time inputTime(istream& in);