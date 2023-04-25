#include "Song.h"
#include <string>

// TODO: finish this function
string convertToLowercase(string s) {
	for(int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
	return s;
}

// TODO: finish Song default value constructor
Song::Song() {
	title = "";
	artist = "";
	genre = "";
	rating = 1;
	next = NULL;
}

// TODO: finish Song explicit value constructor
Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam) {
	title = titleParam;
	artist = artistParam;
	genre = genreParam;
	setRating(ratingParam);
	next = NULL;
}

// TODO: finish Song copy constructor
Song::Song(const Song& other) {
	title = other.title;
	artist = other.artist;
	genre = other.genre;
	rating = other.rating;
	next = NULL;
}

string Song::getTitle() {
	return title;
}

void Song::setTitle(string newTitle) {
	title = convertToLowercase(newTitle);
}

string Song::getArtist() {
	return artist;
}

void Song::setArtist(string newArtist) {
	artist = convertToLowercase(newArtist);
}

string Song::getGenre() {
	return genre;
}

void Song::setGenre(string newGenre) {
	genre = convertToLowercase(newGenre);
}

int Song::getRating() {
	return rating;
}

void Song::setRating(int newRating) {
	if (newRating < MIN_RATING || newRating > MAX_RATING) {
		cout << "Rating must be in [" << MIN_RATING << ", " << MAX_RATING << "]" << endl;
	}
	if (newRating < MIN_RATING) {
		rating = MIN_RATING;
	}
	else if (newRating > MAX_RATING) {
		rating = MAX_RATING;
	}
	else {
		rating = newRating;
	}
}

Song * Song::getNext() {
	return next;
}

void Song::setNext(Song * newNext) {
	next = newNext;
}

// TODO: finish this function
string Song::getStringAttributeValue(string attribute) {
	if(attribute == "title") {
		return title;
	}
	else if(attribute == "artist") {
		return artist;
	}
	else if(attribute == "genre") {
		return genre;
	}
	else if(attribute == "rating") {
		return to_string(rating);
	}
	return "";
}

// TODO: finish this function
void Song::displaySong() {
	cout << title << " " << artist << " " << genre << " " << rating << endl;
}