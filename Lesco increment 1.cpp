#include<conio.h>
#include<fstream>
#include<string>
#include<ctime>
#include<Windows.h>
#include<cstdlib>
#include<vector>
using namespace std;
class employee{
private:
	string username;
	string password;
	char** passwaords;
	char** usernames;
	vector <string> credentials;
	int index;
public:
	employee(string u, string p)
	{
		username = u;
		password = p;
		index = 0;
	}
	bool login()
	{
		ifstream fin;
		fin.open("Employee.txt");
		if (fin.is_open())
		{
		}
		else
		{
			cout << "Error opening file ";
			return false;
		}
		while (!fin.eof())
		{
			string temp;
			getline(fin, temp);
			credentials.push_back(temp);
		}
		fin.close();
		int size = credentials.size();
		passwaords = new char* [size];
		usernames = new  char* [size];
		for (int j = 0; j < size; j++)
		{
			usernames[j] = new char[50];
		}
		for (int j = 0; j < size; j++)
		{
			passwaords[j] = new char[20];
		}
		for (int i = 0; i < size; i++)
		{
			int j = 0;
			for (; credentials[i][j] != ','; j++)
			{
				usernames[i][j] = credentials[i][j];
			}
			usernames[i][j] = '\0';
		}
		for (int i = 0; i < size; i++)
		{
			int j = 0;
			int k = 0;
			bool check = false;
			for (int l = 0; credentials[i][l] != ','; l++)
			{
				j++;
			}
			j++;
			for (; credentials[i][j] != '\0'; j++, k++)
			{
				passwaords[i][k] = credentials[i][j];
			}
			passwaords[i][k] = '\0';
		}
		bool user = false;
		bool pass = false;
		for (int i = 0; i < size; i++)
		{
			if (username == usernames[i])
			{
				user = true;
				index = i;
				break;
			}
		}
		for (int i = 0; i < size; i++)
		{
			if (password == passwaords[i])
			{
				pass = true;
				break;
			}
		}

		if (user && pass)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void password_change()
	{
		string pass;
		while (1)
		{
			cout << "Enter the new password :";
			cin >> pass;
			if (pass.size() < 21)
			{
				passwaords[index] = new char[20];
				int i = 0;
				for (; i < pass.size(); i++)
				{
					passwaords[index][i] = pass[i];
				}
				passwaords[index][i] = '\0';

				ofstream fout;
				fout.open("Employee.txt");
				for (int i = 0; i < credentials.size(); i++)
				{
					fout << usernames[i] << "," << passwaords[i];
					if (i != credentials.size() - 1)
						fout << endl;
				}
				fout.close();
				break;
			}
			else {
				cout << "Invalid lenght try agin";
				break;
			}
		}



	}
	void tax_tarif_file_updation()
	{

		char choice;
		ifstream fin;
		while (1)
		{
			string taxinfo[4];
			fin.open("TariffTaxInfo.txt");
			if (fin.is_open())
			{
				for (int i = 0; i < 4; i++)
				{
					getline(fin, taxinfo[i]);
				}
			}
			else
			{
				cout << "Cannot open the Tariff Tax file  " << endl;
				return;
			}
			fin.close();
			cout << "Press 1 to change tariff and tax information about domestic customers with 1-phase meter " << endl;
			cout << "Press 2 to change tariff and tax information about commercial customers with 1-phase meter " << endl;
			cout << "Press 3 to change tariff and tax information about domestic customers with 3-phase meter " << endl;
			cout << "Press 4 to change tariff and tax information about commercial customers with 3-phase meter " << endl;
			cout << "Press 5 to go back to main menu" << endl;
			choice = _getch();
			if (choice == '1')
			{
				system("CLS");
				tax_tarif_file_updation_row1(taxinfo);
			}
			else if (choice == '2')
			{
				system("CLS");
				tax_tarif_file_updation_row2(taxinfo);
			}
			else if (choice == '3')
			{
				system("CLS");
				tax_tarif_file_updation_row3(taxinfo);
			}
			else if (choice == '4')
			{
				system("CLS");
				tax_tarif_file_updation_row4(taxinfo);
			}
			else if (choice == '5')
			{
				system("CLS");
				return;
			}
			else
			{
				system("CLS");
				cout << "Invalid Entery" << endl;
				cout << "Press 1 to try again " << endl;
				cout << "Press 2 to go back to main menu" << endl;
				choice = _getche();
				if (choice == '1')
				{
					system("CLS");
					continue;

				}
				else
				{
					system("CLS");
					return;

				}
			}
		}

	}
	void tax_tarif_file_updation_row1(string taxinfo[])
	{
		char choice;
		while (1)
		{
			cout << "Press 1 to update meter type " << endl;
			cout << "Press 2 to update regular unit price " << endl;
			cout << "Press 3 to update peak hour unit price " << endl;
			cout << "Press 4 to update the percentage of tax " << endl;
			cout << "Press 5 to update fixed charges " << endl;
			choice = _getche();
			if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5')
			{
				system("CLS");
				if (choice == '1')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						string change;
						int count = -1;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						fout << change;
						for (int i = 0; i < taxinfo[0].size(); i++)
						{
							if (taxinfo[0][i] == ',')
							{
								count = 0;
							}
							if (count == 0)
							{
								fout << taxinfo[0][i];
							}
						}
						fout << endl;
						fout << taxinfo[1];
						fout << endl;
						fout << taxinfo[2];
						fout << endl;
						fout << taxinfo[3];
						fout << endl;
						fout.close();
					}
				}
				if (choice == '2')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						string change;
						int count = 0;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						int i = 0;
						for (; i < taxinfo[0].size(); i++)
						{
							if (taxinfo[0][i] == ',')
							{
								count++;
							}
							fout << taxinfo[0][i];
							if (count == 1)
							{
								break;
							}
						}
						fout << change;
						count = 0;
						i = i + 1;
						for (; i < taxinfo[0].size(); i++)
						{
							if (taxinfo[0][i] == ',')
							{
								count++;
							}
							if (count == 1)
							{
								break;
							}
						}
						for (; i < taxinfo[0].size(); i++)
						{
							fout << taxinfo[0][i];
						}
						fout << endl;
						fout << taxinfo[1];
						fout << endl;
						fout << taxinfo[2];
						fout << endl;
						fout << taxinfo[3];
						fout << endl;
						fout.close();
					}
				}
				if (choice == '3')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						string change;
						int count = 0;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						int i = 0;
						for (; i < taxinfo[0].size(); i++)
						{
							if (taxinfo[0][i] == ',')
							{
								count++;
							}
							fout << taxinfo[0][i];
							if (count == 2)
							{
								break;
							}
						}
						fout << change;
						count = 0;
						i = i + 1;
						for (; i < taxinfo[0].size(); i++)
						{
							if (taxinfo[0][i] == ',')
							{
								count++;
							}
							if (count == 1)
							{
								break;
							}
						}
						for (; i < taxinfo[0].size(); i++)
						{
							fout << taxinfo[0][i];
						}
						fout << endl;
						fout << taxinfo[1];
						fout << endl;
						fout << taxinfo[2];
						fout << endl;
						fout << taxinfo[3];
						fout << endl;
						fout.close();
					}

				}
				if (choice == '4')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						string change;
						int count = 0;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						int i = 0;
						for (; i < taxinfo[0].size(); i++)
						{
							if (taxinfo[0][i] == ',')
							{
								count++;
							}
							fout << taxinfo[0][i];
							if (count == 3)
							{
								break;
							}
						}
						fout << change;
						count = 0;
						i = i + 1;
						for (; i < taxinfo[0].size(); i++)
						{
							if (taxinfo[0][i] == ',')
							{
								count++;
							}
							if (count == 1)
							{
								break;
							}
						}
						for (; i < taxinfo[0].size(); i++)
						{
							fout << taxinfo[0][i];
						}
						fout << endl;
						fout << taxinfo[1];
						fout << endl;
						fout << taxinfo[2];
						fout << endl;
						fout << taxinfo[3];
						fout << endl;
						fout.close();
					}

				}

				if (choice == '5')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						string change;
						int count = 0;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						int i = 0;
						for (; i < taxinfo[0].size(); i++)
						{
							if (taxinfo[0][i] == ',')
							{
								count++;
							}
							fout << taxinfo[0][i];
							if (count == 4)
							{
								break;
							}
						}
						fout << change;
						count = 0;
						i = i + 1;
						for (; i < taxinfo[0].size(); i++)
						{
							if (taxinfo[0][i] == ',')
							{
								count++;
							}
							if (count == 1)
							{
								break;
							}
						}
						for (; i < taxinfo[0].size(); i++)
						{
							fout << taxinfo[0][i];
						}
						fout << endl;
						fout << taxinfo[1];
						fout << endl;
						fout << taxinfo[2];
						fout << endl;
						fout << taxinfo[3];
						fout << endl;
						fout.close();
					}

				}

				break;
			}
			else
			{
				system("CLS");
				cout << "Invalid Entery" << endl;
				cout << "Press 1 to try again " << endl;
				cout << "Press 2 to go back" << endl;
				choice = _getche();
				if (choice == '1')
				{
					system("CLS");
					continue;

				}
				else
				{
					system("CLS");
					return;

				}
			}
		}

	}
	void tax_tarif_file_updation_row2(string taxinfo[])
	{
		char choice;
		while (1)
		{
			cout << "Press 1 to update meter type " << endl;
			cout << "Press 2 to update regular unit price " << endl;
			cout << "Press 3 to update peak hour unit price " << endl;
			cout << "Press 4 to update the percentage of tax " << endl;
			cout << "Press 5 to update fixed charges " << endl;
			choice = _getche();
			if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5')
			{
				system("CLS");
				if (choice == '1')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						fout << taxinfo[0];
						fout << endl;
						string change;
						int count = -1;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						fout << change;
						for (int i = 0; i < taxinfo[1].size(); i++)
						{
							if (taxinfo[1][i] == ',')
							{
								count = 0;
							}
							if (count == 0)
							{
								fout << taxinfo[1][i];
							}
						}

						fout << endl;
						fout << taxinfo[2];
						fout << endl;
						fout << taxinfo[3];
						fout << endl;
						fout.close();
					}
				}
				if (choice == '2')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						fout << taxinfo[0];
						fout << endl;
						string change;
						int count = 0;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						int i = 0;
						for (; i < taxinfo[1].size(); i++)
						{
							if (taxinfo[1][i] == ',')
							{
								count++;
							}
							fout << taxinfo[1][i];
							if (count == 1)
							{
								break;
							}
						}
						fout << change;
						count = 0;
						i = i + 1;
						for (; i < taxinfo[1].size(); i++)
						{
							if (taxinfo[1][i] == ',')
							{
								count++;
							}
							if (count == 1)
							{
								break;
							}
						}
						for (; i < taxinfo[1].size(); i++)
						{
							fout << taxinfo[1][i];
						}
						fout << endl;
						fout << taxinfo[2];
						fout << endl;
						fout << taxinfo[3];
						fout << endl;
						fout.close();
					}
				}
				if (choice == '3')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						fout << taxinfo[0];
						fout << endl;
						string change;
						int count = 0;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						int i = 0;
						for (; i < taxinfo[1].size(); i++)
						{
							if (taxinfo[1][i] == ',')
							{
								count++;
							}
							fout << taxinfo[1][i];
							if (count == 2)
							{
								break;
							}
						}
						fout << change;
						count = 0;
						i = i + 1;
						for (; i < taxinfo[1].size(); i++)
						{
							if (taxinfo[1][i] == ',')
							{
								count++;
							}
							if (count == 1)
							{
								break;
							}
						}
						for (; i < taxinfo[1].size(); i++)
						{
							fout << taxinfo[1][i];
						}
						fout << endl;
						fout << taxinfo[2];
						fout << endl;
						fout << taxinfo[3];
						fout << endl;
						fout.close();
					}

				}
				if (choice == '4')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						fout << taxinfo[0];
						fout << endl;
						string change;
						int count = 0;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						int i = 0;
						for (; i < taxinfo[1].size(); i++)
						{
							if (taxinfo[1][i] == ',')
							{
								count++;
							}
							fout << taxinfo[1][i];
							if (count == 3)
							{
								break;
							}
						}
						fout << change;
						count = 0;
						i = i + 1;
						for (; i < taxinfo[1].size(); i++)
						{
							if (taxinfo[1][i] == ',')
							{
								count++;
							}
							if (count == 1)
							{
								break;
							}
						}
						for (; i < taxinfo[1].size(); i++)
						{
							fout << taxinfo[1][i];
						}
						fout << endl;
						fout << taxinfo[2];
						fout << endl;
						fout << taxinfo[3];
						fout << endl;
						fout.close();
					}

				}

				if (choice == '5')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						fout << taxinfo[0];
						fout << endl;
						string change;
						int count = 0;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						int i = 0;
						for (; i < taxinfo[1].size(); i++)
						{
							if (taxinfo[1][i] == ',')
							{
								count++;
							}
							fout << taxinfo[1][i];
							if (count == 4)
							{
								break;
							}
						}
						fout << change;
						count = 0;
						i = i + 1;
						for (; i < taxinfo[1].size(); i++)
						{
							if (taxinfo[1][i] == ',')
							{
								count++;
							}
							if (count == 1)
							{
								break;
							}
						}
						for (; i < taxinfo[1].size(); i++)
						{
							fout << taxinfo[1][i];
						}
						fout << endl;
						fout << taxinfo[2];
						fout << endl;
						fout << taxinfo[3];
						fout << endl;
						fout.close();
					}

				}

				break;
			}
			else
			{
				system("CLS");
				cout << "Invalid Entery" << endl;
				cout << "Press 1 to try again " << endl;
				cout << "Press 2 to go back" << endl;
				choice = _getche();
				if (choice == '1')
				{
					system("CLS");
					continue;

				}
				else
				{
					system("CLS");
					return;

				}
			}
		}
	}
	void tax_tarif_file_updation_row3(string taxinfo[])
	{
		char choice;
		while (1)
		{
			cout << "Press 1 to update meter type " << endl;
			cout << "Press 2 to update regular unit price " << endl;
			cout << "Press 3 to update peak hour unit price " << endl;
			cout << "Press 4 to update the percentage of tax " << endl;
			cout << "Press 5 to update fixed charges " << endl;
			choice = _getche();
			if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5')
			{
				system("CLS");
				if (choice == '1')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						fout << taxinfo[0];
						fout << endl;
						fout << taxinfo[1];
						fout << endl;
						string change;
						int count = -1;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						fout << change;
						for (int i = 0; i < taxinfo[2].size(); i++)
						{
							if (taxinfo[2][i] == ',')
							{
								count = 0;
							}
							if (count == 0)
							{
								fout << taxinfo[2][i];
							}
						}
						fout << endl;
						fout << taxinfo[3];
						fout << endl;
						fout.close();
					}
				}
				if (choice == '2')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						fout << taxinfo[0];
						fout << endl;
						fout << taxinfo[1];
						fout << endl;
						string change;
						int count = 0;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						int i = 0;
						for (; i < taxinfo[2].size(); i++)
						{
							if (taxinfo[2][i] == ',')
							{
								count++;
							}
							fout << taxinfo[2][i];
							if (count == 1)
							{
								break;
							}
						}
						fout << change;
						count = 0;
						i = i + 1;
						for (; i < taxinfo[2].size(); i++)
						{
							if (taxinfo[2][i] == ',')
							{
								count++;
							}
							if (count == 1)
							{
								break;
							}
						}
						for (; i < taxinfo[2].size(); i++)
						{
							fout << taxinfo[2][i];
						}
						fout << endl;
						fout << taxinfo[3];
						fout << endl;
						fout.close();
					}
				}
				if (choice == '3')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						fout << taxinfo[0];
						fout << endl;
						fout << taxinfo[1];
						fout << endl;
						string change;
						int count = 0;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						int i = 0;
						for (; i < taxinfo[2].size(); i++)
						{
							if (taxinfo[2][i] == ',')
							{
								count++;
							}
							fout << taxinfo[2][i];
							if (count == 2)
							{
								break;
							}
						}
						fout << change;
						count = 0;
						i = i + 1;
						for (; i < taxinfo[2].size(); i++)
						{
							if (taxinfo[2][i] == ',')
							{
								count++;
							}
							if (count == 1)
							{
								break;
							}
						}
						for (; i < taxinfo[2].size(); i++)
						{
							fout << taxinfo[2][i];
						}
						fout << endl;
						fout << taxinfo[3];
						fout << endl;
						fout.close();
					}

				}
				if (choice == '4')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						fout << taxinfo[0];
						fout << endl;
						fout << taxinfo[1];
						fout << endl;
						string change;
						int count = 0;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						int i = 0;
						for (; i < taxinfo[2].size(); i++)
						{
							if (taxinfo[2][i] == ',')
							{
								count++;
							}
							fout << taxinfo[2][i];
							if (count == 3)
							{
								break;
							}
						}
						fout << change;
						count = 0;
						i = i + 1;
						for (; i < taxinfo[2].size(); i++)
						{
							if (taxinfo[2][i] == ',')
							{
								count++;
							}
							if (count == 1)
							{
								break;
							}
						}
						for (; i < taxinfo[2].size(); i++)
						{
							fout << taxinfo[2][i];
						}
						fout << endl;
						fout << taxinfo[3];
						fout << endl;
						fout.close();
					}

				}

				if (choice == '5')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						fout << taxinfo[0];
						fout << endl;
						fout << taxinfo[1];
						fout << endl;
						string change;
						int count = 0;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						int i = 0;
						for (; i < taxinfo[2].size(); i++)
						{
							if (taxinfo[2][i] == ',')
							{
								count++;
							}
							fout << taxinfo[2][i];
							if (count == 4)
							{
								break;
							}
						}
						fout << change;
						count = 0;
						i = i + 1;
						for (; i < taxinfo[2].size(); i++)
						{
							if (taxinfo[2][i] == ',')
							{
								count++;
							}
							if (count == 1)
							{
								break;
							}
						}
						for (; i < taxinfo[2].size(); i++)
						{
							fout << taxinfo[2][i];
						}
						fout << endl;
						fout << taxinfo[3];
						fout << endl;
						fout.close();
					}

				}

				break;
			}
			else
			{
				system("CLS");
				cout << "Invalid Entery" << endl;
				cout << "Press 1 to try again " << endl;
				cout << "Press 2 to go back" << endl;
				choice = _getche();
				if (choice == '1')
				{
					system("CLS");
					continue;

				}
				else
				{
					system("CLS");
					return;

				}
			}
		}
	}
	void tax_tarif_file_updation_row4(string taxinfo[])
	{
		char choice;
		while (1)
		{
			cout << "Press 1 to update meter type " << endl;
			cout << "Press 2 to update regular unit price " << endl;
			cout << "Press 3 to update peak hour unit price " << endl;
			cout << "Press 4 to update the percentage of tax " << endl;
			cout << "Press 5 to update fixed charges " << endl;
			choice = _getche();
			if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5')
			{
				system("CLS");
				if (choice == '1')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						fout << taxinfo[0];
						fout << endl;
						fout << taxinfo[1];
						fout << endl;
						fout << taxinfo[2];
						fout << endl;
						string change;
						int count = -1;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						fout << change;
						for (int i = 0; i < taxinfo[3].size(); i++)
						{
							if (taxinfo[3][i] == ',')
							{
								count = 0;
							}
							if (count == 0)
							{
								fout << taxinfo[3][i];
							}
						}
						fout << endl;
						fout.close();
					}
				}
				if (choice == '2')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						fout << taxinfo[0];
						fout << endl;
						fout << taxinfo[1];
						fout << endl;
						fout << taxinfo[2];
						fout << endl;
						string change;
						int count = 0;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						int i = 0;
						for (; i < taxinfo[3].size(); i++)
						{
							if (taxinfo[3][i] == ',')
							{
								count++;
							}
							fout << taxinfo[3][i];
							if (count == 1)
							{
								break;
							}
						}
						fout << change;
						count = 0;
						i = i + 1;
						for (; i < taxinfo[3].size(); i++)
						{
							if (taxinfo[3][i] == ',')
							{
								count++;
							}
							if (count == 1)
							{
								break;
							}
						}
						for (; i < taxinfo[3].size(); i++)
						{
							fout << taxinfo[3][i];
						}
						fout << endl;
						fout.close();
					}
				}
				if (choice == '3')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						fout << taxinfo[0];
						fout << endl;
						fout << taxinfo[1];
						fout << endl;
						fout << taxinfo[2];
						fout << endl;
						string change;
						int count = 0;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						int i = 0;
						for (; i < taxinfo[3].size(); i++)
						{
							if (taxinfo[3][i] == ',')
							{
								count++;
							}
							fout << taxinfo[3][i];
							if (count == 2)
							{
								break;
							}
						}
						fout << change;
						count = 0;
						i = i + 1;
						for (; i < taxinfo[3].size(); i++)
						{
							if (taxinfo[3][i] == ',')
							{
								count++;
							}
							if (count == 1)
							{
								break;
							}
						}
						for (; i < taxinfo[3].size(); i++)
						{
							fout << taxinfo[3][i];
						}
						fout << endl;
						fout.close();
					}

				}
				if (choice == '4')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						fout << taxinfo[0];
						fout << endl;
						fout << taxinfo[1];
						fout << endl;
						fout << taxinfo[2];
						fout << endl;
						string change;
						int count = 0;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						int i = 0;
						for (; i < taxinfo[3].size(); i++)
						{
							if (taxinfo[3][i] == ',')
							{
								count++;
							}
							fout << taxinfo[3][i];
							if (count == 3)
							{
								break;
							}
						}
						fout << change;
						count = 0;
						i = i + 1;
						for (; i < taxinfo[3].size(); i++)
						{
							if (taxinfo[3][i] == ',')
							{
								count++;
							}
							if (count == 1)
							{
								break;
							}
						}
						for (; i < taxinfo[3].size(); i++)
						{
							fout << taxinfo[3][i];
						}
						fout << endl;
						fout.close();
					}

				}

				if (choice == '5')
				{
					ofstream fout;
					fout.open("TariffTaxInfo.txt");
					if (fout.is_open())
					{
						fout << taxinfo[0];
						fout << endl;
						fout << taxinfo[1];
						fout << endl;
						fout << taxinfo[2];
						fout << endl;
						string change;
						int count = 0;
						cout << "Enter the updation " << endl;
						getline(cin, change);
						int i = 0;
						for (; i < taxinfo[3].size(); i++)
						{
							if (taxinfo[3][i] == ',')
							{
								count++;
							}
							fout << taxinfo[3][i];
							if (count == 4)
							{
								break;
							}
						}
						fout << change;
						count = 0;
						i = i + 1;
						for (; i < taxinfo[3].size(); i++)
						{
							if (taxinfo[3][i] == ',')
							{
								count++;
							}
							if (count == 1)
							{
								break;
							}
						}
						for (; i < taxinfo[3].size(); i++)
						{
							fout << taxinfo[3][i];
						}
						fout << endl;
						fout.close();
					}

				}

				break;
			}
			else
			{
				system("CLS");
				cout << "Invalid Entery" << endl;
				cout << "Press 1 to try again " << endl;
				cout << "Press 2 to go back" << endl;
				choice = _getche();
				if (choice == '1')
				{
					system("CLS");
					continue;

				}
				else
				{
					system("CLS");
					return;

				}
			}
		}
	}
	void empty()
	{
		credentials.clear();
	}
};
class UpdateCustomer {

