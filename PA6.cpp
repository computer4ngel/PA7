#include "PA6.h"
#include <string>

void displayMenu() {
	cout << endl << "Welcome to the CPSC 122 Music Manager!!" << endl;
	cout << "Please choose from the following options: " << endl;
	cout << "1) Load library" << endl;
	cout << "2) Store library" << endl;
	cout << "3) Display library" << endl;
	cout << "4) Sort library" << endl;
	cout << "5) Search library" << endl;
	cout << "6) Insert song in order" << endl;
	cout << "7) Remove song" << endl;
	cout << "8) Edit song" << endl;
	cout << "9) Exit" << endl;
}

int getValidChoice() {
	int choice = -1;
	string temp;
	do {
		cout << "Choice: ";
		cin >> choice;
		if (choice < FIRST_OPTION || choice > LAST_OPTION) {
			cout << "That is not a valid option. Please try again." << endl;
		}
	} while (choice < FIRST_OPTION || choice > LAST_OPTION);
	getline(cin, temp); // flush the newline outta the buffer
	return choice;
}

void executeUserChoice(int choice, SongLibrary& lib) {
	string file1, file2, file3, searchatt, searchval, editval, editatt, changeval;
	bool fnd;
	int indx;
	Song * searchSong;
	Song * newSong;
	bool * foundQ = &fnd;
	int * indexQ = &indx;
	
	switch (choice) {
		case 1:
			cout << "Please input the file that you'd like to load from: ";
			cin >> file1;
			cin.ignore();
			lib.performLoad(file1);
			break;
		case 2:
			cout << "Please input the file that you are saving to: " << endl;
			cin >> file2;
			cin.ignore();
			lib.performSave(file2);
			break;
		case 3: 
			lib.printLibrary();
			break;
		case 4:
			lib.performSort();
			break;
		case 5:
			cout << "Please input the attribute you'd like to search for (title, artist, genre, rating): " << endl;
			cin >> searchatt;
			cin.ignore();
			cout << "Please input the value you are searching for: " << endl;
			cin >> searchval;
			cin.ignore();
			searchSong = lib.performSearch(searchatt, searchval, foundQ, indexQ);
			searchSong->displaySong();
			break;
		case 6:
			// TODO: call a member function, something like lib.insertSongInLibraryOrder();
			newSong = lib.createSong();
			lib.performInsertSongInOrder(newSong);
			lib.printLibrary();
			break;
		case 7:
			// TODO: call a member function, something like lib.removeSongFromLibrary();
			break;
		case 8:
			lib.printLibrary();
			cout << "Please input the title of the song you would like to edit: ";
			getline(cin, editatt);

			cout << "Please input the attribute that you would like to edit: ";
			getline(cin, editval);

			cout << "Please input the value you would like to change the attribute to: ";
			getline(cin, changeval);
			cout << "\n";

			searchSong = lib.editQuery(editatt);
			lib.performEditSong(searchSong, editval, changeval);
			searchSong->displaySong();

			break;
		default:
			cout << "Unrecognized menu choice" << endl;
			break;
	}
}

void runMusicManager() {
	SongLibrary lib;
	
	int choice = -1;
	do {
		displayMenu();
		choice = getValidChoice();
		if (choice != QUIT_OPTION) {
			executeUserChoice(choice, lib);
		}
	} while (choice != QUIT_OPTION);
	cout << "Thanks for you using the CPSC 122 Music Manager!!" << endl;
}