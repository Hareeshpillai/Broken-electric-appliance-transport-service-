#include<bits/stdc++.h>

using namespace std;


class Customer //C++ class
{
public:
    string name;
    string address;
    char description[50000];
    string phone_num;
    string store;
    string item;
    string sheet_num;
};

void services();
void more();
void contact();
void repair();
void submit_message();
void show_repair_info();

void submit_message(Customer &c)
{
    system("cls");
    srand(time(NULL));
    int num;
    num = rand()%10000000+100000000;
    auto s = to_string(num);
    cout << "You have sent the sheet successfully!\n";
    cout << "Sheet number: NO."<< num << endl;
    cout << "Contact us if any question 03-1234567\n\n";
    s = s+".txt";
    ofstream sheet(s,ios::out);
    sheet << "Name: " << c.name << endl;
    sheet << "Address: "<< c.address << endl;
    sheet << "Phone number: "<< c.phone_num << endl;
    sheet << "Item type: "<< c.item << endl;
    sheet << "Designated store: "<< c.store << endl;
    string s1 = c.description;
    sheet << "Description : \n" << s1 << endl;

    system("pause");
    services();
}


void show_repair_info(Customer &c)
{
    system("cls");
    cout << "Name: " << c.name << endl;
    cout << "Address: "<< c.address << endl;
    cout << "Phone number: "<< c.phone_num << endl;
    cout << "Your item type: "<< c.item << endl;
    cout << "Designated store: "<< c.store << endl;
    cout << "Description :"<< c.description << "\n\n";

    int choice;
    cout << "Enter 1 to fill the repair sheet again if you need.\n";
    cout << "Enter any other number to submit the sheet.\n";
    cin >> choice;
    if(choice==1) repair();
    else submit_message(c);
}

void repair()
{
    Customer c;
    system("cls");
    cout << "Name: ";
    cin >> c.name;
    cout << "Address: ";
    cin >> c.address;
    cout << "Phone number: ";
    cin>> c.phone_num;
    system("cls");
    cout << "Choose your item type!\n\n1. computer\n\n2. smartphone\n\n3. monitor\n\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        c.item = "computer";
        break;
    case 2:
        c.item = "smartphone";
        break;
    case 3:
        c.item = "monitor";
        break;
    default:
        cout << "error!\n";
        system("pause");
        repair();
        break;
    }
    system("cls");
    cout << "Choose the designated store!\n\n1. Bsus\n\n2. Bcer\n\n3. Random\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        c.store = "Bsus";
        break;
    case 2:
        c.store = "Bcer";
        break;
    case 3:
        c.store = "Random";
        break;
    default:
        cout << "error!\n";
        system("pause");
        repair();
        break;
    }
    system("cls");
    cout << "Description of your broken item:\n";
    char blank;
    cin.get(blank);
    cin.getline(c.description,50000);
    show_repair_info(c);

}

void contact()
{
    system("cls");
    Customer c;
    cout << "Name: ";
    cin >> c.name;
    cout << "sheet number: ";
    cin >> c.sheet_num;
    cout << "Phone number: ";
    cin>> c.phone_num;
    cout << "Description: ";
    char blank;
    cin.get(blank);
    cin.getline(c.description,50000);

    string file_name = c.sheet_num + "request.txt";
    ofstream request(file_name,ios::out);
    request << "Name: " << c.name << endl;
    request << "sheet number: "<< c.sheet_num << endl;
    request << "Phone number: "<< c.phone_num << endl;
    string s1 = c.description;
    request << "Description : \n" << s1 << endl;
    int choice;
    cout << "\nEnter 1 to fill the repair sheet again if you need.\n";
    cout << "Enter any other number to submit the sheet.\n";
    cin >> choice;
    if(choice==1) contact();
    else services();
}

void more()
{
    cout << "The service will help you to transport your broken product and send it back when fixed.\n";
    cout << "You just need to stay home and wait for your product to be repaired.\n";
    cout << "height < 30cm and width < 30cm and length < 30cm  ------> 100 shipping fee\n";
    cout << "height < 80cm and width < 80cm and length < 80cm  ------> 200 shipping fee\n";
    cout << "height < 150cm and width < 150cm and length < 150cm  ------> 300 shipping fee\n";
    cout << "height < 200cm and width < 200cm and length < 200cm  ------> 400 shipping fee\n";
    system("pause");
    services();
}

void services()
{
    system("cls");
    cout << "Hi\n\n";
    cout << "What kind of service do you need?\n\n";
    cout << "1. Repair product\n";
    cout << "2. Contact customer service representative\n";
    cout << "3. More information about this service\n";
    cout << "4. Exit\n";

    cout << "\n\n\nEnter your choice : ";
    int choice=0;
    cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        repair();
        break;
    case 2:
        system("cls");
        contact();
        break;
    case 3:
        system("cls");
        more();
        break;
    case 4:
        exit(1);
        break;
    default:
        cout << "error!\n";
        system("pause");
        system("cls");
        services();
        break;
    }
}


int main()
{
    services();
}
