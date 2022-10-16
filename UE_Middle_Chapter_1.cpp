#include <iostream>
#include <cmath>
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

int main()
{
	Vector vector1(0, 1, 2);
	Vector vector2(3, 4, 5);
	Vector vector3;

	std::cout << "Vector1 = " << vector1 << '\n';
	std::cout << "Vector2 = " << vector2 << '\n';
	std::cout << std::endl;

	std::cout << "Vector1 + Vector2 = " << vector1 + vector2 << '\n';
	std::cout << "Vector2 - Vector1 = " << vector2 - vector1 << '\n';
	std::cout << "Vector1 * int(2) = " << vector1 * 2 << '\n';
	std::cout << "Vector1 length = " << float(vector1) <<'\n';
	std::cout << "Vector2 num1 = " << vector2[1] << '\n';
	std::cout << std::endl;

	std::cin >> vector3;
	std::cout << "Your Vector3 = " << vector3 << '\n';



	std::cout << '\n' << "===============================" << '\n';
	//system("pause");
    return 0; 
}
