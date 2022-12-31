#include <iostream>
#include<cstdlib>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <shader.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <math.h>

struct STRVertex
{
	glm::vec3 position;
	glm::vec3 couleur;
};


int main()
{
	// initialiser GLFW //
	glfwInit();

	// initialiser les parametres //
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// creer la fenetre principale //
	GLFWwindow* window = glfwCreateWindow(800, 800, "Test OPENGL", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to Open Window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// fenetre comme contexte pour opengl //
	glfwMakeContextCurrent(window);

	// init opengl //
	gladLoadGL();

	glViewport(0, 0, 800, 800);


	// data //


	//data
	STRVertex vert[] = {
					glm::vec3(1.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f),
					glm::vec3(-1.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f),
					glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f),
					glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f),
					glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f),
					glm::vec3(1.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f),
					// face 1
					{glm::vec3(1.0f, 0.0f, 1.0f),  glm::vec3(1.0f, 1.0f, 0.0f)},
					{glm::vec3(1.0f,0.0f, -1.0f), glm::vec3(1.0f, 1.0f, 0.0f)},
					{glm::vec3(0.0f,1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)},

					// face 2
					{glm::vec3(1.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 1.0f)},
					{glm::vec3(-1.0f,0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 1.0f)},
					{glm::vec3(0.0f,1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f)},

					// face 3
					{glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
					{glm::vec3(-1.0f,0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
					{glm::vec3(0.0f,1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},

					// face 4
					{glm::vec3(-1.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
					{glm::vec3(-1.0f,0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
					{glm::vec3(0.0f,1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)},








	};

	STRVertex vert1[] = {
				glm::vec3(1.0f, 2.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f),
				glm::vec3(-1.0f, 2.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f),
				glm::vec3(-1.0f, 2.0f, -1.0f), glm::vec3(1.0f, 0.0f, 0.0f),
				glm::vec3(-1.0f, 2.0f, -1.0f), glm::vec3(1.0f, 0.0f, 0.0f),
				glm::vec3(1.0f, 2.0f, -1.0f), glm::vec3(1.0f, 0.0f, 0.0f),
				glm::vec3(1.0f, 2.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f),
				// face 1
				{glm::vec3(1.0f, 2.0f, 1.0f),  glm::vec3(1.0f, 0.0f, 0.0f)},
				{glm::vec3(1.0f,2.0f, -1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
				{glm::vec3(0.0f,1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},

				// face 2
				{glm::vec3(1.0f, 2.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
				{glm::vec3(-1.0f,2.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
				{glm::vec3(0.0f,1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},

				// face 3
				{glm::vec3(1.0f, 2.0f, -1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
				{glm::vec3(-1.0f,2.0f, -1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
				{glm::vec3(0.0f,1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},

				// face 4
				{glm::vec3(-1.0f, 2.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
				{glm::vec3(-1.0f,2.0f, -1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
				{glm::vec3(0.0f,1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},








	};




	STRVertex vert2[] = {
				glm::vec3(1.0f, 2.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f),
				glm::vec3(-1.0f, 2.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f),
				glm::vec3(-1.0f, 2.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f),
				glm::vec3(-1.0f, 2.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f),
				glm::vec3(1.0f, 2.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f),
				glm::vec3(1.0f, 2.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f),
				// face 1
				{glm::vec3(1.0f, 2.0f, 1.0f),  glm::vec3(0.0f, 1.0f, 0.0f)},
				{glm::vec3(1.0f,2.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
				{glm::vec3(0.0f,1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},

				// face 2
				{glm::vec3(1.0f, 2.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
				{glm::vec3(-1.0f,2.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
				{glm::vec3(0.0f,1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},

				// face 3
				{glm::vec3(1.0f, 2.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
				{glm::vec3(-1.0f,2.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
				{glm::vec3(0.0f,1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},

				// face 4
				{glm::vec3(-1.0f, 2.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
				{glm::vec3(-1.0f,2.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
				{glm::vec3(0.0f,1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},








	};
	//objet 1

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);


	GLuint VBO; // cree vertex buffer object
	glGenBuffers(1, &VBO); // generer 1 seul vbo
	glBindBuffer(GL_ARRAY_BUFFER, VBO);  // binder le VBO avec gl_array_buffer

	// remplir le buffer avec data ( les donnees du vbo)
	glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), (void*)offsetof(STRVertex, position));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), (void*)offsetof(STRVertex, couleur));


	//objet2

	GLuint VAO2;
	glGenVertexArrays(1, &VAO2);
	glBindVertexArray(VAO2);


	GLuint VBO2; // cree vertex buffer object
	glGenBuffers(1, &VBO2); // generer 1 seul vbo
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);  // binder le VBO avec gl_array_buffer

	// remplir le buffer avec data ( les donnees du vbo)
	glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert1, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), (void*)offsetof(STRVertex, position));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), (void*)offsetof(STRVertex, couleur));

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//objet 3

	GLuint VAO3;
	glGenVertexArrays(1, &VAO3);
	glBindVertexArray(VAO3);


	GLuint VBO3; // cree vertex buffer object
	glGenBuffers(1, &VBO3); // generer 1 seul vbo
	glBindBuffer(GL_ARRAY_BUFFER, VBO3);  // binder le VBO avec gl_array_buffer

	// remplir le buffer avec data ( les donnees du vbo)
	glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert2, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), (void*)offsetof(STRVertex, position));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(STRVertex), (void*)offsetof(STRVertex, couleur));

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//---
	GLuint ShaderProgram;

	ShaderProgram = LoadShaders("Dependecies/shader/SimpleVertexShader.vertexshader", "Dependecies/shader/SimpleFragmentShader.fragmentshader");




	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	int i = 0;
	int var = 0;


	// Main Loop //
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f); // definir une couleur a la fenetre
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		glUseProgram(ShaderProgram);

		i++;
		if (i % 10000 == 0) {
			var++;
			i = 0;

		}
		// application de transformation


		glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);

		glm::mat4 View = glm::lookAt(glm::vec3(0, 0, 9), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
		glm::mat4 Model = glm::mat4(1.0f);
		//Model = glm::translate(Model, glm::vec3(0.0f, 0.0f, 0.0f));
		//Model = glm::scale(Model, glm::vec3(2.5f, 1.5f, 1.0f));
		//Model = glm::rotate(Model, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		Model = glm::rotate(Model, (float)glfwGetTime(), glm::vec3(2.0f, 0.0f, 0.0f));
		// ensuite on multiple le tout
		glm::mat4 MVP = Projection * View * Model;
		// on cree une variable uniform
		GLuint MatrixID = glGetUniformLocation(ShaderProgram, "MVP");
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);



		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 18);
		


		glm::mat4 Model2 = glm::rotate(Model, (float)glfwGetTime()*8.0f, glm::vec3(0.0f, 2.0f, 0.0f));
		// ensuite on multiple le tout
		MVP = Projection * View * Model2;
		// on cree une variable uniform
		MatrixID = glGetUniformLocation(ShaderProgram, "MVP");
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);



		glBindVertexArray(VAO2);
		glDrawArrays(GL_TRIANGLES, 0, 18);

		glm::mat4 Model3 = glm::mat4(1.0f);
		Model3 = glm::translate(Model3, glm::vec3(0.0f, 0.0f, 0.0f));
		 Model3 = glm::rotate(Model3, (float)glfwGetTime() *5, glm::vec3(0.0f, 0.0f, 2.0f));
		// ensuite on multiple le tout
		MVP = Projection * View * Model3;
		// on cree une variable uniform
		MatrixID = glGetUniformLocation(ShaderProgram, "MVP");
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);



		glBindVertexArray(VAO3);
		glDrawArrays(GL_TRIANGLES, 0, 18);


		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	// finishing //
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}