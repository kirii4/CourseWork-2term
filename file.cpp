#include "file.h"

void file_input(std::vector<Student>& vecStud) {
    std::ifstream f_in(fileStud);

    if (!f_in.is_open()) {
        std::cout << "\nОшибка открытия файла!" << std::endl;
        exit(0);
    }
    else {
        Student n;
        while (f_in >> n.ID &&
            f_in >> n.fio.surname &&
            f_in >> n.fio.name &&
            f_in >> n.fio.patronymic &&
            f_in >> n.sex &&
            f_in >> n.num_group &&
            f_in >> n.avr_marks &&
            f_in >> n.is_worked &&
            f_in >> n.sal_par &&
            f_in >> n.checkIn) {//Запись из файла в вектор
            if (vecStud.size() >= MAX_VECTOR_SIZE) {
                std::cout << "\n\nПревышение размерности списка!!!.\n";
                break;
            }
            vecStud.push_back(n);
        }
    }
    f_in.close();
}

void file_input(std::vector<input>& vecAcc, std::string data) {
    std::ifstream f_in(data);

    if (!f_in.is_open()) {
        std::cout << "\nОшибка открытия файла!" << std::endl;
        exit(0);
    }
    else {
        input n;
        while (f_in >> n.login &&
            f_in >> n.password &&
            f_in >> n.role) {//Запись из файла в вектор
            if (vecAcc.size() >= MAX_VECTOR_SIZE) {
                std::cout << "\n\nПревышение размерности списка!!!.\n";
                break;
            }
            vecAcc.push_back(n);
        }
    }
    f_in.close();
}

void file_output(std::vector<Student>& vecStud) {
    std::ofstream fout(fileStud, std::ios_base::out | std::ios_base::trunc);
    if (!fout.is_open()) {
        std::cout << "\nОшибка открытия файла!" << std::endl;
        exit(1);
    }
    else {
        print_file(vecStud, fout);
    }
    fout.close();
}

void file_output(std::vector<input>& vecReg) {
    std::ofstream fout(fileReg, std::ios_base::out | std::ios_base::trunc);
    if (!fout.is_open()) {
        std::cout << "\nОшибка открытия файла!" << std::endl;
        exit(1);
    }
    else {
        print_file(vecReg, fout);
    }
    fout.close();
}

void file_AccOutput(std::vector<input>& vecAcc) {
    std::ofstream fout(fileAcc, std::ios_base::out | std::ios_base::trunc);
    if (!fout.is_open()) {
        std::cout << "\nОшибка открытия файла!" << std::endl;
        exit(1);
    }
    else {
        print_file(vecAcc, fout);
    }
    fout.close();
}

void print_file(std::vector<Student>& vecStud, std::ofstream& fl) { //Вывод в файл
    for (auto i = 0; i < vecStud.size(); i++) {
        fl << vecStud[i].ID << ' ' << vecStud[i].fio.surname << ' ' << vecStud[i].fio.name << ' ' << vecStud[i].fio.patronymic
            << ' ' << vecStud[i].sex << ' ' << vecStud[i].num_group << ' ' << vecStud[i].avr_marks
            << ' ' << vecStud[i].is_worked << ' ' << vecStud[i].sal_par << ' ' << vecStud[i].checkIn << std::endl;
    }
}

void print_file(std::vector<input>& vecStud, std::ofstream& fl) { //Вывод в файл
    for (auto i = 0; i < vecStud.size(); i++) {
        fl << vecStud[i].login << ' '
            << vecStud[i].password << ' '
            << vecStud[i].role << std::endl;
    }
}

void print_file(input obj, std::ofstream& fl) { //Вывод в файл
    fl << obj.login << ' '
        << obj.password << ' '
        << obj.role << std::endl;
}

