#include <iostream>
#include <vector>
#include <functional>

/*
class IErrorLog
{
public:
	virtual bool openlog(const char* filename) = 0;
	virtual bool closeLog() = 0;
	virtual bool writeError(const char* errorMessage) = 0;

	virtual ~IErrorLog() {};
};

class FileErrorLog : public IErrorLog
{
	
};

class ConsoleErrorLog : public IErrorLog
{
	
};
*/

class Wheel
{
public:
	float diameter;
	Wheel(float f)
	{
		diameter = f;
	}
};

class Engine
{
public:
	float power;
	Engine(float f)
	{
		power = f;
	}
};

class Vehicle
{
public:
	Vehicle()
	{
	}
	friend std::ostream& operator<<(std::ostream& out, const Vehicle& vehicle);

	virtual void print(std::ostream& out) = 0;
	virtual float GetPowerEngine() = 0;
};

std::ostream& operator<<(std::ostream& out, Vehicle& vehicle)
{
	vehicle.print(out);
	return out;
}

class WaterVehicle : public Vehicle
{
	Engine* engine;
protected:
	float draught;
public:
	WaterVehicle(Engine engi, float value)
	{
		engine = new Engine(engi);
		draught = value;
	}

	void print(std::ostream& out) override {
		out << "WaterVehicle";
	}

	float GetPowerEngine() override {
		return engine->power;
	}
};

class RoadVehicle : public Vehicle
{
protected:
	Engine* engine;
	float clearance;
public:
	RoadVehicle(Engine engine, float clearance)
	{
		this->engine = new Engine(engine);
		this->clearance = clearance;
	}

	void print(std::ostream& out) override {
		out << "RoadVehicle";
	}

	float GetPowerEngine() override {
		return engine->power;
	}
};

class Bicycle : public RoadVehicle
{
	Wheel* frontWheel;
	Wheel* backWheel;
public:
	Bicycle(Engine engine, Wheel wheel1, Wheel wheel2, float clearance) : RoadVehicle(engine, clearance)
	{
		frontWheel = new Wheel(wheel1);
		backWheel = new Wheel(wheel2);
	}

	void print(std::ostream& out) override
	{
		out << "Bicycle Wheels: " << frontWheel->diameter << " " << backWheel->diameter;
		out << " Ride height : " << clearance;
	}
};

class Car : public RoadVehicle
{
	Wheel* frontRightWheel;
	Wheel* frontLeftWheel;
	Wheel* backRightWheel;
	Wheel* backLeftWheel;
public:
	Car(Engine engine, Wheel wheel1, Wheel wheel2, Wheel wheel3, Wheel wheel4, float value) : RoadVehicle(engine, value)
	{
		frontRightWheel = new Wheel(wheel1);
		frontLeftWheel = new Wheel(wheel2);
		backRightWheel = new Wheel(wheel3);
		backLeftWheel = new Wheel(wheel4);
	}

	void print(std::ostream& out) override
	{
		out << "Car Engine : " << engine->power;
		out << " Wheels : " << frontRightWheel->diameter << " " << frontLeftWheel->diameter << " " << backRightWheel->diameter << " " << backLeftWheel->diameter;
		out << " Ride height : " << clearance;
	}
};

float GetHighestPower(std::vector<Vehicle*> vehicles)
{
	if (vehicles.size() == 0) return 0;
	float maxEngine = 0;
	for (int i = 0; i < vehicles.size(); i++)
		if (vehicles[i]->GetPowerEngine() > maxEngine)
			maxEngine = vehicles[i]->GetPowerEngine();
	if (maxEngine == 0) return 0;
	return maxEngine;
}

int main()
{
	//first part
	Car c(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 150);
	std::cout << c << std::endl;

	Bicycle b(Engine(150), Wheel(20), Wheel(20), 300);
	std::cout << b << std::endl;

	//second part
	std::vector<Vehicle*> v;
	v.push_back(new Car(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 250));
	v.push_back(new Bicycle(Engine(250), Wheel(1), Wheel(1), 7));
	v.push_back(new Car(Engine(200), Wheel(19), Wheel(19), Wheel(19), Wheel(19), 130));
	v.push_back(new WaterVehicle(Engine(150), 5000));

	std::cout << "The highest power is " << GetHighestPower(v) << std::endl;

	return 0;
}
