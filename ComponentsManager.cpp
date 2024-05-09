#include <ComponentsManager.hpp>
#include <Component.hpp>
#include <iostream>

namespace ECS
{

//====================================================================
// template <uint32_t N, Component_C... C>
// ComponentsManager<N, C...>::ComponentsManager() : m_refComponents()
// {

// }

//====================================================================


//====================================================================
template <uint32_t N, Component_C... C>
void ComponentsManager<N, C...>::reserveEntities(uint32_t entitiesNumber)
{
    m_refComponents.reserve(entitiesNumber);
    for(uint32_t i = 0; i < N; ++i)
    {
        std::get<i>(m_tup).reserve(entitiesNumber);
    }
}

//====================================================================
template <uint32_t N, Component_C... C>
void ComponentsManager<N, C...>::clear()
{
    m_tup.clear();
    m_cacheDeletedEntities.clear();
    m_refComponents.clear();
    m_refDelComponents.clear();
}

}
