#include "../header-Files/headerlib.hpp"

void banktest()
{
	std::cout << "Bank" << std::endl;
}

void showBankMainMenue(player* player)
{

	menue_strings::bank_menue bank_menue;

	int terminate, position, tick;

	terminate = 0;
	position = 0;
	tick = 0;

	do
	{
		system("cls");

		std::cout << "*****************Bank*****************" << std::endl;
		std::cout << "| Hello                              |" << std::endl;
		std::cout << "| Welcome to the MAIN STREET BANK.   |" << std::endl;
		std::cout << "| How may we help you today?         |" << std::endl;
		std::cout << "| ---------------------------------- |" << std::endl;
		if (position == 0)
		{
			std::cout << bank_menue.bank_menue_bank_balance_selected << std::endl;
		}
		else
		{
			std::cout << bank_menue.bank_menue_bank_balance_not_selected << std::endl;
		}
		std::cout << "| ---------------------------------- |" << std::endl;
		if (position == 1)
		{
			std::cout << bank_menue.bank_menue_exit_selected << std::endl;
		}
		else
		{
			std::cout << bank_menue.bank_menue_exit_not_selected << std::endl;
		}
		std::cout << "**************************************" << std::endl;

		std::cout << "The Bank is currently reworked." << std::endl;

		gotoxy(9, 2);
		std::cout << player->name;

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