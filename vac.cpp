#include "vac.hpp"

unsigned int Time::getMinute() {
    return minute;
}

unsigned int Time::getHour() {
    return hour;
}

void Time::setMinute(unsigned int min) {
    if(min > 60)
        throw invalid_argument("Minutes Cannot be greater than 59");
    
    minute = min;

    
}


void Time::setHour(unsigned int hou) {
    if(hou > 24)
        throw invalid_argument("Hours Cannot be greater than 23");
    
    hour = hou;
}

Time::Time() {
    minute = 0;
    hour = 0;
}

Time::Time(unsigned int hour, unsigned int minute) {
    setHour(hour);
    setMinute(minute);
}

bool Time::operator==(const Time& RHS) const{
    return hour == RHS.hour && minute == RHS.minute;
}

void Time::increaseQuarter() {
    if(minute >= 45) {
        ++hour;
        minute -= 45;
    }

    else
        minute += 15;
}

ostream& operator<<(ostream& out, const Time& time) {
    out << (time.hour < 10 ? "0": "") << time.hour << ":" << (time.minute < 10 ? "0": "") << time.minute;
    return out;
}

/*----------------------------------------------------------------------------------------------------------------------------*/

unsigned int Date::getDay() {
    return day;
}

unsigned int Date::getMonth() {
    return month;
}

unsigned int Date::getYear() {
    return year;
}

void Date::setDay(unsigned int day) {
    if(month == 2 && day > 28)
        throw invalid_argument("Feb cannot have more than 28 days");

    else if(month == (1 || 3 || 5 || 7 || 8 || 10 || 12) && day > 31)
        throw invalid_argument("This month cannot have more than 31 days");

    else if(month == (4 || 6 || 9 || 11) && day > 30)
        throw invalid_argument("This month cannot have more than 30 days");

    else if(month == 0 && day != 0)
        throw invalid_argument("Set month first");

    this->day = day;
}

void Date::setMonth(unsigned int month) {
    if(month > 12)
        throw invalid_argument("Months Cannot be greater than 12");

    this->month = month;
}

void Date::setYear(unsigned int year) {
    this->year = year;
}

Date::Date() {
    month = 0;
    day = 0;
    year = 0;
}

Date::Date(unsigned int day, unsigned int month, unsigned int year) {
    setMonth(month);
    setDay(day);
    setYear(year);
}

Date& Date::operator=(const Date& RHS) {
    setMonth(RHS.month);
    setDay(RHS.day);
    setYear(RHS.year);

    return *this;
}

Date Date::operator+(const Date& RHS) {
    unsigned int tempYear =  year + RHS.year;

    unsigned int tempMonth =  month + RHS.month;
    if(tempMonth > 12) {
        ++tempYear;
        tempMonth -= 12;
    }

    unsigned int tempDay =  day + RHS.day;
    if(month == 2 && day > 28) {
        ++tempMonth;
        tempDay -= 28;
    }

    else if(month == (1 || 3 || 5 || 7 || 8 || 10 || 12) && day > 31) {
        ++tempMonth;
        tempDay -= 31;
    }

    else if(month == (4 || 6 || 9 || 11) && day > 30) {
        ++tempMonth;
        tempDay -= 30;
    }
    
    Date result(tempDay, tempMonth, tempYear);
    return result;
}

Date& Date::operator++() {
    if(month == 2 && day == 28) {
        ++month;
        day = 1;
    }

    else if(month == (1 || 3 || 5 || 7 || 8 || 10) && day == 31) {
        ++month;
        day = 1;
    }

    else if(month == (4 || 6 || 9 || 11) && day == 30) {
        ++month;
        day = 1;
    }

    else if(month == 12 && day == 31) {
        ++year;
        month = 1;
        day = 1;
    }

    ++day;

    return *this;
}

bool Date::operator==(const Date& RHS) const {
    return (day == RHS.day) && (month == RHS.month) && (year == RHS.year);
}

bool Date::operator!=(const Date& RHS) const {
    return !(day == RHS.day && month == RHS.month && year == RHS.year);
}

bool operator<(const Date& LHS, const Date& RHS) {
    if(LHS.year < RHS.year)
        return true;

    else if(LHS.year == RHS.year) {
        if(LHS.month < RHS.month)
            return true;

        else if(LHS.month == RHS.month) {
            if(LHS.day < RHS.day)
                return true;
        }
    }

    return false;
}