	char NewDatatoEnter[10][100];//updated data;
	char inputFromFile[10][100];//get info from file act like a search variable;


	//NewDatatoEnter and inputFromFile have 10 rows containing 10 type of information ....
	//4 digit id,cnic,name,adress,ph no.,customer type,meter type,connection date, regular units,peak hour units;
	char IssueDateForNADRAFile[11];
	char expiryDateForNADRAFile[11];

	char dataToUpdate[5];//to compare data from file takes 4 digit user id;
public:
	UpdateCustomer();
	void input();//takes the input for customer id and data to update;
	void fileSearch();//search the data in file using customer id;
	void UpdateData();//it will update the file if user is found;
	void AddDataTofile();//add new customer;
	void inputId();
	void InputCNIC();
	bool NewcustomerCheck();
	void InputMeterReading();

	void NADRAFile();
	void IssueDate();

	void NADRAFileUpdate();

	void UpdateCustomerMain();//calling all  the functions
};

UpdateCustomer::UpdateCustomer() {
	for (int i = 0; i < 10; i++) {
		strcpy_s(NewDatatoEnter[i], "");
		strcpy_s(inputFromFile[i], "");
	}
	strcpy_s(dataToUpdate, "");
	strcpy_s(IssueDateForNADRAFile, "");
	strcpy_s(expiryDateForNADRAFile, "");
}

