export module M_EntitiesMan;

import <cstdint>;
import <vector>;

export
{
    namespace ECS
    {
    using VectUI_t = std::vector<uint32_t>;
    using VectVectUI_t = std::vector<VectUI_t>;

    class EntitiesManager
    {
    public:
        EntitiesManager();
        ~EntitiesManager() = default;
        void setNumberComponents(uint32_t num);
        uint32_t createEntity(const VectUI_t &vect);
        void deleteEntity(uint32_t entityNum);
        void clear();
        inline const VectVectUI_t &getVectEntities()const
        {
            return m_vectEntities;
        }
    private:
        uint32_t m_numComponants = 0;
        VectUI_t m_cacheDeletedEntities;
        VectVectUI_t m_vectEntities;
    };
    }
}
