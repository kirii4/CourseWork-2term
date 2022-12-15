#pragma once
#include "Libraries.h"
#include "check.h"
#include "accMenu.h"
#include "sort.h"
#include "file.h"

int welcome(); //���� � ���������

int sign_in(std::string& cashLogin); //���� � �������

void star(std::string& password); //������ ��������� ������ �� ���������

void registration(std::vector<input>& vecAcc, std::vector<input>& vecReg); //�����������

void inputPassword(std::string& password); //���� ������(�������� �� ������, ������� ������� � ������)

void regWork(std::vector<input>& vecAcc, std::vector<input>& vecReg); //������ � ���������� �� ������ ������������� �����������

void registrMenu(std::vector<input>& vecAcc, std::vector<input>& vecReg); //���� �����������

void printConsole(std::vector<input> vecReg); //����� ���������

void finishReg(std::vector<input>& vecAcc, std::vector<input>& vecReg, const int pos);  //������������� �����������(�����)

void delAcc(std::vector<input>& vecAcc, std::string cashLogin); //�������� ������� ������� (�����)