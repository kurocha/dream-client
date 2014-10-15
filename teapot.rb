
#
#  This file is part of the "Teapot" project, and is released under the MIT license.
#

teapot_version "1.0"

define_target "dream-client" do |target|
	target.build do
		source_root = target.package.path + 'source'
		
		copy headers: source_root.glob('Dream/**/*.{h,hpp}')
		
		build static_library: "DreamClient", source_files: source_root.glob('Dream/**/*.cpp')
	end
	
	target.depends :platform
	target.depends "Build/Files"
	target.depends "Build/Clang"
	target.depends "Language/C++11"
	
	target.depends "Library/Dream"
	
	target.depends "Library/Dream/Audio"
	target.depends "Library/Dream/Imaging"
	target.depends "Library/Dream/Text"
	target.depends "Library/Dream/Graphics"
	
	# The platform specific display context:
	target.depends "Library/Dream/Client/Display"
		
	target.provides "Library/Dream/Client" do
		append linkflags "-lDreamClient"
	end
end

define_configuration "dream-client" do |configuration|
	configuration.public!
	
	configuration.require "platforms"

	configuration.require "dream"
	configuration.require "dream-imaging"
	configuration.require "dream-text"
	configuration.require "dream-graphics"
	configuration.require "dream-display"
	configuration.require "unit-test"
	
	# Provides suitable packages for building on darwin:
	host /darwin/ do
		configuration.require "dream-display-osx"
		configuration.require "dream-display-ios"
	end

	# Provides suitable packages for building on linux:
	host /linux/ do
		configuration.require "dream-display-x11"
	end

	# Provides suitable packages for building on windows:
	host /windows/ do
		configuration.require "dream-display-sdl"
	end
	
	configuration.require "dream-audio-openal"
end

define_configuration "travis" do |configuration|
	configuration[:source] = "https://github.com/dream-framework"
	
	configuration.require "platforms"
	configuration.require "dream-display-osx"
end
