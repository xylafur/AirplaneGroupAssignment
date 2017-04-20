class City:
    def __init__(self, name):
        self.outgoingFlights = []
        self.name = name

    def __str__(self):
        return "{}   Outgoing Flights: {}".format(
                self.name, [ flight.__str__() for flight in self.outgoingFlights ] )
    def addFlight(self, destination, distance, price):
        temp = Flight( destination, distance, price)
        self.outgoingFlights.append( temp )

    def printFlights(self):
        pass

class Flight:
    def __init__(self, destination, distance, price):
        self.destination = destination
        self.distance = distance
        self.price = price

    def __str__(self):
        return (
            "Destination: {}   Distance: {}   Price: {}".format(
            self.destination.name,  self.distance, self.price) )
    
class Airline:
    def __init__(self):
        self.cities = []
    
    def __str__(self):
        ret = "Airline Object   Cities: {}".format(
                [city.__str__() for city in self.cities ])
        return ret

    def print(self):
        print("*"*23)
        print("*Airline with cities: *")
        print("*"*23)
        for city in self.cities:
            print("*{}".format(city))
        print("*"*20)

    def addFlight(self, origin, destination, distance, price):
        origin_ptr = None;  destination_ptr = None
        for city in self.cities:
            if city.name == origin:
                origin_ptr = city

            if city.name == destination:
                destination_ptr = city

        if origin_ptr == None:
            origin_ptr = City( origin )
            self.cities.append( origin_ptr )

        if destination_ptr == None:
            destination_ptr = City( destination )
            self.cities.append( City(destination_ptr) )

        #now both the destination and origin are created
        origin_ptr.addFlight( destination_ptr, distance, price )


cosc = Airline()

cosc.addFlight("Houston", "Las Vegas", 500, 200)

cosc.print()
