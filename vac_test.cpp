#include "vac.hpp"

bool checkTime(Time time, unsigned int hour, unsigned int minute) {
    if(time.getHour() == hour && time.getMinute() == minute)
        return true;

    return false;
}

bool checkDate(Date date, unsigned int day, unsigned int month, unsigned int year) {
    if(date.getDay() == day && date.getMonth() == month && date.getYear() == year)
        return true;

    return false;
}

bool checkAppointment(Appointment appointment, unsigned int ID, Time time, bool booked) {
    if(appointment.getAppointeeID() == ID && appointment.getTime() == time && appointment.getBooked() == booked)
        return true;

    return false;
}

bool checkDay(Day day, Date date, bool allocated) {
    if(day.getDate() == date && day.getAllocated() == allocated)
        return true;

    return false;
}

bool checkShipment(Shipment shipment, Date exp, unsigned int qty) {
    if(shipment.getExpiry() == exp && shipment.getQuantity() == qty)
        return true;

    return false;
}

bool checkVaccine(Vaccine vaccine, unsigned int tag, string company, unsigned int dosesReq, Date bestBefore, bool available) {
    if(vaccine.getTag() == tag && vaccine.getCompany() == company && vaccine.getDosesRequired() == dosesReq && vaccine.getBestBefore() == bestBefore && vaccine.getAvailable() == available)
        return true;

    return false;
}

