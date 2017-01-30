//
// Created by Kraghan on 30/01/2017.
//

#ifndef KUI_WINDOW_HPP
#define KUI_WINDOW_HPP

#include "../Panels/KPanel.hpp"
#include "../Buttons/KMenuBar.hpp"

class KWindow : public Container
{
public :
    void                SetContentPane                  (Container* panel);
    void                Pack                            ();

private :
    KMenuBar*           m_menuBar;
    std::string         m_title;
};


#endif //KUI_WINDOW_HPP
