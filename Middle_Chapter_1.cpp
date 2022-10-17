#include <iostream>
#include <string>
#include <vector>
#include <iostream>
//https://itnan.ru/post.php?c=1&p=308890



class Vector
{
public:
	Vector()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Vector(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	operator float()
	{
		return sqrt(x * x + y * y + z * z);
	}

	friend Vector operator+(const Vector& a, const Vector& b);
	friend Vector operator-(const Vector& a, const Vector& b);
	friend Vector operator*(const Vector& a, const int b);
	friend bool operator>(const Vector& a, const Vector& b);
	friend std::ostream& operator<<(std::ostream& out, const Vector& v);
	friend std::istream& operator>>(std::istream& stream, Vector& v);


	float operator[](int index)
	{
		switch (index)
		{
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		case 2:
			return z;
			break;
		default:
			std::cout << "index error";
			return 0;
		}
	}

private:
	float x;
	float y;
	float z;
};

Vector operator+(const Vector& a, const Vector& b)
{
	return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector operator-(const Vector& a, const Vector& b)
{
	return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector operator*(const Vector& a, const int b)
{
	return Vector(a.x * b, a.y * b, a.z * b);
}

bool operator>(const Vector& a, const Vector& b)
{

	return false;
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
	out << v.x << ' ' << v.y << ' ' << v.z;
	return out;
}

std::istream& operator>>(std::istream& stream, Vector& v)
{
	std::cout << "Input vector3:\nX:";
	std::cin >> v.x;
	std::cout << "Y:";
	std::cin >> v.y;
	std::cout << "Z:";
	std::cin >> v.z;
	std::cout << '\n';
	return stream;
}

class Item
{
	std::string ItemName;
public:
	Item()
	{
		ItemName = "None";
	}
	Item(std::string inItemName)
	{
		ItemName = inItemName;
	}
	std::string ShowItemName()
	{
		//std::cout << ItemName << std::endl;
		return ItemName;
	}
};

class Guild;

class Player
{
	Vector Location;
	std::string PlayerName;
	Item* MainItem;
	std::vector<Guild*> Guilds;
public:
	Player()
	{
		PlayerName = "none";
	}

	Player(std::string inPlayerName, Vector InitLocation)
	{
		PlayerName = inPlayerName;
		Location = InitLocation;
	}

	void ShowPlayerInfo()
	{
		std::cout << PlayerName << " is at " << Location << std::endl;
		if (MainItem)
		{
			std::cout << PlayerName << " have " << MainItem->ShowItemName() << std::endl;
		}
		else
		{
			std::cout << PlayerName << " dont have item" << std::endl;
		}
	}
	void SetNewItem(Item* newItem)
	{
		MainItem = newItem;
	}

	void JoinGuild(Guild* guildToJoin)
	{
		Guilds.push_back(guildToJoin);
	}

	friend class Guild;
};

class Guild
{
	std::vector<Player*> Players;
public:
	void AddNewPlayer(Player* newPlayer)
	{
		newPlayer->JoinGuild(this);
		Players.push_back(newPlayer);
	}

	void RemovePlayer(Player* PlayerToRemove)
	{
		//Players.push_back(PlayerToRemove);
	}
};

class PlayerParty
{
	Player** players;
	int CurrentPlayersNum;
public:
	PlayerParty()
	{
		CurrentPlayersNum = 0;
		players = new Player * [4];
	}
	void AddPlayerToParty(Player* newPlayer)
	{
		players[CurrentPlayersNum] = newPlayer;
		CurrentPlayersNum++;
	}
	void ShowAllPlayersInfo()
	{
		for (int i = 0; i < CurrentPlayersNum; i++)
		{
			players[i]->ShowPlayerInfo();
		}
	}
};

int main()
{
	Player* PlayerA = new Player("Vasyan", Vector(4,0,4));
	Player* PlayerB = new Player("Petyan", Vector(7, 7, 7));
	Item* Sword = new Item("Sword");
	PlayerA->SetNewItem(Sword);
	std::cout << std::endl;

	PlayerParty* MainParty = new PlayerParty;
	MainParty->AddPlayerToParty(PlayerA);
	MainParty->AddPlayerToParty(PlayerB);
	MainParty->ShowAllPlayersInfo();
	std::cout << std::endl;

	std::cout << std::endl << "===============================" << std::endl;
	//system("pause");
	return 0;
}
