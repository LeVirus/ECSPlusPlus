export module M_Component;

import <vector>;
import <cstdint>;
import <memory>;

export
{
    namespace ECS
    {
        struct Component
        {
            ~Component() = default;
        protected:
            Component();
        };
        template <typename S>
        concept Component_C = std::derived_from<S, Component>;
    }
}
