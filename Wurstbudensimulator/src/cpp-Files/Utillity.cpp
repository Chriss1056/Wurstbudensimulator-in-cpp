#include "../header-Files/headerlib.hpp"

void utillitytest()
{
	std::cout << "Utillity" << std::endl;
}

int get_key()
{
	int key = _getch();
	if (key >= 224)
	{
		key = key + _getch();
	}
	return key;
}

void text_color(console::foreground color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color);
}

void text_background_color(console::background color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color);
}

void set_text_flags(console::special flag)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, flag);
}

void gotoxy(short x, short y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = x - 1;
	position.Y = y - 1;
	SetConsoleCursorPosition(handle, position);
}

void setCursorVisibility(int show)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = show;
	SetConsoleCursorInfo(out, &cursorInfo);
}