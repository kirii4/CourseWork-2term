#include "accMenu.h"

//���� ������������
void userMenu() { 
    std::vector<Student> vecStud;
    std::vector<block> vecBlock;
    file_input(vecStud);
    fileblockInput(vecBlock);
    int menu = 0;
    while (menu != 4) {
        system("cls");
        std::cout << "\t ���� ������������\n";
        std::cout << "=======================================\n\n";
        std::cout << "1.������ � ������� ���������.\n"
            "2.������ � ������� ���������.\n"
            "3.�����.\n";
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
            std::cout << "\n����� �� ���������.\n";
            file_output(vecStud);
            fileblockOutput(vecBlock);
            exit(0);
            break;
        default:
            system("cls");
            std::cout << "\n������ �����!!\n";
            break;
        }
    }
}

//���� ������
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
        std::cout << "\t\t ���� ������\n";
        std::cout << "===========================================\n\n";
        std::cout << "1.������ � ����������.\n" //1.�������� ������ �� �����������
            "2.������ � �������.\n"
            "3.����� �� �������.\n";
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
            std::cout << "\n����� �� �������.\n";
            file_output(vecStud);
            file_AccOutput(vecAcc);
            fileblockOutput(vecBlock);
            exit(0);
            break;
        default:
            system("cls");
            std::cout << "������ �����!!\n";
            break;
        }
    }
}

//���� ������� �������(�����)
void accMenu(std::vector<input>& vecReg, std::vector<input>& vecAcc, std::string cashLogin) {
    int menu = 0;
    while (menu != 5) {
        system("cls");
        std::cout << "\t���� ������ � ����������\n"
            << "=============================================\n\n";
        std::cout << "1.�������� ������ �� �����������.\n"
            "2.�������� ������� �������.\n"
            "3.�������� ������� �������.\n"
            "4.������� ������ ��� ����� ������� ������.\n"
            "5.��������� � ������� ����.\n";
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
            std::cout << "������ �����!!\n";
            break;
        }
    }
}

//���� ��� ������ � �������(�����)
void dataMenu(std::vector<Student>& vecStud, std::vector<block>& vecBlock) { 
    int menu = 0;
    while (menu != 3) {
        system("cls");
        std::cout << "\t���� ������ � �������\n";
        std::cout << "=======================================\n\n";
        std::cout << "1.������ � ������� � ���������.\n"
            "2.������ � ������� ���������.\n"
            "3.��������� � ������� ����.\n";
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
            std::cout << "������ �����!!\n";
            break;
        }
    }
}

void studMenuUser(std::vector<Student>& vecStud) {
    int menu = 0;
    while (menu != 4) {
        system("cls");
        std::cout << "\t���� ������ � ���������\n";
        std::cout << "=======================================\n\n";
        std::cout << "1.����������� ������ ���������.\n"
            "2.������������� ������.\n"
            "3.����� ��������.\n"
            "4.��������� � ����.\n";
        checkInt(menu);
        switch (menu) {
        case 1:
            system("cls");
            if (vecStud.size() == 0) {
                std::cout << std::endl << "������ ����." << std::endl << std::endl;
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
            std::cout << "������ �����!!\n";
            break;
        }
    }
}

void studMenu(std::vector<Student>& vecStud) {
    int menu = 0;
    while (menu != 7) {
        system("cls");
        std::cout << "\t���� ������ � ���������\n";
        std::cout << "=======================================\n\n";
        std::cout << "1.����������� ������ ���������.\n"
            "2.�������� ��������.\n"
            "3.������� ��������.\n"
            "4.������������� ������.\n"
            "5.�������������� ������.\n"
            "6.����� ��������.\n"
            "7.��������� � ����.\n";
        checkInt(menu);
        switch (menu) {
        case 1:
            system("cls");
            if (vecStud.size() == 0) {
                std::cout << std::endl << "������ ����." << std::endl << std::endl;
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
            std::cout << "������ �����!!\n";
            break;
        }
    }
}

void dormMenuUser(std::vector<block>& vecBlock) {
    int menu = 0;
    while (menu != 2) {
        system("cls");
        std::cout << "\t���� ������ ���������\n";
        std::cout << "==========================================\n\n";
        std::cout << "1.����������� ������� �����.\n"
                     "2.��������� � ����.\n";
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
            std::cout << "������ �����!!\n";
            break;
        }
    }
}

//���� ��� ������ � ����������� ���������
void dormMenu(std::vector<block>& vecBlock, std::vector<Student>& vecStud) { 
    int menu = 0, val{0};
    while (menu != 5) {
        system("cls");
        std::cout << "\t���� ������ ���������\n";
        std::cout << "==========================================\n\n";
        std::cout //<< "1.����������� ������ ������ �� �����.\n"
            //<< "2.����������� ������ ������ � ����������� ������.\n"
            << "1.����������� ������� �����.\n"
            "2.������������� ������� �������.\n"
            "3.������ ��������� ���������.\n"
            "4.�������� ����.\n"
            "5.��������� � ����.\n";
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
                std::cout << "\t������\n����� �� �������!";
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
            std::cout << "������ �����!!\n";
            break;
        }
    }
}

void find(std::vector<Student>& vecStud) {
    int menu = 0;
    while (menu != 3) {
        system("cls");
        std::cout << "\t\t���� ������\n"
            << "=============================================\n\n";
        std::cout << "1.����� �� ���.\n"
            "2.����� �� ������ ������.\n"
            "3.��������� � ����.\n";
          
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
            std::cout << "������ �����!!\n";
            break;
        }
    }
}