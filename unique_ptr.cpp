#include <iostream>
#include <memory>
#include <map>
#include <string>
#include <vector>



class Vocabulary
{
public:
	Vocabulary(int s):size(s)
	{
		ptrU = std::make_unique<std::vector<std::string>>();
		std::cout << "Vocabulary is created!" << std::endl;
	}

	~Vocabulary()
	{
		std::cout << "Vocabulary is destroyed!" << std::endl;
	}

	void Insert(std::unique_ptr<std::string> ptr)
	{
		ptrU->push_back(*ptr);
	}

	void Print()
	{
		for (int i = 0; i < ptrU->size(); ++i)
		{
			std::cout << (*ptrU)[i] << std::endl;
		}
	}

private:
	std::unique_ptr<std::vector<std::string>> ptrU;
	int size;
};



int main()
{
	
	Vocabulary V(2);

	std::unique_ptr<std::string> ptrU1{ new std::string("first") };
	std::unique_ptr<std::string> ptrU2{ new std::string("second")};

	V.Insert(move(ptrU1));
	V.Insert(move(ptrU2));

	V.Print();
	

	return 0;
}