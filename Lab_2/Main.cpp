#include <iostream>
#include <string>
//#include "List_Sequence.h"
//#include "ArraySequence.h"
#include "MyClass.h"

int interface() {

	std::cout << "What type of data do you want to work with? \n";
	std::cout << "Choose type of the list:\n1. int\n2. double\n3. string\n";
	int type;
	do {
		std::cin >> type; //std::cout << "\n";
		if ((type != 1) && (type != 2) && (type != 3))
		{
			std::cout << ("You must choose 1 or 2 or 3\n");
		}
	} while ((type != 1) && (type != 2) && (type != 3));
	

	//создание массива
	MyClass<int>* mas1;
	mas1 = new MyClass<int>();
	MyClass<double>* mas2;
	mas2 = new MyClass<double>();
	MyClass<std::string>* mas3;
	mas3 = new MyClass<std::string>();

	MyClass<int>* con1;
	con1 = new MyClass<int>();
	MyClass<double>* con2;
	con2 = new MyClass<double>();
	MyClass<std::string>* con3;
	con3 = new MyClass<std::string>();

	MyClass<int>* search1;
	search1 = new MyClass<int>();
	MyClass<double>* search2;
	search2 = new MyClass<double>();
	MyClass<std::string>* search3;
	search3 = new MyClass<std::string>();

	switch (type)
	{
	case 1:
		mas1->Enter();
		break;
	case 2:
		mas2->Enter();
		break;
	case 3:
		mas3->Enter();
		break;
	default: printf("ERROR. You need choose an action.");
		break;
	}

	switch (type)
	{
	case 1:

		delete[] mas2;
		delete[] mas3;
		break;
	case 2:
		delete[] mas1;
		delete[] mas3;
		break;
	case 3:
		delete[] mas2;
		delete[] mas1;
		break;
	default: printf("ERROR");
		break;
	}
	
	//выбор функции
	int choice = 0;
	
	std::cout << " Choose the operation:\n"
		"1. Print array \n"
		"2. Get Length\n"
		"3. Concatination\n"
		"4. Search\n"
		"5. Get\n"
		"6. Get First\n"
		"7. Get Last\n"
		"8. Append\n"
		"9. Prepend\n"
		"10. InsertAt\n"
		"11. exit\n";

	
	do {
		std::cout << "\nYour choice: ";
	std::cin >> choice; std::cout << "\n";

	int ap1(0);
	double ap2(0);
	std::string ap3("");
	int index(0),startIndex(0),endIndex(0);
	
		switch (choice) {
		case 1:
			if (type == 1) mas1->Print();
			if (type == 2) mas2->Print();
			if (type == 3) mas3->Print();
			break;
		case 2:
			if (type == 1) { std::cout << mas1->GetLength() << "\n"; }
			if (type == 2) { std::cout << mas2->GetLength() << "\n"; }
			if (type == 3) { std::cout << mas3->GetLength() << "\n"; }
			break;
		case 3:
			std::cout << "Enter new list: ";

			if (type == 1) { con1->Enter(); (mas1->Concat(con1))->Print(); }
			if (type == 2) { con2->Enter(); (mas2->Concat(con2))->Print(); }
			if (type == 3) { con3->Enter(); (mas3->Concat(con3))->Print(); }
			break;
		case 4:
			std::cout << "Enter piece of list: ";

			if (type == 1) { std::cin >> ap1; search1->Prepend(ap1); std::cout << mas1->Search(search1) << "\n"; }
			if (type == 2) { std::cin >> ap2; search2->Prepend(ap2); std::cout << mas2->Search(search2) << "\n"; }
			if (type == 3) { std::cin >> ap3; search3->Prepend(ap3); std::cout << mas3->Search(search3) << "\n"; }
			break;
		case 5:
			std::cout << "Enter index: ";
			std::cin >> index;

			if (type == 1) { std::cout << mas1->Get(index)<<"\n"; }
			if (type == 2) { std::cout << mas2->Get(index) << "\n"; }
			if (type == 3) { std::cout << mas3->Get(index) << "\n"; }
			break;
		case 6:
			if (type == 1) { std::cout << mas1->GetFirst() << "\n"; }
			if (type == 2) { std::cout << mas2->GetFirst() << "\n"; }
			if (type == 3) { std::cout << mas3->GetFirst() << "\n"; }
			break;
		case 7:
			if (type == 1) { std::cout << mas1->GetLast() << "\n"; }
			if (type == 2) { std::cout << mas2->GetLast() << "\n"; }
			if (type == 3) { std::cout << mas3->GetLast() << "\n"; }
			break;
		case 8:
			std::cout << "Enter element: ";

			if (type == 1) { std::cin >> ap1; mas1->Append(ap1); }
			if (type == 2) { std::cin >> ap2; mas2->Append(ap2); }
			if (type == 3) { std::cin >> ap3; mas3->Append(ap3); }
			break;
		case 9:
			std::cout << "Enter element: ";

			if (type == 1) { std::cin >> ap1; mas1->Prepend(ap1); }
			if (type == 2) { std::cin >> ap2; mas2->Prepend(ap2); }
			if (type == 3) { std::cin >> ap3; mas3->Prepend(ap3); }
			break;
		case 10:
			std::cout << "Enter index: ";
			std::cin >> index;
			std::cout << "Enter new element: ";
			
			if (type == 1) { std::cin >> ap1; mas1->InsertAt(ap1,index); }
			if (type == 2) { std::cin >> ap2; mas2->InsertAt(ap2, index); }
			if (type == 3) { std::cin >> ap3; mas3->InsertAt(ap3, index); }
			break;
		case 11:
			std::cout << "Good job";
			break;
		default: std::cout << "ERROR. You need choose an action.";
		}
	} while (choice!=11);

	switch (type)
	{
	case 1:
		delete mas1;
		break;
	case 2:
		delete mas2;
		break;
	case 3:
		delete mas3;
		break;
	default: printf("ERROR");
		break;
	}

	delete con1;
	delete con2;
	delete con3;
	delete search1;
	delete search2;
	delete search3;

	return 0;
}


int main() {
	//Test_List_Sequence();
	//Test_Array_Sequence();
	//Test_MyClass();
	interface();
	
	return 0;
}

