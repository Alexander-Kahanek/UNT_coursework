program: rides.o ride.o drivers.o driver.o passengers.o passenger.o main.o functions.o economy.o basic.o
	g++ -o program *.o

rides.o: rides.h rides.cpp
	g++ -c rides.cpp

ride.o: ride.h ride.cpp
	g++ -c ride.cpp

drivers.o: drivers.h drivers.cpp
	g++ -c drivers.cpp

driver.o: driver.h driver.cpp
	g++ -c driver.cpp

passengers:o passengers.h passengers.cpp
	g++ -c passenger.cpp

passenger.o: passenger.h passenger.cpp
	g++ -c passenger.cpp

main.o: main.cpp main.h
	g++ -c main.cpp

functions.o: functions.cpp main.h
	g++ -c functions.cpp

economy.o: economy.h economy.cpp
	g++ -c economy.cpp

basic.o: basic.h basic.cpp
	g++ -c basic.cpp

group.o: group.h group.cpp
	g++ -c group.cpp

luxury.o: luxury.h luxury.cpp
	g++ -c luxury.cpp

clean:
	rm -f  *o program

run:
	make
	./program
