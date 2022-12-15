#pragma once
#include "Libraries.h"
#include "list.h"
#include "check.h"

void sort_menu(std::vector<Student>& vecStud); //Меню сортировки

bool is_ID_sort(Student vecStud1, Student vecStud2); //Компаратор для сортировки по номеру студенческого билета

void ID_sort(std::vector<Student>& vecStud); //Сортировка по номеру студенческого

bool is_alph_sort(Student vecStud1, Student vecStud2);

void alph_sort(std::vector<Student>& vecStud); //Сортировка по алфавиту

bool is_group_sort(Student vecStud1, Student vecStud2);

void group_sort(std::vector<Student>& vecStud); //Сортировка по номеру группы

bool is_marks_sort(Student vecStud1, Student vecStud2);

void marks_sort(std::vector<Student>& vecStud); //Сортировка по среднему баллу

bool is_work_sort(Student vecStud1, Student vecStud2);

void work_sort(std::vector<Student>& vecStud); //Сортировка по выполнению общественной деятельности

bool is_salary_sort(Student vecStud1, Student vecStud2);

void salary_sort(std::vector<Student>& vecStud); //Сортировка по уровню дохода семьи

bool is_checkIn_sort(Student vecStud1, Student vecStud2);

bool is_checkInWithData_sort(Student vecStud1, Student vecStud2);

void checkInWithData_sort(std::vector<Student>& vecStud); //Сортировка для заселения с введенной минимальной заработной платой

bool is_secondCheckIn_sort(Student vecStud1, Student vecStud2);

void secondCheckIn_sort(std::vector<Student>& vecStud); //Сортировка по полю заселен / не заселен