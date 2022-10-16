#include "../header-Files/headerlib.hpp"

void lagertest()
{
	std::cout << "Lager" << std::endl;
}

void showLagerMainMenue(player* player, nodemanager* nodemanager)
{
	menue_strings::lager_menue lager_menue;
	menue_strings::util_menue util_menue;

	int terminate, tick, position;

	terminate = 0;
	tick = 0;
	position = 0;

	node* var = nullptr;
	

	do
	{
		system("cls");

		std::cout << "*******************Lager*Menue*******************" << std::endl;
		std::cout << "|     Name     |  auf Lager  |  ekp   |  vkp    |" << std::endl;
		std::cout << "| ------------ | ----------- | ------ | ------- |" << std::endl;
		for (int i = 1; i < nodemanager->getNodesCount(); i++)
		{
			var = nodemanager->getNodeByIndex(i);
			gotoxy(1, (i + 3));
			std::cout << "|              |             |        |         |";
			gotoxy(3, (i + 3));
			printf("%s", var->name);
			gotoxy(18, (i + 3));
			printf("%d", var->inStock);
			gotoxy(32, (i + 3));
			printf("%.2f", var->ekp);
			gotoxy(41, (i + 3));
			printf("%.2f", var->vkp);
		}
		std::cout << std::endl << "| --------------------------------------------- |" << std::endl;
		if (position == 0)
		{
			std::cout << lager_menue.lager_menue_markt_selected << std::endl;
		}
		else
		{
			std::cout << lager_menue.lager_menue_markt_not_selected << std::endl;
		}
		std::cout << "| --------------------------------------------- |" << std::endl;
		if (position == 1)
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
						showMarktMainMenue(player, nodemanager);
						tick = 1;
						break;
					}
					case 1:
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