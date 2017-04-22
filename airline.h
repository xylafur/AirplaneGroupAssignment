#ifndef AIRLINE_HEADER
    #define AIRLINE_HEADER
#include <vector>
#include <string>
#include <iostream>

struct Flight{
    std::string destination;
    int distance;
    int price;
};

class City{
private:
    std::string name;
    std::vector<Flight> outgoingFlights;
public:
    City(){}
    City(std::string name){
        this->name = name;
    }
    void addFlight(std::string destination, int distance, int price){
        Flight temp;
        temp.destination = destination;
        temp.distance = distance;
        temp.price = price;
        outgoingFlights.push_back(temp);
    }
    void print(){
        std::cout<<this->name<<" with outgoing flights:"<<std::endl;
        for( int i = 0; i < this->outgoingFlights.size(); i++){
            std::cout<<"\tDestination: "<<outgoingFlights[i].destination<<
                "\tDistance: "<<outgoingFlights[i].distance<<"\tPrice: "
                <<outgoingFlights[i].price<<std::endl;
        }
    }
};

class Airline{
private:
    std::vector<City> cities;

public:
    Airline(){

    }
};

#endif


