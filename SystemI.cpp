module;

module M_System;

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
        for(uint32_t j = 0; j < m_cacheUsedComponent.size(); ++j)
        {
            if(m_arrEntities[m_cacheUsedComponent[j]] != m_cacheUsedComponent[j])
            {
                ok = false;
                break;
            }
        }
        m_usedEntities.emplace_back(vect[i]);
    }
}

}
