# LRU LFU Cache Visualization Program using SFML Library

This program demonstrates the visualization of an LRU (Least Recently Used) LFU (Least Frequently Used) Cache using the SFML (Simple and Fast Multimedia Library). The cache is implemented using a linked list data structure.

## Prerequisites
- SFML library installed on your system. For more deatails, please visit: [SFML Setup in Visual Studio](https://www.youtube.com/watch?v=4fcTqmT0Hhg)
- `arial.ttf` font file in the same directory as the program

## How to Run
1. Compile and run the program.
2. Enter your choice as follows:
   - Enter `1` to put a key-value pair in the cache.
   - Enter `2` to get the value for a specific key from the cache.
   - Enter `q` to quit the program.

## Program Explanation
- The program uses the SFML library to create a graphical window for cache visualization.
- All operations here are being done using queue algorithm techniques.
- For the sake of ease of use, the queue is implemented using a doubly linked list, where each node represents a key-value pair.
- The `LinkedList` class contains methods to add a node, remove a node, find a key, and draw the linked list on the SFML window.
- The main function sets up the SFML window and starts a separate input thread to interact with the cache.
- The cache visualization is updated in the main loop of the program using the SFML window.

## Conclusion
The program allows you to interactively add and retrieve key-value pairs from the LRU LFU cache visualization. The SFML library is used to create a graphical window and draw the cache's linked list representation.
