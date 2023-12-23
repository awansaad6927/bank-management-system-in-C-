// ConsoleApplication6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include <random>
#include <cstdlib>
using namespace std;

class diamond {
public:
    void d()
    {

        system("color 0c");
        for (int i = 1; i < 18; i++)
        {
            for (int j = 1; j <= 20 - i; j++)
            {
                cout << setw(3) << " ";
            }
            for (int k = 1; k <= 2 * i - 1; k++) {

                cout << setw(3) << "*";

            }
            cout << endl;
        }
        cout << "\t-------------------------------------------------------------------------------------------------------" << endl;
        for (int i = 18; i >= 1; i--)
        {

            for (int j = 1; j <= 20 - i; j++)
            {
                cout << setw(3) << " ";
            }
            for (int k = 1; k <= 2 * i - 1; k++) {
                cout << setw(3) << "*";

            }
            cout << endl;
        }
    }

};
struct Bank
{
    string namee;
    string cnic;
    string input;
    string email;
    int connum; // contact number
    int amount = 0;
    int creditno;
    int password;

    int pass() {
        srand(time(NULL));
        int pass = rand() % 10000 + 1000;
        return pass;
    }

    long credit(int n) {
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<> distribution(0, 9);  // Generate digits 0-9

        long  number = 0;
        for (int i = 0; i < n; ++i) {
            number = number * 10 + distribution(generator);  // Append digit
        }

        return number;
    }
    int m() {
        int base = credit(15);  // Generate 15-digit base number (excluding check digit)
        int sum = 0;
        bool alternate = false;

        for (int i = base; i > 0; i /= 10) {
            int digit = i % 10;

            if (alternate) {
                digit *= 2;
                if (digit > 9) {
                    digit -= 9;  // Handle double-digit overflow
                }
            }

            sum += digit;
            alternate = !alternate;
        }

        int check = (10 - (sum % 10)) % 10;  // Calculate check digit
        base = base * 10 + check;  // Append check digit
        if (base < 0) {
            cout << -base << endl;
        }
        else {



            // Print the complete Luhn number
            return base;
        }

    }


    void info()
    {
        cout << endl;
        cout << "\t\t\t\t\tEnter your good name = ";
        getline(cin, namee);
        cout << endl;
        cout << "\t\t\t\t\tEnter your CNIC = ";
        getline(cin, cnic);
        cout << endl;
        cout << "\t\t\t\t\tEnter your Email = ";
        getline(cin, email);
        cout << endl;
        cout << "\t\t\t\t\tEnter your Contact number = ";
        cin >> connum;
        cout << endl;
        cout << "\t\t\t\t\tYour credit card number is = ";

        creditno = m();
        cout << creditno << endl;
        cout << "\t\t\t\t\t You Password is = ";
        password = pass();
        cout << password << endl;

    }

    void menu()
    {
        diamond d;
        d.d();




        Sleep(4000);
        system("cls");
        system("color 1f");
        cout << endl;
        cout << " \t\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU TRANSACTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    t:   cout << "\n\n\t\t\t\t\t [ 1 ] Create Account";
        cout << "\n\t\t\t\t\t [ 2 ] Deposit" << endl;
        cout << "\t\t\t\t\t [ 3 ] Withdraw" << endl;
        cout << "\t\t\t\t\t [ 4 ] Check Balance" << endl;
        cout << "\t\t\t\t\t [ 5 ] Update Record" << endl;
        cout << "\t\t\t\t\t [ 6 ] Delete Record" << endl;
        cout << "\t\t\t\t\t [ 7 ] Search Record" << endl;
        cout << "\t\t\t\t\t [ 8 ] Exit ATM" << endl;
        cout << "\t\t\t\t\t _____________________________________________" << endl;
        cout << "\t\t\t\t\t Enter your choice: ";
    }
    void clearMenu()
    {
        system("Pause");
        system("Cls");
        menu();
    }
    void display()
    {
        cout << "\t\t\t\t\tYour name is " << namee << endl;
        cout << "\t\t\t\t\tYour CNIC is " << cnic << endl;
        cout << "\t\t\t\t\tYour EMAIL is " << email << endl;
        cout << "\t\t\t\t\tYour Contact Number is " << connum << endl;
        cout << "\t\t\t\t\tYour Current Amount is " << amount << endl;
        cout << "\t\t\t\t\tYour credit card number is = " << creditno << endl;
    }
};

