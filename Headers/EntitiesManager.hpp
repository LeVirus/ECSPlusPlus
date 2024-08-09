#pragma once

#include <cstdint>
#include <vector>
#include <iostream>
#include <cassert>

using VectUI_t = std::vector<uint32_t>;

namespace ECS
{

template<uint32_t T>
class EntitiesManager
{
    using ArrUI_t = std::array<uint32_t, T>;
    using VectArrUI_t = std::vector<ArrUI_t>;
public:
    EntitiesManager() = default;
    ~EntitiesManager() = default;

    uint32_t createEntity(const std::array<uint32_t, T> &vect)
    {
        uint32_t final;
        if(m_numTotalComponants == 0)
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

    void deleteEntity(uint32_t entityNum);
    void clear();
    inline const VectArrUI_t &getVectEntities()const
    {
        return m_vectEntities;
    }
private:
    const uint32_t m_numTotalComponants = T;
    //mem location of deleted entities for future entity creation
    VectArrUI_t m_vectEntities;
    VectUI_t m_cacheDeletedEntities;
};

}
