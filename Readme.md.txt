Inventory Management System
This is a C++ program that implements an inventory management system using doubly linked lists. It organizes inventory data hierarchically across cities, stores, sections, and items, allowing users to add, remove, and display items through a menu-driven interface.
Features include:

Add a new store to a city
Add a new section to a store
Add an item to a specific section
Remove an item from a section
Display all items in a specific section
Display all items across all stores and sections
Exit the program

Requirements:

A C++ compiler (e.g., g++ supporting C++11 or later)
A C++-compatible IDE or command-line environment

Installation:

Clone or download this repository to your local machine
Navigate to the project directory
Compile the C++ code:g++ InventoryManagement.cpp -o InventoryManagement


Run the program:./InventoryManagement



Usage:Run the program, and you will see a menu:
===== Inventory Management System =====
1. Add a new Section
2. Add an Item
3. Remove an Item
4. Display all Items of a Section
5. Display all Items of a Store
6. Exit
Enter your choice:

Enter a number (1-6) to select an option. Follow the prompts to input store, section, or item names. The program initializes with a city containing two stores ("SuperMart" and "MegaStore"), with "SuperMart" having three sections ("Groceries," "Fruits," "Sports") and predefined items (e.g., "Rice," "Apple," "Football").
Example Commands:

To add a section: Choose 1, enter a section name (e.g., "Electronics")
To add an item: Choose 2, enter a section name (e.g., "Groceries") and item name (e.g., "Oil")
To remove an item: Choose 3, enter a section name (e.g., "Fruits") and item name (e.g., "Banana")
To display section items: Choose 4, enter a section name (e.g., "Sports")
To display all items: Choose 5
To exit: Choose 6

Implementation Details:The program uses doubly linked lists to manage a hierarchical structure:

City: Contains a list of stores
Store: Contains a list of sections
Section: Contains a list of items
Item: Stores the item nameEach node (city, store, section, item) has pointers to the next and previous nodes, enabling efficient traversal and modification. The program initializes with sample data for testing, including stores, sections, and items. User inputs are validated to ensure sections and items exist before performing operations.

Limitations:

Limited to one city; additional cities require manual extension
No persistent storage; data is lost when the program exits
Case-sensitive input for section and item names
No support for duplicate section or item names

Contributing:Feel free to fork this repository, make improvements, and submit pull requests. Suggestions for new features or bug fixes are welcome!
License:This project is licensed under the MIT License. See the LICENSE file for details.
Contact:For questions or feedback, please open an issue on this repository.
