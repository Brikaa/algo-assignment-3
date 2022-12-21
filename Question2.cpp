#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Activity
{int start, finish;};

bool activityCompare(Activity a1, Activity a2)
{return (a1.finish < a2.finish);}

void getMaxActivities(Activity arr[], int activityNo)
{
    //Sort activity array according to finish times
    sort(arr, arr + activityNo, activityCompare);

    cout << "Maximum activities: ";
    //First activity is always selected in a sorted activity list
    int i = 0, activityCount = 1;
    cout << "{" << arr[i].start << ", " << arr[i].finish << "}";

    //Check if start time of an incoming activity is greater than or equal
    //finish time of the previous activity
    for (int j = 1; j < activityNo; j++) {
        if (arr[j].start >= arr[i].finish) {
            activityCount++;
            cout << ", {" << arr[j].start << ", " << arr[j].finish << "}";
            i = j;
        }
    }
    cout << ", " << activityCount << " activities";
}

int main()
{
    int activityNo;
    cout << "Enter number of activities: ";
    cin >> activityNo;
    Activity arr[activityNo];
    
    for (int i = 0; i < activityNo; i++) {
        int startTime, endTime;
        cout << "Enter activity start and end time (seperated by space): ";
        cin >> startTime >> endTime;
        arr[i] = {startTime, endTime};
    }

    getMaxActivities(arr, activityNo);
    return 0;
}