#include "List_Sequence.h"

template <class T>
class MyClass : public LinkedListSequence<T> {
private:
	LinkedListSequence<T>* list;
	//int size = 0;

public:
	MyClass() {
		list = new LinkedListSequence<T>();
	}

	MyClass(T* values, int size) {
		list = new LinkedListSequence<T>(values, size);
	}

	MyClass(MyClass<T> & list2) {
		list = new LinkedListSequence<T>(list2->GetLength());
		for (int i = 0; i < list->GetLength(); i++)
			list->Append(list2->Get(i));
	}

	~MyClass() = default;

	T Get(int index) {
		if (index < 0 || index >= list->GetLength()) throw std::out_of_range(IndexOutOfRange);

		return list->Get(index);
	}

	int GetLength() const {
		return list->GetLength();
	}

	T GetFirst() const {
		if (list->GetLength() == 0) throw std::out_of_range(IndexOutOfRange);

		return list->GetFirst();
	}

	T GetLast() const {
		if (list->GetLength() == 0) throw std::out_of_range(IndexOutOfRange);

		return list->GetLast();
	}

	T Get(int index) const {
		if (index < 0 || index >= list->GetLength()) throw std::out_of_range(IndexOutOfRange);

		return list->Get(index);
	}

	MyClass<T>* Concat(MyClass<T>* list2) {
		MyClass<T>* concatList = new MyClass<T>();
		concatList->list = this->list->Concat(list2->list);
	
		return concatList;
	}

	MyClass<T>* Map(T(*foo) (T)) {
		MyClass<T>* maplist = new MyClass<T>();
		int size = this->GetLength();

		for (size_t i = 0; i < size; i++) {
			maplist->list->Prepend(foo(list->Get(i)));
		}

		return maplist;
	}

	MyClass<T>* Where(bool (*foo)(T)) {
		int size = this->GetLength();

		MyClass<T>* wherelist;
		wherelist = new MyClass<T>();

		for (size_t i = 0; i < size; i++) {
			if (foo(Get(i)) == 1)
			{
				wherelist->list->Prepend(Get(i));
			}
		}

		return wherelist;
	}

	MyClass<T>* GetSubSequence(int startIndex, int endIndex) const {
		if (startIndex < 0 || endIndex < 0 || startIndex >= list->GetLength() || endIndex >= list->GetLength())
			throw std::out_of_range(IndexOutOfRange);

		Sequence<T>* subList = list->GetSubSequence(startIndex, endIndex);
		MyClass<T>* subSequence = new MyClass<T>();

		for (int i = 0; i < subList->GetLength(); i++)
			subSequence->Prepend(subList->Get(i));

		return subSequence; 
	} 

	void Append(T values) {
		return list->Append(values);
	}

	void Prepend(T values) {
		return list->Prepend(values);
	}

	int Search(MyClass<T>* list2){
		if (list2->GetLength() < this->GetLength())
			for (int i = 0; i < this->GetLength() - list2->GetLength() + 1; i++){
				if (this->Get(i) == list2->Get(0)){
					if (this->GetLength() - i + 1 < list2->GetLength()){
						return -1;
					}
					else{
						int temp = 0;
						for (int j = 0; j < list2->GetLength(); j++){
							if ((this->GetSubSequence(i, list2->GetLength() + i - 1))->Get(j) == list2->Get(j)){
								temp++;
							}
							if (temp == list2->GetLength()){
								return i;
							}
						}
					}
				}
				if (i == this->GetLength() - list2->GetLength()){
					return -1;
				}

			}

		return -1;
	}

	void Print() {
		return list->Print();
	}

	void Enter() {
		std::cout << "Enter size: ";
		int count;
		std::cin >> count;

		for (int i = 0; i < count; i++) {
			T data;
			std::cout << "Element " << i << " : ";
			std::cin >> data;
			Prepend(data);
		}

	}

	void InsertAt(T values, int index) {
		if (index < 0 || index >= list->GetLength()) throw std::out_of_range(IndexOutOfRange);

		return list->InsertAt(values, index);
	}
};



