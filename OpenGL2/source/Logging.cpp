#include "Logging.h"



bool restart_gl_log()
{
	FILE* file = fopen (GL_LOG_FILE, "w+"); 
	if(!file)
	{
		fprintf (stderr, "ERROR: could not open %s log file for writing\n",  GL_LOG_FILE); 
		return false; 
	}
	time_t now = time (NULL); 
	char* date = ctime (&now); 
	fprintf (file, "%s log. local time %s\n", GL_LOG_FILE, date); 
	fclose (file); 
	return true; 
}

bool gl_log (const char* message, const char* filename, int line)
{
	FILE* file = fopen (GL_LOG_FILE, "a+"); 
	if(!file)
	{
		fprintf (stderr, "ERROR: could not open %s for writing\n", GL_LOG_FILE); 
		return false; 
	}
	fprintf (file, "%s:%i %s\n", filename, line, message); 
	fclose (file); 
	return true; 
}

bool printShaderInfoLog(GLuint obj)
{
	int infologLength = 0; 
	int charsWritten = 0; 
	char *infoLog;

	glGetShaderiv(obj, GL_INFO_LOG_LENGTH, &infologLength); 

	if(infologLength > 0)
	{
		infoLog = (char *) malloc (infologLength); 
		glGetShaderInfoLog(obj, infologLength, &charsWritten, infoLog); 
		printf("%s\n", infoLog); 
		free(infoLog); 
	}
	return true; 
}

bool printProgramInfoLog(GLuint obj)
{
	int infologLength = 0; 
	int charsWritten = 0; 
	char *infoLog;

	glGetProgramiv(obj, GL_INFO_LOG_LENGTH, &infologLength); 

	if(infologLength > 0)
	{
		infoLog = (char *) malloc (infologLength); 
		glGetProgramInfoLog(obj, infologLength, &charsWritten, infoLog); 
		printf("%s\n", infoLog); 
		free(infoLog); 
	}
	return true;
}


///////////////////////////////////////////TEXT FILE READER 
/*
Usage 
	 std::string vString, fString;
	 const char *vs, *fs;

// Read source code from files
	vString = textFileReader("./resources/exampleVert.glsl");
	fString = textFileReader("./resources/exampleFrag.glsl");

	vs = vString.c_str();
	fs = fString.c_str();

	// Set shader source
*/

std::string textFileReader(const char* a_szFileName) {
 
    std::string FileContents;
	std::ifstream FileStream;
 
	FileStream.open(a_szFileName, std::ios::in);
	if (FileStream.is_open()) {
        std::string Line = "";
			while(getline(FileStream,Line))
				FileContents += "\n" + Line;
			FileStream.close();
    }
	else
	{
		printf("Error: Failed to open file '%s'!\n",a_szFileName);
	}

	return FileContents;
}