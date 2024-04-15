#include <ECSManager.hpp>

namespace ECS
{

//====================================================================
template <uint32_t T>
ECSManager<T>::ECSManager() :
    m_systemsManager(&m_entitiesManager),  m_numComponents(T)
{

}

}
