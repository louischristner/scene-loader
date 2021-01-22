#include <vector>

#include "Scene.hpp"

#define PATH(name) "scenes/" + name + ".json"

int main(void)
{
    std::vector<Scene> scenes;
    std::string filenames[] = {
        "scene1", "scene2"
    };

    for (size_t i = 0; i < sizeof(filenames) / sizeof(std::string); i++)
        scenes.push_back(Scene(PATH(filenames[i])));

    for (const auto &scene : scenes)
        scene.displayDebug();

    return 0;
}
