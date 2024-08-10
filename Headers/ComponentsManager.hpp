#pragma once

#include <vector>
#include <cstdint>
#include <optional>
#include <memory>
#include <set>
#include <array>
#include <iostream>
#include <cassert>
#include <Component.hpp>
#include <EntitiesManager.hpp>

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
// TEST=====================================================

using VectUI_t = std::vector<uint32_t>;

template <uint32_t N, Component_C... C>
class ComponentsManager
{
    using ArrUI_t = std::array<uint32_t, N>;
    using VectArrUI_t = std::vector<ArrUI_t>;
public:
    ComponentsManager() = default;
    ~ComponentsManager() = default;

    void reserveEntities(uint32_t entitiesNumber);

    //====================================================================
    // template <Component_C T>
    void removeEntity(uint32_t numEntity)
    {
        assert(numEntity < m_refComponents.size());
        for(uint32_t i = 0; i < N; ++i)
        {
            if(m_refComponents[numEntity][i].size() > 0)
            {
                for(uint32_t j = 0; j < m_refComponents[numEntity][i].size(); ++j)
                {
                    m_refDelComponents[i].emplace_back(m_refComponents[numEntity][i][j]);
                }
                m_refComponents[numEntity][i].clear();
            }
        }
        m_cacheDeletedEntities.insert(numEntity);
        m_entitiesManager.deleteEntity(numEntity);
    }

    //====================================================================
    template <Component_C T, uint32_t NC>
    T *getComponent(uint32_t entityNum, uint32_t componentNum = 0)
    {
        assert(entityNum < m_refComponents.size());
        assert(NC < N);
        if(m_refComponents[entityNum][NC].size() == 0 || componentNum >= m_refComponents[entityNum][NC].size())
        {
            return nullptr;
        }
        uint32_t indexComp = m_refComponents[entityNum][NC][componentNum];
        std::vector<T> &vect = std::get<NC>(m_tup);
        assert(indexComp < vect.size());
        return &vect[indexComp];
    }

    //====================================================================
    uint32_t addEntity(const std::array<uint32_t, N> &vect)
    {
        uint32_t numEntity;
        uint32_t numEntityB = m_entitiesManager.createEntity(vect);
        if(!m_cacheDeletedEntities.empty())
        {
            std::set<uint32_t>::iterator it = m_cacheDeletedEntities.begin();
            numEntity = *it;
            m_cacheDeletedEntities.erase(it);
        }
        else
        {
            numEntity = m_refComponents.size();
            m_refComponents.emplace_back(std::array<VectUI_t, N>());
        }
        assert(numEntity == numEntityB);
        instanciateComponentFromEntity(numEntity, vect);
        return numEntity;
    }

    virtual void instanciateComponentFromEntity(uint32_t numEntity, const std::array<uint32_t, N> &vect) = 0;
    //====================================================================
    template <uint32_t compType, Component_C T>
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
    void clear();

    //====================================================================
    inline const VectArrUI_t &getVectEntities()const
    {
        return m_entitiesManager.getVectEntities();
    }
protected:
    std::tuple<std::vector<C>...> m_tup;
    std::set<uint32_t> m_cacheDeletedEntities;
    //cache index of entities's component
    std::vector<std::array<VectUI_t, N>> m_refComponents;
    std::array<std::vector<uint32_t>, N> m_refDelComponents;
    EntitiesManager<N> m_entitiesManager;
};
}


//get tuple size
template <class T>
uint32_t getTupleElementsNumber()
{
    return std::tuple_size<T>{}; // or at run time
}

// template class ECS::ComponentsManager<4u, ECS::Test, ECS::TestB>;
