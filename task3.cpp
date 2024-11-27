#include <iostream>
#include <fstream>
#include <string>

bool check_example(std::string& example) {
    int operand1 = example[0] - '0';
    char operation = example[1];
    int operand2 = example[2] - '0';
    int answer = example[4] - '0';

    int result;
    if (operation == '+') {
        result = operand1 + operand2;
    } else if (operation == '-') {
        result = operand1 - operand2;
    } else {
        return false;
    }

    return result == answer;
}

int main() {
    // Опять использую абсолютные пути, нашел в чем проблема, но пока не могу исправить
    std::ifstream input_file("/Users/nikzan/CLionProjects/lab10sem1/FN1.txt");
    std::ofstream output_file("/Users/nikzan/CLionProjects/lab10sem1/FN2.txt");

    if (!input_file.is_open() || !output_file.is_open()) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(input_file, line)) {
        if (line.length() != 5 || line[3] != '=') {
            std::cerr << "Неверный формат строки: " << line << std::endl;
            continue;
        }

        bool is_correct = check_example(line);
        output_file << line << (is_correct ? " +" : " -") << std::endl;
    }

    /* Пример вывода в файл
        2+3=5 +
        4-1=3 +
        7+2=9 +
        5-3=2 +
        1+1=3 -
     */

    input_file.close();
    output_file.close();

    return 0;
}