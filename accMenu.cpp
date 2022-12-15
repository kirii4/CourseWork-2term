#include "accMenu.h"

//Меню пользователя
void userMenu() { 
    std::vector<Student> vecStud;
    std::vector<block> vecBlock;
    file_input(vecStud);
    fileblockInput(vecBlock);
    int menu = 0;
    while (menu != 4) {
        system("cls");
        std::cout << "\t Меню пользователя\n";
        std::cout << "=======================================\n\n";
        std::cout << "1.Работа с данными студентов.\n"
            "2.Работа с данными общежития.\n"
            "3.Выход.\n";
        checkInt(menu);
        switch (menu) {
        case 1:
            system("cls");
            studMenuUser(vecStud);
            break;
        case 2:
            system("cls");
            dormMenuUser(vecBlock);
            break;
        case 3:
            std::cout << "\nВыход из программы.\n";
            file_output(vecStud);
            fileblockOutput(vecBlock);
            exit(0);
            break;
        default:
            system("cls");
            std::cout << "\nОшибка ввода!!\n";
            break;
        }
    }
}

//Меню админа
void adminMenu(std::string cashLogin) {
    std::vector<Student> vecStud;
    std::vector<input> vecReg;
    std::vector<input> vecAcc;
    std::vector<block> vecBlock;
    file_input(vecStud);
    file_input(vecReg, fileReg);
    file_input(vecAcc, fileAcc);
    fileblockInput(vecBlock);
    int menu = 0;
    while (menu != 3) {
        system("cls");
        std::cout << "\t\t Меню админа\n";
        std::cout << "===========================================\n\n";
        std::cout << "1.Работа с аккаунтами.\n" //1.Просмотр заявок на регистрацию
            "2.Работа с данными.\n"
            "3.Выход из системы.\n";
        checkInt(menu);
        switch (menu) {
        case 1:
            system("cls");
            accMenu(vecReg, vecAcc, cashLogin);
            break;
        case 2:
            system("cls");
            dataMenu(vecStud, vecBlock);
            break;
        case 3:
            std::cout << "\nВыход из системы.\n";
            file_output(vecStud);
            file_AccOutput(vecAcc);
            fileblockOutput(vecBlock);
            exit(0);
            break;
        default:
            system("cls");
            std::cout << "Ошибка ввода!!\n";
            break;
        }
    }
}

//Меню учетных записей(админ)
void accMenu(std::vector<input>& vecReg, std::vector<input>& vecAcc, std::string cashLogin) {
    int menu = 0;
    while (menu != 5) {
        system("cls");
        std::cout << "\tМеню работы с аккаунтами\n"
            << "=============================================\n\n";
        std::cout << "1.Просмотр заявок на регистрацию.\n"
            "2.Просмотр учетных записей.\n"
            "3.Удаление учетный записей.\n"
            "4.Создать заявку для новой учетной записи.\n"
            "5.Вернуться в главное меню.\n";
        checkInt(menu);
        switch (menu) {
        case 1:
            system("cls");
            registrMenu(vecAcc, vecReg);
            break;
        case 2:
            system("cls");
            printConsole(vecAcc);
            system("pause");
            break;
        case 3:
            system("cls");
            printConsole(vecAcc);
            delAcc(vecAcc, cashLogin);
            system("pause");
            break;
        case 4:
            system("cls");
            registration(vecAcc, vecReg);
            system("pause");
            break;
        case 5:
            system("cls");
            break;
        default:
            system("cls");
            std::cout << "Ошибка ввода!!\n";
            break;
        }
    }
}

//меню для работы с данными(админ)
void dataMenu(std::vector<Student>& vecStud, std::vector<block>& vecBlock) { 
    int menu = 0;
    while (menu != 3) {
        system("cls");
        std::cout << "\tМеню работы с данными\n";
        std::cout << "=======================================\n\n";
        std::cout << "1.Работа с данными о студентах.\n"
            "2.Работа с данными общежития.\n"
            "3.Вернуться в главное меню.\n";
        checkInt(menu);
        switch (menu) {
        case 1:
            system("cls");
            studMenu(vecStud);
            break;
        case 2:
            system("cls");
            dormMenu(vecBlock, vecStud);
            break;
        case 3:
            system("cls");
            break;
        default:
            system("cls");
            std::cout << "Ошибка ввода!!\n";
            break;
        }
    }
}

