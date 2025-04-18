#include "MinHeap.h"
using namespace std;

int main(int argc, char* argv[]) {
    MinHeap M;
    ifstream inFile(argv[1]);
    ofstream outFile(argv[2]);
    string line;
    getline(inFile, line);
    stringstream ss(line);
    ss >> M.maxSize;
    M.handleArr.resize(M.maxSize + 1, -1);
    while(getline(inFile, line)) {
        stringstream ss(line);
        string command; string argument1; string argument2;
        int arg1, arg2;
        ss >> command;
        if(ss >> argument1) arg1 = stoi(argument1.substr(1, argument1.length() - 1));
        if(ss >> argument2) arg2 = stoi(argument2.substr(1, argument1.length() - 1));
        if(command == "findContestant") {
            outFile << "findContestant <" << arg1 << ">" << endl;
            M.findContestant(arg1, outFile);
        } else if (command == "insertContestant") {
            outFile << "insertContestant <" << arg1 << "> <" << arg2 << ">" << endl;
            M.insertContestant(arg1, arg2, outFile);
        } else if(command == "eliminateWeakest") {
            outFile << "eliminateWeakest" << endl;
            M.eliminateWeakest(outFile);
        } else if(command == "earnPoints") {
            outFile << "earnPoints <" << arg1 << "> <" << arg2 << ">" << endl;
            M.earnPoints(arg1, arg2, outFile);
        } else if(command == "losePoints") {
            outFile << "losePoints <" << arg1 << "> <" << arg2 << ">" << endl;
            M.losePoints(arg1, arg2, outFile);
        } else if(command == "crownWinner") {
            outFile << "crownWinner" << endl;
            M.crownWinner(outFile);
        } else if(command == "showContestants") {
            outFile << "showContestants" << endl;
            M.showContestants(outFile);
        } else if(command == "showHandles") {
            outFile << "showHandles" << endl;
            M.showHandles(outFile);
        } else if(command == "showLocation") {
            outFile << "showLocation <" << arg1 << ">" << endl;
            M.showLocation(arg1, outFile);
        }
        else outFile << "Command does not exist." << endl;
    }
    inFile.close();
    outFile.close();
}