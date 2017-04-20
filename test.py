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
            self.destination, self.distance, self.price) )

class Airline:
    def __init__(self):
        self.cities = []

    def addFlight(self, origin, destination, distance, price):
        for city in self.cities:
            #this means the origin is valid
            if city.name == origin:
                city.addFlight( destination, distance, price)
                return

        self.cities.append( City(origin) )
        self.cities[-1].addFlight( destination, distance, price)