void studMenuUser(std::vector<Student>& vecStud) {
    int menu = 0;
    while (menu != 4) {
        system("cls");
        std::cout << "\tМеню данных о студентах\n";
        std::cout << "=======================================\n\n";
        std::cout << "1.Просмотреть список студентов.\n"
            "2.Отсортировать список.\n"
            "3.Поиск студента.\n"
            "4.Вернуться в меню.\n";
        checkInt(menu);
        switch (menu) {
        case 1:
            system("cls");
            if (vecStud.size() == 0) {
                std::cout << std::endl << "Список пуст." << std::endl << std::endl;
            }
            else {
                print_console(vecStud);
            }
            system("pause");
            break;
        case 2:
            system("cls");
            sort_menu(vecStud);
            system("pause");
            break;
        case 3:
            system("cls");
            find(vecStud);
            system("pause");
            break;
        case 4:
            system("cls");
            break;
        default:
            system("cls");
            std::cout << "Ошибка ввода!!\n";
            break;
        }
    }
}

void studMenu(std::vector<Student>& vecStud) {
    int menu = 0;
    while (menu != 7) {
        system("cls");
        std::cout << "\tМеню данных о студентах\n";
        std::cout << "=======================================\n\n";
        std::cout << "1.Просмотреть список студентов.\n"
            "2.Добавить студента.\n"
            "3.Удалить студента.\n"
            "4.Отсортировать список.\n"
            "5.Корректировать данные.\n"
            "6.Поиск студента.\n"
            "7.Вернуться в меню.\n";
        checkInt(menu);
        switch (menu) {
        case 1:
            system("cls");
            if (vecStud.size() == 0) {
                std::cout << std::endl << "Список пуст." << std::endl << std::endl;
            }else {
                print_console(vecStud);
            }
            system("pause");
            break;
        case 2:
            system("cls");
            add(vecStud);
            system("pause");
            break;
        case 3:
            system("cls");
            del(vecStud);
            system("pause");
            break;
        case 4:
            system("cls");
            sort_menu(vecStud);
            system("pause");
            break;
        case 5:
            system("cls");
            print_console(vecStud);
            editing_a_list(vecStud);
            system("pause");
            break;
        case 6:
            system("cls");
            find(vecStud);
            break;
        case 7:
            system("cls");
            break;
        default:
            system("cls");
            std::cout << "Ошибка ввода!!\n";
            break;
        }
    }
}

void dormMenuUser(std::vector<block>& vecBlock) {
    int menu = 0;
    while (menu != 2) {
        system("cls");
        std::cout << "\tМеню данных общежития\n";
        std::cout << "==========================================\n\n";
        std::cout << "1.Просмотреть жильцов этажа.\n"
                     "2.Вернуться в меню.\n";
        checkInt(menu);
        switch (menu) {
        case 1:
            system("cls");
            printFloor(vecBlock);
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            break;
        default:
            system("cls");
            std::cout << "Ошибка ввода!!\n";
            break;
        }
    }
}

//меню для работы с информацией общежития
void dormMenu(std::vector<block>& vecBlock, std::vector<Student>& vecStud) { 
    int menu = 0, val{0};
    while (menu != 5) {
        system("cls");
        std::cout << "\tМеню данных общежития\n";
        std::cout << "==========================================\n\n";
        std::cout //<< "1.Просмотреть список комнат по этажу.\n"
            //<< "2.Просмотреть список этажей с количеством комнат.\n"
            << "1.Просмотреть жильцов этажа.\n"
            "2.Редактировать жильцов комнаты.\n"
            "3.Начать заселение студентов.\n"
            "4.Выселить всех.\n"
            "5.Вернуться в меню.\n";
        checkInt(menu);
        switch (menu) {
        case 1:
            system("cls");
            printFloor(vecBlock);
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            val = findBlock(vecBlock);
            if (val == -1) {
                system("cls");
                std::cout << "\tОшибка\nБлока не найдено!";
                system("pause");
            }else {
                editBlock(vecBlock[val], vecStud);
            }
            break;
        case 3:
            system("cls");
            checkIn(vecBlock, vecStud);
            secondCheckIn(vecBlock, vecStud);
            printNotCheckInStud(vecStud);
            system("pause");
            break;
        case 4:
            clearDorm(vecBlock,vecStud);
            system("pause");
            break;
        case 5:
            system("cls");
            break;
        default:
            system("cls");
            std::cout << "Ошибка ввода!!\n";
            break;
        }
    }
}

void find(std::vector<Student>& vecStud) {
    int menu = 0;
    while (menu != 3) {
        system("cls");
        std::cout << "\t\tМеню поиска\n"
            << "=============================================\n\n";
        std::cout << "1.Поиск по ФИО.\n"
            "2.Поиск по номеру группы.\n"
            "3.Вернуться в меню.\n";
          
        checkInt(menu);
        switch (menu) {
        case 1:
            system("cls");
            find_stud(vecStud);
            system("pause");
            break;
        case 2:
            system("cls");
            findGroup(vecStud);
            system("pause");
            break;
        case 3:
            break;
        default:
            system("cls");
            std::cout << "Ошибка ввода!!\n";
            break;
        }
    }
}