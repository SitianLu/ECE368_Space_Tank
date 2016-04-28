//
//  Menu.h
//  test2
//
//  Created by Maxim Baldakov on 4/24/16.
//  Copyright (c) 2016 Maxim Baldakov. All rights reserved.
//
#include <iostream>
#include <sstream>

#ifndef test2_Menu_h
#define test2_Menu_h

class GameSettings {
public:
	std::string Player1;
	std::string Player2;
	int Map;
};

GameSettings StartMenu();
#endif
