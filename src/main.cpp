#include<iostream>

#include<fstream>

#include<string.h>

#include<stdio.h>

#include<unistd.h>

#include<conio.h>

#include<stdlib.h>

using namespace std;
void mainmenu();
void supplier_info();
void customer_info();
void customer_info();
void medicine1();
class supplier {
    char supid[9];
    char supname[25], supcity[30], supemail[50], supcontact[20];
    public:
        void display_supplier();
    void search_supplier(const char * );
    void delete_supplier(const char * );
    void get_supplier_info();
    int store_supplier_data();
    void supplier_purchase_show();
    void show();
    void search_supplier_purchase(const char * );
};
void supplier::show() {
    cout << "\n\n\t\t\t" << "ID-" << supid << "\t\t\t\t" << "Name-" << supname << "\n\n\t\t\t" << "City-" << supcity << "\t\t\t" << "Email-" << supemail << "\n\n\t\t\t" << "Contact-" << supcontact << "\n";
    cout << "\n\n";
}
void supplier::get_supplier_info() {
    {
        cout << "\n\t\t\tID-";
        cin.ignore();
        cin.getline(supid, 8);
        cout << "\n\t\t\tName-";
        cin.getline(supname, 24);
        cout << "\n\t\t\tCity-";
        cin.getline(supcity, 29);
        cout << "\n\t\t\tEmail-";
        cin.getline(supemail, 49);
        cout << "\n\t\t\tContact-";
        cin.getline(supcontact, 19);

    }
}
int supplier::store_supplier_data() {
    if (supid == 0) {
        cout << "\nSupplier data not initialised";
        return 0;
    } else {
        ofstream file;
        file.open("supplier.dat", ios::app | ios::binary);
        file.write((char * ) this, sizeof( * this));
        file.close();
        return (1);
    }
}
void supplier::display_supplier() {
    ifstream file;
    file.open("supplier.dat", ios:: in | ios::binary);
    if (!file) {
        cout << "\n\n\t\t\tFile not found\n\n";
    } else {
        file.read((char * ) this, sizeof( * this));
        while (!file.eof()) {
            show();
            file.read((char * ) this, sizeof( * this));
        }
        file.close();
    }
}
void supplier::search_supplier(const char * t) {
    int count = 0;
    ifstream file;
    file.open("supplier.dat", ios:: in | ios::binary);
    if (!file) {
        cout << "\n\n\t\t\tFile not found\n\n";
    } else {
        file.read((char * ) this, sizeof( * this));
        while (!file.eof()) {
            if (!strcmp(t, supid)) {
                show();
                count++;
            }
            file.read((char * ) this, sizeof( * this));
        }
        if (count == 0) {
            cout << "\n\n\t\t\tRecord Not Found\n\n";
        }
        file.close();
    }
}
void supplier::delete_supplier(const char * t) {
    ifstream fin;
    ofstream fout;
    fin.open("supplier.dat", ios:: in | ios::binary);
    if (!fin) {
        cout << "\n\n\t\t\tfile not found\n\n";
    } else {
        fout.open("temp.dat", ios::out | ios::binary);
        fin.read((char * ) this, sizeof( * this));
        while (!fin.eof()) {
            if (strcmp(supid, t)) {
                fout.write((char * ) this, sizeof( * this));
            }
            fin.read((char * ) this, sizeof( * this));
        }
        fin.close();
        fout.close();
        remove("supplier.dat");
        rename("temp.dat", "supplier.dat");
    }
}
void supplier_info() {
    supplier s;
    int choice;
    char search[20];
    do {
        system("cls");
        cout << "\n\t\t\t------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t\t\tSUPPLIER'S INFO\n";
        cout << "\t\t\t------------------------------------------------------------------------------\n";
        cout << "\n\n\t\t\t(1) Add Supplier\n\n\t\t\t(2) Display Existing Suppliers\n\n\t\t\t(3) Search Supplier\n\n\t\t\t(4)Delete Supplier\n\n\t\t\t(5)Main Menu";
        cout << "\n\n\t\t\tEnter Your Choice-";
        cin >> choice;
        cout << "\n";
        switch (choice) {
        case 1:
            system("cls");
            cout << "\n\n\t\t\t------------------------------------------------------------------------------";
            cout << "\n\t\t\t\t\t\tSUPPLIER ENTRY\n";
            cout << "\t\t\t------------------------------------------------------------------------------\n";
            s.get_supplier_info();
            s.store_supplier_data();
            cout << "\n\t\t\tData Entered Sucessfully !!!!!";
            cout << "\n\n\t\t\tPress Any key to continue.......";
            getch();
            break;
        case 2:
            system("cls");
            cout << "\n\t\t\t------------------------------------------------------------------------------";
            cout << "\n\t\t\t\t\t\tLIST OF EXIXTING SUPPLIERS\n";
            cout << "\t\t\t------------------------------------------------------------------------------\n";
            s.display_supplier();
            cout << "\n\n\t\t\tPress Any key to continue.......";
            getch();
            break;
        case 3:
            system("cls");
            cout << "\n\t\t\t------------------------------------------------------------------------------";
            cout << "\n\t\t\t\t\t\tSEARCH SUPPLIERS\n";
            cout << "\t\t\t------------------------------------------------------------------------------\n";
            cout << "\n\n\t\t\tEnter Supplier's ID to search-";
            cin >> search;
            s.search_supplier(search);
            cout << "\n\n\t\t\tPress Any key to continue.......";
            getch();
            break;
        case 4:
            system("cls");
            cout << "\n\t\t\t------------------------------------------------------------------------------";
            cout << "\n\t\t\t\t\t\tDELETE SUPPLIERS\n";
            cout << "\t\t\t------------------------------------------------------------------------------\n";
            cout << "\n\n\t\t\tEnter Supplier's ID to Delete-";
            cin >> search;
            s.delete_supplier(search);
            cout << "\n\n\t\t\tData Deleted Sucessfully !!!!!!";
            cout << "\n\n\t\t\tPress Any key to continue.......";
            getch();
            break;
        case 5:
            system("cls");
            mainmenu();
            break;
        default:
            cout << "\n\t\t\t\t\tEnter a Valid Choice !!!!!\n";
            break;
        }
    } while (choice != 5);
}
class customer {
    char cusid[9];
    char cusname[25], cuscontact[20];
    public:
        void display_customer();
    void search_customer(const char * );
    void search_customer_sale(const char * );
    void delete_customer(const char * );
    void get_customer_info();
    int store_customer_data();
    void show();
    void show1();
};
void customer::show() {

    cout << "\n\n\t\t\t" << "ID-" << cusid << "\t\t\t\t" << "Name-" << cusname << "\n\n\t\t\t" << "Contact-" << cuscontact << "\n";
    cout << "\n\n";
}
void customer::get_customer_info() {
    {
        cout << "\n\t\t\tID (Max 8 digits):";
        cin.ignore();
        cin.getline(cusid, 8);
        cout << "\n\t\t\tName-";
        cin.getline(cusname, 24);
        cout << "\n\t\t\tContact-";
        cin.getline(cuscontact, 19);
    }
}
int customer::store_customer_data() {
    if (cusid == 0) {
        cout << "\nCustomer data not initialised";
        return 0;
    } else {
        ofstream file;
        file.open("customer.dat", ios::app | ios::binary);
        file.write((char * ) this, sizeof( * this));
        file.close();
        return (1);
    }
}
void customer::display_customer() {
    ifstream file;
    file.open("customer.dat", ios:: in | ios::binary);
    if (!file) {
        cout << "\n\n\t\t\tFile not found\n\n";
    } else {
        file.read((char * ) this, sizeof( * this));
        while (!file.eof()) {
            show();
            file.read((char * ) this, sizeof( * this));
        }
        file.close();
    }
}
void customer::search_customer(const char * t) {
    int count = 0;
    ifstream file;
    file.open("customer.dat", ios:: in | ios::binary);
    if (!file) {
        cout << "\n\n\t\t\tFile not found\n\n";
    } else {
        file.read((char * ) this, sizeof( * this));
        while (!file.eof()) {
            if (!strcmp(t, cusid)) {
                show();
                count++;
            }
            file.read((char * ) this, sizeof( * this));
        }
        if (count == 0) {
            cout << "\n\n\t\t\tRecord Not Found\n\n";
        }
        file.close();
    }
}
void customer::delete_customer(const char * t) {
    ifstream fin;
    ofstream fout;
    fin.open("customer.dat", ios:: in | ios::binary);
    if (!fin) {
        cout << "\n\n\t\t\tfile not found\n\n";
    } else {
        fout.open("temp1.dat", ios::out | ios::binary);
        fin.read((char * ) this, sizeof( * this));
        while (!fin.eof()) {
            if (strcmp(cusid, t)) {
                fout.write((char * ) this, sizeof( * this));
            }
            fin.read((char * ) this, sizeof( * this));
        }
        fin.close();
        fout.close();
        remove("customer.dat");
        rename("temp1.dat", "customer.dat");
    }
}
void customer_info() {
    customer c;
    int choice;
    char search[20];
    do {
        system("cls");
        cout << "\n\t\t\t------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t\t\tCUSTOMER'S INFO\n";
        cout << "\t\t\t------------------------------------------------------------------------------\n";
        cout << "\n\n\t\t\t(1) Add Customer\n\n\t\t\t(2) Display Existing Customerss\n\n\t\t\t(3) Search Customer\n\n\t\t\t(4)Delete Customer\n\n\t\t\t(5)Main Menu";
        cout << "\n\n\t\t\tEnter Your Choice-";
        cin >> choice;
        cout << "\n";
        switch (choice) {
        case 1:
            system("cls");
            cout << "\n\n\t\t\t------------------------------------------------------------------------------";
            cout << "\n\t\t\t\t\t\tCUSTOMER ENTRY\n";
            cout << "\t\t\t------------------------------------------------------------------------------\n";
            c.get_customer_info();
            c.store_customer_data();
            cout << "\n\t\t\tData Entered Sucessfully !!!!!";
            cout << "\n\n\t\t\tPress Any key to continue.......";
            getch();
            break;
        case 2:
            system("cls");
            cout << "\n\t\t\t------------------------------------------------------------------------------";
            cout << "\n\t\t\t\t\t\tLIST OF EXIXTING CUSTOMERS\n";
            cout << "\t\t\t------------------------------------------------------------------------------\n";
            c.display_customer();
            cout << "\n\n\t\t\tPress Any key to continue.......";
            getch();
            break;
        case 3:
            system("cls");
            cout << "\n\t\t\t------------------------------------------------------------------------------";
            cout << "\n\t\t\t\t\t\tSEARCH CUSTOMER\n";
            cout << "\t\t\t------------------------------------------------------------------------------\n";
            cout << "\n\n\t\t\tEnter Customer's ID to search-";
            cin >> search;
            c.search_customer(search);
            cout << "\n\n\t\t\tPress Any key to continue.......";
            getch();
            break;
        case 4:
            system("cls");
            cout << "\n\t\t\t------------------------------------------------------------------------------";
            cout << "\n\t\t\t\t\t\tDELETE CUSTOMER\n";
            cout << "\t\t\t------------------------------------------------------------------------------\n";
            cout << "\n\n\t\t\tEnter Customer's ID to Delete-";
            cin >> search;
            c.delete_customer(search);
            cout << "\n\t\t\tData Deleted Sucessfully !!!!!";
            cout << "\n\n\t\t\tPress Any key to continue.......";
            getch();
            break;
        case 5:
            system("cls");
            mainmenu();
            break;
        default:
            cout << "\n\t\t\t\t\tEnter a Valid Choice !!!!!\n";
            break;
        }
    } while (choice != 5);
}

