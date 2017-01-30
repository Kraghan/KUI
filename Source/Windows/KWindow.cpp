//
// Created by Kraghan on 30/01/2017.
//

#include "../../Header/Windows/KWindow.hpp"

void KWindow::SetContentPane(Container *panel)
{
    for(unsigned i = 0; i < panel->m_apComponents.size(); ++i)
    {
        m_apComponents.push_back(panel->m_apComponents[i]);
    }
}

void KWindow::Pack()
{
    // Todo Pack
}
