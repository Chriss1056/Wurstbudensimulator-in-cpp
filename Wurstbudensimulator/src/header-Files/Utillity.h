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
}

constexpr auto UP_ARROW_KEY = 296;
constexpr auto DOWN_ARROW_KEY = 304;

constexpr auto ENTER_KEY = 13;

constexpr auto ESCAPE_KEY = 27;

void utillitytest();

int get_key();
