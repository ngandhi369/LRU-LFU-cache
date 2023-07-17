#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <mutex>

struct Node {
    int key;
    int value;
    int freq;
    Node* next;
};

class LinkedList {
private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text text;

public:
    Node* head;

    LinkedList(sf::RenderWindow& win) : head(nullptr), window(win) {
        if (!font.loadFromFile("arial.ttf")) {
            std::cerr << "Failed to load font." << std::endl;
        }
        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
    }

    void addNode(int tempkey, int tempvalue, int f) {
        Node* newNode = new Node;
        newNode->key = tempkey;
        newNode->value = tempvalue;
        newNode->freq = f+1;

        newNode->next = head;
        head = newNode;
    }

    int traverseLastNode() {
 
        Node* current = head;

        while (current->next != nullptr) {
            //std::cout << "value:" << current->value << std::endl;
            current = current->next;
        }
        return (current->value);
    }

    void remove(int tempkey) {
        if (head == nullptr) {
            return;
        }

        if (head->key == tempkey) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->key != tempkey) {
            previous = current;
            current = current->next;
        }

        if (current != nullptr) {
            previous->next = current->next;
            delete current;
        }
    }
    
    void removeNode(int min_freq) {

        Node* temp = head;
        int tempkey = -1;
        int flag = 0;

        while (temp != nullptr)
        {
            if (temp->freq == min_freq)
            {
                tempkey = temp->key;
                flag = 1;
            }
            temp = temp->next;
        }
        if (flag == 1)
        {
            std::cout << "Node to be deleted:" << tempkey << std::endl;
            remove(tempkey);// due to key remains unique
        }
    }

    Node* findKey(int tempkey)
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (current->key == tempkey)
                return current;
            current = current->next;
        }
        return nullptr;
    }

    void drawLinkedList() {
        Node* current = head;
        int index = 0;
        const int nodeSize = 100;
        const int nodeSpacing = 20;
        const int startY = 200;

        sf::RectangleShape nodeRect5(sf::Vector2f(650, 75));
        nodeRect5.setFillColor(sf::Color::Transparent);
        nodeRect5.setPosition(167, 50);
        sf::Text text1("LFU cache Visualization", font, 30);

        text1.setPosition(nodeRect5.getPosition().x + 650 / 2 - text1.getLocalBounds().width / 2, nodeRect5.getPosition().y + 75 / 2 - text1.getLocalBounds().height / 2);
        text1.setFillColor(sf::Color::Yellow);

        window.draw(nodeRect5);
        window.draw(text1);

        sf::RectangleShape nodeRect(sf::Vector2f(nodeSize, nodeSize));
        nodeRect.setFillColor(sf::Color::Magenta);
        nodeRect.setPosition(index * (nodeSize + nodeSpacing) + nodeSpacing, startY);

        text.setString("Head");
        text.setPosition(nodeRect.getPosition().x + nodeSize / 2 - text.getLocalBounds().width / 2, nodeRect.getPosition().y + nodeSize / 2 - text.getLocalBounds().height / 2);


        sf::Text text5;
        text5.setFont(font);
        text5.setString("Value:");
        text5.setPosition(36, 371);
        text5.setFillColor(sf::Color::Cyan);
        text5.setCharacterSize(22);
        window.draw(text5);

        sf::Text text6;
        text6.setFont(font);
        text6.setString("Frequency:");
        text6.setPosition(18, 472);
        text6.setFillColor(sf::Color::Green);
        text6.setCharacterSize(22);
        window.draw(text6);

        window.draw(nodeRect);
        window.draw(text);        
        
        index = 1;

        while (current != nullptr) {
            sf::RectangleShape nodeRect3(sf::Vector2f(nodeSize, nodeSize));
            nodeRect3.setFillColor(sf::Color::Blue);
            nodeRect3.setPosition(index * (nodeSize + nodeSpacing) + nodeSpacing, startY);

            sf::Text text7, text8, text9;
            text7.setString(std::to_string(current->key));
            text7.setFillColor(sf::Color::White);
            text7.setFont(font);
            text7.setPosition(nodeRect3.getPosition().x + nodeSize / 2 - text7.getLocalBounds().width / 2, nodeRect3.getPosition().y + nodeSize / 2 - text7.getLocalBounds().height / 2);

            window.draw(nodeRect3);
            window.draw(text7);


            // to draw value for particular key
            sf::RectangleShape nodeRect4(sf::Vector2f(nodeSize, nodeSize));
            nodeRect4.setFillColor(sf::Color::White);
            nodeRect4.setPosition(index * (nodeSize + nodeSpacing) + nodeSpacing, startY+130);

            text8.setString(std::to_string(current->value));
            text8.setFillColor(sf::Color::Black);
            text8.setFont(font);
            text8.setPosition(nodeRect4.getPosition().x + nodeSize / 2 - text8.getLocalBounds().width / 2, nodeRect4.getPosition().y + nodeSize / 2 - text8.getLocalBounds().height / 2);

            window.draw(nodeRect4);
            window.draw(text8);


            // for frequency
            sf::RectangleShape nodeRect6(sf::Vector2f(nodeSize, nodeSize));
            nodeRect6.setFillColor(sf::Color::Transparent);
            nodeRect6.setPosition(index * (nodeSize + nodeSpacing) + nodeSpacing, startY+230);

            text9.setString(std::to_string(current->freq));
            text9.setFont(font);
            text9.setPosition(nodeRect6.getPosition().x + nodeSize / 2 - text9.getLocalBounds().width / 2, nodeRect6.getPosition().y + nodeSize / 2 - text9.getLocalBounds().height / 2);

            window.draw(nodeRect6);
            window.draw(text9);



            current = current->next;
            index++;
        }

        index = 7;
        sf::RectangleShape nodeRect2(sf::Vector2f(nodeSize, nodeSize));
        nodeRect2.setFillColor(sf::Color::Magenta);
        nodeRect2.setPosition(index * (nodeSize + nodeSpacing) + nodeSpacing, startY);

        text.setString("Tail");
        text.setPosition(nodeRect2.getPosition().x + nodeSize / 2 - text.getLocalBounds().width / 2, nodeRect2.getPosition().y + nodeSize / 2 - text.getLocalBounds().height / 2);

        window.draw(nodeRect2);
        window.draw(text);

        sf::Text text3("> Least Frequently Used (LFU) Cahce is deleted when size is full.", font, 20);
        sf::Text text4("> If there are more than one Least Frequently Used Cache then it removes Least Recently Used Cache.", font, 20);

        text3.setPosition(205, 590);
        text4.setPosition(45, 640);

        text3.setFillColor(sf::Color::White);
        text4.setFillColor(sf::Color::White);
        window.draw(text3);
        window.draw(text4);
    }

};

