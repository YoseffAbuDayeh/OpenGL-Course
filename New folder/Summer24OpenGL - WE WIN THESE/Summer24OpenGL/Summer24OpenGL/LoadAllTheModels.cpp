#include "globalOpenGL.h"
#include "sharedThings.h"

#include "cBasicTextureManager/cBasicTextureManager.h"
#include "cVAOManager/cVAOManager.h"
#include "cMeshObject.h"

#include <iostream>

extern cVAOManager* g_pMeshManager;

extern int dungeon[19][19];

void LoadTextures(cBasicTextureManager* pTextureManager)
{
    pTextureManager->SetBasePath("assets/textures");
    if (pTextureManager->Create2DTextureFromBMPFile("fire.bmp", true))
    {
        std::cout << "Loaded fire.bmp OK" << std::endl;
    }
    if (pTextureManager->Create2DTextureFromBMPFile("water.bmp", true))
    {
        std::cout << "Loaded water.bmp OK" << std::endl;
    }
    if (pTextureManager->Create2DTextureFromBMPFile("floor.bmp", true))
    {
        std::cout << "Loaded floor.bmp OK" << std::endl;
    }
    if (pTextureManager->Create2DTextureFromBMPFile("wall.bmp", true))
    {
        std::cout << "Loaded wall.bmp OK" << std::endl;
    }
    if (pTextureManager->Create2DTextureFromBMPFile("anv.bmp", true))
    {
        std::cout << "Loaded anv.bmp OK" << std::endl;
    }
    if (pTextureManager->Create2DTextureFromBMPFile("bag.bmp", true))
    {
        std::cout << "Loaded bag.bmp OK" << std::endl;
    }

    if (pTextureManager->Create2DTextureFromBMPFile("bottle.bmp", true))
    {
        std::cout << "Loaded bottle.bmp OK" << std::endl;
    }
    if (pTextureManager->Create2DTextureFromBMPFile("comp.bmp", true))
    {
        std::cout << "Loaded comp.bmp OK" << std::endl;
    }

    if (pTextureManager->Create2DTextureFromBMPFile("cry.bmp", true))
    {
        std::cout << "Loaded cry.bmp OK" << std::endl;
    }


    if (pTextureManager->Create2DTextureFromBMPFile("lant.bmp", true))
    {
        std::cout << "Loaded lant.bmp OK" << std::endl;
    }

    if (pTextureManager->Create2DTextureFromBMPFile("mug.bmp", true))
    {
        std::cout << "Loaded mug.bmp OK" << std::endl;
    }
    if (pTextureManager->Create2DTextureFromBMPFile("plant.bmp", true))
    {
        std::cout << "Loaded plant.bmp OK" << std::endl;
    }
    if (pTextureManager->Create2DTextureFromBMPFile("skel.bmp", true))
    {
        std::cout << "Loaded skel.bmp OK" << std::endl;
    }
    if (pTextureManager->Create2DTextureFromBMPFile("torch.bmp", true))
    {
        std::cout << "Loaded torch.bmp OK" << std::endl;
    }
    if (pTextureManager->Create2DTextureFromBMPFile("tree.bmp", true))
    {
        std::cout << "Loaded tree.bmp OK" << std::endl;
    }



    return;
}

void LoadFilesIntoVAOManager(GLuint program)
{
    sModelDrawInfo meshCompass;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/compass.ply", meshCompass, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }

    sModelDrawInfo meshBag;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/bag.ply", meshBag, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshAnvil;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/anvil.ply", meshAnvil, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshTree;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/tree.ply", meshTree, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshPlant;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/plant.ply", meshPlant, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshCamp;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/camp.ply", meshCamp, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshCrystal2;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/cry2.ply", meshCrystal2, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshCrystal1;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/cry1.ply", meshCrystal1, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshCrystal3;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/cry3.ply", meshCrystal3, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshCrystal4;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/cry4.ply", meshCrystal4, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshCrystal5;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/cry5.ply", meshCrystal5, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshBottle1;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/bottle1.ply", meshBottle1, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshBottle2;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/bottle2.ply", meshBottle2, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshBottle3;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/bottle3.ply", meshBottle3, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshBottle4;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/bottle4.ply", meshBottle4, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshBottle5;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/bottle5.ply", meshBottle5, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshBottle6;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/bottle6.ply", meshBottle6, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshBottle7;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/bottle7.ply", meshBottle7, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshSkeleton;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/skel1.ply", meshSkeleton, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshSkeleton2;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/skel2.ply", meshSkeleton2, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshSkeleton3;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/skel3.ply", meshSkeleton3, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshMug;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/mug.ply", meshMug, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshFloor;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/Floor.ply", meshFloor, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo meshWall;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/Wall.ply", meshWall, program))
    {
        std::cout << "ERROR: Didn't load the wall" << std::endl;
    }

    sModelDrawInfo meshLantern;
    if (!::g_pMeshManager->LoadModelIntoVAO("assets/models/Lantern.ply", meshLantern, program))
    {
        std::cout << "ERROR: Didn't load the floor" << std::endl;
    }
    sModelDrawInfo wallMesh;
    if (::g_pMeshManager->LoadModelIntoVAO("assets/models/Wall.ply", wallMesh, program))
    {
        std::cout << "loaded: "
            << wallMesh.meshName << " "
            << wallMesh.numberOfVertices << " vertices" << std::endl;
    }

    sModelDrawInfo floorMesh;
    if (::g_pMeshManager->LoadModelIntoVAO("assets/models/Floor.ply", floorMesh, program))
    {
        std::cout << "loaded: "
            << floorMesh.meshName << " "
            << floorMesh.numberOfVertices << " vertices" << std::endl;
    }
    
    sModelDrawInfo torchMesh;
    if (::g_pMeshManager->LoadModelIntoVAO("assets/models/torch.ply", torchMesh, program))
    {
        std::cout << "loaded: "
            << torchMesh.meshName << " "
            << torchMesh.numberOfVertices << " vertices" << std::endl;
    }

    
    sModelDrawInfo flameMesh;
    if (::g_pMeshManager->LoadModelIntoVAO("assets/models/flame.ply", flameMesh, program))
    {
        std::cout << "loaded: "
            << flameMesh.meshName << " "
            << flameMesh.numberOfVertices << " vertices" << std::endl;
    }
    
    sModelDrawInfo waterMesh;
    if (::g_pMeshManager->LoadModelIntoVAO("assets/models/Water.ply", waterMesh, program))
    {
        std::cout << "loaded: "
            << waterMesh.meshName << " "
            << waterMesh.numberOfVertices << " vertices" << std::endl;
    }




    return;
}

