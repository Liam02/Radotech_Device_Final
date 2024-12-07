#include "HealthMetrics.h"

HealthMetrics::HealthMetrics()
{

}

void HealthMetrics::addReading(map<string, int> r, map<string, string> a){
    allScans.push_back(r);
    scanAnalysis.push_back(a);
}

void HealthMetrics::addNote(vector<int> n){
    endOfScanNotes.push_back(n);
}

map<string, int> HealthMetrics::getScan(int i){
    return allScans[i];
}

vector<int> HealthMetrics::getNote(int i){
    return endOfScanNotes[i];
}

map<string, string> HealthMetrics::getAnalysis(int i){
    return scanAnalysis[i];
}

int HealthMetrics::getScanArraySize(){
    return allScans.size();
}

int HealthMetrics::getNotesArraySize(){
    return endOfScanNotes.size();
}
