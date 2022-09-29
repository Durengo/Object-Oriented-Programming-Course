#include "Front.h"

#include "Core/Log.h"

Layer::Layer(const std::string &Name, Fl_Window *wInstance, int ID)
    : boxCount(0), textCount(0), buttonCount(0), inputCount(0), outputCount(0), layerInstance(nullptr), windowInstance(wInstance), layerCount(ID), layerDone(false)
{
}

Layer::Layer(Fl_Window *wInstance, int ID)
    : boxCount(0), textCount(0), buttonCount(0), inputCount(0), outputCount(0), layerInstance(nullptr), windowInstance(wInstance), layerCount(ID), layerDone(false)
{
}

Layer::Layer(const std::string &Name, Fl_Window *wInstance)
    : boxCount(0), textCount(0), buttonCount(0), inputCount(0), outputCount(0), layerInstance(nullptr), windowInstance(wInstance), layerCount(-1), layerDone(false)
{
}

Layer::Layer(Fl_Window *wInstance)
    : boxCount(0), textCount(0), buttonCount(0), inputCount(0), outputCount(0), layerInstance(nullptr), windowInstance(wInstance), layerCount(-1), layerDone(false)
{
}

Layer::~Layer()
{
}

void Layer::addLayer()
{
    if (layerCount == -1)
    {
        layerCount = 1;
        this->setLayerID(layerCount - 1);
        this->setHead(this);
        //CLI_INFO("NEW LAYER ADDED.");
        //CLI_INFO("NEW LAYER ID = {0}", this->getLayerID());
        //CLI_INFO("LOGIC ADDED TO LAYER.");
        LayerLogic *newLogic = new LayerLogic(this);
        Logic.push_back(newLogic);
        return;
    }
    Layer *temp = this;
    Layer *head = this;

    while (temp->layerInstance != nullptr)
    {
        temp = temp->layerInstance;
    }
    if (!temp->layerDone && temp != head)
    {
        CLI_ERROR("ADDING Layer WHILE NOT DONE.");
        return;
    }

    temp->layerInstance = new Layer(windowInstance, layerCount);
    temp->layerInstance->setLayerID(layerCount);
    temp->layerInstance->setHead(head->getHead());
    //CLI_INFO("NEW LAYER ID = {0}", temp->layerInstance->getLayerID());

    //CLI_INFO("NEW LAYER ADDED. PREVIOUS COUNT = {0}", layerCount);
    layerCount++;
    //CLI_INFO("NEW COUNT = {0}", layerCount);

    //CLI_INFO("NEW LAYER ADDED.");
    //CLI_INFO("LOGIC ADDED TO LAYER.");
    LayerLogic *newLogic = new LayerLogic(temp->layerInstance);
    Logic.push_back(newLogic);

    return;
}

void Layer::doneLayer()
{
    Layer *temp = this;
    while (temp->layerInstance != nullptr)
    {
        temp = temp->layerInstance;
    }
    temp->setDone();
    //CLI_INFO("LAYER COMPLETED.");
}

Layer *Layer::getLayerInstance(int layerId)
{
    if (layerId > layerCount || layerId < 0)
    {
        CLI_ASSERT(0, "ACCESSING OUT OF BOUNDS LAYER\n LAYER DOES NOT EXIST.");
        return nullptr;
    }
    Layer *temp = head;
    for (int i = 0; i != layerId; i++)
    {
        if (temp->layerInstance == nullptr)
        {
            CLI_ERROR("OUT OF BOUNDS ID");
        }
        // CLI_TRACE("PROVIDED ID = {0}; CURRENT ID = {1}", layerId, temp->getLayerCount());
        temp = temp->layerInstance;
    }
    return temp;
}

void Layer::addBox(int x, int y, int w, int h, Fl_Boxtype boxtype, const char *text)
{
    Layer *temp = this;
    while (temp->layerInstance != nullptr)
    {
        temp = temp->layerInstance;
    }
    if (temp->getDone())
    {
        CLI_ERROR("CANNOT ADD UI ELEMENT ONCE doneLayer() is called.");
        return;
    }
    Fl_Box *box = new Fl_Box(x, y, w, h);
    box->box(boxtype);
    temp->BoxList.push_back(box);
    temp->boxCount++;
    return;
}

void Layer::addBox(int x, int y, int w, int h, Fl_Boxtype boxtype, Fl_Color color, const char *text)
{
    Layer *temp = this;
    while (temp->layerInstance != nullptr)
    {
        temp = temp->layerInstance;
    }
    if (temp->getDone())
    {
        CLI_ERROR("CANNOT ADD UI ELEMENT ONCE doneLayer() is called.");
        return;
    }
    Fl_Box *box = new Fl_Box(x, y, w, h);
    box->color(color);
    box->box(boxtype);
    temp->BoxList.push_back(box);
    temp->boxCount++;
    return;
}

void Layer::addText(int x, int y, int w, int h, const char *text)
{
    Layer *temp = this;
    while (temp->layerInstance != nullptr)
    {
        temp = temp->layerInstance;
    }
    if (temp->getDone())
    {
        CLI_ERROR("CANNOT ADD UI ELEMENT ONCE doneLayer() is called.");
        return;
    }
    Fl_Text_Display *textT = new Fl_Text_Display(x, y, w, h, text);
    temp->TextList.push_back(textT);
    temp->textCount++;
    return;
}

