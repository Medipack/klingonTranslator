all: EKTAppV2

EKTAppV2: EKTAppV2.o Word.o
	g++ -Wall -o EKTAppV2 EKTAppV2.o Word.o
	
EKTAppV2.o: EKTAppV2.cpp klingonTrans.h Word.h wordNode.h hashedEntry.h hashTable.h
	g++ -Wall -c EKTAppV2.cpp
	
Word.o: Word.cpp Word.h
	g++ -Wall -c Word.cpp

clean:
	rm -f EKTApp *.o
