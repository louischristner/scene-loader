#include "Person.hpp"

Person::Person(const size_t &id, const std::string &name):
    _id(id), _name(name)
{
}

Person::Person(const std::string &filename)
{
    std::ifstream stream(filename);

    if (stream.is_open()) {
        this->loadFromFile(stream);
        stream.close();
    }
}

Person::Person(std::ifstream &stream)
{
    this->loadFromFile(stream);
}

Person::~Person()
{
}

bool Person::loadFromFile(std::ifstream &stream)
{
    std::regex idRegex("\"id\": \\d+");
    std::regex nameRegex("\"name\": \"[\\w\\s]+\"");

    for (std::string line; std::getline(stream, line); ) {
        std::smatch match;
        size_t pos = line.find(": ");
        std::string sub = line.substr(pos + 2);

        if (std::regex_search(line, idRegex)) {
            if (std::regex_search(sub, match, std::regex("\\d+")))
                _id = std::stoul(match[0]);
        } else if (std::regex_search(line, nameRegex)) {
            if (std::regex_search(sub, match, std::regex("[\\w\\s]+")))
                _name = match[0];
        }

        if (line.find('}') != std::string::npos)
            break;
    }

    return true;
}

void Person::displayDebug(void) const noexcept
{
    std::cerr << "ID: " << _id << std::endl;
    std::cerr << "NAME: " << _name << std::endl;
}