bool operator>(const Date& LHS, const Date& RHS) {
    if(LHS.year > RHS.year)
        return true;

    else if(LHS.year == RHS.year) {
        if(LHS.month > RHS.month)
            return true;

        else if(LHS.month == RHS.month) {
            if(LHS.day > RHS.day)
                return true;
        }
    }

    return false;
}

ostream& operator<<(ostream& out, const Date& date) {
    out << (date.day < 10 ? "0": "") << date.day << "-" << (date.month < 10 ? "0": "") << date.month << "-" << date.year;

    return out;
}

/*----------------------------------------------------------------------------------------------------------------------------*/

Time Appointment::getTime() const {
    return time;
}

unsigned int Appointment::getAppointeeID() {
    return appointeeID;
}

bool Appointment::getBooked() const{
    return booked;
}

void Appointment::setTime(Time time) {
    this->time = time;
}

void Appointment::setAppointeeID(unsigned int ID) {
    appointeeID = ID;
}

Appointment::Appointment() {
    appointeeID = 0;
    booked = false;
}

Appointment::Appointment(Time time, unsigned int ID) {
    setTime(time);
    setAppointeeID(ID);
    booked = true;
}

void Appointment::setBooked() {
    booked = !booked;
}

bool Appointment::operator==(const Appointment &RHS) const {
    return time == RHS.time && appointeeID == RHS.appointeeID && booked == RHS.booked;
}

bool Appointment::operator!=(const Appointment &RHS) const {
    return !(time == RHS.time && appointeeID == RHS.appointeeID && booked == RHS.booked);
}

ostream& operator<<(ostream& out, const Appointment& appointment) {
    out << appointment.time << (appointment.booked ? " X" : " O");

    return out;
}

/*----------------------------------------------------------------------------------------------------------------------------*/

Appointment& Day::refAppointmentByTime(Time time) {
    for(auto i = appointmentList.begin(); i != appointmentList.end(); ++i) {
        if ((*i).getTime() == time)
            return *i;
    }

    throw invalid_argument("No Appointment at given time");
}

Date Day::getDate() {
    return date;
}

Appointment Day::getAppointmentByID(unsigned int ID) {
    for(auto i = appointmentList.begin(); i != appointmentList.end(); ++i) {
        if ((*i).getAppointeeID() == ID)
            return *i;
    }

    throw invalid_argument("No Appointment with given ID");
}

Appointment Day::getAppointmentByTime(Time time) {
    for(auto i = appointmentList.begin(); i != appointmentList.end(); ++i) {
        if ((*i).getTime() == time)
            return *i;
    }

    throw invalid_argument("No Appointment at given time");
}

bool Day::getAllocated() {
    return allocated;
}

unsigned int Day::getAppointmentsPerDay() {
    return appointmentList.size();
}

void Day::setDate(Date date) {
    this->date = date;
}

void Day::setAllocated() {
    allocated = !allocated;
}

Day::Day() {
    allocated = false;
}

bool Day::checkAppointmentByID(unsigned int ID) {
    try {
        getAppointmentByID(ID);
        return true;
    }

    catch(invalid_argument &err) {
        return false;
    }
}

void Day::regenSchedule(unsigned int appointmentsPerDay, Time startTime) {
    Appointment temp;
    appointmentList.clear();

    for(unsigned int i = 0; i < appointmentsPerDay; ++i) {
        appointmentList.push_back(temp);
    }

    Time time = startTime;

    for(auto i = appointmentList.begin(); i != appointmentList.end(); ++i) {
        (*i).setTime(time);
        time.increaseQuarter();
    }
}

void Day::setAppointment(unsigned int ID, Time time) {
    if(getAppointmentByTime(time).getBooked())
        throw invalid_argument("Appointment slot is already booked");

    refAppointmentByTime(time).setAppointeeID(ID);
    refAppointmentByTime(time).setBooked();
}

bool Day::operator==(const Day &RHS) const {
    if(date != RHS.date || allocated != RHS.allocated || appointmentList.size() != RHS.appointmentList.size())
        return false;

    
    for(auto i = appointmentList.begin(), j = RHS.appointmentList.begin(); i != appointmentList.end() && j != appointmentList.end(); ++i, ++j) {
        if((*i) != (*j))
            return false;
    }

    return true;
}

