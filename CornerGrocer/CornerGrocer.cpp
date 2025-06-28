#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <limits>

using namespace std;

// GroceryTracker class encapsulates the logic to track item purchases from an input file
class GroceryTracker {
private:
	map<string, int> itemFrequencyMap; // Stores item names and their corresponding frequency counts

	// Reads items from a given file and populates the itemFrequencyMap
	void LoadItemsFromFile(const string& filename) {
		ifstream inFile(filename);
		string item;

		if (!inFile.is_open()) { // Handle file open failure
			cerr << "Error: Could not open input file." << endl;
			exit(1);
		}

		// Increment frequency count for each item read
		while (inFile >> item) {
			++itemFrequencyMap[item];
		}

		inFile.close(); // Close file after reading
	}

	// Writes the frequency data to a backup file for persistence
	void WriteFrequenciesToBackup(const string& backupFilename) {
		ofstream outFile(backupFilename);

		if (!outFile.is_open()) { // Handle file write failure
			cerr << "Error: Could not create backup file." << endl;
			return;
		}

		// Output each item and its count to the file
		for (const auto& pair : itemFrequencyMap) {
			outFile << pair.first << " " << pair.second << endl;
		}

		outFile.close(); // Close file after writing
	}

public:
	// Constructor initializes the map by reading input and writing backup
	GroceryTracker(const string& inputFilename, const string& backupFilename) {
		LoadItemsFromFile(inputFilename); // Populate frequency map
		WriteFrequenciesToBackup(backupFilename); // Save data to backup file
	}

	// Returns the frequency of a specific item, or 0 if not found
	int GetItemFrequency(const string& itemName) const {
		auto it = itemFrequencyMap.find(itemName);
		return (it != itemFrequencyMap.end()) ? it->second : 0;
	}

	// Outputs all item frequencies to the console
	void PrintAllItemFrequencies() const {
		for (const auto& pair : itemFrequencyMap) {
			cout << pair.first << " " << pair.second << endl;
		}
	}

	// Displays a histogram representing each item's frequency with asterisks
	void PrintHistogram() const {
		for (const auto& pair : itemFrequencyMap) {
			cout << setw(12) << left << pair.first << " ";
			for (int i = 0; i < pair.second; ++i) {
				cout << "*"; // Each asterisk represents one purchase
			}
			cout << endl;
		}
	}
};

// Displays the interactive menu options to the user
void DisplayMenu() {
	cout << "\nMenu:\n";
	cout << "1. Search for an item\n";
	cout << "2. Print all item frequencies\n";
	cout << "3. Print histogram of items\n";
	cout << "4. Exit\n";
	cout << "Choose an option (1-4): ";
}

int main() {
	// Instantiate GroceryTracker with input file and backup file names
	GroceryTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");
	int choice; // User menu selection
	string userItem; // Item entered by user for lookup

	// Infinite loop for menu interaction until user chooses to exit
	while (true) {
		DisplayMenu(); // Show menu
		cin >> choice; // Get user choice

		// Validate user input is numeric
		if (cin.fail()) {
			cin.clear(); // Clear error flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
			cout << "Invalid input. Please enter a number from 1 - 4 \n";
			continue;
		}

		// Handle user's menu choice
		switch (choice) {
		case 1:
			cout << "Enter item name: ";
			cin >> userItem; // Get item to search
			// Display frequency of the item
			cout << userItem << " was purchased " << tracker.GetItemFrequency(userItem) << " times.\n";
			break;
		case 2:
			// Print all items with their frequencies
			tracker.PrintAllItemFrequencies();
			break;
		case 3:
			// Display a histogram showing frequency of each item
			tracker.PrintHistogram();
			break;
		case 4:
			// Exit the program
			cout << "Exiting program...\n";
			return 0;
		default:
			// Handle invalid menu option
			cout << "Invalid option. Please choose between 1 and 4.\n";
		}
	}

	return 0; // Program should never reach here due to infinite loop
}
