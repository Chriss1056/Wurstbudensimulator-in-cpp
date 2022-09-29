#include "../header-Files/headerlib.hpp"

void banktest()
{
	std::cout << "Bank" << std::endl;
}

void kreditAufnehmen(player* player)
{
	system("cls");
	std::cout << "Not Implemented yet." << std::endl;
	std::cout << "press ENTER to return..." << std::endl;
	std::cin.get();
}

void kreditAbzahlen(player* player)
{
	system("cls");
	std::cout << "Not Implemented yet." << std::endl;
	std::cout << "press ENTER to return..." << std::endl;
	std::cin.get();
}

void aktienMainMenue(player* player)
{
	
	menue_strings::bank_menue bank_menue;

	int terminate, position, tick;

	terminate = 0;
	position = 0;
	tick = 0;

	do
	{
		system("cls");

		std::cout << "****************Boerse****************" << std::endl;
		if (position == 0)
		{
			std::cout << bank_menue.bank_menue_exit_selected << std::endl;
		}
		else
		{
			std::cout << bank_menue.bank_menue_exit_not_selected << std::endl;
		}
		std::cout << "**************************************" << std::endl;

		std::cout << "Die Boerse ist derzeit nicht verfügbar." << std::endl;

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

		std::cout << "*************Kredit*Menue*************" << std::endl;
		std::cout << "| Kontostand:                        |" << std::endl;
		std::cout << "| Zinssatz:                          |" << std::endl;
		std::cout << "| Kredit o.Z.:                       |" << std::endl;
		std::cout << "| Kredit m.Z.:                       |" << std::endl;
		std::cout << "| ---------------------------------- |" << std::endl;
		if (position == 0)
		{
			std::cout << bank_menue.bank_menue_kredit_aufnehmen_selected << std::endl;
			std::cout << bank_menue.bank_menue_kredit_abzahlen_not_selected << std::endl;
		}
		else if (position == 1)
		{
			std::cout << bank_menue.bank_menue_kredit_aufnehmen_not_selected << std::endl;
			std::cout << bank_menue.bank_menue_kredit_abzahlen_selected << std::endl;
		}
		else
		{
			std::cout << bank_menue.bank_menue_kredit_aufnehmen_not_selected << std::endl;
			std::cout << bank_menue.bank_menue_kredit_abzahlen_not_selected << std::endl;
		}
		std::cout << "| ---------------------------------- |" << std::endl;
		if (position == 2)
		{
			std::cout << bank_menue.bank_menue_back_selected << std::endl;
		}
		else
		{
			std::cout << bank_menue.bank_menue_back_not_selected << std::endl;
		}
		std::cout << "**************************************" << std::endl;

		gotoxy(18, 2);
		printf("%.2f$", player->money);
		gotoxy(18, 3);
		printf("%.2f", player->zinsen - 1.00);
		std::cout << "%";
		gotoxy(18, 4);
		printf("%.2f$", player->kredit_raw);
		gotoxy(18, 5);
		printf("%.2f$", player->kredit);

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
						kreditAufnehmen(player);
						tick = 1;
						break;
					}
					case 1:
					{
						kreditAbzahlen(player);
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

void bankBalanceMainMenue(player* player)
{

	menue_strings::bank_menue bank_menue;

	int terminate, tick;

	terminate = 0;
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
		std::cout << bank_menue.bank_menue_back_selected << std::endl;
		std::cout << "**************************************" << std::endl;

		gotoxy(18, 2);
		printf("%.2f$", player->money);
		gotoxy(18, 3);
		printf("%.2f", player->zinsen - 1.00);
		std::cout << "%";
		gotoxy(18, 4);
		printf("%.2f$", player->kredit_raw);
		gotoxy(18, 5);
		printf("%.2f$", player->kredit);
		gotoxy(18, 7);
		printf("%.2f$", player->einnahmen_taeglich);
		gotoxy(18, 8);
		printf("%.2f$", player->ausgaben_taeglich);
		gotoxy(18, 9);
		printf("%.2f$", player->einnahmen_gesamt);
		gotoxy(18, 10);
		printf("%.2f$", player->ausgaben_gesamt);
		gotoxy(17, 11);
		if (player->umsatz_taeglich == 0)
		{
			printf(" %.2f$", player->umsatz_taeglich);
		}
		else if (player->umsatz_taeglich > 0)
		{
			printf("+%.2f$", player->umsatz_taeglich);
		}
		else if (player->umsatz_taeglich < 0)
		{
			printf("%.2f$", player->umsatz_taeglich);
		}
		gotoxy(17, 12);
		if (player->umsatz_gesamt == 0)
		{
			printf(" %.2f$", player->umsatz_gesamt);
		}
		else if (player->umsatz_gesamt > 0)
		{
			printf("+%.2f$", player->umsatz_gesamt);
		}
		else if (player->umsatz_gesamt < 0)
		{
			printf("%.2f$", player->umsatz_gesamt);
		}

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
			std::cout << bank_menue.bank_menue_main_börse_not_selected << std::endl;
		}
		else if (position == 1)
		{
			std::cout << bank_menue.bank_menue_main_bank_balance_not_selected << std::endl;
			std::cout << bank_menue.bank_menue_main_kredit_selected << std::endl;
			std::cout << bank_menue.bank_menue_main_börse_not_selected << std::endl;
		}
		else if (position == 2)
		{
			std::cout << bank_menue.bank_menue_main_bank_balance_not_selected << std::endl;
			std::cout << bank_menue.bank_menue_main_kredit_not_selected << std::endl;
			std::cout << bank_menue.bank_menue_main_börse_selected << std::endl;
		}
		else
		{
			std::cout << bank_menue.bank_menue_main_bank_balance_not_selected << std::endl;
			std::cout << bank_menue.bank_menue_main_kredit_not_selected << std::endl;
			std::cout << bank_menue.bank_menue_main_börse_not_selected << std::endl;
		}
		std::cout << "| ---------------------------------- |" << std::endl;
		if (position == 3)
		{
			std::cout << bank_menue.bank_menue_exit_selected << std::endl;
		}
		else
		{
			std::cout << bank_menue.bank_menue_exit_not_selected << std::endl;
		}
		std::cout << "**************************************" << std::endl;

		std::cout << "The Bank is currently not fully operational due to maintenance." << std::endl;

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
				else if ((key == DOWN_ARROW_KEY) && (position < 3))
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
						aktienMainMenue(player);
						tick = 1;
						break;
					}
					case 3:
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