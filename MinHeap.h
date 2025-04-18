#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

struct Node {
    int id;
    int score;
    Node(int x, int y) : id(x), score(y) {}
};

class MinHeap {
    public:
        int parent(int i);
        int left(int i);
        int right(int i);
        void percolateUp(int score);
        void percolateDown(int score);
        void findContestant(int id, ofstream &output);
        void insertContestant(int id, int points, ofstream &output);
        void eliminateWeakest(ofstream &output);
        void earnPoints(int id, int points, ofstream &output);
        void losePoints(int id, int points, ofstream &output);
        void crownWinner(ofstream &output);
        void showContestants(ofstream &output);
        void showHandles(ofstream &output);
        void showLocation(int id, ofstream &output);
        vector<int> handleArr;
        int maxSize;
    private:
        int size = 0;
        vector<Node> minHeap = {Node(-1, -1)};
};