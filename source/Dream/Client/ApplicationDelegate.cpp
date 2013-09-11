//
//  ApplicationDelegate.cpp
//  File file is part of the "dream-client" project and released under the .
//
//  Created by Samuel Williams on 10/9/2013.
//  Copyright, 2013, by Samuel Williams. All rights reserved.
//

#include "ApplicationDelegate.h"

#include <Dream/Events/Thread.h>

#include <Dream/Imaging/Image.h>
#include <Dream/Text/Font.h>
#include <Dream/Audio/Sound.h>
#include <Dream/Audio/OggResource.h>
#include <Dream/Graphics/ShaderFactory.h>

namespace Dream
{
	namespace Client
	{
		ApplicationDelegate::ApplicationDelegate(Ptr<IScene> scene, Ptr<Dictionary> config) : _scene(scene), _config(config)
		{
		}

		ApplicationDelegate::~ApplicationDelegate()
		{
			_context->stop();
			_thread->stop();
		}

		void ApplicationDelegate::application_did_finish_launching (IApplication * application)
		{
			_context = application->create_context(_config);

			_thread = new Events::Thread;
			_thread->start();

			Path runtime_path;

			_config.get("Application.RuntimePath", runtime_path);
			Ref<ILoader> loader = default_resource_loader(runtime_path);
			
			_scene_manager = new SceneManager(_context, _thread->loop(), loader);
			_scene_manager->push_scene(_scene);

#ifdef DREAM_DEBUG
			logger()->log(LOG_INFO, "Debugging mode active.");
#else
			logger()->log(LOG_INFO, "Debugging mode inactive.");
#endif
		}

		void ApplicationDelegate::application_will_enter_background (IApplication * application)
		{
			logger()->log(LOG_INFO, "Application entering background...");

			EventInput suspend_event(EventInput::PAUSE);
			_scene_manager->process_input(_context, suspend_event);

			_context->stop();
			//_thread->stop();
		}

		void ApplicationDelegate::application_did_enter_foreground (IApplication * application)
		{
			logger()->log(LOG_INFO, "Application entering foreground...");

			//_thread->start();
			_context->start();

			EventInput resume_event(EventInput::RESUME);
			_scene_manager->process_input(_context, resume_event);
		}
		
		Ref<Resources::ILoader> default_resource_loader (Path path)
		{
			// Something like this would be nice?
			// Imaging::register_loaders(loader);
			// Audio::register_loaders(loader);
			// Text::register_loaders(loader);
			// Graphics::register_loaders(loader);
			
			Ref<ILoader> loader = new Resources::Loader(path);
			
			loader->add_loader(new Imaging::Image::Loader);
			loader->add_loader(new Audio::Sound::Loader);
			loader->add_loader(new Audio::OggResource::Loader);
			loader->add_loader(new Text::Font::Loader);
			loader->add_loader(new Graphics::ShaderFactory::Loader);
			
			return loader;
		}
	}
}
