export module M_EntitiesMan;

import <cstdint>;
import <vector>;

export
{
    namespace ECS
    {
    using VectUI_t = std::vector<uint32_t>;
    using VectVectUI_t = std::vector<VectUI_t>;

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
        const uint32_t m_numComponants;
        //mem location of deleted entities for future entity creation
        VectUI_t m_cacheDeletedEntities;
        VectVectUI_t m_vectEntities;
    };
    }
}
