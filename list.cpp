#include "list.h"

void add(std::vector<Student>& vecStud) { //���� ������ ��������
    if (vecStud.size() >= MAX_VECTOR_SIZE) std::cout << "���������� ����������� ������!!!\n";
    else {
        Student s;
        std::cout << "������� ����� ������������� ������: (8 ����)\n";
        bool val = true;
        do {
            checkID(s.ID);
            if (check_ID(s.ID, vecStud)) {
                val = false;
            }else {
                std::cout << "����� ������������� ������ ��� ������� � ����.\n";
            }
        } while (val);
        std::cout << "������� �������:\n";
        checkString(s.fio.surname);
        std::cout << "������� ���:\n";
        checkString(s.fio.name);
        std::cout << "������� ��������:\n";
        checkString(s.fio.patronymic);
        std::cout << "������� ��� ��������(woman, man): ";
        checkSex(s.sex);   
        std::cout << "������� ����� ������: (6 ����)\n";
        checkGroup(s.num_group);
        std::cout << "������� ������� ����:\n";
        checkMarks(s.avr_marks);
        std::cout << "������� ������������ ������������(0 / 1):\n";
        checkWork(s.is_worked);
        std::cout << "������� ����� �� ������ ����� ����� (BYN):\n";
        checkDouble(s.sal_par);
        s.checkIn = 0;
        vecStud.push_back(s);
        accessAdd();
    }
}

void del(std::vector<Student>& vecStud) { //�������� �������� �� ������
    if (vecStud.size() == 0) std::cout << std::endl << "������ ����." << std::endl << std::endl;
    else {
        print_console(vecStud);
        std::cout << "������� ������ ���������� ����.\n";
        int num;
        while (true) {
            checkInt(num);
            num--;
            if (num >= vecStud.size() || num < 0) std::cout << "\n�������� ���� ������!\n";
            else {
                std::string val;
                std::cout << "\n�� �������� ������� ����(y/n): \n";
                checkDel(val);
                if (val == "n" || val == "N") {
                    std::cout << "\n�������� ��������!\n\n";
                    break;
                }
                else {
                    vecStud.erase(vecStud.begin() + num);
                    accessDelete();
                    break;
                }
            }
        }
    }
}

void editing_a_list(std::vector<Student>& vecStud) {
    if (vecStud.size() == 0) {
        std::cout << std::endl << "������ ����." << std::endl << std::endl;
    }
    else {
        std::cout << "������� ����� �������� ��� ���������.\n";
        int num_list;
        checkInt(num_list);
        while (!(num_list > 0 && num_list <= vecStud.size())) {
            std::cout << "�������� ���� ������!\n";
            checkInt(num_list);
        }
        std::cout << "��������:\n"
            "1.�������.\n"
            "2.���.\n"
            "3.��������.\n"
            "4.����� ������.\n"
            "5.���������� ������������ ������������.\n"
            "6.�������� ����.\n"
            "7.����� �� ����� �����.\n";
        int menu;
        std::string _surname;
        std::string _name;
        std::string _patronymic;
        int _num_group;
        int _is_worked;
        double _avr_marks;
        double _sal_par;
        checkInt(menu);
        std::cout << "������� ��������: ";
        switch (menu) {
        case 1: //��������� �������
            std::cout << vecStud[num_list - 1].fio.surname << ".\n"
                << "������� ����� ��������: ";
            checkString(_surname);
            vecStud[num_list - 1].fio.surname = _surname;
            break;
        case 2: //��������� ����� 
            std::cout << vecStud[num_list - 1].fio.name << ".\n"
                << "������� ����� ��������: ";
            checkString(_name);
            vecStud[num_list - 1].fio.name = _name;
            break;
        case 3: //��������� �������� 
            std::cout << vecStud[num_list - 1].fio.patronymic << ".\n"
                << "������� ����� ��������: ";
            checkString(_patronymic);
            vecStud[num_list - 1].fio.patronymic = _patronymic;
            break;
        case 4: //��������� ������ ������
            std::cout << vecStud[num_list - 1].num_group << ".\n"
                << "������� ����� ��������: ";
            checkGroup(_num_group);
            vecStud[num_list - 1].num_group = _num_group;
            break;
        case 5: //��������� ���. ������������
            std::cout << vecStud[num_list - 1].is_worked << ".\n"
                << "������� ����� ��������: ";
            checkWork(_is_worked);
            vecStud[num_list - 1].is_worked = _is_worked;
            break;
        case 6: //��������� �������� �����
            std::cout << vecStud[num_list - 1].avr_marks << ".\n"
                << "������� ����� ��������: ";
            checkMarks(_avr_marks);
            vecStud[num_list - 1].avr_marks = _avr_marks;
            break;
        case 7:  //��������� ������
            std::cout << vecStud[num_list - 1].sal_par << ".\n"
                << "������� ����� ��������: ";
            checkDouble(_sal_par);
            vecStud[num_list - 1].sal_par = _sal_par;
            break;
        default:
            std::cout << "������ �����!!\n";
            break;
        }
        accessEdit();
    }
}

void findGroup(std::vector<Student>& vecStud) {
    std::cout << "������� ����� ������(6 �����): ";
    int group;
    checkGroup(group);
    int k = 0;
    std::cout << std::endl;
    for (auto i = 0U; i < vecStud.size(); i++) {
        if (vecStud[i].num_group == group) {
            printSoloStud(vecStud[i], k);
        }
    }
    if (k == 0) {
        std::cout << "��������� �� ����������� ������ �� �������!\n";
    }
}

void find_stud(std::vector<Student>& vecStud) {
    std::cout << "������� ��� ��������: ";
    std::string name;
    checkFind(name);
    //std::cout << name << std::endl;
    int k = 0;
    std::cout << std::endl;
    for (auto i = 0U; i < vecStud.size(); i++) {
        std::string _name = vecStud[i].fio.surname + ' ' + vecStud[i].fio.name + ' ' + vecStud[i].fio.patronymic;
        if (_name.find(name) != std::string::npos) {
            printSoloStud(vecStud[i], k);
        }
    }
    if (k == 0) {
        std::cout << "��������� �� ����������� ������� �� �������!\n";
    }
    std::cout << std::endl;
}

void print_console(std::vector<Student>& s) { //����� � �������
    printf("+---------------------------------------------------------------------------------------------------------+-------+\n");
    printf("|      ����.���.                 ���                          | ������|   ��.����   ����.����.      ����� |�������|\n");
    printf("+---------------------------------------------------------------------------------------------------------|-------+\n");
    for (auto i = 0; i < s.size(); i++) {
        printf("|%3d.  %-8d  %-14s %-14s %-15s| %6d| %8.2lf %8d %12.2lf BYN| %3c   |\n",
            i + 1, s[i].ID, s[i].fio.surname.c_str(), s[i].fio.name.c_str(), s[i].fio.patronymic.c_str(), s[i].num_group, 
            s[i].avr_marks, s[i].is_worked, s[i].sal_par, (s[i].checkIn == 1)? '+': '-');
    }
    printf("+-----------------------------------------------------------------------------------------------------------------+\n\n");
}

void printSoloStud(Student stud, int& k) {
    printf("%3d. %-8d  %-14s %-14s %-15s %6d\n",
        ++k, stud.ID, stud.fio.surname.c_str(), stud.fio.name.c_str(), stud.fio.patronymic.c_str(), stud.num_group);
}