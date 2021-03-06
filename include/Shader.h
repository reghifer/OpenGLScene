#ifndef SHADER_INCLUDE
#define SHADER_INCLUDE

#define ERROR_MAX_LENGTH 500

#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include "logger.h"
#include <string>


/** \brief A graphic program.*/
class Shader {
	public:
		/** \brief the shader constructor. Should never be called alone (use loader functions)*/
		Shader();

		/* \brief Destructor. Destroy the shader component created */
		~Shader();

		/** \brief get the program ID stored in the graphic memory of this shader.
		 * \return the program ID */
		int getProgramID() const;

		/** \brief get the vertex ID stored in the graphic memory of this shader.
		 * \return the vertex ID */
		int getVertexID() const;

		/** \brief get the fragment ID stored in the graphic memory of this shader.
		 * \return the fragment ID */
		int getFragID() const;

		void Bind() const;
		void Unbind() const;

		void SetUniform1i(const std::string& name, int value);
		void SetUniform1f(const std::string& name, float value);
		void SetUniform3f(const std::string& name, float v0, float v1, float v2);
		void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
		void SetUniformVec3f(const std::string& name, glm::vec3 vector);
		void SetUniformVec4f(const std::string& name, glm::vec4 vector);
		void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);

		/** \brief create a shader from a vertex and a fragment file.
		 * \param vertexFile the vertex file.
		 * \param fragmentFile the fragment file.
		 *
		 * \return the Shader constructed or NULL if error*/
		static Shader* loadFromFiles(FILE* vertexFile, FILE* fragFile, unsigned int count, va_list args);

		/** \brief create a shader from a vertex and a fragment string.
		 * \param vertexString the vertex string.
		 * \param fragmentString the fragment string.
		 *
		 * \return the Shader constructed or NULL if error
		 * */
		static Shader* loadFromStrings(const std::string& vertexString, const std::string& fragString, unsigned int count, va_list args);
	private:
		GLuint m_programID; /*!< The shader   program ID*/
		GLuint m_vertexID;  /*!< The vertex   shader  ID*/
		GLuint m_fragID;    /*!< The fragment shader  ID*/
		std::unordered_map<std::string, int> m_UniformLocationCache;
		int GetUniformLocation(const std::string& name);


		/** \brief Bind the attributes key string by an ID
		 * \param code the attribute name
		 * \param type the type of this attribute (vertex, fragment, etc.)*/
		static int loadShader(const std::string& code, int type);
};

#endif
