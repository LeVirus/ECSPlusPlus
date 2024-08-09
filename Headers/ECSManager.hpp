#pragma once

#include <cstdint>
#include <vector>
#include <SystemManager.hpp>
#include <System.hpp>
#include <ComponentsManager.hpp>


namespace ECS
{

template<uint32_t T, Component_C... C>
class ECSManager
{
    using ArrUI_t = std::array<uint32_t, T>;
    using VectArrUI_t = std::vector<ArrUI_t>;
public:
    static ECSManager &instance()
    {
        static ECSManager ecsMan;
        return ecsMan;
    }
    ~ECSManager() = default;
    inline const VectVectUI_t &getVectEntities()const
    {
        return m_componentsManager.getVectEntities();
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
    void addEntities(const std::array<uint32_t, T> &vect)
    {
        m_componentsManager.addEntity(vect);
    }
private:
    ECSManager()
    {
        assert(T == sizeof...(C));
    }
    SystemManager<T> m_systemsManager;
    // template <uint32_t T, Component_C... C>
    ComponentsManager<T, C...> m_componentsManager;
    const uint32_t m_numComponents = T;
};
}
