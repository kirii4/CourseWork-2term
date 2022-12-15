#pragma once
#include "Libraries.h"
#include "check.h"
#include "accMenu.h"
#include "sort.h"
#include "file.h"

int welcome(); //Вход в программу

int sign_in(std::string& cashLogin); //Вход в аккаунт

void star(std::string& password); //Замена вводимого пароля на звездочки

void registration(std::vector<input>& vecAcc, std::vector<input>& vecReg); //Регистрация

void inputPassword(std::string& password); //Ввод пароля(проверка на ошибку, наличия пробела в пароле)

void regWork(std::vector<input>& vecAcc, std::vector<input>& vecReg); //Работа с аккаунтами на стадии подтверждения регистрации

void registrMenu(std::vector<input>& vecAcc, std::vector<input>& vecReg); //Меню регистрации

void printConsole(std::vector<input> vecReg); //Вывод аккаунтов

void finishReg(std::vector<input>& vecAcc, std::vector<input>& vecReg, const int pos);  //Подтверждение регистрации(админ)

void delAcc(std::vector<input>& vecAcc, std::string cashLogin); //удаление учетных записей (админ)