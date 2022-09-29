#pragma once

#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Display.H>

#include "Fl_Widget_Wrapper.h"
#include "Person/Person.h"
#include "Core/Log.h"

class Layer;

enum Callbacks
{
    ToggleTextVisibility = 0,
    CopyInputToOutput = 1,
    ResetInputAndOutput = 2,
    ResetInputAndOutputHideBoxAndText = 3,
    PersonCopyParsePaste = 4,
};

enum FLTK_WIDGET
{
    Box = 0,
    Text = 1,
    Button = 2,
    Input = 3,
    Output = 4
};

class LayerLogic
{
private:
    Layer *layerInstance = nullptr;
    Fl_Window *windowInstance = nullptr;

    std::vector<Fl_Box *> boxTracker;
    std::vector<Fl_Widget_Wrapper<Fl_Button> *> buttonTracker;
    std::vector<Fl_Input *> inputTracker;
    std::vector<Fl_Output *> outputTracker;
    std::vector<Fl_Text_Display *> textTracker;

    int internalBoxCount = 0;
    int internalTextCount = 0;
    int internalButtonCount = 0;
    int internalInputCount = 0;
    int internalOutputCount = 0;

    int layerInstanceID = 0;

    bool toggleTextVisibility = false;
    bool personCopyParsePaste = false;

    Person *person = nullptr;

    bool isDone = false;

public:
    LayerLogic(Layer *instance);
    ~LayerLogic();

    void bindCallbackToButton(int whichButton, FLTK_WIDGET type, int whichWidget, Callbacks callback, bool conditions[10]);
    void bindCallbackToButton(int whichButton, const FLTK_WIDGET (&type)[], Callbacks callback);
    // void bindCallbackToButton(int whichButton, const FLTK_WIDGET (&type)[], const int (&whichWidget)[], Callbacks callback);

    void addPersonToLogic(Person *p) { person = p; }

    void addBoxToLogic(int boxId);
    void addBoxToLogic(int layerId, int boxId);
    void addTextToLogic(int outputId);
    void addTextToLogic(int layerId, int outputId);
    void addButtonToLogic(int buttonId);
    void addButtonToLogic(int layerId, int buttonId);
    void addInputToLogic(int inputId);
    void addInputToLogic(int layerId, int inputId);
    void addOutputToLogic(int outputId);
    void addOutputToLogic(int layerId, int outputId);

private:
    bool getDone() const { return isDone; }
    Person *getPerson() const { return person; }
    void switchDone()
    {
        if (isDone)
            isDone = true;
        else
            isDone = false;
    }

    // create specific functions and pass them as enums to bind button func
    // e.g.
    // void CopyInputToOutput(Fl_Input[], Fl_Output[])
    // note pass parameters as arrays.
};