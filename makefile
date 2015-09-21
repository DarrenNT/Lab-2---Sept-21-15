diceGame: diceGame.o
	g++ diceGame.o -o diceGame
diceGame.o: diceGame.cpp
	g++ -c diceGame.cpp

clean:
	rm *.o diceGame
