#include "Scene.hpp"

Scene::Scene(const size_t &id, const std::string &name):
    _id(id), _name(name)
{
}

Scene::Scene(const std::string &filename)
{
    std::ifstream stream(filename);

    if (stream.is_open()) {
        this->loadFromFile(stream);
        stream.close();
    }
}

Scene::Scene(std::ifstream &stream)
{
    this->loadFromFile(stream);
}

Scene::~Scene()
{
}

bool Scene::loadFromFile(std::ifstream &stream)
{
    std::regex idRegex("\"id\": \\d+");
    std::regex nameRegex("\"name\": \"[\\w\\s]+\"");
    std::regex personsRegex("\"persons\": ");

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
        } else if (std::regex_search(line, personsRegex)) {
            while (std::getline(stream, line)) {
                if (line.find('{') != std::string::npos) {
                    _persons.push_back(Person());
                    (_persons.end() - 1)->loadFromFile(stream);
                } else if (line.find(']') != std::string::npos) {
                    break;
                }
            }
        }

        if (line.find('}') != std::string::npos)
            break;
    }

    return true;
}

void Scene::displayDebug(void) const noexcept
{
    std::cerr << "ID: " << _id << std::endl;
    std::cerr << "NAME: " << _name << std::endl;
    std::cerr << "PEOPLE: [" << std::endl;
    for (const auto &person : _persons)
        person.displayDebug();
    std::cerr << "]" << std::endl;
}
