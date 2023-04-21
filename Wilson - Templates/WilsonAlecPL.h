/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Alec Wilson
// 10/19/2022
// Personal Library:
//   Make programming generally easier
//
// Resources:
//   https://stackoverflow.com/a/22127058
//   https://www.reddit.com/r/cpp_questions/comments/7425ql/checking_if_input_is_valid_with_cingood/
//   https://stackoverflow.com/a/13636569
// 
/////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <type_traits>
#include <random>

using namespace std;

//****//****//****//
//
// End Program
//
//****//****//****//
static int endProgram(string prompt = "Press Enter to end program.") {
    cout << "\n\n" << prompt;
    cin.ignore(100, '\n');
    cin.get();
    return 0;
}

//****//****//****//
//
// Validate Int, Int Range, Float, Float Range, Character, Chracter Range, Double, and Double Range
// & Integer Range Validation
// 
//****//****//****//
// 
// Use:
// validateNum<Type:numType>(Optional(Prompt:String), Optional(Range:Bool), Optional(rangeUpper:numType), Optional(rangeLower:numType))
// 
// Returns:
// numType
// 
//****//****//****//
// 
// **MAP**:
// <numType>: Type
// prompt: String
// range: Bool
// rangeUpper: Int
// rangeLower: Int
//
//****//****//****//
//****//****//****//
// 
// IMPORTANT!!!
// template type
// https://stackoverflow.com/a/22127058
//
//****//****//****//
template <typename numType> // here -> https://stackoverflow.com/a/22127058
numType validateNum(string prompt = "Enter a number: ", bool range = false, numType rangeLower = 0, numType rangeUpper = 0) {
    bool validated = false;
    numType input = 0;

    do {
        cout << prompt << " ";
        cin >> input;

        if (is_same<numType, char>::value) { // here -> https://stackoverflow.com/a/13636569
            input = toupper(input);
            rangeLower = toupper(rangeLower);
            rangeUpper = toupper(rangeUpper);
        }

        if (cin.good() && range == true && input <= rangeUpper && input >= rangeLower || range == false && cin.good()) { // here -> https://www.reddit.com/r/cpp_questions/comments/7425ql/checking_if_input_is_valid_with_cingood/
            validated = true;
        }
        else {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input given, try again." << endl;
        }
    } while (!validated);

    return input;
}

//****//****//****//
//
// Random Number
//
//****//****//****//
template <typename numType> // here -> https://stackoverflow.com/a/22127058
numType randomNum(/*bool range = true, */ int rangeLower = 0, int rangeUpper = 10) {
    numType randomNum = 0;

    unsigned seed = time(0);

    srand(seed);

    randomNum = (rand() / (rangeUpper - rangeLower + 1)) + rangeLower;

    return randomNum;
}
