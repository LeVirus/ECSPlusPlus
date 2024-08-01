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
    static ECSManager &instance()
    {
        static ECSManager ecs;
        return ecs;
    }
    ~ECSManager() = default;
    void init()
    {
        m_systemsManager.memEntitiesVect(m_entitiesManager.getVectEntities());
    }
    inline const VectVectUI_t &getVectEntities()const
    {
        return m_entitiesManager.getVectEntities();
    }
    ///////////////////////////////////////////////////////////SystemManager
    inline void execAllSystems()
    {
        m_systemsManager.execAllSystems();
    }
    inline bool addNewSystem(std::unique_ptr<System<T>> system)
    {
        return m_systemsManager.addNewSystem(std::move(system));
    }
    template <typename System_C>
    System_C *getSystem(uint32_t numSystem)
    {
        return m_systemsManager.template getSystem<System_C>(numSystem);
    }
private:
    ECSManager()
    {
        assert(T == sizeof...(C));
        init();
    }
    EntitiesManager<T> m_entitiesManager;
    SystemManager<T> m_systemsManager;
    // template <uint32_t T, Component_C... C>
    ComponentsManager<T, C...> m_componentsManager;
    const uint32_t m_numComponents = T;
};
}
