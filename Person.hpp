#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <regex>
#include <fstream>
#include <iostream>

class Person {
    public:
        Person(const size_t &id = 0, const std::string &name = "");
        Person(const std::string &filename);
        Person(std::ifstream &stream);
        ~Person();

        bool loadFromFile(std::ifstream &stream);
        void displayDebug(void) const noexcept;

    protected:
    private:
        size_t _id;
        std::string _name;
};

#endif /* !PERSON_HPP_ */
