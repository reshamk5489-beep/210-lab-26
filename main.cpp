#include <iostream>
#include <fstream>
#include <chrono>
#include <list>
#include <set>
#include <algorithm>
using namespace std;
using namespace std::chrono;

const int NUM_OF_OPERATIONS = 4;
const int NUM_OF_CONTAINERS = 3;
const int NUM_OF_RUNS = 15;

// Comment #1: Function prototypes
int readCodesToVector(vector<string> &codesVector);
int readCodesToList(list<string> &codesList);
int readCodesToSet(set<string> &codesSet);
void printRightJustified(string text, int width);
int sortVector(vector<string> &codes);
int sortList(list<string> &codes);
int sortSet(set<string> &codes);
int insertVector(vector<string> &codesVector);
int insertList(list<string> &codesList);
int insertSet(set<string> &codesSet);
int deleteVector(vector<string> &codesVector);
int deleteList(list<string> &codesList);
int deleteSet(set<string> &codesSet);

int main() {
    // Comment #2: Define vectors, lists, and sets to hold codes
    vector<string> codesVector;
    list<string> codesList;
    set<string> codesSet;

    int result[NUM_OF_OPERATIONS][NUM_OF_CONTAINERS];

    // Comment #3: Read codes into each data structure and time the operations
    for (int i = 0; i < NUM_OF_RUNS; i++)
    {
        int readVectorTime = readCodesToVector(codesVector);
        int readListTime = readCodesToList(codesList);
        int readSetTime = readCodesToSet(codesSet);

        result[0][0] += readVectorTime;
        result[0][1] += readListTime;
        result[0][2] += readSetTime;
    }

    result[0][0] /= NUM_OF_RUNS;
    result[0][1] /= NUM_OF_RUNS;
    result[0][2] /= NUM_OF_RUNS;

    // Comment #4: Print the timing results
    cout << "Operation    Vector      List       Set" << endl;
    printRightJustified("Read", 9);
    printRightJustified(to_string(result[0][0]), 10); 
    printRightJustified(to_string(result[0][1]), 10); 
    printRightJustified(to_string(result[0][2]), 10); 
    cout << endl;

    // Comment #5: Sort the data structures and time the operations
    int sortVectorTime = sortVector(codesVector);
    int sortListTime = sortList(codesList);
    int sortSetTime = sortSet(codesSet);

    printRightJustified("Sort", 9);
    printRightJustified(to_string(sortVectorTime), 10); 
    printRightJustified(to_string(sortListTime), 10); 
    printRightJustified(to_string(sortSetTime), 10); 
    cout << endl;

    // Comment #6: Insert into the data structures and time the operations
    int insertVectorTime = insertVector(codesVector);
    int insertListTime = insertList(codesList);
    int insertSetTime = insertSet(codesSet);

    printRightJustified("Insert", 9);
    printRightJustified(to_string(insertVectorTime), 10); 
    printRightJustified(to_string(insertListTime), 10); 
    printRightJustified(to_string(insertSetTime), 10); 
    cout << endl;

    // Comment #7: Delete from the data structures and time the operations
    int deleteVectorTime = deleteVector(codesVector);
    int deleteListTime = deleteList(codesList);
    int deleteSetTime = deleteSet(codesSet);

    printRightJustified("Delete", 9);
    printRightJustified(to_string(deleteVectorTime), 10); 
    printRightJustified(to_string(deleteListTime), 10); 
    printRightJustified(to_string(deleteSetTime), 10); 
    cout << endl << endl;

    return 0;
}

int readCodesToVector(vector<string> &codesVector)
{
    // Comment #8: Read codes from file into vector and time the operation
    ifstream fin("Codes.txt");
    string code;

    auto start = high_resolution_clock::now();
    while (fin >> code) // Comment #9: Read each code from the file
    {
        codesVector.push_back(code); // Comment #10: Add code to vector
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    fin.close(); // Comment #11: Close the file

    return duration.count(); // Comment #12: Return the time taken in microseconds
}

int readCodesToList(list<string> &codesList)
{
    ifstream fin("Codes.txt");
    string code;

    auto start = high_resolution_clock::now();
    while (fin >> code)
    {
        codesList.push_back(code); // Comment #13: Add code to list
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    fin.close();

    return duration.count();
}

int readCodesToSet(set<string> &codesSet)
{
    ifstream fin("Codes.txt");
    string code;

    auto start = high_resolution_clock::now();
    while (fin >> code)
    {
        codesSet.insert(code); // Comment #14: Add code to set using insert
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    fin.close();

    return duration.count();
}

void printRightJustified(string text, int width) 
{
    cout << setw(width) << text; // Comment #15: Print text right-justified with specified width
}

int sortVector(vector<string> &codes)
{
    auto start = high_resolution_clock::now();
    
    sort(codes.begin(), codes.end()); // Comment #16: Sort the vector using std::sort

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    return duration.count();
}

int sortList(list<string> &codes)
{
    auto start = high_resolution_clock::now();
    
    codes.sort(); // Comment #17: Sort the list using its member sort function

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    return duration.count();
}

int sortSet(set<string> &codes)
{
    // Comment #18: No sorting is required for set because item is sorted by default so returning -1
    return -1;
}

int insertVector(vector<string> &codesVector)
{
    auto start = high_resolution_clock::now();
    
    // Comment #19: Insert "TESTCODE" at index 10000
    codesVector.insert(codesVector.begin() + 10000, "TESTCODE"); 

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    return duration.count();
}

int insertList(list<string> &codesList)
{
    auto start = high_resolution_clock::now();
    
    // Comment #20: Insert "TESTCODE" at the 10000th position in the list
    auto it = next(codesList.begin(), 10000);
    codesList.insert(it, "TESTCODE");

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    return duration.count();
}

int insertSet(set<string> &codesSet)
{
    auto start = high_resolution_clock::now();
    
    // Comment #21: Insert "TESTCODE" into the set
    codesSet.insert("TESTCODE");

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    return duration.count();
}

int deleteVector(vector<string> &codesVector)
{
    auto start = high_resolution_clock::now();
    
    // Comment #22: Delete the element at index 10000
    codesVector.erase(codesVector.begin() + 10000);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    return duration.count();
}

int deleteList(list<string> &codesList)
{
    auto start = high_resolution_clock::now();
    
    // Comment #23: Delete the element at the 10000th position in the list
    auto it = next(codesList.begin(), 10000);
    codesList.erase(it);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    return duration.count();
}

int deleteSet(set<string> &codesSet)
{
    auto start = high_resolution_clock::now();
    
    // Comment #24: Delete the element at the 10000th position in the set
    auto it = next(codesSet.begin(), 10000);
    codesSet.erase(it);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    return duration.count();
}