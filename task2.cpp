#include <iostream>
#include <string>
#include <ctime>

std::string generate_password(int length, const std::string& charset, const std::string& required_digits, const std::string& required_symbols) {
    std::string password;
    int required_digits_count = 0;
    int required_symbols_count = 0;
    std::srand(std::time(nullptr));

    for (int i = 0; i < 5; i++) {
        if (required_digits.empty()) {
            break;
        }
        password += required_digits[std::rand() % required_digits.size()];
        required_digits_count++;

    }

    for (int i = 0; i < 5; i++) {
        if (required_symbols.empty()) {
            break;
        }
        password += required_symbols[std::rand() % required_symbols.size()];
        required_symbols_count++;

    }

    for (int i = required_digits_count + required_symbols_count; i < length; i++) {
        password += charset[std::rand() % charset.size()];
    }

    // Перемешиваем пароль
    for (int i = 0; i < password.size(); i++) {
        int j = std::rand() % password.size();
        std::swap(password[i], password[j]);
    }

    return password;
}

int main() {
    const std::string lower = "abcdefghijklmnopqrstuvwxyz";
    const std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string digits = "0123456789";
    const std::string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    int level;
    do {
        std::cout << "Выберите уровень сложности (1 - низкий, 2 - средний, 3 - высокий, 0 - выход): ";
        std::cin >> level;

        if (level == 0) {
            std::cout << "Выход из программы." << std::endl;
            break;
        }

    int length;
    std::string charset, required_digits, required_symbols;

    switch (level) {
        case 1: // Заглавные и строчные буквы
            length = 8;
            charset = lower + upper;
            required_digits = "";
            required_symbols = "";
            break;
        case 2: // Заглавные, строчные буквы и цифры
            length = 12;
            charset = lower + upper + digits;
            required_digits = "0123456789";
            required_symbols = "";
            break;
        case 3: // Заглавные, строчные буквы, цифры и символы
            length = 16;
            charset = lower + upper + digits + symbols;
            required_digits = "0123456789";
            required_symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";
            break;
        default:
            std::cout << "Неверный уровень сложности!" << std::endl;
                continue;
    }

    std::string password = generate_password(length, charset, required_digits, required_symbols);
    std::cout << "Сгенерированный пароль: " << password << std::endl;

    } while (true);

    /* Примеры
        1 - jrjeYrho
        2 - TkFIpdU05cyK
        3 - d.xED,.E+K:!+jok
    */

    return 0;
}


