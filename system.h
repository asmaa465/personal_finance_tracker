//
// Created by Ts on 28/08/2024.
//

#ifndef PERSONNAL_FINANCE_TRACKER_SYSTEM_H
#define PERSONNAL_FINANCE_TRACKER_SYSTEM_H
#include <iostream>
using namespace std;
#include <vector>
class Money{
public:
    virtual void add(int money)=0;
    virtual void view()=0;
    virtual ~Money()=default;
};

class income:public Money{
    vector<int>money;
public:
    void add(int money1) override;
    void view() override;
    vector<int>& getmoney();
};
class expenses:public Money{
    vector<int>expenses;
public:
    void add(int money1) override;
    void view() override;
    vector<int>& getexpenses();
};
enum  category{
    savings,
    education,
    housing,
    groceries
};
class budgets:public Money{
    vector<pair<int,category>>budget;
public:
    void add(int money1) override ;
    void add(int money1,category cat);
    void view() override;
    vector<pair<int,category>>& getbudget();
};

class Edit{
public:
    virtual void edit( int oldAmount, int newAmount)=0;
    virtual ~Edit()=default;
};
class EditOnIncome :public Edit {
    income &in;
public:
    EditOnIncome(income &in);
    void edit(int oldAmount, int newAmount);
};
class EditOnExpenses : public Edit {
    expenses& ex;
public:
    EditOnExpenses(expenses& ex);
    void edit( int oldAmount, int newAmount);
};

class user{
    string name;
    int id;
    income my_income;
    expenses my_expenses;
    budgets my_budgets;
    vector<string>messages;
public:
    user();
    user(const string &name ,const int & id );

    void setIncome(const income& newIncome) ;

    void setExpenses(const expenses& newExpenses) ;

    void setBudgets(const budgets& newBudgets) ;
    income& getIncome() ;

    expenses& getExpenses();

    budgets& getBudgets();
    void addmessage(string str);
    void viewmessages();
};
class transcations{
    user& us;
    income& in;
    expenses& ex;
public:
    transcations(user&us);
    void editincome(int oldAmount, int newAmount);
    void editexpenses(int oldAmount, int newAmount);
    void addincome(int money1);
    void addexpenses(int money1);
};
class notify{
    string message;
    vector<user*>users;
public:
    notify(const string& news);
    void adduser(user& user1);
     void addmessage();
};
class tracker{
    user user1;
public:
    tracker(user&user1);
    void view();
    void view_notifications();

};
#endif //PERSONNAL_FINANCE_TRACKER_SYSTEM_H