void LoadModelsIntoScene(void)
{

    cMeshObject* pWater = new cMeshObject();
    pWater->meshFileName = "assets/models/Water.ply";
    pWater->textureNames[1] = "water.bmp";
    pWater->textureBlendRatio[1] = 1.0f;
    pWater->bOverrideVertexModelColour = true;
    pWater->bUseTextureAsColour = true;
    pWater->colourRGB = glm::vec3(0.0f, 0.0f, 1.0f);
    pWater->position = glm::vec3(7.87,-0.5,10.5);
    pWater->scale /= 100;
    pWater->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pWater);


    cMeshObject* pCrystal21 = new cMeshObject();
    pCrystal21->meshFileName = "assets/models/cry2.ply";
    pCrystal21->bOverrideVertexModelColour = true;
    pCrystal21->colourRGB = glm::vec3(0.5f, 0.0f, 0.5f);
    pCrystal21->shinniness = 10000.f;
    pCrystal21->alphaTransparency = 0.6f;
    pCrystal21->position = glm::vec3(9.37,-0.8,8.399);
    pCrystal21->scale /= 100;
    pCrystal21->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pCrystal21);

    cMeshObject* pBot21 = new cMeshObject();
    pBot21->meshFileName = "assets/models/bottle7.ply";
    pBot21->bOverrideVertexModelColour = true;
    pBot21->alphaTransparency = 0.6f;
    pBot21->colourRGB = glm::vec3(222.0/255.0, 184.0 / 255.0, 135.0 / 255.0);
    pBot21->position = glm::vec3(9.77, -0.8, 9.4);
    pBot21->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pBot21);

    cMeshObject* pMug21 = new cMeshObject();
    pMug21->meshFileName = "assets/models/mug.ply";
    pMug21->bOverrideVertexModelColour = true;
    pMug21->colourRGB = glm::vec3(0.66f, 0.66f, 0.66f);
    pMug21->position = glm::vec3(9.37,-0.8,8.3999);
    pMug21->scale /= 100.0f;
    pMug21->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pMug21);


    cMeshObject* pCamp = new cMeshObject();
    pCamp->meshFileName = "assets/models/camp.ply";
    pCamp->bOverrideVertexModelColour = true;
    pCamp->colourRGB = glm::vec3(245.0 / 255.0, 222.0 / 255.0, 179.0 / 255.0);
    pCamp->position = glm::vec3(5.07,0.0,7.8);
    pCamp->scale /= 300;
    pCamp->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pCamp);


    cMeshObject* pflame7 = new cMeshObject();
    pflame7->meshFileName = "assets/models/flame.ply";
    pflame7->bOverrideVertexModelColour = true;
    pflame7->colourRGB = glm::vec3(1.0f, 0.0f, 0.0f);
    pflame7->textureNames[0] = "fire.bmp";
    pflame7->textureBlendRatio[0] = 1.0f;
    pflame7->bUseTextureAsColour = true;
    pflame7->position = glm::vec3(17.0f, 0.6f, 11.5f);
    pflame7->scale /= 100.0f;
    pflame7->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pflame7);

    cMeshObject* pflame8 = new cMeshObject();
    pflame8->meshFileName = "assets/models/flame.ply";
    pflame8->bOverrideVertexModelColour = true;
    pflame8->colourRGB = glm::vec3(1.0f, 0.0f, 0.0f);
    pflame8->position = glm::vec3(17.0f, 0.6f, 2.0f);
    pflame8->textureNames[0] = "fire.bmp";
    pflame8->textureBlendRatio[0] = 1.0f;
    pflame8->bUseTextureAsColour = true;
    pflame8->orientation.y = glm::radians(180.0f);
    pflame8->scale /= 100.0f;
    pflame8->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pflame8);


    cMeshObject* pflame9 = new cMeshObject();
    pflame9->meshFileName = "assets/models/flame.ply";
    pflame9->bOverrideVertexModelColour = true;
    pflame9->colourRGB = glm::vec3(1.0f, 0.0f, 0.0f);
    pflame9->position = glm::vec3(4.5f, 0.6f, 4.0f);
    pflame9->textureNames[0] = "fire.bmp";
    pflame9->textureBlendRatio[0] = 1.0f;
    pflame9->bUseTextureAsColour = true;
    pflame9->orientation.y = glm::radians(180.0f);
    pflame9->scale /= 100.0f;
    pflame9->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pflame9);

    cMeshObject* pTorch4 = new cMeshObject();
    pTorch4->meshFileName = "assets/models/torch.ply";
    pTorch4->bOverrideVertexModelColour = true;
    pTorch4->bUseTextureAsColour = true;
    pTorch4->colourRGB = glm::vec3(139.0 / 255.0, 69.0 / 255.0, 19.0 / 255.0);
    pTorch4->textureNames[0] = "torch.bmp";
    pTorch4->position = glm::vec3(2.5f, 0.5f, 15.6f);
    pTorch4->scale /= 100.0f;
    pTorch4->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pTorch4);

    cMeshObject* pflame4 = new cMeshObject();
    pflame4->meshFileName = "assets/models/flame.ply";
    pflame4->bOverrideVertexModelColour = true;
    pflame4->colourRGB = glm::vec3(1.0f, 0.0f, 0.0f);
    pflame4->position = glm::vec3(2.5f, 1.f, 15.2f);
    pflame4->scale /= 100.0f;
    pflame4->textureNames[0] = "fire.bmp";
    pflame4->textureBlendRatio[0] = 1.0f;
    pflame4->bUseTextureAsColour = true;
    pflame4->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pflame4);

    cMeshObject* pflame3 = new cMeshObject();
    pflame3->meshFileName = "assets/models/flame.ply";
    pflame3->bOverrideVertexModelColour = true;
    pflame3->colourRGB = glm::vec3(1.0f, 0.0f, 0.0f);
    pflame3->position = glm::vec3(10.5f, 0.6f, 0.4f);
    pflame3->textureNames[0] = "fire.bmp";
    pflame3->bUseTextureAsColour = true;
    pflame3->textureBlendRatio[0] = 1.0f;
    pflame3->orientation.y = glm::radians(180.0f);
    pflame3->scale /= 100.0f;
    pflame3->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pflame3);

    cMeshObject* pflame1 = new cMeshObject();
    pflame1->meshFileName = "assets/models/flame.ply";
    pflame1->position = glm::vec3(17.5f, 0.8f, 17.1f);
    pflame1->scale /= 100.0f;
    pflame1->bOverrideVertexModelColour = true;
    pflame1->colourRGB = glm::vec3(1.0f, 0.0f, 0.0f);
    pflame1->textureNames[0] = "fire.bmp";
    pflame1->textureBlendRatio[0] = 1.0f;
    pflame1->bUseTextureAsColour = true;
    pflame1->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pflame1);

    cMeshObject* pflame2 = new cMeshObject();
    pflame2->meshFileName = "assets/models/flame.ply";
    pflame2->bOverrideVertexModelColour = true;
    pflame2->colourRGB = glm::vec3(1.0f, 0.0f, 0.0f);
    pflame2->textureNames[0] = "fire.bmp";
    pflame2->bUseTextureAsColour = true;
    pflame2->textureBlendRatio[0] = 1.0f;
    pflame2->position = glm::vec3(1.0f, 0.8f, 0.4f);
    pflame2->orientation.y = glm::radians(180.0f);
    pflame2->scale /= 100.0f;
    pflame2->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pflame2);


    cMeshObject* pflame5 = new cMeshObject();
    pflame5->meshFileName = "assets/models/flame.ply";
    pflame5->bOverrideVertexModelColour = true;
    pflame5->colourRGB = glm::vec3(1.0f, 0.0f, 0.0f);
    pflame5->position = glm::vec3(5.0f, 0.8f, 13.1f);
    pflame5->scale /= 100.0f;
    pflame5->textureNames[0] = "fire.bmp";
    pflame5->bUseTextureAsColour = true;
    pflame5->textureBlendRatio[0] = 1.0f;
    pflame5->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pflame5);
    cMeshObject* pflame6 = new cMeshObject();
    pflame6->meshFileName = "assets/models/flame.ply";
    pflame6->bOverrideVertexModelColour = true;
    pflame6->textureNames[0] = "fire.bmp";
    pflame6->bUseTextureAsColour = true;
    pflame6->textureBlendRatio[0] = 1.0f;
    pflame6->colourRGB = glm::vec3(1.0f, 0.0f, 0.0f);
    pflame6->position = glm::vec3(11.0f, 0.8f, 11.1f);
    pflame6->scale /= 100.0f;
    pflame6->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pflame6);


    cMeshObject* pMug1 = new cMeshObject();
    pMug1->meshFileName = "assets/models/mug.ply";
    pMug1->bOverrideVertexModelColour = true;
    pMug1->colourRGB = glm::vec3(0.66f, 0.66f, 0.66f);
    pMug1->textureNames[0] = "mug.bmp";
    pMug1->bUseTextureAsColour = true;
    pMug1->position = glm::vec3(16.67f, 0.0f, 11.17f);
    pMug1->scale /= 100.0f;
    pMug1->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pMug1);

    cMeshObject* pMug2 = new cMeshObject();
    pMug2->meshFileName = "assets/models/mug.ply";
    pMug2->bOverrideVertexModelColour = true;
    pMug2->colourRGB = glm::vec3(0.66f, 0.66f, 0.66f);
    pMug2->position = glm::vec3(10.17f, 0.0f, 11.15f);
    pMug2->textureNames[0] = "mug.bmp";
    pMug2->bUseTextureAsColour = true;
    pMug2->scale /= 100.0f;
    pMug2->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pMug2);

    cMeshObject* pMug3 = new cMeshObject();
    pMug3->meshFileName = "assets/models/mug.ply";
    pMug3->bOverrideVertexModelColour = true;
    pMug3->colourRGB = glm::vec3(0.66f, 0.66f, 0.66f);
    pMug3->textureNames[0] = "mug.bmp";
    pMug3->bUseTextureAsColour = true;
    pMug3->position = glm::vec3(5.17f, 0.0f, 4.67f);
    pMug3->scale /= 100.0f;
    pMug3->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pMug3);

    cMeshObject* pSkeleton1 = new cMeshObject();
    pSkeleton1->meshFileName = "assets/models/skel1.ply";
    pSkeleton1->bOverrideVertexModelColour = true;
    pSkeleton1->colourRGB = glm::vec3(1.0f);
    pSkeleton1->textureNames[0] = "skel.bmp";
    pSkeleton1->bUseTextureAsColour = true;
    pSkeleton1->position = glm::vec3(1.17f, 0.15f, 0.67f);
    pSkeleton1->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pSkeleton1);


    cMeshObject* pSkeleton3 = new cMeshObject();
    pSkeleton3->meshFileName = "assets/models/skel3.ply";
    pSkeleton3->bOverrideVertexModelColour = true;
    pSkeleton3->textureNames[0] = "skel.bmp";
    pSkeleton3->bUseTextureAsColour = true;
    pSkeleton3->colourRGB = glm::vec3(1.0f);
    pSkeleton3->position = glm::vec3(5.17f, 0.15f, 5.67f);
    pSkeleton3->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pSkeleton3);

    cMeshObject* pSkeleton2 = new cMeshObject();
    pSkeleton2->meshFileName = "assets/models/skel2.ply";
    pSkeleton2->bOverrideVertexModelColour = true;
    pSkeleton2->colourRGB = glm::vec3(1.0f);
    pSkeleton2->textureNames[0] = "skel.bmp";
    pSkeleton2->bUseTextureAsColour = true;
    pSkeleton2->position = glm::vec3(4.67f, 0.15f, 12.17f);
    pSkeleton2->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pSkeleton2);

    cMeshObject* pBot10 = new cMeshObject();
    pBot10->meshFileName = "assets/models/bottle7.ply";
    pBot10->bOverrideVertexModelColour = true;
    pBot10->colourRGB = glm::vec3(0.0,1.0,0.0);
    pBot10->alphaTransparency = 0.7;
    pBot10->textureNames[0] = "bottle.bmp";
    pBot10->bUseTextureAsColour = true;
    pBot10->position = glm::vec3(4.67f, 0.15f, 13.3f);
    pBot10->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pBot10);
    cMeshObject* pBot9 = new cMeshObject();
    pBot9->meshFileName = "assets/models/bottle7.ply";
    pBot9->bOverrideVertexModelColour = true;
    pBot9->alphaTransparency = 0.7;
    pBot9->textureNames[0] = "bottle.bmp";
    pBot9->bUseTextureAsColour = true;
    pBot9->colourRGB = glm::vec3(0.0, 1.0, 0.0);
    pBot9->position = glm::vec3(10.67f, 0.15f, 0.3f);
    pBot9->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pBot9);

    cMeshObject* pBot8 = new cMeshObject();
    pBot8->meshFileName = "assets/models/bottle7.ply";
    pBot8->bOverrideVertexModelColour = true;
    pBot8->alphaTransparency = 0.7;
    pBot8->textureNames[0] = "bottle.bmp";
    pBot8->bUseTextureAsColour = true;
    pBot8->colourRGB = glm::vec3(0.0, 1.0, 0.0);
    pBot8->position = glm::vec3(16.67f, 0.15f, 11.3f);
    pBot8->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pBot8);

    cMeshObject* pBot7 = new cMeshObject();
    pBot7->meshFileName = "assets/models/bottle7.ply";
    pBot7->bOverrideVertexModelColour = true;
    pBot7->alphaTransparency = 0.7;
    pBot7->textureNames[0] = "bottle.bmp";
    pBot7->bUseTextureAsColour = true;
    pBot7->colourRGB = glm::vec3(0.0, 1.0, 0.0);
    pBot7->position = glm::vec3(17.67f, 0.15f, 17.3f);
    pBot7->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pBot7);

    cMeshObject* pBot6 = new cMeshObject();
    pBot6->meshFileName = "assets/models/bottle6.ply";
    pBot6->bOverrideVertexModelColour = true;
    pBot6->alphaTransparency = 0.7;
    pBot6->textureNames[0] = "bottle.bmp";
    pBot6->bUseTextureAsColour = true;
    pBot6->colourRGB = glm::vec3(0.0, 1.0, 0.0);
    pBot6->position = glm::vec3(16.67f, 0.15f, 2.3f);
    pBot6->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pBot6);

    cMeshObject* pBot5 = new cMeshObject();
    pBot5->meshFileName = "assets/models/bottle5.ply";
    pBot5->bOverrideVertexModelColour = true;
    pBot5->alphaTransparency = 0.7;
    pBot5->textureNames[0] = "bottle.bmp";
    pBot5->bUseTextureAsColour = true;
    pBot5->colourRGB = glm::vec3(0.0, 1.0, 0.0);
    pBot5->position = glm::vec3(0.67f, 0.15f, 0.3f);
    pBot5->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pBot5);

    cMeshObject* pBot4 = new cMeshObject();
    pBot4->meshFileName = "assets/models/bottle4.ply";
    pBot4->bOverrideVertexModelColour = true;
    pBot4->alphaTransparency = 0.7;
    pBot4->textureNames[0] = "bottle.bmp";
    pBot4->bUseTextureAsColour = true;
    pBot4->colourRGB = glm::vec3(0.0, 1.0, 0.0);
    pBot4->position = glm::vec3(4.67f, 0.15f, 4.8f);
    pBot4->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pBot4);

    cMeshObject* pBot3 = new cMeshObject();
    pBot3->meshFileName = "assets/models/bottle3.ply";
    pBot3->bOverrideVertexModelColour = true;
    pBot3->alphaTransparency = 0.7;
    pBot3->textureNames[0] = "bottle.bmp";
    pBot3->bUseTextureAsColour = true;
    pBot3->colourRGB = glm::vec3(0.0, 1.0, 0.0);
    pBot3->position = glm::vec3(10.67f, 0.15f, 0.3f);
    pBot3->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pBot3);

    cMeshObject* pBot1 = new cMeshObject();
    pBot1->meshFileName = "assets/models/bottle1.ply";
    pBot1->bOverrideVertexModelColour = true;
    pBot1->alphaTransparency = 0.7;
    pBot1->textureNames[0] = "bottle.bmp";
    pBot1->bUseTextureAsColour = true;
    pBot1->colourRGB = glm::vec3(0.0, 1.0, 0.0);
    pBot1->position = glm::vec3(10.17f, 0.15f, 11.17f);
    pBot1->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pBot1);

    cMeshObject* pBot2 = new cMeshObject();
    pBot2->meshFileName = "assets/models/bottle2.ply";
    pBot2->bOverrideVertexModelColour = true;
    pBot2->alphaTransparency = 0.7;
    pBot2->textureNames[0] = "bottle.bmp";
    pBot2->bUseTextureAsColour = true;
    pBot2->colourRGB = glm::vec3(0.0, 1.0, 0.0);
    pBot2->position = glm::vec3(4.67f, 0.15f, 12.67);
    pBot2->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pBot2);

    cMeshObject* pTree2 = new cMeshObject();
    pTree2->meshFileName = "assets/models/tree.ply";
    pTree2->bOverrideVertexModelColour = true;
    pTree2->textureNames[0] = "tree.bmp";
    pTree2->bUseTextureAsColour = true;
    pTree2->colourRGB = glm::vec3(53.0/255.0, 46.0 / 255.0, 54.0 / 255.0);
    pTree2->position = glm::vec3(8.67, 0.0, 15.3);
    pTree2->scale /= 5;
    pTree2->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pTree2);



    cMeshObject* pPlant1 = new cMeshObject();
    pPlant1->meshFileName = "assets/models/plant.ply";
    pPlant1->bOverrideVertexModelColour = true;
    pPlant1->textureNames[0] = "plant.bmp";
    pPlant1->bUseTextureAsColour = true;
    pPlant1->colourRGB = glm::vec3(0.0f,1.0f,0.0f);
    pPlant1->position = glm::vec3(17.12, 0.0, 10.5);
    pPlant1->scale /= 3;
    pPlant1->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pPlant1);

    cMeshObject* pPlant2 = new cMeshObject();
    pPlant2->meshFileName = "assets/models/plant.ply";
    pPlant2->bOverrideVertexModelColour = true;
    pPlant2->colourRGB = glm::vec3(1.0f);
    pPlant2->textureNames[0] = "plant.bmp";
    pPlant2->bUseTextureAsColour = true;
    pPlant2->colourRGB = glm::vec3(0.0f, 1.0f, 0.0f);
    pPlant2->position = glm::vec3(17.5, 0.0, 10.9);
    pPlant2->scale /= 3;
    pPlant2->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pPlant2);

    cMeshObject* pPlant3 = new cMeshObject();
    pPlant3->meshFileName = "assets/models/plant.ply";
    pPlant3->bOverrideVertexModelColour = true;
    pPlant3->colourRGB = glm::vec3(1.0f);
    pPlant3->textureNames[0] = "plant.bmp";
    pPlant3->bUseTextureAsColour = true;
    pPlant3->colourRGB = glm::vec3(0.0f, 1.0f, 0.0f);
    pPlant3->position = glm::vec3(16.8, 0.0, 10.4);
    pPlant3->scale /= 3;
    pPlant3->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pPlant3);

    cMeshObject* pTree1 = new cMeshObject();
    pTree1->meshFileName = "assets/models/tree.ply";
    pTree1->bOverrideVertexModelColour = true;
    pTree1->colourRGB = glm::vec3(1.0f);
    pTree1->textureNames[0] = "tree.bmp";
    pTree1->bUseTextureAsColour = true;
    pTree1->colourRGB = glm::vec3(53.0 / 255.0, 46.0 / 255.0, 54.0 / 255.0);
    pTree1->position = glm::vec3(17.17, 0.0, 10.8);
    pTree1->scale /= 5;
    pTree1->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pTree1);


    cMeshObject* pPlant4 = new cMeshObject();
    pPlant4->meshFileName = "assets/models/plant.ply";
    pPlant4->bOverrideVertexModelColour = true;
    pPlant4->colourRGB = glm::vec3(1.0f);
    pPlant4->textureNames[0] = "plant.bmp";
    pPlant4->bUseTextureAsColour = true;
    pPlant4->colourRGB = glm::vec3(0.0f, 1.0f, 0.0f);
    pPlant4->position = glm::vec3(8.62, 0.0, 15.5);
    pPlant4->scale /= 3;
    pPlant4->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pPlant4);

    cMeshObject* pPlant6 = new cMeshObject();
    pPlant6->meshFileName = "assets/models/plant.ply";
    pPlant6->bOverrideVertexModelColour = true;
    pPlant6->textureNames[0] = "plant.bmp";
    pPlant6->bUseTextureAsColour = true;
    pPlant6->colourRGB = glm::vec3(0.0f, 1.0f, 0.0f);
    pPlant6->colourRGB = glm::vec3(1.0f);
    pPlant6->position = glm::vec3(8.52, 0.0, 15.6);
    pPlant6->scale /= 3;
    pPlant6->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pPlant6);
    cMeshObject* pPlant5 = new cMeshObject();
    pPlant5->meshFileName = "assets/models/plant.ply";
    pPlant5->bOverrideVertexModelColour = true;
    pPlant5->colourRGB = glm::vec3(1.0f);
    pPlant5->textureNames[0] = "plant.bmp";
    pPlant5->bUseTextureAsColour = true;
    pPlant5->colourRGB = glm::vec3(0.0f, 1.0f, 0.0f);
    pPlant5->position = glm::vec3(8.72, 0.0, 15.4);
    pPlant5->scale /= 3;
    pPlant5->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pPlant5);


    cMeshObject* pCrystal1 = new cMeshObject();
    pCrystal1->meshFileName = "assets/models/cry1.ply";
    pCrystal1->bOverrideVertexModelColour = true;
    pCrystal1->colourRGB = glm::vec3(0.5f, 0.0f, 0.5f);
    pCrystal1->position = glm::vec3(2.67, -0.19, 14.8);
    pCrystal1->shinniness = 10000.f;
    pCrystal1->textureNames[0] = "cry.bmp";
    pCrystal1->bUseTextureAsColour = true;
    pCrystal1->alphaTransparency = 0.6f;
    pCrystal1->scale /= 100;
    pCrystal1->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pCrystal1);

    cMeshObject* pCrystal5 = new cMeshObject();
    pCrystal5->meshFileName = "assets/models/cry5.ply";
    pCrystal5->bOverrideVertexModelColour = true;
    pCrystal5->textureNames[0] = "cry.bmp";
    pCrystal5->bUseTextureAsColour = true;
    pCrystal5->colourRGB = glm::vec3(0.5f, 0.0f, 0.5f);
    pCrystal5->position = glm::vec3(0.67, 0.0, 6.8);
    pCrystal5->shinniness = 10000.f;
    pCrystal5->alphaTransparency = 0.6f;
    pCrystal5->scale /= 100;
    pCrystal5->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pCrystal5);

    cMeshObject* pCrystal4 = new cMeshObject();
    pCrystal4->meshFileName = "assets/models/cry4.ply";
    pCrystal4->bOverrideVertexModelColour = true;
    pCrystal4->colourRGB = glm::vec3(0.5f, 0.0f, 0.5f);
    pCrystal4->shinniness = 10000.f;
    pCrystal4->textureNames[0] = "cry.bmp";
    pCrystal4->bUseTextureAsColour = true;
    pCrystal4->alphaTransparency = 0.6f;
    pCrystal4->position = glm::vec3(13.17, 0.0, 6.8);
    pCrystal4->scale /= 100;
    pCrystal4->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pCrystal4);

    cMeshObject* pCrystal3 = new cMeshObject();
    pCrystal3->meshFileName = "assets/models/cry3.ply";
    pCrystal3->bOverrideVertexModelColour = true;
    pCrystal3->colourRGB = glm::vec3(0.5f, 0.0f, 0.5f);
    pCrystal3->shinniness = 10000.f;
    pCrystal3->textureNames[0] = "cry.bmp";
    pCrystal3->bUseTextureAsColour = true;
    pCrystal3->alphaTransparency = 0.6f;
    pCrystal3->position = glm::vec3(11.17, 0.0, 17.3);
    pCrystal3->scale /= 100;
    pCrystal3->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pCrystal3);

    cMeshObject* pCrystal2 = new cMeshObject();
    pCrystal2->meshFileName = "assets/models/cry2.ply";
    pCrystal2->bOverrideVertexModelColour = true;
    pCrystal2->colourRGB = glm::vec3(0.5f, 0.0f, 0.5f);
    pCrystal2->shinniness = 10000.f;
    pCrystal2->textureNames[0] = "cry.bmp";
    pCrystal2->bUseTextureAsColour = true;
    pCrystal2->alphaTransparency = 0.6f;
    pCrystal2->position = glm::vec3(13.17, 0.0, 15.3);
    pCrystal2->scale /= 100;
    pCrystal2->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pCrystal2);
    

    cMeshObject* pCrystal41 = new cMeshObject();
    pCrystal41->meshFileName = "assets/models/cry2.ply";
    pCrystal41->bOverrideVertexModelColour = true;
    pCrystal41->colourRGB = glm::vec3(0.5f, 0.0f, 0.5f);
    pCrystal41->shinniness = 10000.f;
    pCrystal41->textureNames[0] = "cry.bmp";
    pCrystal41->bUseTextureAsColour = true;
    pCrystal41->alphaTransparency = 0.6f;
    pCrystal41->position = glm::vec3(9.67,0,1.17);
    pCrystal41->scale /= 100;
    pCrystal41->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pCrystal41);
    

    cMeshObject* pCrystal42 = new cMeshObject();
    pCrystal42->meshFileName = "assets/models/cry2.ply";
    pCrystal42->bOverrideVertexModelColour = true;
    pCrystal42->colourRGB = glm::vec3(0.5f, 0.0f, 0.5f);
    pCrystal42->shinniness = 10000.f;
    pCrystal42->textureNames[0] = "cry.bmp";
    pCrystal42->bUseTextureAsColour = true;
    pCrystal42->alphaTransparency = 0.6f;
    pCrystal42->position = glm::vec3(9.67,0,2.17);
    pCrystal42->scale /= 100;
    pCrystal42->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pCrystal42);
    

    cMeshObject* pCrystal43 = new cMeshObject();
    pCrystal43->meshFileName = "assets/models/cry2.ply";
    pCrystal43->bOverrideVertexModelColour = true;
    pCrystal43->colourRGB = glm::vec3(0.5f, 0.0f, 0.5f);
    pCrystal43->shinniness = 10000.f;
    pCrystal43->textureNames[0] = "cry.bmp";
    pCrystal43->bUseTextureAsColour = true;
    pCrystal43->alphaTransparency = 0.6f;
    pCrystal43->position = glm::vec3(8.67, 0, 2.17);
    pCrystal43->scale /= 100;
    pCrystal43->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pCrystal43);
    

    cMeshObject* pCrystal44 = new cMeshObject();
    pCrystal44->meshFileName = "assets/models/cry2.ply";
    pCrystal44->bOverrideVertexModelColour = true;
    pCrystal44->colourRGB = glm::vec3(0.5f,0.0f,0.5f);
    pCrystal44->shinniness = 10000.f;
    pCrystal44->textureNames[0] = "cry.bmp";
    pCrystal44->bUseTextureAsColour = true;
    pCrystal44->alphaTransparency = 0.6f;
    pCrystal44->position = glm::vec3(8.67, 0, 1.17);
    pCrystal44->scale /= 100;
    pCrystal44->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pCrystal44);




    cMeshObject* pTree3 = new cMeshObject();
    pTree3->meshFileName = "assets/models/tree.ply";
    pTree3->bOverrideVertexModelColour = true;
    pTree3->textureNames[0] = "tree.bmp";
    pTree3->bUseTextureAsColour = true;
    pTree3->colourRGB = glm::vec3(53.0 / 255.0, 46.0 / 255.0, 54.0 / 255.0);
    pTree3->position = glm::vec3(17.17, 0.0, 12.8);
    pTree3->scale /= 5;
    pTree3->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pTree3);

    cMeshObject* pPlant7 = new cMeshObject();
    pPlant7->meshFileName = "assets/models/plant.ply";
    pPlant7->bOverrideVertexModelColour = true;
    pPlant7->textureNames[0] = "plant.bmp";
    pPlant7->bUseTextureAsColour = true;
    pPlant7->colourRGB = glm::vec3(0.0,0.0,1.0);
    pPlant7->position = glm::vec3(17.0, 0.0, 12.7);
    pPlant7->scale /= 3;
    pPlant7->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pPlant7);

    cMeshObject* pPlant8 = new cMeshObject();
    pPlant8->meshFileName = "assets/models/plant.ply";
    pPlant8->bOverrideVertexModelColour = true;
    pPlant8->textureNames[0] = "plant.bmp";
    pPlant8->bUseTextureAsColour = true;
    pPlant8->colourRGB = glm::vec3(0.0, 0.0, 1.0);
    pPlant8->colourRGB = glm::vec3(1.0f);
    pPlant8->position = glm::vec3(17.3, 0.0, 12.9);
    pPlant8->scale /= 3;
    pPlant8->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pPlant8);

    cMeshObject* pPlant9 = new cMeshObject();
    pPlant9->meshFileName = "assets/models/plant.ply";
    pPlant9->bOverrideVertexModelColour = true;
    pPlant9->textureNames[0] = "plant.bmp";
    pPlant9->bUseTextureAsColour = true;
    pPlant9->colourRGB = glm::vec3(0.0, 0.0, 1.0);
    pPlant9->colourRGB = glm::vec3(1.0f);
    pPlant9->position = glm::vec3(16.8, 0.0, 12.7);
    pPlant9->scale /= 3;
    pPlant9->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pPlant9);



    cMeshObject* pCompass = new cMeshObject();
    pCompass->meshFileName = "assets/models/compass.ply";
    pCompass->bOverrideVertexModelColour = true;
    pCompass->textureNames[0] = "comp.bmp";
    pCompass->bUseTextureAsColour = true;
    pCompass->colourRGB = glm::vec3(53.0/255.0, 46.0 / 255.0, 54.0 / 255.0);
    pCompass->position = glm::vec3(5.6, 1.0, 0.7);
    pCompass->scale *= 2;
    pCompass->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pCompass);

    cMeshObject* pLantern = new cMeshObject();
    pLantern->meshFileName = "assets/models/Lantern.ply";
    pLantern->bOverrideVertexModelColour = true;
    pLantern->textureNames[0] = "lant.bmp";
    pLantern->bUseTextureAsColour = true;
    pLantern->colourRGB = glm::vec3(53.0 / 255.0, 46.0 / 255.0, 54.0 / 255.0);
    pLantern->position = glm::vec3(4.3, 0.0, 13.2);
    pLantern->scale /= 2;
    pLantern->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pLantern);


    cMeshObject* pAnvil = new cMeshObject();
    pAnvil->meshFileName = "assets/models/anvil.ply";
    pAnvil->bOverrideVertexModelColour = true;
    pAnvil->textureNames[0] = "anv.bmp";
    pAnvil->bUseTextureAsColour = true;
    pAnvil->colourRGB = glm::vec3(53.0 / 255.0, 46.0 / 255.0, 54.0 / 255.0);
    pAnvil->position = glm::vec3(5.5, 0.0, 0.7);
    pAnvil->scale /= 100;
    pAnvil->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pAnvil);


    cMeshObject* pBag = new cMeshObject();
    pBag->meshFileName = "assets/models/bag.ply";
    pBag->bOverrideVertexModelColour = true;
    pBag->textureNames[0] = "bag.bmp";
    pBag->bUseTextureAsColour = true;
    pBag->colourRGB = glm::vec3(77.0 / 255.0, 38.0 / 255.0, 33.0 / 255.0);
    pBag->position = glm::vec3(5.0, 1.0, 0.7);
    pBag->scale /= 1;
    pBag->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pBag);

    cMeshObject* pTorch1 = new cMeshObject();
    pTorch1->meshFileName = "assets/models/torch.ply";
    pTorch1->position = glm::vec3(17.5f, 0.3f, 17.5f);
    pTorch1->scale /= 100.0f;
    pTorch1->bOverrideVertexModelColour = true;
    pTorch1->textureNames[0] = "torch.bmp";
    pTorch1->bUseTextureAsColour = true;
    pTorch1->colourRGB = glm::vec3(2.0 / 255.0, 5.0 / 255.0, 16.0 / 255.0);
    pTorch1->bIsVisible = true;



    ::g_MeshesToDraw.push_back(pTorch1);  
    cMeshObject* pTorch2 = new cMeshObject();
    pTorch2->meshFileName = "assets/models/torch.ply";
    pTorch2->bOverrideVertexModelColour = true;
    pTorch2->textureNames[0] = "torch.bmp";
    pTorch2->bUseTextureAsColour = true;
    pTorch2->colourRGB = glm::vec3(2.0 / 255.0, 5.0 / 255.0, 16.0 / 255.0);
    pTorch2->position = glm::vec3(1.0f, 0.3f, 0.0f);
    pTorch2->orientation.y = glm::radians(180.0f);
    pTorch2->scale /= 100.0f;
    pTorch2->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pTorch2);

    cMeshObject* pTorch3 = new cMeshObject();
    pTorch3->meshFileName = "assets/models/torch.ply";
    pTorch3->bOverrideVertexModelColour = true;
    pTorch3->textureNames[0] = "torch.bmp";
    pTorch3->bUseTextureAsColour = true;
    pTorch3->colourRGB = glm::vec3(2.0 / 255.0, 5.0 / 255.0, 16.0 / 255.0);
    pTorch3->position = glm::vec3(10.5f, 0.3f, 0.0f);
    pTorch3->orientation.y = glm::radians(180.0f);
    pTorch3->scale /= 100.0f;
    pTorch3->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pTorch3);
    //tp





    cMeshObject* pTorch5 = new cMeshObject();
    pTorch5->meshFileName = "assets/models/torch.ply";
    pTorch5->bOverrideVertexModelColour = true;
    pTorch5->textureNames[0] = "torch.bmp";
    pTorch5->bUseTextureAsColour = true;
    pTorch5->colourRGB = glm::vec3(2.0 / 255.0, 5.0 / 255.0, 16.0 / 255.0);
    pTorch5->position = glm::vec3(5.0f, 0.3f, 13.5f);
    pTorch5->scale /= 100.0f;
    pTorch5->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pTorch5);
    cMeshObject* pTorch6 = new cMeshObject();
    pTorch6->meshFileName = "assets/models/torch.ply";
    pTorch6->bOverrideVertexModelColour = true;
    pTorch6->textureNames[0] = "torch.bmp";
    pTorch6->bUseTextureAsColour = true;
    pTorch6->colourRGB = glm::vec3(2.0 / 255.0, 5.0 / 255.0, 16.0 / 255.0);
    pTorch6->position = glm::vec3(11.0f, 0.3f, 11.5f);
    pTorch6->scale /= 100.0f;
    pTorch6->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pTorch6);

    cMeshObject* pTorch7 = new cMeshObject();
    pTorch7->meshFileName = "assets/models/torch.ply";
    pTorch7->bOverrideVertexModelColour = true;
    pTorch7->textureNames[0] = "torch.bmp";
    pTorch7->bUseTextureAsColour = true;
    pTorch7->colourRGB = glm::vec3(2.0 / 255.0, 5.0 / 255.0, 16.0 / 255.0);
    pTorch7->position = glm::vec3(17.0f, 0.3f, 11.5f);
    pTorch7->scale /= 100.0f;
    pTorch7->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pTorch7);

    cMeshObject* pTorch8 = new cMeshObject();
    pTorch8->meshFileName = "assets/models/torch.ply";
    pTorch8->bOverrideVertexModelColour = true;
    pTorch8->textureNames[0] = "torch.bmp";
    pTorch8->bUseTextureAsColour = true;
    pTorch8->colourRGB = glm::vec3(2.0 / 255.0, 5.0 / 255.0, 16.0 / 255.0);
    pTorch8->position = glm::vec3(17.0f, 0.3f, 2.0f);
    pTorch8->orientation.y = glm::radians(180.0f);
    pTorch8->scale /= 100.0f;
    pTorch8->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pTorch8);


    cMeshObject* pTorch9 = new cMeshObject();
    pTorch9->meshFileName = "assets/models/torch.ply";
    pTorch9->bOverrideVertexModelColour = true;
    pTorch9->textureNames[0] = "torch.bmp";
    pTorch9->bUseTextureAsColour = true;
    pTorch9->colourRGB = glm::vec3(2.0 / 255.0, 5.0 / 255.0, 16.0 / 255.0);
    pTorch9->position = glm::vec3(4.5f, 0.3f, 4.0f);
    pTorch9->orientation.y = glm::radians(180.0f);
    pTorch9->scale /= 100.0f;
    pTorch9->bIsVisible = true;
    ::g_MeshesToDraw.push_back(pTorch9);


    // 
    // 
    //cMeshObject* pFloor = new cMeshObject();
    //pFloor->meshFileName = "assets/models/Dungeon_models/Floors/SM_Env_Dwarf_Floor_07_no_UV.ply";
    ////pFloor->bIsWireFrame = true;
    //pFloor->position.y = -5.0f;
    //pFloor->position.x = 10.0f;
    //pFloor->bOverrideVertexModelColour = true;
    //pFloor->colourRGB = glm::vec3(1.0f, 1.0f, 1.0f);
    //pFloor->scale = 0.025f;
    //::g_MeshesToDraw.push_back(pFloor);

    //cMeshObject* pSkull = new cMeshObject();
    //pSkull->meshFileName = "assets/models/Dungeon_models/Dead bodies, etc/SM_Item_Skull_01_no_UV.ply";
    ////pSkull->bIsWireFrame = true;
    //pSkull->bOverrideVertexModelColour = true;
    //pSkull->colourRGB = glm::vec3(1.0f, 1.0f, 1.0f);
    //pSkull->scale = 15.0f;
    //::g_MeshesToDraw.push_back(pSkull);


    ::g_pSmoothSphere = new cMeshObject();
    ::g_pSmoothSphere->meshFileName = "assets/models/Isoshphere_flat_4div_xyz_n_rgba_uv.ply";
