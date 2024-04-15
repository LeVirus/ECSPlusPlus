#include "System.hpp"

namespace ECS
{

//====================================================================
template <uint32_t T>
System<T>::System() : m_arrEntities(T)
{

}

//====================================================================
template<uint32_t T>
void System<T>::updateEntities()
{
    const VectVectUI_t &vect = m_systemManager->getVectEntities();
    bool ok;
    for(uint32_t i = 0; i < vect.size(); ++i)
    {
        ok = true;
        for(uint32_t j : m_cacheUsedComponent)
        {
            if(m_arrEntities[j] != vect[i][j])
            {
                ok = false;
                break;
            }
        }
        m_usedEntities.insert(i);
    }
}

//====================================================================
template<uint32_t T>
void System<T>::addComponentsToSystem(uint32_t typeComponent, uint32_t numberOfComponent)
{
    assert(m_arrEntities.size() < typeComponent);
    m_arrEntities[typeComponent] = numberOfComponent;
    m_cacheUsedComponent.insert(typeComponent);
}

}
