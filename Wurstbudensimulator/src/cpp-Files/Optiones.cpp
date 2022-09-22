#include "../header-Files/headerlib.hpp"

void optionestest()
{
	std::cout << "Optiones" << std::endl;
}

int showOptionesMainMenue(player* player, nodemanager* nodemanager)
{

	menue_strings::optiones_menue optiones_menue;

	int terminate, position, tick;

	terminate = 0;
	position = 0;
	tick = 0;

	do
	{
		system("cls");
		std::cout << "****Optiones****" << std::endl;
		if (position == 0)
		{
			std::cout << optiones_menue.optiones_menue_save_selected << std::endl;
			std::cout << optiones_menue.optiones_menue_load_not_selected << std::endl;
		}
		else if (position == 1)
		{
			std::cout << optiones_menue.optiones_menue_save_not_selected << std::endl;
			std::cout << optiones_menue.optiones_menue_load_selected << std::endl;
		}
		else
		{
			std::cout << optiones_menue.optiones_menue_save_not_selected << std::endl;
			std::cout << optiones_menue.optiones_menue_load_not_selected << std::endl;
		}
		std::cout << "| ------------ |" << std::endl;
		if (position == 2)
		{
			std::cout << optiones_menue.optiones_menue_settings_selected << std::endl;
		}
		else
		{
			std::cout << optiones_menue.optiones_menue_settings_not_selected << std::endl;
		}
		std::cout << "| ------------ |" << std::endl;
		if (position == 3)
		{
			std::cout << optiones_menue.optiones_menue_exit_selected << std::endl;
		}
		else
		{
			std::cout << optiones_menue.optiones_menue_exit_not_selected << std::endl;
		}
		std::cout << "| ------------ |" << std::endl;
		if (position == 4)
		{
			std::cout << optiones_menue.optiones_menue_back_selected << std::endl;
		}
		else
		{
			std::cout << optiones_menue.optiones_menue_back_not_selected << std::endl;
		}
		std::cout << "****************" << std::endl;

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
				else if ((key == DOWN_ARROW_KEY) && (position < 4))
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
						saveFileMain(player, nodemanager);
						tick = 1;
						break;
					}
					case 3:
					{
						int validation, validation_tick;

						validation = 0;
						validation_tick = 0;
						do
						{
							system("cls");

							std::cout << "Are you sure?" << std::endl;
							std::cout << "Press Enter to continue..." << std::endl;

							do
							{
								if (_kbhit())
								{
									key = get_key();

									if (key == ENTER_KEY)
									{
										system("cls");
										return 1;
									}
									else
									{
										system("cls");
										validation_tick = 1;
										validation = 1;
									}
								}
							} while (!validation_tick);
						} while (!validation);
						tick = 1;
						break;
					}
					case 4:
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
	return 0;
}