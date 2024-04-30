#pragma once

#include <vector>
#include <cstdint>
#include <memory>
#include <iostream>
#include <Component.hpp>

#include <tuple>



namespace ECS
{

// TEST=====================================================
// using VectorTemp = std::vector<T>;
template <uint32_t SS, Component_C... C>
struct Ha
{
    std::tuple<std::vector<C>...> m_tup;
    // std::array<std::vector<T...>, SS> m_contComponents;
    //cache index of entities's component
    std::vector<std::array<uint32_t, SS>> m_refComponents;

    std::tuple<std::vector<C>...> getTup()
    {
        return m_tup;
    }

    template <Component_C SC, uint32_t compNum>
    void add(SC &comp)
    {
        std::vector<SC> &vect = std::get<compNum>(m_tup);
        vect.emplace_back(comp);
    }
};
// TEST=====================================================

struct Test : ECS::Component
{
    Test() = default;
    ~Test() = default;
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


//get tuple size
template <class T>
uint32_t getTupleElementsNumber()
{
    return std::tuple_size<T>{}; // or at run time
}

// template class ECS::ComponentsManager<4u, ECS::Test, ECS::TestB>;
