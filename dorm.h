#pragma once
#include "Libraries.h"
#include "check.h"
#include "sort.h"

void printFloor(std::vector<block>& vecBlock); //����� ��������� �������, �� ��������� �����

void printBlock(block block); //����� ������� �����

int randBlock(std::vector<block> vecBlock, std::string sex); //����� ����� ��� ���������(1-� ������)

void checkIn(std::vector<block>& vecBlock, std::vector<Student>& vecStud); //�������� �� ����������� ���������(������ 1-� ������)

void secondCheckIn(std::vector<block>& vecBlock, std::vector<Student>& vecStud); //2-� ������ ���������

void wassup(block& block, Student& stud, char val, int iVal); //������ �������� � ������� 

int findBlock(std::vector<block>& vecBlock); //����� ���������� � ����� �� ���������� ������

void editBlock(block& Block, std::vector<Student>& vecStud); //�������������� �����

void clearBlock(block& Block, std::vector<Student>& vecStud); //������� �����

void mainCheckIn(block& Block, Student& Stud); //��������� ��������� � ����

void clearRoom(block& Block, const int value, std::vector<Student>& vecStud, int idStud); //������� �������

int findBlockStud(block Block, std::vector<Student>& vecStud, int val); //����� �����, � ������� ��������� ������������ �������

void handCheckIn(block& Block, std::vector<Student>& vecStud); //������ ��������� ��������

Student* choiceStud(std::string name, std::vector<Student>& vecStud);

bool genderBlock(block Block, std::string sex); //�������� �� ������������ ������� ����������� � ����� � �����������(������������)

bool isFreeBlock(block Block); //�������� �� ������� �����

bool isFreeRoom(block Block); //�������� �� ������� �������

bool isFullBlock(block Block); //�������� �� ������������� �����

void clearDorm(std::vector<block>& vecBlock, std::vector<Student>& vecStud); //��������� ���� �� ���������

void goOutStud(std::vector<block>& vecBlock); //������� ���� ������

void printNotCheckInStud(std::vector<Student> vecStud); //������ ������������ ���������