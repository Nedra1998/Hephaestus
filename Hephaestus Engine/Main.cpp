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
	H.Layers[0]->Colored_Objects[0]->New_Colored_Object(4, 0.05, 0.1, 1.0, 1.0, 1.0, 1.0, 1);
	H.Layers[0]->Colored_Objects[0]->Translate_Object(-0.8, 0.0, 0.0);
	H.Layers[0]->Initilize_Object(1);
	H.Layers[0]->Colored_Objects[1]->New_Colored_Object(4, 0.05, 0.1, 1.0, 1.0, 1.0, 1.0, 1);
	H.Layers[0]->Colored_Objects[1]->Translate_Object(0.8, 0.0, 0.0);
	int delay = 10;

	H.Layers[0]->Initilize_Object(6);
	H.Layers[0]->Physics_Objects[0]->New_Color_Physics_Object(4, 0.01, 0.01, 1.0, 1.0, 1.0, 1.0, 1);
	H.Layers[0]->Physics_Objects[0]->Translate_Physics_Object(0.0, 0.0, 0.0);
	H.Layers[0]->Physics_Objects[0]->Set_Velocity_Physics_Object(-0.1, 0.00, 0.0);
	H.Layers[0]->Physics_Objects[0]->Set_Velocity_Reflection(75);
	H.Layers[0]->Physics_Objects[0]->Set_Velocity_Transfer(100);
	H.Layers[0]->Physics_Objects[0]->Physics->Set_Collision_Set(H.Layers[0]->Colored_Objects, 0, -1);
	H.Layers[0]->Colored_Objects[0]->Set_Collision_Set(H.Layers[0]->Physics_Objects, 0, -1);
	while (!glfwWindowShouldClose(Win)){
		/*>>>>>Place While Running Code Here<<<<<*/
		if (glfwGetKey(Win, GLFW_KEY_W)){
			H.Layers[0]->Colored_Objects[0]->Move_Object(0.0, 0.02, 0.0, 0);
		}
		if (glfwGetKey(Win, GLFW_KEY_S)){
			H.Layers[0]->Colored_Objects[0]->Move_Object(0.0, -0.02, 0.0, 0);
		}
		if (glfwGetKey(Win, GLFW_KEY_UP)){
			H.Layers[0]->Colored_Objects[1]->Move_Object(0.0, 0.02, 0.0, 0);
		}
		if (glfwGetKey(Win, GLFW_KEY_DOWN)){
			H.Layers[0]->Colored_Objects[1]->Move_Object(0.0, -0.02, 0.0, 0);
		}
		H.Layers[0]->Run_All_Physics();
		H.Display_All_Layers();
		H.Frame();
	}
	H.Terminate_Log();
	return(0);
}