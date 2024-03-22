export module M_SystemMan;

import <vector>;
import <cstdint>;
import <memory>;

import M_System;
import M_EntitiesMan;

export
{
    namespace ECS
    {

    template <uint32_t T>
    class SystemManager
    {
    public:
        SystemManager(const EntitiesManager *entitiesMan);
        ~SystemManager() = default;
        bool addNewSystem(std::unique_ptr<System<T>> system);
        inline const VectVectUI_t &getVectEntities()const
        {
            return m_entitiesMan->getVectEntities();
        }
    private:
        const EntitiesManager *m_entitiesMan = nullptr;
        uint32_t m_numComponents = 0;
        std::vector<std::unique_ptr<System<T>>> m_vectSystem;
    };

    }
}