void fileblockInput(std::vector<block>& vecBlock) {
    std::ifstream f_in(fileBlock, std::ios_base::in);

    if (!f_in.is_open()) {
        std::cout << "\nОшибка открытия файла!" << std::endl;
        exit(0);
    }else {
        block d;
        while ((f_in >> d.roomA[0].numRoom 
            >> d.roomA[0].student.surname 
            >> d.roomA[0].student.name
            >> d.roomA[0].student.patronymic
            >> d.roomA[0].checkInDate.day
            >> d.roomA[0].checkInDate.month
            >> d.roomA[0].checkInDate.year
            >> d.roomA[0].gender) &&
               (f_in >> d.roomA[1].numRoom
                   >> d.roomA[1].student.surname
                   >> d.roomA[1].student.name
                   >> d.roomA[1].student.patronymic
                   >> d.roomA[1].checkInDate.day
                   >> d.roomA[1].checkInDate.month
                   >> d.roomA[1].checkInDate.year
                   >> d.roomA[1].gender) &&
                   (f_in >> d.roomB[0].numRoom 
                       >> d.roomB[0].student.surname
                       >> d.roomB[0].student.name
                       >> d.roomB[0].student.patronymic
                       >> d.roomB[0].checkInDate.day
                       >> d.roomB[0].checkInDate.month
                       >> d.roomB[0].checkInDate.year
                       >> d.roomB[0].gender) &&
                       (f_in >> d.roomB[1].numRoom
                           >> d.roomB[1].student.surname
                           >> d.roomB[1].student.name
                           >> d.roomB[1].student.patronymic
                           >> d.roomB[1].checkInDate.day
                           >> d.roomB[1].checkInDate.month
                           >> d.roomB[1].checkInDate.year
                           >> d.roomB[1].gender)) {//Запись из файла в вектор
            if (vecBlock.size() >= MAX_BLOCKS) {
                std::cout << "\n\nПревышение размерности списка!!!.\n";
                break;
            }
            vecBlock.push_back(d);
        }
    }
    f_in.close();
    if (vecBlock.size() != MAX_BLOCKS) {
        system("cls");
        std::cout << std::endl << "Некорректнное считывание данных о общежитии." << std::endl;
        exit(1);
    }
}

void fileblockOutput(std::vector<block>& vecBlock){
    std::ofstream fout(fileBlock, std::ios_base::out | std::ios_base::trunc);
    if (!fout.is_open()) {
        std::cout << "\nОшибка открытия файла!" << std::endl;
        exit(0);
    }
    else {
        for (auto i = 0U; i < vecBlock.size(); i++) {
            fout << vecBlock[i].roomA[0].numRoom << ' '
                << vecBlock[i].roomA[0].student.surname << ' '
                << vecBlock[i].roomA[0].student.name << ' '
                << vecBlock[i].roomA[0].student.patronymic << ' '
                << vecBlock[i].roomA[0].checkInDate.day << ' '
                << vecBlock[i].roomA[0].checkInDate.month << ' '
                << vecBlock[i].roomA[0].checkInDate.year << ' '
                << vecBlock[i].roomA[0].gender << std::endl;
            fout << vecBlock[i].roomA[1].numRoom << ' '
                << vecBlock[i].roomA[1].student.surname << ' '
                << vecBlock[i].roomA[1].student.name << ' '
                << vecBlock[i].roomA[1].student.patronymic << ' '
                << vecBlock[i].roomA[1].checkInDate.day << ' '
                << vecBlock[i].roomA[1].checkInDate.month << ' '
                << vecBlock[i].roomA[1].checkInDate.year << ' '
                << vecBlock[i].roomA[1].gender << std::endl;
            fout << vecBlock[i].roomB[0].numRoom << ' '
                << vecBlock[i].roomB[0].student.surname << ' '
                << vecBlock[i].roomB[0].student.name << ' '
                << vecBlock[i].roomB[0].student.patronymic << ' '
                << vecBlock[i].roomB[0].checkInDate.day << ' '
                << vecBlock[i].roomB[0].checkInDate.month << ' '
                << vecBlock[i].roomB[0].checkInDate.year << ' '
                << vecBlock[i].roomB[0].gender << std::endl;
            fout << vecBlock[i].roomB[1].numRoom << ' '
                << vecBlock[i].roomB[1].student.surname << ' '
                << vecBlock[i].roomB[1].student.name << ' '
                << vecBlock[i].roomB[1].student.patronymic << ' '
                << vecBlock[i].roomB[1].checkInDate.day << ' '
                << vecBlock[i].roomB[1].checkInDate.month << ' '
                << vecBlock[i].roomB[1].checkInDate.year << ' '
                << vecBlock[i].roomB[1].gender << std::endl;
        }
    }
    fout.close();   
}

void createAdmin() {
    std::ofstream acc(fileAcc);
    acc << "admin " << 16559146482384667732 << ' ' << 1; //Заполнение файла аккаунтом базового админа
}                                                        //16559146482384667732 = hash("admin")