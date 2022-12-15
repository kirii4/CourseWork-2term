#pragma once

#include "Libraries.h"

void file_input(std::vector<Student>& vecStud); //Открытие файла для записи студентов в вектор

void file_input(std::vector<input>& vecAcc, std::string data); //Открытие файла для записи подтвержденных аккаунтов в вектор

void file_output(std::vector<Student>& vecStud); //Открытие файла для записи студентов в файл

void file_output(std::vector<input>& vecReg); //Открытие файла для записи аккаунтов для регистрации в файл

void file_AccOutput(std::vector<input>& vecAcc); //Открытие файла для записи подтвержденных аккаунтов в файл

void print_file(std::vector<Student>& vecStud, std::ofstream& fl); //Запись студентов в файл

void print_file(std::vector<input>& vecAcc, std::ofstream& fl); //Запись подтвержденных аккаунтов в файл

void print_file(input obj, std::ofstream& fl); // Запись аккаунтов для регистрации в файл

void fileblockInput(std::vector<block>& vecBlock); // Запись информации общежития из файла

void fileblockOutput(std::vector<block>& vecBlock); // Запись информации общежития в файл

void createAdmin(); //Создание файла с админом, если файла с аккаунтами нет