//use to print Customer information;
void printData(char a[10][100]) {
	cout << "Customer data" << endl << endl << endl;
	cout << "ID                    :   " << a[0] << endl;
	cout << "CNIC                  :   " << a[1] << endl;
	cout << "Name                  :   " << a[2] << endl;
	cout << "Adress                :   " << a[3] << endl;
	cout << "Phone numer           :   " << a[4] << endl;
	cout << "Customer Type         :   " << a[5] << endl;
	cout << "Meter Type            :   " << a[6] << endl;
	cout << "Connection Date       :   " << a[7] << endl;
	cout << "Regular consumed units:   " << a[8] << endl;
	cout << "Peak consumed units   :   " << a[9] << endl;

	cout << endl << endl << endl;
}

//inputs the customer id for searching purposes in file search and update funtions;
void UpdateCustomer::inputId() {
	//entering 4-digit customer ID;
	{

		cout << "Enter the 4-digit customer ID to edit data:   ";


		for (int i = 0; i < 4; i++)
		{
			dataToUpdate[i] = _getche();
			if (dataToUpdate[i] != '9' && dataToUpdate[i] != '0' && dataToUpdate[i] != '1'
				&& dataToUpdate[i] != '2' && dataToUpdate[i] != '3' && dataToUpdate[i] != '4'
				&& dataToUpdate[i] != '5' && dataToUpdate[i] != '6' && dataToUpdate[i] != '7'
				&& dataToUpdate[i] != '8')
			{
				cout << endl;
				cout << "invalid input " << dataToUpdate[i] << " is not a digit\nEnter Again: ";
				i = -1;

			}
		}
		dataToUpdate[4] = '\0';
	}
}

