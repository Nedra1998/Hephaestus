#include "Libraries.h"
#include "Hephaestus.h"
#include "Logging.h"
using namespace std;
Hephaestus H;
GLFWwindow* Win;
void Key_Call(GLFWwindow* Win, int key, int scancode, int action, int mods){
	H.Key_Call_Back(Win, key, scancode, action, mods);
}
void Mouse_Call(GLFWwindow* Win, int button, int action, int mods){
	H.Mouse_Call_Back(Win, button, action, mods);
}
void Window_Call(GLFWwindow* Win, int width, int hight){
	glfwSetWindowSize(Win, width, hight);
}
int main(){
	GLFWwindow* Win;
	Win = H.Full_Setup();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwSetKeyCallback(Win, Key_Call);
	glfwSetMouseButtonCallback(Win, Mouse_Call);
	glfwSetWindowSizeCallback(Win, Window_Call);
	srand(time(NULL));
	/*>>>>>Place Before Start Code Here<<<<<*/
	int index = 0;
	H.Layers[0]->Initilize_Object(1);
	H.Layers[0]->Colored_Objects[0]->New_Colored_Object(4, 0.1, 0.1, 1.0, 1.0, 1.0, 1.0, 1);
	while (!glfwWindowShouldClose(Win)){
		/*>>>>>Place While Running Code Here<<<<<*/
		if (glfwGetKey(Win, GLFW_KEY_A)){
			H.Layers[0]->Colored_Objects[0]->Move_Object(-0.01, 0.0, 0.0, 0);
		}
		if (glfwGetKey(Win, GLFW_KEY_W)){
			H.Layers[0]->Colored_Objects[0]->Move_Object(0.0, 0.01, 0.0, 0);
		}
		if (glfwGetKey(Win, GLFW_KEY_S)){
			H.Layers[0]->Colored_Objects[0]->Move_Object(0.0, -0.01, 0.0, 0);
		}
		if (glfwGetKey(Win, GLFW_KEY_D)){
			H.Layers[0]->Colored_Objects[0]->Move_Object(0.01, 0.0, 0.0, 0);
		}
		if (glfwGetKey(Win, GLFW_KEY_N)){
			int points = 3;
			float x, y, r, g, b, xp, yp;
			H.Layers[0]->Initilize_Object(6);
			r = (float)(rand() % 10) / (float)10;
			g = (float)(rand() % 10) / (float)10;
			x = (float)(rand() % 100) / (float)500;
			y = (float)(rand() % 100) / (float)500;
			b = (float)(rand() % 10) / (float)10;
			xp = (float)((rand() % 200) - 100) / (float)100;
			yp = (float)((rand() % 200) - 100) / (float)100;
			points = (rand() % 97) + 3;
			H.Layers[0]->Physics_Objects[index]->New_Color_Physics_Object(30, x, y, r, g, b, 1.0, 1);
			H.Layers[0]->Physics_Objects[index]->Translate_Physics_Object(0.0, 1.0, 0.0);
			H.Layers[0]->Physics_Objects[index]->Accelerate_Physics_Object(0.0, -0.1, 0.0);
			H.Layers[0]->Physics_Objects[index]->Physics->Set_Collision_Set(H.Layers[0]->Colored_Objects, 0, 10);
			H.Layers[0]->Colored_Objects[0]->Set_Collision_Set(H.Layers[0]->Physics_Objects, 0, -1);
			index++;
		}
		H.Layers[0]->Run_All_Physics();
		H.Display_All_Layers();
		H.Frame();
	}
	H.Terminate_Log();
	return(0);
}