class medicine {
    char medid[9], medid1[9], medname[40], rack[10], cabnit[10], company[40], supplierid[4], mfg[12], exp[12], date[12], date1[12];
    float ucost, scost, amount, amount1;
    int quantity, quantity1;
    char bill[10], customerid[4];
    float price;
    char a[4];
    int b, n;

    public:
        medicine() {
            n = 0;
        }
    void purchase();
    int store_medpurchase_data();
    void search_medicine(const char * );
    void search_supplier_purchase();
    void sale();
    void purchasebillshow();
    void salesbillshow();
    void pbillshow();
    void saleshow();
    void sbillshow();
    void showstock();
    void show3();
    int purchasebill();
    int store_medsale_data();
    void search_customer_sale();
    void medsearch(const char * );
    void medsearch1(const char * );
    float cost(int,
        const char * );

};
void medicine::show3() {
    cout << "\n\n\t\t\t" << n;
}
void medicine::showstock() {

    ifstream file;
    file.open("stock.dat", ios:: in | ios::binary);
    file.read((char * ) this, sizeof( * this));
    while (!file.eof()) {
        cout << "\n\n\t\t\t" << n;
        file.read((char * ) this, sizeof( * this));
    }
    file.close();
}
void supplier::supplier_purchase_show() //used to show purchase from existing suppliers
{
    cout << "\n\t\t\t" << "Name-" << supname << "\n\n\t\t\t" << "Contact-" << supcontact << "\n";
}
int medicine::store_medpurchase_data() //stores data eneterd by user
{
    if (medid == 0) {
        cout << "\nMedicine data not initialised";
        return 0;
    } else {
        ofstream file;
        file.open("medicine.dat", ios::app | ios::binary);
        file.write((char * ) this, sizeof( * this));
        file.close();
        return (1);
    }
}
void medicine::saleshow() {
    medicine m;
    cout << "\n\t\t\t" << "Medicine Name-" << medname << "\n\n\t\t\t" << "Sales Price-" << scost << "\n";
}
void customer::show1() {

    cout << "\n\n\t\t\t" << "Name-" << cusname << "\n\n\t\t\t" << "Contact-" << cuscontact << "\n";
    cout << "\n\n";
}
void customer::search_customer_sale(const char * t) //used in purchase from existing supplier
{
    customer c;
    int count = 0;
    ifstream file;
    file.open("customer.dat", ios:: in | ios::binary);
    if (!file) {
        cout << "\n\n\t\t\tNo Data Found-";
    } else {
        file.read((char * ) this, sizeof( * this));
        while (!file.eof()) {
            if (!strcmp(t, cusid)) {
                show1();
                count++;
            }
            file.read((char * ) this, sizeof( * this));
        }
        if (count == 0) {
            cout << "\n\n\t\t\tCustomer Data  not found\n\n";
            cout << "\n\n\t\t\tDo You want to add a new Customer";
            cout << "\n\n\t\t\tY for Yes\t\t\tn for No";
            cout << "\n\n\t\t\tEnter Your Choice-";
            char choice;
            cin >> choice;
            switch (choice) {
            case 'y':
            case 'Y':
                customer c;
                c.get_customer_info();
                c.store_customer_data();
                break;
            case 'n':
            case 'N':
                medicine1();
                break;
            default:
                cout << "\n\n\t\t\tEnter a Valid choice !!!!!";
                break;
            }
        }
        file.close();
    }
}
void medicine::sbillshow() {
    cout << "\n\n\t\t\tMedicine Id: " << medid1 << "\t\t\tMedicine Name: " << medname << "\n\n\t\t\tQuantities Sold: " << quantity1 << "\t\t\tAmount: " << amount << "\n\n\t\t\tDate Of Sale: " << date1;
    cout << "\n\n";
}
void medicine::salesbillshow() {
    medicine m;
    ifstream file;
    file.open("salemedicine.dat", ios:: in | ios::binary);
    if (!file) {
        cout << "\n\n\t\t\tFile not found\n\n";
    } else {
        file.read((char * ) this, sizeof( * this));
        while (!file.eof()) {
            sbillshow();
            file.read((char * ) this, sizeof( * this));
        }
        file.close();
    }
}

