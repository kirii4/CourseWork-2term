#include "acc.h"

int welcome() {
    std::cout << "����� ����������!\n\n";
    std::cout << "1.����� � �������.\n"
        << "2.������� �������.\n"
		<< "3.�����.\n";
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
        std::cout << "�������� ������������� ����������� �������!\n";
		return 0;
		break;
	case 3:
		std::cout << "����� �� �������.\n";
		break;
    default:
        std::cout << "������ �����!\n";
        break;
    }
}

int sign_in(std::string& cashLogin) {  //���� � �������
    std::ifstream acc(fileAcc);
	if (!acc.is_open()) {
		createAdmin();
	}
	acc.close();
	acc.open(fileAcc);
	int try_ = 0; // ���������� �������(�������� 3)
	bool input = false;
	std::string login, password;
	std::string _login, _password;
	int _role; //1 - �����, 0 - ������������
	system("cls");
	while (true) {
		std::cout << "\t�����������" << std::endl;
		std::cout << "==============================" << std::endl << std::endl;
		std::cout << "������� �����:" << std::endl;
		if (try_ == 0) getchar();
		getline(std::cin, login);
		std::cout << "������� ������:" << std::endl;
		star(password);
		std::hash<std::string> salt;
		password = std::to_string(salt(password));

		while (acc >> _login && acc >> _password && acc >> _role) {
			if (_login == login && _password == password) { //������ � ������� ����� - ������� �� ����� �������� �� �����
				input = true;
				break;
			}
		}

		if (input) { //���� ����� � ������ ������� ��������� � ����
			if (_role == 1) {
				cashLogin = login;
				return 1;
			}
			else {
				return 0;
			}
		}else {
			acc.clear(); //������� ��������� �� ������ �����
			acc.seekg(0);
			try_++;
			system("cls");
			std::cout << "������ ��� ����� ������������!!!\n\n";
			if (try_ == 1) std::cout << "� ��� �������� " << 3 - try_ << " �������!!!\n\n"; // �������� 2 �������
			else std::cout << "� ��� �������� " << 3 - try_ << " �������!!!\n\n"; // �������� 1 �������
			if (try_ == 3) {           //�������� ������
				std::cout << "\n������ �����!!!\n";
				exit(0);
			}
		}
	}
}

void star(std::string& password) {
	password = "";
	int ch = 0;
	while (true) {              // ������ ������ ��� ����� �� ��������� (*)
		ch = _getch();        // �������� ��� ������� ������� � ����������.
		if (ch == 13) {         // ��������� Enter �� ���������� �����.
			break;         // ���������� �����.
		}
		if (ch == 27) {   // Esc - ����� ���������
			exit(0);
		}
		if (ch == 8) {    //Backspace
			std::cout << (char)8 << ' ' << char(8); //�������� ������� �� ���� ������� �����, ����� ������� �
													// ����� �������� ������� ����� (��� ������� Backspace
													// ������ ����� ���������, � ������ ������������).
			if (!password.empty()) //���� ������ pass �� �������� ������, �� �� ��
									//����� ������� ��������� ������ (����� ����������� �������.
				password.erase(password.length() - 1); // ��������� ������� ��������� ������ �� ������ pass
		}
		else {
			std::cout << '*';            // ������ �������� �� *
			password += (char)ch;       // ��� �� ������ ����� -> ������.
		}
	}
}

void registrMenu(std::vector<input>& vecAcc, std::vector<input>& vecReg) {
	int menu = 0;
	while (menu != 2) {
		system("cls");
		std::cout << "\t���� ������ � ������������\n"
			<< "==========================================\n\n";
		std::cout << "1.���������� ������� �� �����������.\n"
			<< "2.��������� � ������� ����.\n";
		checkInt(menu);
		if (vecReg.empty() && menu == 1) {
			system("cls");
			std::cout << "�������� ��� ����������� ���.\n\n";
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
				std::cout << "������ �����!!\n";
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
	std::cout << "�������� ����� ���� ��� ���������: ";
	int pos;
	checkInt(pos);
	std::cout << "1. ����������� �����������.\n"
		<< "2. ��������� �����������.\n";
	checkInt(reg);
	switch (reg) {
	case 1:
		system("cls");
		finishReg(vecAcc, vecReg, pos);
		break;
	case 2:
		system("cls");
		std::cout << "�������� ������ ������!\n"
			<< "����������� ��������(y/n)";
		getchar();
		checkDel(val);
		if (val == "n" || val == "N") {
			std::cout << "\n�������� ��������!\n\n";
			break;
		}
		else {
			vecReg.erase(vecReg.begin() + pos - 1);
			accessDelete();
			break;
		}
	default:
		std::cout << "������ �����!!\n";
		break;
	}
}

void registration(std::vector<input>& vecAcc, std::vector<input>& vecReg) {
	input obj;
	std::string _password2;
	int try_ = 0;
	bool bLogin = false, bPassword = false;

	while (try_ != 3) {
		std::cout << "������� �����: ";
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
			std::cout << "������ ����� ��� �����.\n";
			try_++;
			bLogin = false;
		}
		else {
			break;
		}
		if (try_ == 3) {
			std::cout << "��������� ������� �����������\n";
		}
	}

	if (try_ != 3) {
		try_ = 0;
		while (try_ != 3) {
			std::cout << "������� ������: ";
			inputPassword(obj.password);
			std::cout << std::endl << "��������� ������: ";
			inputPassword(_password2);

			if (obj.password != _password2) {
				std::cout << std::endl << "������ �� ���������!\n";
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
				std::cout << std::endl << "������ ������ �� ��������.\n";
				try_++;
				bPassword = false;
			}
			else {
				break;
			}

		}
		if (try_ == 3) {
			std::cout << std::endl << "��������� ������� �����������.\n";
		}
		else {
			system("cls");
			std::cout << "������� ���� ������� ��������(0 - ������������, 1 - �����):\n";
			checkWork(obj.role);

			std::string file = "registration.txt";
			std::ofstream fReg(file, std::ios_base::out | std::ios_base::app);
			print_file(obj, fReg);
			std::cout << "����������� ���������.\n";
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
				std::cout << std::endl << "������ �����(�������� ������ ������)." << std::endl;
				break;
				error = true;
			}
		}
	} while (error);
}

void delAcc(std::vector<input>& vecAcc, std::string cashLogin) {
	if (vecAcc.size() == 0) std::cout << std::endl << "������ ����." << std::endl << std::endl;
	else {
		std::cout << "������� ������ ���������� ����.\n";
		int num;
		while (true) {
			checkInt(num);
			num--;
			if (num >= vecAcc.size() || num < 0) std::cout << "\n�������� ���� ������!\n";
			else if (vecAcc[num].login == cashLogin) {
				std::cout << "\t������\n�� �� ������ ������� ����������� �������.";
				break;
			}else{
				std::string val;
				std::cout << "\n�� �������� ������� ����(y/n): \n";
				getchar();
				checkDel(val);
				if (val == "n" || val == "N") {
					std::cout << "\n�������� ��������!\n\n";
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

void printConsole(std::vector<input> vecAcc) { //����� � �������
	std::cout << "=========================================\n";
	std::cout << "|              �����          ����      |\n";
	for (auto i = 0U; i < vecAcc.size(); i++) {
		printf("|%2d. %15s %14s     |\n", i + 1, vecAcc[i].login.c_str(), (vecAcc[i].role == 1) ? "�����" : "�����.");
	}
	std::cout << "=========================================\n\n";
}