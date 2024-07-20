#include <iostream>
#include <ECSManager.hpp>
#include <SystemManager.hpp>>
#include <memory>
// #include <TemplateDeclaration.hpp>

// template class ECS::ECSManager<4u, ECS::Test, ECS::TestB>;
// template class ECS::ComponentsManager<4u, ECS::Test, ECS::TestB>;

using TupleComp_t = std::tuple<ECS::Test, ECS::TestB>;

int main()
{
    // ECS::Ha<4, ECS::Test, ECS::TestB> ss;
    // std::tuple<std::vector<ECS::Test>, std::vector<ECS::TestB>> tt = ss.getTup();
    // std:: cerr << getTupleElementsNumber<TupleComp_t>() << "\n";

    //================================================================================================================ComponentManager
    ECS::Test *a = new ECS::Test();
    ECS::TestB *b = new ECS::TestB();
    // std::get<0>(tt).push_back(*a);
    ECS::ComponentsManager<2, ECS::Test, ECS::TestB> compTest;
    // compTest.addEntity({1, 1}); //issue template
    compTest.addNewComponent<0, ECS::Test>();
    compTest.addEntity({1, 1});
    compTest.removeEntity(0);
    // compTest.removeEntity(5);
    //================================================================================================================ComponentManager

    //================================================================================================================SystemManager
    // ECS::SysTest<2> d;
    std::unique_ptr<ECS::SysTest<2>> sys = std::make_unique<ECS::SysTest<2>>();
    // ECS::SystemManager<4> cc;
    //================================================================================================================SystemManager

    // ECS::EntitiesManager<4u> dd;
    ECS::ECSManager<2u, ECS::Test, ECS::TestB> ecs;
    ecs.init();
    // ecs.addNewSystem(std::make_unique<ECS::SysTest<2>>());
    ecs.addNewSystem(std::move(sys));
    ECS::SysTest<2> *syss = ecs.getSystem<ECS::SysTest<2>>(0);
    std::cerr << "dsfg\n";
    syss->execSystem();
    std::cerr << "mùmùmù\n";

    ecs.execAllSystems();

    std::cout << " LLLL\n";

    return 0;
}
