#include "../header-Files/headerlib.hpp"

void banktest()
{
	std::cout << "Bank" << std::endl;
}

void bankBalanceMainMenue(player* player)
{

	menue_strings::bank_menue bank_menue;

	int terminate, position, tick;

	terminate = 0;
	position = 0;
	tick = 0;

	do
	{
		system("cls");

		std::cout << "***********Kontostand*Menue***********" << std::endl;
		std::cout << "| Kontostand:                        |" << std::endl;
		std::cout << "| Zinssatz:                          |" << std::endl;
		std::cout << "| Kredit o.Z.:                       |" << std::endl;
		std::cout << "| Kredit m.Z.:                       |" << std::endl;
		std::cout << "| ---------------------------------- |" << std::endl;
		std::cout << "| Einnahmen T.:                      |" << std::endl;
		std::cout << "| Ausgaben T.:                       |" << std::endl;
		std::cout << "| Einnahmen G.:                      |" << std::endl;
		std::cout << "| Ausgaben G.:                       |" << std::endl;
		std::cout << "| Umsatz T.:                         |" << std::endl;
		std::cout << "| Umsatz G.:                         |" << std::endl;
		std::cout << "| ---------------------------------- |" << std::endl;
		std::cout << bank_menue.bank_menue_exit_selected << std::endl;
		std::cout << "**************************************" << std::endl;

		gotoxy(16, 2);
		std::cout << player->money << "$";

		gotoxy(16, 3);
		std::cout << player->zinsen - 1.00 << "%";

		gotoxy(16, 4);
		std::cout << player->kredit_raw << "$";

		gotoxy(16, 5);
		std::cout << player->kredit << "$";

		gotoxy(16, 7);
		std::cout << player->einnahmen_taeglich << "$";

		gotoxy(16, 8);
		std::cout << player->ausgaben_taeglich << "$";

		gotoxy(16, 9);
		std::cout << player->einnahmen_gesamt << "$";

		gotoxy(16, 10);
		std::cout << player->ausgaben_gesamt << "$";

		do
		{
			if (_kbhit())
			{
				int key = get_key();

				if (key == ENTER_KEY)
				{
					system("cls");
					tick = 1;
					terminate = 1;
					break;
				}
			}
		} while (!tick);
		tick = 0;

	} while (!terminate);
	terminate = 0;
}

void kreditMainMenue(player* player)
{

	menue_strings::bank_menue bank_menue;

	int terminate, position, tick;

	terminate = 0;
	position = 0;
	tick = 0;

	do
	{
		system("cls");

		std::cout << "kredite" << std::endl;

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
			std::cout << bank_menue.bank_menue_main_bank_balance_selected << std::endl;
			std::cout << bank_menue.bank_menue_main_kredit_not_selected << std::endl;
		}
		else if (position == 1)
		{
			std::cout << bank_menue.bank_menue_main_bank_balance_not_selected << std::endl;
			std::cout << bank_menue.bank_menue_main_kredit_selected << std::endl;
		}
		else
		{
			std::cout << bank_menue.bank_menue_main_bank_balance_not_selected << std::endl;
			std::cout << bank_menue.bank_menue_main_kredit_not_selected << std::endl;
		}
		std::cout << "| ---------------------------------- |" << std::endl;
		if (position == 2)
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
				else if ((key == DOWN_ARROW_KEY) && (position < 2))
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
						bankBalanceMainMenue(player);
						tick = 1;
						break;
					}
					case 1:
					{
						kreditMainMenue(player);
						tick = 1;
						break;
					}
					case 2:
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