//taking input in different variales day mmonth and year and then concatinating them to a sigle array with /;
void DateConcatinate(char* a, char* day, char* month, char* year) {
	a[0] = day[0];
	a[1] = day[1];
	a[2] = '/';
	a[3] = month[0];
	a[4] = month[1];
	a[5] = '/';
	a[6] = year[0];
	a[7] = year[1];
	a[8] = year[2];
	a[9] = year[3];
	a[10] = year[4];
}

//funtion to input the customer cnic;
void UpdateCustomer::InputCNIC() {
	{

		cout << "Enter CNIC (Without '-') :  ";

		for (int i = 0; i < 13; i++) {

			NewDatatoEnter[1][i] = _getche();
			if (NewDatatoEnter[1][i] != '9' && NewDatatoEnter[1][i] != '0' && NewDatatoEnter[1][i] != '1'
				&& NewDatatoEnter[1][i] != '2' && NewDatatoEnter[1][i] != '3' && NewDatatoEnter[1][i] != '4'
				&& NewDatatoEnter[1][i] != '5' && NewDatatoEnter[1][i] != '6' && NewDatatoEnter[1][i] != '7'
				&& NewDatatoEnter[1][i] != '8')
			{
				cout << endl;
				cout << "invalid input " << NewDatatoEnter[1][i] << " is not a digit\nEnter Again: ";
				i = -1;
			}
		}
		NewDatatoEnter[1][13] = '\0';
	}
}

