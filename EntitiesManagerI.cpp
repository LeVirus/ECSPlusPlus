module;

import <iostream>;
import <cassert>;
import <algorithm>;

module EntitiesMan;

//====================================================================
EntitiesManager::EntitiesManager()
{

}

//====================================================================
void EntitiesManager::setNumberComponents(uint32_t num)
{
    m_numComponants = num;
}

//====================================================================
uint32_t EntitiesManager::createEntity(const VectUI_t &vect)
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
void EntitiesManager::deleteEntity(uint32_t entityNum)
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
void EntitiesManager::clear()
{
    m_cacheDeletedEntities.clear();
    m_vectEntities.clear();
}
