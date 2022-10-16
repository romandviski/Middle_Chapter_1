#include <iostream>
//https://itnan.ru/post.php?c=1&p=308890

const int N = 2;

class User
{
	std::string* nickname;
	double* score;
	int** itemsID;
public:
	User()
	{
		this->nickname = new std::string();
		this->itemsID = new int* [0];
		this->score = 0;
	}

	User(std::string nickname, double score, int** itemsID)
	{
		this->nickname = new std::string(nickname);
		this->score = new double(score);
		this->itemsID = new int* [N];

		for (int i = 0; i < N; i++)
			this->itemsID[i] = new int[N];

		for (int x = 0; x < N; x++)
			for (int y = 0; y < N; y++)
				this->itemsID[x][y] = itemsID[x][y];
	}

	User(const User& other)
	{
		std::cout << "copy constructor calling" << std::endl;
		nickname = new std::string(*other.nickname);
		score = new double(*other.score);

		this->itemsID = new int* [N];
		for (int i = 0; i < N; i++)
			this->itemsID[i] = new int[N];

		for (int x = 0; x < N; x++)
			for (int y = 0; y < N; y++)
				this->itemsID[x][y] = other.itemsID[x][y];
	}

	~User()
	{
		std::cout << "destructor calling" << std::endl;
		delete nickname;
		delete itemsID;
		delete score;
	}

	friend std::istream& operator>> (std::istream& in, User& user);
	friend std::ostream& operator<<(std::ostream& out, const User& user);

	User& operator=(const User& other)
	{
		nickname = new std::string(*other.nickname);
		score = new double(*other.score);

		this->itemsID = new int* [N];
		for (int i = 0; i < N; i++)
			this->itemsID[i] = new int[N];

		for (int x = 0; x < N; x++)
			for (int y = 0; y < N; y++)
				this->itemsID[x][y] = other.itemsID[x][y];

		return *this;
	}
};

std::istream& operator>>(std::istream& in, User& user)
{
	in >> *user.nickname >> *user.score;
	return in;
}

std::ostream& operator<<(std::ostream& out, const User& user)
{
	out << *user.nickname << "\nScore: " << *user.score << "\nitemsID:\n";
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++)
			out << user.itemsID[x][y] << " ";
		out << "\n";
	}
	return out;
}

int main()
{
	int** itemsID = new int* [N];
	for (int i = 0; i < N; i++)
		itemsID[i] = new int[N];
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			itemsID[x][y] = x + y;

	User Mikhail("romandviski", 2.28, itemsID);

	delete[] itemsID;

	User Vasyan = Mikhail;
	std::cout << Mikhail << std::endl;
	std::cout << Vasyan << std::endl;

	std::cout << std::endl;

	std::cin >> Vasyan;
	std::cout << std::endl;
	std::cout << Vasyan << std::endl;

	std::cout << '\n' << "===============================" << '\n';
	//system("pause");
	return 0;
}
