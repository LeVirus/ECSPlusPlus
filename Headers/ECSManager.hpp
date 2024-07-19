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
    ECSManager() = default;
    ~ECSManager() = default;
    void init()
    {
        m_systemsManager.memEntitiesVect(m_entitiesManager.getVectEntities());
    }
    inline const VectVectUI_t &getVectEntities()const
    {
        return m_entitiesManager.getVectEntities();
    }
    inline bool addNewSystem(std::unique_ptr<System<T>> system)
    {
        return m_systemsManager.addNewSystem(std::move(system));
    }
private:
    EntitiesManager<T> m_entitiesManager;
    SystemManager<T> m_systemsManager;
    // template <uint32_t T, Component_C... C>
    ComponentsManager<T, C...> m_componentsManager;
    const uint32_t m_numComponents = T;
};
}
