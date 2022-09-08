#include "../header-Files/headerlib.h"

void savefileManagerTest()
{
	std::cout << "SavefileManager" << std::endl;
}

int lookForSaveFile()
{
	std::string path;

	system("cls");
	std::cout << "Please enter the path to your Savefiles with double Backslashes(C:\\Users\\...\\playerData\\): "; 
	getline(std::cin, path);

#ifndef RELEASE
	if (path.empty())
	{
		path = "C:\\Users\\offic\\OneDrive\\Desktop\\Coding\\Visual Studio\\Wurstbudensimulator\\Wurstbudensimulator\\Wurstbudensimulator\\src\\playerData\\";
	}
#endif
	
	for (const auto& i : std::filesystem::directory_iterator(path))
	{

		std::string fileName = i.path().filename().string();
		if (fileName.find("*_saveFile_*.wsim") == std::string::npos)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return -1;
}

void playerDefaultStatsSetup(player* player)
{
	player->name = "default";
	player->money = 50000.00;
	player->zinsen = 0.00;
	player->kredit = 0.00;
}

void showSaveFileLoadSelectorMenue(nodemanager* nodemanager, player* player)
{
	//ToDo
	playerDefaultStatsSetup(player);
}

void showSaveFileLoadMenue(nodemanager* nodemanager, player* player)
{
	int resume, position, tick;

	resume = 0;
	position = 0;
	tick = 0;

	do
	{
		system("cls");

		std::cout << "***********Save/Load*Manager*********" << std::endl;
		std::cout << "| Do you wish to load an Save File? |" << std::endl;
		std::cout << "| --------------------------------- |" << std::endl;
					  
		if (position == 0)
		{
			//umf�rben
			std::cout << "| # YES #                           |" << std::endl;
			std::cout << "|   no                              |" << std::endl;
		}
		else if (position == 1)
		{
			//Umf�rben
			std::cout << "|   yes                             |" << std::endl;
			std::cout << "| # NO  #                           |" << std::endl;
		}
		else
		{
			system("cls");
			std::cerr << "Something went wrong..." << std::endl;
			resume = 1;
			return;
		}

		std::cout << "| --------------------------------- |" << std::endl;
		std::cout << "| ARROW_KEYS ... Menue Navigation   |" << std::endl;
		std::cout << "| ENTER      ... Auswaehlen         |" << std::endl;
		std::cout << "*************************************" << std::endl;

		do
		{
			if (_kbhit())
			{
				int key = get_key();

				if ((key == UP_ARROW_KEY) && (position == 1))
				{
					position--;
					tick = 1;
				}
				else if ((key == DOWN_ARROW_KEY) && (position == 0))
				{
					position++;
					tick = 1;
				}
				else if ((key == ENTER_KEY) && (position == 1))
				{
					resume = 1;
					tick = 1;
					playerDefaultStatsSetup(player);
				}
				else if((key == ENTER_KEY) && (position == 0))
				{
					resume = 1;
					tick = 1;
					showSaveFileLoadSelectorMenue(nodemanager ,player);
				}
			}
		} while (!tick);
		tick = 0;

	} while (!resume);
}

void saveFileMain (player* player, nodemanager* nodemanager)
{
	switch (lookForSaveFile())
	{
	case 0:
	{
		playerDefaultStatsSetup(player);
		break;
	}
	case 1:
	{
		showSaveFileLoadMenue(nodemanager, player);
		break;
	}
	default:
	{
		system("cls");
		std::cerr << "Something went wrong..." << std::endl;
		return;
		break;
	}
	}
}