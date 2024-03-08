module;

module EntitiesMan;

import <iostream>;
import <cassert>;

//==============================================
EntitiesManager::EntitiesManager()
{

}

//==============================================
void EntitiesManager::setNumberComponents(uint32_t num)
{
    m_numComponants = num;
}

//==============================================
void EntitiesManager::createEntity(const VectUI_t &vect)
{
    if(m_numComponants == 0)
    {
        std::cout << "EntitiesManager::createEntity // Error : Components num is not set\n";
    }
    if(m_cacheDeletedEntities.empty())
    {
        m_vectEntities.emplace_back(vect);
    }
    else
    {
        assert(m_vectEntities.size() < m_cacheDeletedEntities.back());
        m_vectEntities[m_cacheDeletedEntities.back()] = vect;
        m_cacheDeletedEntities.pop_back();
    }
}