int medicine::store_medsale_data() {
    if (medid == 0) {
        cout << "\nMedicine data not initialised";
        return 0;
    } else {
        ofstream file;
        file.open("salemedicine.dat", ios::app | ios::binary);
        file.write((char * ) this, sizeof( * this));
        file.close();
        return (1);
    }
}
void medicine::medsearch(const char * t) {
    medicine m;
    int count = 0;
    fstream file;
    file.open("medicine.dat", ios:: in | ios::binary);
    if (!file) {
        cout << "\n\n\t\t\tFile not found\n\n";
        getch();
        medicine1();

    } else {
        file.read((char * ) this, sizeof( * this));
        while (!file.eof()) {
            if (!strcmp(t, medid)) {
                saleshow();
                count++;
            }
            file.read((char * ) this, sizeof( * this));
        }
        if (count == 0) {
            cout << "\n\n\t\t\tRecord Not Found\n\n";
            //medicine1();
        }
        file.close();
    }
}
float medicine::cost(int x,
    const char * t) {
    int d;
    float a;
    d = x;
    int count = 0;
    ifstream file;
    file.open("medicine.dat", ios:: in | ios::binary);
    if (!file) {
        cout << "\n\n\t\t\tFile not found\n\n";
    } else {
        file.read((char * ) this, sizeof( * this));
        while (!file.eof()) {
            if (!strcmp(t, medid)) {
                //show();
                a = d * scost;
                count++;
            }
            file.read((char * ) this, sizeof( * this));
        }
        if (count == 0) {
            cout << "\n\n\t\t\tRecord Not Found\n\n";
        }
        file.close();
    }
    return a;
}
void medicine::sale() {
    medicine m;
    customer c;
    int b;
    int result1, result2;
    cout << "\n\t\t\tEnetr Medicne ID To be sold (Max 8 Digits):";
    cin.ignore();
    cin.getline(medid1, 8);
    m.medsearch(medid1);

    cout << "\n\t\t\tBill No.-";
    cin.ignore();
    cin.getline(bill, 9);
    cout << "\n\t\t\tCustomer ID-";
    cin.getline(customerid, 39);
    c.search_customer_sale(customerid);
    cout << "\t\t\tDate-";
    cin.getline(date1, 11);
    cout << "\n\t\t\tQuantity Want to Sale-";
    //b=quantity1;cin>>b;
    cin >> quantity1;
    cout << "\n\t\t\tAmount Paid By Customer-";
    amount = m.cost(quantity1, medid1);
    cout << amount;
}
void supplier::search_supplier_purchase(const char * t) //used in purchase from existing supplier
{
    int count = 0;
    ifstream file;
    file.open("supplier.dat", ios:: in | ios::binary);
    if (!file) {
        cout << "\n\n\t\t\tNo Data Found-";
    } else {
        file.read((char * ) this, sizeof( * this));
        while (!file.eof()) {
            if (!strcmp(t, supid)) {
                supplier_purchase_show();
                count++;
            }
            file.read((char * ) this, sizeof( * this));
        }
        if (count == 0) {
            cout << "\n\n\t\t\tSupplier Data  not found\n\n";
            cout << "\n\n\t\t\tDo You want to add a new supplier";
            cout << "\n\n\t\t\tY for Yes\t\t\tn for No";
            cout << "\n\n\t\t\tEnter Your Choice-";
            char choice;
            cin >> choice;
            switch (choice) {
            case 'y':
            case 'Y':
                supplier s;
                s.get_supplier_info();
                s.store_supplier_data();
                break;
            case 'n':
            case 'N':
                medicine1();
                break;
            default:
                cout << "\n\n\t\t\tEnter a Valid choice !!!!!";
                break;
            }
        }
        file.close();
    }
}
void medicine::pbillshow() {
    cout << "\n\n\t\t\t" << "Medicine ID: " << medid << "\t\t\t" << "Medicine Name: " << medname << "\n\n\t\t\t" << "Unit Cost: RS. " << ucost;
    cout << "\t\t\tAmount Paid: RS. " << amount1 << "\n\n\t\t\tQuantities Purchased: " << quantity << "\n\n\t\t\tDate of Purcahse: " << date;
    cout << "\n\n";
}
void medicine::purchasebillshow() {

    ifstream file;
    file.open("medicine.dat", ios:: in | ios::binary);
    if (!file) {
        cout << "\n\n\t\t\tFile not found\n\n";
    } else {
        file.read((char * ) this, sizeof( * this));
        while (!file.eof()) {
            pbillshow();
            file.read((char * ) this, sizeof( * this));
        }
        file.close();
    }
}

