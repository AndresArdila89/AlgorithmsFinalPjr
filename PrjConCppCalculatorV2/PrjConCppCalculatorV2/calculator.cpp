#include "LaSalleLibraryOne.h"

int main() {
	SetConsoleTitle("CALCULATOR V2 by ANDRES ARDILA");
	system("color F0");
	short x = 0;
	float number,ans=0;
	
	introductionScreen("Calculator V2");
	
	while (x == 0)
	{
		

	switch (menu())
	{
	case 1:
		Add(0);
		break;
	case 2:
		Substract(0);
		system("pause");
		break;
	case 3:
		cout << "multiplication";
		system("pause");
		break;
	case 4:
		cout << "division";
		system("pause");
		break;
	case 5:
		x = 1;
	default:
		break;
	}

	}

	system("pause");
	return 0;
}