#include <iostream>
#include <algorithm>
#include <cassert>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>
#include <regex>
#include <vector>
#include <string.h>
using namespace std;

const string INF = "NULL";
const string LAM = "LAM";

//                         program                              begin   end.   var   ;   integer   :     ,   print               (      )   value=      =      +             -       *     /       a           b             c            d            f            0      1       2       3       4       5       6       7        8      9      LAM

const string ppt[23][33] = { "program I ; var K begin O end.",   INF,   INF,   INF,  INF,  INF,    INF,  INF,  INF,              INF,   INF,   INF,     INF,  INF,          INF,     INF,  INF,    INF,        INF,          INF,         INF,         INF,         INF,    INF,   INF,    INF,    INF,    INF,    INF,    INF,     INF,   INF,     INF,           // P
                            INF,                                INF,   INF,   INF,  INF,  INF,    INF,  LAM,  INF,              INF,   INF,   INF,     INF,  INF,          INF,     INF,  INF,   "L X",      "L X",       "L X",        "L X",       "L X",        INF,    INF,    INF,   INF,    INF,    INF,    INF,    INF,     INF,   INF,     INF,           // I
                            INF,                                INF,   INF,   INF,  LAM,  INF,    LAM,  LAM,  INF,              INF,   LAM,   INF,     LAM,  LAM,          LAM,     LAM,  LAM,   "L X",      "L X",       "L X",        "L X",       "L X",       "H X", "H X", "H X",   "H X",  "H X",  "H X",  "H X",  "H X",   "H X",  "H X",   INF,          // X
                            INF,                                INF,   INF,   INF,  INF,  INF,    INF,  INF,  INF,              INF,   INF,   INF,     INF,  INF,          INF,     INF,  INF,  "D : V ;",  "D : V ;",   "D : V ;",    "D : V ;",   "D : V ;",    INF,    INF,    INF,    INF,    INF,    INF,    INF,    INF,    INF,    INF,     INF,          // K
                            INF,                                INF,   INF,   INF,  INF,  INF,    INF,"I , D", INF,             INF,   INF,   INF,     INF,  INF,          INF,     INF,  INF,   "I Z",      "I Z",        "I Z",      "I Z",        "I Z",       INF,    INF,    INF,    INF,    INF,    INF,    INF,    INF,     INF,   INF,     INF,         // D
                            INF,                                INF,   INF,   INF,  INF,  INF,    LAM, ", D Z",INF,             INF,   INF,   INF,     INF,  INF,          INF,     INF,  INF,   INF,         INF,          INF,         INF,         INF,        INF,    INF,    INF,    INF,    INF,    INF,    INF,    INF,     INF,   INF,     INF,        //Z
                            INF,                                INF,   INF,   INF,  INF,"integer",INF,  INF,  INF,              INF,   INF,   INF,     INF,  INF,          INF,     INF,  INF,   INF,         INF,          INF,         INF,         INF,        INF,    INF,    INF,    INF,    INF,    INF,    INF,    INF,     INF,   INF,     INF,          // V
                            INF,                                INF,   LAM,   INF,  INF,  INF,    INF,  INF, "S O",             INF,   INF,   INF,     INF,  INF,          INF,     INF,  INF,   "S O",      "S O",        "S O",       "S O",       "S O",       INF,    INF,    INF,    INF,    INF,    INF,    INF,    INF,     INF,   INF,     INF,         // O
                            INF,                                INF,   LAM,   INF,  INF,  INF,    INF,  INF,  "O B",            INF,   INF,   INF,     INF,  "O B",        "O B",   INF,  INF,   INF,        INF,          INF,         INF,         INF,         INF,    INF,    INF,    INF,    INF,    INF,    INF,    INF,     INF,   INF,    "O B",          // B
                            INF,                                INF,   INF,   INF,  INF,  INF,    INF,  INF,  "W",              INF,   INF,   INF,     INF,  INF,          INF,     INF,  INF,   "A",         "A",          "A",         "A",         "A",        INF,    INF,    INF,    INF,    INF,    INF,    INF,    INF,     INF,   INF,     INF,         // S
                            INF,                                INF,   INF,   INF,  INF,  INF,    INF,  INF, "print ( U , I ) ;",INF,  INF,   INF,     INF,  INF,          INF,     INF,  INF,   INF,        INF,          INF,         INF,         INF,         INF,    INF,    INF,    INF,    INF,    INF,    INF,    INF,     INF,   INF,     INF,        // W
                            INF,                                INF,   INF,   INF,  INF,  INF,    INF,"\"value=\"",INF,         INF,   INF, "\"value=\"",INF,INF,          INF,     INF,  INF,   LAM,         LAM,          LAM,         LAM,         LAM,        INF,    INF,    INF,    INF,    INF,    INF,    INF,    INF,     INF,   INF,   "\"value=\"",     // U
                            INF,                                INF,   INF,   INF,  INF,  INF,    INF,  INF,  INF,              INF,   INF,   INF,     INF,  INF,          INF,     INF,  INF,   "I = E ;",  "I = E ;",   "I = E ;",    "I = E ;",    "I = E ;",  INF,    INF,    INF,    INF,    INF,    INF,    INF,    INF,     INF,   INF,     INF,        // A
                            INF,                                INF,   INF,   INF,  INF,  INF,    INF,  INF,  INF,             "T Q",  INF,   INF,     INF,  "T Q",       "T Q",    INF,  INF,   "T Q",      "T Q",         "T Q",       "T Q",      "T Q",      "T Q",  "T Q",  "T Q",  "T Q",  "T Q",  "T Q",  "T Q",  "T Q",  "T Q",  "T Q",    INF,        // E
                            INF,                                INF,   INF,   INF,  LAM,  INF,    INF,  INF,  INF,              INF,   LAM,   INF,     INF, "+ T Q",     "- T Q",   INF,  INF,   INF,         INF,          INF,         INF,         INF,        INF,    INF,    INF,    INF,    INF,    INF,    INF,    INF,     INF,   INF,     INF,         // Q
                            INF,                                INF,   INF,   INF,  INF,  INF,    INF,  INF,  INF,             "F R",  INF,   INF,     INF,  "F R",       "F R",    INF,  INF,   "F R",      "F R",        "F R",      "F R",        "F R",      "F R",  "F R",  "F R",  "F R",  "F R",  "F R",  "F R",  "F R",  "F R",  "F R",    INF,          // T
                            INF,                                INF,   INF,   INF,  LAM,  INF,    INF,  INF,  INF,              INF,   LAM,   INF,     INF,  LAM,          LAM, "* F R", "/ F R" ,INF,        INF,          INF,        INF,          INF,        INF,    INF,    INF,    INF,    INF,    INF,    INF,    INF,     INF,   INF,     INF,            // R
                            INF,                                INF,   INF,   INF,  INF,  INF,    INF,  INF,  INF,            "( E )", INF,   INF,     INF,  "N",          "N",     INF,  INF,   "I",         "I",          "I",        "I",          "I",        "N",    "N",    "N",    "N",    "N",    "N",    "N",    "N",    "N",    "N",     INF,              // F
                            INF,                                INF,   INF,   INF,  INF,  INF,    INF,  INF,  INF,              INF,   INF,   INF,     INF,"M H Y",       "M H Y",  INF,  INF,   INF,         INF,          INF,        INF,          INF,      "M H Y","M H Y", "M H Y", "M H Y", "M H Y", "M H Y",  "M H Y",  "M H Y",   "M H Y", "M H Y",  INF,     // N
                            INF,                                INF,   INF,   INF,  LAM,  INF,    INF,  INF,  INF,              INF,   INF,   INF,     INF,  INF,          INF,     LAM,  LAM,   INF,         INF,          INF,        INF,          INF,       "H Y", "H Y",   "H Y",  "H Y",  "H Y",  "H Y",  "H Y",  "H Y",   "H Y",  "H Y",   INF,              // Y
                            INF,                                INF,   INF,   INF,  INF,  INF,    INF,  INF,  INF,              INF,   INF,   INF,     INF,  "+",          "-",     INF,  INF,   INF,         INF,          INF,        INF,          INF,        LAM,    LAM,    LAM,    LAM,    LAM,    LAM,    LAM,    LAM,     LAM,   LAM,     INF,              // M
                            INF,                                INF,   INF,   INF,  INF,  INF,    INF,  INF,  INF,              INF,   INF,   INF,     INF,  INF,          INF,     INF,  INF,    "a",        "b",          "c",        "d",          "f",        INF,    INF,    INF,    INF,    INF,    INF,    INF,    INF,     INF,   INF,     INF,              // L
                            INF,                                INF,   INF,   INF,  INF,  INF,    INF,  INF,  INF,              INF,   INF,   INF,     INF,  INF,          INF,     INF,  INF,   INF,         INF,          INF,        INF,          INF,        "0",    "1",    "2",    "3",    "4",    "5",    "6",    "7",    "8",    "9",     INF, };           // H

