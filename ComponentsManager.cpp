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
template <uint32_t N, Component_C... C>
void ComponentsManager<N, C...>::addEntity(uint32_t numEntity, const std::array<bool, N> &vect)
{
    //if num entity > existing component ==> incoherence
    assert(numEntity <= m_refComponents.size());
    if(numEntity == m_refComponents.size())
    {
        m_refComponents.emplace_back(std::array<uint32_t, N>());
    }
    for(uint32_t i = 0; i < N; ++i)
    {
        if(vect[i])
        {
            m_refComponents[numEntity][i] = addNewComponent<i>();
        }
    }
}

//====================================================================
template <uint32_t N, Component_C... C>
void ComponentsManager<N, C...>::reserveEntities(uint32_t entitiesNumber)
{
    m_refComponents.reserve(entitiesNumber);
    m_refDelEntities.reserve(entitiesNumber);
    for(uint32_t i = 0; i < N; ++i)
    {
        std::get<i>(m_tup).reserve(entitiesNumber);
    }
}

}
