#ifndef GAME_HPP_
#define GAME_HPP_

#include <vector>

#include "Scene.hpp"

class Game {
    public:
        Game(const std::string &filename);
        ~Game();

        void setCurrentSceneById(const size_t &id);

        const Scene &getCurrentScene() const;
        const std::vector<Scene> &getScenes() const;

        bool loadFromFile(std::ifstream &stream);

    protected:
    private:
        size_t _currentSceneIndex;
        std::vector<Scene> _scenes;
};

#endif /* !GAME_HPP_ */
