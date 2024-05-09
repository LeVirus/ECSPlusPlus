#pragma once

#include <cstdint>
#include <vector>

using VectUI_t = std::vector<uint32_t>;
using VectVectUI_t = std::vector<VectUI_t>;

namespace ECS
{

template<uint32_t T>
class EntitiesManager
{
public:
    EntitiesManager();
    ~EntitiesManager() = default;
    uint32_t createEntity(const VectUI_t &vect);
    void deleteEntity(uint32_t entityNum);
    void clear();
    inline const VectVectUI_t &getVectEntities()const
    {
        return m_vectEntities;
    }
private:
    const uint32_t m_numTotalComponants;
    //mem location of deleted entities for future entity creation
    VectVectUI_t m_vectEntities;
};

}