bool Day::operator!=(const Day &RHS) const {
    if(date != RHS.date || allocated != RHS.allocated)
        return true;

    for(auto i = appointmentList.begin(), j = RHS.appointmentList.begin(); i != appointmentList.end() || j != appointmentList.end(); ++i, ++j) {
        if((*i) != (*j))
            return true;
    }

    return false;
}

ostream& operator<<(ostream& out, const Day& day) {
    out << day.date << endl;

    for(auto i = day.appointmentList.begin(); i != day.appointmentList.end(); ++i) {
        out << *i << endl;
    }

    return out;
}



/*----------------------------------------------------------------------------------------------------------------------------*/

Date Shipment::getExpiry() {
    return expiry;
}

unsigned int Shipment::getQuantity() {
    return quantity;
}

void Shipment::setExpiry(Date exp) {
    expiry = exp;
}

void Shipment::setQuantity(unsigned int qty) {
    quantity = qty;
}

Shipment::Shipment() {
    quantity = 0;
}

Shipment::Shipment(Date exp, unsigned int qty) {
    this->setExpiry(exp);
    this->setQuantity(qty);
}

void Shipment::reduceQuantity() {
    if(quantity == 0)
        throw out_of_range("Quantity cannot be reduced further");

    --quantity;
}

/*----------------------------------------------------------------------------------------------------------------------------*/

unsigned int Vaccine::getTag() {
    return tag;
}

string Vaccine::getCompany() {
    return company;
}

unsigned int Vaccine::getDosesRequired() {
    return dosesRequired;
}

Date Vaccine::getBestBefore() {
    return bestBefore;
}

bool Vaccine::getAvailable() {
    return available;
}

void Vaccine::setTag(unsigned int tg) {
    tag = tg;
}

void Vaccine::setCompany(string cmp) {
    company = cmp;
}

void Vaccine::setDosesRequired(unsigned int req) {
    if(req > 4)
        throw invalid_argument("Vaccine cannot have more than 4 doses");

    dosesRequired = req;
}

void Vaccine::setBestBefore(Date best) {
    bestBefore = best;
}

void Vaccine::setAvailable() {
    available = !available;
}

Vaccine::Vaccine() {
    tag = 0;
    company = "None";
    dosesRequired = 0;
    available = false;
}

Vaccine::Vaccine(unsigned int tag, string company, unsigned int dosesReq, Date bestBefore) {
    this->setTag(tag);
    this->setCompany(company);
    this->setDosesRequired(dosesReq);
    this->setBestBefore(bestBefore);
    available = false;
}

void Vaccine::restock(unsigned int qty, Date currDate) {
    Shipment temp(currDate + bestBefore, qty);
    shipmentList.push_back(temp);
}

/*----------------------------------------------------------------------------------------------------------------------------*/

unsigned int Customer::getID() {
    return ID;
}

unsigned int Customer::getPIN() {
    return PIN;
}

string Customer::getName() {
    return name;
}

bool Customer::getOnDose() {
    return onDose;
}

unsigned int Customer::getTag() {
    return tag;
}

unsigned int Customer::getDosesTaken() {
    return dosesTaken;
}

void Customer::setID(unsigned int ID) {
    if(ID > 9999)
        throw invalid_argument("ID cannot be more than 4 digits");

    this->ID = ID;
}

void Customer::setPIN(unsigned int PIN) {
    if(PIN > 9999)
        throw invalid_argument("PIN cannot be more than 4 digits");

    this->PIN = PIN;
}

void Customer::setName(string name) {
    this->name = name;
}

void Customer::setOnDose() {
    onDose = !onDose;
}

void Customer::setTag(unsigned int tg) {
    tag = tg;
}

void Customer::setDosesTaken(unsigned int doses) {
    if(doses > 3)
        throw invalid_argument("Customer cannot have taken more than 3 doses");

    dosesTaken = doses;
}

Customer::Customer() {
    ID = 0;
    PIN = 0;
    name = "None";
    onDose = false;
    tag = 0;
    dosesTaken = 0;
}

Customer::Customer(unsigned int ID, unsigned int PIN, string name) {
    this->setID(ID);
    this->setPIN(PIN);
    this->setName(name);
    this->setOnDose();
    this->setTag(0);
    this->setDosesTaken(0);
}

/*----------------------------------------------------------------------------------------------------------------------------*/

Day& Centre::refDayByDate(Date date) {
    for(auto i = dayList.begin(); i != dayList.end(); ++i) {
        if ((*i).getDate() == date)
            return *i;
    }

    throw invalid_argument("No Allocated Day at given Date");
}

