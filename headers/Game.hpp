#ifndef GAME_HPP_
#define GAME_HPP_

#include <vector>

#include "Scene.hpp"

class Game {
    public:
        Game(const std::string &filename);
        ~Game();

        const std::vector<Scene> &getScenes() const;

        bool loadFromFile(std::ifstream &stream);

    protected:
    private:
        std::vector<Scene> _scenes;
};

#endif /* !GAME_HPP_ */
