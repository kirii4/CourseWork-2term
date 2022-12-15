#include "list.h"

void add(std::vector<Student>& vecStud) { //Ввод нового студента
    if (vecStud.size() >= MAX_VECTOR_SIZE) std::cout << "Превышение размерности списка!!!\n";
    else {
        Student s;
        std::cout << "Введите номер студенческого билета: (8 цифр)\n";
        bool val = true;
        do {
            checkID(s.ID);
            if (check_ID(s.ID, vecStud)) {
                val = false;
            }else {
                std::cout << "Номер студенческого билета уже имеется в базе.\n";
            }
        } while (val);
        std::cout << "Введите фамилию:\n";
        checkString(s.fio.surname);
        std::cout << "Введите имя:\n";
        checkString(s.fio.name);
        std::cout << "Введите отчество:\n";
        checkString(s.fio.patronymic);
        std::cout << "Введите пол студента(woman, man): ";
        checkSex(s.sex);   
        std::cout << "Введите номер группы: (6 цифр)\n";
        checkGroup(s.num_group);
        std::cout << "Введите средний балл:\n";
        checkMarks(s.avr_marks);
        std::cout << "Введите общественную деятельность(0 / 1):\n";
        checkWork(s.is_worked);
        std::cout << "Введите доход на одного члена семьи (BYN):\n";
        checkDouble(s.sal_par);
        s.checkIn = 0;
        vecStud.push_back(s);
        accessAdd();
    }
}

void del(std::vector<Student>& vecStud) { //Удаление студента по номеру
    if (vecStud.size() == 0) std::cout << std::endl << "Список пуст." << std::endl << std::endl;
    else {
        print_console(vecStud);
        std::cout << "Введите индекс удаляемого поля.\n";
        int num;
        while (true) {
            checkInt(num);
            num--;
            if (num >= vecStud.size() || num < 0) std::cout << "\nНеверный ввод номера!\n";
            else {
                std::string val;
                std::cout << "\nВы согласны удалить поле(y/n): \n";
                checkDel(val);
                if (val == "n" || val == "N") {
                    std::cout << "\nУдаление отменено!\n\n";
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
        std::cout << std::endl << "Список пуст." << std::endl << std::endl;
    }
    else {
        std::cout << "Введите номер элемента для изменения.\n";
        int num_list;
        checkInt(num_list);
        while (!(num_list > 0 && num_list <= vecStud.size())) {
            std::cout << "Неверный ввод номера!\n";
            checkInt(num_list);
        }
        std::cout << "Изменить:\n"
            "1.Фамилию.\n"
            "2.Имя.\n"
            "3.Отчество.\n"
            "4.Номер группы.\n"
            "5.Выполнение общественной деятельности.\n"
            "6.Среднний балл.\n"
            "7.Доход на члена семьи.\n";
        int menu;
        std::string _surname;
        std::string _name;
        std::string _patronymic;
        int _num_group;
        int _is_worked;
        double _avr_marks;
        double _sal_par;
        checkInt(menu);
        std::cout << "Текущее значение: ";
        switch (menu) {
        case 1: //изменение фамилии
            std::cout << vecStud[num_list - 1].fio.surname << ".\n"
                << "Введите новое значение: ";
            checkString(_surname);
            vecStud[num_list - 1].fio.surname = _surname;
            break;
        case 2: //изменение имени 
            std::cout << vecStud[num_list - 1].fio.name << ".\n"
                << "Введите новое значение: ";
            checkString(_name);
            vecStud[num_list - 1].fio.name = _name;
            break;
        case 3: //изменение отчества 
            std::cout << vecStud[num_list - 1].fio.patronymic << ".\n"
                << "Введите новое значение: ";
            checkString(_patronymic);
            vecStud[num_list - 1].fio.patronymic = _patronymic;
            break;
        case 4: //изменение номера группы
            std::cout << vecStud[num_list - 1].num_group << ".\n"
                << "Введите новое значение: ";
            checkGroup(_num_group);
            vecStud[num_list - 1].num_group = _num_group;
            break;
        case 5: //изменение общ. деятельности
            std::cout << vecStud[num_list - 1].is_worked << ".\n"
                << "Введите новое значение: ";
            checkWork(_is_worked);
            vecStud[num_list - 1].is_worked = _is_worked;
            break;
        case 6: //изменение среднего балла
            std::cout << vecStud[num_list - 1].avr_marks << ".\n"
                << "Введите новое значение: ";
            checkMarks(_avr_marks);
            vecStud[num_list - 1].avr_marks = _avr_marks;
            break;
        case 7:  //изменение дохода
            std::cout << vecStud[num_list - 1].sal_par << ".\n"
                << "Введите новое значение: ";
            checkDouble(_sal_par);
            vecStud[num_list - 1].sal_par = _sal_par;
            break;
        default:
            std::cout << "Ошибка ввода!!\n";
            break;
        }
        accessEdit();
    }
}

void findGroup(std::vector<Student>& vecStud) {
    std::cout << "Введите номер группы(6 чисел): ";
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
        std::cout << "Студентов по запрошенной группе не найдено!\n";
    }
}

void find_stud(std::vector<Student>& vecStud) {
    std::cout << "Введите ФИО студента: ";
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
        std::cout << "Студентов по запрошенной фамилии не найдено!\n";
    }
    std::cout << std::endl;
}

void print_console(std::vector<Student>& s) { //Вывод в консоль
    printf("+---------------------------------------------------------------------------------------------------------+-------+\n");
    printf("|      Студ.ном.                 ФИО                          | Группа|   Ср.балл   Труд.деят.      Доход |Заселен|\n");
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