void inputThreadFunc(LinkedList& linkedList, int& curr_size)
{
    int minfreq=0;
    while (true)
    {
        int key, value;
        std::cout << "Enter a choice ('q' to quit): 1. Put   2. get" << std::endl;
        int ch;
        std::cin >> ch;

        //std::cout << "Size :" << curr_size << std::endl;

        switch (ch)
        {
            case 1:std::cout << "Enter key:" << std::endl;
                std::cin >> key;
                std::cout << "Enter its value:" << std::endl;
                std::cin >> value;
                if (linkedList.findKey(key) != nullptr)
                {
                    Node* temp = linkedList.findKey(key);
                    int temp_freq = temp->freq;
                    int temp_val = value;
                    linkedList.remove(key);
                    std::cout << "Updated value for key:" << key << " is:" << temp_val << std::endl;
                    linkedList.addNode(key, temp_val, temp_freq);//update freq
                }
                else if (curr_size == 6)
                {
                    std::cout << "Size is full. Now it's time to remove least frequent used cache" << std::endl;
                    int tempkey = linkedList.traverseLastNode();
                    std::cout << "....................." << tempkey << " will be deleted." << std::endl;
                    linkedList.removeNode(minfreq);
                    linkedList.addNode(key, value, 0);
                }
                else
                {
                    std::cout << "New Node added successfully" << std::endl;
                    curr_size++;
                    linkedList.addNode(key, value, 0);
                }
                break;

            case 2:std::cout << "Enter key:" << std::endl;
                std::cin >> key;
                if (linkedList.findKey(key) != nullptr)
                {
                    Node* temp = linkedList.findKey(key);
                    int temp_freq = temp->freq;
                    int temp_val = temp->value;
                    linkedList.remove(key);
                    std::cout << "Value for key:" << key << " is:" << temp_val << std::endl;
                    linkedList.addNode(key, temp_val, temp_freq); //update freq
                }
                else
                {
                    std::cout << "Sorry, key is Not Found!" << std::endl;
                }
                break;

            default:std::cout << "INVALID INPUT!" << std::endl;
        }

        Node* check = linkedList.head;
        minfreq = INT_MAX;
        while (check != nullptr)
        {
            minfreq = std::min(minfreq, check->freq);
            check = check->next;
        }
        std::cout << "min freq" << minfreq << std::endl;
    }
}

int main()
{
    const int windowWidth = 1000;
    const int windowHeight = 700;

    int curr_size = 0;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "LFU cache Visualization");
    window.setFramerateLimit(60);

    LinkedList linkedList(window);

    std::thread inputThread(inputThreadFunc, std::ref(linkedList), std::ref(curr_size));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        linkedList.drawLinkedList();
        window.display();
    }

    inputThread.join();

    return 0;
}