bool test_where(std::string str) {
	if (str == "one")
	{
		return 1;
	}
	else return 0;
}
std::string test_map1(std::string str) {
	str = "cat";
	return str;
}
std::string test_map2(std::string str) {
	str = str+str;
	return str;
}

int Test_MyClass() {
	MyClass<std::string>* map1;
	map1 = new MyClass<std::string>();
	MyClass<std::string>* map2;
	map2 = new MyClass<std::string>();
	MyClass<std::string>* map3;
	map3 = new MyClass<std::string>();

	MyClass<std::string>* list1;
	list1 = new MyClass<std::string>();
	list1->Prepend("Hello");
	list1->Prepend("my");
	list1->Prepend("friend.");
	list1->Prepend("How are you?");
	list1->Prepend("Fine");

	MyClass<std::string>* list2;
	MyClass<std::string>* list3;
	list2 = new MyClass<std::string>();
	list3 = new MyClass<std::string>();
	list2->Prepend("one");
	list2->Prepend("two");
	list2->Prepend("three");
	list3->Prepend("four");
	list3->Prepend("five");
	list3->Prepend("six");

	if (list1->GetFirst() == "Hello")
		std::cout << "Test GetFirst: success" << "\n";
	else {
		std::cout << "Test GetFirst: fail" << "\n";
	}; 

	if (list1->GetLast() == "Fine")
		std::cout << "Test GetLast: success" << "\n";
	else {
		std::cout << "Test GetLast: fail" << "\n";
	};

	if (list1->GetLength() == 5)
		std::cout << "Test GetLenght: success" << "\n";
	else {
		std::cout << "Test GetLenght: fail" << "\n";
	};

	if (list1->Get(3) == "How are you?")
		std::cout << "Test Get: success" << "\n";
	else {
		std::cout << "Test Get: fail" << "\n";
	};

	list1->Append("Ohhh");
	if (list1->Get(0) == "Ohhh")
		std::cout << "Test Append: success" << "\n";
	else {
		std::cout << "Test Append: fail" << "\n";
	};

	list1->Prepend("I am too");
	if (list1->Get(6) == "I am too")
		std::cout << "Test Prepend: success" << "\n";
	else {
		std::cout << "Test Prepend: fail" << "\n";
	};

	list1->InsertAt("Best", 3);
	if (list1->Get(3) == "Best")
		std::cout << "Test InsertAt: success" << "\n";
	else {
		std::cout << "Test InsertAt: fail" << "\n";
	};

	MyClass<std::string>* p2 = list2->Concat(list3);
	if (p2->Get(0) =="one" && p2->Get(1) == "two" && p2->Get(2) == "three"
		&& p2->Get(3) == "four" && p2->Get(4) == "five" 
		&& p2->Get(5) == "six")
		std::cout << "Test Concat: success" << "\n";
	else {
		std::cout << "Test Concat: fail" << "\n";
	};

	map1 = list2->Map(test_map1);
	map2 = list3->Map(test_map2);
	if (map1->Get(0)=="cat" && map1->Get(1) == "cat"&& map1->Get(2) == "cat")
		std::cout << "Test Map1: success" << "\n";
	else {
		std::cout << "Test Map1: fail" << "\n";
	};

	if (map2->Get(0) == "fourfour" && map2->Get(1) == "fivefive" && map2->Get(2) == "sixsix")
		std::cout << "Test Map2: success" << "\n";
	else {
		std::cout << "Test Map2: fail" << "\n";
	};

	map3 = list2->Where(test_where);
	if (map3->Get(0) == "one")
		std::cout << "Test Where: success" << "\n";
	else {
		std::cout << "Test Where: fail" << "\n";
	};

	MyClass<std::string>* search1;
	search1 = new MyClass<std::string>();
	search1->Prepend("two");

	if (list2->Search(search1) == 1)
		std::cout << "Test Search: success" << "\n";
	else {
		std::cout << "Test Search: fail" << "\n";
	};

	delete search1;
	delete list1;
	delete list2;
	delete list3;
	delete map1;
	delete map2;
	delete map3;

	return 0;
}





