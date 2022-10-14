#include "../header-Files/headerlib.hpp"

void lagertest()
{
	std::cout << "Markt" << std::endl;
}

void showLagerMainMenue(player* player, nodemanager* nodemanager)
{
	menue_strings::lager_menue lager_menue;
	menue_strings::util_menue util_menue;

	int terminate, tick, position;

	terminate = 0;
	tick = 0;
	position = 0;

	node* test1 = nullptr;
	
	test1 = nodemanager->getNodeByIndex(1);

	do
	{
		system("cls");

		std::cout << "*******************Lager*Menue*******************" << std::endl;
		std::cout << "|     Name     |  auf Lager  |  ekp   |  vkp    |" << std::endl;
		std::cout << "|--------------|-------------|--------|---------|" << std::endl;
		for (int i = 0; i < nodemanager->getNodesCount(); i++)
		{
			if (i % 2)
			{
				std::cout << "|              |             |        |         |" << std::endl;
			}
			else
			{
				std::cout << "|              |             |        |         |" << std::endl;
			}
		}
		std::cout << "-------------------------------------------------" << std::endl;
		if (position == 0)
		{
			std::cout << util_menue.util_menue_exit_selected << std::endl;
		}
		else
		{
			std::cout << util_menue.util_menue_exit_not_selected << std::endl;
		}
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
				else if ((key == DOWN_ARROW_KEY) && (position < 1))
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
						system("cls");
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