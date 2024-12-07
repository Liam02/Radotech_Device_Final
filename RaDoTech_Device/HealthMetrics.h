#ifndef HEALTHMETRICS_H
#define HEALTHMETRICS_H
#include <string>
#include <map>
#include <vector>
using namespace std;

class HealthMetrics
{
public:
    HealthMetrics();
    void addReading(map<string, int>, map<string, string>); // scan analysis
    void addNote(vector<int>);
    map<string, int> getScan(int);
    vector<int> getNote(int);
    map<string, string> getAnalysis(int);
    int getScanArraySize();
    int getNotesArraySize();
private:
    vector<map<string, int>> allScans;
    vector<vector<int>> endOfScanNotes;
    vector<map<string, string>> scanAnalysis;
};

#endif // HEALTHMETRICS_H
