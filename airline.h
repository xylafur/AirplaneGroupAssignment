#ifndef AIRLINE_HEADER
    #define AIRLINE_HEADER
#include <vector>
#include <string>
#include <iostream>

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
    std::string getName(){
        return this->name;
    }   
};

class Airline{
private:
    std::vector<City *> cities;

public:
    Airline(){}
    void addFlight(std::string origin, std::string destination,
            int distance, int price){
        City *origin_ptr = NULL, *destination_ptr = NULL;
        //loop through all the cities to see if the origin and destination are
        //already defined
        for( int i = 0; i < cities.size(); i++){
            if( origin.compare( cities[i]->getName() ) == 0)
                origin_ptr = cities[i];
            if( destination.compare( cities[i]->getName() ) == 0)
                destination_ptr = cities[i];
        }
        //if the cities don't exist in the cities list we will create and append
        //them
        if( origin_ptr == NULL){
            origin_ptr = new City(origin);
            this->cities.push_back(origin_ptr);
        }
        if( destination_ptr == NULL){
            destination_ptr = new City(destination);
            this->cities.push_back(destination_ptr);
        }
        //At this point both origin and destinatoin ptr are created and exist in
        //the list of cities.  SO now we jsut add the destination as a outgoing
        //flight for origin.

    }
};

#endif


