#include <iostream>
#include <cassert>
#include <limits>
#include <random>
#include "random.h"

constexpr int g_consolelines{ 25 };




class Direction {
public:
    enum Type {
        up,
        down,
        left,
        right,
        max,
    };

    Direction(char move) {
        switch (move)
        {
        case 'w':
            m_type = up;
            break;
        case 's':
            m_type = down;
            break;
        case 'a':
            m_type = left;
            break;
        case 'd':
            m_type = right;
            break;
        default:
            break;
        }
    }

    static Direction random() {
        return Direction{static_cast<Type>(Random::get(0, 3))};
    }

    Direction(Type e) : m_type{e} {
    }


    Direction operator-() const {
        if(static_cast<int>(m_type) % 2 == 0)
            return Direction{ static_cast<Type>(static_cast<int>(m_type) + 1) };
        else
            return Direction{ static_cast<Type>(static_cast<int>(m_type) - 1) };
    }

    friend std::ostream& operator<<(std::ostream& out, const Direction& Direction){
        switch (static_cast<int>(Direction.m_type))
        {
        case 0:
            out << "up";
            break;
        case 1:
            out << "down";
            break;
        case 2:
            out << "left";
            break;
        case 3:
            out << "right";
            break;
        default:
            break;
        }
        return out; 
    }

    const Type& typegetter() const {
        return m_type;
    }

private:
    Type m_type;

};


//Point Struct that represents a Coordinate


struct Point
{
    int x;
    int y;
    bool friend operator==(const Point& a, const Point& b){
        return a.x == b.x && a.y == b.y;
    }
        bool friend operator!=(const Point& a, const Point& b){
        return a.x != b.x || a.y != b.y;
    }
    Point getAdjacentPoint(const Direction direct){
        switch (direct.typegetter())
        {
        case Direction::up:
            return Point{x, y-1};
        case Direction::down:
            return Point{x, y+1};
        case Direction::left:
            return Point{x-1, y};
        case Direction::right:
            return Point{x+1, y};
        
        default:
            return *this;
        }
    }
};


class Tile
{
private:
    int m_value;

public:
    Tile() = default;

    explicit Tile (int value) : m_value{value} {
        assert(m_value >= 0 && m_value <= 15 && "m_value is not within range");
    }
    ~Tile() = default;

    int GetNum() const {return m_value;}

    friend std::ostream& operator<<(std::ostream& out, const Tile& obj){
        if (obj.m_value > 9){
            out << " " << obj.m_value << " ";
        } else if(9 >= obj.m_value && obj.m_value > 0) {
            out << "  " << obj.m_value << " ";
        } else {
            out << "    ";
        }

        return out; 
    }
     bool friend operator==(const Tile& a, const Tile& b){
        return a.m_value == b.m_value;
    }
};

class Board {
private:
    Tile m_array[4][4] { {Tile{1}, Tile{2}, Tile{3}, Tile{4}}, 
                         {Tile{5}, Tile{6}, Tile{7}, Tile{8}}, 
                         {Tile{9}, Tile{10}, Tile{11}, Tile{12}}, 
                         {Tile{13}, Tile{14}, Tile{15}, Tile{0}} };

public:
    friend std::ostream& operator<<(std::ostream& out, const Board& board){
        for (size_t i = 0; i < g_consolelines; i++)
        {
            out << '\n'; 
        }
        for (size_t i = 0; i < 4; i++){
            for (size_t t = 0; t < 4; t++){
                out << board.m_array[i][t];
            }
            out << '\n';
        }
        
        
        return out; 
    }

    bool checkValid(Point a) {
        return (a.x >= 0 && a.x <= 3 && a.y >= 0 && a.y <= 3);
    }

    void Swap(Point& a, Point& b){
        Point newPoint{a};
        a = b;
        b = newPoint;
    }

    bool movetile(){
        

    }



    
    Point FindEmpty(){
        for (size_t i = 0; i < 4; i++){
            for (size_t t = 0; t < 4; t++){
                if(this->m_array[i][t] == Tile{0}){
                    return {i, t};
                }
                
            }
    }
    
    }
};


namespace UserInput {

char getCommandFromUser(){
    char command;
    while (true){
        std::cin >> command;
        if (command == 'w' || command == 'a' || command == 's' || command == 'd' || command == 'q') {
        return command;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void playGame(){
    Board game;
    std::cout << game;


   char command{};
   while (true)
   {
    command = getCommandFromUser();
    switch (command)
    {
    case 'w':
        std::cout << "Valid command: " << command << '\n';
        break;
     case 'a':
        std::cout << "Valid command: " << command << '\n';
        break;
     case 's':
        std::cout << "Valid command: " << command << '\n';
        break;
     case 'd':
        std::cout << "Valid command: " << command << '\n';
        break;
     case 'q':
        std::cout << "Valid command: " << command << '\n';
        std::cout << "\n\nBye!\n\n";
        return;
    default:
        break;
    }
    }
    }

}

int main() {
    UserInput::playGame();


    return 0;
}