Customer& Centre::refCustomerByID(unsigned int ID) {
    for(auto i = customerList.begin(); i != customerList.end(); ++i) {
        if ((*i).getID() == ID)
            return *i;
    }

    throw invalid_argument("No customer with given ID");
}

string Centre::getName() {
    return name;
}

string Centre::getAddress() {
    return address;
}

void Centre::setName(string name) {
    this->name = name;
}

void Centre::setAddress(string address) {
    this->address = address;
}

void Centre::setAllocatedDays(unsigned int allocatedDays) {
    this->allocatedDays = allocatedDays;
}

void Centre::setAppointmentsPerDay(unsigned int appointmentsPerDay) {
    if(appointmentsPerDay > 90)
        throw invalid_argument("There cannot be more than 90 appointments per day");

    this->appointmentsPerDay = appointmentsPerDay;
}

void Centre::setStartTime(Time startTime) {
    if(startTime.getHour() > 12)
        throw invalid_argument("Centre must open by 12 noon");

    this->startTime = startTime;
}

Centre::Centre() {
    name = "None";
    address = "None";
}

Centre::Centre(string name, string address, unsigned int allocatedDays, unsigned int appointmentsPerDay, Time startTime) {
    setName(name);
    setAddress(address);

    const time_t now = time(nullptr);
    const tm nowLocal = *localtime(addressof(now));

    currDate.setMonth(nowLocal.tm_mon + 1);
    currDate.setDay(nowLocal.tm_mday);
    currDate.setYear(nowLocal.tm_year + 1900);

    currTime.setHour(nowLocal.tm_hour);
    currTime.setMinute(nowLocal.tm_min);

    regenSchedule(allocatedDays, currDate, appointmentsPerDay, startTime);
}

Customer Centre::getCustomerByID(unsigned int ID) {
    for(auto i = customerList.begin(); i != customerList.end(); ++i) {
        if((*i).getID() == ID)
            return *i;
    }

    throw invalid_argument("No customer with such ID exists");
}

bool Centre::authorizeLogin(unsigned int ID) {
    try {
        getCustomerByID(ID);
        return true;
    }

    catch(invalid_argument &err) {
        return false;
    }
}

void Centre::addCustomer(unsigned int login, unsigned int password, string name) {
    Customer temp(login, password, name);

    customerList.push_back(temp);
}

Day Centre::getDayByID(unsigned int ID) {
    for(auto i = dayList.begin(); i != dayList.end(); ++i) {
        if((*i).checkAppointmentByID(ID))
            return *i;
    }

    throw invalid_argument("No customer with such ID exists");
}

Day Centre::getDayByDate(Date date) {
    return refDayByDate(date);
}

bool Centre::checkAppointmentByID(unsigned int ID) {
    try {
        getDayByID(ID).getAppointmentByID(ID);
        return true;
    }

    catch(invalid_argument& err) {
        return false;
    }
}

bool Centre::checkAppointmentByTime(Date date, Time time) {
    try {
        return !getDayByDate(date).getAppointmentByTime(time).getBooked();
    }

    catch(invalid_argument& err) {
        return false;
    }
}

void Centre::regenSchedule(unsigned int allocatedDays, Date startDate, unsigned int appointmentsPerDay, Time startTime) {
    Day temp;
    dayList.clear();

    for(unsigned int i = 0; i < allocatedDays; ++i) {
        dayList.push_back(temp);
    }

    Date date = startDate;

    for(auto i = dayList.begin(); i != dayList.end(); ++i) {
        (*i).setDate(date);
        (*i).regenSchedule(appointmentsPerDay, startTime);
        //(*i).setAllocated();
        ++date;
    }
}

void Centre::startPage() {
    cout << "START PAGE" << endl
    << "Enter number of the desired menu item" << endl
    << "(1) login" << endl
    << "(2) register" << endl
    << "---------------" << endl;

    switch(inputInt(1, 2, cin)) {
        case 1:
            cout << "---------------" << endl << endl;
            loginPage();
            break;
        case 2:
            cout << "---------------" << endl << endl;
            registerPage();
            break;       
    }
}

