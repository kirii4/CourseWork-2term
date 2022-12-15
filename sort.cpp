#include "sort.h"

void sort_menu(std::vector<Student>& vecStud) { //���� ����������
    system("cls");
    int menu = 0;
    std::cout << "\t���� ����������\n"
        << "==================================\n\n";
    while (menu != 8) {
        std::cout << "1.������������� �� ������ ������������� ������.\n"
            "2.������������� �� ��������.\n"
            "3.������������� �� ������ ������.\n"
            "4.������������� �� �������� �����.\n"
            "5.������������� �� ���������� ������������ ������������.\n"
            "6.������������� �� ������ �����.\n"
            "7.������������� �������� �������� ��������� ���������(���. ���.).\n"
            "8.��������� � ����.\n";
        checkInt(menu);
        switch (menu) {
        case 1:
            system("cls");
            ID_sort(vecStud);
            std::cout << "\t\t\t\t\t" << "���������� �� ������ ������������� ������." << std::endl << std::endl;
            print_console(vecStud);
            system("pause");
            break;
        case 2:
            system("cls");
            alph_sort(vecStud);
            std::cout << "\t\t\t\t\t" << "���������� �� ��������." << std::endl << std::endl;
            print_console(vecStud);
            system("pause");
            break;
        case 3:
            system("cls");
            group_sort(vecStud);
            std::cout << "\t\t\t\t\t" << "���������� �� ������ ������." << std::endl << std::endl;
            print_console(vecStud);
            system("pause");
            break;
        case 4:
            system("cls");
            marks_sort(vecStud);
            std::cout << "\t\t\t\t\t" << "���������� �� �������� �����." << std::endl << std::endl;
            print_console(vecStud);
            system("pause");
            break;
        case 5:
            system("cls");
            work_sort(vecStud);
            std::cout << "\t\t\t\t\t" << "���������� �� ���������� ������������ ������������." << std::endl << std::endl;
            print_console(vecStud);
            system("pause");
            break;
        case 6:
            system("cls");
            salary_sort(vecStud);
            std::cout << "\t\t\t\t\t" << "���������� �� ���-�� ������." << std::endl << std::endl;
            print_console(vecStud);
            system("pause");
            break;
        case 7:
            system("cls");
            salary_sort(vecStud);
            checkInWithData_sort(vecStud);
            std::cout << "\t\t\t\t\t" << "���������� �������� �������� ���������." << std::endl << std::endl;
            print_console(vecStud);
            system("pause");
            break;
        case 8:
            system("cls");
            break;
        default:
            std::cout << "\n������ �����!!\n";
            break;
        }
    }
}

bool is_ID_sort(Student vecStud1, Student vecStud2) { //���������� ��� sort
    return vecStud1.ID < vecStud2.ID;
}

void ID_sort(std::vector<Student>& vecStud) { //���������� �� ��������
    if (vecStud.size() == 0) {
        std::cout << std::endl << "������ ����." << std::endl << std::endl;
    }
    else {
        sort(vecStud.begin(), vecStud.end(), is_ID_sort);
    }
}

bool is_alph_sort(Student vecStud1, Student vecStud2) { //���������� ��� sort
    if (vecStud1.fio.surname == vecStud2.fio.surname) {
        if (vecStud1.fio.name == vecStud2.fio.name) {
            return vecStud1.fio.patronymic < vecStud2.fio.patronymic;
        }else {
            return vecStud1.fio.name < vecStud1.fio.name;
        }
    }else {
        return vecStud1.fio.surname < vecStud2.fio.surname;
    }
}

void alph_sort(std::vector<Student>& vecStud) { //���������� �� ��������
    if (vecStud.size() == 0) {
        std::cout << std::endl << "������ ����." << std::endl << std::endl;
    }else {
        sort(vecStud.begin(), vecStud.end(), is_alph_sort); 
    }
}

bool is_group_sort(Student vecStud1, Student vecStud2) { 
    return vecStud1.num_group < vecStud2.num_group;
}

void group_sort(std::vector<Student>& vecStud) { //���������� �� ������ ������
    if (vecStud.size() == 0) {
        std::cout << std::endl << "������ ����." << std::endl << std::endl;
    }else {
        sort(vecStud.begin(), vecStud.end(), is_group_sort);
    }
}

bool is_marks_sort(Student vecStud1, Student vecStud2) { 
    return vecStud1.avr_marks > vecStud2.avr_marks;
}

void marks_sort(std::vector<Student>& vecStud) { //���������� �� �������� �����
    if (vecStud.size() == 0) { 
        std::cout << std::endl << "������ ����." << std::endl << std::endl; 
    }else {
        sort(vecStud.begin(), vecStud.end(), is_marks_sort);
    }
}

bool is_work_sort(Student vecStud1, Student vecStud2) {
    return vecStud1.is_worked > vecStud2.is_worked;
}

void work_sort(std::vector<Student>& vecStud) { //���������� �� ���������� ������������ ������������
    if (vecStud.size() == 0) {
        std::cout << std::endl << "������ ����." << std::endl << std::endl;
    }
    else {
        sort(vecStud.begin(), vecStud.end(), is_work_sort);
    }
}

bool is_salary_sort(Student vecStud1, Student vecStud2) {
    return vecStud1.sal_par < vecStud2.sal_par;
}

void salary_sort(std::vector<Student>& vecStud) { //���������� �� ������ ������ �����
    if (vecStud.size() == 0) {
        std::cout << std::endl << "������ ����." << std::endl << std::endl;
    }
    else {
        sort(vecStud.begin(), vecStud.end(), is_salary_sort);
    }
}

bool is_checkIn_sort(Student vecStud1, Student vecStud2) {
    if (vecStud1.sal_par == vecStud2.sal_par) {
        if (vecStud1.avr_marks == vecStud2.avr_marks) {
            return vecStud1.is_worked > vecStud2.is_worked;
        }else {
            return vecStud1.avr_marks > vecStud2.avr_marks;
        }
    }
    else {
        return vecStud1.sal_par < vecStud2.sal_par;
    }
}

bool is_checkInWithData_sort(Student vecStud1, Student vecStud2) {
    if (vecStud1.avr_marks == vecStud2.avr_marks) {
        return vecStud1.is_worked > vecStud2.is_worked;
    }else {
        return vecStud1.avr_marks > vecStud2.avr_marks;
    }
}

void checkInWithData_sort(std::vector<Student>& vecStud) { //���������� �� ������ ������ �����
    if (vecStud.size() == 0) {
        std::cout << std::endl << "������ ����." << std::endl << std::endl;
    }
    else {
        std::cout << "������� ������ ����������� ��������.\n";
        double salary = 0;
        checkDouble(salary);
        int i = 0;
        while (vecStud[i++].sal_par <= salary && i < vecStud.size());
        i--;
        //std::cout << i << std::endl;
        sort(vecStud.begin(), vecStud.end(), is_salary_sort);
        sort(vecStud.begin(), vecStud.begin() + i, is_checkIn_sort);
        sort(vecStud.begin() + i, vecStud.end(), is_checkInWithData_sort);
        
    }
}

bool is_secondCheckIn_sort(Student vecStud1, Student vecStud2) {
    return vecStud1.checkIn < vecStud2.checkIn;
}

void secondCheckIn_sort(std::vector<Student>& vecStud) { //���������� �� ������ ������ �����
    if (vecStud.size() == 0) {
        std::cout << std::endl << "������ ����." << std::endl << std::endl;
    }
    else {
        sort(vecStud.begin(), vecStud.end(), is_secondCheckIn_sort);
    }
}