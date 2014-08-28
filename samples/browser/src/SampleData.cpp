/***********************************************************************
created:    4/6/2012
author:     Lukas E Meindl
*************************************************************************/
/***************************************************************************
*   Copyright (C) 2004 - 2012 Paul D Turner & The CEGUI Development Team
*
*   Permission is hereby granted, free of charge, to any person obtaining
*   a copy of this software and associated documentation files (the
*   "Software"), to deal in the Software without restriction, including
*   without limitation the rights to use, copy, modify, merge, publish,
*   distribute, sublicense, and/or sell copies of the Software, and to
*   permit persons to whom the Software is furnished to do so, subject to
*   the following conditions:
*
*   The above copyright notice and this permission notice shall be
*   included in all copies or substantial portions of the Software.
*
*   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
*   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
*   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
*   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
*   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
*   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
*   OTHER DEALINGS IN THE SOFTWARE.
***************************************************************************/
#include "SampleData.h"
#include "Sample.h"

#include "CEGUI/DynamicModule.h"
#include "CEGUI/Version.h"
#include "CEGUI/Exceptions.h"
#include "CEGUI/System.h"
#include "CEGUI/TextureTarget.h"
#include "CEGUI/BitmapImage.h"
#include "CEGUI/GUIContext.h"
#include "CEGUI/Texture.h"
#include "CEGUI/ImageManager.h"
#include "CEGUI/InputAggregator.h"
#include "CEGUI/Window.h"
#include "CEGUI/Vector.h"

using namespace CEGUI;

#define S_(X) #X
#define STRINGIZE(X) S_(X)

SampleData::SampleData(CEGUI::String sampleName,
                       CEGUI::String summary,
                       CEGUI::String description,
                       SampleType sampleTypeEnum,
                       CEGUI::String credits)
    : d_name(sampleName)
    , d_summary(summary)
    , d_description(description)
    , d_type(sampleTypeEnum)
    , d_usedFilesString("")
    , d_credits(credits)
    , d_sampleWindow(0)
    , d_inputAggregator(0)
    , d_nonDefaultInputAggregator(true)
    , d_guiContext(0)
    , d_textureTarget(0)
    , d_textureTargetImage(0)
{
}

SampleData::~SampleData()
{

}

CEGUI::String SampleData::getName()
{
    return d_name;
}

CEGUI::String SampleData::getSummary()
{
    return "Summary:\n" + d_summary;
}

CEGUI::String SampleData::getCredits()
{
    return "Credits:\n" + d_credits;
}

CEGUI::String SampleData::getSampleTypeString()
{
    switch(d_type)
    {
    case ST_Module:
        return "C++ Module";
        break;
    case ST_Lua:
        return "Lua";
        break;
    case ST_Python:
        return "Python";
    default:
        return "";
    }
}

CEGUI::String SampleData::getDescription()
{
    return "Description:\n" + d_description;
}

CEGUI::String SampleData::getUsedFilesString()
{
    return "Used files:\n" + d_usedFilesString;
}

void SampleData::setSampleWindow(CEGUI::Window* sampleWindow)
{
    d_sampleWindow = sampleWindow;
}

CEGUI::Window* SampleData::getSampleWindow()
{
    return d_sampleWindow;
}

void SampleData::initialise(int width, int height)
{
    CEGUI::System& system(System::getSingleton());

    CEGUI::Sizef size(static_cast<float>(width), static_cast<float>(height));

    d_textureTarget = system.getRenderer()->createTextureTarget();
    d_guiContext = &system.createGUIContext((RenderTarget&)*d_textureTarget);
    d_inputAggregator = new CEGUI::InputAggregator(d_guiContext);
    d_inputAggregator->initialise();
    d_textureTarget->declareRenderSize(size);

    CEGUI::String imageName(d_textureTarget->getTexture().getName());
    d_textureTargetImage = static_cast<CEGUI::BitmapImage*>(&CEGUI::ImageManager::getSingleton().create("BitmapImage", "SampleBrowser/" + imageName));
    d_textureTargetImage->setTexture(&d_textureTarget->getTexture());

    setTextureTargetImageArea(static_cast<float>(height), static_cast<float>(width));
}

void SampleData::deinitialise()
{
    CEGUI::System& system(System::getSingleton());

    if(d_guiContext)
    {
        system.destroyGUIContext(*d_guiContext);
        d_guiContext = 0;
    }

    if (d_inputAggregator && !d_nonDefaultInputAggregator)
    {
        delete d_inputAggregator;
        d_inputAggregator = 0;
    }

    if(d_textureTarget)
    {
        system.getRenderer()->destroyTextureTarget(d_textureTarget);
        d_textureTarget = 0;
    }

    if(d_textureTargetImage)
    {
        CEGUI::ImageManager::getSingleton().destroy(*d_textureTargetImage);
        d_textureTargetImage = 0;
    }
}

GUIContext* SampleData::getGuiContext()
{
    return d_guiContext;
}

InputAggregator* SampleData::getInputAggregator()
{
    return d_inputAggregator;
}

void SampleData::handleNewWindowSize(float width, float height)
{
    setTextureTargetImageArea(height, width);

    CEGUI::Sizef windowSize(width, height);
    if(d_textureTarget)
    {
        d_textureTarget->declareRenderSize(windowSize);

        d_sampleWindow->getRenderingSurface()->invalidate();
    }
}

CEGUI::Image& SampleData::getRTTImage()
{
    return *d_textureTargetImage;
}

void SampleData::setGUIContextRTT()
{
    d_guiContext->setRenderTarget(*d_textureTarget);
}

void SampleData::clearRTTTexture()
{
    d_textureTarget->clear();
}

void SampleData::setTextureTargetImageArea(float height, float width)
{
    if(d_textureTarget)
    {
        bool isTextureTargetVerticallyFlipped = d_textureTarget->isRenderingInverted();
        CEGUI::Rectf renderArea;
        if(isTextureTargetVerticallyFlipped)
            renderArea = CEGUI::Rectf(0.0f, height, width, 0.0f);
        else
            renderArea = CEGUI::Rectf(0.0f, 0.0f, width, height);


        if(d_textureTargetImage)
            d_textureTargetImage->setImageArea(renderArea);
    }
}

//----------------------------------------------------------------------------//
SampleDataModule::SampleDataModule(Sample* instance,
                                   CEGUI::String sampleName,
                                   CEGUI::String summary,
                                   CEGUI::String description,
                                   SampleType sampleTypeEnum,
                                   CEGUI::String credits)
    : SampleData(sampleName, summary, description, sampleTypeEnum, credits)
    , d_sample(instance)
    , d_dynamicModule(0)
{
}

SampleDataModule::~SampleDataModule()
{
}

void SampleDataModule::initialise(int width, int height)
{
    SampleData::initialise(width, height);

    d_sample->initialise(d_guiContext);
    d_usedFilesString = d_sample->getUsedFilesString();

    // we need to override the default sample input aggregator
    if (d_sample->getInputAggregator() != 0)
    {
        delete d_inputAggregator;

        d_inputAggregator = d_sample->getInputAggregator();
        d_nonDefaultInputAggregator = true;
    }
}

void SampleDataModule::deinitialise()
{
    if(d_sample)
        d_sample->deinitialise();

    SampleData::deinitialise();   
}

void SampleDataModule::onEnteringSample()
{
    d_sample->onEnteringSample();
}

void SampleDataModule::update(float timeSinceLastUpdate)
{
    d_sample->update(timeSinceLastUpdate);
}