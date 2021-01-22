#include "headers/Game.hpp"

int main(void)
{
    Game game("files/game.json");

    for (std::string input; std::getline(std::cin, input); ) {
        if (input.find("scene ") != std::string::npos) {
            game.setCurrentSceneById(std::stoul(input.substr(6)));
        } else if (input.find("show") != std::string::npos) {
            game.getCurrentScene().displayDebug();
        }
    }

    return 0;
}
