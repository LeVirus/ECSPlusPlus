export module EntitiesMan;

// #include <stdlib.h>
import <cstdint>;
import <vector>;

export
{
    using VectUI_t = std::vector<uint32_t>;
    using VectVectUI_t = std::vector<VectUI_t>;

    class EntitiesManager
    {
    public:
        EntitiesManager();
        ~EntitiesManager() = default;
        void setNumberComponents(uint32_t num);
        void createEntity(const VectUI_t &vect);
    private:
        uint32_t m_numComponants = 0;
        VectUI_t m_cacheDeletedEntities;
        VectVectUI_t m_vectEntities;
    };
}
