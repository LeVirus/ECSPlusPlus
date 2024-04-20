#include <ECSManager.hpp>
#include <cstdint>

namespace ECS
{

//====================================================================
template <uint32_t T>
ECSManager<T>::ECSManager() :m_systemsManager(&m_entitiesManager) , m_numComponents(T)
{

}

}

template ECS::ECSManager<4>::ECSManager(); // OK: explicit instantiation

// template class ECS::ECSManager<4>;
// template class ECS::EntitiesManager<4u>;

