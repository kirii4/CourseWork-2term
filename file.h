#pragma once

#include "Libraries.h"

void file_input(std::vector<Student>& vecStud); //�������� ����� ��� ������ ��������� � ������

void file_input(std::vector<input>& vecAcc, std::string data); //�������� ����� ��� ������ �������������� ��������� � ������

void file_output(std::vector<Student>& vecStud); //�������� ����� ��� ������ ��������� � ����

void file_output(std::vector<input>& vecReg); //�������� ����� ��� ������ ��������� ��� ����������� � ����

void file_AccOutput(std::vector<input>& vecAcc); //�������� ����� ��� ������ �������������� ��������� � ����

void print_file(std::vector<Student>& vecStud, std::ofstream& fl); //������ ��������� � ����

void print_file(std::vector<input>& vecAcc, std::ofstream& fl); //������ �������������� ��������� � ����

void print_file(input obj, std::ofstream& fl); // ������ ��������� ��� ����������� � ����

void fileblockInput(std::vector<block>& vecBlock); // ������ ���������� ��������� �� �����

void fileblockOutput(std::vector<block>& vecBlock); // ������ ���������� ��������� � ����

void createAdmin(); //�������� ����� � �������, ���� ����� � ���������� ���