#include "acc.h"

int welcome() {
    std::cout << "Добро пожаловать!\n\n";
    std::cout << "1.Войти в аккаунт.\n"
        << "2.Создать аккаунт.\n"
		<< "3.Выход.\n";
    int menu{0};
    checkInt(menu);
    std::vector<input> vecReg;
    std::vector<input> vecAcc;
    switch (menu) {
    case 1:
		return 1;
        break;
    case 2:
        file_input(vecReg, fileReg);
        file_input(vecAcc, fileAcc);
        registration(vecAcc,vecReg);
        std::cout << "Ожидайте подтверждение регистрации админом!\n";
		return 0;
		break;
	case 3:
		std::cout << "Выход из системы.\n";
		break;
    default:
        std::cout << "Ошибка ввода!\n";
        break;
    }
}

int sign_in(std::string& cashLogin) {  //Вход в аккаунт
    std::ifstream acc(fileAcc);
	if (!acc.is_open()) {
		createAdmin();
	}
	acc.close();
	acc.open(fileAcc);
	int try_ = 0; // Количество попыток(максимум 3)
	bool input = false;
	std::string login, password;
	std::string _login, _password;
	int _role; //1 - админ, 0 - пользователь
	system("cls");
	while (true) {
		std::cout << "\tАвторизация" << std::endl;
		std::cout << "==============================" << std::endl << std::endl;
		std::cout << "Введите логин:" << std::endl;
		if (try_ == 0) getchar();
		getline(std::cin, login);
		std::cout << "Введите пароль:" << std::endl;
		star(password);
		std::hash<std::string> salt;
		password = std::to_string(salt(password));

		while (acc >> _login && acc >> _password && acc >> _role) {
			if (_login == login && _password == password) { //Пароль с логином нашли - выходим из цикла проверки по файлу
				input = true;
				break;
			}
		}

		if (input) { //Если логин и пароль подошли переходим в меню
			if (_role == 1) {
				cashLogin = login;
				return 1;
			}
			else {
				return 0;
			}
		}else {
			acc.clear(); //возврат указателя на начало файла
			acc.seekg(0);
			try_++;
			system("cls");
			std::cout << "Пароль или логин неправильный!!!\n\n";
			if (try_ == 1) std::cout << "У вас осталось " << 3 - try_ << " попытки!!!\n\n"; // осталось 2 попытки
			else std::cout << "У вас осталась " << 3 - try_ << " попытка!!!\n\n"; // осталась 1 попытка
			if (try_ == 3) {           //Проверка пароля
				std::cout << "\nОшибка входа!!!\n";
				exit(0);
			}
		}
	}
}

void star(std::string& password) {
	password = "";
	int ch = 0;
	while (true) {              // Замена пароля при вводе на звездочки (*)
		ch = _getch();        // Помещаем код нажатой клавиши в переменную.
		if (ch == 13) {         // Установка Enter на прерывание цикла.
			break;         // Прерывание цикла.
		}
		if (ch == 27) {   // Esc - конец программы
			exit(0);
		}
		if (ch == 8) {    //Backspace
			std::cout << (char)8 << ' ' << char(8); //Смещение курсора на одну позицию влево, вывод пробела и
													// снова смещение курсора влево (при нажатии Backspace
													// символ будет стираться, а курсор перемещается).
			if (!password.empty()) //Если строка pass не является пустой, то из неё
									//можно удалять последний символ (Иначе закрывалась консоль.
				password.erase(password.length() - 1); // позволяет удалить последний символ из строки pass
		}
		else {
			std::cout << '*';            // Замена символов на *
			password += (char)ch;       // Код из целого числа -> символ.
		}
	}
}

void registrMenu(std::vector<input>& vecAcc, std::vector<input>& vecReg) {
	int menu = 0;
	while (menu != 2) {
		system("cls");
		std::cout << "\tМеню работы с регистрацией\n"
			<< "==========================================\n\n";
		std::cout << "1.Обработать запросы на регистрацию.\n"
			<< "2.Вернуться в главное меню.\n";
		checkInt(menu);
		if (vecReg.empty() && menu == 1) {
			system("cls");
			std::cout << "Запросов для регистраций нет.\n\n";
			break;
		}else
		if (menu == 1) {
			switch (menu) {
			case 1:
				regWork(vecAcc, vecReg);
				system("pause");
				break;
			case 2:
				system("cls");
				break;
			default:
				std::cout << "Ошибка ввода!!\n";
				break;
			}
		}
		file_output(vecReg);
	}
}