//function to input the consumed units and peak units;
void UpdateCustomer::InputMeterReading() {
	{
		int i = 0;
		char unit[10] = "";
		cout << "Enter units:  ";

		for (i; i < 9; i++)
		{
			unit[i] = _getche();
			if (unit[i] == 13 || unit[i] == '\0')
				break;

			else if
				(
					unit[i] != '.' && unit[i] != '0' && unit[i] != '1'
					&& unit[i] != '2' && unit[i] != '3' && unit[i] != '4'
					&& unit[i] != '5' && unit[i] != '6' && unit[i] != '7'
					&& unit[i] != '8' && unit[i] != '9' && unit[i] != '\0'
					&& unit[i] != 13
					)
			{

				cout << endl;
				cout << "units can only be number or floating point '.'";
				cout << "Enter again:  ";

				i = -1;
			}
		}
		unit[i] = '\0';
		strcpy_s(NewDatatoEnter[8], unit);

	}
	//entering peak Hourse unit;
	if (strcmp(NewDatatoEnter[6], "3Phase") == 0)
	{
		int i = 0;

		char peak[10] = "";
		cout << "Enter peak hours unit:  ";
		cin.getline(peak, 10);
		for (i; i < 9; i++)
		{
			peak[i] = _getche();
			if (peak[i] == 13 || peak[i] == '\0')
				break;

			else if (peak[i] != '.' && peak[i] != '0' && peak[i] != '1'
				&& peak[i] != '2' && peak[i] != '3' && peak[i] != '4'
				&& peak[i] != '5' && peak[i] != '6' && peak[i] != '7'
				&& peak[i] != '8' && peak[i] != '9' && peak[i] != '\0' && peak[i] != 13)
			{
				cout << endl;
				cout << "units can only be number or floating point '.'";
				cout << "Enter again:  ";
				i = -1;
			}
		}
		peak[i] = '\0';
		strcpy_s(NewDatatoEnter[9], peak);
	}

}

//in this function user is entering his name, adress,phone number, customertype,meter type and date;
void UpdateCustomer::input() {


	cout << endl;

	//entering name;
	{
		cin.ignore();

		cout << "Enter name(do notpalce ',') : ";
		cin.getline(NewDatatoEnter[2], 100);
		{
			for (int i = 0; NewDatatoEnter[2][i] != '\0'; i++) {
				if (NewDatatoEnter[2][i] == ',') {
					cout << "',' is paced\nEnter Again:   ";
					cin.getline(NewDatatoEnter[2], 100);
				}
			}
		}
		cout << endl;

	}
	//entering address;
	{
		cout << "Enter Address(without','):  ";
		cin.getline(NewDatatoEnter[3], 100);
		NewDatatoEnter[3][99] = '\0';
		for (int i = 0; NewDatatoEnter[3][i] != '\0'; i++) {
			if (NewDatatoEnter[3][i] == ',') {
				i = -1;
				cout << endl;
				cout << "Enter data again:  ";
				cin.getline(NewDatatoEnter[3], 100);
			}
		}
	}

	cout << endl;
	//entering phone number;
	{

		cout << "Enter phone number:  ";

		for (int i = 0; i < 11; i++) {
			NewDatatoEnter[4][i] = _getche();
			if (NewDatatoEnter[4][i] != '9' && NewDatatoEnter[4][i] != '0' && NewDatatoEnter[4][i] != '1'
				&& NewDatatoEnter[4][i] != '2' && NewDatatoEnter[4][i] != '3' && NewDatatoEnter[4][i] != '4'
				&& NewDatatoEnter[4][i] != '5' && NewDatatoEnter[4][i] != '6' && NewDatatoEnter[4][i] != '7'
				&& NewDatatoEnter[4][i] != '8')
			{
				cout << endl;
				cout << "Invalid input Enter phonr number again:  ";
				i = -1;
			}
		}
		NewDatatoEnter[4][11] = '\0';
	}

	cout << endl;
	//selecting customer type;
	{

		char selection;
		cout << "Select customer type: " << endl;
		cout << "1) Commercial " << endl;
		cout << "2) Domestic " << endl;
		cin >> selection;
		while (selection != '1' && selection != '2') {
			cout << "Select 1 or 2" << endl;
			cout << "Enter again: ";
			cin >> selection;

			cout << endl;
		}
		if (selection == '1')
			strcpy_s(NewDatatoEnter[5], "Commercial");
		else
			strcpy_s(NewDatatoEnter[5], "Domestic");
	}

	cout << endl;
	//selecting meter type;
	{

		char select;
		cout << "Select Meter Type:  " << endl;
		cout << "1) 1 Phase Meter" << endl;
		cout << "2) 3 Phase Meter" << endl;
		cin >> select;
		while (select != '1' && select != '2') {

			cout << "Select 1 or 2" << endl;
			cout << "Enter again: ";
			cin >> select;

		}

		if (select == '1')
			strcpy_s(NewDatatoEnter[6], "1Phase");
		else
			strcpy_s(NewDatatoEnter[6], "3Phase");

	}

	cout << endl;
	//entering date;
	{
		char day[3], month[3], year[5];
		//entering day;
		{


			cout << "Enter day (DD):  ";
			day[0] = _getche();
			while (day[0] != '0' && day[0] != '1' && day[0] != '2' && day[0] != '3')
			{
				cout << endl;
				cout << "For first number the only options are 0, 1 and 3" << endl;
				cout << "Enter agian:  ";
				day[0] = _getche();

			}
			day[1] = _getche();

			if (day[0] == '0') {
				while (day[1] != '1' && day[1] != '2' && day[1] != '3'
					&& day[1] != '4' && day[1] != '5' && day[1] != '6'
					&& day[1] != '7' && day[1] != '8' && day[1] != '9')
				{
					cout << endl;
					cout << "For 2nd value the only options are 1 to 9 " << endl;
					cout << "Enter again:  ";
					day[1] = _getche();
				}
			}
			else if (day[0] == '3') {
				while (day[0] == 3 && day[1] != '0' && day[1] != '1') {
					cout << endl;
					cout << "For 2nd vlue the only options are 0 and 1";
					cout << "Enter again:  ";
					day[1] = _getche();
				}
			}

			while (day[1] != '0' && day[1] != '1' && day[1] != '2' && day[1] != '3'
				&& day[1] != '4' && day[1] != '5' && day[1] != '6' && day[1] != '7'
				&& day[1] != '8' && day[1] != '9')
			{
				cout << endl;
				cout << "For 2nd value the only options are 0 to 9 " << endl;
				cout << "Enter again:  ";
				day[1] = _getche();
			}

			day[2] = '\0';


		}
		cout << endl;
		//entering month;
		{
			cout << "Enter Month (MM):  ";
			month[0] = _getche();

			while (month[0] != '0' && month[0] != '1') {
				cout << endl;
				cout << "The only options are 0 and 1" << endl;
				cout << "Enter again:  ";
				month[0] = _getche();
			}
			month[1] = _getche();
			while (
				month[0] == '0'
				&& month[1] != '1' && month[1] != '2' && month[1] != '3'
				&& month[1] != '4' && month[1] != '5' && month[1] != '6'
				&& month[1] != '7' && month[1] != '8' && month[1] != '9'
				)
			{
				cout << endl;
				cout << "The option ranges from 1 to 9" << endl;
				cout << "Enter again:  ";
			}

			while (month[0] == '1' && month[1] != '0' && month[1] != '1' && month[1] != '2')
			{
				cout << endl;
				cout << "The only options are 0, 1 and 2" << endl;
				cout << "Enter again:  ";
				month[1] = _getche();
			}

			month[2] = '\0';
		}
		cout << endl;
		//entering year;
		{
			cout << "Enter year (YYYY):  ";
			//input first digit;
			year[0] = _getche();
			while (year[0] != '1' && year[0] != '2') {
				cout << endl;
				cout << "For 1st vlue the only options are 1 and 2" << endl;
				cout << "Enter agian:  ";
				year[0] = _getche();
			}
			//input second digit;
			year[1] = _getche();
			while (year[0] == '1' && year[1] != '9') {
				cout << endl;
				cout << "Your only option is 9" << endl;
				cout << "Enter again:  ";
				year[1] = _getche();
			}
			while (year[0] == '2' && year[1] != '0') {
				cout << endl;
				cout << "Your only option is 0" << endl;
				cout << "Enter agian:  ";
				year[1] = _getche();
			}
			//input 3rd digit;
			year[2] = _getche();
			while (year[0] == '1' && year[1] == '9' && year[2] != '1'
				&& year[2] != '2' && year[2] != '3' && year[2] != '4'
				&& year[2] != '5' && year[2] != '6' && year[2] != '7'
				&& year[2] != '8' && year[2] != '9')
			{
				cout << endl;
				cout << "Your only options are 1 to 9" << endl;
				cout << "Enter again:  ";
				year[2] = _getche();
			}
			while (year[0] == '2' && year[1] == '0' && year[2] != '1'
				&& year[2] != '2' && year[2] != '0')
			{
				cout << endl;
				cout << "Your only options are 0, 1 and 2" << endl;
				cout << "Enter again:  ";
				year[2] = _getche();
			}

			//input 4th digit;
			year[3] = _getche();

			while (year[0] == '1' && year[1] == '9' && year[2] == '1'
				&& year[3] != '3' && year[3] != '4' && year[3] != '5'
				&& year[3] != '6' && year[3] != '7' && year[3] != '8'
				&& year[3] != '9')
			{
				cout << endl;
				cout << "your only options are 3 to 9" << endl;
				cout << "Enter agian:  ";
				year[3] = _getche();
			}
			while (year[0] == '2' && year[1] == '0' && year[2] == '2'
				&& year[3] != '0' && year[3] != '1' && year[3] != '2') {
				cout << endl;
				cout << "Your only options are 0, 1 and 2" << endl;
				cout << "Enter agian:  ";
				year[3] = _getche();
			}
			year[4] = '\0';
		}

		DateConcatinate(NewDatatoEnter[7], day, month, year);
	}

	cout << endl;

}

