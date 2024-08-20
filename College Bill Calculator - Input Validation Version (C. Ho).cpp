// Description: This is an improvement of the lab done before, 
// https://bhcc.digication.com/cit120all_master_delta/College_Bill_Calculator.
// This program reviews previous learning outcomes:
//		customizing the cmp window,
//		naming constant variables,
//		printing a centered banner using the WYSIWYG approach,
//		strings,
//		using functions and methods that work with cin,
//		if statements,
//		if ... else statements,
//		logical operators,
//		conditional operators; 
// illustrates Chapter 5 learning outcomes:
//		input validation using a while loop;
// and contains other minor UX improvements such as:
//		formatting the output with comma separators for the thousands,
//		beeping,
//		changing the color of the monitor to draw the user's attention, and
//		resetting the cmp color to normal after the error situation is corrected.
// Instruction files: 
//		https://bhcc.digication.com/cit120all_master_delta/College_Bill_Calculator_-_Input_Validation_version,
//		https://bhcc.digication.com/cit120all_master_delta/switch_case_style_points1,
//		https://bhcc.digication.com/cit120all_master_delta/the_setfill_manipulator
// Title: College Bill Calculator - Input Validation Version
// Programmer: C. Ho
// Last Modified: Tue. Oct. 31, 2023 @ 5:24 PM

// PREPROCESSOR DIRECTIVE SECTION
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// FUNCTION DECLARATION SECTION, INCLUDING FUNCTION PROTOTYPES - N/A IN THIS LAB

