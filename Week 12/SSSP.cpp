#include <iostream>
#include <queue>
#include <limits>
#include <vector>
#include <stdio.h>
using namespace std;

using namespace std;

double dijkstraImplementation(int start, int paths[][6]){

    int time[6] = {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
    time[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int x = 0; x < 6; x++){
            if (paths[current][x] != 0){
                int distanceXtoY = paths[current][x];
                if (time[current] + distanceXtoY < time[x]){
                    time[x] = time[current] + distanceXtoY;
                    q.push(x);
                }
            }
        }
    }
    
    for(int x = 0;x<6;x++){
        if (x==start){
            continue;
        }
        else{
            cout<<"Minimum time from "<<start<<" City to "<<x<<" City is: "<<time[x]<<endl;
        }
    }
    
    int totalTime = 0;
    
    for (int x = 0; x < 6; x++){
        
        totalTime = totalTime +  time[x];
    }
    cout<<endl;
    return (double)totalTime/(double)5;
    
}

int main(){
    int paths[6][6] = { {0,10,0,0,15,5},
                        {10,0,10,30,0,0},
                        {0,10,0,12,5,0},
                        {0,30,12,0,0,20},
                        {15,0,5,0,0,0},
                        {5,0,0,20,0,0}};
    double avgTimes[6];
    double min = INT_MAX;
    for(int x=0;x<6;x++){
        cout<<"============Considering City"<<x<<"============\n";
        avgTimes[x]=dijkstraImplementation(x,paths);
        if (avgTimes[x]<min){
            min = avgTimes[x];
        }
    }
    for(int x=0;x<6;x++){
        
        cout<<"Average time of City "<<x<<": "<<avgTimes[x]<<endl;
    }
    vector <int> suitableCities;
    for(int x = 0;x<6;x++){
        if(avgTimes[x]==min){
            suitableCities.push_back(x);
            cout<<"City "<<x<<" is suitable for fascilitating a Hospital"<<endl;
        }
    }
}
