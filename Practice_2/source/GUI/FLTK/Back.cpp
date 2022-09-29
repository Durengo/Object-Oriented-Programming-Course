#include "Back.h"

#include "Front.h"
#include "Callbacks.h"
#include "Core/Log.h"

LayerLogic::LayerLogic(Layer *instance)
    : layerInstance(instance), windowInstance(instance->getWindow())
{
    layerInstanceID = layerInstance->getLayerID();
}

LayerLogic::~LayerLogic()
{
}

void LayerLogic::bindCallbackToButton(int whichButton, FLTK_WIDGET type, int whichWidget, Callbacks callback, bool conditions[10])
{
    if (isDone)
    {
        CLI_ASSERT(0, "THIS LAYER ALREADY HAS A BIND");
        return;
    }
    if (whichButton < 0 || whichButton > buttonTracker.size() - 1)
    {
        CLI_ASSERT(0, "OUT OF BOUNDS WHICH BUTTON");
    }
    Fl_Widget_Wrapper<Fl_Button> *button = buttonTracker[whichButton];

    std::vector<Fl_Text_Display *> Texts;
    std::vector<Fl_Output *> Outputs;

    switch (type)
    {
    case FLTK_WIDGET::Box:

        break;
    case FLTK_WIDGET::Text:
        Texts.push_back(textTracker[whichWidget]);
        switch (callback)
        {
        case ToggleTextVisibility:
            button->callback([&](Fl_Widget &sender, std::any arg)
                             { CB::toggleTextVisibility(toggleTextVisibility, buttonTracker.size(), textTracker); });
            return;
        default:
            return;
        }
        break;
    default:
        return;
    }
}

void LayerLogic::bindCallbackToButton(int whichButton, const FLTK_WIDGET (&type)[], Callbacks callback)
{
    if (isDone)
    {
        CLI_ASSERT(0, "THIS LAYER ALREADY HAS A BIND");
        return;
    }
    if (whichButton < 0 || whichButton > buttonTracker.size() - 1)
    {
        CLI_ASSERT(0, "OUT OF BOUNDS WHICH BUTTON");
    }
    Fl_Widget_Wrapper<Fl_Button> *button = buttonTracker[whichButton];

    if ((type[0] == FLTK_WIDGET::Input && type[1] == FLTK_WIDGET::Output && type[2] == FLTK_WIDGET::Box && type[3] == FLTK_WIDGET::Text))
    {
        switch (callback)
        {
        case ResetInputAndOutputHideBoxAndText:
            button->callback([&](Fl_Widget &sender, std::any arg)
                             { CB::reset_input_and_output_hide_box_and_text(inputTracker, outputTracker, boxTracker, textTracker); });
            return;
        default:
            return;
        }
    }
    else if ((type[0] == FLTK_WIDGET::Input && type[1] == FLTK_WIDGET::Output) || (type[0] == FLTK_WIDGET::Output && type[1] == FLTK_WIDGET::Input))
    {
        switch (callback)
        {
        case ToggleTextVisibility:
            return;
        case CopyInputToOutput:
            button->callback([&](Fl_Widget &sender, std::any arg)
                             { CB::copy_input_to_output(inputTracker, outputTracker); });
            return;
        case ResetInputAndOutput:
            button->callback([&](Fl_Widget &sender, std::any arg)
                             { CB::reset_input_and_output(inputTracker, outputTracker); });
            return;
        case PersonCopyParsePaste:
            button->callback([&](Fl_Widget &sender, std::any arg)
                             { CB::person_copy_parse_paste(inputTracker, outputTracker, boxTracker, textTracker, person); });
            return;
        default:
            return;
        }
    }
    else
    {
        CLI_ASSERT(0, "NO OTHER TYPES CURRENTLY ACCEPTED");
    }
}

void LayerLogic::addBoxToLogic(int boxId)
{
    Layer *temp = layerInstance->getLayerInstance(layerInstanceID);

    Fl_Box *newB = temp->getBox(boxId);

    boxTracker.push_back(newB);
    internalBoxCount++;
    // CLI_TRACE("Box = {0}", internalBoxCount);
}

void LayerLogic::addBoxToLogic(int layerId, int boxId)
{
    Layer *temp = layerInstance->getHead();
    if (layerId > temp->getLayerCount() || layerId < 0)
    {
        CLI_ASSERT(0, "LAYER OUT OF BOUNDS");
        return;
    }
    for (int i = 0; i != layerId; i++)
    {
        if (temp->layerInstance == nullptr)
        {
            CLI_ERROR("OUT OF BOUNDS ID");
        }
        temp = temp->layerInstance;
    }

    Fl_Box *newB = temp->getBox(boxId);

    boxTracker.push_back(newB);
    internalBoxCount++;
    // CLI_TRACE("Box = {0}", internalBoxCount);
}