//to assign a custer id frist did the file search for number of enteries in file and then converted that into the customer id in string form;
void IntToChar(char b[], int a) {


	int n = 1000;
	for (int i = 0; i < 4; i++) {
		b[i] = (char)((a / n) + 48);
		a = a % n;
		n /= 10;
	}
	b[4] = '\0';

}

//checking if there are more than 3 user with same cnic;
bool UpdateCustomer::NewcustomerCheck() {

	int counter = 0;
	{
		ofstream fout;
		fout.open("Customerinfo.txt");
		fout.close();
	}

	ifstream fin;
	fin.open("Customerinfo.txt", ios::in);

	char extra[100] = "";
	char c;
	int i = 0;

	while (fin.get(c)) {
		if (c == ',') {
			extra[i] = '\0';
			if (strcmp(extra, NewDatatoEnter[1]) == 0) {
				counter++;
			}
			i = 0;
		}
		extra[i++] = c;
	}


	return (counter < 4);
}

//this function is used to add new customer data into the file;
void UpdateCustomer::AddDataTofile() {
	char c;
	int counter = 1;

	InputCNIC();
	if (NewcustomerCheck()) {
		ifstream fin;
		fin.open("Customerinfo.txt", ios::in);

		while (fin.get(c)) {
			if (c == '\n')
				counter++;
		}
		fin.close();
		if (counter > 9999) {
			cout << "The file is full" << endl;
			return;
		}




		//user id;
		strcpy_s(NewDatatoEnter[0], "");

		IntToChar(NewDatatoEnter[0], counter);

		input();

		strcpy_s(NewDatatoEnter[8], "0");
		strcpy_s(NewDatatoEnter[9], "0");

		{
			ofstream fout;
			fout.open("Customerinfo.txt", ios::app);
			fout << NewDatatoEnter[0] << ',' << NewDatatoEnter[1] << ',' << NewDatatoEnter[2]
				<< ',' << NewDatatoEnter[3] << ',' << NewDatatoEnter[4] << ',' << NewDatatoEnter[5]
				<< ',' << NewDatatoEnter[6] << ',' << NewDatatoEnter[7] << ',' << NewDatatoEnter[8]
				<< ',' << NewDatatoEnter[9] << '\n';

			fout.close();
		}
		NADRAFile();
	}
	else cout << "Customer limit on CNIC reached";



}

//this function is used to search the data in file after providing customer id;
void UpdateCustomer::fileSearch() {
	inputId();
	char c;
	bool flag = false;
	bool IDcommpare = true;
	ifstream fin;
	int i = 0, j = 0;

	fin.open("Customerinfo.txt", ios::in);
	while (fin.get(c)) {
		{
			if (c == ',') {
				inputFromFile[j][i] = '\0';
				i = 0;
				j++;

			}
			else if (c == '\n') {
				inputFromFile[j][i] = '\0';
				if (IDcommpare == true) {
					flag = true;
					break;
				}

				i = 0;
				j = 0;
				IDcommpare = true;
			}
			else
				inputFromFile[j][i++] = c;
		}
		cout << endl;
		{
			if (IDcommpare == true) {
				if (strcmp(inputFromFile[0], dataToUpdate) == 0) {
					IDcommpare = true;
				}
				else
					IDcommpare = false;
			}
		}
	}
	fin.close();
	if (flag == true)
		printData(inputFromFile);
	else
		cout << "NO Data Found" << endl << endl << endl;

}

//used to update the data for customer info file; 
void UpdateCustomer::UpdateData() {
	//inputs;
	inputId();
	cout << "Enter Updated data" << endl << endl;

	input();

	//opening files;
	ifstream fin("Customerinfo.txt", ios::in);
	ofstream fout("temp.txt", ios::app);

	//character to take input form customerinfo.txt;
	char c;
	//integers to controll variables;
	int i = 0, j = 0;



	while (fin.get(c)) {
		if (c == ',') {
			inputFromFile[i][j] = '\0';
			if (strcmp(inputFromFile[0], dataToUpdate) == 0) {
				strcpy_s(inputFromFile[i], NewDatatoEnter[i]);
			}
			i++;
			j = 0;
		}
		else if (c == '\n') {
			inputFromFile[i][j] = '\0';
			if (strcmp(inputFromFile[0], dataToUpdate) == 0) {
				strcpy_s(inputFromFile[i], NewDatatoEnter[i]);
			}
			fout << inputFromFile[0] << ',' << inputFromFile[1] << ',' << inputFromFile[2]
				<< ',' << inputFromFile[3] << ',' << inputFromFile[4] << ',' << inputFromFile[5]
				<< ',' << inputFromFile[6] << ',' << inputFromFile[7] << ',' << inputFromFile[8]
				<< ',' << inputFromFile[9] << '\n';
		}
		else
			inputFromFile[i][j++] = c;
	}

	fin.close();
	fout.close();
	remove("Customerinfo.txt");
	rename("temp.txt", "Customerinfo.txt");
}

