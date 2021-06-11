#include "vac.hpp"

int main() {
    Time start(11, 0);
    Centre UI("Wojskowy Instytut Medyczny", "Szaserów 128, Warszawa", 3, 4, start);

    Date d1(0, 4, 0);
    Date D1(12, 7, 2021);
    Vaccine Vaxzevria(1222, "AstraZeneca", 2, d1);
    Vaxzevria.restock(500, D1, 122272);
    UI.addVaccine(Vaxzevria);

    Date d2(0, 2, 0);
    Vaccine Comirnaty(91300, "Pfizer BioNtech", 2, d2);
    Comirnaty.restock(3000, D1, 9130002);
    UI.addVaccine(Comirnaty);

    UI.addCustomer(1234, 1234, "Devansh");

    UI.startPage();
}