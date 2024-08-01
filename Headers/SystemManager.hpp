#pragma once

#include <System.hpp>
#include <Component.hpp>
#include <vector>
#include <cstdint>
#include <iostream>
#include <cassert>
#include <memory>

using VectUI_t = std::vector<uint32_t>;
using VectVectUI_t = std::vector<VectUI_t>;

namespace ECS
{

//FORWARD DECL
// template <uint32_t T>
// class System;

template <uint32_t T>
class EntitiesManager;

template <uint32_t T>
class SystemManager
{
public:
    SystemManager() = default;
    virtual ~SystemManager() = default;
    bool addNewSystem(std::unique_ptr<System<T>> system)
    {
        if(m_numComponents == 0)
        {
            return false;
        }
        m_vectSystem.emplace_back(std::move(system));
        m_vectSystem.back()->linkSystemManager(this);
        return true;
    }
    //Warning exec this before use the classs
    inline void memEntitiesVect(const VectVectUI_t &vect)
    {
        m_vectEntities = &vect;
    }
    inline const VectVectUI_t &getVectEntities()const
    {
        return *m_vectEntities;
    }
    void execAllSystems()
    {
        for(uint32_t i = 0; i < m_vectSystem.size(); ++i)
        {
            m_vectSystem[i]->execSystem();
        }
    }

    template <typename System_C>
    System_C *getSystem(uint32_t numSystem)
    {
        if(numSystem >= m_vectSystem.size())
        {
            std::cout << "Warning: System not found.\n";
            return nullptr;
        }
        return static_cast<System_C*>(m_vectSystem[numSystem].get());
    }
private:
    const VectVectUI_t *m_vectEntities;
    const uint32_t m_numComponents = T;
    std::vector<std::unique_ptr<System<T>>> m_vectSystem;
};


// TEST=====================================================
template <uint32_t T>
class SysTest : public ECS::System<T>
{
public:
    SysTest() = default;
    virtual ~SysTest() = default;
    void execSystem()
    {
        ECS::System<T>::updateEntities();
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
        ECS::System<T>::updateEntities();
        std::cout << "kikou\n";
    }
};

// TEST=====================================================

}