//saving customer's id card information in NADRA file;
void UpdateCustomer::NADRAFile() {
	ofstream fout("NADRA.txt", ios::app);
	cout << endl;

	IssueDate();

	fout << NewDatatoEnter[1] << ',' << IssueDateForNADRAFile << ',' << expiryDateForNADRAFile << '\n';

	fout.close();
}

//Update The data of file NADRA;
void UpdateCustomer::NADRAFileUpdate() {

	ifstream fin("NADRA.txt", ios::in);

	ofstream fout("temp.txt", ios::app);


	char CNIC[14];

	{//gTTING CNIC FOR SEARCH PUPOSE;
		cout << "Enter CNIC Whose data you want to change (Without '-') :  ";

		for (int i = 0; i < 13; i++) {

			CNIC[i] = _getche();
			if (CNIC[i] != '9' && CNIC[i] != '0' && CNIC[i] != '1'
				&& CNIC[i] != '2' && CNIC[i] != '3' && CNIC[i] != '4'
				&& CNIC[i] != '5' && CNIC[i] != '6' && CNIC[i] != '7'
				&& CNIC[i] != '8')
			{
				cout << endl;
				cout << "invalid input " << CNIC[i] << " is not a digit\nEnter Again: ";
				i = -1;
			}
		}
		CNIC[13] = '\0';
	}
	char DataFromNADRA[3][14], c;


	int i = 0, j = 0;
	bool flag = false;

	while (fin.get(c)) {

		if (c == ',') {
			DataFromNADRA[i][j] = '\0';
			if (strcmp(CNIC, DataFromNADRA[0]) == 0) {
				flag = true;
				cout << "Enter Updated Issue Date" << endl << endl;
				IssueDate();

			}
			j = 0;
			i++;
		}
		if (c == '\n') {
			DataFromNADRA[i][j] = '\0';
			if (flag) {
				fout << CNIC << ',' << IssueDateForNADRAFile << ',' << expiryDateForNADRAFile << '\n';
			}
			else
				fout << DataFromNADRA[0] << ',' << DataFromNADRA[1] << ',' << DataFromNADRA[2] << '\n';


			j = 0;
			i = 0;

		}

		DataFromNADRA[i][j++] = c;
	}
	if (!flag) {
		std::cout << CNIC << " was not found";
	}
	fin.close();
	fout.close();

	remove("NADRA.txt");
	rename("temp.txt", "NADRA.txt");



}

//use to input Issue date of id card and also convert it into expiry date of +10 years;
void UpdateCustomer::IssueDate() {
	//entering day

	cout << "Enter Issue date" << endl << endl;

	char day[3], month[3], * year = new char[5];

	{
		cout << "Enter day (DD):  ";
		day[0] = _getche();
		while (day[0] != '0' && day[0] != '1' && day[0] != '2' && day[0] != '3')
		{
			cout << endl;
			cout << "For first number the only options are 0, 1 and 3" << endl;
			cout << "Enter agian:  ";
			day[0] = _getche();
		}
		day[1] = _getche();

		if (day[0] == '0') {
			while (day[1] != '1' && day[1] != '2' && day[1] != '3'
				&& day[1] != '4' && day[1] != '5' && day[1] != '6'
				&& day[1] != '7' && day[1] != '8' && day[1] != '9')
			{
				cout << endl;
				cout << "For 2nd value the only options are 1 to 9 " << endl;
				cout << "Enter again:  ";
				day[1] = _getche();
			}
		}
		else if (day[0] == '3') {
			while (day[0] == 3 && day[1] != '0' && day[1] != '1') {
				cout << endl;
				cout << "For 2nd vlue the only options are 0 and 1";
				cout << "Enter again:  ";
				day[1] = _getche();
			}
		}

		while (day[1] != '0' && day[1] != '1' && day[1] != '2' && day[1] != '3'
			&& day[1] != '4' && day[1] != '5' && day[1] != '6' && day[1] != '7'
			&& day[1] != '8' && day[1] != '9')
		{
			cout << endl;
			cout << "For 2nd value the only options are 0 to 9 " << endl;
			cout << "Enter again:  ";
			day[1] = _getche();
		}

		day[2] = '\0';
	}
	cout << endl;
	//entering month;
	{
		cout << "Enter Month (MM):  ";
		month[0] = _getche();

		while (month[0] != '0' && month[0] != '1') {
			cout << endl;
			cout << "The only options are 0 and 1" << endl;
			cout << "Enter again:  ";
			month[0] = _getche();
		}
		month[1] = _getche();
		while (
			month[0] == '0'
			&& month[1] != '1' && month[1] != '2' && month[1] != '3'
			&& month[1] != '4' && month[1] != '5' && month[1] != '6'
			&& month[1] != '7' && month[1] != '8' && month[1] != '9'
			)
		{
			cout << endl;
			cout << "The option ranges from 1 to 9" << endl;
			cout << "Enter again:  ";
		}

		while (month[0] == '1' && month[1] != '0' && month[1] != '1' && month[1] != '2')
		{
			cout << endl;
			cout << "The only options are 0, 1 and 2" << endl;
			cout << "Enter again:  ";
			month[1] = _getche();
		}

		month[2] = '\0';
	}
	//entering year;
	cout << endl;
	{
		cout << "Enter year (YYYY):  ";
		//input first digit;
		year[0] = _getche();
		while (year[0] != '2') {
			cout << endl;
			cout << "For 1st vlue the only options is 2 as NADRA was established in 2000" << endl;
			cout << "Enter agian:  ";
			year[0] = _getche();
		}
		//input second digit;
		year[1] = _getche();
		while (year[0] == '2' && year[1] != '0') {
			cout << endl;
			cout << "Your only option is 0" << endl;
			cout << "Enter agian:  ";
			year[1] = _getche();
		}
		//input 3rd digit;
		year[2] = _getche();
		while (year[0] == '2' && year[1] == '0' && year[2] != '1'
			&& year[2] != '2' && year[2] != '0')
		{
			cout << endl;
			cout << "Your only options are 0, 1 and 2" << endl;
			cout << "Enter again:  ";
			year[2] = _getche();
		}

		//input 4th digit;
		year[3] = _getche();
		while (year[0] == '2' && year[1] == '0' && (year[2] == '0' || year[2] == '1')
			&& year[3] != '1' && year[3] != '2' && year[3] != '3' && year[3] != '4'
			&& year[3] != '5' && year[3] != '6' && year[3] != '7' && year[3] != '8'
			&& year[3] != '9' && year[3] != '0')
		{
			cout << "Your only optios are 0 to 9" << endl;
			cout << "Enter again:  ";

			year[3] = _getche();
		}
		while (year[0] == '2' && year[1] == '0' && year[2] == '2'
			&& year[3] != '0' && year[3] != '1' && year[3] != '2') {
			cout << endl;
			cout << "Your only options are 0, 1 and 2" << endl;
			cout << "Enter agian:  ";
			year[3] = _getche();
		}
		year[4] = '\0';
	}

	DateConcatinate(IssueDateForNADRAFile, day, month, year);

	int YEAR = atoi(year);

	YEAR += 10;

	IntToChar(year, YEAR);

	DateConcatinate(expiryDateForNADRAFile, day, month, year);



}

