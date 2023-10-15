
# Readme

## Description

This is a C++ class called `Window` designed for managing windows in a graphical application. It provides functionalities to create a window, handle events, and manage printable elements. The class is designed to work with SFML library for graphics.


### Checking if Window is Open

bool isOpen() const;

- Returns true if the window is currently open.

### Closing the Window

void close();

- Closes the window.

### Displaying the Window

void display();

- Displays the window, handles events, and renders printable elements.

### Creating a Window

void create(const Json::Value &value);

- Creates a window with the specified properties from a JSON value.

### Printing Elements

void print(IPrintable &printable);

- Adds a printable element to be rendered in the window.

### Getting SFML Event

sf::Event &getEvent();

- Returns a reference to the SFML event object for handling events.

### Getting SFML RenderWindow

sf::RenderWindow &getRenderWindow();

- Returns a reference to the SFML RenderWindow object.
