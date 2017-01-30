//
// Created by Kraghan on 30/01/2017.
//

#ifndef KUI_COMPONENT_HPP
#define KUI_COMPONENT_HPP

#include "Container.hpp"

class Component : Container
{
public:
    explicit                Component               ();
    int                     GetId                   ();
    void                    SetDimension            (sf::Vector2f size);
    sf::Vector2f            GetDimension            ();
    void                    SetMaximumSize          (sf::Vector2f size);
    sf::Vector2f            GetMaximumSize          ();
    void                    SetMinimumSize          (sf::Vector2f size);
    sf::Vector2f            GetMinimumSize          ();
    void                    SetVisible              (bool visible);
private:
    static int              autoIncrementForId = 0;
    sf::Vector2f            m_dimensions;
    sf::Vector2f            m_minimumSize;
    sf::Vector2f            m_maximumSize;
    int                     m_id;
    bool                    m_visible;
};


#endif //KUI_COMPONENT_HPP
