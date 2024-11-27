#include <iostream>
#include <string>
#include <vector>

bool first_equal_last(std::string& word) {
    if (word.empty()) return false;
    return word.front() == word.back();
}

int count_matching_words(std::string& input) {
    int count = 0;
    std::string word;
    for (size_t i = 0; i <= input.length(); ++i) {
        if (i == input.length() || input[i] == ' ') {
            if (first_equal_last(word)) {
                count++;
            }
            word.clear();
        } else {
            word += input[i];
        }
    }
    return count;
}

int main() {

    std::vector<std::string> tests = {
        "ABBA ABCA A", // 3
        "HELLO WORLD", // 0
        "LEVEL CAR LOL", // 2
        "A B C D E", // 5
        "WOW MOM" // 2
    };

    for (std::string& test : tests) {
        std::cout << "Тест: \"" << test << "\" -> Количество слов: " << count_matching_words(test) << std::endl;
    }

    return 0;
}