#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>

using namespace std;

// Condition key to check valid passport for part one
static vector<pair<string, bool>> conOne
{
    {"byr", false},
    {"iyr", false},
    {"eyr", false},
    {"hgt", false},
    {"hcl", false},
    {"ecl", false},
    {"pid", false},
};

// Condition key to check valid passport for part two
static vector<pair<string, bool>> conTwo
{
    {"byr", false},
    {"iyr", false},
    {"eyr", false},
    {"hgt", false},
    {"hcl", false},
    {"ecl", false},
    {"pid", false},
};

// Vector of validating function
static vector<bool (*)(string)> _functions;

// Colors to check for ecl in part two
static vector<string> colors
{
    "amb",
    "blu",
    "brn",
    "gry",
    "grn",
    "hzl",
    "oth",
};

bool getResult(vector<pair<string, bool>> *condition)
{
    bool result{true};

    // Get the result for part one
    for(auto x: *condition)
    {
        result &= x.second;
    }

    // Reset the condition key to false
    for(auto x: *condition)
    {
        x.second = false;
    }

    return result;
}

/*
 * Part One
 */

void PartOne(string const key)
{
    for(auto x: conOne)
    {
        if(key==x.first) x.second=true;
    }
}

/*
 * Part Two
 */

bool checkByr(string value)
{
    stringstream ss(value);
    int year{0};

    ss >> year;
    if(year>=1920 && year<=2002) return true;
    return false;
}

bool checkIyr(string value)
{
    stringstream ss(value);
    int year{0};

    ss >> year;
    if(year>=2010 && year<=2020) return true;
    return false;
}

bool checkEyr(string value)
{
    stringstream ss(value);
    int year{0};

    ss >> year;
    if(year>=2020 && year<=2030) return true;
    return false;
}

bool checkHgt(string value)
{
    stringstream ss(value);
    int hgt{0};
    string unit;

    ss >> hgt >> unit;
    
    if("cm"==unit)
    {
        if(hgt>=150 && hgt<=193) return true;
        return false;
    }

    if(hgt>=59 && hgt<=76) return true;
    return false;
}

bool checkHcl(string value)
{
    regex pattern{"^#([a-f]|[0-9]){6}$"};
    return regex_match(value, pattern);
}

bool checkEcl(string value)
{
    for(auto x: colors)
    {
        if(x==value) return true;
    }

    return false;
}

bool checkPid(string value)
{
    regex pattern{"[0-9]{9}$"};
    return regex_match(value, pattern);
}

void addFunctions()
{
    _functions.push_back(checkByr);
    _functions.push_back(checkIyr);
    _functions.push_back(checkEyr);
    _functions.push_back(checkHgt);
    _functions.push_back(checkHcl);
    _functions.push_back(checkEcl);
    _functions.push_back(checkPid);
}

void PartTwo(string const key, string const value)
{
    unsigned int i;

    for(i=0; i<conTwo.size(); i++)
    {
        if(key==conTwo[i].first) 
            conTwo[i].second = _functions[i](value); 
    }
}

/*
 * Main
 */

int main()
{
    ifstream file;
    file.open("day4.txt");

    unsigned int countOne{0};
    unsigned int countTwo{0};

    // Prepare funtions for part two
    addFunctions();

    if(file.is_open())
    {
        string line;

        while(getline(file, line))
        {
            if("\0"!=line)
            {
                stringstream ss(line);
                string check;
                
                while(ss>>check)
                {
                    unsigned int len = check.length();
                    string key = check.substr(0, 3);
                    string value = check.substr(4, len-4);

                    PartOne(key);
                    PartTwo(key, value);
                }

                // Dont continue if reach the end of the file
                if(!file.eof()) continue;
            }

            // Part one
            if(getResult(&conOne)) countOne++;

            // Part two
            if(getResult(&conTwo)) countTwo++;
        }
    }

    // Close file
    file.close();

    // Print out result
    cout << "The number of valid passport in part one: " << countOne << endl;
    cout << "The number of valid passport in part two: " << countTwo << endl;

    return 0;
}