void medicine::purchase() {
    supplier s;
    //medicine m;
    cout << "\n\t\t\tMedicne ID (Max 8 Digits):";
    cin.ignore();
    cin.getline(medid, 8);
    cout << "\n\t\t\tMedicine Name-";
    cin.getline(medname, 39);
    cout << "\n\t\t\tRack No.-";
    cin.getline(rack, 9);
    cout << "\n\t\t\tCabnit No.-";
    cin.getline(cabnit, 9);
    cout << "\n\t\t\tCompany Name-";
    cin.getline(company, 39);
    cout << "\n\t\t\tSupplier ID-";
    cin.getline(supplierid, 39);
    s.search_supplier_purchase(supplierid);
    //cin.ignore();
    cout << "\n\t\t\tDate-";
    cin >> date;
    cout << "\n\t\t\tUnit Cost-";
    cin >> ucost;
    cout << "\n\t\t\tSale Cost-";
    cin >> scost;
    cout << "\n\t\t\t\tQuantity-";
    cin >> quantity;
    cout << "\n\t\t\tTotal Cost :";
    amount1 = ucost * quantity;
    cout << amount1;
    cin.ignore();
    cout << "\n\t\t\tMFG Date(dd-mm-yyyy)-";
    cin.getline(mfg, 11);
    cout << "\n\t\t\t\tEXP Date(dd-mm-yyyy)-";
    cin.getline(exp, 11);

}

