#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

class GymManagment
{
	class GymClient
	{
	public:

		static int global_id;
		int ID;
		string name;
		int subscribe_months;

		GymClient(string name)
		{
			ID = global_id++;
			this->name = name;
			subscribe_months = 0;
		}

	};

	vector<GymClient> all_clients;

public:

	void create_client(string name)
	{
		all_clients.push_back(GymClient(name));
		cout << "\n�������� �������� ������.\n";
	}
	
	void delete_client(int ID)
	{
		for (vector<GymClient>::iterator i = all_clients.begin(); i < all_clients.end(); i++)
		{
			if ((*i).ID == ID)
			{
				all_clients.erase(i);
				cout << "\n�������� �������� ������.\n";
				return;
			}
		}

		cout << "\n��������� �������� �볺���. ������������� �� ���� (ID:" << ID << ")\n";
	}
	
	void continue_subscription(int ID, int months_number)
	{
		if (months_number < 0)
		{
			cout << "\n��������� ���������� ������� �볺���. ���������� ������� ������ (N:" << months_number << ")\n";
			return;
		}

		for (vector<GymClient>::iterator i = all_clients.begin(); i < all_clients.end(); i++)
		{
			if ((*i).ID == ID)
			{
				(*i).subscribe_months += months_number;
				cout << "\n�������� �������� ������.\n";
				return;
			}
		}

		cout << "\n��������� ���������� ������� �볺���. ������������� �� ���� (ID:" << ID << ")\n";
	}
	
	void unsubscribe_client(int ID)
	{
		for (vector<GymClient>::iterator i = all_clients.begin(); i < all_clients.end(); i++)
		{
			if ((*i).ID == ID)
			{
				(*i).subscribe_months = 0;
				cout << "\n�������� �������� ������.\n";
				return;
			}
		}

		cout << "\n��������� ��������� ������� �볺���. ������������� �� ���� (ID:" << ID << ")\n";
	}
	
	void unsubscribe_client(int ID, int months_number)
	{
		if (months_number < 0)
		{
			cout << "\n��������� ��������� ������� �볺���. ���������� ������� ������ (N:" << months_number << ")\n";
			return;
		}

		for (vector<GymClient>::iterator i = all_clients.begin(); i < all_clients.end(); i++)
		{
			if ((*i).ID == ID)
			{
				if (months_number > (*i).subscribe_months)
				{
					cout << "\n��������� ��������� ������� �볺���. ���������� ������� ������\n"
						"(N:" << months_number << ", ϳ������ �����������:" << (*i).subscribe_months << ")\n";
					return;
				}
				(*i).subscribe_months -= months_number;

				if ((*i).subscribe_months < 0)
					(*i).subscribe_months = 0;

				cout << "\n�������� �������� ������.\n";
				return;
			}
		}

		cout << "\n��������� ��������� ������� �볺��� �� ��������� ������� ������. ������������� �� ���� (ID:" << ID << ")\n";
	}

	void console_info_output()
	{
		if (all_clients.size() == 0)
		{
			cout << "����� ���� ������� �������������� �볺���.\n\n";
			return;
		}

		for (auto& i : all_clients)
			cout << "ID: " << i.ID << " | ��'�: " << i.name << " | ̳����� �������: " << i.subscribe_months << "\n\n";
	}
};

int GymManagment::GymClient::global_id = 0;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	GymManagment proccess;
	bool exit = false;
	while (exit == false)
	{
		int choice = -1, input_id = 0, input_months = 0;
		string input_name = "";
		while (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
		{
			system("cls");
			proccess.console_info_output();
			cout << "������:"
				"\n<0> - ��� ������ ������ �볺���"
				"\n<1> - ��� �������� �볺��� �� ���������������"
				"\n<2> - ��� ���������� ������� �볺��� �� ���������������\n"
				"<3> - ��� ��������� ������� �볺��� �� ���������������\n"
				"<4> - ��� ��������� ������� �볺��� �� ��������� ������� ������ �� ���������������\n"
				"<5> - ��� �����"
				"\n-> ";
			cin >> choice;
		}
		switch (choice)
		{
		case 0:
			system("cls");
			cout << "������ ��'� -> ";
			cin >> input_name;
			proccess.create_client(input_name);
			system("pause");
			break;
		case 1:
			system("cls");
			cout << "������ ������������� -> ";
			cin >> input_id;
			proccess.delete_client(input_id);
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "������ ������������� -> ";
			cin >> input_id;
			cout << "������ ������� ������ -> ";
			cin >> input_months;
			proccess.continue_subscription(input_id, input_months);
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "������ ������������� -> ";
			cin >> input_id;
			proccess.unsubscribe_client(input_id);
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "������ ������������� -> ";
			cin >> input_id;
			cout << "������ ������� ������ -> ";
			cin >> input_months;
			proccess.unsubscribe_client(input_id, input_months);
			system("pause");
			break;
		case 5:
			system("cls");
			cout << "�������� ���������.";
			exit = true;
		}
	}
}