
			#version 330\n
		in vec4 vColor;
		in vec2 UV;
		out vec4 outColour;
		uniform sampler2D diffuseTexture;
		void main () {
			outColour =  texture2D(diffuseTexture, UV) * vColor;
		}