
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Equipment
{
public:
    string id;
    string type;

    int usage;
    int failure;
    int condition;
    int temp;
    int days;
    int risk;

    Equipment(string i, string t, int u, int f, int c, int te, int d)
    {
        id = i;
        type = t;
        usage = u;
        failure = f;
        condition = c;
        temp = te;
        days = d;
        risk = 0;
    }

    void calculateRisk()
    {
        risk = usage / 20;
        risk = risk + failure * 10;
        risk = risk + condition * 10;
        risk = risk + temp / 5;
        risk = risk + days / 5;
    }

    void display()
    {
        cout << "\n----------------------";
        cout << "\nID: " << id;
        cout << "\nType: " << type;
        cout << "\nUsage Hours: " << usage;
        cout << "\nFailures: " << failure;

        cout << "\nCondition: ";

        if (condition == 1)
            cout << "Good";
        else if (condition == 2)
            cout << "Average";
        else
            cout << "Poor";

        cout << "\nTemperature: " << temp;
        cout << "\nMaintenance Days: " << days;
        cout << "\nRisk Score: " << risk;

        cout << "\nStatus: ";

        if (risk >= 120)
            cout << "Critical";
        else if (risk >= 80)
            cout << "High";
        else if (risk >= 40)
            cout << "Medium";
        else
            cout << "Low";

        cout << "\n----------------------\n";
    }
};


class MaintenanceSystem
{
public:
    vector<Equipment> list;


    void add()
    {
        string id;
        string type;

        int usage;
        int failure;
        int condition;
        int temp;
        int days;

        cout << "\nEnter ID: ";
        cin >> id;

        cout << "Enter Type: ";
        cin >> type;

        cout << "Enter Usage Hours: ";
        cin >> usage;

        cout << "Enter Previous Failures: ";
        cin >> failure;

        cout << "\nCondition";
        cout << "\n1. Good";
        cout << "\n2. Average";
        cout << "\n3. Poor";
        cout << "\nEnter choice: ";
        cin >> condition;

        cout << "Enter Temperature: ";
        cin >> temp;

        cout << "Enter Maintenance Days: ";
        cin >> days;

        Equipment e(id, type, usage, failure,
                    condition, temp, days);

        e.calculateRisk();

        list.push_back(e);

        cout << "\nEquipment added.\n";
    }


    void display()
    {
        if (list.size() == 0)
        {
            cout << "\nNo equipment found.\n";
            return;
        }

        for (int i = 0; i < list.size(); i++)
        {
            list[i].display();
        }
    }


    void search()
    {
        string id;

        cout << "\nEnter ID to search: ";
        cin >> id;

        for (int i = 0; i < list.size(); i++)
        {
            if (list[i].id == id)
            {
                cout << "\nEquipment found.";
                list[i].display();
                return;
            }
        }

        cout << "\nEquipment not found.\n";
    }


    void update()
    {
        string id;

        cout << "\nEnter ID to update: ";
        cin >> id;

        for (int i = 0; i < list.size(); i++)
        {
            if (list[i].id == id)
            {
                cout << "\nEnter new usage hours: ";
                cin >> list[i].usage;

                cout << "Enter new temperature: ";
                cin >> list[i].temp;

                cout << "Enter new condition (1-Good, 2-Average, 3-Poor): ";
                cin >> list[i].condition;

                cout << "Enter new maintenance days: ";
                cin >> list[i].days;

                list[i].calculateRisk();

                cout << "\nUpdated successfully.\n";
                return;
            }
        }

        cout << "\nEquipment not found.\n";
    }
};


int main()
{
    MaintenanceSystem m;

    int ch;

    while (1)
    {
        cout << "\n\n===== EQUIPMENT SYSTEM =====";
        cout << "\n1. Add";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Update";
        cout << "\n0. Exit";

        cout << "\nEnter choice: ";
        cin >> ch;

        if (ch == 1)
        {
            m.add();
        }
        else if (ch == 2)
        {
            m.display();
        }
        else if (ch == 3)
        {
            m.search();
        }
        else if (ch == 4)
        {
            m.update();
        }
        else if (ch == 0)
        {
            cout << "\nProgram ended.";
            break;
        }
        else
        {
            cout << "\nWrong choice.";
        }
    }

    return 0;
}

