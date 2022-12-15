#include "dorm.h"

void printFloor(std::vector<block>& vecBlock) {
	std::cout << "Введите номер этажа: (1-" << vecBlock.size() / BLOCKS_ON_FLOOR << ')' << std::endl;
	int floor;
	checkFloor(floor);
    system("cls");
    std::cout << "\t\t\tИнформация о " << floor << " этаже" << std::endl << std::endl;
    floor--;
    printf("+----------------------------------------------------------------------+\n");
    printf("|  № Комнаты                      ФИО                    Дата заселения|\n");
    printf("+----------------------------------------------------------------------+\n");
    for (auto i = floor * BLOCKS_ON_FLOOR; i < (floor + 1) * BLOCKS_ON_FLOOR; i++) {
        printBlock(vecBlock[i]);
        std::cout << "|                                                                      |\n";
    }
    printf("+----------------------------------------------------------------------+\n\n");
}

void printBlock(block block) {
    for (auto i = 0U; i < 2; i++) {
        printf("|%8s %14s %14s %15s %7s.%2s.%4s|\n", block.roomA[i].numRoom.c_str(), 
            block.roomA[i].student.surname.c_str(), block.roomA[i].student.name.c_str(),
            block.roomA[i].student.patronymic.c_str(), block.roomA[i].checkInDate.day.c_str(),
            block.roomA[i].checkInDate.month.c_str(), block.roomA[i].checkInDate.year.c_str());
    }
    for (auto i = 0U; i < 2; i++) {
        printf("|%8s %14s %14s %15s %7s.%2s.%4s|\n", block.roomB[i].numRoom.c_str(), 
            block.roomB[i].student.surname.c_str(), block.roomB[i].student.name.c_str(),
            block.roomB[i].student.patronymic.c_str(), block.roomB[i].checkInDate.day.c_str(),
            block.roomB[i].checkInDate.month.c_str(), block.roomB[i].checkInDate.year.c_str());
    }
}

void checkIn(std::vector<block>& vecBlock, std::vector<Student>& vecStud) {
    uint16_t freeRoom{ 0 }, freeStud{ 0 };
    int16_t val{ 0 };
    for (auto i = 0U; i < vecBlock.size(); i++) {
        if (vecBlock[i].roomA[0].checkInDate.year == "0000") freeRoom++;
        if (vecBlock[i].roomA[1].checkInDate.year == "0000") freeRoom++;
        if (vecBlock[i].roomB[0].checkInDate.year == "0000") freeRoom++;
        if (vecBlock[i].roomB[1].checkInDate.year == "0000") freeRoom++;
    }
    //std::cout << freeRoom << std::endl;
    for (auto i = 0U; i < vecStud.size(); i++) {
        if (vecStud[i].checkIn == 0) {
            freeStud++;
        }
    }

    if (freeRoom == 0) {
        std::cout << "Свободных комнат нет." << std::endl;
    }else if (freeStud == 0) {
        std::cout << "Студентов нуждающихся в общежитии не найдено." << std::endl;
    }
    else {
        checkInWithData_sort(vecStud);  //Сортировка списка студентов по приоритетам заселения
        for (auto i = 0U; i < vecStud.size(); i++) {//Пока есть свободные комнаты
            if (freeRoom == 0) {
                std::cout << "Комнаты для заселения закончились." << std::endl;
                break;
            }
            if (vecStud[i].checkIn == 0) {
                val = randBlock(vecBlock, vecStud[i].sex);
                    
                if (val != -1){
                    mainCheckIn(vecBlock[val], vecStud[i]);
                    freeRoom--;
                }
            }
        }
        std::cout << "Заселение завершено." << std::endl;
    }
}

void secondCheckIn(std::vector<block>& vecBlock, std::vector<Student>& vecStud) {
    secondCheckIn_sort(vecStud);
    for (auto i = 0U; i < vecBlock.size(); i++) {
        if (!isFreeBlock(vecBlock[i])) {
            continue;
        }                   
        for (auto j = 0U; vecStud[j].checkIn == 0; j++) {
            if (genderBlock(vecBlock[i], vecStud[j].sex)) {
                mainCheckIn(vecBlock[i], vecStud[j]);
            }
        }
        secondCheckIn_sort(vecStud);
    }   
}

