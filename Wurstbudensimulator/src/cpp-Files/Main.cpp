#include "../header-Files/headerlib.hpp"

int main()
{
	utillitytest();
	savefileManagerTest();
	settingsManagerTest();
	nodestest();
	banktest();
	markttest();
	preisetest();
	optionestest();
	std::cout << "Hello World." << std::endl;
	std::cin.get();

	system("cls");
	std::cout << "### Wurstbudensimulator 5.0 ###" << std::endl << std::endl;
#ifdef RELEASE
	std::cout << "Branch:  " << RELEASE_VERSION << std::endl;
#else
	std::cout << "Branch:  " << BETA_VERSION << std::endl;
#endif
	std::cout << "Major:   " << MAJOR_VERSION << std::endl;
	std::cout << "Minor:   " << MINOR_VERSION << std::endl;
	std::cout << "Release: " << RELEASE_VERSION << std::endl;
	std::cout << "Build:   " << BUILD_VERSION << std::endl << std::endl;
#ifdef RELEASE
	std::cout << "Version: " << STABLE_VERSION << " " << MAJOR_VERSION << "." << MINOR_VERSION << "." << RELEASE_VERSION << "." << BUILD_VERSION << std::endl << std::endl;
#else
	std::cout << "Version: " << BETA_VERSION << " " << MAJOR_VERSION << "." << MINOR_VERSION << "." << RELEASE_VERSION << "." << BUILD_VERSION << std::endl << std::endl;
#endif
	std::cout << "Please expect bugs and errors while playing this Version of the game" << std::endl << std::endl;
	std::cout << "Copyright \251 Christopher Glechner, 2022" << std::endl;
	std::cin.get();

	player player;
	nodemanager nodemanager;

	TCHAR title[MAX_PATH];

	StringCchPrintf(title, MAX_PATH, TEXT("Wurstbudensimulator V5.0"));

	if (!SetConsoleTitle(title))
	{
		system("cls");
		std::cout << "Something went wrong..." << std::endl;
		return 1;
	}

	menue_strings::main_menue main_menue;

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
			std::cout << main_menue.optiones_main_menue_selected << std::endl;
			std::cout << main_menue.hilfe_main_menue_not_selected << std::endl;
		}
		else if (position == 4)
		{
			std::cout << main_menue.optiones_main_menue_not_selected << std::endl;
			std::cout << main_menue.hilfe_main_menue_selected << std::endl;
		}
		else
		{
			std::cout << main_menue.optiones_main_menue_not_selected << std::endl;
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
						showBankMainMenue(&player);
						tick = 1;
						break;
					}
					case 3:
					{
						int status = showOptionesMainMenue(&player, &nodemanager);
						if (status == 1)
						{
							terminate = 1;
						}
						tick = 1;
						break;
					}
					default:
					{
						system("cls");
						std::cerr << "Something went wrong..." << std::endl;
						Sleep(5000);
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

	system("cls");
	system("pause");
	return 0;
}