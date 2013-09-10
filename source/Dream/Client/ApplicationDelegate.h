//
//  ApplicationDelegate.h
//  File file is part of the "dream-client" project and released under the .
//
//  Created by Samuel Williams on 10/9/2013.
//  Copyright, 2013, by Samuel Williams. All rights reserved.
//

#ifndef DREAM_CLIENT_APPLICATIONDELEGATE_H
#define DREAM_CLIENT_APPLICATIONDELEGATE_H

#include <Dream/Display/Application.h>
#include <Dream/Display/Scene.h>

namespace Dream
{
	namespace Client
	{
		using namespace Display;
		
		class ApplicationDelegate : public Object, implements IApplicationDelegate {
		public:
			ApplicationDelegate(Ptr<IScene> scene, Ptr<Dictionary> config);
			virtual ~ApplicationDelegate();

		protected:
			Ref<IScene> _scene;
			Ref<Dictionary> _config;
			Ref<IContext> _context;
			Ref<Events::Thread> _thread;
			Ref<SceneManager> _scene_manager;

			virtual void application_did_finish_launching (IApplication * application);

			virtual void application_will_enter_background (IApplication * application);
			virtual void application_did_enter_foreground (IApplication * application);
		};
		
		Ref<Resources::ILoader> default_resource_loader ();
	}
}

#endif
