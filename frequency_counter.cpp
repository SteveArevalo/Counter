#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class FrequencyCounter {
private:
    map<string, int> frequencyMap; // Map to store word frequencies

public:
    // Constructor to initialize the FrequencyCounter
    FrequencyCounter() {}

    // Method to count frequencies of words in the input file
    void countFrequencies(const string& inputFilename) {
        ifstream inputFile(inputFilename); // Open the input file
        if (!inputFile.is_open()) { // Check if the file is successfully opened
            cerr << "Error opening file: " << inputFilename << endl; // Display error message if file opening fails
            return; // Return if file opening fails
        }

        string word;
        while (inputFile >> word) { // Read words from file until end-of-file is reached
            frequencyMap[word]++; // Increment the frequency count of each word
        }

        inputFile.close(); // Close the input file
    }

    // Method to write frequencies to a file for backup
    void writeFrequenciesToFile(const string& outputFilename) const {
        ofstream outputFile(outputFilename); // Open the output file
        if (!outputFile.is_open()) { // Check if the file is successfully opened
            cerr << "Error opening file: " << outputFilename << endl; // Display error message if file opening fails
            return; // Return if file opening fails
        }

        for (const auto& pair : frequencyMap) { // Iterate over each pair in the frequency map
            outputFile << pair.first << " " << pair.second << endl; // Write the word and its frequency to the output file
        }

        outputFile.close(); // Close the output file
    }
    
    // Method to get the frequency of a specific word
    int getFrequency(const string& item) const {
        auto it = frequencyMap.find(item); // Search for the word in the frequency map
        return (it != frequencyMap.end()) ? it->second : 0; // Return its frequency if found, otherwise return 0
    }

    // Method to print all word frequencies
    void printFrequencies() const {
        for (const auto& pair : frequencyMap) { // Iterate over each pair in the frequency map
            cout << pair.first << " " << pair.second << endl; // Print the word and its frequency
        }
    }

    // Method to print a histogram representing word frequencies
    void printHistogram() const {
        for (const auto& pair : frequencyMap) { // Iterate over each pair in the frequency map
            cout << pair.first << " "; // Print the word
            cout << string(pair.second, '*') << endl; // Print '*' character representing the frequency
        }
    }
    
    // Method to display the main menu
    void displayMenu() const {
        cout << "Menu:" << endl;
        cout << "1. Search for item and get frequency" << endl;
        cout << "2. Print frequency of all items" << endl;
        cout << "3. Print histogram" << endl;
        cout << "4. Exit" << endl;
    }
};

int main() {

    string inputFilename = "CS210_Project_Three_Input_File.txt"; // Input filename
    string outputFilename = "frequency.dat"; // Output filename for backup

    FrequencyCounter counter;
    counter.countFrequencies(inputFilename); // Count frequencies of words in the input file
    counter.writeFrequenciesToFile(outputFilename); // Write frequencies to output file for backup

    // Main menu loop
    int choice = 0;
    while (choice != 4) {
        counter.displayMenu(); // Display the main menu

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string item;
                cout << "Enter item to search for: ";
                cin >> item;
                int frequency = counter.getFrequency(item);
                cout << "Frequency of " << item << ": " << frequency << endl;
                break;
            }
            case 2: {
                cout << "\nQUANTITY OF EACH ITEM PURCHASED TODAY:\n";
                counter.printFrequencies();
                cout << endl;
                break;
            }
            case 3: {
                cout << "\nHISTOGRAM\n";
                counter.printHistogram();
                cout << endl;
                break;
            }
            case 4: {
                cout << "Exiting program" << endl;
                break; // Exit the loop
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
}
