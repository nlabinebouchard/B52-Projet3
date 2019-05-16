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

	Console::getInstance().writer().createImage("Allo",'a').drawRect(1, 1, 10, 10, 'w', ConsoleColor::tb);

	Console::getInstance().writer().write("Allo");

	// Console::getInstance().writer().write();


	int a{ 0 };
}