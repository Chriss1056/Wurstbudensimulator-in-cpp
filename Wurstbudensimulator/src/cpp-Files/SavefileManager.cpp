#include "../header-Files/headerlib.hpp"

void savefileManagerTest()
{
	std::cout << "SavefileManager" << std::endl;
}

void playerDefaultStatsSetup(player* player)
{
	player->name = "default";
	player->money = 50000.00f;
	player->zinsen = 1.10f;
	player->kredit_raw = 20.00f;
	player->kredit = player->kredit_raw * player->zinsen;
	player->einnahmen_taeglich = 10.00f;
	player->einnahmen_gesamt = 20.00f;
	player->ausgaben_taeglich = 20.00f;
	player->ausgaben_gesamt = 10.00f;
	player->umsatz_taeglich = player->einnahmen_taeglich - player->ausgaben_taeglich;
	player->umsatz_gesamt = player->einnahmen_gesamt - player->ausgaben_gesamt;
	player->boerse = 0;
	player->min_aktien_req = 0.00;
	player->aktienwert = 0.00;
	player->aktienmarkt = 0.00;
	player->level = 0;
	player->vernichtet = 0;
}

void nodesDefaultSetup(nodemanager* nodemanager)
{
	nodemanager->createNode("Coca Cola");
	nodemanager->createNode("Fanta");
	nodemanager->createNode("Semmel");
	nodemanager->createNode("Wurst");
	for (int i = 1; i <= 4; i++)
	{
		node* var = nodemanager->getNodeByIndex(i);
		if (var == NULL)
		{
			break;
		}
		var->inStock = 0;
		var->ekp = 0.00f;
		var->vkp = 0.00f;
	}
}

int lookForSaveFile(player* player)
{
	std::string path;

	setCursorVisibility(1);

	system("cls");
	std::cout << "Please enter the path to your Savefiles with double Backslashes(C:\\Users\\...\\playerData\\): "; 
	getline(std::cin, path);

	setCursorVisibility(0);

#ifndef RELEASE
	if (path.empty())
	{
		path = "C:\\Users\\offic\\OneDrive\\Desktop\\Coding\\Visual Studio\\Wurstbudensimulator\\Wurstbudensimulator\\Wurstbudensimulator\\src\\playerData\\";
	}
#else
	if (path.empty())
	{
		playerDefaultStatsSetup(player);
		return -1;
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

void showSaveFileLoadSelectorMenue(nodemanager* nodemanager, player* player)
{
	//ToDo
	playerDefaultStatsSetup(player);
	nodesDefaultSetup(nodemanager);
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
			std::cout << "| # YES #                           |" << std::endl;
			std::cout << "|   no                              |" << std::endl;
		}
		else if (position == 1)
		{
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
					nodesDefaultSetup(nodemanager);
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
	switch (lookForSaveFile(player))
	{
	case 0:
	{
		playerDefaultStatsSetup(player);
		nodesDefaultSetup(nodemanager);
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