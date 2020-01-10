#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>

const int MAX_NUM_ERR=11;

struct Dictionary {

	std::vector<std::string> vecOfWords;

};

struct GameState {
	std::string currentWord;
	int numOfErrors;
	std::vector<bool> guessedLetters;
	long unsigned int guessLetterNum;
};

bool getFileContent(std::string fileName, std::vector<std::string> & vecOfStrs)
{

	std::ifstream in(fileName.c_str());

	if(!in)
	{
		std::cerr << "Cannot open the File : "<<fileName<<std::endl;
		return false;
	}

	std::string str;
	while (std::getline(in, str))
	{
		if(str.size() > 0)
			vecOfStrs.push_back(str);
	}
	in.close();
	return true;
}

void generateDict(Dictionary *dict) {

	getFileContent("slownik.txt",dict->vecOfWords);

}

std::string getRanWord(Dictionary *dict) {
	int index = rand() % dict->vecOfWords.size();
	return dict->vecOfWords[index];
}

void printCurrentWord(GameState *gs) {
	std::string word = gs->currentWord;
	std::vector<bool> state = gs->guessedLetters;
	long unsigned int i;
	for (i = 0; i < word.length(); i++) {

		if (state[i]) {
			std::cout << word[i];
		} else {
			std::cout << "_";
		}
		std::cout << " ";

	}
	std::cout <<std::endl;
}

bool guessLetter (GameState *gs,char letter) {
	std::string word=gs->currentWord;
	bool success=false;
	long unsigned int i;
	for(i=0;i<word.length();i++) {

	if (word[i]== letter){
		if(gs->guessedLetters[i]){
			break;
		}
		gs->guessedLetters[i]=true;
		success=true;
		gs->guessLetterNum++;
	}

	}
	return success;
}

void printWholeWord(GameState *gs){
	std::cout<< gs->currentWord<<std::endl;
}

void printHangMan(GameState *gs){

	switch (gs->numOfErrors)
		{
			case 0:
				std::cout << "            " << std::endl;
				std::cout << "            " << std::endl;
				std::cout << "            " << std::endl;
				std::cout << "            " << std::endl;
				std::cout << "            " << std::endl;
				std::cout << "            " << std::endl;
				std::cout << "            " << std::endl;
				std::cout <<"             " << std::endl;
				std::cout << "            " << std::endl;
				break;
			case 1:
				std::cout << "            " << std::endl;
				std::cout << "            " << std::endl;
				std::cout << "            " << std::endl;
				std::cout << "            " << std::endl;
				std::cout << "            " << std::endl;
				std::cout << "            " << std::endl;
				std::cout << "            " << std::endl;
				std::cout <<"/\\          " << std::endl;
				std::cout << "            " << std::endl;
				break;
			case 2:
				std::cout << "            " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout <<"/\\          " << std::endl;
				std::cout << "            " << std::endl;
				break;
			case 3:
				std::cout << "            " << std::endl;
				std::cout << "|---------  " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout <<"/\\          " << std::endl;
				std::cout << "            " << std::endl;
				break;
			case 4:
				std::cout << "            " << std::endl;
				std::cout << "|---------  " << std::endl;
				std::cout << "|/          " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout <<"/\\          " << std::endl;
				std::cout << "            " << std::endl;
				break;
			case 5:
				std::cout << "            " << std::endl;
				std::cout << "|---------  " << std::endl;
				std::cout << "|        |  " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout <<"/\\          " << std::endl;
				std::cout << "            " << std::endl;
				break;
			case 6:
				std::cout << "            " << std::endl;
				std::cout << "|---------  " << std::endl;
				std::cout << "|        |  " << std::endl;
				std::cout << "|        O  " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout <<"/\\          " << std::endl;
				std::cout << "            " << std::endl;
				break;
			case 7:
				std::cout << "            " << std::endl;
				std::cout << "|---------  " << std::endl;
				std::cout << "|        |  " << std::endl;
				std::cout << "|        O  " << std::endl;
				std::cout << "|        |  " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout <<"/\\          " << std::endl;
				std::cout << "            " << std::endl;
				break;
			case 8:
				std::cout << "            " << std::endl;
				std::cout << "|---------  " << std::endl;
				std::cout << "|        |  " << std::endl;
				std::cout << "|        O  " << std::endl;
				std::cout << "|        |\\" << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout <<"/\\          " << std::endl;
				std::cout << "            " << std::endl;
				break;
			case 9:
				std::cout << "            " << std::endl;
				std::cout << "|---------  " << std::endl;
				std::cout << "|        |  " << std::endl;
				std::cout << "|        O  " << std::endl;
				std::cout << "|       /|\\" << std::endl;
				std::cout << "|           " << std::endl;
				std::cout << "|           " << std::endl;
				std::cout <<"/\\          " << std::endl;
				std::cout << "            " << std::endl;
				break;
			case 10:
				std::cout << "|---------  " << std::endl;
				std::cout << "|        |  " << std::endl;
				std::cout << "|        O  " << std::endl;
				std::cout << "|       /|\\" << std::endl;
				std::cout << "|         \\" << std::endl;
				std::cout << "|           " << std::endl;
				std::cout <<"/\\          " << std::endl;
				std::cout << "            " << std::endl;
				break;
			case 11:
				std::cout << "            " << std::endl;
				std::cout << "|---------  " << std::endl;
				std::cout << "|        |  " << std::endl;
				std::cout << "|        O  " << std::endl;
				std::cout << "|       /|\\" << std::endl;
				std::cout << "|       / \\" << std::endl;
				std::cout << "|           " << std::endl;
				std::cout <<"/\\          " << std::endl;
				std::cout << "            " << std::endl;
				break;
		};

}

void step(GameState *gs){
	char letter;
	std::cout <<"Padaj litere: ";
	std::cin >> letter;
	bool guessed =guessLetter(gs, letter);
	if (!guessed){
		gs->numOfErrors++;
	}
	std::system("clear");
	printCurrentWord(gs);
	printHangMan(gs);
}

void loop (GameState *gs){

	printCurrentWord(gs);
	printHangMan(gs);
	bool win=false;
	while (gs->numOfErrors<MAX_NUM_ERR ){

		step(gs);
		if (gs->guessLetterNum==gs->currentWord.length()){
			win=true;
			break;
		}

	}
	if (win){
		std::cout << "Twoje jest wygranko!"<<std::endl;
	}
	else{
		std::cout << "Przegales :( "<<std::endl;
	}
}

void reset(GameState *gameState, Dictionary *dict){
		gameState->currentWord=getRanWord(dict);
		gameState->numOfErrors=0;
		gameState->guessedLetters.assign(gameState->currentWord.length(), false);
		gameState->guessLetterNum=0;
}

int main() {

	std::system("clear");
	srand(time(0));
	Dictionary dict;
	GameState gameState;

	generateDict(&dict);

	while(true){
		reset(&gameState, &dict);
		loop(&gameState);

		char letter;
		std::cout <<"Czy chcesz zagrac jeszcze raz wpisz t lub n ";
		std::cin >> letter;

		if(letter =='n'){
				break;
		}
		std::system("clear");
	}

	return 0;
}
