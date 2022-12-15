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

bool check_ID(int& ID, std::vector<Student>& vecStud); //�������� �� ���� ������������� ������

void accessDelete(); //����� ��������� �� �������� ��������

void access(); //����� ��������� �� �������� ��������

void accessEdit(); //����� ��������� �� �������� ��������������

void accessAdd(); //����� ��������� �� �������� ����������

void accessReg(); //����� ��������� � ������������� �����������