#pragma once

#include <System.hpp>
#include <vector>
#include <cstdint>
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
    }
};

// TEST=====================================================

}

