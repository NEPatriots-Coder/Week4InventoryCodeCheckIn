#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream> // for std::ostringstream

// A struct, I feel is the best way to group these related variables together.

struct inventoryItem
{
    std::string Product_ID;
    std::string Product_Name;
    std::string Category;
    std::string Sub_Category;
    double price = {};
    int quantity = {};
};
//Function to Dispaly all items in Inventory:
void printInventory(const std::vector<inventoryItem>& inventory)
{
    for (const auto& item : inventory)
    {
        std::cout << "Product ID: " << item.Product_ID << std::endl;
        std::cout << "Product Name: " << item.Product_Name << std::endl;
        std::cout << "Category: " << item.Category << std::endl;
        std::cout << "Sub-Category: " << item.Sub_Category << std::endl;
        std::cout << "Price: " << item.price << std::endl;
        std::cout << "Quantity: " << item.quantity << std::endl;
        std::cout << std::endl;
    }
}

// CRUD OPERATIONS

void addItem(std::vector<inventoryItem>& inventory, const inventoryItem& newItem)
{
    inventory.push_back(newItem);
}
//This function deleteItem accepts a reference to a vector of inventoryItem objects,
// and a reference to a Product_ID string. It removes any inventoryItem object from the vector with a
// matching Product_ID.

void deleteItem(std::vector<inventoryItem>& inventory, const std::string& Product_ID)
{
    for (auto it = inventory.begin(); it != inventory.end(); ++it)
    {
        if (it ->Product_ID == Product_ID)
        {
            inventory.erase(it);
            break;
        }
    }
}

void updatePrice(std::vector<inventoryItem>& inventory, const std::string& Product_ID, double newPrice)
{
    for (auto&item : inventory)
    {
        if (item.Product_ID == Product_ID)
        {
            item.price = newPrice;
            std::ostringstream  oss;
            oss << "Updated Product Name: " << item.Product_Name << "\nNew Price: " << item.price;
            std::cout << oss.str() << std::endl;
            break;
        }
    }
};
void updateQuantity(std::vector<inventoryItem>& inventory, const std::string& ProductID, int newQuantity)
{
    for (auto& item : inventory)
    {
        if (item.Product_ID == ProductID)
        {
            item.quantity = newQuantity;
            std::ostringstream  oss;
            oss << "Updated Product Name: " << item.Product_Name << "\nNew Quantity: " << item.quantity;
            std::cout << oss.str() << std::endl;
            break;
        }
    }
}

int main()
{
    // Manually populate Inventory -- Use SQL functionality-- Import CSV
    std::vector<inventoryItem> inventory = {
            {"001", "Tractor", "Machinery", "Farm", 15000.00, 5},
            {"002", "Plow", "Machinery", "Farm", 2500.99, 10},
            {"003", "Sprayer", "Machinery", "Farm", 25000.00, 4},
            {"004", "Seeder", "Machinery", "Farm", 5000.00, 8},
            {"005", "Harvester", "Machinery", "Farming", 22000.00, 15}

    };
    std::cout << "Initial Inventory:\n";
    printInventory(inventory);
    std::cout << std::endl;

    inventoryItem newItem = {"004", "Harvester", "Machinery", "Farm", 40000.0, 2};
    addItem(inventory, newItem);
    std::cout << "After Adding New Item:\n";
    printInventory(inventory);

    updatePrice(inventory, "003", 1300.0);
    std::cout << "After Updating Price of Product ID 003:\n";
    printInventory(inventory);

    updateQuantity(inventory, "002", 20);
    std::cout << "After Updating Quantity of Product ID 002:\n";
    printInventory(inventory);

    deleteItem(inventory, "001");
    std::cout << "After Deleting Product ID 001:\n";
    printInventory(inventory);




   return 0;
}
