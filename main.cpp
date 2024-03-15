module;

import <iostream>;
//g++ -std=c++20 -fmodules-ts -xc++-system-header iostream
module EntitiesMan;

int main()
{
    ECS::EntitiesManager ecs;
    std::cout << "HELLO\n";
    return 0;
}
