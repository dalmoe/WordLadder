#include "Game.h"
#include <iostream>
#include <vector>
#include <string>


int main()
{  
	const int RANDOMCT = 1;
	Game g("dictionary.txt");
	//g.listWords();  //Lists the first ten words in the dictionary as a test.
	g.play("this", "those");
	g.play("vicki", "allan");
	g.play("oops", "pops");
	g.play("happily", "angrily");
	g.play("slow", "fast");
	g.play("stone", "money");
}
