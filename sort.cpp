#include "sort.h"

void sort_menu(std::vector<Student>& vecStud) { //Меню сортировки
    system("cls");
    int menu = 0;
    std::cout << "\tМеню сортировки\n"
        << "==================================\n\n";
    while (menu != 8) {
        std::cout << "1.Отсортировать по номеру студенческого билета.\n"
            "2.Отсортировать по алфавиту.\n"
            "3.Отсортировать по номеру группы.\n"
            "4.Отсортировать по среднему баллу.\n"
            "5.Отсортировать по выполнению общественной деятельности.\n"
            "6.Отсортировать по доходу семьи.\n"
            "7.Отсортировать согласно правилам заселения студентов(инд. зад.).\n"
            "8.Вернуться в меню.\n";
        checkInt(menu);
        switch (menu) {
        case 1:
            system("cls");
            ID_sort(vecStud);
            std::cout << "\t\t\t\t\t" << "Сортировка по номеру студенческого билета." << std::endl << std::endl;
            print_console(vecStud);
            system("pause");
            break;
        case 2:
            system("cls");
            alph_sort(vecStud);
            std::cout << "\t\t\t\t\t" << "Сортировка по алфавиту." << std::endl << std::endl;
            print_console(vecStud);
            system("pause");
            break;
        case 3:
            system("cls");
            group_sort(vecStud);
            std::cout << "\t\t\t\t\t" << "Сортировка по номеру группы." << std::endl << std::endl;
            print_console(vecStud);
            system("pause");
            break;
        case 4:
            system("cls");
            marks_sort(vecStud);
            std::cout << "\t\t\t\t\t" << "Сортировка по среднему баллу." << std::endl << std::endl;
            print_console(vecStud);
            system("pause");
            break;
        case 5:
            system("cls");
            work_sort(vecStud);
            std::cout << "\t\t\t\t\t" << "Сортировка по выполнению общественной деятельности." << std::endl << std::endl;
            print_console(vecStud);
            system("pause");
            break;
        case 6:
            system("cls");
            salary_sort(vecStud);
            std::cout << "\t\t\t\t\t" << "Сортировка по кол-ву дохода." << std::endl << std::endl;
            print_console(vecStud);
            system("pause");
            break;
        case 7:
            system("cls");
            salary_sort(vecStud);
            checkInWithData_sort(vecStud);
            std::cout << "\t\t\t\t\t" << "Сортировка согласно правилам заселения." << std::endl << std::endl;
            print_console(vecStud);
            system("pause");
            break;
        case 8:
            system("cls");
            break;
        default:
            std::cout << "\nОшибка ввода!!\n";
            break;
        }
    }
}

bool is_ID_sort(Student vecStud1, Student vecStud2) { //Компаратор для sort
    return vecStud1.ID < vecStud2.ID;
}

void ID_sort(std::vector<Student>& vecStud) { //Сортировка по алфавиту
    if (vecStud.size() == 0) {
        std::cout << std::endl << "Список пуст." << std::endl << std::endl;
    }
    else {
        sort(vecStud.begin(), vecStud.end(), is_ID_sort);
    }
}

bool is_alph_sort(Student vecStud1, Student vecStud2) { //Компаратор для sort
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

void alph_sort(std::vector<Student>& vecStud) { //Сортировка по алфавиту
    if (vecStud.size() == 0) {
        std::cout << std::endl << "Список пуст." << std::endl << std::endl;
    }else {
        sort(vecStud.begin(), vecStud.end(), is_alph_sort); 
    }
}

bool is_group_sort(Student vecStud1, Student vecStud2) { 
    return vecStud1.num_group < vecStud2.num_group;
}

void group_sort(std::vector<Student>& vecStud) { //Сортировка по номеру группы
    if (vecStud.size() == 0) {
        std::cout << std::endl << "Список пуст." << std::endl << std::endl;
    }else {
        sort(vecStud.begin(), vecStud.end(), is_group_sort);
    }
}

bool is_marks_sort(Student vecStud1, Student vecStud2) { 
    return vecStud1.avr_marks > vecStud2.avr_marks;
}

void marks_sort(std::vector<Student>& vecStud) { //Сортировка по среднему баллу
    if (vecStud.size() == 0) { 
        std::cout << std::endl << "Список пуст." << std::endl << std::endl; 
    }else {
        sort(vecStud.begin(), vecStud.end(), is_marks_sort);
    }
}

bool is_work_sort(Student vecStud1, Student vecStud2) {
    return vecStud1.is_worked > vecStud2.is_worked;
}

void work_sort(std::vector<Student>& vecStud) { //Сортировка по выполнению общественной деятельности
    if (vecStud.size() == 0) {
        std::cout << std::endl << "Список пуст." << std::endl << std::endl;
    }
    else {
        sort(vecStud.begin(), vecStud.end(), is_work_sort);
    }
}

bool is_salary_sort(Student vecStud1, Student vecStud2) {
    return vecStud1.sal_par < vecStud2.sal_par;
}

void salary_sort(std::vector<Student>& vecStud) { //Сортировка по уровню дохода семьи
    if (vecStud.size() == 0) {
        std::cout << std::endl << "Список пуст." << std::endl << std::endl;
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

void checkInWithData_sort(std::vector<Student>& vecStud) { //Сортировка по уровню дохода семьи
    if (vecStud.size() == 0) {
        std::cout << std::endl << "Список пуст." << std::endl << std::endl;
    }
    else {
        std::cout << "Введите размер минимальной зарплаты.\n";
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

void secondCheckIn_sort(std::vector<Student>& vecStud) { //Сортировка по уровню дохода семьи
    if (vecStud.size() == 0) {
        std::cout << std::endl << "Список пуст." << std::endl << std::endl;
    }
    else {
        sort(vecStud.begin(), vecStud.end(), is_secondCheckIn_sort);
    }
}