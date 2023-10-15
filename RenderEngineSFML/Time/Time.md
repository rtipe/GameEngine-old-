# Clock Class

## Description

The `Clock` class provides functionality to measure time, including seconds, milliseconds, and microseconds. It also allows for restarting the clock, pausing, and resuming.

## Member Functions

- `Clock()`: Constructor for the `Clock` class.
- `void restart()`: Restarts the clock.
- `long long getSeconds() const`: Gets the elapsed time in seconds.
- `long long getMilliSeconds() const`: Gets the elapsed time in milliseconds.
- `long long getMicroSeconds() const`: Gets the elapsed time in microseconds.
- `void pause()`: Pauses the clock.
- `void start()`: Starts or resumes the clock.

## Private Members

- `std::mutex _mutex`: Mutex for thread safety.
- `std::chrono::high_resolution_clock::time_point _start`: Time point representing the start time.
- `std::chrono::high_resolution_clock::time_point _pause`: Time point representing the pause time.
- `bool _paused = false`: Flag indicating whether the clock is paused.
