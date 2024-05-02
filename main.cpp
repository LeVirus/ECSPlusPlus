#include <iostream>
#include <ECSManager.hpp>
#include <memory>
// #include <TemplateDeclaration.hpp>

// template class ECS::ECSManager<4u, ECS::Test, ECS::TestB>;
// template class ECS::ComponentsManager<4u, ECS::Test, ECS::TestB>;

using TupleComp_t = std::tuple<ECS::Test, ECS::TestB>;

int main()
{
    // ECS::ComponentsManager<4u, ECS::Test, ECS::TestB> ecs;
    // ECS::Ha<4, ECS::Test, ECS::TestB> ss;
    // std::tuple<std::vector<ECS::Test>, std::vector<ECS::TestB>> tt = ss.getTup();
    // std:: cerr << getTupleElementsNumber<TupleComp_t>() << "\n";
    ECS::Test *a = new ECS::Test();
    ECS::TestB *b = new ECS::TestB();
    // std::get<0>(tt).push_back(*a);
    ECS::ComponentsManager<2, ECS::Test, ECS::TestB> compTest;
    // compTest.addEntity({true, true});

    // ECS::EntitiesManager<4u> dd;
    // ECS::ECSManager<4u, ECS::Test, ECS::TestB> ecs;
    // ECS::SystemManager<4> cc(&dd);
    std::cout << " LLLL\n";

    return 0;
}