void UpdateCustomer::UpdateCustomerMain() {

	char c;
	cout << "Select options: " << endl;
	cout << "3. Add new customer" << endl;
	cout << "4. Update Customer data" << endl;
	cout << "5. Update issue date for CNIC of customer" << endl;
	cout << "6. go back" << endl;
	cin >> c;

	while (c != '3' && c != '4' && c != '5' && c!='6') {
		cout << "Your only options are 3, 4 and 5" << endl;
		cout << "Enter again: ";
		cin >> c;
	}

	switch (c) {
	case'3':
		AddDataTofile();
		break;
	case'4':
		UpdateData();
		break;
	case'5':
		NADRAFileUpdate();
		break;
	case'6':
		return;
		break;
	}
}
class customer {
public:
	bool cutomer_login(string username,string password)
	{
		char** passwords;
		char** usernames;
		vector <string> credentials;
		ifstream fin;
		fin.open("customerinfo.txt");
		if (fin.is_open())
		{

		}
		else
		{
			cout << "Error opening file ";
			return false;
		}
		while (!fin.eof())
		{
			string temp;
			getline(fin, temp);
			credentials.push_back(temp);
		}
		fin.close();
		int size = credentials.size();
		passwords = new char* [size];
		usernames = new  char* [size];
		for (int j = 0; j < size; j++)
		{
			usernames[j] = new char[4];
		}
		for (int j = 0; j < size; j++)
		{
			passwords[j] = new char[14];
		}
		for (int i = 0; i < size; i++)
		{
			int j = 0;
			for (; credentials[i][j] != ','; j++)
			{
				usernames[i][j] = credentials[i][j];
			}
			usernames[i][j] = '\0';
		}

		for (int i = 0; i < size; i++)
		{
			int j = 5;
			int k = 0;
			for (; k < 13; j++, k++)
			{
				passwords[i][k] = credentials[i][j];
			}
			passwords[i][k] = '\0';
		}
		bool user = false;
		bool pass = false;
		for (int i = 0; i < size; i++)
		{
			if (username == usernames[i])
			{
				user = true;
				break;
			}
		}
		for (int i = 0; i < size; i++)
		{
			if (password == passwords[i])
			{
				pass = true;
				break;
			}
		}

		if (user && pass)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
char Main_menu()
{
	char choice;
	while (1)
	{
		cout << "=======================================================================" << endl;
		cout << "|                          Main Menu                                  |" << endl;
		cout << "=======================================================================" << endl;
		cout << "|   =>Press 1 to login as Customer                                    |\n";
		cout << "|                                                                     |" << endl;
		cout << "|   =>Press 2 to login as Employee                                    |\n";
		cout << "|                                                                     |" << endl;
		cout << "|   =>Press 3 to Exit the Software                                    |\n";
		for (int i = 0; i < 2; i++)
			cout << "|                                                                     |" << endl;
		cout << "=======================================================================" << endl;
		choice = _getche();
		if (choice == '1' || choice == '2' || choice == '3')
		{
			break;
		}
		else
		{
			system("CLS");
			continue;
		}
	}
	return choice;
}
void Employee()
{
	string u, p;
	cout << "User name:";
	getline(cin, u);
	cout << endl;
	cout << "Password:";
	getline(cin, p);
	employee e(u, p);
	while (1)
	{
		bool check = e.login();
		if (check)
		{
			char c;
			system("CLS");
			cout << "=======================================================================" << endl;
			cout << "|                         Employee                                     |" << endl;
			cout << "=======================================================================" << endl;
			cout << "|  Press 1 to Change Password                                          |\n";
			cout << "|                                                                     ,|" << endl;
			cout << "|  Press 2 to edit Tax Tarif file                                      |\n";
			cout << "|                                                                      |" << endl;
			cout << "|  Press 3 to edit or add new customer                                 |\n";
			cout << "|                                                                      |" << endl;
			cout << "|  Press 0 to return Main menu                                         |\n";
			cout << "=======================================================================" << endl;
			c = _getch();
			if (c == '1')
			{
				system("CLS");
				e.password_change();
				system("CLS");
			}
			if (c == '2')
			{
				system("CLS");
				e.tax_tarif_file_updation();
				system("CLS");

			}
			if (c == '3')
			{
				system("CLS");
				UpdateCustomer e1;
				e1.UpdateCustomerMain();
				system("CLS");

			}
			if (c == '0')
			{
				e.empty();
				system("CLS");
				return;
			}

		}
		else
		{
			system("CLS");
			char c;
			cout << "Wrong Credentials...\n";
			cout << "Press 1 to try again\n";
			cout << "Press 2 to go back to main menu\n";
		     c = _getch();
			 if (c == '2')
			 {
				 system("CLS");
				 return;
			 }
			 if (c == '1')
			 {
				 continue;
			 }
		}
	}
}
void Customer()
{
	customer c;
	while (1)
	{
		string username;
		string password;
		cout << "Enter the username(Unique 4-digit)\n";
		getline(cin, username);
		cout << "Enter the Password(Cnic)\n";
		getline(cin, password);
		bool check = c.cutomer_login(username,password);
		if (check)
		{
			char c;
			system("CLS");
			cout << "=======================================================================" << endl;
			cout << "|                         Cutomer                                      |" << endl;
			cout << "=======================================================================" << endl;
			cout << "|   Press 1 to view bill                                               |\n";
			cout << "|                                                                     ,|" << endl;
			cout << "|                                                                      |\n";
			cout << "|                                                                      |" << endl;
			cout << "|  Press 0 to return Main menu                                         |\n";
			cout << "=======================================================================" << endl;
			c = _getch();
			if (c == '0')
			{
				system("CLS");
				return;
			}
			if (c == '1')
			{

			}

		}
		else
		{
			system("CLS");
			char c;
			cout << "Wrong Credentials...\n";
			cout << "Press 1 to try again\n";
			cout << "Press 2 to go back to main menu\n";
			c = _getch();
			if (c == '2')
			{
				system("CLS");
				return;
			}
			if (c == '1')
			{
				continue;
			}
		}
	}


}
int main()
{
	while (1)
	{
		char choice = Main_menu();
		system("CLS");
		if (choice == '2')
		{
			Employee();
		}
		if (choice == '1')
		{
			Customer();
		}
		if (choice == '3')
		{
			break;
		}
	}
	return 0;
}