void Layer::addText(int x, int y, int w, int h, const char *text, Fl_Color color)
{
    Layer *temp = this;
    while (temp->layerInstance != nullptr)
    {
        temp = temp->layerInstance;
    }
    if (temp->getDone())
    {
        CLI_ERROR("CANNOT ADD UI ELEMENT ONCE doneLayer() is called.");
        return;
    }
    Fl_Text_Display *textT = new Fl_Text_Display(x, y, w, h, text);
    textT->color(color);
    temp->TextList.push_back(textT);
    temp->textCount++;
    return;
}

void Layer::addButton(int x, int y, int w, int h, const char *text)
{
    Layer *temp = this;
    while (temp->layerInstance != nullptr)
    {
        temp = temp->layerInstance;
    }
    if (temp->getDone())
    {
        CLI_ERROR("CANNOT ADD UI ELEMENT ONCE doneLayer() is called.");
        return;
    }
    //CLI_INFO("LAYER = {0}; NEW BUTTON ADDED; PREVIOUS COUNT = {1}", temp->getLayerID(), temp->getTotalButtons());
    Fl_Widget_Wrapper<Fl_Button> *button = new Fl_Widget_Wrapper<Fl_Button>(x, y, w, h, text);
    temp->ButtonList.push_back(button);
    temp->buttonCount++;
    //CLI_INFO("NEW COUNT = {0}", temp->getTotalButtons());
    return;
}

void Layer::addInput(int x, int y, int w, int h, const char *text)
{
    Layer *temp = this;
    while (temp->layerInstance != nullptr)
    {
        temp = temp->layerInstance;
    }
    if (temp->getDone())
    {
        CLI_ERROR("CANNOT ADD UI ELEMENT ONCE doneLayer() is called.");
        return;
    }
    Fl_Input *input = new Fl_Input(x, y, w, h, text);
    temp->InputList.push_back(input);
    temp->inputCount++;
    return;
}

void Layer::addOutput(int x, int y, int w, int h, const char *text)
{
    Layer *temp = this;
    while (temp->layerInstance != nullptr)
    {
        temp = temp->layerInstance;
    }
    if (temp->getDone())
    {
        CLI_ERROR("CANNOT ADD UI ELEMENT ONCE doneLayer() is called.");
        return;
    }
    Fl_Output *output = new Fl_Output(x, y, w, h, text);
    temp->OutputList.push_back(output);
    temp->outputCount++;
    return;
}

Fl_Box *Layer::getBox(int boxId)
{
    if (boxId < 0)
    {
        CLI_ASSERT(0, "ACCESSING OUT OF BOUNDS BOX\n BOX DOES NOT EXIST.");
        return nullptr;
    }
    if (boxId > this->boxCount)
    {
        CLI_ASSERT(0, "ACCESSING OUT OF BOUNDS BOX\n BOX DOES NOT EXIST.");
        return nullptr;
    }
    Fl_Box *newBox = this->BoxList[boxId];
    return newBox;
}

Fl_Widget_Wrapper<Fl_Button> *Layer::getButton(int buttonId)
{
    if (buttonId < 0)
    {
        CLI_ASSERT(0, "ACCESSING OUT OF BOUNDS BUTTON\n BUTTON DOES NOT EXIST.");
        return nullptr;
    }
    if (buttonId > this->buttonCount)
    {
        CLI_ASSERT(0, "ACCESSING OUT OF BOUNDS BOX\n BOX DOES NOT EXIST.");
        return nullptr;
    }
    Fl_Widget_Wrapper<Fl_Button> *newButton = this->ButtonList[buttonId];
    return newButton;
}

Fl_Input *Layer::getInput(int inputId)
{
    if (inputId < 0)
    {
        CLI_ASSERT(0, "ACCESSING OUT OF BOUNDS INPUT\n INPUT DOES NOT EXIST.");
        return nullptr;
    }
    if (inputId > this->inputCount)
    {
        CLI_ASSERT(0, "ACCESSING OUT OF BOUNDS BOX\n BOX DOES NOT EXIST.");
        return nullptr;
    }
    Fl_Input *newInput = this->InputList[inputId];
    return newInput;
}

Fl_Output *Layer::getOutput(int outputId)
{
    if (outputId < 0)
    {
        CLI_ASSERT(0, "ACCESSING OUT OF BOUNDS OUTPUT\n OUTPUT DOES NOT EXIST.");
        return nullptr;
    }
    if (outputId > this->outputCount)
    {
        CLI_ASSERT(0, "ACCESSING OUT OF BOUNDS BOX\n BOX DOES NOT EXIST.");
        return nullptr;
    }
    Fl_Output *newOutput = this->OutputList[outputId];
    return newOutput;
}

Fl_Text_Display *Layer::getText(int textId)
{
    if (textId < 0)
    {
        CLI_ASSERT(0, "ACCESSING OUT OF BOUNDS TEXT\n TEXT DOES NOT EXIST.");
        return nullptr;
    }
    if (textId > this->textCount)
    {
        CLI_ASSERT(0, "ACCESSING OUT OF BOUNDS BOX\n BOX DOES NOT EXIST.");
        return nullptr;
    }
    Fl_Text_Display *newText = this->TextList[textId];
    return newText;
}

LayerLogic *Layer::getLayerLogicInstance(int which)
{
    // CLI_ERROR("SIZE OF LAYER VECTOR = {0}", Logic.size());
    if (which > this->layerCount || which < 0 || which > Logic.size() - 1)
    {
        CLI_ASSERT(0, "ACCESSING OUT OF BOUNDS LAYER LOGIC\n LAYER LOGIC DOES NOT EXIST.");
        return nullptr;
    }
    return Logic[which];
}