//    ::g_pSmoothSphere->meshFileName = "assets/models/Isoshphere_smooth_inverted_normals_xyz_n_rgba.ply";
    ::g_pSmoothSphere->bIsWireFrame = true;
    ::g_pSmoothSphere->bOverrideVertexModelColour = true;
    ::g_pSmoothSphere->colourRGB = glm::vec3(1.0f);
    ::g_pSmoothSphere->scale = 1.0f;
    ::g_pSmoothSphere->bIsVisible = true;
//    ::g_MeshesToDraw.push_back(::g_pSmoothSphere)


    return;
}

void LoadMap(void)
{

    float floorWidth = 250.0f / 240.0f;
    float floorHeight = 27.94f / 240.0f;
    float floorDepth = 250.0f / 240.0f;

    float wallWidth = 500.0f / 5000.0f;
    float wallHeight = 500.0f / 5000.0f;
    float wallDepth = 56.39f / 5000.0f;


    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cMeshObject* pTile = new cMeshObject();
            pTile->bOverrideVertexModelColour = true;
            if (dungeon[i][j] == 0) {
                pTile->meshFileName = "assets/models/Floor.ply";
                pTile->colourRGB = glm::vec3(0.5f, 0.5f, 0.5f);
                pTile->position = glm::vec3(j * floorWidth, 0.0f, i * floorDepth);
                pTile->scale /= 230.0f;
                pTile->bUseTextureAsColour = true;
                pTile->textureNames[0] = "floor.bmp";
                pTile->textureBlendRatio[0] = 0.0f;
                ::g_MeshesToDraw.push_back(pTile);
            }
            else if (dungeon[i][j] == 1)
            {
                glm::vec3 wallColor = glm::vec3(0.60f, 0.30f, 0.01f);
                //Left
                pTile->meshFileName = "assets/models/Wall.ply";
                pTile->colourRGB = wallColor;
                pTile->position = glm::vec3(j * floorWidth, 0.0f, i * floorDepth);
                pTile->scale /= 490.0f;
                pTile->textureNames[0] = "floor.bmp";
                ::g_MeshesToDraw.push_back(pTile);

                //Up
                cMeshObject* pTile2 = new cMeshObject();
                pTile2->orientation.y = glm::radians(90.0f);
                pTile2->meshFileName = "assets/models/Wall.ply";
                pTile2->bOverrideVertexModelColour = true;
                pTile2->colourRGB = wallColor;
                pTile2->position = glm::vec3(j * floorWidth, 0.0f, i * floorDepth - floorDepth);
                pTile2->scale /= 490.0f;
                pTile2->textureNames[0] = "wall.bmp";
                ::g_MeshesToDraw.push_back(pTile2);


                //Down
                cMeshObject* pTile3 = new cMeshObject();
                pTile3->orientation.y = glm::radians(180.0f);
                pTile3->meshFileName = "assets/models/Wall.ply";
                pTile3->bOverrideVertexModelColour = true;
                pTile3->colourRGB = wallColor;
                pTile3->position = glm::vec3(j * floorWidth - floorWidth, 0.0f, i * floorDepth - floorDepth);
                pTile3->scale /= 490.0f;
                pTile3->textureNames[0] = "wall.bmp";
                ::g_MeshesToDraw.push_back(pTile3);

                //Right
                cMeshObject* pTile4 = new cMeshObject();
                pTile4->orientation.y = glm::radians(270.0f);
                pTile4->meshFileName = "assets/models/Wall.ply";
                pTile4->bOverrideVertexModelColour = true;
                pTile4->colourRGB = wallColor;
                pTile4->position = glm::vec3(j * floorWidth - floorDepth, 0.0f, i * floorDepth);
                pTile4->scale /= 490.0f;
                pTile4->textureNames[0] = "wall.bmp";
                ::g_MeshesToDraw.push_back(pTile4);

            }
            else if (dungeon[i][j] == 22)
            {
                glm::vec3 wallColor = glm::vec3(0.60f, 0.30f, 0.01f);

                pTile->meshFileName = "assets/models/Floor.ply";
                pTile->colourRGB = glm::vec3(0.5f, 0.5f, 0.5f);
                pTile->position = glm::vec3(j * floorWidth, -1.0f, i * floorDepth);
                pTile->scale /= 230.0f;
                pTile->textureNames[0] = "floor.bmp";
                ::g_MeshesToDraw.push_back(pTile);

                //Up
                cMeshObject* pTile2 = new cMeshObject();
                pTile2->meshFileName = "assets/models/Wall.ply";
                pTile2->bOverrideVertexModelColour = true;
                pTile2->colourRGB = wallColor;
                pTile2->position = glm::vec3(j * floorWidth, -1.0f, i * floorDepth);
                pTile2->scale /= 490.0f;
                pTile2->textureNames[0] = "wall.bmp";
                ::g_MeshesToDraw.push_back(pTile2);

                //Right
                cMeshObject* pTile4 = new cMeshObject();
                pTile4->orientation.y = glm::radians(270.0f);
                pTile4->meshFileName = "assets/models/Wall.ply";
                pTile4->bOverrideVertexModelColour = true;
                pTile4->colourRGB = wallColor;
                pTile4->textureNames[0] = "wall.bmp";
                pTile4->position = glm::vec3(j * floorWidth - floorDepth, -1.0f, i * floorDepth);
                pTile4->scale /= 490.0f;
                ::g_MeshesToDraw.push_back(pTile4);
            }            
            else if (dungeon[i][j] == 21)
            {
                glm::vec3 wallColor = glm::vec3(0.60f, 0.30f, 0.01f);

                pTile->meshFileName = "assets/models/Floor.ply";
                pTile->colourRGB = glm::vec3(0.5f, 0.5f, 0.5f);
                pTile->position = glm::vec3(j * floorWidth, -1.0f, i * floorDepth);
                pTile->scale /= 230.0f;
                pTile->textureNames[0] = "floor.bmp";
                ::g_MeshesToDraw.push_back(pTile);

                //Down
                cMeshObject* pTile3 = new cMeshObject();
                pTile3->orientation.y = glm::radians(180.0f);
                pTile3->meshFileName = "assets/models/Wall.ply";
                pTile3->bOverrideVertexModelColour = true;
                pTile3->colourRGB = wallColor;
                pTile3->textureNames[0] = "wall.bmp";
                pTile3->position = glm::vec3(j * floorWidth - floorWidth, -1.0f, i * floorDepth - floorDepth);
                pTile3->scale /= 490.0f;
                ::g_MeshesToDraw.push_back(pTile3);

                //Right
                cMeshObject* pTile4 = new cMeshObject();
                pTile4->orientation.y = glm::radians(270.0f);
                pTile4->meshFileName = "assets/models/Wall.ply";
                pTile4->bOverrideVertexModelColour = true;
                pTile4->colourRGB = wallColor;
                pTile4->textureNames[0] = "wall.bmp";
                pTile4->position = glm::vec3(j * floorWidth - floorDepth, -1.0f, i * floorDepth);
                pTile4->scale /= 490.0f;
                ::g_MeshesToDraw.push_back(pTile4);
            }           
            else if (dungeon[i][j] == 24)
            {
                glm::vec3 wallColor = glm::vec3(0.60f, 0.30f, 0.01f);

                pTile->meshFileName = "assets/models/Floor.ply";
                pTile->colourRGB = glm::vec3(0.5f, 0.5f, 0.5f);
                pTile->position = glm::vec3(j * floorWidth, -1.0f, i * floorDepth);
                pTile->scale /= 230.0f;
                pTile->textureNames[0] = "floor.bmp";
                ::g_MeshesToDraw.push_back(pTile);

                //Down
                cMeshObject* pTile3 = new cMeshObject();
                pTile3->orientation.y = glm::radians(180.0f);
                pTile3->meshFileName = "assets/models/Wall.ply";
                pTile3->bOverrideVertexModelColour = true;
                pTile3->colourRGB = wallColor;
                pTile3->textureNames[0] = "wall.bmp";
                pTile3->position = glm::vec3(j * floorWidth - floorWidth, -1.0f, i * floorDepth - floorDepth);
                pTile3->scale /= 490.0f;
                ::g_MeshesToDraw.push_back(pTile3);

                //Left
                cMeshObject* pTile1 = new cMeshObject();
                pTile1->meshFileName = "assets/models/Wall.ply";
                pTile1->colourRGB = wallColor;
                pTile1->textureNames[0] = "wall.bmp";
                pTile1->orientation.y = glm::radians(90.0f);
                pTile1->position = glm::vec3(j * floorWidth, -1.0f, i * floorDepth - floorWidth);
                pTile1->scale /= 490.0f;
                ::g_MeshesToDraw.push_back(pTile1);
            }          
            else if (dungeon[i][j] == 23)
            {
                glm::vec3 wallColor = glm::vec3(0.60f, 0.30f, 0.01f);

                pTile->meshFileName = "assets/models/Floor.ply";
                pTile->colourRGB = glm::vec3(0.5f, 0.5f, 0.5f);
                pTile->position = glm::vec3(j * floorWidth, -1.0f, i * floorDepth);
                pTile->scale /= 230.0f;
                pTile->textureNames[0] = "floor.bmp";
                ::g_MeshesToDraw.push_back(pTile);

                //Up
                cMeshObject* pTile2 = new cMeshObject();
                pTile2->meshFileName = "assets/models/Wall.ply";
                pTile2->bOverrideVertexModelColour = true;
                pTile2->colourRGB = wallColor;
                pTile2->textureNames[0] = "wall.bmp";
                pTile2->position = glm::vec3(j * floorWidth, -1.0f, i * floorDepth);
                pTile2->scale /= 490.0f;
                ::g_MeshesToDraw.push_back(pTile2);


                //Left
                cMeshObject* pTile1 = new cMeshObject();
                pTile1->meshFileName = "assets/models/Wall.ply";
                pTile1->colourRGB = wallColor;
                pTile1->textureNames[0] = "wall.bmp";
                pTile1->orientation.y = glm::radians(90.0f);
                pTile1->position = glm::vec3(j * floorWidth, -1.0f, i * floorDepth - floorWidth);
                pTile1->scale /= 490.0f;
                ::g_MeshesToDraw.push_back(pTile1);
            }

        }
    }


}

