GroceryTracker is a command-line application designed to help users record, view, and analyze their purchases. It solves the common problem of lost receipts and unclear spending habits by offering a simple, text-based interface to track items, prices, dates and categories, allowing users to quickly review what has been bought and how much they've spent over time.

- WHAT THE PROJECT DOES WELL
- Used encapsulation via a GroceryTracker class to cleanly separate data management from user interaction.
- Clear logic for reading, processing, and outputting frequency data
- Provided good error handling for file operations and user input (e.g., using cin.fail() and numeric_limits).
- Cleanly structured methods like LoadItemsFromFile, WriteFrequenciesToBackup, and PrintHistogram.

- AREAS FOR IMPROVEMENT AND IMPACT
- Data validation and error handling: Add more rigorous checks for date formats, price values, and required fields to help avoid corruption or crashes and improve reliability
- Separation of concerns: Move menu logic to its own function/class to improve modularity and make the program easier to expand
- Dynamic file inputs: Allow user to specify input/output file paths to add flexibility for reuse
- Case insensitive item search: normalize input using transform() to prevent duplicate item counts to capitalization differences
- Unit testing support: Modularize LoadItemsFromFile and make it testable with mock data

- CHALLENGING PARTS I OVERCAME
- Ensuring input validation for menu options (handled via cin.fail() and clearing the stream).
- Displaying a formatted histogram using setw() and loops
- Managing file I/O while handling possible failures

- TOOLS AND RESOURCES REFLECTED
- Standard Template Library (map, string, fstream) to manage input and output
- iomanip and limits for clean formatting and safe input handling

- TRANSFERABLE SKILLS
- Working with file input/output and handling edge cases
- Using associative containers like map to count frequencies
- Menu-driven console interaction logic
- Writing modular and well-documented code, which is critical in object-oriented programming and real-world applications

- CODE MAINTAINABILITY AND READABILITY
- Features descriptive comments and uses clear method names for readability
- Features consistent indentation and naming conventions
- By encapsulating logic in methods, the program is easy to modify or extend later
