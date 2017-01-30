//
// Created by Kraghan on 30/01/2017.
//

#include "../../Header/Interfaces/Container.hpp"

void Container::AddComponents(Component *component)
{
    m_apComponents.push_back(component);
}

void Container::RemoveComponents(Component *component)
{
    for(unsigned i = 0; i < m_apComponents.size(); ++i)
    {
        if(m_apComponents[i]->GetId() == component->GetId())
        {
            m_apComponents.erase(m_apComponents.begin() + i);
            break;
        }
    }
}
