#pragma once
#include "Libraries.h"
#include "check.h"
#include "accMenu.h"
#include "sort.h"

void add(std::vector<Student>& vecStud); //���������� ��������

void del(std::vector<Student>& vecStud); //�������� ��������

void editing_a_list(std::vector<Student>& vecStud); //������������� ������

void find_stud(std::vector<Student>& vecStud); //����� �������� �� ���

void findGroup(std::vector<Student>& vecStud); //����� �������� �� ������ ������

void print_console(std::vector<Student>& s); //����� ��������� �� �����

void printSoloStud(Student stud, int& k); //������ ������ ��������(������������ ��� ������ ��������)