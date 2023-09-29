#include "src/UnitiGame.hpp"

int main()
{
    UnitiGameEngine::Uniti("../Json/projectInfos.json");

    UnitiGameEngine::Uniti::getInstance().start();
    return 0;
}