//
//  Display/Application.h
//  This file is part of the "Dream" project, and is released under the MIT license.
//
//  Created by Samuel Williams on 14/09/11.
//  Copyright (c) 2011 Samuel Williams. All rights reserved.
//

#ifndef _DREAM_CLIENT_APPLICATION_H
#define _DREAM_CLIENT_APPLICATION_H

#include <Dream/Display/Application.h>
#include <Dream/Display/Scene.h>

namespace Dream
{
	namespace Client
	{
		using namespace Dream::Display;
		
		/// Helper for very basic apps.
		void run(Ptr<IApplicationDelegate> delegate);
		void run(Ptr<IScene> scene, Ptr<Dictionary> config);
		void run(Ptr<ISceneManager> scene_manager, Ptr<Dictionary> config);
	}
}

#endif
