#pragma once

#include <vector>
#include <cstdint>
#include <memory>
#include <Component.hpp>



namespace ECS
{

struct Test : ECS::Component
{
    int m_b;
};

struct TestB : ECS::Component
{
    int m_bs;
};

template <uint32_t T, Component_C... C>
class ComponentsManager
{
public:
    ComponentsManager();
    ~ComponentsManager() = default;
    void addEntity(const std::array<bool, T> &vect);
    void addNewComponentType(C...);
    void addNewComponentType();
private:
    // template <Component_C... C>
    std::array<std::vector<C...>, T> m_contComponents;
    //cache index of entities's component
    std::vector<std::array<uint32_t, T>> m_refComponents;
};
}

// template class ECS::ComponentsManager<4u, ECS::Test, ECS::TestB>;
