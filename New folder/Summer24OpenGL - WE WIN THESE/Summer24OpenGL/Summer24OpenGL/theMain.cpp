//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
#include "globalOpenGL.h"

//#include "linmath.h"
#include <glm/glm.hpp>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> 
// glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include "cShaderManager/cShaderManager.h"
#include "cVAOManager/cVAOManager.h"
#include "cLightManager.h"
#include "cLightHelper/cLightHelper.h"

#include "cBasicTextureManager/cBasicTextureManager.h"

#include <vector>
#include "cMeshObject.h"

#include "sharedThings.h"
#include <algorithm>




//Light over everything
float Sunshine = 1.0f;
// 1 = on
// 0 = off


extern unsigned int g_selectedLightIndex;


int dungeon[19][19] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,1,0,1,1,1,0,0,0,0,1,1,1,1,0,1,0,1},
    {1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,1,0,0,1,0,0,1,1,0,1,0,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,1},
    {1,0,1,0,0,0,0,0,0,21,24,0,1,0,0,0,1,0,1},
    {1,0,1,0,0,1,1,0,0,22,23,0,1,0,1,1,1,0,1},
    {1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1},
    {1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1},
    {0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1},
    {1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

glm::vec3 g_cameraEye = glm::vec3(0.0, 12.0f, -39.0f);
glm::vec3 g_cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);

extern unsigned int g_selectedObjectIndex;

void LoadFilesIntoVAOManager(GLuint program);
// note that this is a pointer because 


void LoadTextures(cBasicTextureManager* pTextureManager);

void LoadModelsIntoScene(void);

void LoadMap(void);

cShaderManager* g_pTheShaderManager = NULL;     // Actual thing is on the HEAP
//cShaderManager TheShaderManager;                // Stack

cVAOManager* g_pMeshManager = NULL;

cBasicTextureManager* g_TextureManager = NULL;

cLightManager* g_pLights = NULL;

// This is some object we can move about
cMeshObject* g_pSmoothSphere = NULL;

extern bool g_ShowLightDebugSphereThings;

void handleKeyboardAsync(GLFWwindow* window);

cMeshObject* g_findMeshByFriendlyName( std::string theName )
{
    // can also be a regular for loop
    // can also be a regular for loop
    for ( cMeshObject* pCurMesh : g_MeshesToDraw )
    {
        if ( pCurMesh->friendlyName == theName )
        {
            return pCurMesh;
        }
    }
    return NULL;    // or nullptr or 0
}


static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

//     void function_name(GLFWwindow* window, int key, int scancode, int action, int mods)
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


void DrawMesh(cMeshObject* pCurrentMesh, GLuint shaderProgram);

