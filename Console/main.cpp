#include "Console.h"
#include "ConsoleContext.h"
#include <iostream>


int main()
{
	
	ConsoleContext myContext(50,50,"Projet-3 B52",20,20, L"Consolas");

	Console::defineContext(myContext);

	//ConsoleImage::drawLine(20, 80, 20, 60, 'b', ConsoleColor::bb);

	//Console::getInstance(); // necessaire pour re size la console de output

	// ConsoleImage image;

	//Console::getInstance().writer().randomize();

	ConsoleWriter *curWriter = &Console::getInstance().writer();

	//Console::getInstance().writer().createImage("Allo").drawRect(1, 1, 10, 10, 'w', ConsoleColor::tb);
	Console::getInstance().writer().createImage("Allo").drawRect(30, 30, 10, 10, 'w', ConsoleColor::tb);

	curWriter->createImage("Allo").drawRect(1, 1, 10, 10, 'w', ConsoleColor::tb);

	int b{ 0 };

	while (b == 0)
	{

		curWriter->write("Allo");

	//Console::getInstance().writer().write("Allo");

	// fonctionne pas Console::getInstance().writer().write(ConsoleWriter::createImage("Allo").drawRect(30, 30, 5, 5, "o", ConsoleColor::tc));


	//Console::getInstance().writer().write("bonjour");
	}


	int a{ 0 };
}