// MAIN SECTION
int main()
{
	// SET UP SECTION
	// System function call to change text in title bar
	system("title Constant Variables, cin Functions + Methods, if + if ... else Statements, Logical Operators, and Conditional Operators     by C. Ho");

	// System function call to change the color of the cmp window (background, foreground)
	system("color E1");

	// Centered banner using the WYSIWYG approach
	cout << "\n"
		<< "\t\t\t                        College Bill Calculator                      \n"
		<< "\t\t\t                Make sure you test EVERY possible input.             \n"
		<< "\t\t\t       Not as easy as it looks - the devil is in the details!        \n"
		<< "\t\t\t                   Compensate for user's extra input.                \n"
		<< "\t\t\t Make sure you follow all the learning outcomes of the previous lab. \n"
		<< "\t\t\t                                Lab #4                               \n"
		<< "\t\t\t                               by C. Ho                              \n\n";

	// Hints about typing
	cout << "\n"
		<< "Hints:\n"
		<< "  To reduce typing time you can copy and paste my prompts from the exe.\n"
		<< "  You need to use the WYSIWYG approach in many places!\n";

	// Hints about constant variables
	cout << "\n"
		<< "You MUST have and appropriately use the following as const variables:\n"
		<< "  in-state tuition       $ 3,000\n"
		<< "  out-of-state tuition   $ 5,000\n"
		<< "  international tuition  $ 6,700\n"
		<< "  private room charge    $ 8,000\n"
		<< "  discount per roommate  $ 1,000.\n";

	// Hints about validation constraints
	cout << "\n"
		<< "To make sure you practice more learning outcomes, make sure that\n"
		<< "  for checking the residency validity, you do NOT use < or <= or >=; and\n"
		<< "  for checking the housing preference validity, you do NOT use !=.\n\n";

	// VARIABLE DECLARATION SECTION
	string name;
	int residencyStatus, housingPreference, numberOfRoommates, boardDiscount, tuition, board;

	// Constants for tuition rates
	const int
		IN_STATE_TUITION = 3'000,
		OUT_OF_STATE_TUITION = 5'000,
		INTERNATIONAL_TUITION = 6'700;
	
	// Constants for room charges
	const int
		PRIVATE_ROOM_CHARGE = 8'000,
		ROOMMATE_DISCOUNT = 1'000;

	// INPUT SECTION
	// Get the user's name.
	cout << "Please enter your full name: ";
	getline(cin, name);		// Allow names with spaces.

	// Prompt the user to enter residency status.
	cout << "\n"
		<< "What is your residency status, \"" << name << "\"?\n"
		<< "  Residency status choices:  \n"
		<< "    1] In state              \n"
		<< "    2] Out of state          \n"
		<< "    3] International         \n";

	// Get the user's residency status.
	cout << "  Enter your choice [1, 2 or 3]: ";
	cin >> residencyStatus;
	cin.ignore(1000, '\n');	// Remove data from input buffer.

	// Validate residency choice.
	while (residencyStatus != 1 && residencyStatus != 2 && residencyStatus != 3 || static_cast<int>(residencyStatus) != residencyStatus)
	{
		// Change color of window background and text.
		system("color C7");

		// Alert user with a beep.
		cout << "\a";

		// Display error message.
		cout << "\n   xxx   You entered an illegal residency choice   xxx";
		// Display detailed input hint to user.
		cout << (residencyStatus < 1 || residencyStatus > 3 ? "\n   Valid residency status choices must be between 1 and 3." : "");
		cout << (static_cast<int>(residencyStatus) == residencyStatus ? "" : "\n   Residency status MUST be an integer.") << "\n";

		// Prompt user to enter a valid residency status.
		cout << "\n   Please enter a valid residency status: ";
		cin >> residencyStatus;
		cin.ignore(1000, '\n');	// Remove data from input buffer.
	}

	// Prompt the user to enter housing preference.
	cout << "\n"
		<< "What is your housing preference, \"" << name << "\"?\n"
		<< "  Housing choices:        \n"
		<< "    1]  Single room dorm  \n"
		<< "    2]  Double room dorm  \n"
		<< "    3]  Triple room dorm  \n"
		<< "    4]  Quad room dorm    \n"
		<< "    5]  Live off campus   \n";

	// Get the user's housing choice.
	cout << "  Enter your choice [1 to 5]: ";
	cin >> housingPreference;
	cin.ignore(1000, '\n');		// Remove data from input buffer.

	// Validate housing choice. 
	while (housingPreference < 1 || housingPreference > 5 || housingPreference - static_cast<int>(housingPreference) != 0)
	{
		// Change color of window background and text.
		system("color C7");

		// Alert user with a beep.
		cout << "\a";

		// Display error message.
		cout << "\n   xxx   You entered an illegal housing choice   xxx";
		// Display detailed input hint to user.
		cout << (housingPreference < 1 || housingPreference > 5 ? "\n   Valid housing choices must be between 1 and 5." : "");
		cout << (housingPreference - static_cast<int>(housingPreference) != 0 ? "\n   Housing choice MUST be an integer." : "") << "\n";

		// Prompt user to enter a valid housing choice.
		cout << "\n   Please enter a valid housing choice: ";
		cin >> housingPreference;
		cin.ignore(1000, '\n');	// Remove data from input buffer.
	}

	// PROCESSING SECTION 
	// Calculations for residency status and tuition

	switch (residencyStatus)
	{
		case 1:		tuition = IN_STATE_TUITION;			break;
		case 2:		tuition = OUT_OF_STATE_TUITION;		break;
		case 3:		tuition = INTERNATIONAL_TUITION;	break;
	}

	cout << setfill('0') << right;	// Formatting for dollar amounts to follow.

	// Calculations for housing preference and number of roommates
	if (housingPreference != 5)
	{
		numberOfRoommates = housingPreference - 1;
		boardDiscount = numberOfRoommates * ROOMMATE_DISCOUNT;

		// State room discount if applicable & use conditional statement to pluralize "roommate"
		cout << "\n  Your room discount is $ " << boardDiscount / 1000 << "," << setw(3)
			<< boardDiscount % 1000 << " because you have " << numberOfRoommates
			<< " roommate" << (numberOfRoommates == 1 ? "" : "s") << ".\n";
	}

	// Calculations for room charge
	if (housingPreference >= 1 && housingPreference <= 4)
		board = PRIVATE_ROOM_CHARGE - numberOfRoommates * ROOMMATE_DISCOUNT;
	else
		board = 0;

	// OUTPUT SECTION
	// Print a line of asterisks to demarcate the bill statement.
	cout << "\n"
		<< "          ******************************************\n";

	// Print a statement with user's tuition, board, and total bill.
	cout << "\n"
		<< "    Your bill is $ " << tuition / 1000 << "," << setw(3) << tuition % 1000
		<< " for tuition and $ " << board / 1000 << "," << setw(3) << board % 1000
		<< " for room charge.\n"
		<< "    The total amount you owe is $ " << (tuition + board) / 1000 << "," 
		<< setw(3) << (tuition + board) % 1000 << ".\n\n";

	// CLEAN UP SECTION
	system("pause");	// Hold screen so user sees the final message.
	return 0;			// End program.
	// MAIN ENDS
}