#include "Strategy.h"

Strategy::Strategy() {
	
}

Strategy::Strategy(bool show_logo) {
	if (show_logo) {
		ShowLogo();
	}
}

void Strategy::ShowLogo() {
	// std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMMMMMMMMMMMWWWWNNNNNNNNNNNNNNNNNNNWWWWNNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMWWNXXXXKXXKK00OOkxdxxxxxxkxkkkkkkkkOkxxxxxxxxxxxxxxxxxxxxxxxxxxkkkkkkkkkkOO0KKXXXNNNWWMMMMMMM" << std::endl;
	// std::cout << "MMMMMMN0xdddoloxOOkxxkOOxdxxxxkkkxxxkOOOOxddddddddddodddddddddoooddddddddddddddddxkO000000000KNMMMMM" << std::endl;
	// std::cout << "MMMMMWOocclolclodddxxkkOkxddoooooooodkkkkxdoddddddddddddddddddddddddddddddddddddddxkO0KXXK00Ok0WMMMM" << std::endl;
	// std::cout << "MMMMMNOxdooddolloodxkkkkkkkkkkOOOOOkkkOOOkdoccloooooodoooooooooooodddooooooooooooooooodddddxkxOWMMMM" << std::endl;
	// std::cout << "MMMMMWKkkxxxkkkxdxxxxxxxxkkkkOOOkkxxxxkkkxdolllloooooooooooooooooooooooooooooooooolloodxddddxkXWMMMM" << std::endl;
	// std::cout << "MMMMMMWKxdlcc:cccllooddooddddddddooooooooooooooooooooooooooodddddddddddooooooooooddxkkkxxxkk0XWMMMMM" << std::endl;
	// std::cout << "MMMMMMMNOdoolllloodxxkkkkkkkkkkkkkkkkkkkkkOOkkOOkkkkkkkkkkkkOOkkkkkkkkkkkxxxxxxxxddddoooddxkKWMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNx:;;'.''';::::::::::::::cccccccccccccccllllllllllllllllllllcclcccccllllllccc:;;;:ccdKMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNx:::,...  .     .......   ..........         ....      ......       ............,;:dXMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNxccc;,''...  .,col:;:cll,.:oddolcclolc,.    ,oxxl.    .codddo,    .:odddo,......,;:dXMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNx::c;,,'... .:xko.    'l:..okkx,...cxkkc. .;dxxkko'    .okkOkd,  .:kOOOxc;,'...':ccdXMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNklll:,,'... .lkkxc,.....  .okkd'   ,xkko';odo,:xkko'   .lkkkOko..:xkkOOx;..'..';cllxXMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNklol:,,'...  ;dkkkkxxdoc'..okkx;.':dkxl,;dkd, .:xkko.  .lkllkkkolxocdOOx, ...',:lookXMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNklol;,,'...   .;:clodkkkx:,okkkdlllc;..'okkxlccoxkkkl. .lx;.ckOOOd''dOOx, ..',;:looxXMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNkllc,'''.....:,.   ..;dkkl;okkx,.     .cxo:;,,,,:dkkx:..ok; .lkOd, .oOOk, ...',;:clxXMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNkl:,..    ..,dxl'.  .,dkd;;dkkx;     .;xx,       ;xkkd,'okc. .co,  'dOOk:......';:cxXMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNkl:;..   ..  .;clccclll;..:loooc.    'loo;..     ,odoolcodo:.     .:odddl'......,:cxXMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNklc;..   ..      .....      ..........'''..................       .............',:cxXMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNklc;...  ..         ....',;::clllcllllllllcccc:::;;;,'''''.....   .............';:cxXMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNklc;'..  ..    ..,:cloodddddoooooooollllcccclccccc:::;;::::::::;,;,...    .....';:cxXMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNklc;'..  ....,codddddddooddooollloolllllccccc:ccc:;,;;;;:;;;:;;:cc::c:;,'......';:cxXMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNklc:'... .':loodddddoooooodoollllooc:cccc::;;:c;,;;,;,,,,,,,,,;::;;:cccllc:,...';:lxXMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNklc:'... .;clloooooollloooolllcclllc:::cc:;;;;:;,;;,'',;;;;,'',,;,,;:ccloddo:'.';:lxXMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNklc:,... .;cccllloolllloolollllccccc:::::;;;;;:;;;;,',;;,,;,,,;;;;;:ccclodxxo;.';:lxXMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNklc:,... .';:clloooooooooooollccccccc::::::::::::::,,;;::;;;;;;;;:::cloodxxxd:',;:lxXMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNklc:;........';cllooooooooolllcccccc:::::::cc::cc::;;::::::;;;::cccclodddxxxl,',;:lxKWMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNOoc:;'.....''';loollolllllllccccc:::;;;;;,,,,,,;:ccccccclllcccccclloddxkxc,,'.',;:lxKMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNOocc;'.......':cc:;:c:;;,,'''''''''...............',;:cllooooodddddxxxkkx;....,:looxKMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNOoc::,,,''......'''''..................................';:::cc:;;;;;:::::;;,'':oxxxxKWMMMMMM" << std::endl;
	// std::cout << "MMMMMMMWOocc:;;;;;;:c::;,,''......................................'',''.....'''',,;;,;:loooxKMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMW0occ::,'',,:oxxxxdolc::::;;;;;,,,,,''''''''''''''''....'''.........'''''''',,,,;::lxKMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNOolllc;',,,;:lddxdoc:;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,,,,;;:::::;;;;;;::c;'.'',,,;::clxKMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNkoodoc;,;,,;;;cloc;,,,;;::;;,,,'''''''.''''''''''.......'',,;:ccccclll;''',,;;;::cldKMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNOooool:;;;::;,,::;,,;;;:::;,'''...'''.........''..............',;::cc:,'',,,,;::::cdKWMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNOollolc:;;:::,',;;;;;;::::,'.......'''''..........................',,'''''',,,;:;:cdKWMMMMMM" << std::endl;
	// std::cout << "MMMMMMMNOolllol:;;:::;,,;;;,;;;;::;''.................... .....''................',,';:;;:co0WMMMMMM" << std::endl;
	// std::cout << "MMMMMMMW0dlllccc::cc:::::;'..',;;;,'.........................',,,,'..   .......'...';cc:::co0WMMMMMM" << std::endl;
	// std::cout << "MMMMMMMWKkxdlc:ccloollooll:;;:c;,'''....... .''.....'',,''..,,;;;,''....,,,''';cc;,;:llcccldKMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMMNK00Okxxxxxxxxxxxddodddlc:::;'''',;'',,'''',,',;:,,;;:cccccccccllllllloddddxxkkxxxk0WMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMMWNXKKK0000000000OkkxkxooooddooooooocccllllllllloolclllooooodxxdddddxkOO00KKKKKK00KNWMMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMMMMMWWNNXXKKKXXXXXKKKK0O00KKKKKKK0K0OO000000000000OOOOO000000K0000KKXXNNNNNNNNNWWMMMMMMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMMMMMMMMMMMWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
	// std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
}
