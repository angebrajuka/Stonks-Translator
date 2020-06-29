#include <iostream>
#include <string>

std::string getInput() {
    std::string input;
    std::cin >> input;
    return input;
}

std::string translate(std::string input) {
    char *output = (char *)input.c_str();

    for(int i = 0; i < input.length(); i-=-1) {
        switch(output[i]) {
            case 'c':
                output[i] = 'n';
                break;
        }
    }

    return output;
}

int main() {
    std::cout << translate(getInput()) << std::endl;
}