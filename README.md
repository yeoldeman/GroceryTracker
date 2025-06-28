This C++ program, titled GroceryTracker, is designed to read a list of grocery item purchases from a file, 
track their frequency, and offer users an interactive menu to explore that data. The heart of the program is the 
GroceryTracker class, which encapsulates functionality to read data from a text file, maintain item frequency counts 
using a std::map, and provide reporting features including a histogram. The constructor accepts two filenames: one for input
(CS210_Project_Three_Input_File.txt) and one for backup (frequency.dat). Internally, the LoadItemsFromFile() method populates 
the frequency map, while WriteFrequenciesToBackup() saves a copy for persistence. Key public methods include GetItemFrequency(),
which returns how often a given item appears, PrintAllItemFrequencies() for listing all item counts, and PrintHistogram(), which
graphically represents purchase frequency using asterisks. In main(), the program presents an interactive text-based menu allowing
users to search for an item, display all item frequencies, or view the histogram. Input validation is handled using cin.fail() and numeric_limits 
to ensure robustness. The use of object oriented programming keeps data and functionality modular, while the map ensures efficient lookups and 
sorting by item name. The development approach emphasizes clean separation of concerns, reusability and maintainability. Overall, the program 
demonstrates practical use of C++ fundamentals including file I/O, containers, input validation, and class design. It provides a scalable and 
user-friendly way to analyze item frequency data from grocery transactions, making it suitable for expansion into more complex inventory or
sales tracking systems.
