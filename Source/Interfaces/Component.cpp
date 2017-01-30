//
// Created by Kraghan on 30/01/2017.
//

#include "../../Header/Interfaces/Component.hpp"

Component::Component()
: m_id(autoIncrementForId)
, m_visible(false)
{
    ++autoIncrementForId;
}

int Component::GetId()
{
    return m_id;
}

void Component::SetDimension(sf::Vector2f size)
{
    m_dimensions = size;
}

sf::Vector2f Component::GetDimension()
{
    return m_dimensions;
}

void Component::SetMaximumSize(sf::Vector2f size)
{
    m_maximumSize = size;
}

sf::Vector2f Component::GetMaximumSize()
{
    return m_maximumSize;
}

void Component::SetMinimumSize(sf::Vector2f size)
{
    m_minimumSize = size;
}

sf::Vector2f Component::GetMinimumSize()
{
    return m_minimumSize;
}

void Component::SetVisible(bool)
{
    m_visible = true;
}
