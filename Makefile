all: WordLadder

WordLadder: ListNode.o TestLadder.o DLinkedList.o Game.o Test.o 
	g++ ListNode.o TestLadder.o DLinkedList.o Game.o Test.o -o WordLadder
	
debug:ListNode.o TestLadder.o DLinkedList.o Game.o Test.o 
	g++ -ggdb3 -o0 ListNode.o TestLadder.o DLinkedList.o Game.o Test.o -o Test.cpp.o
	
ListNode.o: ListNode.cpp ListNode.h
	g++ -c ListNode.cpp
	
TestLadder.o: TestLadder.cpp
	g++ -c TestLadder.cpp
	
DLinkedList.o: DLinkedList.cpp DLinkedList.h
	g++ -c DLinkedList.cpp
	
Game.o: Game.cpp Game.h
	g++ -c Game.cpp
	
Test.o: Test.cpp
	g++ -c Test.cpp

clean:
	rm *o WordLadder