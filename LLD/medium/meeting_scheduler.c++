// design a meeting scheduler 
// Requirements: 
// 1) There are n given meeting rooms. 
// 2) Book a meeting in any meeting room at given interval (start time and end time, capacity) 
// 3) send notification to all the persons who are invited to the meeting 
// 4) Use Meeting room calendar to track the meetings data and time.

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

enum class Day {Sunday};

class Location {
    private:
        int floorNo;
        int building;
};

class MeetingRoom {
    private:
        bool is_available;
        int id;
        int capacity;
        Location loc;
};

class MeetingRoomManager {
    private:
        vector<MeetingRoom> rooms;
        unordered_map<MeetingRoom, Calendar> intervals;
    public:
        //CRUD APIS
};

class TimeInterval {
    private:
        Day day;
        int start;
        int end;
};

class Calendar {
    private:
        vector<TimeInterval> intervals;
};

class MeetingScheduler {
    private:
        MeetingRoomManager manager;
};