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
#include <fstream>
class UtilClass{
private:
    std::string str;
public:
    UtilClass(){}
    UtilClass(std::string str){this->str = str;}
    std::vector<std::string> splitBy(char split){
        int lastPos = 0;
        std::vector<std::string> ret;

        for( int i = 0; i < str.length(); i++){
            if(str.at(i) == split ){
                std::string temp = str.substr(lastPos, i-lastPos);
                lastPos = i;
                ret.push_back(temp);
            }
        }
        ret.push_back( str.substr(lastPos));
        return ret;
    }
    std::vector<std::string> splitBy(std::string str, char split){
        int lastPos = 0;
        std::vector<std::string> ret;

        for( int i = 0; i < str.length(); i++){
            if(str.at(i) == split ){
                std::string temp = str.substr(lastPos, i-lastPos);
                lastPos = i;
                ret.push_back(temp);
            }
        }
        ret.push_back( str.substr(lastPos));
        return ret;
    }
    std::vector<std::string> readFileToVector(std::string filename){
        std::fstream file;
        file.open(filename);
        std::vector<std::string> ret;
        std::string line;

        if(file.is_open()){
            while(getline(file, line)){
                ret.push_back(line);
            }
            file.close();
        }

        return ret;
    }
    void fillAirline(Airline &airline, std::string str){
        std::vector<std::string> temp;
        temp = readFileToVector(str);
        fillAirline(airline, temp);
    }
    void fillAirline(Airline &airline, std::vector<std::string> vec){
        for(int i = 0; i < vec.size(); i++){
            std::vector<std::string> temp;
            temp = this->splitBy( vec[i], ' ');
            std::cout<<temp[0]<<temp[1]<<temp[2]<<temp[3]<<std::endl;
        }
    }
};

int main(){
    UtilClass helper;

    std::string str = "Houston Dallas 100 100";
    Airline myAirline;
    
    std::string st = "flights.txt";
    helper.fillAirline(myAirline, st);
    myAirline.addFlight("Houston", "Dallas", 100, 100);
    myAirline.print();
    return 0;
}
