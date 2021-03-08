/*

731. My Calendar II

Implement a MyCalendarTwo class to store your events. A new event can be added if adding the event will not cause a triple booking.

Your class will have one method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

A triple booking happens when three events have some non-empty intersection (ie., there is some time that is common to all 3 events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.

Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)

*/

class MyCalendarTwo {
public:
    vector<pair<int, int>> overlap;
    vector<pair<int, int>> calendar;
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto it : overlap) {
            if ((start < it.second) && (end > it.first)) {
                return false;
            }
        }
        for(auto it : calendar) {
            if ((start < it.second) && (end > it.first)) {
                overlap.emplace_back(max(start, it.first), min(end, it.second));
            }
        }
        calendar.emplace_back(start, end);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