int main() {

cout << "Testing TIME class" << endl;
cout << "-- Checking Default constructor" << endl;
{
    Time timeTest;
    if(checkTime(timeTest, 0, 0))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking int constructor" << endl;
{
    Time timeTest(23, 55);
    if(checkTime(timeTest, 23, 55))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking setters" << endl;
{
    Time timeTest;

    try {
        timeTest.setHour(36);
        cout << "-- -- NOT WORKING" << endl;
    }

    catch(invalid_argument &error) {
        cout << "-- -- OK -- " << error.what() << endl;
    }

    try {
        timeTest.setMinute(75);
        cout << "-- -- NOT WORKING" << endl;
    }

    catch(invalid_argument & error) {
        cout << "-- -- OK -- " << error.what() << endl;
    }

    timeTest.setHour(8);
    timeTest.setMinute(30);
    if(checkTime(timeTest, 8, 30))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking == Operator" << endl;
{
    Time timeTest1;
    Time timeTest2;

    timeTest1.setHour(10);
    timeTest1.setMinute(15);

    timeTest2.setHour(10);
    timeTest2.setMinute(15);

    if(timeTest1 == timeTest2)
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking << Operator" << endl;
{
    Time timeTest(12, 30);

    stringstream out;
    out << timeTest;

    if(out.str() == "12:30")
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking increaseQuarter" << endl;
{
    Time timeTest;

    timeTest.setHour(10);
    timeTest.setMinute(5);
    timeTest.increaseQuarter();

    if(checkTime(timeTest, 10, 20))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;

    timeTest.setHour(10);
    timeTest.setMinute(55);
    timeTest.increaseQuarter();

    if(checkTime(timeTest, 11, 10))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

/*----------------------------------------------------------------------------------------------------------------------------*/

cout << "Testing DATE class" << endl;
cout << "-- Checking Default constructor" << endl;
{
    Date dateTest;
    if(checkDate(dateTest, 0, 0, 0))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking int constructor" << endl;
{
    Date dateTest(4, 4, 2002);
    if(checkDate(dateTest, 4, 4, 2002))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking setters" << endl;
{
    Date dateTest;

    try {
        dateTest.setDay(40);
        cout << "-- -- NOT WORKING" << endl;
    }

    catch(invalid_argument &error) {
        cout << "-- -- OK -- " << error.what() << endl;
    }

    try {
        dateTest.setMonth(15);
        cout << "-- -- NOT WORKING" << endl;
    }

    catch(invalid_argument &error) {
        cout << "-- -- OK -- " << error.what() << endl;
    }

    dateTest.setMonth(12);
    dateTest.setDay(15);
    dateTest.setYear(3030);
    if(checkDate(dateTest, 15, 12, 3030))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking = Operator" << endl;
{
    Date dateTest1(4, 4, 2002);
    Date dateTest2 = dateTest1;

    if(checkDate(dateTest2, 4, 4, 2002))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking + Operator" << endl;
{
    Date dateTest1(10, 10, 2002);
    Date dateTest2(19, 1, 0);
    Date dateTest = dateTest1 + dateTest2;

    if(checkDate(dateTest, 29, 11, 2002))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking == Operator" << endl;
{
    Date dateTest1(10, 10, 2002);
    Date dateTest2(10, 10, 2002);

    if(dateTest1 == dateTest2)
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking << Operator" << endl;
{
    Date dateTest(15, 12, 2077);

    stringstream out;
    out << dateTest;

    if(out.str() == "15-12-2077")
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

/*----------------------------------------------------------------------------------------------------------------------------*/

cout << "Testing APPOINTMENT class" << endl;
cout << "-- Checking Default constructor" << endl;
{
    Appointment appointmentTest;
    Time timeTest;
    if(checkAppointment(appointmentTest, 0, timeTest, false))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking int constructor" << endl;
{
    Time timeTest;
    Appointment appointmentTest(timeTest, 5000);
    if(checkAppointment(appointmentTest, 5000, timeTest, false))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking setters" << endl;
{
    Appointment appointmentTest;
    Time timeTest;

    appointmentTest.setAppointeeID(1234);
    appointmentTest.setBooked();
    if(checkAppointment(appointmentTest, 1234, timeTest, true))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking << Operator" << endl;
{
    Time timeTest;
    Appointment appointmentTest(timeTest, 4004);

    stringstream out;
    out << appointmentTest;

    if(out.str() == "00:00 X")
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

/*----------------------------------------------------------------------------------------------------------------------------*/

cout << "Testing DAY class" << endl;
cout << "-- Checking Default constructor" << endl;
{
    Day dayTest;
    Date dateTest;
    if(checkDay(dayTest, dateTest, false))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking setters" << endl;
{
    Day dayTest;
    Date dateTest(20, 9, 1999);

    dayTest.setDate(dateTest);
    dayTest.setAllocated();
    if(checkDay(dayTest, dateTest, true))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking regenSchedule" << endl;
{
    Day dayTest;
    Time timeTest;

    dayTest.regenSchedule(50, timeTest);
    if(dayTest.getAppointmentsPerDay() == 50)
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;

    if(!dayTest.getAppointmentByTime(timeTest).getBooked())
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;

    timeTest.setHour(12);
    timeTest.setMinute(15);
    if(!dayTest.getAppointmentByTime(timeTest).getBooked())
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;

    timeTest.setMinute(30);
    try {
        cout << dayTest.getAppointmentByTime(timeTest).getTime() << "-- -- NOT WORKING" << endl;
    }

    catch(invalid_argument &error) {
        cout << "-- -- OK -- " << error.what() << endl;
    }
}

cout << "-- Checking setAppointment" << endl;
{
    Day dayTest;
    Time timeTest(2, 15);
    dayTest.regenSchedule(10, timeTest);

    dayTest.setAppointment(4567, timeTest);

    if(dayTest.getAppointmentByID(4567).getTime() == timeTest)
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;

    if(dayTest.getAppointmentByTime(timeTest).getAppointeeID() == 4567)
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking checkAppointmentByID" << endl;
{
    Day dayTest;
    Time timeTest;
    
    dayTest.regenSchedule(8, timeTest);

    timeTest.setMinute(45);
    dayTest.setAppointment(9000, timeTest);

    if(dayTest.checkAppointmentByID(9000))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking << Operator" << endl;
{
    Day dayTest;
    Time timeTest(12, 0);

    dayTest.regenSchedule(2, timeTest);

    stringstream out;
    out << dayTest;

    if(out.str() == "12:00 O\n12:15 O\n")
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << dayTest << endl;
}

/*----------------------------------------------------------------------------------------------------------------------------*/

cout << "Testing SHIPMENT class" << endl;
cout << "-- Checking Default constructor" << endl;
{
    Shipment shipmentTest;
    Date dateTest;
    if(checkShipment(shipmentTest, dateTest, false))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking int constructor" << endl;
{
    Date dateTest(27, 5, 2021);
    Shipment shipmentTest(dateTest, 1000);
    if(checkShipment(shipmentTest, dateTest, 1000))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking setters" << endl;
{
    Date dateTest;
    Shipment shipmentTest;

    shipmentTest.setExpiry(dateTest);
    shipmentTest.setQuantity(10);

    if(checkShipment(shipmentTest, dateTest, 10))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking settersreduceQuantity" << endl;
{
    Date dateTest;
    Shipment shipmentTest(dateTest, 101);

    shipmentTest.reduceQuantity();

    if(checkShipment(shipmentTest, dateTest, 100))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

/*----------------------------------------------------------------------------------------------------------------------------*/

cout << "Testing VACCINE class" << endl;
cout << "-- Checking Default constructor" << endl;
{
    Vaccine vaccineTest;
    Date dateTest;

    if(checkVaccine(vaccineTest, 0, "None", 0, dateTest, false))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking int constructor" << endl;
{
    Date dateTest;
    Vaccine vaccineTest(9000, "I can't let you do that", 1, dateTest);

    if(checkVaccine(vaccineTest, 9000, "I can't let you do that", 1, dateTest, false))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}

cout << "-- Checking setters" << endl;
{
    Date dateTest;
    Vaccine vaccineTest;

    vaccineTest.setTag(420);
    vaccineTest.setCompany("Bharat Biotech");
    vaccineTest.setDosesRequired(2);
    vaccineTest.setBestBefore(dateTest);
    vaccineTest.setAvailable();

    if(checkVaccine(vaccineTest, 420, "Bharat Biotech", 2, dateTest, true))
        cout << "-- -- OK" << endl;

    else
        cout << "-- -- NOT WORKING" << endl;
}



}