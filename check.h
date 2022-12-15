#pragma once
#include "Libraries.h"

void checkInt(int& n);

void checkID(int& n);

void checkGroup(int& n);

void checkWork(int& n);

void checkFloor(int& n);

void checkDouble(double& n);

void checkMarks(double& n);

void checkString(std::string& str);

void checkSex(std::string& str);

void checkFind(std::string& str);

void checkDel(std::string& str);

void checkCheckIn(std::string& str);

bool check_ID(int& ID, std::vector<Student>& vecStud); //Проверка на ввод студенческого билета

void accessDelete(); //Вывод сообщения об успешном удалении

void access(); //Вывод сообщения об успешном действии

void accessEdit(); //Вывод сообщения об успешном редактировании

void accessAdd(); //Вывод сообщения об успешном добавлении

void accessReg(); //Вывод сообщения о подтверждении регистрации