const vector<string> RESERVED_WORDS = { "program", "var", "begin", "end.", "integer", "print", "\"value=\"" };
const vector<string> NON_TERMINALS = { "P", "I", "X", "K", "D", "Z", "V", "O", "B", "S", "W", "U", "A", "E", "Q", "T", "R", "F", "N", "Y", "M", "L", "H" };
const vector<string> TERMINALS = { "program",	"begin",	"end.", 	"var",	";",	"integer",	":",	",",	"print",	"(",	")", "\"value=\"",	"=",	"+",	"-",	"*",	"/",	"a",	"b",	"c",	"d",	"f",	"0",	"1",	"2",	"3",	"4",	"5",	"6",	"7",	"8",	"9",	LAM };
const vector<string> SEPARATORS = { ",", ":", ";", "\"", "(", ")", "=", "+", "-", "*", "/" };

bool interpret(string input);
void printstack(stack<string> s);
string getSymbolfromInput(string& x);
string deleteTokenFromInput(string input);
int getIndex(vector<string> vec, string search);
vector<string> getAllSubStrings(string x);
string frontShort(string x);
void cleanFile(string file_to_be_cleaned, string output_file);
string readProgramFileIntoString(string file);
void convertToPython(string input_file);

bool DEBUG = false;


int main() {

    string input;
    string to_be_cleaned, output;

    cout << "Please enter the filename you want to clean followed by the name of the output file. \n(<file to be cleaned> <output file): ";
    cin >> to_be_cleaned >> output;
    cleanFile(to_be_cleaned, output);

    input = readProgramFileIntoString(output);
    input = regex_replace(input, regex("\n"), " ");

    /*
      // Test cases
      vector<string> test_cases = {"program f2022 ; var a,1 , b2a , bc , ba2 : integer ; begin az1 = 3 ; b2a = 4 ; bc = 5 ; print ( value= , bc ) ; ba2 = az1 * ( b2a + 2 * bc ) ; print ( value= , ba2 ) ; end.",
                                   "program f198 ; var d4 , c3 , b2 , a1 : integer ; begin a1 = 2 ; b2 = 1 ; c3 = 5 ; d4 = 8 ; print ( value= , a1 ) ; f5 = a1 * ( b2 + 4 * c3 ) ; print ( value= , f5 ) ; end."};

      for (auto test: test_cases) {
        if (interpret(test)) {
          cout << "\nSuccess!" << endl;
        }
        else {
          cout << "\nFails!" << endl;
        }
      }
     */
    if (interpret(input)) {
        cout << "\nThis program passes!" << endl;
    }
    else {
        cout << "\nThis program fails!" << endl;
    }

    cout << "Converting to python in finalp3.py." << endl;
    convertToPython(output);

    cout << "Executing in Python..." << endl;
    system("python finalp3.py");

    return 0;
}