void regWork(std::vector<input>& vecAcc, std::vector<input>& vecReg) {
	int reg;
	std::string val;
	printConsole(vecReg);
	std::cout << "Выберите номер поля для обработки: ";
	int pos;
	checkInt(pos);
	std::cout << "1. Подтвердить регистрацию.\n"
		<< "2. Отклонить регистрацию.\n";
	checkInt(reg);
	switch (reg) {
	case 1:
		system("cls");
		finishReg(vecAcc, vecReg, pos);
		break;
	case 2:
		system("cls");
		std::cout << "Возможна потеря данных!\n"
			<< "Подтвердите действие(y/n)";
		getchar();
		checkDel(val);
		if (val == "n" || val == "N") {
			std::cout << "\nУдаление отменено!\n\n";
			break;
		}
		else {
			vecReg.erase(vecReg.begin() + pos - 1);
			accessDelete();
			break;
		}
	default:
		std::cout << "Ошибка ввода!!\n";
		break;
	}
}

void registration(std::vector<input>& vecAcc, std::vector<input>& vecReg) {
	input obj;
	std::string _password2;
	int try_ = 0;
	bool bLogin = false, bPassword = false;

	while (try_ != 3) {
		std::cout << "Введите логин: ";
		getchar();
		getline(std::cin, obj.login);
		for (auto i = 0U; i < vecAcc.size(); i++) {
			if (vecAcc[i].login == obj.login) {
				system("cls");
				bLogin = true;
				break;
			}
		}
		if (bLogin) {
			std::cout << "Данный логин уже занят.\n";
			try_++;
			bLogin = false;
		}
		else {
			break;
		}
		if (try_ == 3) {
			std::cout << "Неудачная попытка регистрации\n";
		}
	}

	if (try_ != 3) {
		try_ = 0;
		while (try_ != 3) {
			std::cout << "Введите пароль: ";
			inputPassword(obj.password);
			std::cout << std::endl << "Повторите пароль: ";
			inputPassword(_password2);

			if (obj.password != _password2) {
				std::cout << std::endl << "Пароли не совпадают!\n";
				try_++;
				continue;
			}

			std::hash<std::string> salt;
			obj.password = std::to_string(salt(obj.password));

			for (auto i = 0U; i < vecAcc.size(); i++) {
				if (vecAcc[i].password == obj.password) {
					try_++;
					bPassword = true;
					break;
				}
			}
			if (bPassword) {
				std::cout << std::endl << "Данный пароль не уникален.\n";
				try_++;
				bPassword = false;
			}
			else {
				break;
			}

		}
		if (try_ == 3) {
			std::cout << std::endl << "Неудачная попытка регистрации.\n";
		}
		else {
			system("cls");
			std::cout << "Введите роль данного аккаунта(0 - пользователь, 1 - админ):\n";
			checkWork(obj.role);

			std::string file = "registration.txt";
			std::ofstream fReg(file, std::ios_base::out | std::ios_base::app);
			print_file(obj, fReg);
			std::cout << "Регистрация завершена.\n";
			vecReg.push_back(obj);
			fReg.close();
		}
	}
}

void inputPassword(std::string& password) {
	bool error{false};
	do {
		error = false;
		star(password);
		for (auto i = 0U; i < password.size(); i++) {
			if (password[i] == ' ') {
				std::cout << std::endl << "Ошибка ввода(возможно введен пробел)." << std::endl;
				break;
				error = true;
			}
		}
	} while (error);
}

void delAcc(std::vector<input>& vecAcc, std::string cashLogin) {
	if (vecAcc.size() == 0) std::cout << std::endl << "Список пуст." << std::endl << std::endl;
	else {
		std::cout << "Введите индекс удаляемого поля.\n";
		int num;
		while (true) {
			checkInt(num);
			num--;
			if (num >= vecAcc.size() || num < 0) std::cout << "\nНеверный ввод номера!\n";
			else if (vecAcc[num].login == cashLogin) {
				std::cout << "\tОшибка\nВы не можете удалить собственный аккаунт.";
				break;
			}else{
				std::string val;
				std::cout << "\nВы согласны удалить поле(y/n): \n";
				getchar();
				checkDel(val);
				if (val == "n" || val == "N") {
					std::cout << "\nУдаление отменено!\n\n";
					break;
				}
				else {
					vecAcc.erase(vecAcc.begin() + num);
					system("cls");
					accessDelete();
					break;
				}
			}
		}
	}
}

void finishReg(std::vector<input>& vecAcc, std::vector<input>& vecReg, const int pos) {
	std::ofstream fout(fileAcc, std::ios_base::app); //acc_base
	vecAcc.push_back(vecReg[pos - 1]);
	//fout << vecReg[pos - 1].login << ' ' << vecReg[pos - 1].password << ' ' << vecReg[pos - 1].role << std::endl;
	vecReg.erase(vecReg.begin() + pos - 1);
	accessReg();
	system("cls");
}

void printConsole(std::vector<input> vecAcc) { //Вывод в консоль
	std::cout << "=========================================\n";
	std::cout << "|              Логин          Роль      |\n";
	for (auto i = 0U; i < vecAcc.size(); i++) {
		printf("|%2d. %15s %14s     |\n", i + 1, vecAcc[i].login.c_str(), (vecAcc[i].role == 1) ? "Админ" : "Польз.");
	}
	std::cout << "=========================================\n\n";
}