int main()
{
    Bank b;
    int key;

    b.menu();
    do
    {
        cin >> key;
        cin.ignore();

        if (key == 1) // account create
        {
            b.info();
            fstream B("Bank.txt", ios::app | ios::in | ios::out);
            B.write((char*)&b, sizeof(b));
            B.close();
            Sleep(2000);
            b.clearMenu();
        }
        else if (key == 2) // deposit
        {
            int p;
            int am = 0;
            int flag = 0;

            cout << "\t\t\t\t\tEnter Your Password =  ";
            cin >> p;

            fstream u("Bank.txt", ios::in | ios::out | ios::app);
            fstream temp("Bank1.txt", ios::app | ios::out | ios::in);

            while (u.read((char*)&b, sizeof(b)))
            {
                if (p == b.password)
                {
                    cout << "\t\t\t\t\tName of Account holder is = " << b.namee << endl;
                    cout << "\t\t\t\t\tYour Current Amount is = " << b.amount << endl;

                    cout << "\t\t\t\t\tEnter new amount: ";
                    cin >> am;
                    b.amount += am;

                    cout << "\t\t\t\t\tName of Account holder is = " << b.namee << endl;
                    cout << "\t\t\t\t\tYour Current Amount is = " << b.amount << endl;

                    temp.write((char*)&b, sizeof(b));
                    flag++;
                }
                else
                {
                    temp.write((char*)&b, sizeof(b));
                }
            }

            u.close();
            temp.close();

            remove("Bank.txt");
            rename("Bank1.txt", "Bank.txt");

            if (flag == 0)
            {
                cout << "\t\t\t\t\tNo record found. Please re-enter.\n";
            }

            Sleep(2000);
            b.clearMenu();
        }

        else if (key == 3) // withdraw
        {
            int p;
            int am = 0;
            int flag = 0;
            cout << "\t\t\t\t\tEnter Your Password =  ";
            cin >> p;

            fstream u("Bank.txt");
            fstream temp("Bank1.txt", ios::app | ios::out);

            while (u.read((char*)&b, sizeof(b)))
            {
                if (p == b.password)
                {
                    cout << "\t\t\t\t\tName of Account holder is = " << b.namee << endl;
                    cout << "\t\t\t\t\tYour Current Amount is = " << b.amount << endl;

                    do
                    {
                        cout << "\t\t\t\t\tEnter Withdraw Amount: ";
                        cin >> am;
                        if (am > b.amount)
                        {
                            cerr << "\t\t\t\t\tError: Amount withdrawn is more than the current amount. Try again.\n";
                        }
                    } while (am > b.amount);

                    b.amount -= am;
                    cout << endl;
                    cout << "\t\t\t\t\tName of Account holder is = " << b.namee << endl;
                    cout << "\t\t\t\t\tYour Current Amount is = " << b.amount << endl;

                    temp.write((char*)&b, sizeof(b));
                    flag++;
                }
                else
                {
                    temp.write((char*)&b, sizeof(b));
                }
            }

            u.close();
            temp.close();

            remove("Bank.txt");
            rename("Bank1.txt", "Bank.txt");

            if (flag == 0)
            {
                cout << "\t\t\t\t\tNo record found. Please re-enter.\n";
            }

            Sleep(2000);
            b.clearMenu();
        }

        else if (key == 4) // check balance
        {
            int p;
            int flag = 0;
            cout << "\t\t\t\t\tEnter Your Password = ";
            cin >> p;
            fstream u("Bank.txt", ios::app | ios::in | ios::out);
            while (u.read((char*)&b, sizeof(b)))
            {
                if (p == b.password)
                {
                    b.display();
                    flag++;
                }
            }
            u.close();
            if (flag == 0)
            {
                cout << "\t\t\t\t\tNo record found. Please re-enter.\n";
            }
            Sleep(2000);
            b.clearMenu();
        }
        else if (key == 5) // update
        {
            int p;
            int flag = 0;
            char k, m = '/1';
            cout << "\t\t\t\t\tEnter Your Password = ";
            cin >> p;
            fstream u("Bank.txt");
            fstream temp("Bank1.txt", ios::app | ios::out);
            while (u.read((char*)&b, sizeof(b)))
            {
                if (p == b.password)
                {
                    b.display();
                    cout << endl;
                    cout << "\t\t\t\t\t======================================== " << endl;
                z:;
                    cout << "\t\t\t\t\tTo Update First Name . please (press f) " << endl;
                    cout << "\t\t\t\t\tTo Update CNIC. please (press c)" << endl;
                    cout << "\t\t\t\t\tTo Update EMAIL . please (press e)" << endl;
                    cout << "\t\t\t\t\tTo Update Contact Number  . please (press n) " << endl;

                    cin >> k;
                    if (k == 'f')
                    {
                        cout << "\t\t\t\t\tEnter your new name = ";
                        cin >> b.namee;
                        cout << "\t\t\t\t\tName of Account holder is " << b.namee;
                    }
                    else if (k == 'c')
                    {
                        cout << "\t\t\t\t\tEnter your new CNIC = ";
                        cin >> b.cnic;
                        cout << "\t\t\t\t\tYour New Cnic is = " << b.cnic;
                    }
                    else if (k == 'e')
                    {
                        cout << "\t\t\t\t\tEnter your new EMAIL = ";
                        cin >> b.email;
                        cout << "\t\t\t\t\tYour New Email is = " << b.email;
                    }
                    else if (k == 'n')
                    {
                        cout << "\t\t\t\t\tEnter your new phone number = ";
                        cin >> b.connum;
                        cout << "\t\t\t\t\tYour new Phone Number is = " << b.connum;
                    }
                    temp.write((char*)&b, sizeof(b));
                    flag++;
                }
                else
                {
                    temp.write((char*)&b, sizeof(b));
                }
            }
            u.close();
            temp.close();
            remove("Bank.txt");
            rename("Bank1.txt", "Bank.txt");
            if (flag == 0)
            {
                cout << "\t\t\t\t\tNo record found. Please re-enter.\n";
            }
            Sleep(2000);
            b.clearMenu();
        }
        else if (key == 6) // delete record
        {

            string nam;
            int p;
            int am = 0;
            int flag = 0;
            char confirm;
            cout << "\t\t\t\t\tEnter Your First Name: ";
            getline(cin, nam);
            cout << "\t\t\t\t\tEnter Your Password: ";
            cin >> p;
            fstream u("Bank.txt", ios::in);
            fstream temp("Bank1.txt", ios::app | ios::out);

            while (u.read((char*)&b, sizeof(b)))
            {
                if (p == b.password)
                {
                    cout << "\t\t\t\t\tName of Account holder is = " << b.namee << endl;
                    cout << "\t\t\t\t\tYour Current Amount is = " << b.amount << endl;

                    cout << "\t\t\t\t\tDo You Wish to Delete Your Account (Y/N)";
                    cin >> confirm;
                    if (key == 'Y' || key == 'y') {
                        cout << "\t\t\t\t\tRecords Deleted Successfully";
                        continue;
                        fstream u("Bank1.txt", ios::app | ios::out);

                        while (u.read((char*)&b, sizeof(b))) {
                            if (nam != b.namee)
                            {
                                temp.write((char*)&b, sizeof(b));
                            }

                        }
                        cout << "\t\t\t\t\tRecords Deleted Successfully";
                    }

                    temp.close();
                    flag++;
                }
                else
                {
                    temp.write((char*)&b, sizeof(b));
                }
            }

            u.close();
            temp.close();

            remove("Bank.txt");
            rename("Bank1.txt", "Bank.txt");



            Sleep(2000);
            b.clearMenu();
        }
        else if (key == 7)//Search record
        {
            int p;
            string nam;
            int flag = 0;

            cout << "\t\t\t\t\tEnter Your Password = ";
            cin >> p;
            fstream u("Bank.txt", ios::app | ios::in | ios::out);
            while (u.read((char*)&b, sizeof(b)))
            {
                if (p == b.password)
                {
                    b.display();

                }
                else {
                    system("color 0c");
                    cout << "\t\t\t\t\t!!!!!NO RECORDS FOUND!!!!!\n";
                }
            }
            u.close();

            Sleep(2000);
            b.clearMenu();
        }
        else if (key == 8)//exiting the bank
        {
            cout << endl;
            cout << " \t\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 THANK YOU FOR VISITING OUR BANK \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
            cout << endl;
            cout << "\t\t\t\t\t";

            system("Pause");
            exit(0);
        }
    } while (key != 9 && key != 0);








    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
