#pragma once
#include "Libraries.h"
#include "check.h"
#include "accMenu.h"
#include "sort.h"

void add(std::vector<Student>& vecStud); //Добавление студента

void del(std::vector<Student>& vecStud); //Удаление студента

void editing_a_list(std::vector<Student>& vecStud); //Корректировка списка

void find_stud(std::vector<Student>& vecStud); //Поиск студента по ФИО

void findGroup(std::vector<Student>& vecStud); //Поиск студента по номеру группы

void print_console(std::vector<Student>& s); //Вывод студентов на экран

void printSoloStud(Student stud, int& k); //Печать одного студента(используется при поиске студента)