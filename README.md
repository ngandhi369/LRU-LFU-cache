# LRU LFU Cache Visualization Program using SFML Library

This program demonstrates the visualization of an LRU (Least Recently Used) LFU (Least Frequently Used) Cache using the SFML (Simple and Fast Multimedia Library). The cache is implemented using a linked list data structure.

## Prerequisites

1. SFML library installed on your system. For more details, please visit: [SFML Setup in Visual Studio](https://www.youtube.com/watch?v=4fcTqmT0Hhg).
2. `arial.ttf` font file in the same directory as the program.

## How to Run

1. Compile and run the program.
2. Enter your choice as follows:
   - Enter `1` to put a key-value pair in the cache.
   - Enter `2` to get the value for a specific key from the cache.
   - Enter `q` to quit the program.

## Program Explanation

The program uses the SFML library to create a graphical window for cache visualization. It supports both LRU and LFU cache replacement policies.

### Least Recently Used (LRU) Cache:
- The LRU cache replaces the least recently accessed items when the cache is full.
- The cache uses queue algorithm techniques and is implemented as a doubly linked list, where each node represents a key-value pair.
- The `LinkedList` class contains methods to add a node, remove a node, find a key, and draw the linked list on the SFML window.
- The main function sets up the SFML window and starts a separate input thread to interact with the LRU cache.
- The cache visualization is updated in the main loop of the program using the SFML window.

### Least Frequently Used (LFU) Cache:
- The LFU cache replaces the least frequently accessed items when the cache is full. If there are more than one cache having same frequency, then Least Recently Used (LRU) cache will be deleted.
- The `LinkedList` class has been extended to support LFU cache functionality.
- The cache nodes now store a frequency counter, and a separate method is provided to remove the least frequently used node when the cache is full.
- The input thread handles user interaction with the LFU cache, allowing users to put and get key-value pairs.

## Conclusion

The program allows you to interactively add and retrieve key-value pairs using both LRU and LFU cache visualization. The SFML library is used to create a graphical window and draw the cache's linked list representation.