// Checks if the string is tracable with the eUablished parMng table
bool interpret(string input) {
    int count = 2;
    bool read_flag = false;
    string top = "";
    stack<string> mystack;
    string final = " ";
    string read = getSymbolfromInput(input);
    input = deleteTokenFromInput(input);

    // Initialize
    mystack.push("P");

    cout << "\n\t\t" << input << endl;

    while (!mystack.empty()) {

        cout << "\n" << count << "." << endl;

        // Pop step
        top = mystack.top();
        cout << "Pop " << "'" << top << "'" << endl;
        mystack.pop();

        // Read step
        if (read_flag) {
            read = getSymbolfromInput(input);

            // if read is NOT a reserved word
            if (getIndex(RESERVED_WORDS, read) == -1) {
                string temp = "";
                temp += read[0];
                read = temp;
                if (DEBUG) {
                    cout << "Going to delete " << "'" << read << "'" << " assuming theres is NO space after." << endl;
                }
                input = frontShort(input);
                if (DEBUG) {
                    cout << "\tNew read = " << "'" << read << "'" << endl;
                }

            }
            else {
                input = deleteTokenFromInput(input);
            }

            read_flag = false;
        }

        // Match step
        if (top == read) {
            cout << "Match with input " << "'" << read << "'";
            cout << "\t\t" << "\"" << read << " " << input << "\"" << endl;
            cout << "Stack: ";
            printstack(mystack);
            cout << endl << endl;
            final = top;
            read_flag = true;
            ++count;
            continue;
        }


        cout << "Read " << "'" << read << "'" << endl;

        if (DEBUG) {
            cout << "No match detected." << endl;
        }

        // Get value from table
        int non_term_i = getIndex(NON_TERMINALS, top);
        int term_i = getIndex(TERMINALS, read);
        if (non_term_i < 0 || term_i < 0) {
            if (getIndex(SEPARATORS, read) == -1) {
                if (read.length() < 1) {
                    cout << "'" << read << "'" << " is an illegal character." << endl;
                }
                else {
                    cout << "Missing the following separator token: " << "'" << top << "'" << endl;
                }
            }
            else {
                cout << "Missing the following separator token: " << "'" << top << "'" << endl;
            }
            return false;
        }
        string fromTable = ppt[non_term_i][term_i];

        cout << "Go to " << "[" << top << "]" << "[" << read << "]" << " = " << fromTable << endl;


        if (fromTable == INF) {
            cout << "Not in the grammer, " << "ppt[" << top << "]" << "[" << read << "]" << endl;
            return false;
        }
        if (fromTable == LAM) {
            if (DEBUG) {
                cout << "Lambda encountered, skipping... " << endl;
                printstack(mystack);
                cout << endl;
            }
            ++count;
            continue;
        }

        // Pushing value in backwards into stack
        vector<string> allSubStrings = getAllSubStrings(fromTable);
        for (int i = allSubStrings.size() - 1; i >= 0; i--) {
            string substr = allSubStrings[i];
            cout << "Push " << "'" << substr << "'" << " into the stack." << endl;
            mystack.push(allSubStrings[i]);

        }

        cout << "Stack: ";
        printstack(mystack);
        cout << endl << endl;
        ++count;


    }// End while
    if (input == "") {
        return true;
    }
    return false;

}

