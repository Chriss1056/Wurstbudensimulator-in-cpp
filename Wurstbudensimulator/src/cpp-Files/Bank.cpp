#include "../header-Files/headerlib.hpp"

void banktest()
{
	std::cout << "Bank" << std::endl;
}

void showBankMainMenue(player* player)
{
	int terminate, position, tick;

	terminate = 0;
	position = 0;
	tick = 0;

	do
	{
		system("cls");

		std::cout << "The Bank is currently closed." << std::endl;
		std::cout << "Press ESC to get to the Main Menue." << std::endl;


		std::cout << "*****************Bank*****************" << std::endl;
		std::cout << "Press ESC to get to the Main Menue." << std::endl;
		std::cout << "Press ESC to get to the Main Menue." << std::endl;
		std::cout << "Press ESC to get to the Main Menue." << std::endl;
		std::cout << "Press ESC to get to the Main Menue." << std::endl;
		std::cout << "| # KONTOSTAND # |" << std::endl;
		std::cout << "Press ESC to get to the Main Menue." << std::endl;
		std::cout << "Press ESC to get to the Main Menue." << std::endl;
		std::cout << "Press ESC to get to the Main Menue." << std::endl;
		std::cout << "Press ESC to get to the Main Menue." << std::endl;
		std::cout << "Press ESC to get to the Main Menue." << std::endl;
		std::cout << "Press ESC to get to the Main Menue." << std::endl;
		std::cout << "Press ESC to get to the Main Menue." << std::endl;
		std::cout << "Press ESC to get to the Main Menue." << std::endl;
		std::cout << "Press ESC to get to the Main Menue." << std::endl;

		do
		{
			if (_kbhit())
			{
				int key = get_key();

				if (key == ESCAPE_KEY)
				{
					tick = 1;
					terminate = 1;
				}
			}
		} while (!tick);
		tick = 0;

	} while (!terminate);
	terminate = 0;
}