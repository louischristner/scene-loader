#include "Game.hpp"

Game::Game(const std::string &filename)
{
    std::ifstream stream(filename);

    if (stream.is_open()) {
        this->loadFromFile(stream);
        stream.close();
    }
}

Game::~Game()
{
}

const std::vector<Scene> &Game::getScenes() const
{
    return _scenes;
}

bool Game::loadFromFile(std::ifstream &stream)
{
    std::regex scenesRegex("\"scenes\": ");

    for (std::string line; std::getline(stream, line); ) {
        if (std::regex_search(line, scenesRegex)) {
            while (std::getline(stream, line)) {
                if (line.find("]") == std::string::npos) {
                    std::smatch match;
                    if (std::regex_search(line, match, std::regex("\".+\\.json\"")))
                        _scenes.push_back(Scene(std::string(match[0]).substr(1, std::string(match[0]).size() - 2)));
                } else {
                    break;
                }
            }
        }

        if (line.find('}') != std::string::npos)
            break;
    }

    return true;
}
