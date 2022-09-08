#include "../header-Files/headerlib.hpp"

void utillitytest()
{
	std::cout << "Utillity" << std::endl;
}

int get_key()
{
	int key = _getch();
	if (key >= 224)
	{
		key = key + _getch();
	}
	return key;
}