import pdb
class City:
    def __init__(self, name):
        self.outgoingFlights = []
        self.name = name

    def __str__(self):
        return self.name

    def printIt(self):

        print( "\n{} outgoing flights: ".format(self.name ) )
        for flight in self.outgoingFlights:
            print( flight)
    
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
            "\tDestination: {}   Distance: {}   Price: {}".format(
            self.destination.name,  self.distance, self.price) )
    
class Airline:
    def __init__(self):
        self.cities = []
    
    def printIt(self):
        print("*"*23)
        print("*Airline with cities: *")
        print("*"*23)
        for city in self.cities:
            city.printIt()
        print("*"*20)

    def addFlight(self, origin, destination, distance, price):
        origin_ptr = None;  destination_ptr = None
        for city in self.cities:
            if city.name == origin:
                origin_ptr = city

            if city.name == destination:
                destination_ptr = city


        if origin_ptr == None:
            print("didnt find origin: {}".format(origin))
            origin_ptr = City( origin )
            self.cities.append( origin_ptr )

        if destination_ptr == None:
            print("didnt find destination: {}".format(destination))
            destination_ptr = City( destination )
            self.cities.append( City(destination_ptr) )
        #now both the destination and origin are created
        origin_ptr.addFlight( destination_ptr, distance, price )

class Runner:
    #class to open a file and create airline object with cities and flights and
    #that good stuff

    def __init__(self, inFile):
        self.airline = Airline()
        self.file = inFile

    def run(self):
        def createEntry(entry):
            entry = entry.split()
            self.airline.addFlight(entry[0], 
                    entry[1], int(entry[2]), int(entry[3]) )

        for line in open(self.file):
            createEntry( line )
        pdb.set_trace()
        self.airline.printIt()


runner = Runner( "flights.txt" )
runner.run()





