#pragma once

#include <cstdint>
#include <vector>
#include <EntitiesManager.hpp>
#include <SystemManager.hpp>

using VectUI_t = std::vector<uint32_t>;
using VectVectUI_t = std::vector<VectUI_t>;

namespace ECS
{

template<uint32_t T>
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
    uint32_t m_numComponents = 0;
};
}
