#include <EntitiesManager.hpp>

namespace ECS
{

//====================================================================
template <uint32_t T>
EntitiesManager<T>::EntitiesManager() : m_numComponants(T)
{

}

//====================================================================
template <uint32_t T>
uint32_t EntitiesManager<T>::createEntity(const VectUI_t &vect)
{
    uint32_t final;
    if(m_numComponants == 0)
    {
        std::cout << "EntitiesManager::createEntity // Error : Components num is not set\n";
    }
    if(m_cacheDeletedEntities.empty())
    {
        final = m_vectEntities.size();
        m_vectEntities.emplace_back(vect);
    }
    else
    {
        assert(m_vectEntities.size() < m_cacheDeletedEntities.back());
        m_vectEntities[m_cacheDeletedEntities.back()] = vect;
        final = m_cacheDeletedEntities.back();
        m_cacheDeletedEntities.pop_back();
    }
    return final;
}

//====================================================================
template <uint32_t T>
void EntitiesManager<T>::deleteEntity(uint32_t entityNum)
{
    if(entityNum >= m_vectEntities.size())
    {
        return;
    }
    if(std::find(m_cacheDeletedEntities.begin(), m_cacheDeletedEntities.end(), entityNum) != m_cacheDeletedEntities.end())
    {
        return;
    }
    m_cacheDeletedEntities.emplace_back(entityNum);
    std::fill(m_vectEntities[entityNum].begin(), m_vectEntities[entityNum].end(), 0);
}

//====================================================================
template <uint32_t T>
void EntitiesManager<T>::clear()
{
    m_cacheDeletedEntities.clear();
    m_vectEntities.clear();
}

}
