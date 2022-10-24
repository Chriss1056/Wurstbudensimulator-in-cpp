#include "../header-Files/headerlib.hpp"

void markttest()
{
	std::cout << "Markt" << std::endl;
}

void showMarktMainMenue(player* player, nodemanager* nodemanager)
{

	menue_strings::util_menue util_menue;
	menue_strings::markt_menue markt_menue;

	int terminate, tick, position, level;

	terminate = 0;
	tick = 0;
	position = 0;
	level = player->level;

	do
	{
		system("cls");
		std::cout << "**********************MARKT**********************" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "| --------------------------------------------- |" << std::endl;
		std::cout << "| Der Markt ist derzeit geschlossen.            |" << std::endl;
		std::cout << "| Druecke ENTER um zum Lager zurueckzukehren... |" << std::endl;
		std::cout << "*************************************************" << std::endl;

		do
		{
			if (_kbhit())
			{
				int key = get_key();

				if ((key == UP_ARROW_KEY) && (position > 0))
				{
					position--;
					tick = 1;
				}
				else if ((key == DOWN_ARROW_KEY) && (position < 0))
				{
					position++;
					tick = 1;
				}
				else if (key == ENTER_KEY)
				{
					switch (position)
					{
					case 0:
					{
						tick = 1;
						terminate = 1;
						break;
					}
					default:
					{
						system("cls");
						std::cerr << "Something went wrong..." << std::endl;
						Sleep(500);
						key = NULL;
						tick = 1;
						system("cls");
						break;
					}
					}
				}
			}
		} while (!tick);
		tick = 0;

	} while (!terminate);
	terminate = 0;
}