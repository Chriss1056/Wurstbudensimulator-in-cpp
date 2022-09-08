#pragma once

struct player
{
	const char* name;
	float money;
	float zinsen;
	float kredit;
};

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

		const char* einstellungen_main_menue_selected = "| # EINSTELLUNGEN                    # |";
		const char* einstellungen_main_menue_not_selected = "|   einstellungen                      |";

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
	};
}

constexpr auto UP_ARROW_KEY = 296;
constexpr auto DOWN_ARROW_KEY = 304;

constexpr auto ENTER_KEY = 13;

constexpr auto ESCAPE_KEY = 27;

void utillitytest();

int get_key();
