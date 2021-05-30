#include "vac.hpp"

int inputInt() {
    int input;

    cin >> input;
        while(true) {
            if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '/n');
                cout << "Invalid input, try again" << endl;
                cin >> input;
            }
            
            else
                break;
        }

    return input;
}

int inputInt(int a, int b) {
    int input;

    cin >> input;
        while(true || input < a || input > b) {
            if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '/n');
                cout << "Invalid input, try again" << endl;
                cin >> input;
            }
            
            else
                break;
        }

    return input;
}

//AppointmentList

AppointmentList::AppointmentList() {
    table = nullptr;
    appointmentsPerDay = 0;
    daysAllocated = 0;
    bookedSlots = 0;
}

void AppointmentList::allocate(int appointmentsPerDay, int daysAllocated) {
    this->appointmentsPerDay = appointmentsPerDay;
    this->daysAllocated = daysAllocated;
}

void AppointmentList::addAppointment(int appointee) {
    Appointment* temp = new Appointment[bookedSlots];
    for(int i = 0; i < bookedSlots; i++) {
        temp[i] = table[i];
    }

    table = new Appointment[bookedSlots + 1];

    for(int i = 0; i < bookedSlots; i++) {
        table[i] = temp[i];
    }

    table[bookedSlots++] = {appointee};
}

Appointment AppointmentList::findByID(int ID) {
    for(int i = 0; i < bookedSlots; i++) {
        if(table[i].appointeeID == ID) {
            return table[i];
        }
    }

    throw invalid_argument("Customer with this ID does not have ab appointment");
}

Appointment AppointmentList::findByIndex(int n) {
    return table[n];
}

int AppointmentList::getAppointmentNumber(int ID) {
    return bookedSlots % appointmentsPerDay;
}

int AppointmentList::getAppointmentDay(int ID) {
    return bookedSlots / appointmentsPerDay;
}

int AppointmentList::getbookedSlots() {
    return bookedSlots;
}

//VaccineList

VaccineList::VaccineList() {
    vaccinesAvailable = 0;
    table = nullptr;
}

void VaccineList::printTable() {
    cout << "Select one of the available vaccines, number of doses in curly brackets" << endl;

    for(int i = 0; i < vaccinesAvailable; i++) {
        cout << "(" << i+1 << ")" << table[i].dosesAvailable << "{" << table[i].dosesRequired << endl;
    }
}

void VaccineList::addVaccine(int ID, string name, int dosesRequired, int dosesAvailable) {
    Vaccine* temp = new Vaccine[vaccinesAvailable];
    for(int i = 0; i < vaccinesAvailable; i++) {
        temp[i] = table[i];
    }

    table = new Vaccine[vaccinesAvailable + 1];

    for(int i = 0; i < vaccinesAvailable; i++) {
        table[i] = temp[i];
    }

    table[vaccinesAvailable++] = {ID, name, dosesRequired, dosesAvailable};
}

void VaccineList::addVaccine(Vaccine vac) {
    Vaccine* temp = new Vaccine[vaccinesAvailable];
    for(int i = 0; i < vaccinesAvailable; i++) {
        temp[i] = table[i];
    }

    table = new Vaccine[vaccinesAvailable + 1];

    for(int i = 0; i < vaccinesAvailable; i++) {
        table[i] = temp[i];
    }

    table[vaccinesAvailable++] = {vac.ID, vac.name, vac.dosesRequired, vac.dosesAvailable};
}

Vaccine VaccineList::findByID(int ID) {
    for(int i = 0; i < vaccinesAvailable; i++) {
        if(table[i].ID == ID) {
            return table[i];
        }
    }

    throw invalid_argument("Vaccine with this ID is not available");
}

Vaccine VaccineList::findByIndex(int n) {
    return table[n];
}

int VaccineList::getvaccinesAvailable() {
    return vaccinesAvailable;
}

//CustomerList

void CustomerList::addCustomer(int ID, int PIN, string name) {
    Customer* temp = new Customer[totalCustomers];
    for(int i = 0; i < totalCustomers; i++) {
        temp[i] = table[i];
    }

    table = new Customer[totalCustomers + 1];

    for(int i = 0; i < totalCustomers; i++) {
        table[i] = temp[i];
    }

    table[totalCustomers++] = {ID, PIN, name, false, 0, 0};
}

void CustomerList::assignVaccine(int ID, int vaccine) {
    table[getIndexByID(ID)].onDose = true;
    table[getIndexByID(ID)].vaccineID = vaccine;
}

Customer CustomerList::findByID(int ID) {
    for(int i = 0; i < totalCustomers; i++) {
        if(table[i].ID == ID) {
            return table[i];
        }
    }

    throw invalid_argument("Customer with this ID is not available");
}

Customer CustomerList::findByIndex(int n) {
    return table[n];
}

int CustomerList::gettotalCustomers() {
    return totalCustomers;
}

