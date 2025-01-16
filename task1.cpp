#include <iostream>
#include <string>
using namespace std;

class Appliance {
protected:
    string brand;
    float powerUsage;
    bool isOn;

public:
    static float totalPowerUsage;

    Appliance(string b, float p) : brand(b), powerUsage(p), isOn(false) {}

    virtual void turnOn() 
    {
        isOn = true;
        cout << brand << " turned on.\n";
    }

    virtual void turnOff()
    {
        isOn = false;
        cout << brand << " turned off.\n";
    }
};

float Appliance::totalPowerUsage = 0;

class WashingMachine : public Appliance
{
private:
    float loadCapacity;
    float powerPerCycle;

public:
    WashingMachine(string b, float p, float lc, float pp)
        : Appliance(b, p), loadCapacity(lc), powerPerCycle(pp) {}

    void startWashCycle()
    {
        if (isOn)
        {
            Appliance::totalPowerUsage += powerPerCycle;
            cout << "Washing cycle started, power used: " << powerPerCycle << " units.\n";
        }
        else {
            cout << "Turn on the washing machine first.\n";
        }
    }
};

class AirConditioner : public Appliance
{
private:
    float coolingCapacity;
    float avgPowerConsumption;
    int temperature;

public:
    AirConditioner(string b, float p, float cc, float apc)
        : Appliance(b, p), coolingCapacity(cc), avgPowerConsumption(apc), temperature(24) {}

    void setTemperature(int temp)
    {
        if (isOn)
        {
            temperature = temp;
            cout << "Temperature set to " << temperature << " degrees.\n";
        }
        else {
            cout << "Turn on the air conditioner first.\n";
        }
    }

    void turnOn() override
    {
        Appliance::turnOn();
        Appliance::totalPowerUsage += avgPowerConsumption;
    }

    void turnOff() override
    {
        Appliance::turnOff();
    }
};
class fridge : public Appliance
{
private:
    double space;
    double powerconsumed;
public:
    fridge(string b, float p, double sp, double pow):Appliance(b , p) , space(sp),powerconsumed(pow)  { }
};

class NetworkDevice
{
protected:
    string ipAddress;
    bool connectionStatus;

public:
    NetworkDevice() : ipAddress(""), connectionStatus(false) {}

    void connect(string ip)
    {
        ipAddress = ip;
        connectionStatus = true;
        cout << "Connected to network with IP: " << ipAddress << "\n";
    }

    void disconnect() 
    {
        connectionStatus = false;
        ipAddress = "";
        cout << "Disconnected from network.\n";
    }
};
class Refrigerator : public Appliance
{
private:
    float storageVolume;
    float avgPowerConsumption;
    int internalTemperature;

public:
    Refrigerator(string b, float p, float sv, float apc)
        : Appliance(b, p), storageVolume(sv), avgPowerConsumption(apc), internalTemperature(4) {}

    void adjustTemperature(int temp)
    {
        internalTemperature = temp;
        cout << "Internal temperature adjusted to " << internalTemperature << " degrees.\n";
    }

    void turnOn() override
    {
        Appliance::turnOn();
        Appliance::totalPowerUsage += avgPowerConsumption;
    }

    void turnOff() override
    {
        Appliance::turnOff();
    }
};

class SmartAppliance : public Appliance, protected NetworkDevice
{
public:
    SmartAppliance(string b, float p) : Appliance(b, p) {}

    void turnOn() override
    {
        Appliance::turnOn();
        connect("192.168.1.1");
    }

    void turnOff() override
    {
        Appliance::turnOff();
        disconnect();
    }
};

int main()
{
    Appliance* appliances[4];

    appliances[0] = new WashingMachine("Samsung Washer", 0, 8.0, 1.5);
    appliances[1] = new AirConditioner("LG AC", 0, 5.5, 2.0);
    appliances[2] = new Refrigerator("Whirlpool Fridge", 0, 300.0, 1.2);
    appliances[3] = new SmartAppliance("Smart Light", 0.1);

    appliances[0]->turnOn();
    static_cast<WashingMachine*>(appliances[0])->startWashCycle();
    appliances[1]->turnOn();
    static_cast<AirConditioner*>(appliances[1])->setTemperature(22);
    appliances[2]->turnOn();
    static_cast<Refrigerator*>(appliances[2])->adjustTemperature(3);
    appliances[3]->turnOn();

    cout << "Total power usage: " << Appliance::totalPowerUsage << " units.\n";

    for (int i = 0; i < 4; i++) {
        appliances[i]->turnOff();
        delete appliances[i];
    }

    return 0;
}