// Prints the contents of stack of chars
void printstack(stack<string> s) {
    if (s.empty()) {
        return;
    }

    string x = s.top();

    s.pop();

    printstack(s);

    cout << x << " ";

    s.push(x);
}

string getSymbolfromInput(string& x) {
    string token = "";
    for (int i = 0; i < x.length(); i++) {
        if (x[i] != ' ') {
            token += x[i];
        }
        else {
            break;
        }
    }

    return token;
}

string deleteTokenFromInput(string input) {
    string temp = "";

    // "program f2022 ;"
    int whitespace = input.find(" ", 0);

    for (int i = whitespace + 1; i < input.length(); i++) {
        temp += input[i];
    }
    return temp;
}

int getIndex(const vector<string> vec, string search) {
    auto it = find(vec.begin(), vec.end(), search);

    // If element was found
    if (it != vec.end())
    {
        return it - vec.begin();
    }
    else {
        return -1;
    }
}

vector<string> getAllSubStrings(string x) {
    vector<string> sub_strs;
    char* ptr = strdup(x.c_str());

    string temp = strtok(ptr, " ");
    while (ptr != NULL) {
        sub_strs.push_back(ptr);
        ptr = strtok(NULL, " ");
    }

    free(ptr);
    return sub_strs;
}

string frontShort(string x) {
    string str = "";
    for (int i = 1; i < x.length(); i++) {
        str += x[i];
    }
    if (str[0] == ' ') {
        str = frontShort(str);
    }
    return str;
}

