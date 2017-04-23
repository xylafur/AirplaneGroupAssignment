/*
 *      We can use a graph to represent the airline
 *      Creaty a city object, with this city object we can add flights
 *
 *      Our graph object will hold these cities
 *
 *      connect cities by every way they can go
 *
 */
#include "airline.h"

int main(){
    std::string str = "Houston Dallas 100 100";
    Airline myAirline;
    myAirline.addFlight("Houston", "Dallas", 100, 100);
    myAirline.print();
    return 0;
}
