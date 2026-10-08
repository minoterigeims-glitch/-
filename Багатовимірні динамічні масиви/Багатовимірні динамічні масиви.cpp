

#include <iostream>
#include <windows.h>
#include <string>


using namespace std;


void transpose(int** arr, int rows, int cols)
{
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << arr[j][i] << "\t";
        }
        cout << endl;
    }
}





int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a;
    do {
        cout << "Введіть номер завдання (1-3)( Вихід = 0). : ";
        cin >> a;
        switch (a) {
        case 1:
        {
            const int rows = 3;
            const int cols = 4;

            int** arr = new int* [rows];

            for (int i = 0; i < rows; i++)
            {
                arr[i] = new int[cols];
            }

            
            int number = 1;

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    arr[i][j] = number++;
                }
            }

            cout << "Початкова матриця:" << endl;

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    cout << arr[i][j] << "\t";
                }
                cout << endl;
            }

            cout << "\nТранспонована матриця:" << endl;

            transpose(arr, rows, cols);

            
            for (int i = 0; i < rows; i++)
            {
                delete[] arr[i];
            }

            delete[] arr;

            return 0;
            break;
        }
        

        case 2:
        {
            int n;

            cout << "Введіть кількість контактів: ";
            cin >> n;
            cin.ignore();

            
            string** contacts = new string * [2];

            for (int i = 0; i < 2; i++) {
                contacts[i] = new string[n];
            }

            
            for (int i = 0; i < n; i++) {
                cout << "\nКонтакт " << i + 1 << endl;

                cout << "Ім'я: ";
                getline(cin, contacts[0][i]);

                cout << "Телефон: ";
                getline(cin, contacts[1][i]);
            }

            int choice;

            do {
                cout << "\n===== МЕНЮ =====\n";
                cout << "1. Показати всі контакти\n";
                cout << "2. Пошук за ім'ям\n";
                cout << "3. Пошук за номером телефону\n";
                cout << "4. Змінити дані контакту\n";
                cout << "0. Вихід\n";
                cout << "Ваш вибір: ";
                cin >> choice;
                cin.ignore();

                if (choice == 1) {
                    cout << "\nСписок контактів:\n";

                    for (int i = 0; i < n; i++) {
                        cout << i + 1 << ". "
                            << contacts[0][i]
                            << " - "
                            << contacts[1][i]
                            << endl;
                    }
                }

                else if (choice == 2) {
                    string name;
                    bool found = false;

                    cout << "Введіть ім'я для пошуку: ";
                    getline(cin, name);

                    for (int i = 0; i < n; i++) {
                        if (contacts[0][i] == name) {
                            cout << "Знайдено: "
                                << contacts[0][i]
                                << " - "
                                << contacts[1][i]
                                << endl;

                            found = true;
                        }
                    }

                    if (!found) {
                        cout << "Контакт не знайдено.\n";
                    }
                }

                else if (choice == 3) {
                    string phone;
                    bool found = false;

                    cout << "Введіть номер телефону: ";
                    getline(cin, phone);

                    for (int i = 0; i < n; i++) {
                        if (contacts[1][i] == phone) {
                            cout << "Знайдено: "
                                << contacts[0][i]
                                << " - "
                                << contacts[1][i]
                                << endl;

                            found = true;
                        }
                    }

                    if (!found) {
                        cout << "Контакт не знайдено.\n";
                    }
                }

                else if (choice == 4) {
                    string name;
                    bool found = false;

                    cout << "Введіть ім'я контакту, який потрібно змінити: ";
                    getline(cin, name);

                    for (int i = 0; i < n; i++) {
                        if (contacts[0][i] == name) {
                            cout << "Нове ім'я: ";
                            getline(cin, contacts[0][i]);

                            cout << "Новий номер телефону: ";
                            getline(cin, contacts[1][i]);

                            cout << "Дані змінено.\n";
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        cout << "Контакт не знайдено.\n";
                    }
                }

            } while (choice != 0);

            
            for (int i = 0; i < 2; i++) {
                delete[] contacts[i];
            }

            delete[] contacts;

            return 0;
        
            break;
        }

        case 0:
            cout << "Вихід з програми." << endl;
            break;

        default:
            cout << "Неправильний вибір!" << endl;
        }

    } while (a != 0);
}