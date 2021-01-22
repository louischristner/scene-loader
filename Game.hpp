#ifndef GAME_HPP_
#define GAME_HPP_

#include <vector>

#include "Scene.hpp"

class Game {
    public:
        Game(const std::string &filename);
        ~Game();

        const std::vector<Scene> &getScenes() const;
        const std::vector<Person> &getPersons() const;

        bool loadFromFile(std::ifstream &stream);

    protected:
    private:
        std::vector<Scene> _scenes;
        std::vector<Person> _persons;
};

#endif /* !GAME_HPP_ */
