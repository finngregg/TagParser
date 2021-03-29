driver.exe: driver.o 
	g++ driver.o -o driver.exe 
driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

clean: 
	@rm -f *.o *.run

run: driver.exe
	./driver.exe

