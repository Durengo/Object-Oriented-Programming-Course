#include "API.h"

#include "PCH.h"
#include "Core/Log.h"

FLTKAPI::FLTKAPI(int w, int h, const char *title) : Fl_Window(w, h, title), MainLayer(nullptr)
{
    begin();

    MainLayer = new Layer(this);

    //CLI_WARN("{0}", MainLayer->getLayerCount());

    // SECTION I INPUT
    MainLayer->addLayer();
    MainLayer->addBox(5, 10, 300, 340, FL_BORDER_BOX);
    MainLayer->addText(155, 40, 0, 0, "USER INPUT");
    MainLayer->getLayerInstance(0)->getText(0)->hide();
    MainLayer->addInput(150, 50, 140, 30, "First Name:");
    MainLayer->addInput(150, 100, 140, 30, "Last Name:");
    MainLayer->addInput(150, 150, 140, 30, "Date of Birth (Year):");
    MainLayer->addInput(150, 200, 140, 30, "Date of Birth (Month):");
    MainLayer->addInput(150, 250, 140, 30, "Date of Birth (Day):");
    MainLayer->addButton(200, 300, 70, 30, "Create");
    MainLayer->addButton(130, 300, 70, 30, "Reset");
    MainLayer->doneLayer();
    // SECTION I INPUT

    // SECTION II INPUT VALIDATION
    MainLayer->addLayer();
    MainLayer->addBox(330, 10, 300, 340, FL_BORDER_BOX);
    MainLayer->addText(470, 40, 0, 0, "INPUT VALIDATION");
    MainLayer->addText(470, 80, 0, 0, "First Letter Must Be Capital;\nNo more than 2 Capital Letters;");
    MainLayer->getLayerInstance(1)->getText(1)->hide();
    MainLayer->addText(470, 130, 0, 0, "First Letter Must Be Capital;\nNo more than 2 Capital Letters;");
    MainLayer->getLayerInstance(1)->getText(2)->hide();
    MainLayer->addText(470, 180, 0, 0, "Year Cannot Be More Than 2022 Year;\n Year Cannot Be Less Than 1912;");
    MainLayer->getLayerInstance(1)->getText(3)->hide();
    MainLayer->addText(470, 230, 0, 0, "Month Cannot Be:\nLess Than 1 Or More Than 12\n");
    MainLayer->getLayerInstance(1)->getText(4)->hide();
    MainLayer->addText(470, 280, 0, 0, "Day Cannot Be:\nLess Than 1 Or More Than 31");
    MainLayer->getLayerInstance(1)->getText(5)->hide();
    MainLayer->addBox(305, 52, 25, 25, FL_BORDER_BOX, FL_RED);
    MainLayer->getLayerInstance(1)->getBox(1)->hide();
    MainLayer->addBox(305, 102, 25, 25, FL_BORDER_BOX, FL_RED);
    MainLayer->getLayerInstance(1)->getBox(2)->hide();
    MainLayer->addBox(305, 152, 25, 25, FL_BORDER_BOX, FL_RED);
    MainLayer->getLayerInstance(1)->getBox(3)->hide();
    MainLayer->addBox(305, 202, 25, 25, FL_BORDER_BOX, FL_RED);
    MainLayer->getLayerInstance(1)->getBox(4)->hide();
    MainLayer->addBox(305, 252, 25, 25, FL_BORDER_BOX, FL_RED);
    MainLayer->getLayerInstance(1)->getBox(5)->hide();
    MainLayer->doneLayer();
    // SECTION II INPUT VALIDATION

    // SECTION III OUTPUT
    MainLayer->addLayer();
    MainLayer->addBox(5, 370, 625, 150, FL_BORDER_BOX);
    MainLayer->addText(315, 390, 0, 0, "OUTPUT");
    MainLayer->addText(100, 410, 0, 0, "FIRST NAME");
    MainLayer->addOutput(50, 410, 100, 20, "");
    MainLayer->addText(200, 410, 0, 0, "LAST NAME");
    MainLayer->addOutput(150, 410, 100, 20, "");
    MainLayer->addText(350, 410, 0, 0, "Date of Birth (YYYY/MM/DD)");
    MainLayer->addOutput(330, 410, 50, 20, "");
    MainLayer->addOutput(380, 410, 30, 20, "");
    MainLayer->addOutput(410, 410, 30, 20, "");
    MainLayer->addText(100, 460, 0, 0, "Age");
    MainLayer->addOutput(88, 460, 30, 20, "");
    MainLayer->addText(280, 460, 0, 0, "Days Until Next Birthday");
    MainLayer->addOutput(268, 460, 40, 20, "");
    MainLayer->doneLayer();

    // SECTION III OUTPUT

    // BUTTON I
    MainLayer->getLayerLogicInstance(0)->addPersonToLogic(person);
    MainLayer->getLayerLogicInstance(0)->addButtonToLogic(0, 0);
    MainLayer->getLayerLogicInstance(0)->addInputToLogic(0, 0);
    MainLayer->getLayerLogicInstance(0)->addInputToLogic(0, 1);
    MainLayer->getLayerLogicInstance(0)->addInputToLogic(0, 2);
    MainLayer->getLayerLogicInstance(0)->addInputToLogic(0, 3);
    MainLayer->getLayerLogicInstance(0)->addInputToLogic(0, 4);
    MainLayer->getLayerLogicInstance(0)->addOutputToLogic(2, 0);
    MainLayer->getLayerLogicInstance(0)->addOutputToLogic(2, 1);
    MainLayer->getLayerLogicInstance(0)->addOutputToLogic(2, 2);
    MainLayer->getLayerLogicInstance(0)->addOutputToLogic(2, 3);
    MainLayer->getLayerLogicInstance(0)->addOutputToLogic(2, 4);
    MainLayer->getLayerLogicInstance(0)->addOutputToLogic(2, 5);
    MainLayer->getLayerLogicInstance(0)->addOutputToLogic(2, 6);
    MainLayer->getLayerLogicInstance(0)->addTextToLogic(1, 1);
    MainLayer->getLayerLogicInstance(0)->addBoxToLogic(1, 1);
    MainLayer->getLayerLogicInstance(0)->addTextToLogic(1, 2);
    MainLayer->getLayerLogicInstance(0)->addBoxToLogic(1, 2);
    MainLayer->getLayerLogicInstance(0)->addTextToLogic(1, 3);
    MainLayer->getLayerLogicInstance(0)->addBoxToLogic(1, 3);
    MainLayer->getLayerLogicInstance(0)->addTextToLogic(1, 4);
    MainLayer->getLayerLogicInstance(0)->addBoxToLogic(1, 4);
    MainLayer->getLayerLogicInstance(0)->addTextToLogic(1, 5);
    MainLayer->getLayerLogicInstance(0)->addBoxToLogic(1, 5);
    // BUTTON I CALLBACK
    MainLayer->getLayerLogicInstance(0)->bindCallbackToButton(0, {FLTK_WIDGET::Input, FLTK_WIDGET::Output}, Callbacks::PersonCopyParsePaste);

    // BUTTON II
    MainLayer->getLayerLogicInstance(0)->addButtonToLogic(0, 1);
    // BUTTON II CALLBACK
    MainLayer->getLayerLogicInstance(0)->bindCallbackToButton(1, {FLTK_WIDGET::Input, FLTK_WIDGET::Output, FLTK_WIDGET::Box, FLTK_WIDGET::Text}, Callbacks::ResetInputAndOutputHideBoxAndText);

    // DEBUG INFO
    CLI_WARN("LAYER COUNT = {0}", MainLayer->getLayerCount());
    CLI_WARN("LAYER 1 ID = {0}", MainLayer->getLayerInstance(0)->getLayerID());
    CLI_WARN("LAYER 2 ID = {0}", MainLayer->getLayerInstance(1)->getLayerID());
    CLI_WARN("LAYER 3 ID = {0}", MainLayer->getLayerInstance(2)->getLayerID());
    // DEBUG INFO

    end();
    // resizable(this);
    show();
}

FLTKAPI::~FLTKAPI() {}

void FLTKAPI::Init(int resX, int resY, const std::string &title)
{
    FLTKAPI win(resX, resY, title.c_str());
    Fl::run();
}