#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Equipment {
public:
    int id;
    string type;
    int usageHours;
    int failures;
    int condition;
    int temperature;
    int maintenanceDays;
    double riskScore;

    Equipment(int i, string t, int u, int f, int c, int temp, int m) {
        id = i;
        type = t;
        usageHours = u;
        failures = f;
        condition = c;
        temperature = temp;
        maintenanceDays = m;
        riskScore = 0;
    }

    void calculateRisk() {
        riskScore = (usageHours / 20.0)
                  + (failures * 10)
                  + (condition * 10)
                  + (temperature / 5.0)
                  + (maintenanceDays / 5.0);
    }

    void display() {
        cout << "\nEquipment ID: " << id;
        cout << "\nType: " << type;
        cout << "\nUsage Hours: " << usageHours;
        cout << "\nPrevious Failures: " << failures;
        cout << "\nTemperature: " << temperature;
        cout << "\nRisk Score: " << riskScore;

        if (riskScore >= 80)
            cout << "\nStatus: HIGH RISK";
        else
            cout << "\nStatus: NORMAL";

        cout << "\n-------------------------\n";
    }
};

struct CompareRisk {
    bool operator()(Equipment a, Equipment b) {
        return a.riskScore < b.riskScore;
    }
};

int main() {

    vector<Equipment> equipment;

    // Sample machines
    equipment.push_back(
        Equipment(101, "Generator", 920, 4, 3, 87, 75));

    equipment.push_back(
        Equipment(102, "Pump", 340, 1, 1, 54, 20));

    equipment.push_back(
        Equipment(103, "Compressor", 780, 3, 2, 79, 60));

    // Calculate risk
    for (int i = 0; i < equipment.size(); i++) {
        equipment[i].calculateRisk();
    }

    cout << "INDUSTRIAL EQUIPMENT FAILURE PREDICTION SYSTEM\n";
    cout << "================================================\n";

    // Display all equipment
    cout << "\nEquipment Information:\n";

    for (int i = 0; i < equipment.size(); i++) {
        equipment[i].display();
    }

    // Priority queue  highest-risk equipment
    priority_queue<Equipment,
                   vector<Equipment>,
                   CompareRisk> priorityQueue;

    for (int i = 0; i < equipment.size(); i++) {
        priorityQueue.push(equipment[i]);
    }

    cout << "\nMAINTENANCE PRIORITY\n";
    cout << "====================\n";

    while (!priorityQueue.empty()) {

        Equipment top = priorityQueue.top();
        priorityQueue.pop();

        cout << "Equipment " << top.id
             << " (" << top.type << ")"
             << " -> Risk Score: "
             << top.riskScore << endl;
    }

    return 0;
}
