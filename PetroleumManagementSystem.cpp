// date : 1-08-2021
// program : petroleum management system
// author : Priyanshi Agrawal
// co-author : Atharv Vani
#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
class Petroleum
{
private:
    float current_petrol_price, current_diesel_price;                    //current price
    double capacity_petrol = 20000, capacity_diesel = 20000;             //total capacity
    double refill_petrol_amt, refill_diesel_amt;                         // rs for rifill
    double refill_petrol_volume, refill_diesel_volume;                   //liters from rifill amt
    double total_petrol_refilled = 0, total_diesel_refilled = 0;         //total liters
    double total_petrol_refilled_amt = 0, total_diesel_refilled_amt = 0; //total earn
    ;

public:
    Petroleum() //constructor takes current petroleum price as input
    {
        cout << "enter current petrol price : ";
        cin >> current_petrol_price;
        cout << "enter current diesel price : ";
        cin >> current_diesel_price;
    }
    void menu()
    {
        cout << endl;
        cout << "Today's Price : PETROL = " << current_petrol_price << "rs/liter ||  DIESEL = " << current_diesel_price << "rs/liter" << endl;
        cout << "1-> for refilling Petrol" << endl;
        cout << "2-> for refilling Diesel" << endl;
        cout << "3-> show Pump management information" << endl;
        cout << "4-> to Delete data" << endl;
        cout << "5-> to Exit program" << endl;
    }
    void refilling_petrol() //case 1
    {
        cout << "\nenter amount(rs) to be refilled : ";
        cin >> refill_petrol_amt;
        refill_petrol_volume = refill_petrol_amt / current_petrol_price;
        cout << "RS : " << refill_petrol_amt << " and LITERS : " << refill_petrol_volume << endl;
        total_petrol_refilled += refill_petrol_volume;
        total_petrol_refilled_amt += refill_petrol_amt;
    }
    void refilling_diesel() // case 2
    {
        cout << "\nenter amount(rs) to be refilled : ";
        cin >> refill_diesel_amt;
        refill_diesel_volume = refill_diesel_amt / current_diesel_price;
        cout << "RS : " << refill_diesel_amt << "and  LITERS : " << refill_diesel_volume << endl;
        total_diesel_refilled += refill_diesel_volume;
        total_diesel_refilled_amt += refill_diesel_amt;
    }
    void show_details()
    {
        cout << "\n................................................................................\n";
        cout << "PETROLEUM MANAGEMENT DETAILS ~" << endl;
        cout << endl
             << "Petrol Details : " << endl;
        cout << "Total liters of Petrol dispatched : " << total_petrol_refilled << endl;
        cout << "Liter left in tank : " << capacity_petrol - total_petrol_refilled << endl;
        cout << "Total amount earned : " << total_petrol_refilled_amt << endl;

        cout << endl
             << "Diesel Details : " << endl;
        cout << "Total liters of Diesel dispatched : " << total_diesel_refilled << endl;
        cout << "Liter left in tank : " << capacity_diesel - total_diesel_refilled << endl;
        cout << "Total amount earned : " << total_diesel_refilled_amt << endl;

        cout << "\nTOTAL MONEY(rs) : " << total_diesel_refilled_amt + total_petrol_refilled_amt << endl;
        cout << "................................................................................\n";
    }
    void delete_details()
    {
        refill_petrol_amt = 0, refill_diesel_amt = 0;                 // rs for rifill
        refill_petrol_volume = 0, refill_diesel_volume = 0;           //liters from rifill amt
        total_petrol_refilled = 0, total_diesel_refilled = 0;         //total liters
        total_petrol_refilled_amt = 0, total_diesel_refilled_amt = 0; //total earn
    }
};
int main()
{
    Petroleum poj;
    cout<<"Hit enter to continue\n";
    getch();
    system("cls");
    while (1)
    {
        char option;
        poj.menu();
        cout << "Please select operation to be performed : ";
        cin >> option;
        switch (option)
        {
        case '1':
            poj.refilling_petrol();


            break;
        case '2':
            poj.refilling_diesel();
            break;
        case '3':
            poj.show_details();
            break;
        case '4':
            char confirm_delete;
            cout << "\nAre you sure you want to DELETE data. If yes press y/Y : ";
            getchar();
            cin >> confirm_delete;
            if (confirm_delete == 'y' || confirm_delete == 'Y')
                poj.delete_details();
            break;
        case '5':
            char confirm_exit;
            cout << "\nAre you sure you want to EXIT program. If yes press y/Y : ";
            getchar();
            cin >> confirm_exit;
            if (confirm_exit == 'y' || confirm_exit == 'Y')
                exit(0);
            break;

        default:
            cout << "\n************Please enter valid option...ThankYou***********\n";
            break;
        }
        getchar();
    }

    return 0;
}