int CustomerList::getIndexByID(int ID) {
    for(int i = 0; i < totalCustomers; i++) {
        if(table[i].ID == ID) {
            return i;
        }
    }

    throw invalid_argument("Customer with this ID is not available");
}

CustomerList::CustomerList() {
    totalCustomers = 0;
    table = nullptr;
}

//VaccinationCentre

VaccinationCentre::VaccinationCentre(string name, string address, int capacityPerDay, int vaccinesAvailable) {
    logged = 0;
    this->name = name;
    this->address = address;
    this->capacityPerDay = capacityPerDay;
}

void VaccinationCentre::newVaccine(int ID, string name, int dosesRequired, int dosesAvailable) {
    vaccineList.addVaccine(ID, name, dosesRequired, dosesAvailable);
}

void VaccinationCentre::printInfo() {
    cout
    << name << endl
    << "Address: " << address << endl
    << "Slots available per day:" << capacityPerDay << endl;
}

// Vaccine VaccinationCentre::inputVaccine() {
//     Vaccine temp;

//     cout
//     << "Input a new vaccine" << endl
//     << "Name: ";
//     cin >> temp.name;
//     cout << endl;

//     cout << "ID: ";
//     temp.ID = inputInt();
//     cout << endl;

//     cout << "Number of Doses the vaccine requires: ";
//     temp.dosesRequired = inputInt();
//     cout << endl;

//     return temp;
// }

// VaccineList VaccinationCentre::getvaccineList() {
//     return vaccineList;
// }

bool VaccinationCentre::authorizeLogin(int ID) {
    for(int i = 0; i < customerList.gettotalCustomers(); i++) {
        if(customerList.findByIndex(i).ID == ID) {
            return true;
        }
    }

    return false;
}

bool VaccinationCentre::appointmentMade(int ID) {
    for(int i = 0; i < appointmentList.getbookedSlots(); i++) {
        if(customerList.findByIndex(i).ID == ID) {
            return true;
        }
    }

    return false;
}

void VaccinationCentre::startPage() {
    cout << "START PAGE" << endl
    << "Enter number of the desired menu item" << endl
    << "(1) login" << endl
    << "(2) register";

    switch(inputInt(1, 2)) {
        case 1:
            loginPage();
            break;
        case 2:
            registerPage();
            break;           
    }
}

 void VaccinationCentre::loginPage() {
    int login, password;

    cout << "LOGIN PAGE" << endl
    << "login:";

    login = inputInt(1, 10000);

    if(!authorizeLogin(login)) {
        cout << "LoginID not found";
        startPage();
    }

    else {
        logged = login;

        cout << "Welcome" << customerList.findByID(logged).name << endl
        << "PIN:";
        password = inputInt();

        if(!(password = customerList.findByID(logged).PIN)) {
            cout << "Incorrect PIN";
            startPage();
        }

        else {
            menuPage();
        }
    }
 }

void VaccinationCentre::registerPage() {
    int login, password;
    string name;

    cout << "REGISTER PAGE" << endl
    << "login:";
    login = inputInt(1, 10000);

    cout << "PIN:";
    password = inputInt();

    cout << "Name:";
    cin >> name;

    customerList.addCustomer(login, password, name);

    cout << "Your details have been stored";

    loginPage();
}

 void VaccinationCentre::menuPage() {
    cout << "MENU PAGE" << endl
    << "Welcome to the " << getname() << " vaccination appointmnt system" << endl
    << "Enter number of the desired menu item" << endl
    << "(1) My appointments" << endl
    << "(2) Get vaccine appointment" << endl
    << "(n) n";

    switch(inputInt(1, 2)) {
        case 1:
            myAppointmentsPage();
            break;

        case 2:
            newAppointmentPage();        
    } 
 }

 void VaccinationCentre::myAppointmentsPage() {
    if(!appointmentMade(logged)) {
        cout << "You do not have any upcoming appointments";
    }

    else {
        cout << "You have an appointment in slot " << appointmentList.getAppointmentNumber(logged) << "in " << appointmentList.getAppointmentDay(logged) << " days.";
    }

    menuPage();
 }

void VaccinationCentre::newAppointmentPage() {
    if(appointmentMade(logged)) {
        cout << "You already have an upcoming appointment";
    }

    else {
        if(vaccineList.getvaccinesAvailable() == 0) {
            cout << "No Vaccines available right now, try again later";
        }

        else if(vaccineList.getvaccinesAvailable() == 1) {
            appointmentList.addAppointment(logged);
            customerList.assignVaccine(logged, vaccineList.findByIndex(0).ID);

            cout << "Appointment obtained";
        }

        else {
            vaccineList.printTable();
            int input = inputInt(1, vaccineList.getvaccinesAvailable());
            appointmentList.addAppointment(logged);
            customerList.assignVaccine(logged, vaccineList.findByIndex(input - 1).ID);

            cout << "Appointment obtained";
        }
    }

    menuPage();
}

string VaccinationCentre::getname() {
    return name;
}