void cleanFile(string file_to_be_cleaned, string output_file) {
    ofstream outfile;
    outfile.open(output_file);
    outfile.close();

    //bool check if words "program","end.","begin","var","integer","print",";",",","(",")","." is in the file
    bool program_check = false;
    bool end_check = false;
    bool begin_check = false;
    bool var_check = false;
    bool integer_check = false;
    bool print_check = false;
    bool semicolon_check = false;
    bool comma_check = false;
    bool left_paren_check = false;
    bool right_paren_check = false;
    bool period_check = false;

    bool Final_semicolon_check = true;
    bool Final_period_check = true;
    bool Final_comma_check = true;
    bool Final_left_paren_check = true;
    bool Final_right_paren_check = true;

    ifstream file;
    file.open(file_to_be_cleaned);
    if (!file.is_open())
    {
        cout << "Unable to open the file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        //remove extra spaces
        line.erase(unique(line.begin(), line.end(), [](char a, char b) { return isspace(a) && isspace(b); }), line.end());
        //find first two **
        auto pos = line.find("**");
        if (pos != string::npos)
        {
            //find second **
            auto pos2 = line.find("**", pos + 1);
            if (pos2 != string::npos)
            {
                //remove **
                line.erase(pos, 2);
                line.erase(pos2 - 2, 2);
                //remove spaces in g++ compiler
                line.erase(pos, find_if(line.begin() + pos, line.end(), [](int ch) { return !isspace(ch); }) - line.begin());

                //remove the items between the two **
                line.erase(pos - 1, pos2 - 2);
            }
        }
        //remove first and last spaces
        line.erase(line.begin(), find_if(line.begin(), line.end(), [](int ch) { return !isspace(ch); }));
        //remove empty lines
        if (line.empty())
            continue;
        //remove tabs
        line.erase(remove(line.begin(), line.end(), '\t'), line.end());
        //if the line starts with ** then remove the line
        if (line.find("**") == 0)
            continue;
        //if the line ends with ** then remove the line
        if (line.find("**") == line.size() - 2)
            continue;

        //check if words "program","end.","begin","var","integer","print",";",",","(",")" is in the file
        // if yes then set the bool to true
        if (line.find("program") != string::npos)
            program_check = true;
        if (line.find("end.") != string::npos)
            end_check = true;
        if (line.find("begin") != string::npos)
            begin_check = true;
        if (line.find("var") != string::npos)
            var_check = true;
        if (line.find("integer") != string::npos)
            integer_check = true;
        if (line.find("print") != string::npos)
            print_check = true;
        if (line.find(";") != string::npos)
            semicolon_check = true;
        if (line.find(",") != string::npos)
            comma_check = true;
        if (line.find("(") != string::npos)
            left_paren_check = true;
        if (line.find(")") != string::npos)
            right_paren_check = true;
        if (line.find(".") != string::npos)
            period_check = true;

        //if the line is not "begin" or "end." or "var" then check if ";" is at the end of the line
        if (line.find("begin") == string::npos && line.find("end.") == string::npos && line.find("var") == string::npos) {
            if (line.find(";") != line.size() - 1) {
                //if ";" is not at the end of the line set the bool to false
                Final_semicolon_check = false;
            }
        }

        //if "(" is in the line then check if ")" is in the line
        if (line.find("(") != string::npos) {
            if (line.find(")") == string::npos) {
                //if ")" is not in the line set the bool to false
                Final_right_paren_check = false;
            }
        }

        //if find ")" then check if "(" is before it
        if (line.find(")") != string::npos) {
            if (line.find("(") == string::npos) {
                //if "(" is not before ")" set the bool to false
                Final_left_paren_check = false;
            }
        }

        //if find "end" then check if "." is after it
        if (line.find("end") != string::npos) {
            if (line.find(".") == string::npos) {
                //if "." is not after "end" set the bool to false
                Final_period_check = false;
            }
        }



        // write to file
        ofstream outfilcheck;
        outfile.open(output_file, ios_base::app);
        outfile << line << endl;
        outfile.close();
    }

    // write to file called "check.txt" to show the result of the bool
    ofstream check;
    check.open("check.txt");
    // if program is not in the file then write to file "check.txt" that "program missing" , else write "program expected"
    if (program_check == false)
        check << "program is expected(missing or wrong spelling)" << endl;
    else
        check << "program is found" << endl;

    // if end is not in the file then write to file "check.txt" that "end missing" , else write "end expected"
    if (end_check == false)
        check << "end     is expected(missing or wrong spelling)" << endl;
    else
        check << "end     is found" << endl;

    // if begin is not in the file then write to file "check.txt" that "begin missing" , else write "begin expected"
    if (begin_check == false)
        check << "begin   is expected(missing or wrong spelling)" << endl;
    else
        check << "begin   is found" << endl;

    // if var is not in the file then write to file "check.txt" that "var missing" , else write "var expected"
    if (var_check == false)
        check << "var     is expected(missing or wrong spelling)" << endl;
    else
        check << "var     is found" << endl;

    // if integer is not in the file then write to file "check.txt" that "integer missing" , else write "integer expected"
    if (integer_check == false)
        check << "integer is expected(missing or wrong spelling)" << endl;
    else
        check << "integer is found" << endl;

    // if print is not in the file then write to file "check.txt" that "print missing" , else write "print expected"
    if (print_check == false)
        check << "print   is expected(missing or wrong spelling)" << endl;
    else
        check << "print   is found" << endl;

    // if ; is not in the file then write to file "check.txt" that "; missing" , else write "; expected"
    if (Final_semicolon_check == false)
        check << ";       is missing" << endl;
    else
        check << ";       is passing" << endl;

    // if , is not in the file then write to file "check.txt" that ", missing" , else write ", expected"
    if (Final_comma_check == false)
        check << ",       is missing" << endl;
    else
        check << ",       is passing" << endl;

    // if ( is not in the file then write to file "check.txt" that "( missing" , else write "( expected"
    if (Final_left_paren_check == false)
        check << "(       is missing" << endl;
    else
        check << "(       is passing" << endl;

    // if ) is not in the file then write to file "check.txt" that ") missing" , else write ") expected"
    if (Final_right_paren_check == false)
        check << ")       is missing" << endl;
    else
        check << ")       is passing" << endl;

    // if . is not in the file then write to file "check.txt" that ". missing" , else write ". expected"
    if (Final_period_check == false)
        check << ".       is missing" << endl;
    else
        check << ".       is passing" << endl;

    //close file
    outfile.close();

    file.close();

}

string readProgramFileIntoString(string file) {
    ifstream infile(file);
    stringstream buffer;
    buffer << infile.rdbuf();

    return buffer.str();
}

void convertToPython(string input_file) {

    ifstream final_p2;
    ofstream final_p3;
    string token;

    final_p2.open(input_file);
    final_p3.open("finalp3.py");

    while (final_p2 >> token) {
        if (token == "begin") {

            while (final_p2 >> token) {
                if (token == ";") {
                    final_p3 << "\n";
                    continue;
                }

                if (token == "print") {
                    // write print
                    final_p3 << token;
                    final_p2 >> token;
                    //write (
                    final_p3 << token;
                    final_p2 >> token;
                    final_p2 >> token;
                    final_p2 >> token;
                    // write variable
                    final_p3 << token;
                    final_p2 >> token;
                    //write )
                    final_p3 << token;
                    continue;
                } // end "print" if

                if (token == "end.") {
                    break;
                }

                final_p3 << token;
            } // end inner while
        }
    }
    return;
}
