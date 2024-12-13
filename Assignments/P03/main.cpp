#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

// ------------------ Player Class ------------------
class Player {
public:
    Player(const std::string& name) : name(name), score(0) {}

    void add_to_score(int points) { score += points; }
    int get_score() const { return score; }
    std::string get_name() const { return name; }

private:
    std::string name;
    int score;
};

// ------------------ Dice Class ------------------
class Dice {
public:
    Dice() { std::srand(std::time(nullptr)); }

    int roll() { return std::rand() % 6 + 1; } // Random number [1, 6]
};

// ------------------ Grid Class ------------------
class Grid {
public:
    Grid() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cells[i][j] = 0;
    }

    bool place_dice(int row, int col, int value) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || cells[row][col] != 0)
            return false;
        cells[row][col] = value;
        return true;
    }

    int get_cell_value(int row, int col) const {
        return cells[row][col];
    }

private:
    int cells[3][3];
};

// ------------------ Game Class ------------------
class Game {
public:
    Game() : current_player_index(0), window(sf::VideoMode(600, 400), "Knucklebones") {
        players[0] = Player("Player 1");
        players[1] = Player("Player 2");
        font.loadFromFile("arial.ttf"); // Make sure the font file is in the working directory
    }

    void start() {
        while (window.isOpen()) {
            handle_events();
            update();
            render();
        }
    }

private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text text;
    Player players[2];
    int current_player_index;
    Dice dice;
    Grid grid;

    void handle_events() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    void update() {
        // For simplicity, simulate one turn per frame
        take_turn();
        if (check_win())
            window.close();
        switch_turn();
    }

    void render() {
        window.clear(sf::Color::White);

        // Draw the grid
        draw_grid();

        // Draw the scores
        draw_scores();

        // Display everything
        window.display();
    }

    void take_turn() {
        Player& current_player = players[current_player_index];

        int roll = dice.roll();
        int row = std::rand() % 3;
        int col = std::rand() % 3;

        // Attempt to place the dice; retry if invalid
        while (!grid.place_dice(row, col, roll)) {
            row = std::rand() % 3;
            col = std::rand() % 3;
        }

        current_player.add_to_score(roll);
    }

    bool check_win() const {
        return players[0].get_score() >= 50 || players[1].get_score() >= 50;
    }

    void switch_turn() {
        current_player_index = 1 - current_player_index;
    }

    void draw_grid() {
        sf::RectangleShape cell(sf::Vector2f(80, 80));
        cell.setOutlineColor(sf::Color::Black);
        cell.setOutlineThickness(2);

        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                cell.setPosition(150 + col * 90, 100 + row * 90);
                cell.setFillColor(sf::Color(220, 220, 220)); // Light gray background
                window.draw(cell);

                int value = grid.get_cell_value(row, col);
                if (value > 0) {
                    sf::Text value_text;
                    value_text.setFont(font);
                    value_text.setString(std::to_string(value));
                    value_text.setCharacterSize(30);
                    value_text.setFillColor(sf::Color::Black);
                    value_text.setPosition(175 + col * 90, 115 + row * 90);
                    window.draw(value_text);
                }
            }
        }
    }

    void draw_scores() {
        for (int i = 0; i < 2; ++i) {
            sf::Text score_text;
            score_text.setFont(font);
            score_text.setString(players[i].get_name() + ": " + std::to_string(players[i].get_score()));
            score_text.setCharacterSize(20);
            score_text.setFillColor(i == 0 ? sf::Color::Red : sf::Color::Blue);
            score_text.setPosition(20, 20 + i * 30);
            window.draw(score_text);
        }
    }
};

// ------------------ Main Function ------------------
int main() {
    Game game;
    game.start();
    return 0;
}
