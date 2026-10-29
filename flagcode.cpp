#include <iostream>
#include <string>
#include <vector>

// Feature flags
struct FeatureFlags {
    bool showWelcome;
    bool darkMode;
    bool newDashboard;
    bool oldReport;
    bool betaSearch;
    bool discountBanner;
};

const FeatureFlags FEATURE_FLAGS = {
    true,   // showWelcome
    true,   // darkMode
    true,   // newDashboard
    false,  // oldReport
    false,  // betaSearch
    true    // discountBanner
};

// Function prototypes
void welcome(const std::string& name);
void enableDarkMode();
void showDashboard();
void showSummary();
void showOldReport();
void generateOldReport();
std::vector<std::string> betaSearch(const std::string& query);
std::vector<std::string> performSearch(const std::string& query);
void showDiscount();
int calculateTotal(int price, int quantity);
void logActivity(const std::string& message);

void welcome(const std::string& name) {
    if (FEATURE_FLAGS.showWelcome) {
        std::cout << "Welcome, " + name << std::endl;
    }
}

void enableDarkMode() {
    if (FEATURE_FLAGS.darkMode) {
        std::cout << "Dark mode enabled" << std::endl;
    }
}

void showDashboard() {
    if (FEATURE_FLAGS.newDashboard) {
        std::cout << "Showing new dashboard" << std::endl;
        showSummary();
    }
}

void showSummary() {
    std::cout << "You have 5 tasks remaining" << std::endl;
}

// Old report feature
void showOldReport() {
    if (FEATURE_FLAGS.oldReport) {
        std::cout << "Showing old report" << std::endl;
        generateOldReport();
    }
}

void generateOldReport() {
    std::cout << "Generating old report" << std::endl;
}

// Beta search feature
std::vector<std::string> betaSearch(const std::string& query) {
    if (FEATURE_FLAGS.betaSearch) {
        std::cout << "Searching for " + query << std::endl;
        return performSearch(query);
    }
    return {};
}

std::vector<std::string> performSearch(const std::string& query) {
    std::cout << "Search completed for " + query << std::endl;
    return {"Result 1", "Result 2"};
}

// Discount feature
void showDiscount() {
    if (FEATURE_FLAGS.discountBanner) {
        std::cout << "Get 10% discount today!" << std::endl;
    }
}

int calculateTotal(int price, int quantity) {
    return price * quantity;
}

void logActivity(const std::string& message) {
    std::cout << "Activity: " + message << std::endl;
}

// Main program
int main() {
    welcome("Anu");
    enableDarkMode();
    showDashboard();
    showDiscount();

    betaSearch("JavaScript");
    logActivity("User opened dashboard");

    std::cout << "Total: " << calculateTotal(100, 2) << std::endl;

    return 0;
}
