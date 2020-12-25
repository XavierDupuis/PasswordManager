#include "init.h"

/*************************************************************************
 Displays menu options
*************************************************************************/

std::string OptionMenu[NBOPTIONS] = {
	" 0 - SAVE & EXIT (PRESS ENTER) " ,
	" 1 - READ FROM DATA FILE " ,
	" 2 - WRITE TO DATA FILE " ,
	" 3 - EDIT A PASSWORD ",
	" 4 - REVEAL ALL DATA" ,
	" 5 - ERASE ALL DATA " };

void DisplayMenu() {
	std::cout << " - - - - OPTION MENU - - - - " << std::endl;
	for (Option i = EXIT; i < NBOPTIONS; i = Option(i + 1)) {
		std::cout << OptionMenu[(i + 1) % NBOPTIONS] << std::endl;
	}
	std::cout << " - - - - - - - - - - - - - - " << std::endl << std::endl;
}