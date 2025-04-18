all: submission

submission: Main.o MinHeap.o
	g++ Main.o MinHeap.o -o submission

submission.o: Main.cpp MinHeap.h 
	g++ -c Main.cpp

MinHeap.o: MinHeap.cpp MinHeap.h
	g++ -c MinHeap.cpp

clean:
	rm -f *.o submission