void Centre::loginPage() {
    int login, password;

    cout << "LOGIN PAGE" << endl
    << "login:" << endl
    << "---------------" << endl;
    login = inputInt(1, 9999, cin);
    cout << "---------------" << endl;

    if(!authorizeLogin(login)) {
        cout << "LoginID not found!" << endl << endl;
        startPage();
    }

    else {
        logged = login;

        cout << "Welcome " << getCustomerByID(logged).getName() << endl
        << "PIN" << endl
        << "---------------" << endl;
        password = inputInt(1, 999999, cin);
        cout << "---------------" << endl;
        

        if(!(password = getCustomerByID(logged).getPIN())) {
            cout << "Incorrect PIN" << endl;
            startPage();
        }

        else {
            cout << endl;
            menuPage();
        }
    }
}

void Centre::registerPage() {
    int login, password;
    string name;

    cout << "REGISTER PAGE" << endl
    << "Set LoginID" << endl
    << "---------------" << endl;
    login = inputInt(1, 9999, cin);
    cout << "---------------" << endl;

    cout << " Set PIN" << endl
    << "---------------" << endl;
    password = inputInt(1, 999999, cin);
    cout << "---------------" << endl;

    cout << "Name" << endl
    << "---------------" << endl;
    cin >> name;
    cout << "---------------" << endl;

    addCustomer(login, password, name);

    cout << "Your details have been stored" << endl << endl;

    loginPage();
}

void Centre::menuPage() {
    cout << "MENU PAGE" << endl
    << "Welcome to the " << getName() << " vaccination appointmnt system" << endl
    << "Enter number of the desired menu item" << endl
    << "(1) My appointments" << endl
    << "(2) Get vaccine appointment" << endl
    << "(3) Change Name" << endl
    << "(4) Change Login ID" << endl
    << "(5) Change PIN" << endl
    << "(6) Logout" << endl
    << "(7) Quit" << endl
    << "---------------" << endl;

    switch(inputInt(1, 7, cin)) {
        case 1:
            cout << "---------------" << endl;
            myAppointmentsPage();
            break;

        case 2:
            cout << "---------------" << endl;
            newAppointmentsPage();
            break;

        case 6:
            cout << "---------------" << endl;
            startPage();
            break; 

        case 7:
            cout << "---------------" << endl
            << "Thanks for getting Vaccinated! Goodbye.";
            break; 
    } 
}

void Centre::myAppointmentsPage() {
    cout << "MY APPOINTMENTS" << endl;

    if(checkAppointmentByID(logged))
        cout << getDayByID(logged).getDate() << " - " << getDayByID(logged).getAppointmentByID(logged).getTime() << endl << endl;

    else
        cout << "You do not have any scheduled appointments" << endl << endl;

    menuPage();
}

void Centre::newAppointmentsPage() {
    Date selectDate;
    Time selectTime;

    cout << "BOOK APPOINTMENT" << endl;

    for(auto i = dayList.begin(); i != dayList.end(); ++i) {
        cout << *i << endl;
    }

    do {
        cout << "Enter date of appointment in \"dd-mm-yyyy\" format" << endl
        << "---------------" << endl;
        selectDate = inputDate(cin);
        cout << "---------------" << endl;

        cout << "Enter time of appointment in \"hh:mm\" format" << endl
        << "---------------" << endl;
        selectTime = inputTime(cin);
        cout << "---------------" << endl;

        if(checkAppointmentByTime(selectDate, selectTime))
            break;

        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Please enter slot details of available slot " << endl;
        }
    }

    while(true);
}

unsigned int inputInt(unsigned int a, unsigned int b, istream& in) {
    unsigned int input;
    do {
        in >> input;

        if (cin.good() && input >= a && input <= b)
            break;

        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Please enter a number between "<< a << " & " << b << endl;
        }
    }
    
    while (true);

    return input;
}

Date inputDate(istream& in) {
    Date result;
    string temp;
    unsigned int day, month, year;

    do {
        in >> temp;

        try{
            day = stoi(temp.substr(0, 2));
            month = stoi(temp.substr(3, 2));
            year = stoi(temp.substr(6, 2));

            result.setYear(year);
            result.setMonth(month);
            result.setDay(day);

            break;
        }

        catch(invalid_argument &error) {
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << error.what();
        }
    }
    
    while (true);

    return result;
}

Time inputTime(istream& in) {
    Time result;
    string temp;
    unsigned int hour, min;

    do {
        in >> temp;

        try{
            hour = stoi(temp.substr(0, 2));
            min = stoi(temp.substr(3, 2));

            result.setHour(hour);
            result.setMinute(min);

            break;
        }

        catch(invalid_argument &error) {
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << error.what();
        }
    }
    
    while (true);

    return result;
}