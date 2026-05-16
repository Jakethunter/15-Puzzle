#include <iostream>
#include <cassert>
#include <limits>

constexpr int g_consolelines{ 25 };

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
    bool isEmpty(){ return m_value == 0;}

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

};

int main() {
    Board board{};
    std::cout << board;
    UserInput::playGame();
    return 0;
}