#include <iostream>
#include <random>
#include <ctime>
using namespace std;




class BranchFinances {
public:
	const double rentcost = 50; //базовая аренда
	const double overflowpercent = 0.07; //процент за сверх доход
	const double overflowincome = 270; //порог дохода
	const double paycheck = 35; //зарплата продавцу
	const double services = 15; //услуги
	double income; //доход


	BranchFinances() {
		getIncome();
	}
	~BranchFinances(){}


	double getFinalRentCost() { //окончательная стоимость аренды
		if (income <= overflowincome) 	return rentcost;
		else return rentcost + (income - overflowincome) * overflowpercent;
	}

	double getExpenses() { //все затраты
		return paycheck + services + getFinalRentCost();
	}

	void getInfo() { //отчёт
		cout << "Полученные деньги с продаж: " << income << ";\n\n";
		cout << "Зарплата кассиру: " << paycheck << ",   Стоимость аренды: " << getFinalRentCost() << ",   Услуги мракоборцев: " << services << ",\nИтоговые затраты: " << getExpenses() << ";\n\n";
		cout << "Итоговая выручка: " << getFinalRevenue() << endl;
	}

	void getIncome() { //полученные деньги с продаж
		income = rand() % 251 + 250;
	}

	double getFinalRevenue() { //окончательная чистая прибыль
		return income - getExpenses();
	}
};



class NewBranch : public BranchFinances {
private: 
	string branchname;
public:
	NewBranch(string& name) : branchname(name){}
	~NewBranch() {
		cout << "\n\n\nПриятных продаж!";
	}
};



int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	string name;
	cin >> name;
	NewBranch* sus = new NewBranch(name);
	sus->getInfo();
	delete sus;
}