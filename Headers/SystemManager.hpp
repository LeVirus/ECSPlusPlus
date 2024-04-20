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
    SystemManager(EntitiesManager<T> *entitiesMan);
    ~SystemManager() = default;
    bool addNewSystem(std::unique_ptr<System<T>> system);
    inline const VectVectUI_t &getVectEntities()const
    {
        return m_entitiesMan->getVectEntities();
    }
private:
    const EntitiesManager<T> *m_entitiesMan = nullptr;
    uint32_t m_numComponents = 0;
    std::vector<std::unique_ptr<System<T>>> m_vectSystem;
};

}

