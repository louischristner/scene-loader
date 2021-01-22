#include "../headers/Game.hpp"

Game::Game(const std::string &filename):
    _currentSceneIndex(0)
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

void Game::setCurrentSceneById(const size_t &id)
{
    for (size_t i = 0; i < _scenes.size(); i++)
        if (_scenes[i].getId() == id)
            _currentSceneIndex = i;
}

const Scene &Game::getCurrentScene() const
{
    return _scenes[_currentSceneIndex];
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
