#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <mutex>

struct Node {
    int key;
    int value;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text text;

public:
    LinkedList(sf::RenderWindow& win) : head(nullptr), window(win) {
        if (!font.loadFromFile("arial.ttf")) {
            std::cerr << "Failed to load font." << std::endl;
        }

        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
    }

    void addNode(int tempkey, int tempvalue) {
        Node* newNode = new Node;
        newNode->key = tempkey;
        newNode->value = tempvalue;

        newNode->next = head;
        head = newNode;
    }

    int traverseLastNode() {
 
        Node* current = head;

        while (current->next != nullptr) {
            std::cout << "value:" << current->value << std::endl;
            current = current->next;
        }
        return (current->value);
    }

    void removeNode(int tempkey) {
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

    int findKey(int tempkey)
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (current->key == tempkey)
                return current->value;
            current = current->next;
        }
        return -1;
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
        sf::Text text1("LRU cache Visualization", font, 30);

        //text1.setString("LRU cache Visualization");
        text1.setPosition(nodeRect5.getPosition().x + 650 / 2 - text1.getLocalBounds().width / 2, nodeRect5.getPosition().y + 75 / 2 - text1.getLocalBounds().height / 2);
        //text1.setFillColor(sf::Color::Yellow);

        text1.setFillColor(sf::Color::Yellow);
        //text1.setPosition(320, 230);

        window.draw(nodeRect5);
        window.draw(text1);

        sf::RectangleShape nodeRect(sf::Vector2f(nodeSize, nodeSize));
        nodeRect.setFillColor(sf::Color::Magenta);
        nodeRect.setPosition(index * (nodeSize + nodeSpacing) + nodeSpacing, startY);

        text.setString("Head");
        text.setPosition(nodeRect.getPosition().x + nodeSize / 2 - text.getLocalBounds().width / 2, nodeRect.getPosition().y + nodeSize / 2 - text.getLocalBounds().height / 2);

        window.draw(nodeRect);
        window.draw(text);

        index = 1;

        while (current != nullptr) {
            sf::RectangleShape nodeRect3(sf::Vector2f(nodeSize, nodeSize));
            nodeRect3.setFillColor(sf::Color::Blue);
            nodeRect3.setPosition(index * (nodeSize + nodeSpacing) + nodeSpacing, startY);

            text.setString(std::to_string(current->key));
            text.setPosition(nodeRect3.getPosition().x + nodeSize / 2 - text.getLocalBounds().width / 2,
                nodeRect3.getPosition().y + nodeSize / 2 - text.getLocalBounds().height / 2);

            window.draw(nodeRect3);
            window.draw(text);


            // to draw value for particular key
            sf::RectangleShape nodeRect4(sf::Vector2f(nodeSize, nodeSize));
            nodeRect4.setFillColor(sf::Color::Transparent);
            nodeRect4.setPosition(index * (nodeSize + nodeSpacing) + nodeSpacing, startY+150);

            text.setString(std::to_string(current->value));
            text.setPosition(nodeRect4.getPosition().x + nodeSize / 2 - text.getLocalBounds().width / 2,
                nodeRect4.getPosition().y + nodeSize / 2 - text.getLocalBounds().height / 2);

            window.draw(nodeRect4);
            window.draw(text);

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
    }

    // Add getters/setters or additional methods as needed
};

/*class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

public:
    Button(float x, float y, float width, float height,
        std::string buttonText, int textSize,
        sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
        : idleColor(idleColor), hoverColor(hoverColor), activeColor(activeColor) {

        if (!font.loadFromFile("arial.ttf")) {
            std::cerr << "Failed to load font." << std::endl;
        }

        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(idleColor);

        text.setFont(font);
        text.setString(buttonText);
        text.setCharacterSize(textSize);
        text.setFillColor(sf::Color::White);
        text.setPosition(
            shape.getPosition().x + shape.getGlobalBounds().width / 2 - text.getGlobalBounds().width / 2,
            shape.getPosition().y + shape.getGlobalBounds().height / 2 - text.getGlobalBounds().height / 2
        );
    }

    bool isMouseOver(sf::RenderWindow& window) {
        sf::IntRect rect(shape.getPosition().x, shape.getPosition().y, shape.getSize().x, shape.getSize().y);
        if (rect.contains(sf::Mouse::getPosition(window))) {
            return true;
        }
        return false;
    }

    void update(sf::RenderWindow& window) {
        if (isMouseOver(window)) {
            shape.setFillColor(hoverColor);
        }
        else {
            shape.setFillColor(idleColor);
        }
    }

    void render(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }
};*/

void inputThreadFunc(LinkedList& linkedList, int& curr_size)
{
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
            if (linkedList.findKey(key) != -1)
            {
                int value = linkedList.findKey(key);
                linkedList.removeNode(key);
                std::cout << "Updated value for key:" << key << " is:" << value << std::endl;
            }
            else if (curr_size == 6)
            {
                std::cout << "Size is full. Now it's time to remove least frequent." << std::endl;
                int tempkey = linkedList.traverseLastNode();
                linkedList.removeNode(tempkey);
            }
            else
            {
                std::cout << "New Node added successfully" << std::endl;
                curr_size++;
            }
            linkedList.addNode(key, value);
            break;
        case 2:std::cout << "Enter key:" << std::endl;
            std::cin >> key;
            if (linkedList.findKey(key) != -1)
            {
                int tempvalue = linkedList.findKey(key);
                linkedList.removeNode(key);
                std::cout << "Value for key:" << key << " is:" << tempvalue << std::endl;
                linkedList.addNode(key, tempvalue);
            }
            else
            {
                std::cout << "Sorry, key is Not Found!" << std::endl;
            }
            break;
        default:std::cout << "INVALID INPUT!" << std::endl;
        }
    }
}

int main()
{
    const int windowWidth = 1000;
    const int windowHeight = 700;

    int curr_size = 0;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "LRU cache Visualization");
    window.setFramerateLimit(60);

    LinkedList linkedList(window);

    //Button putButton(50, 50, 100, 50, "Put", 24, sf::Color::Green, sf::Color::Cyan, sf::Color::Magenta);
    //Button getButton(250, 50, 100, 50, "Get", 24, sf::Color::Red, sf::Color::Yellow, sf::Color::Blue);

    std::thread inputThread(inputThreadFunc, std::ref(linkedList), std::ref(curr_size));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //putButton.update(window);
            //getButton.update(window);

            /*if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (putButton.isMouseOver(window))
                    {
                        // Process Put button click if needed
                    }
                    else if (getButton.isMouseOver(window))
                    {
                        // Process Get button click if needed
                    }
                }
            }*/
        }

        window.clear();
        linkedList.drawLinkedList();
        //putButton.render(window);
        //getButton.render(window);
        window.display();
    }

    inputThread.join();

    return 0;
}
