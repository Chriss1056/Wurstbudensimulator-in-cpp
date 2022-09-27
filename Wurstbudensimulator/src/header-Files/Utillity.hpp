#pragma once

struct player
{
	const char* name;
	float money;
	float zinsen;
	float kredit;
};

constexpr auto UP_ARROW_KEY = 296;
constexpr auto DOWN_ARROW_KEY = 304;

constexpr auto ENTER_KEY = 13;

constexpr auto ESCAPE_KEY = 27;

void utillitytest();

int get_key();

void gotoxy(short x, short y);
void setCursorVisibility(int show);

namespace console
{
	enum foreground
	{
		F_BLACK = 0,
		F_BLUE_D = FOREGROUND_BLUE,
		F_GREEN_D = FOREGROUND_GREEN,
		F_CYAN_D = FOREGROUND_GREEN | FOREGROUND_BLUE,
		F_RED_D = FOREGROUND_RED,
		F_MAGENTA_D = FOREGROUND_RED | FOREGROUND_BLUE,
		F_YELLOW_D = FOREGROUND_RED | FOREGROUND_GREEN,
		F_GRAY_D = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
		F_GRAY_H = FOREGROUND_INTENSITY,
		F_BLUE_H = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
		F_GREEN_H = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
		F_CYAN_H = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
		F_RED_H = FOREGROUND_INTENSITY | FOREGROUND_RED,
		F_MAGENTA_H = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
		F_YELLOW_H = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
		F_WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	};
	enum background
	{
		B_BLACK = 0,
		B_BLUE_D = BACKGROUND_BLUE,
		B_GREEN_D = BACKGROUND_GREEN,
		B_CYAN_D = BACKGROUND_GREEN | BACKGROUND_BLUE,
		B_RED_D = BACKGROUND_RED,
		B_MAGENTA_D = BACKGROUND_RED | BACKGROUND_BLUE,
		B_YELLOW_D = BACKGROUND_RED | BACKGROUND_GREEN,
		B_GRAY_D = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
		B_GRAY_H = BACKGROUND_INTENSITY,
		B_BLUE_H = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
		B_GREEN_H = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
		B_CYAN_H = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
		B_RED_H = BACKGROUND_INTENSITY | BACKGROUND_RED,
		B_MAGENTA_H = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
		B_YELLOW_H = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
		B_WHITE = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
	};
	enum special
	{
		S_DBCS_LEAD = COMMON_LVB_LEADING_BYTE,
		S_DBCS_TRAIL = COMMON_LVB_TRAILING_BYTE,
		S_DBCS_GRID_TOP_HORIZONTAL = COMMON_LVB_GRID_HORIZONTAL,
		S_DBCS_GRID_LEFT_VERTICAL = COMMON_LVB_GRID_LVERTICAL,
		S_DBCS_GRID_RIGHT_VERTICAL = COMMON_LVB_GRID_RVERTICAL,
		S_DBCS_COLOR_REVERSE = COMMON_LVB_REVERSE_VIDEO,
		S_DBCS_UNDERSCORE = COMMON_LVB_UNDERSCORE,
		S_DBCS_OR_SBCS_FLAG = COMMON_LVB_SBCSDBCS
	};
}

void text_color(console::foreground color);
void text_background_color(console::background color);
void set_text_flags(console::special flag);

namespace menue_strings
{
	struct main_menue
	{
		const char* bank_main_menue_selected = "| # BANK                             # |";
		const char* bank_main_menue_not_selected = "|   bank                               |";

		const char* markt_main_menue_selected = "| # MARKT                            # |";
		const char* markt_main_menue_not_selected = "|   markt                              |";

		const char* preise_main_menue_selected = "| # PREISE                           # |";
		const char* preise_main_menue_not_selected = "|   preise                             |";

		const char* optiones_main_menue_selected = "| # OPTIONEN                         # |";
		const char* optiones_main_menue_not_selected = "|   optionen                           |";

		const char* hilfe_main_menue_selected = "| # HILFE                            # |";
		const char* hilfe_main_menue_not_selected = "|   hilfe                              |";

		const char* rundenende_main_menue_selected = "| # RUNDENENDE                       # |";
		const char* rundenende_main_menue_not_selected = "|   rundenende                         |";
	};
	struct optiones_menue
	{
		const char* optiones_menue_back_selected = "| # BACK     # |";
		const char* optiones_menue_back_not_selected = "|   back       |";

		const char* optiones_menue_exit_selected = "| # EXIT     # |";
		const char* optiones_menue_exit_not_selected = "|   exit       |";

		const char* optiones_menue_load_selected = "| # LOAD     # |";
		const char* optiones_menue_load_not_selected = "|   load       |";

		const char* optiones_menue_save_selected = "| # SAVE     # |";
		const char* optiones_menue_save_not_selected = "|   save       |";

		const char* optiones_menue_settings_selected = "| # SETTINGS # |";
		const char* optiones_menue_settings_not_selected = "|   settings   |";
	};
	struct bank_menue
	{
		const char* bank_menue_bank_balance_selected = "| # KONTOSTAND                     # |";
		const char* bank_menue_bank_balance_not_selected = "|   kontostand                       |";

		const char* bank_menue_kredit_selected = "| # KREDITE                        # |";
		const char* bank_menue_kredit_not_selected = "|   kredite                          |";

		const char* bank_menue_exit_selected = "| # EXIT                           # |";
		const char* bank_menue_exit_not_selected = "|   exit                             |";
	};
}