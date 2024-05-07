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

using VectUI_t = std::vector<uint32_t>;

template <uint32_t N, Component_C... C>
class ComponentsManager
{
public:
    //DEFINIR array!!!!!!!!
    ComponentsManager() = default;
    ~ComponentsManager() = default;

    void reserveEntities(uint32_t entitiesNumber);

    //====================================================================
    template <Component_C T>
    void removeEntity(uint32_t numEntity)
    {
        assert(numEntity < m_refComponents.size());
        for(uint32_t i = 0; i < N; ++i)
        {
            if(m_refComponents[numEntity][i])
            {
                for(uint32_t j = 0; j < m_refComponents[numEntity][i].size(); ++j)
                {
                    m_refDelComponents[i].emplace_back(m_refComponents[numEntity][i][j]);
                }
                m_refComponents[numEntity][i] = std::nullopt;
            }
        }
    }

    //====================================================================
    template <Component_C T>
    std::optional<T> &getComponent(uint32_t entityNum, uint32_t componentType, uint32_t componentNum = 0)
    {
        assert(entityNum < m_refComponents.size());
        assert(componentType < N);
        if(m_refComponents[entityNum][componentType] || componentNum >= m_refComponents[entityNum][componentType].size())
        {
            return std::nullopt;
        }
        uint32_t indexComp = m_refComponents[entityNum][componentType][componentNum];
        std::vector<T> &vect = std::get<componentType>(m_tup);
        return vect[indexComp];
    }

    //====================================================================
    void addEntity(uint32_t numEntity, const std::array<uint32_t, N> &vect)
    {
        //if num entity > existing component ==> incoherence
        assert(numEntity <= m_refComponents.size());
        if(numEntity == m_refComponents.size())
        {
            m_refComponents.emplace_back(std::array<VectUI_t, N>());
        }
        for(uint32_t i = 0; i < N; ++i)
        {
            if(vect[i] > 0)
            {
                (*m_refComponents[numEntity][i]).reserve(vect[i]);
                for(uint32_t j = 0; j < vect[i]; ++j)
                {
                    // std::vector<T> &vect = std::get<j>(m_tup);
                    (*m_refComponents[numEntity][i]).emplace_back(addNewComponent<i>());
                }
            }
        }
    }
private:
    //====================================================================
    template <Component_C T, uint32_t compType>
    uint32_t addNewComponent()
    {
        std::vector<T> &vect = std::get<compType>(m_tup);
        //if no empty case add new one
        if(m_refDelComponents[compType].empty())
        {
            vect.emplace_back(T());
            return vect.size() - 1;
        }
        uint32_t i = m_refDelComponents[compType].back();
        m_refDelComponents[compType].pop_back();
        vect[i] = T();
        return i;
    }
private:
    std::tuple<std::vector<C>...> m_tup;
    //cache index of entities's component
    std::vector<std::array<std::optional<VectUI_t>, N>> m_refComponents;
    std::array<std::vector<uint32_t>, N> m_refDelComponents;
};
}


//get tuple size
template <class T>
uint32_t getTupleElementsNumber()
{
    return std::tuple_size<T>{}; // or at run time
}

// template class ECS::ComponentsManager<4u, ECS::Test, ECS::TestB>;
