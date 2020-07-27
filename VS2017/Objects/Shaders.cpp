#include "Shaders.h"
// Code for specular lighting portion of the shaders inspired from: https://learnopengl.com/Lighting/Basic-Lighting

const char* Shaders::getVertexShaderSource()
{
    // Insert Shaders here ...
   // For now, you use a string for your shader code, in the assignment, shaders will be stored in .glsl files

    return
        "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;"
        "layout (location = 1) in vec3 aNormal;"
        ""
		"uniform vec3 lightPos;" // view-space
        "uniform mat4 worldMatrix = mat4(1.0);"
        "uniform mat4 viewMatrix = mat4(1.0);" // default value for view matrix (identity)
        "uniform mat4 projectionMatrix = mat4(1.0);"
        ""
        //"out vec3 vertexColor;"
        "out vec3 FragPos;"
        "out vec3 Normal;"
		"out vec3 LightPos;" // added for view space test
		""
        "void main()"
        "{"
        //"   vertexColor = aColor;"
        "   mat4 modelViewProjection = projectionMatrix * viewMatrix * worldMatrix;"
        "   FragPos = vec3(modelViewProjection * vec4(aPos, 1.0));"
		//"   Normal = mat3(transpose(inverse(worldMatrix))) * aNormal; " // World space technique, kept for debugging purposes
        "   Normal = mat3(transpose(inverse(viewMatrix * worldMatrix))) * aNormal; "  // view-space
		"   LightPos = vec3(viewMatrix * vec4(lightPos, 1.0));" // view-space
        "   gl_Position = modelViewProjection * vec4(aPos.x, aPos.y, aPos.z, 1.0);"
        "}";
}

const char* Shaders::getFragmentShaderSource()
{
    return
        "#version 330 core\n"
        "out vec4 FragColor;"
        ""
        "in vec3 Normal;"
        "in vec3 FragPos;"
		"in vec3 LightPos;" // view-space
        ""
        "uniform vec3 lightPos;"
        "uniform vec3 viewPos;"
        "uniform vec3 lightColor;"
        "uniform vec3 objectColor;"
        ""
        ""
        "void main()"
        "{"
        "   // ambient\n"
        "   float ambientStrength = 0.1;"
        "   vec3 ambient = ambientStrength * lightColor;"
        ""
        "   // diffuse\n"
        "   vec3 norm = normalize(Normal);"
        "   vec3 lightDir = normalize(lightPos - FragPos);"
        "   float diff = max(dot(norm, lightDir), 0.0);"
        "   vec3 diffuse = diff * lightColor;"
        ""
        "   // specular\n"
		"   float specularStrength = 0.5;"
		//"   vec3 viewDir = normalize(viewPos - FragPos);" // World space technique, kept for debugging purposes
        "   vec3 viewDir = normalize(FragPos);" // view-space
		"   vec3 reflectDir = reflect(-lightDir, norm);"
		"   float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128);"
		"   vec3 specular = specularStrength * spec * lightColor;"
		""
        "   vec3 result = (ambient + diffuse + specular) * objectColor;"
        "   FragColor = vec4(result, 1.0);"
        "}";
}

int Shaders::compileAndLinkShaders()
{
    // compile and link shader program
     // return shader program id
     // ------------------------------------

     // vertex shader
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char* vertexShaderSource = getVertexShaderSource();
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // fragment shader
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragmentShaderSource = getFragmentShaderSource();
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // link shaders
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}
