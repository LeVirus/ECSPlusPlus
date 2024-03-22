module;

import <iostream>;
//g++ -std=c++23 -fmodules-ts -xc++-system-header iostream
module M_EntitiesMan;

int main()
{
    ECS::EntitiesManager ecs;
    std::cout << __GLIBC_MINOR__ << " HELLO\n";

    return 0;
}
