#include <iostream>
#include <string>
#include <ctime>

std::string generate_password(int length, const std::string& charset) {
    std::string password;
    std::srand(std::time(nullptr));

    for (int i = 0; i < length; ++i) {
        password += charset[std::rand() % charset.size()];
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
    std::string charset;

    switch (level) {
        case 1: // Заглавные и строчные буквы
            length = 8;
            charset = lower + upper;
            break;
        case 2: // Заглавные, строчные буквы и цифры
            length = 12;
            charset = lower + upper + digits;
            break;
        case 3: // Заглавные, строчные буквы, цифры и символы
            length = 16;
            charset = lower + upper + digits + symbols;
            break;
        default:
            std::cout << "Неверный уровень сложности!" << std::endl;
                continue;
    }

    std::string password = generate_password(length, charset);
    std::cout << "Сгенерированный пароль: " << password << std::endl;

    } while (true);

    /* Примеры
        1 - jrjeYrho
        2 - TkFIpdU05cyK
        3 - d.xED,.E+K:!+jok
    */

    return 0;
}


