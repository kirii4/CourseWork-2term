#pragma once
#include "Libraries.h"
#include "list.h"
#include "check.h"

void sort_menu(std::vector<Student>& vecStud); //���� ����������

bool is_ID_sort(Student vecStud1, Student vecStud2); //���������� ��� ���������� �� ������ ������������� ������

void ID_sort(std::vector<Student>& vecStud); //���������� �� ������ �������������

bool is_alph_sort(Student vecStud1, Student vecStud2);

void alph_sort(std::vector<Student>& vecStud); //���������� �� ��������

bool is_group_sort(Student vecStud1, Student vecStud2);

void group_sort(std::vector<Student>& vecStud); //���������� �� ������ ������

bool is_marks_sort(Student vecStud1, Student vecStud2);

void marks_sort(std::vector<Student>& vecStud); //���������� �� �������� �����

bool is_work_sort(Student vecStud1, Student vecStud2);

void work_sort(std::vector<Student>& vecStud); //���������� �� ���������� ������������ ������������

bool is_salary_sort(Student vecStud1, Student vecStud2);

void salary_sort(std::vector<Student>& vecStud); //���������� �� ������ ������ �����

bool is_checkIn_sort(Student vecStud1, Student vecStud2);

bool is_checkInWithData_sort(Student vecStud1, Student vecStud2);

void checkInWithData_sort(std::vector<Student>& vecStud); //���������� ��� ��������� � ��������� ����������� ���������� ������

bool is_secondCheckIn_sort(Student vecStud1, Student vecStud2);

void secondCheckIn_sort(std::vector<Student>& vecStud); //���������� �� ���� ������� / �� �������