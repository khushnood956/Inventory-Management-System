#include <iostream>
using namespace std;

struct items {
    string itemName;
    items* next;
    items* prev;
};

struct Section {
    string Location;
    items* itemF = NULL;
    items* itemL = NULL;
    Section* next;
    Section* prev;
};

struct store {
    string SectionName;
    Section* SectF = NULL;
    Section* SectL = NULL;
    store* next;
    store* prev;
};

struct City {
    string StoreName;
    store* StoreF = NULL;
    store* StoreL = NULL;
    City* next;
    City* prev;
};
City* first = NULL;
City* last = NULL;

void AddSection() {
    cout << "Enter Section name: ";
    string a;
    cin >> a;
    
    Section* newS = new Section();
    newS->Location = a;
    newS->next = newS->prev = NULL;
    
    if(first == NULL) {
        cout << "Store not found .. " << endl;
        return;
    }
    
    store* TempS = first->StoreF;
    if(TempS == NULL) {
        cout << "Store not found create first.. " << endl; 
        return;
    }
    
    if(TempS->SectF == NULL) {
        TempS->SectF = TempS->SectL = newS;
    } else {
        TempS->SectL->next = newS;
        newS->prev = TempS->SectL;
        TempS->SectL = newS;
    }
    cout << "Section Successfully added" << endl;
}

void AddStore() {
    cout << "Enter Store name: ";
    string name;
    cin >> name;

    store* newStore = new store();
    newStore->SectionName = name;
    newStore->SectF = newStore->SectL = NULL;
    newStore->next = newStore->prev = NULL;

    if (first == NULL) {
        first = last = new City();
        first->StoreName = name;
        first->StoreF = first->StoreL = newStore;
    } else {
        last->next = new City();
        last->next->prev = last;
        last = last->next;
        last->StoreName = name;
        last->StoreF = last->StoreL = newStore;
    }
    cout << "Store added successfully!" << endl;
}

void addItem() {
    string itemN, sectN;
    cout << "enter the name of section: ";
    cin >> sectN;
    
    Section* sec = first->StoreF->SectF;
    while(sec != NULL && sec->Location != sectN) {
        sec = sec->next;
    }
    if(!sec) {
        cout << "section not found .. " << endl; 
        return;
    }
    
    cout << "enter item name: ";
    cin >> itemN;
    
    items* nItem = new items();
    nItem->itemName = itemN;
    nItem->next = nItem->prev = NULL;
    
    if(sec->itemF == NULL) {
        sec->itemF = sec->itemL = nItem;
    } else {
        sec->itemL->next = nItem;
        nItem->prev = sec->itemL;
        sec->itemL = nItem;
    }
    cout << "Item added sucessfully ... " << endl;
}

void DisplaySectItems() {
    cout << "Enter section name: ";
    string secName;
    cin >> secName;
    
    Section* sec = first->StoreF->SectF;
    
    while (sec != NULL && sec->Location != secName) {
        sec = sec->next;
    }
    
    if(!sec) {
        cout << "section not found.." << endl;
        return;
    }
    items* it = sec->itemF;
    if(it == NULL) {
        cout << "no items found in this section "<<endl;
        return;
    }
    cout << "items in: " << sec->Location << ":\n";
    while(it != NULL) {
        cout << "~ " << it->itemName << endl;
        it = it->next;
    }
}

void DisplayAll() {
    if (first == NULL) {
        cout << "No stores exist." << endl;
        return;
    }
    
    store* tStore = first->StoreF;
    while(tStore != NULL) {
        cout << "Store: " << tStore->SectionName << endl;
        Section* tSec = tStore->SectF;
        while(tSec != NULL) {
            cout << "Section: " << tSec->Location << endl;
            items* tItems = tSec->itemF;
            while(tItems != NULL) {
                cout << "~ " << tItems->itemName << endl;
                tItems = tItems->next;
            }
            tSec = tSec->next;
        }   
        tStore = tStore->next;
    }
}

void DeleteItem() {
    string secName, itemName;
    cout << "Enter Section Name: ";
    cin >> secName;
    cout << "Enter Item Name: ";
    cin >> itemName;
    
    Section* sec = first->StoreF->SectF;
    while(sec != NULL && sec->Location != secName) {
        sec = sec->next;
    }
    if (sec == NULL) {
        cout << "Section not found!" << endl;
        return;
    }
    
    items* it = sec->itemF;
    while(it != NULL && it->itemName != itemName) {
        it = it->next;
    }
    
    if(it == NULL) {
        cout << "item not found .. " << endl;
        return;
    } else {
        if(it->prev != NULL) it->prev->next = it->next;
        if(it->next != NULL) it->next->prev = it->prev;
        
        if(it == sec->itemF) sec->itemF = it->next;
        if(it == sec->itemL) sec->itemL = it->prev;
        
        delete it;
        cout << "deleted successfully .." << endl;
    }
}