void medicine1() {
    medicine m;
    int choice, c;
    char search[20];
    do {
        system("cls");
        cout << "\n\t\t\t------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t\t\tMEDICINE INFO\n";
        cout << "\t\t\t------------------------------------------------------------------------------\n";
        cout << "\n\n\t\t\t(1) Purchase\n\n\t\t\t(2) Sale\n\n\t\t\t(3) Back\n";
        cout << "\n\n\t\t\tEnter Your Choice-";
        cin >> choice;
        cout << "\n";
        switch (choice) {
        case 1:
            system("cls");
            cout << "\n\n\t\t\t------------------------------------------------------------------------------";
            cout << "\n\t\t\t\t\t\tPurchase Entry\n";
            cout << "\t\t\t------------------------------------------------------------------------------\n";
            m.purchase();
            m.store_medpurchase_data();
            cout << "\n\t\t\tData Entered Sucessfully !!!!!";
            cout << "\n\n\t\t\tPress Any key to continue.......";
            getch();
            break;
        case 2:
            system("cls");
            cout << "\n\n\t\t\t------------------------------------------------------------------------------";
            cout << "\n\t\t\t\t\t\tSales Entry\n";
            cout << "\t\t\t------------------------------------------------------------------------------\n";
            m.sale();
            m.store_medsale_data();
            cout << "\n\n\t\t\tData Entered Sucessfully !!!!!";
            cout << "\n\n\t\t\tPress Any key to continue.......";
            getch();
            break;
        case 3:
            system("cls");
            mainmenu();
            break;
        default:
            cout << "\n\t\t\t\t\tEnter a Valid Choice !!!!!\n";
            break;
        }
    } while (choice != 3);
}
void bills() {
    medicine m;
    int choice;
    do {
        system("cls");
        cout << "\n\t\t\t------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t\t\tBill Menu\n";
        cout << "\t\t\t------------------------------------------------------------------------------\n";
        cout << "\n\n\t\t\t(1) Purchase Bill\n\n\t\t\t(2) Sale Bill\n\n\t\t\t(3) Back\n\n\t\t\tEnter Your choice-";
        cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            cout << "\n\t\t\t------------------------------------------------------------------------------";
            cout << "\n\t\t\t\t\t\tPurchase Bill\n";
            cout << "\t\t\t------------------------------------------------------------------------------\n";
            m.purchasebillshow();
            cout << "\n\n\t\t\tPress any key to continue............";
            getch();
            break;
        case 2:
            system("cls");
            cout << "\n\t\t\t------------------------------------------------------------------------------";
            cout << "\n\t\t\t\t\t\tSale Bill\n";
            cout << "\t\t\t------------------------------------------------------------------------------\n";
            m.salesbillshow();
            cout << "\n\n\t\t\tPress any key to continue............";
            getch();
            break;
        case 3:
            system("cls");
            mainmenu();
            break;
        default:
            cout << "\n\n\t\t\tEnter A Valid Choice !!!!!";
            break;
        }
    } while (choice != 3);
}
void mainmenu() {
    medicine m;
    int choice;

    do {
        cout << "\n\t\t\t------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t\t\tMAIN MENU\n";
        cout << "\t\t\t------------------------------------------------------------------------------\n";
        cout << "\n\t\t\t1. SUPPLIER'S INFO\n\n\t\t\t2. CUSTOMER'S INFO\n\n\t\t\t3. MEDICINE\n\n\t\t\t4. BILL\n\n\t\t\t5.LOG OUT\n\n\t\t\tEnter Your Choice-";
        cin >> choice;
        cout << "\n";
        switch (choice) {
        case 1:
            supplier_info();
            break;
        case 2:
            customer_info();
            break;
        case 3:
            medicine1();
            break;
        case 4:
            bills();
            break;
        case 5:
            cout << "\n\t\t\tYou are sucessfully logged out...\n\n";
            exit(0);
            break;
        default:
            cout << "\n\t\t\t\t\tEnter a Valid Choice !!!!!\n";
            break;
        }
    } while (choice != 5);
}
void login() {
    cout << "\n\t\t\t------------------------------------------------------------------------------";
    cout << "\n\t\t\t\t\t\tWELCOME TO THE LOGIN PAGE\n";
    cout << "\t\t\t------------------------------------------------------------------------------\n";
    char username[8], pwd[8], c, ans;
    int i = 0;
    cout << "\n";
    cout << "\n\t\t\t\t\tENTER USERNAME-";
    gets(username);
    if (strcmp(username, "123") == 0) {
        cout << "\n\t\t\t\t\tENTER PASSWORD-";
        for (i = 0; i < 3; i++) {
            c = getch();
            pwd[i] = c;
            c = '*';
            cout << c;
        }
        pwd[i] = '\0';
        if (strcmp(pwd, "abc") == 0) {

            cout << "\n\n\t\t\t\t\tYou are sucessfully logged in...\n\n";
            sleep(2);
            system("cls");
        } else {

            cout << "\n\n\t\t\t\t\tWrong Password !!!!!\n";
            cout << "\n\n\t\t\tYou are automatically redirected to login page in 2 Seconds";
            sleep(2);
            system("cls");
            login();

        }
    } else {
        cout << "\n\n\t\t\t\t\twrong username !!!!!\n\n";
        cout << "\n\n\t\t\t\tYou are automatically redirected to login page in 2 Seconds";
        sleep(2);
        system("cls");
        login();

    }
}
main() {
    login();
    mainmenu();
}
