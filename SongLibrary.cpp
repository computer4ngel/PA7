#include "SongLibrary.h"
#include <string>

int globalcount;

SongLibrary::SongLibrary() {
	// initialize to empty list
	head = NULL; 
	// default sort attribute is title
	sortAttribute = "title";
}

// TODO: finish SongLibrary copy constructor
SongLibrary::SongLibrary(const SongLibrary& other) {
	sortAttribute = other.sortAttribute;
	if(other.head == NULL) {
		head = NULL;
		return;
	}

	head = new Song(*(other.head));

	Song * cur = head;
	Song * copy = other.getHead()->getNext();

	while(copy != NULL) {
		cur->setNext(new Song(*copy));
		cur = cur->getNext();
		copy = copy->getNext();
	}
}

// TODO: finish SongLibrary destructor
SongLibrary::~SongLibrary() {
	if(head == nullptr){
		return;
	}

	Song * prev = NULL;
	Song * cur = head;

	while (cur != nullptr){
		cur = cur->getNext();
		delete prev;
		prev = cur;
	}
}

Song * SongLibrary::getHead() const {
	return head;
}

// TODO: finish this function
void SongLibrary::setHead(Song * newHead) {
	if (head != NULL) {
		// TODO: free old list here!!
		 
	}
	head = newHead;
}

string SongLibrary::getSortAttribute() const {
	return sortAttribute;
}

void SongLibrary::setSortAttribute(string newSortAttribute) {
	sortAttribute = newSortAttribute;
}

void SongLibrary::performLoad(string filename) {
	int tCount = 0, rat;
	string titl,art,gen;
	string fileData;
	bool check;
	ifstream inFile;

	int songCount = countSongs(filename);

		while(head !=nullptr)
			{
  				temp=head->getNext();
  				delete head;
  				head = temp;
			}

	inFile.open(filename);

	while(getline(inFile, fileData)) {
		if(tCount == 0) {
			titl = fileData;
			tCount++;
		}
		else if(tCount == 1) {
			art = fileData;
			tCount++;
		}
		else if(tCount == 2) {
			gen = fileData;
			tCount++;
		}
		else if(tCount == 3) {
			rat = stoi(fileData);
			
			Song * newSong = new Song(titl,art,gen,rat);
			performInsertSongInOrder(newSong);
			tCount++;
		}
		else if(tCount == 4) {
			tCount = 0;
		}
		
	}
	inFile.close();
}


int countSongs(string filename) {
	string datas;
	ifstream inFile;
	inFile.open(filename);

	int tempCount = 0;
	int count = 1;

	if(!inFile) {
		cout << "No such file found";
	}
	else {
		while(getline(inFile, datas)) {
			if(tempCount < 4) {
				++tempCount;
			}
			else {
				count++;
				tempCount = 0;
			}
		}
	}
	inFile.close();
	globalcount = count;
	return count;
}


void SongLibrary::performSave(string filename) {
	ofstream outFile;
	outFile.open(filename, ios::trunc);

for(int i=0; i<globalcount;i++){
	if(head != nullptr) {
		temp = head;
		outFile << temp->getTitle() << endl;
		outFile << temp->getArtist() << endl;
		outFile << temp->getGenre() << endl;
		outFile << temp->getRating() << endl;
		outFile << "\n";

		head = temp->getNext();
	}
	else{
		cout << "Nothing to save." << endl;
	}
}
}

void SongLibrary::performSort() {
	if(head == nullptr || head->getNext() == nullptr){
	}

	Song * newHead = head;
	head = nullptr;


	Song * cur = newHead;
	Song * next = newHead->getNext();

	while(next != nullptr){
		this->performInsertSongInOrder(cur);
		cur = next;
		next = next->getNext();
	}

	this->performInsertSongInOrder(cur);


}

Song * SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, bool * found, int * index) {
	
	Song * cur = head;
	int curIndex = 1;

	while(cur != NULL) {
		if(cur->getStringAttributeValue(searchAttribute) == searchAttributeValue) {
			*found = true;
			*index = curIndex;
			return cur;
		}
	cur = cur->getNext();
	curIndex++;
}

	*found = false;
	*index = -1;
	return NULL;
}

void SongLibrary::performInsertSongInOrder(Song * songToInsert) {
	if(head == NULL) {
		head = songToInsert;
		head->setNext(NULL);
		return;
	}

	Song * cur = head;
	Song * prev = NULL;

	// Moves the two node pointers along the list
    while(cur != nullptr && cur->getStringAttributeValue(sortAttribute) < songToInsert->getStringAttributeValue(sortAttribute)){ 
        prev = cur;
        cur = cur->getNext();
    }

    // Handles case of insertion at the front
    if(prev == nullptr) {
        songToInsert->setNext(head);
        head = songToInsert;
    }
    // Handles case of insertion anywhere else in the list
    else {
        prev->setNext(songToInsert);
        songToInsert->setNext(cur);
    }
	//cout << "Successful insert" << endl;
}



// TODO: finish this function
void SongLibrary::performRemoveSong(Song * songToRemove) {
	
}

void SongLibrary::performEditSong(Song * songToEdit, string attribute, string newAttributeValue) {	
	if(attribute == "title") {
		songToEdit->setTitle(newAttributeValue);
	}
	else if(attribute == "artist"){
		songToEdit->setArtist(newAttributeValue);
	}
	else if(attribute == "Genre"){
		songToEdit->setGenre(newAttributeValue);
	}
	else if(attribute == "rating"){
		songToEdit->setRating(stoi(newAttributeValue));
	}
	// Continue for all attributes
}

void SongLibrary::printLibrary(){
	if(head == nullptr){
		std::cout << "library empty" << std::endl;
		return;
	}
	if(head->getNext() == nullptr){
		head->displaySong();
		return;
	}

	Song * cur = head;

	while(cur != nullptr){
		cur->displaySong();
		cur = cur->getNext();
	}
}

Song * SongLibrary::editQuery(string val) {

		Song * cur = head;
	int curIndex = 1;

	while(cur != NULL) {
		if(cur->getTitle() == val) {
			return cur;
		}
	cur = cur->getNext();
	curIndex++;
	}
}

Song * SongLibrary::createSong() {
	string title, artist, genre;
	int rating;

	Song * newSong = new Song;

	cout << "Please input the title of the new song: ";
	getline(cin, title);
	cout << "Please input the artist of the new song: ";
	getline(cin, artist);
	cout << "Please input the genre of the new song: ";
	getline(cin, genre);
	cout << "Please input the rating of the new song: ";
	cin >> rating;
	cin.ignore();

	newSong->setTitle(title);
	newSong->setArtist(artist);
	newSong->setGenre(genre);
	newSong->setRating(rating);

	return newSong;
}