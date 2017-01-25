all: WordLadder

WordLadder: ListNode.o TestLadder.o DLinkedList.o Game.o Test.o 
	g++ ListNode.o TestLadder.o DLinkedList.o Game.o Test.o -o a.out
	
debug:ListNode.o TestLadder.o DLinkedList.o Game.o Test.o 
	g++ -ggdb3 -O0 ListNode.o TestLadder.o DLinkedList.o Game.o Test.o -o a.out
	
ListNode.o: ListNode.cpp ListNode.h
	g++ -ggdb3 -O0 -c ListNode.cpp
	
TestLadder.o: TestLadder.cpp
	g++ -ggdb3 -O0 -c TestLadder.cpp
	
DLinkedList.o: DLinkedList.cpp DLinkedList.h
	g++ -ggdb3 -O0 -c DLinkedList.cpp
	
Game.o: Game.cpp Game.h
	g++ -ggdb3 -O0 -c Game.cpp
	
Test.o: Test.cpp
	g++ -ggdb3 -O0 -c Test.cpp

clean:
	rm *o 