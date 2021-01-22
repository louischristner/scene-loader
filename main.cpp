#include "Game.hpp"

int main(void)
{
    Game game("files/game.json");

    for (const auto &scene : game.getScenes())
        scene.displayDebug();

    // for (std::string input; std::getline(std::cin, input); ) {

    // }

    return 0;
}
