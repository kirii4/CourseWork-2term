#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <locale>
#include <algorithm>
#include <time.h>

#define MAX_VECTOR_SIZE 150 //Максимальная размерность вектора
#define MAX_BLOCKS 40   //Максимальное количество блоков в общежитии
#define BLOCKS_ON_FLOOR 10 //Максимальное количество блоков на этаже в общежитии

#define fileStud "student.txt"
#define fileReg "registration.txt"
#define fileAcc "account.txt"
#define fileBlock "dorm.txt"

struct input {
    std::string login;
    std::string password;
    int role;
};

struct FIO {
    std::string surname; // Фамилия
    std::string name; // Имя
    std::string patronymic; //Отчество
};

#pragma pack(push,1)
struct Student {
    int ID; //Номер студенческого
    std::string sex; //Пол студента
    FIO fio;   //ФИО
    int is_worked; //Общественная деятельность (0/1)
    int num_group; //Номер группы (6 цифр)
    double avr_marks; //Средний балл
    double sal_par; //Доход на одного члена семьи
    int checkIn; //Заселен(1)/не заселен(0) 
};
#pragma pack(pop)

struct Data {
    std::string day;    //День
    std::string month;  //Месяц
    std::string year;   //Год
};

struct room {
    std::string numRoom; //номер комнаты
    FIO student;
    Data checkInDate; //Дата заселения
    std::string gender; //Пол человека проживающего в комнате
};

struct block {
    room roomA[2]; //2 проживающих студента в комнате А
    room roomB[2]; //2 проживающих студента в комнате В
};
