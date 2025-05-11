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
				"<(module_root_dir)/../lib/glew32s.lib",
				"opengl32.lib"
			],
			"msvs_settings": {
            	"VCCLCompilerTool": {
					'AdditionalOptions': ['/MD']
				}
        	},
			"defines": [
				"GLEW_STATIC"
			]
		}
	]
}