/**************************************************************************
This file is part of IrisGL
http://www.irisgl.org
Copyright (c) 2016  GPLv3 Jahshaka LLC <coders@jahshaka.com>

This is free software: you may copy, redistribute
and/or modify it under the terms of the GPLv3 License

For more information see the LICENSE file
*************************************************************************/

#ifndef RENDERITEM_H
#define RENDERITEM_H

#include "../irisglfwd.h"
#include "material.h"
#include <QMatrix4x4>

namespace iris
{

class Mesh;

enum class FaceCullingMode
{
    None,
    Front,
    Back,
    FrontAndBack
};

enum class RenderItemType
{
    None,
    Mesh,
    ParticleSystem
};

struct RenderItem
{
    RenderItemType type;
    MaterialPtr material;
    Mesh* mesh;

    QMatrix4x4 worldMatrix;
    SceneNodePtr sceneNode;

    QOpenGLShaderProgram* shaderProgram;

    FaceCullingMode faceCullingMode;

    //sort order for render layer
    //used if no material is specified
    int renderLayer;

    RenderItem() {
        type = RenderItemType::None,
        //renderLayer = (int)RenderLayer::Opaque;
        worldMatrix.setToIdentity();
        faceCullingMode = FaceCullingMode::Back;
    }
};

}
#endif // RENDERITEM_H
