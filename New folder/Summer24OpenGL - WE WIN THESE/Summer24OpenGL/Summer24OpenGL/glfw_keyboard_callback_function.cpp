#include "globalOpenGL.h"
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <vector>
#include "cMeshObject.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "cLightManager.h"


//extern glm::vec3 g_cameraEye;//  = glm::vec3(0.0, 0.0, -20.0f);
//
//// note that this is a pointer because 
//extern std::vector< cMeshObject* > g_MeshesToDraw;
//
//extern cMeshObject* g_pSmoothSphere;
//
//extern cLightManager* g_pLights;// = NULL;

#include "sharedThings.h"

bool g_ShowLightDebugSphereThings = true;



// The item that I'm currently selecting
unsigned int g_selectedObjectIndex = 0;

unsigned int g_selectedLightIndex = 0;


bool isShiftDown(int mods)
{
    if ( (mods & GLFW_MOD_SHIFT) == GLFW_MOD_SHIFT)
    {
        // Yup
        return true;
    }
    return false;
}
bool isCntlDown(int mods)
{
    if ( (mods & GLFW_MOD_CONTROL) == GLFW_MOD_CONTROL)
    {
        // Yup
        return true;
    }
    return false;
}
bool isAltDown(int mods)
{
    if ( (mods & GLFW_MOD_ALT) == GLFW_MOD_ALT)
    {
        // Yup
        return true;
    }
    return false;
}

