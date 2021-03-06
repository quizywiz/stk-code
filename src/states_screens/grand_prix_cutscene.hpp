//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2014 konstin
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 3
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef HEADER_GRAND_PRIX_CUTSCENE_HPP
#define HEADER_GRAND_PRIX_CUTSCENE_HPP

#include "guiengine/screen.hpp"
#include "guiengine/widgets/button_widget.hpp"
#include "race/race_manager.hpp"
#include "states_screens/dialogs/enter_gp_name_dialog.hpp"

#include <string>

class GrandPrixCutscene: public GUIEngine::CutsceneScreen,
                         public EnterGPNameDialog::INewGPListener
{
    friend class GUIEngine::ScreenSingleton<GrandPrixCutscene>;
public:
    GrandPrixCutscene(const char * filename) : CutsceneScreen(filename) {}
protected:
    void saveGPButton();

    /** implement callback from INewGPListener */
    void onNewGPWithName(const irr::core::stringw& name);

    // implement callbacks from parent class GUIEngine::Screen
    void eventCallback(GUIEngine::Widget* widget,
                       const std::string& name,
                       const int playerID) OVERRIDE;
    bool onEscapePressed() OVERRIDE;
    void tearDown() OVERRIDE;
};

#endif
