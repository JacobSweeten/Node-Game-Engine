{
	"targets": [
		{
			"target_name": "binding",
			"sources": [
				"src/binding.cc"
			],
			"include_dirs": [
				"../include"
			],
			"libraries": [
				"opengl32.lib",
				"<(module_root_dir)/../lib/GLFW3.lib"
			],
			"msvs_settings": {
            	"VCCLCompilerTool": {
					'AdditionalOptions': ['/MD']
				}
        	}
		}
	]
}