bool areAnyModifiersDown(int mods)
{
    if (isShiftDown(mods)) {
        return true;
    }
    if (isAltDown(mods)) {
        return true;
    } 
    if (isCntlDown(mods)) {
        return true;
    }
    return false;
}
//     void function_name(GLFWwindow* window, int key, int scancode, int action, int mods)
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }


    const float OBJECT_MOVE_SPEED = 0.1f;
    const float LIGHT_MOVE_SPEED = 0.5f;
    const float CAMERA_MOVE_SPEED = 1.0f;

    // if shift is down (just shift) then move the selected object
    if (mods == GLFW_MOD_SHIFT)       // 0001   // 0010  // 0100  // 0111
    {
        // ONLY the shift key (either one) is down


    }//if ( mods == GLFW_MOD_SHIFT )

    // If one of the keys is shift
    //  Shift -- 0001
    //  Cont  -- 0010
    //  Alt   -- 0100
    // Press all 3 --> 0111
    //     & 0001  --- 0001 // "bitwise and is a 'mask' operation
    //             --------
    //                 0001

    // ONLY the control key is down
    if ((mods & GLFW_MOD_CONTROL) == GLFW_MOD_CONTROL)
    {
        if (key == GLFW_KEY_A)
        {
            ::g_pLights->theLights[::g_selectedLightIndex].position.x -= LIGHT_MOVE_SPEED;
//            ::g_pSmoothSphere->position.x -= OBJECT_MOVE_SPEED;
        }
        if (key == GLFW_KEY_D) {
            ::g_pLights->theLights[::g_selectedLightIndex].position.x += LIGHT_MOVE_SPEED;
        }

        if (key == GLFW_KEY_Q)
        {
            ::g_pLights->theLights[::g_selectedLightIndex].position.y -= LIGHT_MOVE_SPEED;
        }
        if (key == GLFW_KEY_E) {
            ::g_pLights->theLights[::g_selectedLightIndex].position.y += LIGHT_MOVE_SPEED;
        }

        if (key == GLFW_KEY_W)
        {
            ::g_pLights->theLights[::g_selectedLightIndex].position.z += LIGHT_MOVE_SPEED;
        }
        if (key == GLFW_KEY_S) {
            ::g_pLights->theLights[::g_selectedLightIndex].position.z -= LIGHT_MOVE_SPEED;
        }

        // 1 and 2 changes linear attenuation
        // 	vec4 atten;		// x = constant, y = linear, z = quadratic, w = DistanceCutOff
        if (key == GLFW_KEY_1)
        {
            // Drop by 1%
            ::g_pLights->theLights[::g_selectedLightIndex].atten.y *= 0.99f;
        }
        if (key == GLFW_KEY_2) {
            // Increase linear attenuation by 1%
            ::g_pLights->theLights[::g_selectedLightIndex].atten.y *= 1.01f;
        }

        // 3 and 4 changes quadratic
        // 	vec4 atten;		// x = constant, y = linear, z = quadratic, w = DistanceCutOff
        if (key == GLFW_KEY_3)
        {
            // Drop by 1%
            ::g_pLights->theLights[::g_selectedLightIndex].atten.z *= 0.99f;
        }
        if (key == GLFW_KEY_4) {
            // Increase linear attenuation by 1%
            ::g_pLights->theLights[::g_selectedLightIndex].atten.z *= 1.01f;
        }

        // Inner angle
        if (key == GLFW_KEY_5) {
            // Make inner spot light angle less by 0.5%
            ::g_pLights->theLights[::g_selectedLightIndex].param1.y -= 0.05f;
        }
        if (key == GLFW_KEY_6) {
            ::g_pLights->theLights[::g_selectedLightIndex].param1.y += 0.05f;
        }
        // Outer angle
        if (key == GLFW_KEY_7) {
            // Make outer spot light angle less by 0.5%
            ::g_pLights->theLights[::g_selectedLightIndex].param1.z -= 0.05f;
        }
        if (key == GLFW_KEY_8) {
            ::g_pLights->theLights[::g_selectedLightIndex].param1.z += 0.05f;
        }


        //if (key == GLFW_KEY_O) 
        //{
        //    // HACK: GOTCHA
        //    ::g_selectedLightIndex++;
        //}

        if (key == GLFW_KEY_9)
        {
            g_ShowLightDebugSphereThings = false;
        }
        if (key == GLFW_KEY_0) {
            g_ShowLightDebugSphereThings = true;
        }

    }//if ((mods & GLFW_MOD_CONTROL) == GLFW_MOD_CONTROL)

    const float OBJECT_ROTATION_SPEED = 0.1f;
    const float OBJECT_SCALE_SPEED = 0.1f;

    // Move a mesh in the scene
    if ((mods & GLFW_MOD_SHIFT) == GLFW_MOD_SHIFT)
    {
        // Then shift (and maybe something else) is down
        
        if (key == GLFW_KEY_A)  
        {  
            ::g_MeshesToDraw[ ::g_selectedObjectIndex ]->position.x -= OBJECT_MOVE_SPEED;
        }
        if (key == GLFW_KEY_D)  {
            ::g_MeshesToDraw[::g_selectedObjectIndex]->position.x += OBJECT_MOVE_SPEED;
        }

        if (key == GLFW_KEY_Q)  
        {  
            ::g_MeshesToDraw[ ::g_selectedObjectIndex ]->position.y -= OBJECT_MOVE_SPEED;
        }
        if (key == GLFW_KEY_E)  {
            ::g_MeshesToDraw[::g_selectedObjectIndex]->position.y += OBJECT_MOVE_SPEED;
        }

        if (key == GLFW_KEY_W)  
        {  
            ::g_MeshesToDraw[ ::g_selectedObjectIndex ]->position.z += OBJECT_MOVE_SPEED;
        }
        if (key == GLFW_KEY_S)  {
            ::g_MeshesToDraw[::g_selectedObjectIndex]->position.z -= OBJECT_MOVE_SPEED;
        }

        //Rotation
        if (key == GLFW_KEY_Z) {
            ::g_MeshesToDraw[::g_selectedObjectIndex]->orientation.x -= OBJECT_ROTATION_SPEED;
        }
        if (key == GLFW_KEY_X) {
            ::g_MeshesToDraw[::g_selectedObjectIndex]->orientation.y -= OBJECT_ROTATION_SPEED;
        }
        if (key == GLFW_KEY_C) {
            ::g_MeshesToDraw[::g_selectedObjectIndex]->orientation.z -= OBJECT_ROTATION_SPEED;
        }

        //Scale
        if (key == GLFW_KEY_V) {
            ::g_MeshesToDraw[::g_selectedObjectIndex]->scale += OBJECT_SCALE_SPEED;
        }
        if (key == GLFW_KEY_B) {
            ::g_MeshesToDraw[::g_selectedObjectIndex]->scale -= OBJECT_SCALE_SPEED;
        }

        if ( (key == GLFW_KEY_O) && (action == GLFW_PRESS) )
        {
            // TODO: ERROR here if out of range
            if (::g_selectedObjectIndex == 0)
            {
                // Yes, so if we -- it, we're screwed.
                // Set it the LAST index in the vector
                ::g_selectedObjectIndex = (unsigned int)(::g_MeshesToDraw.size() - 1);
            }
            else
            {
                // We can --
                ::g_selectedObjectIndex--;  
            }
        }
        if ( (key == GLFW_KEY_P) && (action == GLFW_PRESS) )  // orGLFW_RELEASE
        {
            ::g_selectedObjectIndex++;

            // To high? 
            if (::g_selectedObjectIndex >= ::g_MeshesToDraw.size() )
            {
                // Yeah, so clamp it? Wrap around?
                ::g_selectedObjectIndex = 0;
            }

            std::cout << "Selected object now: " << ::g_selectedObjectIndex << std::endl;;
        }

        if ( key == GLFW_KEY_ENTER && action == GLFW_PRESS)
        {
            std::cout << "Selected Object:\nX: " << ::g_MeshesToDraw[::g_selectedObjectIndex]->position.x << " Y: " << ::g_MeshesToDraw[::g_selectedObjectIndex]->position.y <<
                " Z: " << ::g_MeshesToDraw[::g_selectedObjectIndex]->position.z << "\nRotation (Orientation):\nX:" << ::g_MeshesToDraw[::g_selectedObjectIndex]->orientation.x
                << " Y: " << ::g_MeshesToDraw[::g_selectedObjectIndex]->orientation.y << " Z: " << ::g_MeshesToDraw[::g_selectedObjectIndex]->orientation.z <<
                "\nScale: " << ::g_MeshesToDraw[::g_selectedObjectIndex]->scale << std::endl;

            std::cout << "Selected Light:\nX: " << ::g_pLights->theLights[::g_selectedLightIndex].position.x << " Y: " << ::g_pLights->theLights[::g_selectedLightIndex].position.y
                << " Z: " << ::g_pLights->theLights[::g_selectedLightIndex].position.z << "\nAttenuation:\nX: " << ::g_pLights->theLights[::g_selectedLightIndex].atten.x <<
                " Y: " << ::g_pLights->theLights[::g_selectedLightIndex].position.y << " Z: " << ::g_pLights->theLights[::g_selectedLightIndex].position.z;

        }
       

 


    }//if ((mods & GLFW_MOD_SHIFT) == GLFW_MOD_SHIFT)




    //// Are all modifiers up?
    //if ( ! areAnyModifiersDown(mods) )
    //{

    //    // Move the camera 
    //    if (key == GLFW_KEY_A)
    //    {
    //        // Go left
    //        ::g_cameraEye.x -= CAMERA_MOVE_SPEED;
    ////        ::g_cameraTarget.x -= CAMERA_SPEED;
    //    }
    //    if (key == GLFW_KEY_D)
    //    {
    //        // Go right
    //        ::g_cameraEye.x += CAMERA_MOVE_SPEED;
    ////        ::g_cameraTarget.x += CAMERA_SPEED;
    //    }

    //    if (key == GLFW_KEY_W)
    //    {
    //        // Go forward
    //        ::g_cameraEye.z -= CAMERA_MOVE_SPEED;
    ////        ::g_cameraTarget.x -= CAMERA_SPEED;
    //    }
    //    if (key == GLFW_KEY_S)
    //    {
    //        // Go back
    //        ::g_cameraEye.z += CAMERA_MOVE_SPEED;
    ////        ::g_cameraTarget.x += CAMERA_SPEED;
    //    }

    //    if (key == GLFW_KEY_Q)
    //    {
    //        // Go down
    //        ::g_cameraEye.y -= CAMERA_MOVE_SPEED;
    ////        ::g_cameraTarget.x -= CAMERA_SPEED;
    //    }
    //    if (key == GLFW_KEY_E)
    //    {
    //        // Go up
    //        ::g_cameraEye.y += CAMERA_MOVE_SPEED;
    ////        ::g_cameraTarget.x += CAMERA_SPEED;
    //    }
    //}// if ( ! areAnyModifiersDown(mods) )
    return;
}
