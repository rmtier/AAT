/**
* author: Rami Mtier
* date: 10.9.2016
*/
#include "aat.h"
#include <iostream>

int main()
{
	std::cout << "\nTest aligment lib start..\n";
	
	try{
		AAT::AatCore aat_core;
	
		aat_core.Run();
	}catch(std::string exception_string)
	{
		std::cout <<  "\nException \n" << exception_string;
	}
	
	std::cout << "\n..End\n";	
	return 0;	
}