int main() {
    // Creating initial structure without arrays
    City* city = new City();
    city->StoreName = "City Mart";
    city->StoreF = city->StoreL = new store();
    city->StoreF->SectionName = "SuperMart";
    city->StoreF->SectF = city->StoreF->SectL = NULL;
    first = last = city;
    
    store* store2 = new store();
    store2->SectionName = "MegaStore";
    store2->SectF = store2->SectL = NULL;
    city->StoreF->next = store2;
    store2->prev = city->StoreF;
    city->StoreL = store2;
    
    // Adding sections
    Section* groceries = new Section();
    groceries->Location = "Groceries";
    groceries->next = groceries->prev = NULL;
    city->StoreF->SectF = city->StoreF->SectL = groceries;
    
    Section* fruits = new Section();
    fruits->Location = "Fruits";
    fruits->next = fruits->prev = NULL;
    groceries->next = fruits;
    fruits->prev = groceries;
    
    Section* sports = new Section();
    sports->Location = "Sports";
    sports->next = sports->prev = NULL;
    fruits->next = sports;
    sports->prev = fruits;
    city->StoreF->SectL = sports;
    
    // Adding grocery items individually
    items* rice = new items();
    rice->itemName = "Rice";
    rice->next = rice->prev = NULL;
    groceries->itemF = groceries->itemL = rice;
    
    items* sugar = new items();
    sugar->itemName = "Sugar";
    sugar->next = sugar->prev = NULL;
    rice->next = sugar;
    sugar->prev = rice;
    groceries->itemL = sugar;
    
    items* flour = new items();
    flour->itemName = "Flour";
    flour->next = flour->prev = NULL;
    sugar->next = flour;
    flour->prev = sugar;
    groceries->itemL = flour;
    
    items* salt = new items();
    salt->itemName = "Salt";
    salt->next = salt->prev = NULL;
    flour->next = salt;
    salt->prev = flour;
    groceries->itemL = salt;
    
    // Adding fruit items individually
    items* apple = new items();
    apple->itemName = "Apple";
    apple->next = apple->prev = NULL;
    fruits->itemF = fruits->itemL = apple;
    
    items* banana = new items();
    banana->itemName = "Banana";
    banana->next = banana->prev = NULL;
    apple->next = banana;
    banana->prev = apple;
    fruits->itemL = banana;
    
    items* orange = new items();
    orange->itemName = "Orange";
    orange->next = orange->prev = NULL;
    banana->next = orange;
    orange->prev = banana;
    fruits->itemL = orange;
    
    items* mango = new items();
    mango->itemName = "Mango";
    mango->next = mango->prev = NULL;
    orange->next = mango;
    mango->prev = orange;
    fruits->itemL = mango;
    
    // Adding sports items individually
    items* football = new items();
    football->itemName = "Football";
    football->next = football->prev = NULL;
    sports->itemF = sports->itemL = football;
    
    items* cricket = new items();
    cricket->itemName = "Cricket Bat";
    cricket->next = cricket->prev = NULL;
    football->next = cricket;
    cricket->prev = football;
    sports->itemL = cricket;
    
    items* tennis = new items();
    tennis->itemName = "Tennis Racket";
    tennis->next = tennis->prev = NULL;
    cricket->next = tennis;
    tennis->prev = cricket;
    sports->itemL = tennis;
    
    items* basketball = new items();
    basketball->itemName = "Basketball";
    basketball->next = basketball->prev = NULL;
    tennis->next = basketball;
    basketball->prev = tennis;
    sports->itemL = basketball;
    
    while (true) {
        cout << "\n===== Inventory Management System =====" << endl;
        cout << "1. Add a new Section" << endl;
        cout << "2. Add an Item" << endl;
        cout << "3. Remove an Item" << endl;
        cout << "4. Display all Items of a Section" << endl;
        cout << "5. Display all Items of a Store" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                AddSection();
                break;
            case 2:
                addItem();
                break;
            case 3:
                DeleteItem();
                break;
            case 4:
                DisplaySectItems();
                break;
            case 5:
                DisplayAll();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    }
    
    return 0;
}
