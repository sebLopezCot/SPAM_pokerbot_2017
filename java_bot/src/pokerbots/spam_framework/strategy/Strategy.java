package pokerbots.spam_framework.strategy;

import pokerbots.spam_framework.GameState;

public abstract class Strategy {

	public Strategy(boolean showLogo) {
		if (showLogo) {
			printLogo();
		}
	}
	
	// once the game state is updated, this get action method
	// will be called in order to make a decision on what to do.
	public abstract String getAction(GameState gameState);
	
	public void printLogo() {
		System.out.println("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM");
		System.out.println("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM");
		System.out.println("MMMMMMMMMMMMMMMMMWWWWNNNNNNNNNNNNNNNNNNNWWWWNNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWMMMMMMMMMMMMMMMMMMMMMM");
		System.out.println("MMMMMMMWWNXXXXKXXKK00OOkxdxxxxxxkxkkkkkkkkOkxxxxxxxxxxxxxxxxxxxxxxxxxxkkkkkkkkkkOO0KKXXXNNNWWMMMMMMM");
		System.out.println("MMMMMMN0xdddoloxOOkxxkOOxdxxxxkkkxxxkOOOOxddddddddddodddddddddoooddddddddddddddddxkO000000000KNMMMMM");
		System.out.println("MMMMMWOocclolclodddxxkkOkxddoooooooodkkkkxdoddddddddddddddddddddddddddddddddddddddxkO0KXXK00Ok0WMMMM");
		System.out.println("MMMMMNOxdooddolloodxkkkkkkkkkkOOOOOkkkOOOkdoccloooooodoooooooooooodddooooooooooooooooodddddxkxOWMMMM");
		System.out.println("MMMMMWKkkxxxkkkxdxxxxxxxxkkkkOOOkkxxxxkkkxdolllloooooooooooooooooooooooooooooooooolloodxddddxkXWMMMM");
		System.out.println("MMMMMMWKxdlcc:cccllooddooddddddddooooooooooooooooooooooooooodddddddddddooooooooooddxkkkxxxkk0XWMMMMM");
		System.out.println("MMMMMMMNOdoolllloodxxkkkkkkkkkkkkkkkkkkkkkOOkkOOkkkkkkkkkkkkOOkkkkkkkkkkkxxxxxxxxddddoooddxkKWMMMMMM");
		System.out.println("MMMMMMMNx:;;'.''';::::::::::::::cccccccccccccccllllllllllllllllllllcclcccccllllllccc:;;;:ccdKMMMMMMM");
		System.out.println("MMMMMMMNx:::,...  .     .......   ..........         ....      ......       ............,;:dXMMMMMMM");
		System.out.println("MMMMMMMNxccc;,''...  .,col:;:cll,.:oddolcclolc,.    ,oxxl.    .codddo,    .:odddo,......,;:dXMMMMMMM");
		System.out.println("MMMMMMMNx::c;,,'... .:xko.    'l:..okkx,...cxkkc. .;dxxkko'    .okkOkd,  .:kOOOxc;,'...':ccdXMMMMMMM");
		System.out.println("MMMMMMMNklll:,,'... .lkkxc,.....  .okkd'   ,xkko';odo,:xkko'   .lkkkOko..:xkkOOx;..'..';cllxXMMMMMMM");
		System.out.println("MMMMMMMNklol:,,'...  ;dkkkkxxdoc'..okkx;.':dkxl,;dkd, .:xkko.  .lkllkkkolxocdOOx, ...',:lookXMMMMMMM");
		System.out.println("MMMMMMMNklol;,,'...   .;:clodkkkx:,okkkdlllc;..'okkxlccoxkkkl. .lx;.ckOOOd''dOOx, ..',;:looxXMMMMMMM");
		System.out.println("MMMMMMMNkllc,'''.....:,.   ..;dkkl;okkx,.     .cxo:;,,,,:dkkx:..ok; .lkOd, .oOOk, ...',;:clxXMMMMMMM");
		System.out.println("MMMMMMMNkl:,..    ..,dxl'.  .,dkd;;dkkx;     .;xx,       ;xkkd,'okc. .co,  'dOOk:......';:cxXMMMMMMM");
		System.out.println("MMMMMMMNkl:;..   ..  .;clccclll;..:loooc.    'loo;..     ,odoolcodo:.     .:odddl'......,:cxXMMMMMMM");
		System.out.println("MMMMMMMNklc;..   ..      .....      ..........'''..................       .............',:cxXMMMMMMM");
		System.out.println("MMMMMMMNklc;...  ..         ....',;::clllcllllllllcccc:::;;;,'''''.....   .............';:cxXMMMMMMM");
		System.out.println("MMMMMMMNklc;'..  ..    ..,:cloodddddoooooooollllcccclccccc:::;;::::::::;,;,...    .....';:cxXMMMMMMM");
		System.out.println("MMMMMMMNklc;'..  ....,codddddddooddooollloolllllccccc:ccc:;,;;;;:;;;:;;:cc::c:;,'......';:cxXMMMMMMM");
		System.out.println("MMMMMMMNklc:'... .':loodddddoooooodoollllooc:cccc::;;:c;,;;,;,,,,,,,,,;::;;:cccllc:,...';:lxXMMMMMMM");
		System.out.println("MMMMMMMNklc:'... .;clloooooollloooolllcclllc:::cc:;;;;:;,;;,'',;;;;,'',,;,,;:ccloddo:'.';:lxXMMMMMMM");
		System.out.println("MMMMMMMNklc:,... .;cccllloolllloolollllccccc:::::;;;;;:;;;;,',;;,,;,,,;;;;;:ccclodxxo;.';:lxXMMMMMMM");
		System.out.println("MMMMMMMNklc:,... .';:clloooooooooooollccccccc::::::::::::::,,;;::;;;;;;;;:::cloodxxxd:',;:lxXMMMMMMM");
		System.out.println("MMMMMMMNklc:;........';cllooooooooolllcccccc:::::::cc::cc::;;::::::;;;::cccclodddxxxl,',;:lxKWMMMMMM");
		System.out.println("MMMMMMMNOoc:;'.....''';loollolllllllccccc:::;;;;;,,,,,,;:ccccccclllcccccclloddxkxc,,'.',;:lxKMMMMMMM");
		System.out.println("MMMMMMMNOocc;'.......':cc:;:c:;;,,'''''''''...............',;:cllooooodddddxxxkkx;....,:looxKMMMMMMM");
		System.out.println("MMMMMMMNOoc::,,,''......'''''..................................';:::cc:;;;;;:::::;;,'':oxxxxKWMMMMMM");
		System.out.println("MMMMMMMWOocc:;;;;;;:c::;,,''......................................'',''.....'''',,;;,;:loooxKMMMMMMM");
		System.out.println("MMMMMMMW0occ::,'',,:oxxxxdolc::::;;;;;,,,,,''''''''''''''''....'''.........'''''''',,,,;::lxKMMMMMMM");
		System.out.println("MMMMMMMNOolllc;',,,;:lddxdoc:;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,,,,;;:::::;;;;;;::c;'.'',,,;::clxKMMMMMMM");
		System.out.println("MMMMMMMNkoodoc;,;,,;;;cloc;,,,;;::;;,,,'''''''.''''''''''.......'',,;:ccccclll;''',,;;;::cldKMMMMMMM");
		System.out.println("MMMMMMMNOooool:;;;::;,,::;,,;;;:::;,'''...'''.........''..............',;::cc:,'',,,,;::::cdKWMMMMMM");
		System.out.println("MMMMMMMNOollolc:;;:::,',;;;;;;::::,'.......'''''..........................',,'''''',,,;:;:cdKWMMMMMM");
		System.out.println("MMMMMMMNOolllol:;;:::;,,;;;,;;;;::;''.................... .....''................',,';:;;:co0WMMMMMM");
		System.out.println("MMMMMMMW0dlllccc::cc:::::;'..',;;;,'.........................',,,,'..   .......'...';cc:::co0WMMMMMM");
		System.out.println("MMMMMMMWKkxdlc:ccloollooll:;;:c;,'''....... .''.....'',,''..,,;;;,''....,,,''';cc;,;:llcccldKMMMMMMM");
		System.out.println("MMMMMMMMNK00Okxxxxxxxxxxxddodddlc:::;'''',;'',,'''',,',;:,,;;:cccccccccllllllloddddxxkkxxxk0WMMMMMMM");
		System.out.println("MMMMMMMMWNXKKK0000000000OkkxkxooooddooooooocccllllllllloolclllooooodxxdddddxkOO00KKKKKK00KNWMMMMMMMM");
		System.out.println("MMMMMMMMMMMWWNNXXKKKXXXXXKKKK0O00KKKKKKK0K0OO000000000000OOOOO000000K0000KKXXNNNNNNNNNWWMMMMMMMMMMMM");
		System.out.println("MMMMMMMMMMMMMMMMMWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWMMMMMMMMMMMMMMMMMMMMMMMMMM");
		System.out.println("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM");
		System.out.println("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM");
		System.out.println("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM");

	}
}
