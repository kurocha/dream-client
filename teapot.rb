
#
#  This file is part of the "Teapot" project, and is released under the MIT license.
#

teapot_version "0.8.0"

define_target "dream-client" do |target|
	target.build do |environment|
		build_directory(package.path, 'source', environment)
	end
	
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
