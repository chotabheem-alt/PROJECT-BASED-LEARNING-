
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Equipment {
public:
    string id;
    string type;
    int usageHours;
    int failures;
    int condition;
    int temperature;
    int maintenanceDays;
    int riskScore;

    Equipment(string i, string t, int u, int f, int c, int temp, int days) {
        id = i;
        type = t;
        usageHours = u;
        failures = f;
        condition = c;
        temperature = temp;
        maintenanceDays = days;
        riskScore = 0;
    }

    void calculateRisk() {
        riskScore = (usageHours / 20)
                  + (failures * 10)
                  + (condition * 10)
                  + (temperature / 5)
                  + (maintenanceDays / 5);
    }

    void display() {
        cout << "\n-------------------------";
        cout << "\nEquipment ID: " << id;
        cout << "\nType: " << type;
        cout << "\nUsage Hours: " << usageHours;
        cout << "\nPrevious Failures: " << failures;
        cout << "\nCondition: " << condition;
        cout << "\nTemperature: " << temperature;
        cout << "\nMaintenance Days: " << maintenanceDays;
        cout << "\nRisk Score: " << riskScore;

        if (riskScore >= 120)
            cout << "\nStatus: CRITICAL";
        else if (riskScore >= 80)
            cout << "\nStatus: HIGH";
        else if (riskScore >= 40)
            cout << "\nStatus: MEDIUM";
        else
            cout << "\nStatus: LOW";

        cout << "\n-------------------------\n";
    }
};

struct CompareRisk {
    bool operator()(Equipment a, Equipment b) {
        return a.riskScore < b.riskScore;
    }
};

class MaintenanceSystem {
private:
    vector<Equipment> equipmentList;

public:

    // FUNCTION 1: ADD EQUIPMENT
    void addEquipment() {

        string id, type;
        int usage, failures, condition;
        int temperature, days;

        cout << "\nEnter Equipment ID: ";
        cin >> id;

        cout << "Enter Equipment Type: ";
        cin >> type;

        cout << "Enter Usage Hours: ";
        cin >> usage;

        cout << "Enter Previous Failures: ";
        cin >> failures;

        cout << "Enter Condition (1-Good, 2-Average, 3-Poor): ";
        cin >> condition;

        cout << "Enter Temperature: ";
        cin >> temperature;

        cout << "Enter Days Since Last Maintenance: ";
        cin >> days;

        Equipment e(id, type, usage, failures,
                    condition, temperature, days);

        e.calculateRisk();

        equipmentList.push_back(e);

        cout << "\nEquipment added successfully!\n";
    }


    // FUNCTION 2: DISPLAY ALL
    void displayAll() {

        if (equipmentList.empty()) {
            cout << "\nNo equipment available.\n";
            return;
        }

        cout << "\n========== ALL EQUIPMENT ==========\n";

        for (int i = 0; i < equipmentList.size(); i++) {
            equipmentList[i].display();
        }
    }


    // FUNCTION 3: SEARCH EQUIPMENT
    void searchEquipment() {

        string id;

        cout << "\nEnter Equipment ID: ";
        cin >> id;

        for (int i = 0; i < equipmentList.size(); i++) {

            if (equipmentList[i].id == id) {

                cout << "\nEquipment Found!\n";

                equipmentList[i].display();

                return;
            }
        }

        cout << "\nEquipment not found.\n";
    }


    // FUNCTION 4: UPDATE EQUIPMENT
    void updateEquipment() {

        string id;

        cout << "\nEnter Equipment ID to update: ";
        cin >> id;

        for (int i = 0; i < equipmentList.size(); i++) {

            if (equipmentList[i].id == id) {

                cout << "\nEnter New Usage Hours: ";
                cin >> equipmentList[i].usageHours;

                cout << "Enter New Temperature: ";
                cin >> equipmentList[i].temperature;

                cout << "Enter New Condition: ";
                cin >> equipmentList[i].condition;

                cout << "Enter New Maintenance Days: ";
                cin >> equipmentList[i].maintenanceDays;

                equipmentList[i].calculateRisk();

                cout << "\nEquipment updated successfully!\n";

                return;
            }
        }

        cout << "\nEquipment not found.\n";
    }
};


int main() {

    MaintenanceSystem system;

    int choice;

    while (true) {

        cout << "\n\n===== INDUSTRIAL EQUIPMENT SYSTEM =====";
        cout << "\n1. Add Equipment";
        cout << "\n2. Display All Equipment";
        cout << "\n3. Search Equipment";
        cout << "\n4. Update Equipment";
        cout << "\n0. Exit";

        cout << "\n\nEnter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            system.addEquipment();
            break;

        case 2:
            system.displayAll();
            break;

        case 3:
            system.searchEquipment();
            break;

        case 4:
            system.updateEquipment();
            break;

        case 0:
            cout << "\nProgram ended.\n";
            return 0;

        default:
            cout << "\nInvalid choice.\n";
        }
    }

    return 0;
}

