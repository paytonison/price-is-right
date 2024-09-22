#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

struct Item {
    std::string name;
    double price;
};

int main() {
    // Seed for random number generation
    std::random_device rd;
    std::mt19937 gen(rd());

    // List of items with their prices
    std::vector<Item> items = {
        {"Toaster", 19.99},
        {"Blender", 49.99},
        {"Microwave Oven", 89.99},
        {"Vacuum Cleaner", 129.99},
        {"Coffee Maker", 39.99},
        {"Smartphone", 699.99},
        {"Laptop", 999.99},
        {"Headphones", 199.99},
        {"Smart Watch", 249.99},
        {"Tablet", 329.99}
    };

    // Select a random item
    std::uniform_int_distribution<> itemDist(0, items.size() - 1);
    Item selectedItem = items[itemDist(gen)];

    // Generate price options
    std::vector<double> priceOptions;
    priceOptions.push_back(selectedItem.price); // Correct price

    // Generate three incorrect prices
    std::uniform_real_distribution<> priceVariance(-0.5, 0.5);
    while (priceOptions.size() < 4) {
        double variance = priceVariance(gen);
        double incorrectPrice = selectedItem.price + (selectedItem.price * variance);

        // Round to two decimal places
        incorrectPrice = std::round(incorrectPrice * 100.0) / 100.0;

        // Ensure the incorrect price is not equal to the correct price and not already in the list
        if (incorrectPrice != selectedItem.price &&
            std::find(priceOptions.begin(), priceOptions.end(), incorrectPrice) == priceOptions.end()) {
            priceOptions.push_back(incorrectPrice);
        }
    }

    // Shuffle the price options
    std::shuffle(priceOptions.begin(), priceOptions.end(), gen);

    // Display the game prompt
    std::cout << "Guess the correct price of the following item:\n";
    std::cout << "Item: " << selectedItem.name << "\n\n";
    std::cout << "Price Options:\n";
    for (size_t i = 0; i < priceOptions.size(); ++i) {
        std::cout << i + 1 << ") $" << priceOptions[i] << "\n";
    }

    // Get player's guess
    int choice;
    std::cout << "\nEnter the number corresponding to your guess: ";
    std::cin >> choice;

    // Validate input
    if (choice < 1 || choice > static_cast<int>(priceOptions.size())) {
        std::cout << "Invalid choice. Please run the program again.\n";
        return 1;
    }

    // Check if the guess is correct
    if (priceOptions[choice - 1] == selectedItem.price) {
        std::cout << "Congratulations! You guessed the correct price.\n";
    } else {
        std::cout << "Sorry, that's incorrect. The correct price was $" << selectedItem.price << ".\n";
    }

    return 0;
}

