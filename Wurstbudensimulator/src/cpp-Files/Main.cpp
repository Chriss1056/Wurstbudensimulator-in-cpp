#include "../header-Files/headerlib.h"

int main()
{
	player player;
	nodemanager nodemanager;

	menue_strings::main_menue main_menue;

	utillitytest();
	savefileManagerTest();
	nodestest();
	banktest();
	markttest();
	preisetest();
	optionestest();
	std::cout << "Hello World!" << std::endl;

	saveFileMain(&player, &nodemanager);

	int terminate, position, tick;

	terminate = 0;
	position = 0;
	tick = 0;

	do
	{
		system("cls");

		std::cout << "***************Main*Menue***************" << std::endl;
		if (position == 0)
		{
			std::cout << main_menue.bank_main_menue_selected << std::endl;
			std::cout << main_menue.markt_main_menue_not_selected << std::endl;
			std::cout << main_menue.preise_main_menue_not_selected << std::endl;
		}
		else if(position == 1)
		{
			std::cout << main_menue.bank_main_menue_not_selected << std::endl;
			std::cout << main_menue.markt_main_menue_selected << std::endl;
			std::cout << main_menue.preise_main_menue_not_selected << std::endl;
		}
		else if (position == 2)
		{
			std::cout << main_menue.bank_main_menue_not_selected << std::endl;
			std::cout << main_menue.markt_main_menue_not_selected << std::endl;
			std::cout << main_menue.preise_main_menue_selected << std::endl;
		}
		else
		{
			std::cout << main_menue.bank_main_menue_not_selected << std::endl;
			std::cout << main_menue.markt_main_menue_not_selected << std::endl;
			std::cout << main_menue.preise_main_menue_not_selected << std::endl;
		}
		std::cout << "| ------------------------------------ |" << std::endl;
		if (position == 3)
		{
			std::cout << main_menue.einstellungen_main_menue_selected << std::endl;
			std::cout << main_menue.hilfe_main_menue_not_selected << std::endl;
		}
		else if (position == 4)
		{
			std::cout << main_menue.einstellungen_main_menue_not_selected << std::endl;
			std::cout << main_menue.hilfe_main_menue_selected << std::endl;
		}
		else
		{
			std::cout << main_menue.einstellungen_main_menue_not_selected << std::endl;
			std::cout << main_menue.hilfe_main_menue_not_selected << std::endl;
		}
		std::cout << "| ------------------------------------ |" << std::endl;
		if (position == 5)
		{
			std::cout << main_menue.rundenende_main_menue_selected << std::endl;
		}
		else
		{
			std::cout << main_menue.rundenende_main_menue_not_selected << std::endl;
		}
		std::cout << "| ------------------------------------ |" << std::endl;
		std::cout << "| ARROW_KEYS ... Menue Navigation      |" << std::endl;
		std::cout << "| ENTER      ... Auswaehlen            |" << std::endl;
		std::cout << "****************************************" << std::endl;

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
				else if ((key == DOWN_ARROW_KEY) && (position < 5))
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
						showBankMainMenue(&player, &nodemanager);
						break;
					}
					default:
					{
						system("cls");
						std::cerr << "Something went wrong..." << std::endl;
						break;
					}
					}
					tick = 1;
				}
			}
		} while (!tick);
		tick = 0;

	} while (!terminate);
	terminate = 0;

	system("pause");
	return 0;
}