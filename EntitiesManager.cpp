#include <EntitiesManager.hpp>
#include <algorithm>

namespace ECS
{

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

template class ECS::EntitiesManager<4u>;
