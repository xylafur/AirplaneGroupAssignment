/*
 *
 */

#ifndef CITY_HEAD
    #define CITY_HEAD
#include <iostream>
#include <string>
#include <vector>

class City;

struct Flight{
    std::string destination;
    City* city;
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
    void addFlight(City* destination, int distance, int price){
        Flight temp;
        temp.destination = destination->getName();
        temp.city = destination;
        temp.distance = distance;
        temp.price = price;
        outgoingFlights.push_back(temp);
    }
    void print(){
        std::cout<<"\t"<<this->name<<" with outgoing flights:"<<std::endl;
        for( int i = 0; i < this->outgoingFlights.size(); i++){
            std::cout<<"\t\tDestination: "<<outgoingFlights[i].destination<<
                "\tDistance: "<<outgoingFlights[i].distance<<"\tPrice: "
                <<outgoingFlights[i].price<<std::endl;
        }
    }
    std::string getName(){
        return this->name;
    }   
};



#endif
