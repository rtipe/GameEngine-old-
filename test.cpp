#include <iostream>
#include "src/UnitiGame.hpp"
#include "scripts/VasselMovement.hpp"
#include "scripts/ForwardParallax.hpp"

int main()
{
    try {
        UnitiGameEngine::Uniti::initGameProject("../Json/projectInfos.json");

        UnitiGameEngine::Uniti::getInstance().getScriptFactory().addScript<VasselMovement>("VasselMovement");
        UnitiGameEngine::Uniti::getInstance().getScriptFactory().addScript<ForwardParallax>("ForwardParallax");

        UnitiGameEngine::Uniti::getInstance().start();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}