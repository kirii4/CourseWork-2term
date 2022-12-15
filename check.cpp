#include "check.h"

void checkInt(int& n) {
    while (!(std::cin >> n) || (std::cin.peek() != '\n') || (n < 0 || n > 1'000'000'000)) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << std::endl << "Ошибка ввода, повторите попытку:" << std::endl << std::endl;
    }
}

void checkID(int& n) {
    while (!(std::cin >> n) || (std::cin.peek() != '\n') || (n < 10'000'000 || n > 90'000'000)) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << std::endl << "Ошибка ввода, повторите попытку:" << std::endl << std::endl;
    }
}

void checkGroup(int& n) {
    while (!(std::cin >> n) || (std::cin.peek() != '\n') || (n < 100'000 || n > 900'000)) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << std::endl << "Ошибка ввода, повторите попытку:" << std::endl << std::endl;
    }
}

void checkWork(int& n) {
    while (!(std::cin >> n) || (std::cin.peek() != '\n') || (n < 0 || n > 1)) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << std::endl << "Ошибка ввода, повторите попытку:" << std::endl << std::endl;
    }
}

void checkFloor(int& n) {
    while (!(std::cin >> n) || (std::cin.peek() != '\n') || (n > MAX_BLOCKS / BLOCKS_ON_FLOOR || n < 1)) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << std::endl << "Ошибка ввода, повторите попытку:" << std::endl << std::endl;
    }
}

void checkDouble(double& n) {
    while (!(std::cin >> n) || (std::cin.peek() != '\n') || (n < 0 || n > 1'000'000'000)) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << std::endl << "Ошибка ввода, повторите попытку:" << std::endl << std::endl;
    }
}

void checkMarks(double& n) {
    while (!(std::cin >> n) || (std::cin.peek() != '\n') || (n < 0 || n > 10)) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << std::endl << "Ошибка ввода, повторите попытку:" << std::endl << std::endl;
    }
}

void checkString(std::string& str) {
    while (true) {
        int8_t k = 0;

        getline(std::cin, str);
        for (auto i = 0; i < str.size(); i++) //проверка на ввод
        {
            if ((str[i] >= 'А' && str[i] <= 'Я') || (str[i] >= 'а' && str[i] <= 'я') || (str[i] == '-')) {}
            else {
                k++;
                std::cout << "\nОшибка ввода!!\n";
                break;
            }
        }

        if (k == 1) { continue; }

        if (str.size() > 14) {
            std::cout << "Введите меньше символов.\n";
            continue;
        }

        char delta = 'А' - 'а';     //Корректировка регистра
        if (str[0] >= 'а' && str[0] <= 'я') str[0] += delta;
        for (auto i = 1; i < str.size(); i++) {
            if (str[i] == 'Ё') { str[i] = 'ё'; }
            else if (str[i] >= 'А' && str[i] <= 'Я') { str[i] -= delta; }
        }
        
        break;
    }
}

void checkFind(std::string& str) {
    getchar();
    while (true) {
        int8_t k = 0;
        getline(std::cin, str);
        for (auto i = 0; i < str.size(); i++) //проверка на ввод числа
        {
            if ((str[i] >= 'А' && str[i] <= 'Я') || (str[i] >= 'а' && str[i] <= 'я') || (str[i] == '-') || (str[i] == ' ')) {}
            else {
                k++;
                std::cout << "\nОшибка ввода!!\n";
                break;
            }
        }
        if (k == 1) { continue; }
        if (str == "" || str[str.size() - 1] == ' ') {
            std::cout << "\nОшибка ввода!!\n";
            continue;
        }
        char delta = 'А' - 'а';     //Корректировка регистра
        
        if (str.size() > 14) {
            std::cout << "Введите меньше символов.\n";
            continue;
        }

        if (str[0] >= 'а' && str[0] <= 'я') str[0] += delta;
        for (auto i = 1; i < str.size(); i++) {
            if (str[i] == 'Ё') { str[i] = 'ё'; }
            if (str[i] >= 'А' && str[i] <= 'Я') { str[i] -= delta; }
            if (str[i] >= 'а' && str[i] <= 'я' && str[i - 1] == ' ') str[i] += delta;
        }

        break;
    }
}

void checkSex(std::string& str) {
    while (true) {
        getline(std::cin, str);

        if (str != "woman" && str != "man") {
            std::cout << "\nОшибка ввода!!\n";
            continue;
        }
        
        break;
    }
}

void checkDel(std::string& str) {
    while (true) {
        getchar();
        getline(std::cin, str);

        if ((str != "y" && str != "Y") && (str != "n" && str != "N")) {
            std::cout << "\nОшибка ввода!!\n";
            continue;
        }
        break;
    }
}

void checkCheckIn(std::string& str) {
    while (true) {
        getchar();
        getline(std::cin, str);

        if (str != "а" && str != "б") {
            std::cout << "\nОшибка ввода!!\n";
            continue;
        }
        break;
    }
}

bool check_ID(int& ID, std::vector<Student>& vecStud) {
    bool check = false;
    for (auto i = 0U; i < vecStud.size(); i++) {
        if (vecStud[i].ID == ID) {
            check = true;
        }
    }
    if (check) {
        return false;
    }else {
        return true;
    }
}

void accessDelete() {
    system("cls");
    std::cout << "***************************\n"
        << "     Успешное удаление\n"
        << "***************************\n";
}

void access() {
    system("cls");
    std::cout << "************************\n"
        << "\tУспешно\n"
        << "************************\n";
}

void accessEdit() {
    std::cout << "\n***************************\n"
        << "  Успешное редактирование\n"
        << "***************************\n";
}

void accessAdd() {
    std::cout << "\n***************************\n"
        << "  Успешное добавление\n"
        << "***************************\n";
}

void accessReg() {
    std::cout << "\n***************************\n"
        << "  Успешная регистрация\n"
        << "***************************\n";
}