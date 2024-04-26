#pragma once

#include <cstdint>
#include <vector>
#include <EntitiesManager.hpp>
#include <SystemManager.hpp>
#include <ComponentsManager.hpp>

using VectUI_t = std::vector<uint32_t>;
using VectVectUI_t = std::vector<VectUI_t>;

namespace ECS
{

template<uint32_t T, Component_C... C>
class ECSManager
{
public:
    ECSManager();
    ~ECSManager() = default;
    inline const VectVectUI_t &getVectEntities()const
    {
        return m_entitiesManager.getVectEntities();
    }
private:
    EntitiesManager<T> m_entitiesManager;
    SystemManager<T> m_systemsManager;
    // template <uint32_t T, Component_C... C>
    ComponentsManager<T, C...> m_componentsManager;
    uint32_t m_numComponents = 0;
};
}

// template class ECS::ECSManager<4u, Test, TestB>;

// template     ECS::ECSManager<4u, Test, TestB> ecs;
