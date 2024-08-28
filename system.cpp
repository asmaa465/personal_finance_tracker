//
// Created by Ts on 28/08/2024.
//
#include <iostream>
using namespace std;
#include <vector>
#include "system.h"



     void income:: add(int money1) {
        money.push_back(money1);
    }
    void income::view() {
        for(const auto&it:money){
            cout<<it<<endl;
        }
    }
    vector<int>& income::getmoney(){
        return money;
    }


    void expenses::add(int money1) {
        expenses.push_back(money1);
    }
    void expenses:: view(){
        for(const auto&it:expenses){
            cout<<it<<endl;
        }
    }
    vector<int>& expenses:: getexpenses(){
        return expenses;
    }


    void budgets::add(int money1)  {
        budget.push_back({money1,category::groceries});
    }
    void budgets:: add(int money1,category cat){
        budget.push_back({money1,cat});
    }
    void budgets::view() {
        for(const auto&it:budget){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
    vector<pair<int,category>>& budgets:: getbudget(){
        return budget;
    }



    EditOnIncome::EditOnIncome(income& in) : in(in) {};
    void EditOnIncome::edit( int oldAmount, int newAmount)  {
        bool editsatus=false;
        auto& money=in.getmoney();//
        for(auto &it : money){
            if(it==oldAmount){
                it = newAmount;
                editsatus=true;
                break;
            }
        }
        if(editsatus==false){
            cout<<"there is no amount like that"<<endl;
        }
    }


    EditOnExpenses::EditOnExpenses(expenses& ex) : ex(ex) {};
    void EditOnExpenses::edit( int oldAmount, int newAmount)  {
        bool editsatus=false;
        auto& expense=ex.getexpenses();
        for(auto &it : expense){
            if(it==oldAmount){
                it = newAmount;
                editsatus=true;
                break;
            }
        }
        if(editsatus==false){
            cout<<"there is no amount like that"<<endl;
        }
    }



    user::user(){};
    user:: user(const string &name ,const int & id ){
        this->name=name;
        this->id=id;
    }

    void user::setIncome(const income& newIncome) {
        my_income = newIncome;
    }

    void user::setExpenses(const expenses& newExpenses) {
        my_expenses = newExpenses;
    }

    void user:: setBudgets(const budgets& newBudgets) {
        my_budgets = newBudgets;
    }
    income& user::getIncome() {
        return my_income;
    }

    expenses& user:: getExpenses() {
        return my_expenses;
    }

    budgets& user::getBudgets() {
        return my_budgets;
    }
    void user:: addmessage(string str){
        messages.push_back(str);
    }
    void user::viewmessages(){
        for(auto&it:messages){
            cout<<it<<endl;
        }
    }

   transcations::transcations(user& us):us(us) ,ex(us.getExpenses()),in(us.getIncome()){};
    void transcations::editincome(int oldAmount, int newAmount){
        EditOnIncome ed(in);
        ed.edit(oldAmount,newAmount);
    }
    void transcations::editexpenses(int oldAmount, int newAmount){
        EditOnExpenses ed(ex);
        ed.edit(oldAmount,newAmount);
    }
    void transcations::addincome(int money1){
        //income in;
        in.add(money1);
    }
    void transcations::addexpenses(int money1){

        ex.add(money1);
    }


    notify::notify(const string& news){
        message=news;
    }
    void notify::adduser(user& user1){
        users.push_back(&user1);
    }

void notify::addmessage() {
    for(auto&it:users){
        it->addmessage(message);
    }
}



   tracker:: tracker(user&user1){
        this->user1=user1;
    }
    void tracker::tracker:: view(){
        cout<<"income:"<<endl;
        user1.getIncome().view();
        cout<<"----------"<<endl;
        cout<<"expenses:"<<endl;
        user1.getExpenses().view();
        cout<<"----------"<<endl;
        cout<<"budgets:"<<endl;
        user1.getBudgets().view();
    }
    void tracker:: tracker::view_notifications(){
        user1.viewmessages();
    }

