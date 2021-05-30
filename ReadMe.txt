For the project, I will use a series of class based singly linked lists.
The main idea is that the software would work similar to a scheduling and information database for the 

Class Structure:
*VaccinatationCentre
    -Address
        : (string)Stores address of vaccination centre
    -LocalTime
        : (int)Stores current time
    -LocalDate
        : (int)Stores current date
    -OpenTime
        : (int)Stores time at which centre opens
    -CloseTime
        : (int)Stores time at which centre closes

    +IsOpen()
        : Checks if vaccination centre is currently open
    +Purge()
        : Cancel all appointments and Clear the customer list

*Customer
    *Node
        -Name
            : (string)Stores name of customer
        -Age
            : (int)Stores age of customer
        -CustomerID
            : (int)Stores identifier for each customer
        -OnCourse
            : (bool)Stores if customer is currently on a vaccine course or not
        -Vaccine
            : (*Vaccine)If customer is OnCourse, which vaccine is he being administered
        -DoseStatus
            : (int)If customer is OnCourse, how many doses of the vaccine has he already been given
        =Next
        =Head

    -Num

    +Add()
    +Remove()
    +ClearList()
    
    +TakeDose()
        : Gives a dose of the best class available vaccine or previously selected vaccine to the customer and reduces one from the vaccine's Availability. If it is the last dose, also remove the customer from the list
    +DosesRemaining()
        : If customer is OnCourse, returns the subtraction of the total number of courses required for his vaccine from the number of courses he has been given

*Vaccine
    *Node
        -VaccineID
            : (int)Stores identifier for each vaccine
        -Name
            : (string)Stores name of vaccine
        -Class
            : (int) Ranking of the vaccine as compared to the others
        -Doses
            : (int)Stores number of doses of vaccine that need to be administered
        -Availability
            : (int)Stores number of doses of vaccine available at the centre
        =Next
        =Head

    -Num
        
    +Restock()
        : Add 100 to the Availability of the selected vaccine
    +New()
    +Remove()

*Appointment
    *Node
        -Date
            : (int)Stores the date of the appointment
        -Type
            : (enum)Vaccine dosage appointment or Vaccine restock appointment
        -Appointee
            : (int)Identifier of the person who asked for the appointment
        =Next
        =Head

    -Num

    +VaccineAppointment()
        : If customer's vaccine is available, create appointment at latest available date and add
    +RestockAppointment()
        : If on selected date, any other appointment is scheduled, push them back and call the restock method in Vaccine on selected date
    +Reschedule()
    +Cancel()
    +CancelAll()

*Employee
    *Node
        -Name
            : (string)Stores name of Employee
        -Age
            : (int)Stores age of Employee
        -CustomerID
            : (int)Stores identifier for each Employee
        -Shift
            : (enum)Shift of the employee
        =Next
        =Head

    -Num

    +Hire()
    +Fire()