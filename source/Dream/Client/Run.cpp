//
//  Display/Application.cpp
//  This file is part of the "Dream" project, and is released under the MIT license.
//
//  Created by Samuel Williams on 14/09/11.
//  Copyright (c) 2011 Samuel Williams. All rights reserved.
//

#include "Run.h"
#include "ApplicationDelegate.h"

#include <Dream/Client/Display.h>

namespace Dream
{
	namespace Client
	{
		void run(Ptr<IScene> scene, Ptr<Dictionary> config)
		{
			Ref<ApplicationDelegate> application_delegate = new ApplicationDelegate(scene, config);

			DREAM_ASSERT(config);

			run(application_delegate);
		}
	}
}
