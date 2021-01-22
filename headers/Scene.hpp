#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <regex>
#include <vector>
#include <fstream>
#include <iostream>

#include "Person.hpp"

class Scene {
    public:
        Scene(const size_t &id = 0, const std::string &name = "");
        Scene(const std::string &filename);
        Scene(std::ifstream &stream);
        ~Scene();

        const size_t &getId() const;

        bool loadFromFile(std::ifstream &stream);
        void displayDebug(void) const noexcept;

    protected:
    private:
        size_t _id;
        std::string _name;
        std::vector<Person> _persons;
};

#endif /* !SCENE_HPP_ */
