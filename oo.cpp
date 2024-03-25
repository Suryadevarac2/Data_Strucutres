#include <iostream>                    // Include necessary libraries
#include <string>                      // Include necessary libraries
#include <queue>                       // Include necessary libraries
#include <map>                         // Include necessary libraries
#include <chrono>                      // Include necessary libraries
#include <ctime>                       // Include necessary libraries

using namespace std;                   // Using standard namespace

struct Event {                         // Define structure for Event
    string name;                       // Define structure member for name
    string startTime;                  // Define structure member for start time
    string endTime;                    // Define structure member for end time
    string location;                   // Define structure member for location
    string description;                // Define structure member for description

    Event() : name(""), startTime(""), endTime(""), location(""), description("") {}  // Constructor for Event structure

    Event(const string& n, const string& start, const string& end, const string& loc, const string& desc)
        : name(n), startTime(start), endTime(end), location(loc), description(desc) {}  // Constructor for Event structure with parameters
};

struct CompareEvents {                 // Define structure for comparing Events
    bool operator()(const Event& e1, const Event& e2) const {   // Define operator for comparison
        return e1.startTime > e2.startTime;                      // Compare Events by start time
    }
};

class EventScheduler {                 // Define class for EventScheduler
private:
    priority_queue<Event, vector<Event>, CompareEvents> eventsQueue;   // Define priority queue to store events
    map<string, Event> eventsMap;      // Define map to store events

public:
    bool hasConflict(const string& startTime, const string& endTime) {  // Check for conflict between event timings
        for (const auto& event : eventsMap) {
            if ((startTime < event.second.endTime && endTime > event.second.startTime)) {
                return true; // Conflict detected
            }
        }
        return false; // No conflict
    }

    void addEvent(const string& name, const string& startTime, const string& endTime, const string& location, const string& description) {  // Add new event
        if (hasConflict(startTime, endTime)) {
            cout << "Scheduling conflict detected! Please choose a different time slot." << endl;  // Display conflict message
            return;
        }
        eventsMap[name] = Event(name, startTime, endTime, location, description);  // Add event to map
        rebuildPriorityQueue();  // Rebuild priority queue
    }

    void deleteEvent(const string& name) {  // Delete event
        if (eventsMap.erase(name)) {
            cout << "Event deleted successfully." << endl;  // Display deletion success message
        }
        else {
            cout << "Event not found." << endl;  // Display event not found message
        }
        rebuildPriorityQueue();  // Rebuild priority queue
    }

    void displayUpcomingEvents() {  // Display upcoming events
        rebuildPriorityQueue();  // Ensure the priority queue is up to date
        cout << "Upcoming Events:" << endl;  // Display heading
        while (!eventsQueue.empty()) {
            const Event& event = eventsQueue.top();  // Get top event from priority queue
            cout << "Name: " << event.name << ", Time: " << event.startTime << " - " << event.endTime << ", Location: " << event.location << ", Description: " << event.description << endl;  // Display event details
            eventsQueue.pop();  // Remove top event from priority queue
        }
    }

    void rebuildPriorityQueue() {  // Rebuild priority queue
        while (!eventsQueue.empty()) {
            eventsQueue.pop();  // Remove all events from priority queue
        }
        for (const auto& eventPair : eventsMap) {
            eventsQueue.push(eventPair.second);  // Push events from map to priority queue
        }
    }

    void run() {  // Run interactive console interface
        string choice, name, startTime, endTime, location, description;  // Declare variables
        do {
            cout << "\nOptions:\n1. Add Event\n2. Delete Event\n3. Display Events\n4. Exit\nEnter your choice: ";  // Display options
            cin >> choice;  // Take user input
            cin.ignore(); // Clear the input buffer

            if (choice == "1") {  // If user chooses to add event
                cout << "Enter event name: ";  // Prompt for event name
                getline(cin, name);  // Take event name input
                cout << "Enter start time (YYYY-MM-DD HH:MM): ";  // Prompt for start time
                getline(cin, startTime);  // Take start time input
                cout << "Enter end time (YYYY-MM-DD HH:MM): ";  // Prompt for end time
                getline(cin, endTime);  // Take end time input
                cout << "Enter location: ";  // Prompt for location
                getline(cin, location);  // Take location input
                cout << "Enter description: ";  // Prompt for description
                getline(cin, description);  // Take description input
                addEvent(name, startTime, endTime, location, description);  // Add event
            }
            else if (choice == "2") {  // If user chooses to delete event
                cout << "Enter event name to delete: ";  // Prompt for event name to delete
                getline(cin, name);  // Take event name input
                deleteEvent(name);  // Delete event
            }
            else if (choice == "3") {  // If user chooses to display events
                displayUpcomingEvents();  // Display upcoming events
            }
        } while (choice != "4");  // Repeat until user chooses to exit
    }
};

int main() {  // Main function
    EventScheduler scheduler;  // Create EventScheduler object
    scheduler.run(); // Run the interactive console interface  // Run interactive console interface

    return 0;  // Return 0 to indicate successful execution
}
