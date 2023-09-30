#include <iostream>
#include "src/UnitiGame.hpp"

int main()
{
    try {
        UnitiGameEngine::Uniti::initGameProject("../Json/projectInfos.json");

        UnitiGameEngine::Uniti::getInstance().start();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}