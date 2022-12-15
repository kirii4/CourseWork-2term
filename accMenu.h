#pragma once
#include "Libraries.h"
#include "list.h"
#include "check.h"
#include "sort.h"
#include "file.h"
#include "acc.h"
#include "dorm.h"

void userMenu(); //���� ������������

void adminMenu(std::string cashLogin); //���� ������

void accMenu(std::vector<input>& vecReg, std::vector<input>& vecAcc, std::string cashLogin); //���� ��� ������ � ���������� 

void dataMenu(std::vector<Student>& vecStud, std::vector<block>& vecBlock); //���� ������ � �������

void studMenu(std::vector<Student>& vecStud); //���� ������ � ������� ��������� ��� ������

void studMenuUser(std::vector<Student>& vecStud); //���� ������ � ������� ��������� ��� ������������

void find(std::vector<Student>& vecStud); //���� ������

void dormMenu(std::vector<block>& vecBlock, std::vector<Student>& vecStud); //���� ������ � ������� ���������

void dormMenuUser(std::vector<block>& vecBlock); //���� ������ � ������� ��� ������������