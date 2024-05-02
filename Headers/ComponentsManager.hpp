#pragma once

#include <vector>
#include <cstdint>
#include <optional>
#include <memory>
#include <iostream>
#include <cassert>
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
    //cache index of entities's component
    std::array<std::vector<uint32_t>, SS> m_refComponents;

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

template <uint32_t N, Component_C... C>
class ComponentsManager
{
public:
    //DEFINIR array!!!!!!!!
    ComponentsManager() = default;
    ~ComponentsManager() = default;
    void addEntity(uint32_t numEntity, const std::array<bool, N> &vect);
    void reserveEntities(uint32_t entitiesNumber);

    template <Component_C T>
    void removeEntity(uint32_t numEntity)
    {
        assert(numEntity < m_refComponents.size());
        for(uint32_t i = 0; i < N; ++i)
        {
            std::fill(m_refComponents[numEntity].begin(), m_refComponents[numEntity].end(), std::nullopt);
        }
    }
private:
    template <Component_C T, uint32_t compNum>
    uint32_t addNewComponent()
    {
        std::vector<T> &vect = std::get<compNum>(m_tup);
        if(m_refDelComponents[compNum].empty())
        {
            vect.emplace_back(T());
            return vect.size() - 1;
        }
        uint32_t i = m_refDelComponents[compNum].back();
        m_refDelComponents[compNum].pop_back();
        vect[i] = T();
        return i;
    }
private:
    std::tuple<std::vector<C>...> m_tup;
    //cache index of entities's component
    std::vector<std::array<std::optional<uint32_t>, N>> m_refComponents;
    std::array<std::vector<uint32_t>, N> m_refDelComponents;
    std::vector<uint32_t> m_refDelEntities;
};
}


//get tuple size
template <class T>
uint32_t getTupleElementsNumber()
{
    return std::tuple_size<T>{}; // or at run time
}

// template class ECS::ComponentsManager<4u, ECS::Test, ECS::TestB>;
