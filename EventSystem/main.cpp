
#include <iostream>
#include "src/event.h"
#include "src/event_handler.h"

using namespace std;
using namespace Events;

void callback_1(EventArgs* args);
void callback_2(EventArgs* args);
void callback_3(EventArgs* args);
void pause_console();

int main()
{
	cout << "Testing Event System..." << endl << endl;

	// Create a new event
	Event event{};

	// Create an event handler
	EventHandler event_handler(callback_3);

	// Add three event handlers
	event += callback_1;
	event += callback_2;	
	event.add_handler(event_handler);

	cout << "Registered event handlers: " << event.get_number_of_subscribed_handlers() << endl;

	// Create an EventArgs instance
	map<int, string> arg_list = { {1, "property1"}, {2, "property2"}, {3, "property3"} };
	int event_type = 100;

	EventArgs* args = new EventArgs(event_type, &arg_list);
	
	// Raise event
	event(args);

	cout << endl << "Event handler #3 will be discarded because it's napping!" << endl;

	// Remove second event handler
	event -= event_handler;

	cout << endl << "Registered event handlers: " << event.get_number_of_subscribed_handlers() << endl;

	// Raise event again
	event(args);

	// Pause console
	pause_console();
	return 0;
}

void callback_1(EventArgs* args) {
	cout << "Callback #1 is notified and will show everything..." << endl;

	cout << "Callback #1 =>" << "Event type #" << args->get_event_type() << " triggered on " << args->get_timestamp() << endl;

	map<int, string> _args = *args->get_args();

	cout << "Callback #1 =>" << "Event type id: " << args->get_event_type() << endl;
	for (std::map<int, string>::iterator it = _args.begin(); it != _args.end(); ++it)
	{
		std::cout << "Callback #1 =>" << "Index: " << it->first << ", property: " << it->second << '\n';
	}
}

void callback_2(EventArgs* args) {
	cout << "Callback #2 is notified and will show some data..." << endl;
	cout << "Callback #2 =>" << "Event type #" << args->get_event_type() << " triggered on " << args->get_timestamp() << endl;
}

void callback_3(EventArgs* args) {
	cout << "Callback #3 is notified but it does not care because it's taking a nap..." << endl;
}

void pause_console()
{
	cout << endl << endl << "Press any key to exit...";
	std::cin.get();
}