void mainCheckIn(block& Block, Student& Stud) {
    if (Block.roomA[0].checkInDate.year == "0000") {
        wassup(Block, Stud, 'A', 0);
    }else
    if (Block.roomA[1].checkInDate.year == "0000") {
        wassup(Block, Stud, 'A', 1);
    }else
    if (Block.roomB[0].checkInDate.year == "0000") {
        wassup(Block, Stud, 'B', 0);
    }else
    if (Block.roomB[1].checkInDate.year == "0000") {
        wassup(Block, Stud, 'B', 1);
    }
}

bool isFreeRoom(block Block) {
    if (Block.roomA[0].checkInDate.year == "0000" || Block.roomA[1].checkInDate.year == "0000" ||
        Block.roomB[0].checkInDate.year == "0000" || Block.roomB[1].checkInDate.year == "0000") return true;
    return false;
}

bool isFullBlock(block Block) {
    if (Block.roomA[0].checkInDate.year != "0000" && Block.roomA[1].checkInDate.year != "0000" &&
        Block.roomB[0].checkInDate.year != "0000" && Block.roomB[1].checkInDate.year != "0000")
        return true;
    return false;
}

bool isFreeBlock(block Block) {
    if (Block.roomA[0].checkInDate.year == "0000" && Block.roomA[1].checkInDate.year == "0000" &&
        Block.roomB[0].checkInDate.year == "0000" && Block.roomB[1].checkInDate.year == "0000")
        return true;
    return false;
}

void printNotCheckInStud(std::vector<Student> vecStud) {
    for (auto i = 0U; i < vecStud.size(); i++) {
        if (vecStud[i].checkIn == 0) {
            std::cout << "Для студента " << vecStud[i].fio.surname << ' ' << vecStud[i].fio.name << ' ' << vecStud[i].fio.patronymic << " не нашлось места.\n";
        }
    }
}

int randBlock(std::vector<block> vecBlock,std::string sex) {
    if (sex == "woman") {
        for (auto i = 1U; i < vecBlock.size(); i += 2) {
            if (genderBlock(vecBlock[i],sex) && isFreeRoom(vecBlock[i])) {
                return i;
            }
        }
    }
    if (sex == "man") {
        for (auto i = 0U; i < vecBlock.size(); i += 2) {
            if (genderBlock(vecBlock[i], sex) && isFreeRoom(vecBlock[i])) {
                return i;
            }
        }
    }
    return -1;
}

void wassup(block& block, Student& stud, char val, int iVal){
    time_t seconds = time(NULL);
    tm timeinfo;
    localtime_s(&timeinfo, &seconds);
    std::string year = std::to_string(timeinfo.tm_year + 1900);
    std::string day = (timeinfo.tm_mday < 10)? "0" + std::to_string(timeinfo.tm_mday) : std::to_string(timeinfo.tm_mday);
    std::string month = (timeinfo.tm_mon + 1 < 10)? "0" + std::to_string(timeinfo.tm_mon + 1) : std::to_string(timeinfo.tm_mon + 1);
    //std::cout << day << " " << month << " " << year << std::endl;
    if (val == 'A') { //Комната А
            block.roomA[iVal].student.surname = stud.fio.surname;
            block.roomA[iVal].student.name = stud.fio.name;
            block.roomA[iVal].student.patronymic = stud.fio.patronymic;
            block.roomA[iVal].checkInDate.day = day;
            block.roomA[iVal].checkInDate.month = month;
            block.roomA[iVal].checkInDate.year = year;
            block.roomA[iVal].gender = stud.sex;

    }
    if (val == 'B') { //Комната В
        block.roomB[iVal].student.surname = stud.fio.surname;
        block.roomB[iVal].student.name = stud.fio.name;
        block.roomB[iVal].student.patronymic = stud.fio.patronymic;
        block.roomB[iVal].checkInDate.day = day;
        block.roomB[iVal].checkInDate.month = month;
        block.roomB[iVal].checkInDate.year = year;
        block.roomB[iVal].gender = stud.sex;
    }
    stud.checkIn = 1;
}

int findBlock(std::vector<block>& vecBlock) {
    std::cout << "Введите номер блока(трехзначное число): ";
    int val;
    checkInt(val);
    for (auto i = 0U; i < vecBlock.size(); i++) {
        if (val == stoi(vecBlock[i].roomA->numRoom)) return i;
    }
    return -1;
}

