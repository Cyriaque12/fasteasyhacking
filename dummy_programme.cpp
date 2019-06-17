// game_hacking_tutorial.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>
#include <CoreWindow.h>
#include <stdio.h>

DWORD getMyBaseAddressGMH()
{
	return (DWORD)GetModuleHandle(NULL);
}

DWORD getMyBaseAddressFS()
{
	DWORD newBase;
	__asm
	{
		MOV EAX, DWORD PTR FS : [0x30]
		MOV EAX, DWORD PTR DS : [EAX + 0x8]
		MOV newBase, EAX
	}
	return newBase;
}


int main()
{
	

	int varInt = 123456;
	
	DWORD myBaseAdressGMH = getMyBaseAddressGMH();
	DWORD myBaseAdressFS = getMyBaseAddressFS();

	
	

	while (true) {

		std::cout << "Process ID: " << GetCurrentProcessId() << std::endl;
		std::cout << "Base Adress FS = " << std::hex << myBaseAdressFS << std::endl;
		std::cout << "Base Adress GMH = " << std::hex << myBaseAdressGMH << std::endl;
		
		
		std::cout << "varInt       (0x" << &varInt << ") = " << std::dec << varInt << '\n';
		std::cout << "Press ENTER to print again\n\n";
		std::cout << "-------------------------------\n";

// to pause
		getchar();

	}


}
