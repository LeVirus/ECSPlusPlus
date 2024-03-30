export module M_ComponentsMan;

import <vector>;
import <cstdint>;
import <memory>;

// import M_Component;

struct Component;

export
{
    using VectComp_t = std::vector<std::unique_ptr<Component>>;
    namespace ECS
    {
        template <uint32_t T>
        class ComponentsManager
        {
        public:
            ComponentsManager();
            ~ComponentsManager() = default;
        private:
            //T == ComponentNumber
            std::array<VectComp_t, T> m_contComponents;
        };
    }
}
