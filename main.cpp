#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>

std::string getInput() {
    std::string input;
    std::cin >> input;
    return input;
}

std::string translate(std::string input, std::map<std::string, std::string> dictionary) {
    return dictionary[input];
}

std::map<std::string, std::string> loadDictionaryFromFile(const char *file) {
    std::map<std::string, std::string> dictionary;
    
    std::ifstream inFile = std::ifstream(file);
    std::string nextLine;
    std::istringstream iss;

    if(std::getline(inFile, nextLine)) {
        int num;
        std::istringstream(nextLine) >> num;
        for(int i = 0; i < num; i ++) {
            std::getline(inFile, nextLine);
            std::string english, stonks;
            std::istringstream(nextLine) >> english >> stonks;
            dictionary[english] = stonks;
        }
    }

    return dictionary;
}

int main() {
    std::map<std::string, std::string> dictionary = loadDictionaryFromFile("dictionary.txt");
    std::cout << translate(getInput(), dictionary) << std::endl;
}