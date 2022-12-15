#pragma once
#include "Libraries.h"
#include "check.h"
#include "sort.h"

void printFloor(std::vector<block>& vecBlock); //Вывод студентов жильцов, на введенном этаже

void printBlock(block block); //Вывод жильцов блока

int randBlock(std::vector<block> vecBlock, std::string sex); //Выбор блока для заселения(1-я стадия)

void checkIn(std::vector<block>& vecBlock, std::vector<Student>& vecStud); //Проверка на возможность заселения(начало 1-й стадии)

void secondCheckIn(std::vector<block>& vecBlock, std::vector<Student>& vecStud); //2-я стадия заселения

void wassup(block& block, Student& stud, char val, int iVal); //Запись студента в комнату 

int findBlock(std::vector<block>& vecBlock); //Поиск информации о блоке по введенному номеру

void editBlock(block& Block, std::vector<Student>& vecStud); //Редактирование блока

void clearBlock(block& Block, std::vector<Student>& vecStud); //Очистка блока

void mainCheckIn(block& Block, Student& Stud); //Заселение студентов в блок

void clearRoom(block& Block, const int value, std::vector<Student>& vecStud, int idStud); //Очистка комнаты

int findBlockStud(block Block, std::vector<Student>& vecStud, int val); //Поиск блока, в котором проживает определенный студент

void handCheckIn(block& Block, std::vector<Student>& vecStud); //Ручное заселение студента

Student* choiceStud(std::string name, std::vector<Student>& vecStud);

bool genderBlock(block Block, std::string sex); //Проверка на соответствие гендера проживающих в блоке и заселяющего(заселяющейся)

bool isFreeBlock(block Block); //Проверка на пустоту блока

bool isFreeRoom(block Block); //Проверка на пустоты комнаты

bool isFullBlock(block Block); //Проверка на заполненность блока

void clearDorm(std::vector<block>& vecBlock, std::vector<Student>& vecStud); //Выселение всех из общежития

void goOutStud(std::vector<block>& vecBlock); //Очистка всех блоков

void printNotCheckInStud(std::vector<Student> vecStud); //Печать незаселенных студентов