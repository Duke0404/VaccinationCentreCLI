# VaccinationCentreCLI
The CLI works as a scheduling and information database for a particular Covid-19 Vaccination Centre. There are separate data models with data about customers, vaccines & calendar appointments with vaccines further split into shipments and calendar dates further split into appointments with one-to-many cascading relations between them. In addition to these there are also specif classes for Date and Time management. Once the utility is set up by the centre, a user is be able to signup and login into the software using a user-generated ID and PIN and once logged in, can check the status of their upcoming appointments and make appointments to get vaccinated. The Centre class serves as the main class for the application and we create only one instance of it. The vaccineList & customerList hold available vaccines and registered customers respectively. The dayList holds upcoming calendar dates which further hold the appointments which are generated using data given by the Vaccination Centre, as the appointment is reached, relevant changes to the details of the customer as well as the quantity of vaccine are made by the software.
## Class Diagram
![UML Diagram](https://raw.githubusercontent.com/Duke0404/VaccinationCentreCLI/main/Classes.png)
