# VaccinationCentreCLI
The CLI works as a scheduling and information database for a particular Covid-19 Vaccination Centre. There are separate data models with data about customers, vaccines & calendar appointments with vaccines further split into shipments and calendar dates further split into appointments with one-to-many cascading relations between them. In addition to these there are also specif classes for Date and Time management. Once the utility is set up by the centre, a user is be able to signup and login into the software using a user-generated ID and PIN and once logged in, can check the status of their upcoming appointments and make appointments to get vaccinated. The Centre class serves as the main class for the application and we create only one instance of it. The vaccineList & customerList hold available vaccines and registered customers respectively. The dayList holds upcoming calendar dates which further hold the appointments which are generated using data given by the Vaccination Centre, as the appointment is reached, relevant changes to the details of the customer as well as the quantity of vaccine are made by the software.

## Usage
For compiling the app:
```
g++ UI.cpp vac.cpp -o vac
```
For compiling the tests:
```
g++ vac_test.cpp vac.cpp -o vac_test
```

## Class Diagram
![UML Diagram](https://raw.githubusercontent.com/Duke0404/VaccinationCentreCLI/main/Classes.png)

## Class Descriptions
### Centre
Serving as the main class of the program, the centre class is instantiated in the UI.cpp file and holds all of the data of the Vaccination centre, namely the records of customers, vaccines and deatils of each allocated day in the form of STL lists. It all of it's methods have are made with the purpose of retrieving or modifying data in these lists. In addition to this, the Centre class also holds the methoda that are used to display the UI of the CLI.

### Customer
This class works as an instance of a customer in the Vaccination centre and thus holds all of the data relevant to a customer including their personal details and details about whether they have been assigned a dose, their vaccine of choice & how many doses they have already been given.

### 
