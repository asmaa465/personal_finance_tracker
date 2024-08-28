#include <iostream>
using namespace std;
#include <vector>
#include "system.h"

void showMenu() {
    cout << "Menu:" << endl;
    cout << "1. View Income" << endl;
    cout << "2. View Expenses" << endl;
    cout << "3. View Budgets" << endl;
    cout << "4. Add Income" << endl;
    cout << "5. Add Expenses" << endl;
    cout << "6. Edit Income" << endl;
    cout << "7. Edit Expenses" << endl;
    cout << "8. View Notifications" << endl;
    cout << "9. Exit" << endl;
    cout << "Choose an option: ";
}

void do_op(int option,user&us,transcations&trans){
    switch(option) {
        case 1:
            us.getIncome().view();
            break;
        case 2:
            us.getExpenses().view();
            break;
        case 3:
            us.getBudgets().view();
            break;
        case 4: {
            int amount;
            cout << "Enter amount to add to income: ";
            cin >> amount;
            trans.addincome(amount);
            break;
        }
        case 5: {
            int amount;
            cout << "Enter amount to add to expenses: ";
            cin >> amount;
            trans.addexpenses(amount);
            break;
        }
        case 6: {
            int oldAmount, newAmount;
            cout << "Enter old income amount: ";
            cin >> oldAmount;
            cout << "Enter new income amount: ";
            cin >> newAmount;
            trans.editincome(oldAmount, newAmount);
            break;
        }
        case 7: {
            int oldAmount, newAmount;
            cout << "Enter old expense amount: ";
            cin >> oldAmount;
            cout << "Enter new expense amount: ";
            cin >> newAmount;
            trans.editexpenses(oldAmount, newAmount);
            break;
        }
        case 8:
            us.viewmessages();
            break;
        case 9:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
    }
};

int main() {
        user us("John",2024);
        transcations trans(us);

        notify notty("check your updated budget");
        notty.adduser(us);
        notty.addmessage();
         int option;
        do{
            showMenu();
            cin>>option;
            do_op(option,us,trans) ;
        }while(option!=9);
    return 0;
}
