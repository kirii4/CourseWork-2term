#pragma once
#include "Libraries.h"
#include "list.h"
#include "check.h"
#include "sort.h"
#include "file.h"
#include "acc.h"
#include "dorm.h"

void userMenu(); //Меню пользователя

void adminMenu(std::string cashLogin); //Меню админа

void accMenu(std::vector<input>& vecReg, std::vector<input>& vecAcc, std::string cashLogin); //Меню для работы с аккаунтами 

void dataMenu(std::vector<Student>& vecStud, std::vector<block>& vecBlock); //Меню работы с данными

void studMenu(std::vector<Student>& vecStud); //Меню работы с данными студентов для админа

void studMenuUser(std::vector<Student>& vecStud); //Меню работы с данными студентов для пользователя

void find(std::vector<Student>& vecStud); //Меню поиска

void dormMenu(std::vector<block>& vecBlock, std::vector<Student>& vecStud); //Меню работы с данными общежития

void dormMenuUser(std::vector<block>& vecBlock); //Меню работы с данными для пользователя