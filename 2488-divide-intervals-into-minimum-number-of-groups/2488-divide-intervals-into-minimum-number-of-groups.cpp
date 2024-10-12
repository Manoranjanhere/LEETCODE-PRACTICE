class Solution {
public:

    int minGroups(vector<vector<int>>& intervals) {
    // Vector to store the events (time, type)
    vector<pair<int, int>> events;
    
    // Populate the events vector with start and end+1 events
    for (const auto& interval : intervals) {
        events.push_back({interval[0], 1});     // Starting event
        events.push_back({interval[1] + 1, -1}); // Ending event
    }
    
    // Sort the events: first by time, then by type (-1 before 1 for same time)
    sort(events.begin(), events.end());
    
    int activeIntervals = 0; // Count of active intervals
    int maxGroups = 0;       // Maximum number of active intervals at any point
    
    // Traverse the events to count active intervals
    for (const auto& event : events) {
        activeIntervals += event.second;  // Update count based on event type
        maxGroups = max(maxGroups, activeIntervals); // Track the maximum count
    }
    
    return maxGroups;
}
};