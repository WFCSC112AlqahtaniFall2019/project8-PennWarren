#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include "Data.h"

using namespace std;

int main() {
    //stream files
    ifstream spreadsheet;
    ofstream stackFile;
    ofstream queueFile;
    ofstream sortFile;


    //parsing data
    cout << "Reading dataset..." << endl;
    spreadsheet.open("../TreasuryYieldsData.csv");
    if(!spreadsheet.is_open()){
        cout << "Could not open file." << endl;
    }

    //declare three lists
    stack<Data> stackedYields;
    queue<Data> queuedYields;
    priority_queue<Data, vector<Data>, greater<>> sortedYields;

    while(!spreadsheet.eof()){
        //put each line into a stringstream for parsing
        string line;
        getline(spreadsheet, line);
        stringstream s(line);

        //parse data into string variables
        string tempDate, strThreeMonth, strTwoYear, strTenYear;
        getline(s, tempDate, ',');
        getline(s, strThreeMonth, ',');
        getline(s, strTwoYear, ',');
        getline(s,strTenYear,',');

        //convert variables to correct type and create a temp Data object to add to each list
        Data temp(tempDate, stod(strThreeMonth), stod(strTwoYear), stod(strTenYear));
        stackedYields.push(temp);
        queuedYields.push(temp);
        sortedYields.push(temp);
    }
    spreadsheet.close();


    //Write to stackFile
    cout << "Writing data in stack into stacked.txt" << endl;
    stackFile.open("../stacked.txt");
    //code for stack
    while(!stackedYields.empty()){
        stackFile << stackedYields.top();
        stackedYields.pop();
    }
    stackFile.close();

    //Write to queueFile
    cout << "Writing data in queue into queued.txt" << endl;
    queueFile.open("../queued.txt");
    while(!queuedYields.empty()){
        queueFile << queuedYields.front();
        queuedYields.pop();
    }
    queueFile.close();


    //Write to sortFile
    cout << "Writing data in priority queue sorted by the swap spreads (ascending) into sorted.txt" << endl;
    sortFile.open("../sorted.txt");
    while(!sortedYields.empty()){
        sortFile << sortedYields.top();
        sortedYields.pop();
    }
    sortFile.close();

    return 0;


}