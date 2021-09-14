#include <iostream>
#include <vector>

std::string get_word() {
	std::string wordSelection[] = {"ANGLE" ,"ARMOIRE" ,"BANC" ,"BUREAU" ,"CABINET", "CARREAU", "CHAISE", "CLASSE", "CLEF", "COIN"}; 
    srand(time(NULL));
    return wordSelection[rand() % 10];   
}

bool in_word(std::string word, char input) {

    int i=0;

    while (word[i]!='\0') {
        if(word[i] == input) {
            return true;
        }
        i++;
    }
    return false;
}

int search(std::vector<char> array, int c){
    for(int i = 0; i<array.size(); i++)
    {
        if(array[i]==c){
            return i;
        }
        i++;
    }
    return -1;
    
}

char get_user_input(std::vector<char>* tries){
    char input;
	do {
		std::cout << "\n> ";
		std::cin >> input;
		input = toupper(input);
	} while(search(*tries, input)!=-1);
	(*tries).push_back(input);
    return input;
};



void display_board(std::string word, std::string user_word, std::vector<char> tries, int fail){
    std::string hidden_word;
    int i=0;

    std::cout << std::endl << "============ BOARD ===========";
    std::cout << std::endl << std::endl;

	for(int i = 0; i < tries.size(); i++)
		std::cout << tries.at(i);
	

    std::cout << std::endl << user_word << std::endl;

    std::cout << std::endl;
    std::cout << "Essai restant: " << 11 - fail << std::endl;
    std::cout << std::endl;
    std::cout << "=========== ENDBOARD =========";
    
}

int main() {
	int failed = 0;
	int max_failed = 11;

	std::string word = get_word();
	std::string user_word = "";
	std::vector<char> tries;

	for(int i = 0; i < word.size(); i++)
		user_word += "*";

	do {
		display_board(word, user_word, tries, failed);

		char c = get_user_input(&tries);
		if(!in_word(word, c)) {
			failed++;
		} else {
			for(int i = 0; i < word.size(); i++)
			{
				if(word[i] == c)
					user_word[i] = c;
			}

			if(word == user_word) {
				break;
			}
		}
	} while(failed < max_failed);

	display_board(word, user_word, tries, failed);

	if(word == user_word)
		std::cout << std::endl << "Vous avez gagné à " << 11 - failed << " essaie de la fin !" << std::endl;
	else
		std::cout << std::endl << "Vous avez perdu !" << std::endl;

	std::cout << std::endl << "Le mot était " << word <<std::endl;
	
	return 0;
}