void editBlock(block& Block, std::vector<Student>& vecStud) {
    int menu = 0;
    while (menu != 4) {
        system("cls");
        std::cout << "\tМеню редактирования блока №" << stoi(Block.roomA->numRoom) << std::endl;
        std::cout << "==========================================\n\n";
        std::cout << "1.Просмотреть жильцов блока.\n"
            "2.Выселить студента.\n"
            "3.Заселить студента.\n"
            "4.Вернуться в меню.\n";
        checkInt(menu);
        switch (menu) {
        case 1:
            system("cls");
            printf("+----------------------------------------------------------------------+\n");
            printf("|  № Комнаты                     ФИО                    Дата заселения|\n");
            printf("+----------------------------------------------------------------------+\n");
            printBlock(Block);
            printf("+----------------------------------------------------------------------+\n\n");
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            if (isFreeBlock(Block)) {
                std::cout << "Блок пуст.";
            }
            else {
                clearBlock(Block, vecStud);
            }
            system("pause");
            break;
        case 3:
            system("cls");
            if (isFullBlock(Block)) {
                std::cout << "Блок полон.";
            }
            else {
                handCheckIn(Block, vecStud);
            }
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

void clearBlock(block& Block, std::vector<Student>& vecStud) {
    int val{ 0 }, idStud{0};
    do {
        std::cout << "Введите число(1-4): ";
        do {
            checkInt(val);
        } while (!(val > 0 && val < 5));
        if (Block.roomA[0].checkInDate.year == "0000" && val == 1){
            std::cout << "Комната является пустой." << std::endl;
        continue;
        }
        if (Block.roomA[1].checkInDate.year == "0000" && val == 2){
            std::cout << "Комната является пустой." << std::endl;
        continue;
        }
        if (Block.roomB[0].checkInDate.year == "0000" && val == 3){
            std::cout << "Комната является пустой." << std::endl;
        continue;
        }
        if (Block.roomB[1].checkInDate.year == "0000" && val == 4) {
            std::cout << "Комната является пустой." << std::endl;
            continue;
        }
        break;
    } while (true);

    if (val == 1 || val == 2) {
        std::cout << "Вы выселите \"" << Block.roomA[val - 1].student.surname
            << ' ' << Block.roomA[val - 1].student.name << ' ' << Block.roomA[val - 1].student.patronymic << "\"\n";
    }
    else if (val == 3 || val == 4) {
        std::cout << "Вы выселите \"" << Block.roomB[val - 3].student.surname
            << ' ' << Block.roomB[val - 3].student.name << ' ' << Block.roomB[val - 3].student.patronymic << "\"\n";
    }
    std::cout << "Подтвердите действие(y/n): ";
    std::string _val;
    checkDel(_val);
    if (_val == "y" || _val == "Y") {
        idStud = findBlockStud(Block, vecStud, val);
        clearRoom(Block, val, vecStud, idStud);
        accessDelete();
    }
    else {
        std::cout << "Выселение отменено.\n";
    }
} 

void clearDorm(std::vector<block>& vecBlock, std::vector<Student>& vecStud) {
    for (auto i = 0U; i < vecBlock.size(); i++) {
        goOutStud(vecBlock);
    }
    for (auto i = 0U; i < vecStud.size(); i++) {
        vecStud[i].checkIn = 0;
    }
    std::cout << "Выселение завершено." << std::endl;
}

void goOutStud(std::vector<block>& vecBlock) {
    for (auto i = 0U; i < vecBlock.size(); i++) {
        for (auto j = 0U; j < 2; j++) {
            vecBlock[i].roomA[j].student.surname = "-";
            vecBlock[i].roomA[j].student.name = "-";
            vecBlock[i].roomA[j].student.patronymic = "-";
            vecBlock[i].roomA[j].checkInDate.day = "00";
            vecBlock[i].roomA[j].checkInDate.month = "00";
            vecBlock[i].roomA[j].checkInDate.year = "0000";

            vecBlock[i].roomB[j].student.surname = "-";
            vecBlock[i].roomB[j].student.name = "-";
            vecBlock[i].roomB[j].student.patronymic = "-";
            vecBlock[i].roomB[j].checkInDate.day = "00";
            vecBlock[i].roomB[j].checkInDate.month = "00";
            vecBlock[i].roomB[j].checkInDate.year = "0000";
        }
    }
}

void clearRoom(block& Block, const int val, std::vector<Student>& vecStud, int idStud) {
    if (val == 1 || val == 2) {
        Block.roomA[val - 1].student.surname = "-";
        Block.roomA[val - 1].student.name = "-";
        Block.roomA[val - 1].student.patronymic = "-";
        Block.roomA[val - 1].checkInDate.day = "00";
        Block.roomA[val - 1].checkInDate.month = "00";
        Block.roomA[val - 1].checkInDate.year = "0000";
    }
    if (val == 3 || val == 4) {
        Block.roomB[val - 3].student.surname = "-";
        Block.roomB[val - 3].student.name = "-";
        Block.roomB[val - 3].student.patronymic = "-";
        Block.roomB[val - 3].checkInDate.day = "00";
        Block.roomB[val - 3].checkInDate.month = "00";
        Block.roomB[val - 3].checkInDate.year = "0000";
    }
    vecStud[idStud].checkIn = 0;
}

int findBlockStud(block Block, std::vector<Student>& vecStud, int val) {
    if (val == 1 || val == 2) {
        for (auto i = 0U; i < vecStud.size(); i++) {
            if (vecStud[i].fio.surname == Block.roomA[val - 1].student.surname &&
                vecStud[i].fio.name == Block.roomA[val - 1].student.name &&
                vecStud[i].fio.patronymic == Block.roomA[val - 1].student.patronymic) return i;
        }
    }
    if (val == 3 || val == 4) {
        for (auto i = 0U; i < vecStud.size(); i++) {
            if (vecStud[i].fio.surname == Block.roomB[val - 3].student.surname &&
                vecStud[i].fio.name == Block.roomB[val - 3].student.name &&
                vecStud[i].fio.patronymic == Block.roomB[val - 3].student.patronymic) return i;
        }
    }
}

void handCheckIn(block& Block, std::vector<Student>& vecStud) {
    std::cout << "Введите ФИО студента: ";
    std::string name, _val;
    checkFind(name);
    Student *valStud;
    valStud = choiceStud(name, vecStud);
    if (valStud != nullptr) {
        if (genderBlock(Block, valStud->sex)) {
            bool error{false};
            do {
                error = false;
                std::cout << "Введите комнату, в которую хотите заселить студента(а/б): ";
                checkCheckIn(_val);
                if (_val == "а") {
                    if (Block.roomA[0].checkInDate.year == "0000") {
                        wassup(Block, *valStud, 'A', 0);
                    }
                    else if (Block.roomA[1].checkInDate.year == "0000") {
                        wassup(Block, *valStud, 'A', 1);
                    }
                    else {
                        std::cout << "Данная комната уже занята." << std::endl;
                        error = true;
                    }
                }else if (_val == "б") {
                    if (Block.roomB[0].checkInDate.year == "0000") {
                        wassup(Block, *valStud, 'B', 0);
                    }
                    else if (Block.roomB[1].checkInDate.year == "0000") {
                        wassup(Block, *valStud, 'B', 1);
                    }
                    else{
                        std::cout << "Данная комната уже занята." << std::endl;
                        error = true;
                    }
                }
            } while (error);
            access();
        }else {
            std::cout << "В данном блоке уже проживают студенты противоположного пола.";
        }
    }
}

Student* choiceStud(std::string name, std::vector<Student>& vecStud) {
    int k = 0; 
    auto i = 0U;
    std::cout << std::endl;
    for (; i < vecStud.size(); i++) {
        std::string _name = vecStud[i].fio.surname + ' ' + vecStud[i].fio.name + ' ' + vecStud[i].fio.patronymic;
        if (_name.find(name) != std::string::npos) {
            k++;
            break;
        }
    }
    if (k == 0) {
        std::cout << "Студентов по запрошенной фамилии не найдено!\n";
    }
    else {
        std::cout << "Вы собираетесь заселить \"" << vecStud[i].fio.surname << ' ' << vecStud[i].fio.name << ' ' << vecStud[i].fio.patronymic << "\"\n"
            << "Информация верна(y/n)? ";
        std::string val;
        checkDel(val);
        if (val == "y" || val == "Y") {
            if (vecStud[i].checkIn != 1) {
                FIO val = { vecStud[i].fio.surname, vecStud[i].fio.name, vecStud[i].fio.patronymic };
                return &vecStud[i];
            }
            else {
                std::cout << "Студент уже заселен." << std::endl;
                return nullptr;
            }
        }else {
            std::cout << "Заселение отменено." << std::endl;
            return nullptr;
        }
    }
}

bool genderBlock(block Block, std::string sex) {
    if ((Block.roomA[0].gender != sex && Block.roomA[0].gender != "None") ||
        (Block.roomA[1].gender != sex && Block.roomA[1].gender != "None") ||
        (Block.roomB[0].gender != sex && Block.roomB[0].gender != "None") ||
        (Block.roomB[1].gender != sex && Block.roomB[1].gender != "None")) {
        return false;
    }else {
        return true;
    }
}