int main(void)
{
 //   MessageBox(NULL, L"I love OpenGL", L"Hey!", MB_OK);

//    int ax[3] = { 1, 2, 3 };    // Stack (at compile time)
//    int* pAX = new int[3];      // Heap (at run time)
    // Copy the data

    GLFWwindow* window;
//    GLuint vertex_buffer;
//    GLuint vertex_shader;
//    GLuint fragment_shader;
    GLuint program = 0;
//    GLint mvp_location;

    //GLint vpos_location;
    //GLint vcol_location;

    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwSwapInterval(1);



    // int x = 0;
    // int* pX = new int(); // Same thing
    ::g_pTheShaderManager = new cShaderManager();

    cShaderManager::cShader vertShader;
    vertShader.fileName = "vertexShader01.glsl";

    cShaderManager::cShader fragShader;
    fragShader.fileName = "fragShader01.glsl";

    ::g_pTheShaderManager->setBasePath("assets/shaders/");

    if ( ::g_pTheShaderManager->createProgramFromFile("shader1", vertShader, fragShader ) )
    {
        std::cout << "Hazzah! Compiled OK" << std::endl;
    }
    else
    {
        std::cout << "Shader creation error: "
            << ::g_pTheShaderManager->getLastError()
            << std::endl;
    }

    // Set the shader to the one we want
    program = ::g_pTheShaderManager->getIDFromFriendlyName("shader1");

    // Choose the shader program we're using
    glUseProgram(program);

//    glDeleteShader(program);

 

    // Load all the TYPES of models I can draw
    ::g_pMeshManager = new cVAOManager();

    // This is the selection of models we CAN 'draw' on the screen
    LoadFilesIntoVAOManager(program);

    // Here's the things we'd like to 'show' in our 'scene
    LoadModelsIntoScene();

    ::g_TextureManager = new cBasicTextureManager();

    LoadTextures(::g_TextureManager);

    LoadMap();



    // Enable the depth text per pixel
    glEnable(GL_DEPTH_TEST);

    // Don't draw the "back" part of the objects.
//    glCullFace(GL_BACK);


    // Create the "light manager"
    ::g_pLights = new cLightManager();

    // Get the uniform locations of all the params of the lights
    ::g_pLights->GetUniformLocations(program);

    std::cout << cLightManager::NUMBEROFLIGHTS << std::endl;
    std::cout << ::g_pLights->NUMBEROFLIGHTS << std::endl;


//    // 
//    ::g_pLights->theLights[0].position = glm::vec4(7.0f, 14.0f, -2.0f, 1.0f);
//    // White light (flourescent) light
////    ::g_pLights->theLights[0].diffuse = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
//
//    // https://www.google.com/search?q=rgb+of+sunlight&oq=rgb+of+sunli&gs_lcrp=EgZjaHJvbWUqBwgAEAAYgAQyBwgAEAAYgAQyBggBEEUYOTINCAIQABiGAxiABBiKBTINCAMQABiGAxiABBiKBTINCAQQABiGAxiABBiKBTINCAUQABiGAxiABBiKBTIKCAYQABiABBiiBKgCALACAQ&sourceid=chrome&ie=UTF-8
//    //255, 222, 131
//    ::g_pLights->theLights[0].diffuse = glm::vec4(255.0f/255.0f, 
//                                                  222.0f/255.0f, 
//                                                  131.0f/255.0f, 
//                                                  1.0f);
//    // Turn on
////    ::g_pLights->theLights[0].turnOn();
//    ::g_pLights->theLights[0].param2.x = 1.0f;  // Turn on
//    // Set the attenuation
//    ::g_pLights->theLights[0].atten.x = 0.0f;   // Constant
//    ::g_pLights->theLights[0].atten.y = 0.02f;   // Linear
//    ::g_pLights->theLights[0].atten.z = 0.005f;   // Quadratic
//    //
//    ::g_pLights->theLights[0].param1.x = 0.0f;  // Point light
////    ::g_pLights->theLights[0].param1.x = 1.0f;  // Spot light
//    // 
//    ::g_pLights->theLights[0].direction = glm::vec4(0.0f, -1.0f, 0.0f, 1.0f);
////   vec4 param1;	// x = lightType, y = inner angle, z = outer angle, w = TBD
////               // 0 = pointlight
////               // 1 = spot light
////               // 2 = directional light
//    ::g_pLights->theLights[0].param1.y = 15.0f;
//    ::g_pLights->theLights[0].param1.z = 25.0f;
















    // Position the light high in the sky to simulate sunlight
    ::g_pLights->theLights[0].position = glm::vec4(-1195.0f, 952.0f, -1161.0f, 1.0f);

    // Use a bright white light for daylight simulation
    ::g_pLights->theLights[0].diffuse = glm::vec4(0.8f, 0.75f, 0.6f, 1.0f);  // White light

    // Set the light type to directional light
    ::g_pLights->theLights[0].param1.x = 0.0f;  // Directional light

    // Turn on the light
    ::g_pLights->theLights[0].param2.x = Sunshine;

    // Set the attenuation values for directional light (no attenuation)
    ::g_pLights->theLights[0].atten.x = 2.0f;   // Constant (base intensity)
    ::g_pLights->theLights[0].atten.y = 0.0f;   // No linear attenuation
    ::g_pLights->theLights[0].atten.z = 0.0f;   // No quadratic attenuation



       // 
    ::g_pLights->theLights[1].position = glm::vec4(1.0f, 0.5f, 0.0f, 1.0f);
    ::g_pLights->theLights[1].diffuse = glm::vec4(1.0f, 0.25f, 0.25f, 1.0f);
    //
    ::g_pLights->theLights[1].param1.x = 0.0f;  // Point light
    // Turn on
    ::g_pLights->theLights[1].param2.x = 1.0f;  // Turn on
    // Set the attenuation
    ::g_pLights->theLights[1].atten.x = 0.0f;   // Constant
    ::g_pLights->theLights[1].atten.y = 5.0f;   // Linear
    ::g_pLights->theLights[1].atten.z = 0.137f;   // Quadratic

       // 
    ::g_pLights->theLights[2].position = glm::vec4(10.5f, 0.5f, 0.0f, 1.0f);
    ::g_pLights->theLights[2].diffuse = glm::vec4(1.0f, 0.25f, 0.25f, 1.0f);
    //
    ::g_pLights->theLights[2].param1.x = 0.0f;  // Point light
    // Turn on
    ::g_pLights->theLights[2].param2.x = 1.0f;  // Turn on
    // Set the attenuation
    ::g_pLights->theLights[2].atten.x = 0.0f;   // Constant
    ::g_pLights->theLights[2].atten.y = 5.0f;   // Linear
    ::g_pLights->theLights[2].atten.z = 0.267f;   // Quadratic

       // 
    ::g_pLights->theLights[3].position = glm::vec4(17.5f, 0.5f, 17.5f, 1.0f);
    ::g_pLights->theLights[3].diffuse = glm::vec4(1.0f, 0.25f, 0.25f, 1.0f);
    //
    ::g_pLights->theLights[3].param1.x = 0.0f;  // Point light
    // Turn on
    ::g_pLights->theLights[3].param2.x = 1.0f;  // Turn on
    // Set the attenuation
    ::g_pLights->theLights[3].atten.x = 0.0f;   // Constant
    ::g_pLights->theLights[3].atten.y = 5.0f;   // Linear
    ::g_pLights->theLights[3].atten.z = 0.168f;   // Quadratic


    ::g_pLights->theLights[4].position = glm::vec4(1.5f, 0.5f, 15.5f, 1.0f);
    ::g_pLights->theLights[4].diffuse = glm::vec4(1.0f, 0.25f, 0.25f, 1.0f);
    //
    ::g_pLights->theLights[4].param1.x = 0.0f;  // Point light
    // Turn on
    ::g_pLights->theLights[4].param2.x = 1.0f;  // Turn on
    // Set the attenuation
    ::g_pLights->theLights[4].atten.x = 0.0f;   // Constant
    ::g_pLights->theLights[4].atten.y = 5.0f;   // Linear
    ::g_pLights->theLights[4].atten.z = 0.40f;   // Quadratic



    // 
    ::g_pLights->theLights[5].position = glm::vec4(5.0f, 0.5f, 13.5f, 1.0f);
    ::g_pLights->theLights[5].diffuse = glm::vec4(1.0f, 0.25f, 0.25f, 1.0f);
    //
    ::g_pLights->theLights[5].param1.x = 0.0f;  // Point light
    // Turn on
    ::g_pLights->theLights[5].param2.x = 1.0f;  // Turn on
    // Set the attenuation
    ::g_pLights->theLights[5].atten.x = 0.0f;   // Constant
    ::g_pLights->theLights[5].atten.y = 5.0f;   // Linear
    ::g_pLights->theLights[5].atten.z = 0.35f;   // Quadratic
    // 


    ::g_pLights->theLights[6].position = glm::vec4(11.0f, 0.5f, 11.5f, 1.0f);
    ::g_pLights->theLights[6].diffuse = glm::vec4(1.0f, 0.25f, 0.25f, 1.0f);
    //
    ::g_pLights->theLights[6].param1.x = 0.0f;  // Point light
    // Turn o
    ::g_pLights->theLights[6].param2.x = 1.0f;  // Turn on
    // Set the attenuation
    ::g_pLights->theLights[6].atten.x = 0.0f;   // Constant
    ::g_pLights->theLights[6].atten.y = 5.0f;   // Linear
    ::g_pLights->theLights[6].atten.z = 0.064f;   // Quadratic


    ::g_pLights->theLights[7].position = glm::vec4(17.0f, 0.5f, 11.5f, 1.0f);
    ::g_pLights->theLights[7].diffuse = glm::vec4(1.0f, 0.25f, 0.25f, 1.0f);
   
    ::g_pLights->theLights[7].param1.x = 0.0f;  // Point light
    // Turn o
    ::g_pLights->theLights[7].param2.x = 1.0f;  // Turn on
    // Set the attenuation
    ::g_pLights->theLights[7].atten.x = 0.0f;   // Constant
    ::g_pLights->theLights[7].atten.y = 5.0f;   // Linear
    ::g_pLights->theLights[7].atten.z = 0.092f;   // Quadratic

    ::g_pLights->theLights[8].position = glm::vec4(17.0f, 0.5f, 2.0f, 1.0f);
    ::g_pLights->theLights[8].diffuse = glm::vec4(1.0f, 0.25f, 0.25f, 1.0f);
    ::g_pLights->theLights[8].param1.x = 0.0f;  // Point light
    // Turn o
    ::g_pLights->theLights[8].param2.x = 1.0f;  // Turn on
    // Set the attenuation
    ::g_pLights->theLights[8].atten.x = 0.0f;   // Constant
    ::g_pLights->theLights[8].atten.y = 5.0f;   // Linear
    ::g_pLights->theLights[8].atten.z = 0.35f;   // Quadratic


    ::g_pLights->theLights[9].position = glm::vec4(4.5f, 0.5f, 4.0f, 1.0f);
    ::g_pLights->theLights[9].diffuse = glm::vec4(1.0f, 0.25f, 0.25f, 1.0f);

    ::g_pLights->theLights[9].param1.x = 0.0f;  // Point light
    // Turn o
    ::g_pLights->theLights[9].param2.x = 1.0f;  // Turn on
    // Set the attenuation
    ::g_pLights->theLights[9].atten.x = 0.0f;   // Constant
    ::g_pLights->theLights[9].atten.y = 5.0f;   // Linear
    ::g_pLights->theLights[9].atten.z = 0.0f;   // Quadratic











    // Main loop runs forever
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        //       mat4x4 m, p, mvp;
        //       glm::mat4 m, p, v, mvp;
        for (int i = 1; i < 10; i++)
        {
            if (::g_pLights->theLights[i].increase)
            {
                ::g_pLights->theLights[i].atten.z += 0.05;
                if (::g_pLights->theLights[i].atten.z > 1.0f)
                    ::g_pLights->theLights[i].increase = false;

            }
            else
            {
                ::g_pLights->theLights[i].atten.z -= 0.05;
                if (::g_pLights->theLights[i].atten.z < 0.01f)
                    ::g_pLights->theLights[i].increase = true;

            }
        }



        ::g_pLights->theLights[10].position = glm::vec4(8.5f, 2.0f, 15.f, 1.0f); // Light position
        ::g_pLights->theLights[10].diffuse = glm::vec4(1.0, 1.0, 1.0, 1.0f);       // Diffuse color (white light)
        ::g_pLights->theLights[10].param2.x = 1.0f;                                // Turn on the light

        // Set the attenuation
        ::g_pLights->theLights[10].atten.x = 0.0f;                                 // Constant attenuation
        ::g_pLights->theLights[10].atten.y = 0.02f;                                // Linear attenuation
        ::g_pLights->theLights[10].atten.z = 0.005f;                               // Quadratic attenuation

        // Set the light type to spotlight
        ::g_pLights->theLights[10].param1.x = 1.0f;                                // Spotlight type (1)
        ::g_pLights->theLights[10].direction = glm::vec4(0.1f, -1.0f, 0.2f, 1.0f); // Spotlight direction

        // Set inner and outer angles for the spotlight
        ::g_pLights->theLights[10].param1.y = 1.0f;  // Inner cone angle in degrees
        ::g_pLights->theLights[10].param1.z = 2.0f;  // Outer cone angle in degrees
        

        ::g_pLights->theLights[11].position = glm::vec4(17.f, 3.0f, 10.5f, 1.0f); // Light position
        ::g_pLights->theLights[11].diffuse = glm::vec4(1.0, 1.0, 1.0, 1.0f);       // Diffuse color (white light)
        ::g_pLights->theLights[11].param2.x = 1.0f;                                // Turn on the light

        // Set the attenuation
        ::g_pLights->theLights[11].atten.x = 0.0f;                                 // Constant attenuation
        ::g_pLights->theLights[11].atten.y = 0.02f;                                // Linear attenuation
        ::g_pLights->theLights[11].atten.z = 0.005f;                               // Quadratic attenuation

        // Set the light type to spotlight
        ::g_pLights->theLights[11].param1.x = 1.0f;                                // Spotlight type (1)
        ::g_pLights->theLights[11].direction = glm::vec4(0.1f, -1.0f, 0.2f, 1.0f); // Spotlight direction

        // Set inner and outer angles for the spotlight
        ::g_pLights->theLights[11].param1.y = 1.0f;  // Inner cone angle in degrees
        ::g_pLights->theLights[11].param1.z = 2.0f;  // Outer cone angle in degrees


        ::g_pLights->theLights[12].position = glm::vec4(17.0f, 2.5f, 12.5f, 1.0f); // Light position
        ::g_pLights->theLights[12].diffuse = glm::vec4(1.0, 1.0, 1.0, 1.0f);       // Diffuse color (white light)
        ::g_pLights->theLights[12].param2.x = 1.0f;                                // Turn on the light

        // Set the attenuation
        ::g_pLights->theLights[12].atten.x = 0.0f;                                 // Constant attenuation
        ::g_pLights->theLights[12].atten.y = 0.02f;                                // Linear attenuation
        ::g_pLights->theLights[12].atten.z = 0.005f;                               // Quadratic attenuation

        // Set the light type to spotlight
        ::g_pLights->theLights[12].param1.x = 1.0f;                                // Spotlight type (1)
        ::g_pLights->theLights[12].direction = glm::vec4(0.1f, -1.0f, 0.2f, 1.0f); // Spotlight direction

        // Set inner and outer angles for the spotlight
        ::g_pLights->theLights[12].param1.y = 1.0f;  // Inner cone angle in degrees
        ::g_pLights->theLights[12].param1.z = 2.0f;  // Outer cone angle in degrees












        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;
        glViewport(0, 0, width, height);

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        //mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glm::mat4 matProjection = 
            glm::perspective(0.6f,          // FOV
                             ratio,         // screen aspect ratio 16:9
                             1.0f,          // Neap plane
                             10'000.0f);      // Far plane

        // float 6-7

        glm::mat4 matView = glm::mat4(1.0f);

//        glm::vec3 cameraEye = glm::vec3(   0.0,   0.0, -20.0f);
//        glm::vec3 cameraTarget = glm::vec3(0.0f, -5.0f, 20.0f);
        glm::vec3 upVector = glm::vec3(0.0f, 1.0f, 0.0f);

        matView = glm::lookAt(::g_cameraEye,
                              ::g_cameraTarget,
                              upVector);

        GLint eyeLocation_UL = glGetUniformLocation(program, "eyeLocation");
        glUniform3f(eyeLocation_UL, 
                    ::g_cameraEye.x,
                    ::g_cameraEye.y,
                    ::g_cameraEye.z);

       


       //mat4x4_mul(mvp, p, m);
//        mvp = p * v * m;

        //// Blend from wall to Beyonce
        //cMeshObject* pGround = g_findMeshByFriendlyName("The Ground");
        //if (pGround)
        //{
        //    if (pGround->textureBlendRatio[0] >= 0.0f)
        //    {
        //        // It's there
        //        pGround->textureBlendRatio[0] -= 0.0001f;
        //        pGround->textureBlendRatio[1] += 0.0001f;
        //    }
        //}
        


        // Place light #0 where the sphere is
//        ::g_pLights->theLights[0].position = glm::vec4( g_pSmoothSphere->position, 1.0f);
        ::g_pSmoothSphere->position = glm::vec3(::g_pLights->theLights[0].position);

        // Copy the light information to the shader
        ::g_pLights->UpdateShaderUniforms(program);

        // The project and view stay the same for the entire scene 
        // (like they stay the same as we draw all the objects this pass (or frame))
        GLint mProj_location = glGetUniformLocation(program, "mProj");
        GLint mView_location = glGetUniformLocation(program, "mView");

        glUniformMatrix4fv(mProj_location, 1, GL_FALSE,
                           glm::value_ptr(matProjection));

        glUniformMatrix4fv(mView_location, 1, GL_FALSE,
                           glm::value_ptr(matView));


        // Turn on the lighting
        // uniform bool bDoNotLight;
        GLint bDoNotLight_UL = glGetUniformLocation(program, "bDoNotLight");
        glUniform1f(bDoNotLight_UL, (GLint)GL_FALSE);        // Pass 1.0f;

        GLint ml_UL = glGetUniformLocation(program, "maxLightIndexInUse");
        glUniform1i(ml_UL, cLightManager::NUMBEROFLIGHTS);

        // Start drawing the scene
        // 
        // i.e. draw all the things listed in this:
        // std::vector< cMeshObject* > g_MeshesToDraw;
        //
        // NON-transparent thing...

        std::vector<cMeshObject*> vecTransparentThings;
        std::vector<cMeshObject*> vecSolidThings;

        for ( cMeshObject* pCurMesh : ::g_MeshesToDraw )
        {
            if (pCurMesh->alphaTransparency < 1.0f )
            {
                vecTransparentThings.push_back(pCurMesh);
            }
            else
            {
                vecSolidThings.push_back(pCurMesh);
            }
        }

        // Sort the transparent things far to near

        // Vector of 100 to 1000 thigns
        // Faster search...?
        // LINEAR search

//        Pentium 586 --> Quake 3
//        CPU SPEED : Intel 266 MHz / AMD 350 MHz.
//        RAM : 64 MB.
        if (vecTransparentThings.size() > 0)
        {
            bool swapped = true;
            while (swapped)
            {
                swapped = false;
                for (size_t i = 0; i < vecTransparentThings.size() - 1; ++i)
                {
                    float distToThisObject = glm::distance(g_cameraEye, vecTransparentThings[i]->position);
                    float distToNextObject = glm::distance(g_cameraEye, vecTransparentThings[i + 1]->position);

                    if (distToNextObject > distToThisObject)
                    {
                        std::swap(vecTransparentThings[i], vecTransparentThings[i + 1]);
                        swapped = true;
                    }
                }
            }
        }

        


        //vectro
        //list
        //hash map
        //map (red-black tree)


        for ( unsigned int index = 0; index != vecSolidThings.size(); index++ )
        {

            cMeshObject* pCurrentMesh = vecSolidThings[index];


            DrawMesh(pCurrentMesh, program);

        }//for ( unsigned int index 

        for ( unsigned int index = 0; index != vecTransparentThings.size(); index++ )
        {

            cMeshObject* pCurrentMesh = vecTransparentThings[index];


            DrawMesh(pCurrentMesh, program);

        }//for ( unsigned int index 

//        DrawMesh(::g_pSmoothSphere, program);
// 

        //for ( float x = -50.0f; x < 50.0f; x += 5.0f )
        //{
        //    ::g_MeshesToDraw[1]->scale = 5.0f;
        //    ::g_MeshesToDraw[1]->position.x = x;
        //    ::g_MeshesToDraw[1]->position.y = 10.0f;
        //    ::g_MeshesToDraw[1]->position.z = 0.0f;
        //    ::g_MeshesToDraw[1]->colourRGB = glm::vec3(1.0f, 1.0f, 1.0f);
        //    DrawMesh(::g_MeshesToDraw[1], program);
        //}




        if (g_ShowLightDebugSphereThings)
        {

            // Draw concentric sphers based on how bright the light is at 'that' distance
            cLightHelper myLH;

            const float errorValueForLightLevelGuess = 0.001f;
            const float INFINITE_DISTANCE = 100000.0f;

            // Turn off the lights
            glUniform1f(bDoNotLight_UL, (GLint)GL_TRUE);        // Pass 1.0f;

            // The centre of the light
            ::g_pSmoothSphere->scale = 0.1f;
            ::g_pSmoothSphere->colourRGB = glm::vec3(1.0f, 1.0f, 1.0f);
            ::g_pSmoothSphere->bOverrideVertexModelColour = true;
            ::g_pSmoothSphere->bDoNotLight = true;
            ::g_pSmoothSphere->bUseTextureAsColour = false;
            ::g_pSmoothSphere->position = ::g_pLights->theLights[::g_selectedLightIndex].position;
            DrawMesh(::g_pSmoothSphere, program);

            //float distanceAt75Percent =
            //    myLH.calcApproxDistFromAtten(0.75f,
            //                                 errorValueForLightLevelGuess,
            //                                 INFINITE_DISTANCE,
            //                                 ::g_pLights->theLights[::g_selectedLightIndex].atten.x,     // Const
            //                                 ::g_pLights->theLights[::g_selectedLightIndex].atten.y,     // Linear
            //                                 ::g_pLights->theLights[::g_selectedLightIndex].atten.z);    // Quad

            //::g_pSmoothSphere->scale = distanceAt75Percent;
            //::g_pSmoothSphere->colourRGB = glm::vec3(0.25f, 0.25f, 0.0f);
            //DrawMesh(::g_pSmoothSphere, program);


            //float distanceAt50Percent = 
            //    myLH.calcApproxDistFromAtten(0.5f,
            //                             errorValueForLightLevelGuess,
            //                             INFINITE_DISTANCE,
            //                             ::g_pLights->theLights[::g_selectedLightIndex].atten.x,     // Const
            //                             ::g_pLights->theLights[::g_selectedLightIndex].atten.y,     // Linear
            //                             ::g_pLights->theLights[::g_selectedLightIndex].atten.z);    // Quad

            //::g_pSmoothSphere->scale = distanceAt50Percent;
            //::g_pSmoothSphere->colourRGB = glm::vec3(0.25f, 0.0f, 0.0f);
            //DrawMesh(::g_pSmoothSphere, program);


            //float distanceAt25Percent =
            //    myLH.calcApproxDistFromAtten(0.25f,
            //                                 errorValueForLightLevelGuess,
            //                                 INFINITE_DISTANCE,
            //                                 ::g_pLights->theLights[::g_selectedLightIndex].atten.x,     // Const
            //                                 ::g_pLights->theLights[::g_selectedLightIndex].atten.y,     // Linear
            //                                 ::g_pLights->theLights[::g_selectedLightIndex].atten.z);    // Quad

            //::g_pSmoothSphere->scale = distanceAt25Percent;
            //::g_pSmoothSphere->colourRGB = glm::vec3(0.0f, 0.25f, 0.0f);
            //DrawMesh(::g_pSmoothSphere, program);



            //                        
            //float distanceAt01Percent = 
            //myLH.calcApproxDistFromAtten(0.01f,     // really 'zero'
            //                            errorValueForLightLevelGuess,
            //                            INFINITE_DISTANCE,
            //                            ::g_pLights->theLights[::g_selectedLightIndex].atten.x,     // Const
            //                            ::g_pLights->theLights[::g_selectedLightIndex].atten.y,     // Linear
            //                            ::g_pLights->theLights[::g_selectedLightIndex].atten.z);    // Quad

            //::g_pSmoothSphere->scale = distanceAt01Percent;
            //::g_pSmoothSphere->colourRGB = glm::vec3(0.0f, 0.25f, 0.5f);
            //DrawMesh(::g_pSmoothSphere, program);

            glUniform1f(bDoNotLight_UL, (GLint)GL_FALSE);        // Pass 1.0f;
        }//if (g_ShowLightDebugSphereThings)
         
         // Update the window title to show where the camera is...
        std::stringstream ssWindowsTitle;
//        std::cout 
        ssWindowsTitle
            << "Camera (xyz)"
            << ::g_cameraEye.x << ", "
            << ::g_cameraEye.y << ", "
            << ::g_cameraEye.z
            << "  "
            //<< "light#0: "
            //<< ::g_pLights->theLights[0].position.x << ", "
            //<< ::g_pLights->theLights[0].position.y << ", "
            //<< ::g_pLights->theLights[0].position.z
            //<< " linear: "
            //<< ::g_pLights->theLights[0].atten.y << "  "        // linear attenuation
            //<< " quad: "
            //<< ::g_pLights->theLights[0].atten.z << "  "        // Quadratic
            << "selected object ID: "
            << ::g_selectedObjectIndex << " XYZ "
            << g_MeshesToDraw[::g_selectedObjectIndex]->position.x << ", "
            << g_MeshesToDraw[::g_selectedObjectIndex]->position.y << ", "
            << g_MeshesToDraw[::g_selectedObjectIndex]->position.z << " Rotation "
            << g_MeshesToDraw[::g_selectedObjectIndex]->orientation.x << ", "
            << g_MeshesToDraw[::g_selectedObjectIndex]->orientation.y << ", "
            << g_MeshesToDraw[::g_selectedObjectIndex]->orientation.z << " Scale "
            << g_MeshesToDraw[::g_selectedObjectIndex]->scale << " "
            << g_MeshesToDraw[::g_selectedObjectIndex]->meshFileName;


//            << "selected object ID: " 
//            << ::g_selectedObjectIndex;

//        glfwSetWindowTitle(window, "HEY!");
        glfwSetWindowTitle(window, ssWindowsTitle.str().c_str() );


        glfwSwapBuffers(window);
        glfwPollEvents();

        handleKeyboardAsync(window);
    }


    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}


