#include "../header-Files/headerlib.hpp"

void banktest()
{
	std::cout << "Bank" << std::endl;
}

//ToDo
void kreditAufnehmen(player* player)
{

	menue_strings::bank_menue bank_menue;

	int terminate, position, tick;

	float tmp_kredit;

	terminate = 0;
	position = 0;
	tick = 0;

	tmp_kredit = 0.00;

	do
	{
		system("cls");

		std::cout << "****************Kredit*Aufnehmen*****************" << std::endl;
		std::cout << "| Kontostand ohne Kredit:                       |" << std::endl;
		std::cout << "| Kredit ohne Zinsen:                           |" << std::endl;
		std::cout << "| Zinssatz:                                     |" << std::endl;
		std::cout << "| Kontostand mit Kredit:                        |" << std::endl;
		std::cout << "| Kredit mit Zinsen:                            |" << std::endl;
		std::cout << "| --------------------------------------------- |" << std::endl;
		if (position == 0)
		{
			std::cout << bank_menue.bank_menue_cancel_selected << std::endl;
		}
		else
		{
			std::cout << bank_menue.bank_menue_cancel_not_selected << std::endl;
		}
		std::cout << "*************************************************" << std::endl;

		gotoxy(27, 2);
		printf("%.2f$", player->money);
		gotoxy(27, 3);
		printf("%.2f$", player->kredit_raw);
		gotoxy(27, 4);
		printf("%.2f", player->zinsen - 1.00);
		std::cout << "%";
		gotoxy(27, 5);
		printf("%.2f$", player->money + tmp_kredit);
		gotoxy(27, 6);
		printf("%.2f$", player->kredit_raw * player->zinsen);

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

//ToDo
void kreditAbzahlen(player* player)
{

	menue_strings::bank_menue bank_menue;

	int terminate, position, tick;

	float tmp_kredit;

	terminate = 0;
	position = 0;
	tick = 0;

	tmp_kredit = 0.00;

	do
	{
		system("cls");

		std::cout << "*****************Kredit*Abzahlen*****************" << std::endl;
		std::cout << "| Kontostand mit Kredit:                        |" << std::endl;
		std::cout << "| Kredit mit Zinsen:                            |" << std::endl;
		std::cout << "| Zinssatz:                                     |" << std::endl;
		std::cout << "| --------------------------------------------- |" << std::endl;
		if (position == 0)
		{
			std::cout << bank_menue.bank_menue_cancel_selected << std::endl;
		}
		else
		{
			std::cout << bank_menue.bank_menue_cancel_not_selected << std::endl;
		}
		std::cout << "*************************************************" << std::endl;

		gotoxy(27, 2);
		printf("%.2f$", player->money);
		gotoxy(27, 3);
		printf("%.2f$", player->kredit);
		gotoxy(27, 4);
		printf("%.2f", player->zinsen - 1.00);
		std::cout << "%";

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

//ToDo
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

		std::cout << "*********************Boerse**********************" << std::endl;
		if (position == 0)
		{
			std::cout << bank_menue.bank_menue_exit_selected << std::endl;
		}
		else
		{
			std::cout << bank_menue.bank_menue_exit_not_selected << std::endl;
		}
		std::cout << "*************************************************" << std::endl;

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

		std::cout << "******************Kredit*Menue*******************" << std::endl;
		std::cout << "| Kontostand:                                   |" << std::endl;
		std::cout << "| Zinssatz:                                     |" << std::endl;
		std::cout << "| Kredit ohne Zinsen:                           |" << std::endl;
		std::cout << "| Kredit mit Zinsen                             |" << std::endl;
		std::cout << "| --------------------------------------------- |" << std::endl;
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
		std::cout << "| --------------------------------------------- |" << std::endl;
		if (position == 2)
		{
			std::cout << bank_menue.bank_menue_back_selected << std::endl;
		}
		else
		{
			std::cout << bank_menue.bank_menue_back_not_selected << std::endl;
		}
		std::cout << "*************************************************" << std::endl;

		gotoxy(23, 2);
		printf("%.2f$", player->money);
		gotoxy(23, 3);
		printf("%.2f", player->zinsen - 1.00);
		std::cout << "%";
		gotoxy(23, 4);
		printf("%.2f$", player->kredit_raw);
		gotoxy(23, 5);
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

		std::cout << "****************Kontostand*Menue*****************" << std::endl;
		std::cout << "| Kontostand:                                   |" << std::endl;
		std::cout << "| Zinssatz:                                     |" << std::endl;
		std::cout << "| Kredit ohne Zinsen:                           |" << std::endl;
		std::cout << "| Kredit mit Zinsen                             |" << std::endl;
		std::cout << "| --------------------------------------------- |" << std::endl;
		std::cout << "| Einnahmen Taeglich:                           |" << std::endl;
		std::cout << "| Ausgaben Taeglich:                            |" << std::endl;
		std::cout << "| Einnahmen Gesamt:                             |" << std::endl;
		std::cout << "| Ausgaben Gesamt:                              |" << std::endl;
		std::cout << "| Umsatz Taeglich:                              |" << std::endl;
		std::cout << "| Umsatz Gesamt:                                |" << std::endl;
		std::cout << "| --------------------------------------------- |" << std::endl;
		std::cout << bank_menue.bank_menue_back_selected << std::endl;
		std::cout << "*************************************************" << std::endl;

		gotoxy(23, 2);
		printf("%.2f$", player->money);
		gotoxy(23, 3);
		printf("%.2f", player->zinsen - 1.00);
		std::cout << "%";
		gotoxy(23, 4);
		printf("%.2f$", player->kredit_raw);
		gotoxy(23, 5);
		printf("%.2f$", player->kredit);
		gotoxy(23, 7);
		printf("%.2f$", player->einnahmen_taeglich);
		gotoxy(23, 8);
		printf("%.2f$", player->ausgaben_taeglich);
		gotoxy(23, 9);
		printf("%.2f$", player->einnahmen_gesamt);
		gotoxy(23, 10);
		printf("%.2f$", player->ausgaben_gesamt);
		gotoxy(22, 11);
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
		gotoxy(22, 12);
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
		
		std::cout << "**********************Bank***********************" << std::endl;
		std::cout << "| Hello                                         |" << std::endl;
		std::cout << "| Welcome to the MAIN STREET BANK.              |" << std::endl;
		std::cout << "| How may we help you today?                    |" << std::endl;
		std::cout << "| --------------------------------------------- |" << std::endl;
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
		std::cout << "| --------------------------------------------- |" << std::endl;
		if (position == 3)
		{
			std::cout << bank_menue.bank_menue_exit_selected << std::endl;
		}
		else
		{
			std::cout << bank_menue.bank_menue_exit_not_selected << std::endl;
		}
		std::cout << "*************************************************" << std::endl;

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