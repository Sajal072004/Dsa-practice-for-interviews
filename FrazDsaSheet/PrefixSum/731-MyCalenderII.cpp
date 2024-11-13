class MyCalendarTwo {
public:
    map<int, int> mp;

    MyCalendarTwo() {}

    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;

        int ongoingEvents = 0;
        for (auto &[time, change] : mp) {
            ongoingEvents += change;
            if (ongoingEvents >= 3) {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Usage:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool result = obj->book(start, end);
 */