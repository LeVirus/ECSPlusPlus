export module M_ECSMain;

import <cstdint>;
import <vector>;

// export import :format;

export import :M_EntitiesMan;
export import :M_SystemMan;

export
{
    namespace ECS
    {

    using VectUI_t = std::vector<uint32_t>;
    using VectVectUI_t = std::vector<VectUI_t>;
        template<uint32_t T>
        class ECSManager
        {
        public:
            ECSManager();
            ~ECSManager() = default;
            inline const VectVectUI_t &getVectEntities()const
            {
                return m_entitiesManager.getVectEntities();
            }
        private:
            EntitiesManager<T> m_entitiesManager;
            SystemManager<T> m_systemsManager;
            uint32_t m_numComponents = 0;
        };

        //====================================================================
        template <uint32_t T>
        ECSManager<T>::ECSManager() :
            m_systemsManager(&m_entitiesManager),  m_numComponents(T)
        {

        }

    }
}
