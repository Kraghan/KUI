//
// Created by Kraghan on 30/01/2017.
//

#ifndef KUI_CONTAINER_HPP
#define KUI_CONTAINER_HPP

#include <Vector>
#include <SFML/System.hpp>
#include "Component.hpp"

class Container
{
public :
    void                    AddComponents                   (Component* component);
    void                    RemoveComponents                (Component* component);

protected :
    std::vector<Component*> m_apComponents;
};


#endif //KUI_CONTAINER_HPP
