#include <iostream>
#include <ECSManager.hpp>
#include <SystemManager.hpp>
#include <memory>
// #include <TemplateDeclaration.hpp>

// template class ECS::ECSManager<4u, ECS::Test, ECS::TestB>;
// template class ECS::ComponentsManager<4u, ECS::Test, ECS::TestB>;

using TupleComp_t = std::tuple<ECS::Test, ECS::TestB>;
using Ecsm_t = ECS::ECSManager<2u, ECS::Test, ECS::TestB>;

// TEST=====================================================
template <uint32_t T>
class SysTest : public ECS::System<T>
{
public:
    SysTest() = default;
    virtual ~SysTest() = default;
    void execSystem()
    {
        ECS::System<T>::updateEntities/*<ECS::Test, ECS::TestB>*/();
        std::cout << "LOL\n";
    }
};

template <uint32_t T>
class SysATest : public ECS::System<T>
{
public:
    SysATest() = default;
    ~SysATest() = default;
    void execSystem()
    {
        ECS::System<T>::updateEntities/*<ECS::Test, ECS::TestB>*/();
        std::cout << "kikou\n";
    }
};

// TEST=====================================================



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
    std::unique_ptr<SysTest<2>> sys = std::make_unique<SysTest<2>>();
    // ECS::SystemManager<4> cc;
    //================================================================================================================SystemManager
    ECS::ECSManager<2u, ECS::Test, ECS::TestB>::instance();

    // ECS::EntitiesManager<4u> dd;
    Ecsm_t::instance();
    // ecs.addNewSystem(std::make_unique<ECS::SysTest<2>>());
    Ecsm_t::instance().addNewSystem(std::move(sys));
    SysTest<2> *syss = Ecsm_t::instance().getSystem<SysTest<2>>(0);
    syss->execSystem();
    Ecsm_t::instance().execAllSystems();
    return 0;
}

