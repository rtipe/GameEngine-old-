## Class Network

The `Network` class, located in the `Uniti::Game` namespace, manages network communication within a game or graphical application. It provides functionalities for handling servers, sending and receiving packets, and maintaining network connections. This class uses Boost.Asio for asynchronous I/O operations, enabling efficient and responsive network communication.

### Constructors

- **`Network(unsigned int port, unsigned int latency)`**: Constructor initializing the `Network` object with the specified `port` number and `latency` value, configuring the network communication parameters.

### Public Methods

- **`void start()`**: Starts the network communication, initiating the asynchronous I/O operations for sending and receiving packets.

- **`void update()`**: Updates the network state, handling received packets, processing server data, and maintaining the network connection.

- **`void addServer(const std::string &name, const std::string &ip, unsigned int port, const Json::Value &user)`**: Adds a new server with the specified `name`, `ip` address, `port` number, and `user` data to the network.

- **`void removeServer(const std::string &name)`**: Removes the server with the given `name` from the network.

- **`const Server &getServer(const std::string &name) const`**: Retrieves a constant reference to the server object associated with the specified `name`.

- **`Server &getServer(const std::string &name)`**: Retrieves a reference to the server object associated with the specified `name`, allowing modifications.

- **`void sendPackets()`**: Sends packets containing relevant data to the connected servers.

### Private Methods

- **`std::map<boost::asio::ip::udp::endpoint, Json::Value> getPacketToSend()`**: Retrieves packets that need to be sent to connected endpoints.

- **`void startReceive()`**: Initiates asynchronous operations to receive data from the network.

- **`void receiveBuffer(const std::string &buffer, boost::asio::ip::udp::endpoint &senderEndPoint)`**: Receives and processes data from the network buffer, associating it with the specified sender endpoint.

- **`void handlePackets()`**: Handles received packets, processing the data and taking appropriate actions based on the packet content.

### Private Properties

- **`std::map<std::string, std::unique_ptr<Server>> _servers`**: A map storing server objects associated with their respective names.

- **`boost::asio::io_service _ioService`**: Boost.Asio I/O service for managing asynchronous I/O operations.

- **`boost::asio::ip::udp::socket _socketUDP`**: UDP socket for sending and receiving network data.

- **`std::mutex _mutex`**: Mutex for handling concurrency and ensuring thread safety.

- **`unsigned int _latency`**: Latency value for network communication.

- **`unsigned int _port`**: Port number used for network communication.

- **`std::thread _ioThread`**: Thread for running asynchronous I/O operations.

- **`Render::Clock _clock`**: Clock object for tracking time, used for network-related time calculations.

- **`int _size = 50000`**: Size of the network buffer, initialized to 50000 bytes.

- **`char _buffer[50000]`**: Network buffer for storing received data.

- **`boost::asio::ip::udp::endpoint _senderEndPoint`**: Endpoint representing the sender of the received data.

- **`boost::lockfree::queue<std::tuple<boost::asio::ip::udp::endpoint, std::string> *> _queue`**: Lock-free queue for storing received data tuples (endpoint, data) for further processing.

---

*This documentation provides details on the methods and properties of the `Network` class, offering guidance for developers implementing network communication functionalities within the Uniti game engine.*
