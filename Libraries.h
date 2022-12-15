#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <locale>
#include <algorithm>
#include <time.h>

#define MAX_VECTOR_SIZE 150 //������������ ����������� �������
#define MAX_BLOCKS 40   //������������ ���������� ������ � ���������
#define BLOCKS_ON_FLOOR 10 //������������ ���������� ������ �� ����� � ���������

#define fileStud "student.txt"
#define fileReg "registration.txt"
#define fileAcc "account.txt"
#define fileBlock "dorm.txt"

struct input {
    std::string login;
    std::string password;
    int role;
};

struct FIO {
    std::string surname; // �������
    std::string name; // ���
    std::string patronymic; //��������
};

#pragma pack(push,1)
struct Student {
    int ID; //����� �������������
    std::string sex; //��� ��������
    FIO fio;   //���
    int is_worked; //������������ ������������ (0/1)
    int num_group; //����� ������ (6 ����)
    double avr_marks; //������� ����
    double sal_par; //����� �� ������ ����� �����
    int checkIn; //�������(1)/�� �������(0) 
};
#pragma pack(pop)

struct Data {
    std::string day;    //����
    std::string month;  //�����
    std::string year;   //���
};

struct room {
    std::string numRoom; //����� �������
    FIO student;
    Data checkInDate; //���� ���������
    std::string gender; //��� �������� ������������ � �������
};

struct block {
    room roomA[2]; //2 ����������� �������� � ������� �
    room roomB[2]; //2 ����������� �������� � ������� �
};
