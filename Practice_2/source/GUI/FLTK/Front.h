#pragma once

#include <FL/Fl_Widget.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Window.H>

#include <vector>

#include "Back.h"

class Layer
{
private:
    std::vector<Fl_Box *> BoxList;
    std::vector<Fl_Text_Display *> TextList;
    std::vector<Fl_Widget_Wrapper<Fl_Button> *> ButtonList;
    std::vector<Fl_Input *> InputList;
    std::vector<Fl_Output *> OutputList;

    int boxCount, textCount, buttonCount, inputCount, outputCount;

    Layer *layerInstance;
    Fl_Window *windowInstance;

    int layerCount;
    bool layerDone;

    std::vector<LayerLogic *> Logic;

    int layerID = 0;

    Layer *head = nullptr;

    friend class LayerLogic;

private:
    Layer(const std::string &Name, Fl_Window *wInstance, int ID);
    Layer(Fl_Window *wInstance, int ID);

public:
    Layer(const std::string &Name, Fl_Window *wInstance);
    Layer(Fl_Window *wInstance);
    ~Layer();

    void addLayer();

    void addBox(int x, int y, int w, int h, Fl_Boxtype boxtype, const char *text = "");
    void addBox(int x, int y, int w, int h, Fl_Boxtype boxtype, Fl_Color color, const char *text = "");

    void addText(int x, int y, int w, int h, const char *text);
    void addText(int x, int y, int w, int h, const char *text, Fl_Color color);

    void addButton(int x, int y, int w, int h, const char *text);

    void addInput(int x, int y, int w, int h, const char *text);

    void addOutput(int x, int y, int w, int h, const char *text = "");

    void doneLayer();

    // getters
    int getLayerCount() const { return this->layerCount; }
    int getTotalBoxes() const { return BoxList.size(); }
    int getTotalTexts() const { return TextList.size(); }
    int getTotalButtons() const { return ButtonList.size(); }
    int getTotalInputs() const { return InputList.size(); }
    int getTotalOutputs() const { return OutputList.size(); }
    int getLayerID() const { return layerID; }

    // ptr getters
    Fl_Window *getWindow() const { return windowInstance; }
    Fl_Box *getBox(int boxId);
    Fl_Widget_Wrapper<Fl_Button> *getButton(int buttonId);
    Fl_Input *getInput(int inputId);
    Fl_Output *getOutput(int outputId);
    Fl_Text_Display *getText(int textId);

    // other ptr getters
    Layer *getLayerInstance() const { return this->layerInstance; }
    Layer *getLayerInstance(int layerId);
    LayerLogic *getLayerLogicInstance(int which = 0);

private:
    bool getDone() const { return layerDone; }
    Layer *getHead() const { return head; }

    void setDone() { layerDone = true; }
    void setLayerCount(int count) { layerCount = count; }
    void setLayerID(int Id) { layerID = Id; }
    void setHead(Layer *ptr) { head = ptr; }
};