void LayerLogic::addButtonToLogic(int buttonId)
{
    Layer *temp = layerInstance->getLayerInstance(layerInstanceID);

    Fl_Widget_Wrapper<Fl_Button> *newB = temp->getButton(buttonId);

    buttonTracker.push_back(newB);
    internalButtonCount++;
    // CLI_TRACE("BUTTON = {0}", internalButtonCount);
}

void LayerLogic::addButtonToLogic(int layerId, int buttonId)
{
    Layer *temp = layerInstance->getHead();
    if (layerId > temp->getLayerCount() || layerId < 0)
    {
        CLI_ASSERT(0, "LAYER OUT OF BOUNDS");
        return;
    }
    for (int i = 0; i != layerId; i++)
    {
        if (temp->layerInstance == nullptr)
        {
            CLI_ERROR("OUT OF BOUNDS ID");
        }
        temp = temp->layerInstance;
    }

    Fl_Widget_Wrapper<Fl_Button> *newB = temp->getButton(buttonId);

    buttonTracker.push_back(newB);
    internalButtonCount++;
    // CLI_TRACE("BUTTON = {0}", internalButtonCount);
}

void LayerLogic::addTextToLogic(int outputId)
{
    Layer *temp = layerInstance->getLayerInstance(layerInstanceID);

    Fl_Text_Display *newT = temp->getText(outputId);

    textTracker.push_back(newT);
    internalTextCount++;
    // CLI_TRACE("TEXT = {0}", internalTextCount);
}

void LayerLogic::addTextToLogic(int layerId, int outputId)
{
    Layer *temp = layerInstance->getHead();
    if (layerId > temp->getLayerCount() || layerId < 0)
    {
        CLI_ASSERT(0, "LAYER OUT OF BOUNDS");
        return;
    }
    for (int i = 0; i != layerId; i++)
    {
        if (temp->layerInstance == nullptr)
        {
            CLI_ERROR("OUT OF BOUNDS ID");
        }
        temp = temp->layerInstance;
    }

    Fl_Text_Display *newT = temp->getText(outputId);

    textTracker.push_back(newT);
    internalTextCount++;
    // CLI_TRACE("TEXT = {0}", internalTextCount);
}

void LayerLogic::addInputToLogic(int inputId)
{
    Layer *temp = layerInstance->getLayerInstance(layerInstanceID);

    Fl_Input *newI = temp->getInput(inputId);

    inputTracker.push_back(newI);
    internalInputCount++;
    // CLI_TRACE("INPUT = {0}", internalInputCount);
}

void LayerLogic::addInputToLogic(int layerId, int inputId)
{
    Layer *temp = layerInstance->getHead();
    if (layerId > temp->getLayerCount() || layerId < 0)
    {
        CLI_ASSERT(0, "LAYER OUT OF BOUNDS");
        return;
    }
    for (int i = 0; i != layerId; i++)
    {
        if (temp->layerInstance == nullptr)
        {
            CLI_ERROR("OUT OF BOUNDS ID");
        }
        temp = temp->layerInstance;
    }

    Fl_Input *newI = temp->getInput(inputId);

    inputTracker.push_back(newI);
    internalInputCount++;
    // CLI_TRACE("INPUT = {0}", internalInputCount);
}

void LayerLogic::addOutputToLogic(int outputId)
{
    Layer *temp = layerInstance->getLayerInstance(layerInstanceID);

    Fl_Output *newO = temp->getOutput(outputId);

    outputTracker.push_back(newO);
    internalOutputCount++;
    // CLI_TRACE("OUTPUT = {0}", internalOutputCount);
}

void LayerLogic::addOutputToLogic(int layerId, int outputId)
{
    Layer *temp = layerInstance->getHead();
    if (layerId > temp->getLayerCount() || layerId < 0)
    {
        CLI_ASSERT(0, "LAYER OUT OF BOUNDS");
        return;
    }
    for (int i = 0; i != layerId; i++)
    {
        if (temp->layerInstance == nullptr)
        {
            CLI_ERROR("OUT OF BOUNDS ID");
        }
        temp = temp->layerInstance;
    }

    Fl_Output *newO = temp->getOutput(outputId);

    outputTracker.push_back(newO);
    internalOutputCount++;
    // CLI_TRACE("OUTPUT = {0}", internalOutputCount);
}