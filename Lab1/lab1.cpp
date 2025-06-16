#include <iostream>
#include <random>
#include <cmath>
#include <limits>
#include <string>
#include <sstream>

// Function to validate and read an integer in range
int getValidatedInput(const std::string& prompt, int min, int max) {
    int value;
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        std::stringstream ss(input);
        if (ss >> value && !(ss >> input) && value >= min && value <= max)
            return value;
        std::cout << "Invalid input. Please enter an integer between " << min << " and " << max << ".\n";
    }
}

// Function to generate a random integer in range
int getRandomInt(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(gen);
}

// Function to calculate distance to origin
double distanceToOrigin(int x, int y) {
    return std::sqrt(x * x + y * y);
}

int main() {
    char choice;
    do {
        int x1, y1, x2, y2;

        std::cout << "\nWould you like to (E)nter coordinates or (G)enerate them randomly? (E/G): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear input buffer

        if (choice == 'E' || choice == 'e') {
            x1 = getValidatedInput("Enter x1 (-10 to 10): ", -10, 10);
            y1 = getValidatedInput("Enter y1 (-10 to 10): ", -10, 10);
            x2 = getValidatedInput("Enter x2 (-10 to 10): ", -10, 10);
            y2 = getValidatedInput("Enter y2 (-10 to 10): ", -10, 10);
        }
        else {
            x1 = getRandomInt(-10, 10);
            y1 = getRandomInt(-10, 10);
            x2 = getRandomInt(-10, 10);
            y2 = getRandomInt(-10, 10);
            std::cout << "Generated coordinates:\n";
        }

        double d1 = distanceToOrigin(x1, y1);
        double d2 = distanceToOrigin(x2, y2);

        std::cout << "Point 1: (" << x1 << ", " << y1 << ") - Distance to origin: " << d1 << "\n";
        std::cout << "Point 2: (" << x2 << ", " << y2 << ") - Distance to origin: " << d2 << "\n";

        if (d1 < d2) {
            std::cout << "Point 1 is closer to the origin.\n";
        }
        else if (d2 < d1) {
            std::cout << "Point 2 is closer to the origin.\n";
        }
        else {
            std::cout << "Both points are equally distant from the origin.\n";
        }

        std::cout << "\nWould you like to run again? (Y/N): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer
    } while (choice == 'Y' || choice == 'y');

    std::cout << "Goodbye!\n";
    return 0;
}
