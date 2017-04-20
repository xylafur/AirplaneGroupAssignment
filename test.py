class City:
    def __init__(self, name):
        self.outgoingFlights = []
        self.name = name

    def addFlight(self, destination, distance, price):
        temp = Flight( destination, distance, price)
        self.outgoingFlights.append( temp )

    def printFlights(self):
        print(

class Flight:
    def __init__(self, destination, distance, price):
        self.destination = destination
        self.distance = distance
        self.price = price

    def __str__(self):
        return (
            "Destination: {}\t Distance: {}\tPrice: {}".format(
            self.destination.name,  self.distance, self.price) )

class Airline:
    def __init__(self):
        self.cities = []

    def addFlight(self, origin, destination, distance, price):
        origin_ptr = None;  destination_ptr = None
        for city in self.cities:
            if city.name == origin:
                origin_ptr = city

            if city.name == destination:
                destination_ptr = city

        if origin_ptr == None:
            origin_ptr = City( origin )
            cities.append( origin_ptr )

        if destination_ptr == None:
            destination_ptr = City( destination )
            cities.append( City(destination_ptr) )

        #now both the destination and origin are created
        origin_ptr.addFlight( destination_ptr, distance, price )
